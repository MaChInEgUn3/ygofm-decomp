#!/usr/bin/env python3
"""
Give each arm of a `switch` its own name for a shared local, and measure.

    python tools_src/sweep_arm_split.py func_80057544
    python tools_src/sweep_arm_split.py func_8002BD0C --list

What it is for
--------------
A local used in several arms of a `switch` is ONE pseudo whose live range
spans the whole switch, so gcc's global allocator gives it a register of its
own and every arm's allocation rotates behind it. One name per arm gives short
block-local ranges, which is what the target usually has. Measured on
func_80057544: five names for the D_8009B0F4 read is 53 differences to 29.

The mirror is measured too, and it is why this is a SWEEP and not a rule:
splitting the mask the same way is 29 -> 42 and splitting the record pointer
is 29 -> 34, because retail really does carry those two in one register across
every arm. Which variables want it differs *within one function*, so the only
way to know is to try each one.

What it will and will not offer
-------------------------------
A rename is legal only where the arm both writes the name before reading it
and never hands the value to another arm. The tool therefore offers a split
for an arm only when

  * the name's first occurrence in that arm is a plain `name = ` assignment
    (not `name op= `, not a read), and
  * every occurrence in that arm is BEFORE the arm's first label, so nothing
    reached by a `goto` from elsewhere can see the new name.

That is conservative, and it deliberately cannot find the other shape -- a
name shared by a *group* of arms that jump to one join label (func_8002BD0C's
`n`, which wants one name for the join1 group and another for the join2
group). Do that one by hand.

It is still a search, not an argument. Read the winner and check the live
ranges yourself before installing.

Control (run it after ANY change to this file)
----------------------------------------------
Reconstruct func_80057544's shared-name state by collapsing t0..t4 back to a
single `t` (and its five declarations to one), and this tool must report
`ALL ARMS  t split` at the installed candidate's own count or better -- as of
2026-08-28 that is a base of 50 and a win of 26. A run that finds nothing
there is a broken tool, not a negative.

func_8003C328 is the second control, for the label-delimited arms: it has
three `goto`-reached arms and the tool must SEE them (`--list` prints three
arms, not "no switch arms").
"""
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PY = os.path.join(ROOT, ".venv", "bin", "python")
TRY = os.path.join(ROOT, "tools_src", "try_func.py")

DECL = re.compile(r"^\s+(?:const\s+|volatile\s+|unsigned\s+|signed\s+)*"
                  r"[A-Za-z_][A-Za-z_0-9]*"
                  r"(?:\s+\*+|\s*\*+\s*|\s+)"
                  r"([A-Za-z_][A-Za-z_0-9]*)\s*(?:\[[^\]]*\])?\s*;\s*$")


def measure(func, path):
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
    i = text.index("{\n") if "{\n" in text else 0
    out = []
    for line in text[i:].split("\n")[1:]:
        if not line.strip():
            continue
        m = DECL.match(line)
        if not m:
            break
        out.append((m.group(1), line))
    return out


def arms(text):
    """[(label, start, end)] for each top-level arm.

    An arm runs from its own `case` line to the next one, so consecutive
    `case A: case B:` labels collapse into a single arm, which is right --
    they are one block.

    A plain statement label counts too. Most of the D_8009B0F4 dispatcher
    family is an `if`/`else` chain with `goto m0;` / `goto m1;` rather than a
    `switch`, and the arms are exactly the same thing one level down; without
    this the tool reported "no switch arms" on two thirds of the family. A
    label-delimited arm is only offered for splitting when it ENDS in
    `return` or `break` and contains no `goto` -- see splittable() -- because
    an arm that falls through or jumps to a shared tail can hand its value to
    a block that still uses the old name.
    """
    marks = [(m.start(), m.group(1))
             for m in re.finditer(
                 r"\n *(case [^:\n]+|default|[A-Za-z_][A-Za-z_0-9]*):"
                 r"(?=\s*\n)", text)]
    if not marks:
        return []
    out = []
    for k, (pos, lab) in enumerate(marks):
        end = marks[k + 1][0] if k + 1 < len(marks) else text.rindex("}")
        if out and out[-1][2] == pos and not text[out[-1][1]:pos].strip().endswith(":"):
            pass
        out.append((lab, pos, end))
    # collapse a `case A:` whose body is only the next `case B:` label
    merged = []
    for lab, lo, hi in out:
        body = re.sub(r"\n *(case [^:\n]+|default):", "", text[lo:hi]).strip()
        if not body and merged:
            merged[-1] = (merged[-1][0] + " " + lab, merged[-1][1], hi)
        else:
            merged.append((lab, lo, hi))
    return merged


