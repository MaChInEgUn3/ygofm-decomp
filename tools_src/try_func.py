#!/usr/bin/env python3
"""
Fast single-function matching loop.

Compiles one snippet of candidate C with the real PsyQ toolchain and diffs
the resulting instructions against a target function's disassembly, without
running a full build. Use this while hunting for the C (and flags) that
reproduce a function, then fold the winner into src/ and verify with
tools_src/build.py.

    python tools_src/try_func.py func_80015010 candidate.c [-O2] [-G8] ...

Any trailing arguments are passed straight through to CC1PSX, so you can
sweep optimisation levels etc. without editing anything.
"""

import os
import re
import shutil
import subprocess
import sys
from pathlib import Path

# Every toolchain constant comes from build.py rather than being restated
# here. This file used to keep its own copies, and they went stale without
# anyone noticing: it still pointed at psyq46 after the SDK was corrected to
# 4.5, still passed --aspsx-version=2.86, still ran the Windows venv python,
# and never applied the post-passes. So it would have compiled a candidate
# with the *wrong compiler* and printed a confident side-by-side diff about
# it. Importing is what keeps the two honest -- there is nothing left to
# drift.
sys.path.insert(0, str(Path(__file__).resolve().parent))
import build as B  # noqa: E402

ROOT = B.ROOT
PSYQ_BIN, CPPPSX, CC1PSX = B.PSYQ_BIN, B.CPPPSX, B.CC1PSX
PSYQ_RUNNER = B.PSYQ_RUNNER
ASM_DIR = B.ASM_FUNCS
MASPSX, VENV_PYTHON = B.MASPSX, B.VENV_PYTHON
CPP_FLAGS = B.CPP_FLAGS
# Per-process scratch. These paths were shared, so two try_func runs at once
# -- which is exactly what check_try_func.py plus a manual run looks like --
# clobbered each other's intermediate assembly and produced a diff belonging
# to neither candidate. It reported 32 differing instructions for a function
# that has 5, and two spurious failures in the full regression pass.
SCRATCH = ROOT / "build" / "scratch" / f"try{os.getpid()}"

# cc1psx writes numbered registers; the target disassembly uses ABI names.
REG_NAMES = {
    "$0": "$zero", "$1": "$at", "$2": "$v0", "$3": "$v1",
    "$4": "$a0", "$5": "$a1", "$6": "$a2", "$7": "$a3",
    "$8": "$t0", "$9": "$t1", "$10": "$t2", "$11": "$t3",
    "$12": "$t4", "$13": "$t5", "$14": "$t6", "$15": "$t7",
    "$16": "$s0", "$17": "$s1", "$18": "$s2", "$19": "$s3",
    "$20": "$s4", "$21": "$s5", "$22": "$s6", "$23": "$s7",
    "$24": "$t8", "$25": "$t9", "$28": "$gp", "$29": "$sp",
    "$30": "$fp", "$31": "$ra",
}


# config/symbol_aliases.txt gives a second name to an address splat named once,
# so that gcc materialises the base twice where retail does. The two names
# assemble to the same address and the same bytes -- but they are spelled
# differently, so comparing text reports a difference the build does not have.
# Map every alias back to whichever symbol shares its address.
def _alias_map():
    by_addr, out = {}, {}
    for path, pat in ((ROOT / "config" / "symbol_aliases.txt",
                       re.compile(r"^\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;")),):
        if not path.exists():
            continue
        for line in path.read_text().splitlines():
            m = pat.match(line)
            if m:
                by_addr.setdefault(int(m.group(2), 16), []).append(m.group(1))
    for addr, names in by_addr.items():
        canon = f"D_{addr:08X}".lower()
        for n in names:
            out[n.lower()] = canon
    return out


ALIASES = _alias_map()


def _gp_map():
    """Target listings show `834($gp)` where splat found no symbol.

    Our side emits `%gp_rel(D_8009B24A)($gp)` for the same address, because we
    named it. Same instruction, different spelling, and comparing the text
    calls it a difference -- so resolve the bare offsets to names using _gp
    from the linker script and the symbol tables the build already reads.
    """
    gp, out = None, {}
    ld = ROOT / "config" / "slus_014.11.ld"
    if ld.exists():
        m = re.search(r"_gp\s*=\s*(0x[0-9A-Fa-f]+)", ld.read_text())
        if m:
            gp = int(m.group(1), 16)
    if gp is None:
        return {}
    for name in ("undefined_syms_auto.txt", "symbol_aliases.txt",
                 "symbol_addrs.txt"):
        path = ROOT / "config" / name
        if not path.exists():
            continue
        for line in path.read_text().splitlines():
            m = re.match(r"\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)", line)
            if m:
                off = int(m.group(2), 16) - gp
                if -0x8000 <= off < 0x8000:
                    out.setdefault(off, m.group(1).lower())
    return out


