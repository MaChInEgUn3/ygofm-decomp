#!/usr/bin/env python3
"""
List undecompiled functions worth attempting, cheapest first.

    python tools_src/candidates.py            # default band, 3 shown in full
    python tools_src/candidates.py 24 34 -n 5 # band and count
    python tools_src/candidates.py --count    # just the totals

Excludes only what is genuinely out of scope or genuinely unwritable:

  * PsyQ library functions (docs/LIBRARY_FUNCS.txt) and the library region
    above 0x80073840.
  * GTE and mult/div shapes, and the C runtime stubs, which are hand-written.
  * Functions already decompiled or parked.

Everything else is listed and *tagged*. Three drop rules have now been
retracted in turn, each after it was measured rather than reasoned about, and
each had been hiding a population that matched:

  * the range-check fold, which happens on the `&&` and survives as nested ifs;
  * duplicate %hi, which is not an alias problem at all -- see below;
  * **`mult` and `div`**, dropped as "hand-written or needing idioms not yet
    worked out". They are neither. `a * b` in C compiles to `mult`/`mflo`, and
    `/` or `%` by a constant compiles to a `mult` by a magic number followed by
    `mfhi` and a shift -- func_8002C484 is `(x / 10) * 178 + (x % 10) * 16 + 14`
    and nothing else. Every one of the 66 in-scope functions this rule hid pairs
    its `mult` with an `mflo` or `mfhi`; the genuinely hand-written ones are the
    GTE intrinsics (`wc2`, `rtps`, `mfc2`, `mtc2`), which are still filtered.
  * **calls into PsyQ library functions**, dropped on the grounds that they
    "need prototypes we do not have". They do not. gcc 2.8 takes an implicit
    declaration, and integer and pointer arguments pass correctly without one;
    a dozen functions calling into the library matched in one session with no
    prototype written. What a missing prototype would actually cost is a float
    or struct argument, which is rare and shows up as a wrong instruction
    count immediately. These are tagged lib-call, not hidden.

The dup-%hi tag means what it says and nothing more: retail materialised one
symbol's address twice. All 96 such candidates in the binary use the *bare*
form -- `lui $r,%hi(s)` with the memory op through the same `$r`, which is the
assembler expanding a bare symbol -- so what they want is
`-mno-split-addresses`, not a symbol alias. An alias makes them worse, because
gcc then hoists both %hi values into callee-saved registers. 25 of the 96 also
contain a %hi whose %lo is completed in another block, which is a hoisted
split address that `-mno-split-addresses` cannot produce.

That used to read "a function with both shapes cannot be satisfied by one file
flag", with func_8004BBBC parked as the example. It is not a barrier: the flag
is per file but the *declaration* is per symbol. A scalar or sized declaration
makes cc1psx emit the bare symbol for one name while an unsized array keeps
the split pair for another, and the assembler's -G decides only for the bare
ones. func_8004BBBC and func_8003D46C -- the two examples, in opposite
directions -- both matched on default compiler flags plus `as -G0`. Where a
function has no %gp_rel at all, any -G is free.

The register-allocation class has no target-side signature, so a good fraction
of what this prints will still miss. That is a fixed tax, not a sign the list
is exhausted.
"""

import glob
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ASM = os.path.join(ROOT, "asm", "nonmatchings", "31D8")
LIBRARY_REGION = 0x80073840

