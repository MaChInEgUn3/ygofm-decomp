#!/usr/bin/env python3
"""
Port a function's C from a second decompilation tree into this one and MEASURE it.

Background. A second matching decomp of the same executable (Unchiga's, shared
2026-08-30) covers 981 real-C units below our 0x80073840 scope cut against our
823, and 135 of the functions we have PARKED are real C on that side. None of
that is worth anything on his say-so: his tree is a different toolchain
(PsyQ 4.6/4.7, ASPSX >= 2.56 semantics) with its own headers, and in THIS
project a declaration is a codegen input. So the only question that decides a
merge is the one our own comparator answers -- does his C, compiled by OUR
build.py toolchain against OUR headers, reproduce the retail bytes?

This script asks that question mechanically, one function or all of them:

  * their splat config gives address -> unit name,
  * their symbol_addrs.txt gives their name -> address, which canonicalises to
    our `func_%08X` / `D_%08X` by a word-boundary rewrite,
  * their `extern` lines are dropped for anything our headers already declare
    (keeping them is a hard `conflicting types` error, and *silently keeping
    a different width would be worse*),
  * their per-unit flags (`config/unit_flags.txt`: -G0/-G8/-mno-split-addresses)
    are translated onto our CC1 flags, because measuring their C under our
    default flags is not measuring their C. The first probe run without them
    scored -6/42 on a function and would have been recorded as "does not port".

Nothing is installed. Output is a manifest; installing is a separate, deliberate
act, one function at a time for anything that needs a header change.

    python tools_src/transplant.py --tree <their-root> --func func_80012B50
    python tools_src/transplant.py --tree <their-root> --all --out manifest.tsv
    python tools_src/transplant.py --tree <their-root> --calibrate 12
"""

import argparse
import os
import re
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import build as B  # noqa: E402

ROOT = B.ROOT
# The file-to-vram delta for SLUS_014.11, confirmed in docs/DECISIONS.md. Their
# splat config addresses are file offsets; ours are virtual.
DELTA = 0x8000F800
SCOPE = 0x80073840


def their_units(tree):
    """address -> unit name, for every `c` subsegment in their splat config."""
    text = (tree / "config" / "slus01411.yaml").read_text(errors="replace")
    out = {}
    for m in re.finditer(r"-\s*\[0x([0-9A-Fa-f]+),\s*c,\s*([^\]]+)\]", text):
        out[int(m.group(1), 16) + DELTA] = m.group(2).strip()
    return out


def their_symbols(tree):
    """their name -> (addr, is_func)."""
    out = {}
    for line in (tree / "config" / "symbol_addrs.txt").read_text(errors="replace").splitlines():
        m = re.match(r"\s*([A-Za-z_][A-Za-z_0-9]*)\s*=\s*0x([0-9A-Fa-f]+)\s*;(.*)", line)
        if m:
            out[m.group(1)] = (int(m.group(2), 16), "type:func" in m.group(3))
    return out


def their_flags(tree):
    """unit name -> extra CC1 flags."""
    out = {}
    p = tree / "config" / "unit_flags.txt"
    if not p.exists():
        return out
    for line in p.read_text(errors="replace").splitlines():
        line = line.split("#")[0].strip()
        if not line:
            continue
        parts = line.split()
        if len(parts) >= 2:
            out[parts[0]] = parts[1:]
    return out


def our_name(sym, addr, is_func):
    """Canonical name in this tree. Their semantic names are interpretation;
    every tool here is keyed to the address form, so that is what we rewrite to."""
    return ("func_%08X" if is_func else "D_%08X") % addr


# Their headers declare globals inline in the .c; ours are in include/variables.h
# and include/functions.h, and the two disagreeing is precisely the failure this
# project documents. Drop theirs and let ours win -- a conflict then shows up as
# a compile error rather than as silently different codegen.
EXTERN_RE = re.compile(r"^\s*extern\s.*?\b((?:func_|D_)[0-9A-F]{8})\b[^;]*;\s*$")
CC1_OK = re.compile(r"^-(G[0-9]+|m[a-z-]+|f[a-z-]+|O[0-9])$")
# Their include/common.h, inlined. Deliberately does NOT pull our variables.h:
# see the comment in port().
PRELUDE = ("typedef unsigned char u8;\n"
           "typedef unsigned short u16;\n"
           "typedef unsigned int u32;\n"
           "typedef signed char s8;\n"
           "typedef short s16;\n"
           "typedef int s32;")