GP_SYMS = _gp_map()


def normalise(line):
    """Reduce an asm line to `mnemonic operands` for comparison."""
    line = line.split("#")[0].strip()
    if not line or line.startswith((".", "/*")):
        return None
    line = re.sub(r"/\*.*?\*/", "", line)
    # Numbered registers appear bare and inside operands like `0($4)`, so
    # rewrite them wherever they occur rather than only as whole tokens.
    line = re.sub(r"\$(\d+)\b", lambda m: REG_NAMES.get("$" + m.group(1),
                                                       "$" + m.group(1)), line)
    parts = line.replace(",", " , ").split()
    if not parts:
        return None
    text = " ".join(parts).replace(" , ", ",")
    # `li $r,N` is a pseudo-instruction; for small N the assembler emits
    # exactly `addiu $r,$zero,N`, which is what the disassembly shows.
    # The disassembly spells split constants as expressions; evaluate them
    # so `(0x808080 >> 16)` compares against a plain 0x80.
    text = re.sub(r"\((0x[0-9a-fA-F]+|\d+)\s*>>\s*(\d+)\)",
                  lambda m: str(int(m.group(1), 0) >> int(m.group(2))), text)
    text = re.sub(r"\((0x[0-9a-fA-F]+|\d+)\s*&\s*(0x[0-9a-fA-F]+|\d+)\)",
                  lambda m: str(int(m.group(1), 0) & int(m.group(2), 0)), text)

    m = re.match(r"li (\$\w+),(-?(?:0x)?[0-9a-fA-F]+)$", text)
    if m:
        value = int(m.group(2), 0)
        if -0x8000 <= value < 0x8000:
            text = f"addiu {m.group(1)},$zero,{value}"
        elif 0x8000 <= value <= 0xFFFF:
            # Too large for a signed addiu, no high half: the assembler emits
            # `ori $r,$zero,N`. 0xFFFF masks are common enough that leaving
            # this out shows a phantom diff on every one of them.
            text = f"ori {m.group(1)},$zero,{value}"
        elif (value & 0xFFFF) == 0:
            # A constant with no low half assembles to a bare lui. Negative
            # ones count: `li $a0,-65536` is 0xFFFF0000, which the disassembly
            # shows as `lui $a0,0xFFFF`. Restricting this to positive values
            # made every 0xFFFF0000 mask read as a differing instruction.
            text = f"lui {m.group(1)},{(value >> 16) & 0xFFFF}"
        elif value < 0 or value > 0xFFFF:
            # Both halves needed: the assembler emits lui+ori, two real
            # instructions. Returned as two lines -- the callers splice them
            # in -- because comparing one line against two silently shifts
            # every following instruction and reports the whole tail as
            # differing. func_80059520's reciprocal-multiply constant is the
            # case that found this.
            hi, lo = (value >> 16) & 0xFFFF, value & 0xFFFF
            r = m.group(1)
            text = f"lui {r},{hi}\nori {r},{r},{lo}"
    # `j $ra` and `jr $ra` are the same instruction spelled two ways.
    text = re.sub(r"^j\b", "jr", text) if text.startswith("j $ra") else text
    # An indirect call: gcc writes `jal $ra,$v0`, the disassembly shows the
    # `jalr $v0` the assembler emits with $ra implicit. Same instruction.
    text = re.sub(r"^jalr? \$ra,(\$\w+)$", r"jalr \1", text)
    # cc1psx emits small-data references bare (`lhu $v0,sym`); the assembler
    # turns them into the gp-relative form the disassembly shows. Same thing.
    text = re.sub(r"%gp_rel\(([^)]*)\)\(\$gp\)", r"\1", text)
    # Taking the *address* of a small-data symbol: gcc emits the `la` pseudo
    # and the disassembly shows the `addiu $r,$gp,%gp_rel(sym)` the assembler
    # expanded it to. Same instruction. (For a symbol outside small data `la`
    # expands to two instructions instead, so this equivalence is only safe
    # because the disassembly side is already the gp-relative form -- if the
    # target used lui/%hi there would be nothing here to match against.)
    text = re.sub(r"^addiu (\$\w+),\$gp,%gp_rel\(([^)]*)\)$", r"la \1,\2", text)
    # Immediates and offsets are written 0x1618 in one place and 5656 in
    # the other; normalise every hex literal to decimal so they compare.
    text = re.sub(r"\b0x([0-9a-fA-F]+)\b",
                  lambda m: str(int(m.group(1), 16)), text)
    # After the hex-to-decimal rewrite above: a bare `834($gp)` is an address
    # splat had no name for, and our side spells the same address as a symbol.
    text = re.sub(r"(-?\d+)\(\$gp\)",
                  lambda m: GP_SYMS.get(int(m.group(1)), m.group(0)), text)
    text = text.lower()
    for alias, canon in ALIASES.items():
        text = text.replace(alias, canon)

    # Label definitions occupy no bytes; the two sides can never agree on
    # their names, and renumber_labels only handles references.
    if re.match(r"^(?:\$|\.)?l?\w*:$", text) or text.endswith(":"):
        return None

    # Pseudo-instructions the two sides spell differently but which
    # assemble identically.
    text = re.sub(r"^move (\$\w+),(\$\w+)$", r"addu \1,\2,$zero", text)
    text = re.sub(r"^beqz (\$\w+),", r"beq \1,$zero,", text)
    text = re.sub(r"^bnez (\$\w+),", r"bne \1,$zero,", text)
    text = re.sub(r"^negu (\$\w+),(\$\w+)$", r"subu \1,$zero,\2", text)
    # emits the immediate instruction, which is what the disassembly shows.
    # Each register-form mnemonic has exactly one immediate form, and they are
    # not derivable by a shared rule: add/sub take -iu, and/or/xor take -i,
    # slt takes -i (signed) while sltu takes -iu (unsigned). Folding slt in
    # with add/sub -- as this did until it was caught on func_8002497C --
    # rewrites every signed `slt $r,$r,20` into `sltiu` and reports a
    # signedness difference against the target that does not exist. Two
    # functions were mis-analysed for it before the micro-test showed the
    # tool inventing the diff.
    # Longest alternative first. Written as (...|slt|sltu)u? the regex
    # matches `sltu` as `slt` plus the optional u -- Python's alternation is
    # first-match, not longest-match -- so every unsigned compare was rewritten
    # to the signed immediate form. That is the *second* time this one line
    # invented a signedness difference: the first was mapping slt to sltiu.
    # Each mnemonic is now spelled out and mapped directly.
    _IMM = {"sltu": "sltiu", "slt": "slti", "addu": "addiu", "add": "addiu",
            "subu": "subiu", "sub": "subiu", "and": "andi", "or": "ori",
            "xor": "xori"}
    text = re.sub(r"^(sltu|slt|addu|add|subu|sub|and|or|xor) "
                  r"(\$\w+),(\$\w+),(-?\d+)$",
                  lambda m: f"{_IMM[m.group(1)]} "
                            f"{m.group(2)},{m.group(3)},{m.group(4)}",
                  text)
    # There is no subiu instruction: the assembler emits `addiu $r,$r,-n`,
    # which is what the disassembly shows. This must run *after* the table
    # above, because gcc's own spelling is `subu $sp,$sp,24` and it is that
    # table which turns it into subiu. Placed before it -- as it was when
    # first written -- it never fires, and every stack frame in the project
    # reads as a differing instruction.
    text = re.sub(r"^subiu (\$\w+),(\$\w+),(-?\d+)$",
                  lambda m: f"addiu {m.group(1)},{m.group(2)},{-int(m.group(3))}",
                  text)
    return text