BRANCH = re.compile(r"\b(b(eq|ne|gez|gtz|lez|ltz|eqz|nez)?|j|jal|jr)\b")
# GTE intrinsics and the C runtime stubs (crt0, the constructor walker) are
# hand-written by construction. Everything else that was ever in this list has
# come back out:
#   * `mult`/`div` -- `a * b` and `/`-by-a-constant are ordinary codegen. 66
#     in-scope functions were invisible for months.
#   * `break` -- this was the FIFTH retraction and the only one that was a
#     *toolchain* gap rather than a misread of the target. `break 7` and
#     `break 6` are the divisor and overflow checks aspsx wraps around a real
#     `div`; maspsx only emits them with --expand-div, which build.py did not
#     pass. func_800358FC (`return f() % arg0;`) matched the moment it did.
#     41 in-scope functions were hidden by it. What stays filtered is the
#     *two-operand* form, `break 0,260` and friends: those are the BIOS
#     syscall stubs just under the library boundary, hand-written by
#     construction. `break 7` and `break 6` are the division checks.
#   * `jr $v`/`jr $a`/`jr $t` -- the SIXTH, retracted the same day as the
#     fifth. These are `switch` jump tables and the C is ordinary; what
#     blocked them was that splat emits the table as data at its own address
#     while cc1psx emits its own into the object's .rodata. build.py now
#     splits splat's rodata at the tables owned by compiled functions and
#     places the compiled section in the hole. 37 in-scope functions, 62 KB --
#     more code than everything matched before it. See DECISIONS.md.
# What is left is genuinely hand-written: the GTE intrinsics, and the C
# runtime and BIOS syscall stubs (`break 0,260`, writes to $sp/$gp/$fp).
HAND_WRITTEN = re.compile(r"wc2|rtps|mfc2|mtc2"
                          r"|break\s+\d+\s*,|\bor\s+\$sp\b"
                          r"|\$fp,\s*\$sp|\$gp,\s*%hi")


def parked():
    """Names recorded as parked in the docs, so they are not re-offered.

    An entry is a line starting at column 0 with the function name; anything
    after it on that line, and every indented line under it, is the diagnosis.
    This used to take the whole line as the name, which silently stopped
    filtering the moment entries started carrying `-- diagnosis` inline: only
    the oldest name-only entries were still being excluded, and every function
    parked since was being re-offered as a fresh candidate."""
    path = os.path.join(ROOT, "docs", "PARKED.txt")
    if not os.path.exists(path):
        return set()
    names = set()
    for line in open(path):
        if not line.strip() or line.startswith("#") or line[0].isspace():
            continue
        if not re.match(r"func_[0-9A-Fa-f]{8}\b", line.strip()):
            continue
        # One entry can cover several functions -- `func_A / func_B -- shared
        # diagnosis`. Taking only the first name silently re-offered the rest
        # as fresh candidates, which is how func_80071424 and func_80071460
        # turned up in a "not parked" scan while sitting in parked/. Split the
        # heading from the diagnosis at the first ` -- ` and take every name on
        # the heading side only; the diagnosis body routinely cites other
        # functions and must not be swept in.
        head = line.strip().split(" -- ", 1)[0]
        names.update(re.findall(r"func_[0-9A-Fa-f]{8}", head))
    return names


def read(name):
    """(labels and instructions, instructions only) for one function."""
    both, body = [], []
    for line in open(os.path.join(ASM, name + ".s")):
        s = line.strip()
        if s.startswith(".L") and s.endswith(":"):
            both.append(("L", s))
        elif "/*" in line and "*/" in line:
            insn = re.sub(r"^\s*/\*.*?\*/\s*", "", line).strip()
            both.append(("I", insn))
            body.append(insn)
    return both, body


# A second stack-allocating prologue partway through a listing means splat
# missed a function boundary and glued two functions under one label -- the
# target cannot be written as one C function, and attempting it wastes the
# time it takes to notice. Exactly two listings in the binary are like this,
# both in scope and both undecompiled: func_80030FD0 (second prologue at
# 0x80031004) and func_8002DD74. The real fix is to give splat those two
# symbols and re-split; until then they are tagged, not hidden, so the count
# stays honest.
_PROLOGUE = re.compile(r"addiu\s+\$sp,\s*\$sp,\s*-0x")


def merged_listing(body):
    return sum(1 for ins in body if _PROLOGUE.search(ins)) > 1