def port(tree, addr, unit, syms, flags, keep_externs=False):
    """Rewrite one of their C files into this tree's vocabulary.

    Returns (source_text, cc1_flags) or None when the unit is an INCLUDE_ASM
    stub -- those carve an extent and explicitly claim nothing about the C, so
    counting them as coverage is the filter mistake this repo keeps re-learning.
    """
    src = tree / "src" / (unit + ".c")
    if not src.exists():
        return None
    text = src.read_text(errors="replace")
    if "INCLUDE_ASM" in text:
        return None

    # Their name -> ours, longest first so a prefix never eats a longer symbol.
    for sym in sorted(syms, key=len, reverse=True):
        a, is_func = syms[sym]
        new = our_name(sym, a, is_func)
        if new != sym:
            text = re.sub(r"\b%s\b" % re.escape(sym), new, text)

    # SELF-CONTAINED mode (the default, and the only one that measures what we
    # actually want to know). Their files declare every global they touch
    # inline, and some of those declarations are struct-typed --
    # `extern struct T800E9E18 D_800E9E18[];` where our variables.h says
    # `u8 D_800E9E18[]`. Stripping theirs so ours wins turns `x[0].field46`
    # into a compile error; keeping both is `conflicting types`. Neither of
    # those is the question. The question is whether THEIR C, as they wrote
    # it, produces the retail bytes under OUR toolchain -- so compile it
    # against their own minimal prelude instead of our headers. Reconciling
    # declarations is a later, per-function step for the ones that land.
    if not keep_externs:
        text = re.sub(r'^\s*#\s*include\s+"common\.h".*$', PRELUDE, text,
                      count=1, flags=re.M)

    text = re.sub(r'^\s*#\s*include\s+"(include_asm|common)\.h".*$', "", text, flags=re.M)
    # Their unit_flags mixes compiler flags with flags for their own assembler
    # shim (`--keep-large-ori`). Passing one of those to cc1psx is a hard error
    # that reads as "this function does not port" -- func_800136E4 is 0/2 once
    # the flag is dropped. Allowlist what cc1psx takes.
    ok = [f for f in (flags.get(unit) or ["-G8"]) if CC1_OK.match(f)]
    return text, list(B.CC1_FLAGS[:1]) + ["-O2"] + (ok or ["-G8"])


RESULT_RE = re.compile(r"(\d+) target instruction\(s\), (\d+) built")
INCOMPLETE_RE = re.compile(
    r"`([A-Za-z_][A-Za-z_0-9]*)' has an incomplete type"
    r"|conflicting types for `([A-Za-z_][A-Za-z_0-9]*)'"
    r"|subscripted value is neither array nor pointer")


def available_guards():
    """Symbols in our headers that already have an `#ifdef SYM_IS_SCALAR` arm.

    Their tree declares globals as plain scalars inline; ours often declares the
    same symbol as an unsized array, because the array form is what makes cc1psx
    emit a %hi/%lo pair. Assigning to one is `incomplete type`. Where a scalar
    arm already exists the fix is free; where it does not, the port needs a new
    guard arm in variables.h -- a header edit, which goes in ONE AT A TIME with a
    full build, because two files disagreeing about a symbol breaks matching in
    functions that have nothing to do with this one.
    """
    text = (ROOT / "include" / "variables.h").read_text(errors="replace")
    out = {}
    for suffix in ("IS_SCALAR", "IS_AGGREGATE"):
        for sym in re.findall(r"(?:#ifdef|defined\()\s*([A-Za-z_0-9]+)_" + suffix, text):
            out.setdefault(sym, []).append(suffix)
    return out


GUARDS = available_guards()