def target_lines(func):
    path = ASM_DIR / f"{func}.s"
    if not path.exists():
        sys.exit(f"no disassembly for {func} at {path}")
    out = []
    for line in path.read_text().splitlines():
        # Anything past endlabel is inter-object padding, not part of the
        # function -- see the translation-unit boundary note in DECISIONS.md.
        if line.strip().startswith("endlabel"):
            break
        if "/*" in line and "*/" in line:
            body = line.split("*/", 1)[1]
            n = normalise(body)
            if n:
                out.extend(n.split("\n"))
    return out


_OBJ_REG = re.compile(r"\b(zero|at|v[01]|a[0-3]|t[0-9]|s[0-7]|t[89]|k[01]|gp|sp|fp|ra)\b")
_OBJ_INSN = re.compile(r"^\s*[0-9a-f]+:\s+(\S+)\s*(.*)$")
_OBJ_RELOC = re.compile(r"^\s+[0-9a-f]+:\s+(R_MIPS_\S+)\s+(\S+)")


def built_lines(func, csrc, extra_flags):
    """Compile the candidate and read back what the *assembler* produced.

    Reading cc1psx's text instead was the source of most of this file's
    history of wrong answers. cc1psx emits pseudo-instructions -- `la`,
    `li`, `subiu`, bare-symbol memory ops, `jal $ra,$reg` -- and the
    assembler decides how many real instructions each becomes, sometimes one
    and sometimes two, depending on whether the symbol landed in small data.
    No amount of rewriting rules in this file can know that; the assembler
    does. So we assemble and disassemble, and the only thing left to
    reconstruct is the relocated operands, which objdump prints alongside.
    """
    SCRATCH.mkdir(parents=True, exist_ok=True)
    src = SCRATCH / "try.c"
    src.write_text(Path(csrc).read_text())
    pre, asm = SCRATCH / "try.i", SCRATCH / "try.s"

    for cmd in (
        [*PSYQ_RUNNER, CPPPSX, *CPP_FLAGS, src.relative_to(ROOT).as_posix(),
         pre.relative_to(ROOT).as_posix()],
        [*PSYQ_RUNNER, CC1PSX, *extra_flags, pre.relative_to(ROOT).as_posix(),
         "-o", asm.relative_to(ROOT).as_posix()],
    ):
        r = subprocess.run([str(c) for c in cmd], cwd=ROOT,
                           capture_output=True, text=True)
        if r.returncode != 0:
            sys.exit(f"{Path(str(cmd[0])).name} failed:\n{r.stdout}\n{r.stderr}")

    masm = SCRATCH / "try.maspsx.s"
    with open(asm) as fin, open(masm, "w") as fout:
        r = subprocess.run(
            [str(VENV_PYTHON), str(MASPSX),
             f"--aspsx-version={B.ASPSX_VERSION}", "--macro-inc"],
            stdin=fin, stdout=fout, stderr=subprocess.PIPE, text=True, cwd=ROOT)
    if r.returncode != 0:
        sys.exit(f"maspsx failed:\n{r.stderr[:4000]}")

    text = masm.read_text().splitlines()
    if func in B.DELAY_SLOT_MACRO_FUNCS:
        text = B.fill_delay_slot_with_macro_tail(text)
    if func in B.SMALL_DATA_NOP_FUNCS:
        text = B.insert_small_data_load_delay_nops(text)
    if func in B.HOIST_EPILOGUE_FUNCS:
        text = B.hoist_epilogue_out_of_delay_slot(text)
    masm.write_text("\n".join(text) + "\n")

    obj = SCRATCH / "try.o"
    as_flags = list(B.AS_FLAGS)
    override = B.PER_FUNC_AS_FLAGS.get(func)
    if override:
        as_flags.append(override)
    r = subprocess.run([str(B.AS), *as_flags, "-o",
                        obj.relative_to(ROOT).as_posix(),
                        masm.relative_to(ROOT).as_posix()],
                       cwd=ROOT, capture_output=True, text=True)
    if r.returncode != 0:
        sys.exit(f"as failed:\n{r.stderr[:4000]}")

    r = subprocess.run([str(B.OBJDUMP), "-dr", "--no-show-raw-insn",
                        obj.relative_to(ROOT).as_posix()],
                       cwd=ROOT, capture_output=True, text=True)
    if r.returncode != 0:
        sys.exit(f"objdump failed:\n{r.stderr[:4000]}")
    return _from_objdump(r.stdout, func)


