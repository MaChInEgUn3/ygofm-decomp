#!/usr/bin/env python3
"""
Try every local-name substitution in a candidate and report improvements.

    python tools_src/sweep_borrow.py func_80038EB0
    python tools_src/sweep_borrow.py func_80038EB0 --list   # just show the locals

What it is for
--------------
The most productive lever of the last week is a BORROW: a value written
against the name of some other local whose live range is over, or has not
started. It ties the new value's pseudo to that name's allocation, and a FRESH
name in the same place is worth nothing at all -- measured every time.

Which name to borrow is not something to reason about. func_800220B8's step
constant borrowed `a` for 11 -> 9 and `v` for 9 -> MATCH, while `y` is -7 and
32; func_8005BFC8's constant gave 26/26/+1/24/18 across five candidates. The
difference between the winner and the next one is invisible in the source. So
sweep.

It is a search, not an argument: read the winner, check it is semantically
harmless -- renaming X to Y is only legal where their live ranges do not
overlap, and this tool does not know that -- and only then install it.

Reading the output
------------------
Rows print only when they beat the base on `(abs(length_error), differences)`,
which is try_func's own ordering: never compare counts across lengths.

**It always reports how many substitutions failed to compile.** The first
version of this file silently dropped every same-type substitution, because
renaming `a` to `b` left two `s32 b;` declarations and the compile error was
swallowed -- so it printed a confident "0 better than the base" having tested
almost nothing. That is this repo's oldest recurring bug (see WORKFLOW: "when
a tool says no, ask whether it could have said yes"), and the failure counter
is here so it cannot happen quietly again. A run where `failed` is large is a
run that measured nothing.
"""
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PY = os.path.join(ROOT, ".venv", "bin", "python")
TRY = os.path.join(ROOT, "tools_src", "try_func.py")

# `type name;` or `type *name;` or `type name[N];` -- the type and the name
# must be separated by whitespace or a star, which is what the first version
# got wrong: `\s*` let `return;` parse as type `retur` plus name `n`, and
# `goto have;` as type `goto` plus name `have`.
DECL = re.compile(r"^\s+(?:const\s+|volatile\s+|unsigned\s+|signed\s+)*"
                  r"[A-Za-z_][A-Za-z_0-9]*"
                  r"(?:\s+\*+|\s*\*+\s*|\s+)"
                  r"([A-Za-z_][A-Za-z_0-9]*)\s*(?:\[[^\]]*\])?\s*;\s*$")


def measure(func, path):
    """(abs length error, differences), or None if it did not compile."""
    r = subprocess.run([PY, TRY, func, path], capture_output=True, text=True,
                       cwd=ROOT)
    lines = r.stdout.strip().split("\n")
    err = 0
    for line in lines[-3:]:
        m = re.search(r"LENGTH DIFFERS by ([+-]?\d+)", line)
        if m:
            err = abs(int(m.group(1)))
    for line in reversed(lines):
        if "MATCH" in line:
            return (err, 0)
        m = re.search(r"(\d+) differing", line)
        if m:
            return (err, int(m.group(1)))
    return None


def declarations(text):
    """[(name, line)] for the function's own declaration block only.

    Scans from the body's opening brace and stops at the first line that is
    neither a declaration nor blank, which is where the statements begin. That
    bound is what keeps `goto`s and `return`s out of the list.
    """
    i = text.index("{\n") if "{\n" in text else 0
    out = []
    for line in text[i:].split("\n")[1:]:
        if not line.strip():
            continue
        m = DECL.match(line)
        if not m:
            break
        # keep the type text too, so same-type pairs can be preselected
        head = line.rstrip()[:line.rstrip().rindex(m.group(1))]
        # the star count is part of the type: `u8 **c` and `u8 *e` are not
        # interchangeable and renaming one to the other will not compile
        out.append((m.group(1), tuple(head.replace("*", " ").split())
                    + ("*" * head.count("*"),)))
    return out