def has_duplicate_hi(both):
    """Same symbol's %hi materialised twice without a join label between.

    Two rules, each learned from a case the other gets wrong.

    Reset on labels only, not on branches: cc1psx's CSE works over extended
    basic blocks, so a conditional branch does not stop it reusing an address
    on the fall-through path. Resetting on every branch misses func_80049CB0,
    whose two materialisations are separated by a `beq` and which needed an
    alias.

    Ignore anything in a branch delay slot: filling two delay slots with the
    same `lui` is something cc1psx does on its own, either because a call
    between them clobbers the register (func_8005A0DC) or because the two sit
    on mutually exclusive paths (func_8005C768). Both of those matched with no
    alias, and counting delay slots would have excluded them from mining.
    """
    seen = set()
    after_branch = False
    for kind, text in both:
        if kind == "L":
            seen = set()
            after_branch = False
            continue
        in_delay_slot = after_branch
        after_branch = bool(BRANCH.match(text))
        if in_delay_slot:
            continue
        m = re.search(r"%hi\(([A-Za-z_]\w*)\)", text)
        if m:
            if m.group(1) in seen:
                return True
            seen.add(m.group(1))
    return False


def has_range_check(body):
    """blez/bgtz with an slt within two instructions -- the (v-1) < n fold."""
    return any(
        re.match(r"(blez|bgtz)\b", body[i])
        and any(re.match(r"slti?u?\b", body[k])
                for k in range(i + 1, min(i + 3, len(body))))
        for i in range(len(body)))


def main():
    args = [a for a in sys.argv[1:] if not a.startswith("-")]
    lo = int(args[0]) if args else 16
    hi = int(args[1]) if len(args) > 1 else 26
    show = int(sys.argv[sys.argv.index("-n") + 1]) if "-n" in sys.argv else 3

    lib = {l.strip() for l in open(os.path.join(ROOT, "docs", "LIBRARY_FUNCS.txt"))
           if l.startswith("func_")}
    done = {os.path.basename(p)[:-2]
            for p in glob.glob(os.path.join(ROOT, "src", "func_*.c"))}
    skip = done | lib | parked()

    rows, dropped = [], {"dup_hi": 0, "range": 0}
    for path in glob.glob(os.path.join(ASM, "*.s")):
        name = os.path.basename(path)[:-2]
        if name in skip or int(name[5:], 16) >= LIBRARY_REGION:
            continue
        both, body = read(name)
        if not (lo <= len(body) <= hi):
            continue
        joined = " ".join(body)
        if HAND_WRITTEN.search(joined):
            continue
        libcall = any(c in lib or not c.startswith("func_")
                      for c in re.findall(r"jal\s+(\S+)", joined))
        # Neither of the old drop rules is a "cannot match" any more.
        #
        # The range-check fold was retracted: it happens on the `&&`, and
        # writing the condition as nested `if`s keeps both comparisons. Three
        # functions came out of the park that way, so the filter is gone.
        #
        # Duplicate %hi for one symbol means retail materialised the address
        # twice. Every instance in the binary is the bare-symbol form, so the
        # answer is -mno-split-addresses and not an alias; see the module
        # docstring. Still sorted last, because a quarter of them also want a
        # hoisted split address in the same unit and cannot have both.
        dup = has_duplicate_hi(both)
        if dup:
            dropped["dup_hi"] += 1
        rows.append((dup, len(body), name, both, libcall, merged_listing(body)))

    rows.sort()
    print(f"{len(rows) - dropped['dup_hi']} clean candidates in "
          f"{lo}-{hi} instructions, plus {dropped['dup_hi']} that materialise "
          f"one address twice (listed last, tagged dup-%hi)")
    if "--count" in sys.argv:
        return 0
    for dup, count, name, both, libcall, merged in rows[:show]:
        tag = "  [dup-%hi: try -mno-split-addresses]" if dup else ""
        if libcall:
            tag += "  [lib-call: implicit declaration is enough]"
        if merged:
            tag += "  [MERGED: two functions under one label, see candidates.py]"
        print(f"\n--- {name} ({count}){tag}")
        for _, text in both:
            print("   ", text)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