def _from_objdump(dump, func):
    """Turn `objdump -dr` output into the spelling the target listings use."""
    out, inside = [], False
    for line in dump.splitlines():
        if line.rstrip().endswith(f"<{func}>:"):
            inside = True
            continue
        if not inside:
            continue
        m = _OBJ_RELOC.match(line)
        if m and out:
            kind, sym = m.group(1), m.group(2)
            prev = out[-1]
            # A non-zero immediate on a %hi/%lo pair is an *addend* -- gcc
            # folded a constant offset into the relocation. Retail spelling it
            # as a separate `addiu` is then a real difference of one
            # instruction, and dropping the addend here hides it: that is what
            # this rule did until func_80039E9C, where try_func called a
            # two-instruction difference a match in the making.
            if kind == "R_MIPS_HI16":
                m2 = re.search(r"0x([0-9a-f]+)$", prev)
                add = int(m2.group(1), 16) if m2 else 0
                tag = f"%hi({sym})" if not add else f"%hi({sym}+{add})"
                prev = re.sub(r"0x[0-9a-f]+$", tag, prev)
            elif kind == "R_MIPS_LO16":
                if re.search(r",\s*-?\d+\(", prev):
                    m2 = re.search(r",\s*(-?\d+)\(", prev)
                    add = int(m2.group(1)) if m2 else 0
                    tag = f"%lo({sym})" if not add else f"%lo({sym}+{add})"
                    prev = re.sub(r"(,)\s*-?\d+(\()", rf"\1{tag}\2", prev)
                else:
                    m2 = re.search(r"(-?\d+)$", prev)
                    add = int(m2.group(1)) if m2 else 0
                    tag = f"%lo({sym})" if not add else f"%lo({sym}+{add})"
                    prev = re.sub(r"-?\d+$", tag, prev)
            elif kind == "R_MIPS_GPREL16":
                if re.search(r"-?\d+\(\$gp\)", prev):
                    prev = re.sub(r"-?\d+(\(\$gp\))",
                                  rf"%gp_rel({sym})\1", prev)
                else:
                    # `addiu $r,$gp,0` -- taking the address rather than
                    # loading through it.
                    prev = re.sub(r"(\$gp,)-?\d+$", rf"\1%gp_rel({sym})", prev)
            elif kind == "R_MIPS_26":
                # A jump inside the same section relocates against `.text`
                # itself; that is not a callee name, and substituting it
                # turns a local jump into a call to a section.
                if sym.startswith("."):
                    continue
                prev = re.sub(r"\s+\S+$", f" {sym}", prev)
            out[-1] = prev
            continue
        m = _OBJ_INSN.match(line)
        if not m:
            if line.strip() == "" or line.startswith("Disassembly"):
                continue
            continue
        mnem, ops = m.group(1), m.group(2).strip()
        # objdump prints a branch/jump target as `addr <sym+off>`; drop the
        # symbolic part, renumber_labels only needs a consistent token.
        ops = re.sub(r"\s*<[^>]*>", "", ops)
        ops = _OBJ_REG.sub(lambda mm: "$" + mm.group(1), ops)
        # objdump gives a branch target as a bare hex offset; the target
        # listings give a label. Spell it as one so renumber_labels can map
        # both sides positionally.
        if mnem.startswith("b") or mnem in ("j", "jal"):
            last = ops.rsplit(",", 1)[-1].strip()
            # Whole-token hex only. Testing "does not end in a letter" is
            # wrong -- `5c` is a perfectly good offset and ends in one.
            if re.fullmatch(r"[0-9a-f]+", last):
                ops = ops[:len(ops) - len(last)] + ".L" + last
        out.append(f"{mnem} {ops}".strip())
    # normalise *after* the relocations are spliced in: it lowercases and
    # rewrites immediates, which would stop the reloc patterns from matching.
    final = []
    for raw in out:
        n = normalise(raw)
        if n:
            final.extend(n.split("\n"))
    return final