def run_try(func, path, cc1flags):
    r = subprocess.run(
        [str(B.VENV_PYTHON), str(ROOT / "tools_src" / "try_func.py"), func, str(path)] + cc1flags,
        capture_output=True, text=True, cwd=ROOT,
    )
    return r.stdout + r.stderr


def _named(out):
    return sorted({a or b for a, b, in
                   ((m.group(1), m.group(2)) for m in INCOMPLETE_RE.finditer(out)) if a or b})


def measure(func, path, cc1flags):
    """Measure, and on an `incomplete type` error retry once with the scalar
    guards our headers already provide. Anything still failing reports the
    symbols that would need a new arm, so the header queue comes out of the
    same run rather than out of a second reading."""
    base = path.read_text()
    out = run_try(func, path, cc1flags)
    need = _named(out)
    for suffix in ("IS_SCALAR", "IS_AGGREGATE"):
        if not need:
            break
        have = [s for s in need if suffix in GUARDS.get(s, ())]
        if not have:
            continue
        path.write_text("".join("#define %s_%s\n" % (s, suffix) for s in have) + base)
        out2 = run_try(func, path, cc1flags)
        if not _named(out2):
            out, need = out2, []
            break
        out, need = out2, _named(out2)
    lines = [l for l in out.splitlines() if l.strip()]
    if lines and lines[-1].strip().endswith("MATCH"):
        return ("MATCH", 0, 0, need)
    m = RESULT_RE.search(out)
    if not m:
        return ("ERROR", None, None, need)
    tgt, built = int(m.group(1)), int(m.group(2))
    d = re.search(r"(\d+) differing instruction", out)
    return ("OK", built - tgt, int(d.group(1)) if d else None, need)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--tree", required=True, help="root of the other decomp tree")
    ap.add_argument("--func", help="one function, e.g. func_80012B50")
    ap.add_argument("--all", action="store_true")
    ap.add_argument("--calibrate", type=int, metavar="N",
                    help="N functions this tree ALREADY matches -- the only honest "
                         "way to tell a portable candidate from a broken harness")
    ap.add_argument("--out", help="write a TSV manifest here")
    ap.add_argument("--keep-externs", action="store_true")
    args = ap.parse_args()

    tree = Path(args.tree)
    units, syms, flags = their_units(tree), their_symbols(tree), their_flags(tree)
    ours = {int(p.name[5:-2], 16) for p in (ROOT / "src").glob("func_*.c")}
    scratch = ROOT / "build" / "transplant"
    scratch.mkdir(parents=True, exist_ok=True)

    if args.func:
        targets = [int(args.func[5:], 16)]
    elif args.calibrate:
        targets = sorted(a for a in units if a < SCOPE and a in ours)[: args.calibrate]
    else:
        targets = sorted(a for a in units if a < SCOPE)

    rows = []
    for addr in targets:
        unit = units[addr]
        func = "func_%08X" % addr
        p = port(tree, addr, unit, syms, flags, args.keep_externs)
        if p is None:
            rows.append((func, unit, "STUB", "", "", "", ""))
            print("%-16s %-40s STUB" % (func, unit), flush=True)
            continue
        text, cc1 = p
        f = scratch / (func + ".c")
        f.write_text(text)
        status, lenerr, diffs, need = measure(func, f, cc1)
        have = "ours:MATCH" if addr in ours else "ours:-"
        rows.append((func, unit, status, lenerr, diffs, " ".join(cc1[2:]), ",".join(need)))
        print("%-16s %-38s %-6s len%4s diff%-5s %-26s %-10s %s"
              % (func, unit[:38], status,
                 "" if lenerr is None else lenerr,
                 "" if diffs is None else diffs,
                 " ".join(cc1[2:]), have, ",".join(need)), flush=True)

    if args.out:
        with open(args.out, "w") as fh:
            fh.write("func\tunit\tstatus\tlen_err\tdiffs\tflags\tneeds_guard\n")
            for r in rows:
                fh.write("\t".join(str(x) for x in r) + "\n")
        print("wrote %s (%d rows)" % (args.out, len(rows)), flush=True)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