def brace_blocks(text):
    """(start, end) of every brace-delimited block in the function body,
    outermost first, INCLUDING the body itself.

    A borrow is local by construction -- it is "write this value against that
    other name *here*" -- so a whole-function rename cannot find one. The first
    version of this file did exactly that and its control run missed a known
    MATCH (func_800220B8's `a` -> `v`, which is a rename inside one `else`
    arm). Scope every substitution to a block and the control passes.
    """
    out, stack = [], []
    for i, ch in enumerate(text):
        if ch == "{":
            stack.append(i)
        elif ch == "}" and stack:
            lo = stack.pop()
            out.append((lo, i + 1))
    return sorted(out)


def main():
    if len(sys.argv) < 2:
        sys.exit(__doc__)
    func = sys.argv[1]

    src = os.path.join(ROOT, "parked", func + ".c")
    if not os.path.exists(src):
        src = os.path.join(ROOT, "src", func + ".c")
    if not os.path.exists(src):
        sys.exit(f"no candidate for {func} in parked/ or src/")
    base_text = open(src).read()
    decls = declarations(base_text)

    if "--list" in sys.argv:
        for name, ty in decls:
            print(f"  {name:<12} {' '.join(ty)}")
        return 0

    base = measure(func, src)
    if base is None:
        sys.exit(f"{src} does not compile; fix that first")
    print(f"{func}: base {base[1]} differing"
          f"{'' if base[0] == 0 else f' at length error {base[0]}'}, "
          f"{len(decls)} locals")

    scratch = os.path.join(ROOT, "build", "scratch")
    os.makedirs(scratch, exist_ok=True)
    probe = os.path.join(scratch, f"borrow_{os.getpid()}.c")

    cap = int(sys.argv[sys.argv.index("-n") + 1]) if "-n" in sys.argv else 300
    # Smallest blocks first: a borrow is a local edit, and the innermost arms
    # are where every one found so far has lived. The outermost block is a
    # whole-function rename, which the control run proves cannot find one.
    blocks = sorted(brace_blocks(base_text), key=lambda t: t[1] - t[0])
    print(f"{len(blocks)} brace blocks, smallest first, cap {cap} runs")

    tried = failed = hits = skipped = 0
    seen = set()
    for lo, hi in blocks:
        for a, a_ty in decls:
            for b, b_ty in decls:
                # Only same-type pairs. Renaming across types is a compile
                # error, and letting those run is how the first control put a
                # 25% failure rate on an otherwise good search.
                if a == b or a_ty != b_ty:
                    continue
                blk = base_text[lo:hi]
                new_blk = re.sub(rf"\b{re.escape(a)}\b", b, blk)
                if new_blk == blk:
                    continue
                text = base_text[:lo] + new_blk + base_text[hi:]
                if text in seen:
                    continue
                seen.add(text)
                if tried >= cap:
                    skipped += 1
                    continue
                open(probe, "w").write(text)
                got = measure(func, probe)
                tried += 1
                if got is None:
                    failed += 1
                    continue
                if got < base:
                    hits += 1
                    print(f"  block @{lo:<6} {a:>8} -> {b:<8}  {got[1]} differing"
                          f"{'' if got[0] == 0 else f'  (length error {got[0]})'}")
    print(f"{tried} substitutions tried, {failed} failed to compile, "
          f"{hits} better than the base."
          + (f"  {skipped} NOT TRIED (cap; raise with -n)." if skipped else ""))
    if failed > tried // 4:
        print("WARNING: most substitutions did not compile. This run measured\n"
              "almost nothing -- do not read the result as a negative.")
    elif not hits:
        print("Clean negative over what was tried"
              + (", but the cap bit -- this is NOT a negative for the whole\n"
                 "function. Raise -n before believing it." if skipped else
                 ": nothing to install."))
    else:
        print("Check each winner is semantically harmless before installing:\n"
              "renaming X to Y is only legal where their live ranges do not\n"
              "overlap, and this tool does not know that.")
    if os.path.exists(probe):
        os.remove(probe)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