def renumber_labels(lines):
    """Rewrite branch labels positionally so the two sides can be compared.

    gcc emits `$L3`, the disassembly has `.L80058E34`. The names can never
    agree, so map each side's labels to L1, L2, ... in order of first
    appearance; a real control-flow difference still shows up as a
    mismatch, but the naming no longer does.
    """
    mapping, counter, out = {}, 0, []
    label_re = re.compile(r"(?:\$|\.)l[0-9a-f]+", re.IGNORECASE)

    def sub(m):
        nonlocal counter
        key = m.group(0)
        if key not in mapping:
            counter += 1
            mapping[key] = f"L{counter}"
        return mapping[key]

    for line in lines:
        out.append(label_re.sub(sub, line))
    return out


def main():
    if len(sys.argv) < 3:
        sys.exit(__doc__)
    func, csrc = sys.argv[1], sys.argv[2]
    # Default to the flags the build would use for this very function,
    # including any per-function override, not to a guess at the defaults.
    flags = sys.argv[3:] or list(B.PER_FUNC_FLAGS.get(func, B.CC1_FLAGS))

    want = renumber_labels(target_lines(func))
    got = renumber_labels(built_lines(func, csrc, flags))

    # maspsx inserts the load-delay nops, so both sides now carry them and
    # they must be compared -- they occupy real bytes.
    w, g = want, got

    print(f"flags: {' '.join(flags)}")
    print(f"{'TARGET':<44} {'BUILT'}")
    print("-" * 90)
    bad = 0
    for i in range(max(len(w), len(g))):
        a = w[i] if i < len(w) else ""
        b = g[i] if i < len(g) else ""
        mark = "  " if a == b else "<<"
        if a != b:
            bad += 1
        print(f"{a:<44} {b:<40} {mark}")
    print("-" * 90)
    print("MATCH" if bad == 0 and len(w) == len(g)
          else f"{bad} differing instruction(s)")
    return 0 if bad == 0 else 1


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    finally:
        shutil.rmtree(SCRATCH, ignore_errors=True)