def splittable(block, name, rest=""):
    """Is renaming `name` inside this one arm safe and meaningful?

    `rest` is everything after the arm -- needed for a label-delimited arm,
    where control can leave through a `goto` or by falling into the next
    label carrying the value.
    """
    occ = list(re.finditer(r"\b%s\b" % re.escape(name), block))
    if len(occ) < 2:
        return False
    first = occ[0]
    after = block[first.end():first.end() + 8]
    if not re.match(r"\s*=[^=]", after):
        return False            # first use is a read, or a compound assign
    lab = re.search(r"\n *[A-Za-z_][A-Za-z_0-9]*:(?=\s*\n)", block[1:])
    if lab and occ[-1].start() > lab.start() + 1:
        return False            # something after a goto target would be renamed
    if not block.lstrip().startswith(("case ", "default:")):
        # A label-delimited arm: control can leave it through a `goto` or by
        # falling into the next label, so the value must not be readable
        # anywhere it can reach. An arm that ends in `return`/`break` and
        # contains no `goto` is closed and always safe; otherwise the name
        # must not appear in the rest of the function at all.
        closed = (not re.search(r"\bgoto\b", block)
                  and re.search(r"\n *(return[^\n]*|break);\s*$",
                                block.rstrip()))
        if not closed and re.search(r"\b%s\b" % re.escape(name), rest):
            return False
    return True


def main():
    if len(sys.argv) < 2:
        sys.exit(__doc__)
    func = sys.argv[1]
    src = os.path.join(ROOT, "parked", func + ".c")
    if not os.path.exists(src):
        src = os.path.join(ROOT, "src", func + ".c")
    if not os.path.exists(src):
        sys.exit(f"no candidate for {func} in parked/ or src/")
    text = open(src).read()
    decls = declarations(text)
    blocks = arms(text)
    if not blocks:
        sys.exit(f"{func} has no switch arms; this tool has nothing to do")

    if "--list" in sys.argv:
        print(f"{len(blocks)} arms, {len(decls)} locals", flush=True)
        for lab, lo, hi in blocks:
            names = [n for n, _ in decls if splittable(text[lo:hi], n, text[hi:])]
            print(f"  {lab:<28} splittable: {' '.join(names) or '-'}", flush=True)
        return 0

    base = measure(func, src)
    if base is None:
        sys.exit(f"{src} does not compile; fix that first")
    print(f"{func}: base {base[1]} differing"
          f"{'' if base[0] == 0 else f' at length error {base[0]}'}, "
          f"{len(blocks)} arms, {len(decls)} locals")

    scratch = os.path.join(ROOT, "build", "scratch")
    os.makedirs(scratch, exist_ok=True)
    probe = os.path.join(scratch, f"armsplit_{os.getpid()}.c")

    tried = failed = hits = 0
    for name, decl_line in decls:
        # one arm at a time, then all splittable arms at once
        cands = [(lab, lo, hi) for lab, lo, hi in blocks
                 if splittable(text[lo:hi], name, text[hi:])]
        if not cands:
            continue
        for pick in [[c] for c in cands] + ([cands] if len(cands) > 1 else []):
            new = text
            fresh = []
            for k, (lab, lo, hi) in enumerate(reversed(pick)):
                nn = f"{name}_{len(pick) - 1 - k}"
                fresh.append(nn)
                new = (new[:lo]
                       + re.sub(r"\b%s\b" % re.escape(name), nn, new[lo:hi])
                       + new[hi:])
            extra = "".join(decl_line.replace(name, n) + "\n" for n in fresh)
            new = new.replace(decl_line + "\n", decl_line + "\n" + extra, 1)
            open(probe, "w").write(new)
            got = measure(func, probe)
            tried += 1
            if got is None:
                failed += 1
                continue
            if got < base:
                hits += 1
                where = "ALL ARMS" if len(pick) > 1 else pick[0][0]
                print(f"  {where:<28} {name:>8} split  {got[1]} differing"
                      f"{'' if got[0] == 0 else f'  (length error {got[0]})'}")
    print(f"{tried} splits tried, {failed} failed to compile, "
          f"{hits} better than the base.")
    if failed > tried // 4:
        print("WARNING: most splits did not compile. This run measured almost\n"
              "nothing -- do not read the result as a negative.")
    elif not hits:
        print("Clean negative: nothing to install.", flush=True)
    else:
        print("Check each winner by hand: a split is only legal where the arm\n"
              "writes the name before reading it and hands it to nobody else.")
    if os.path.exists(probe):
        os.remove(probe)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
