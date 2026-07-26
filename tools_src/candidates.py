#!/usr/bin/env python3
"""
List undecompiled functions worth attempting, cheapest first.

    python tools_src/candidates.py            # default band, 3 shown in full
    python tools_src/candidates.py 24 34 -n 5 # band and count
    python tools_src/candidates.py --count    # just the totals

Excludes, in order of how much time each used to waste:

  * PsyQ library functions (docs/LIBRARY_FUNCS.txt) and the library region
    above 0x80073840, both out of scope.
  * GTE and mult/div shapes, which are hand-written or need idioms not yet
    worked out.
  * Calls into PsyQ library functions, which need prototypes we do not have.
  * Functions already decompiled or parked.
  * **The two detectable closed-class signatures.** A same-basic-block
    duplicate %hi needs a symbol alias and usually an allocator disagreement
    on top; an adjacent blez/slti is the range-check fold. Neither is
    reachable from C, so attempting them is wasted effort -- filtering them
    out took a batch from 1-2 hits to 3 of 3. See docs/DECISIONS.md.

The register-allocation class has no target-side signature, so roughly a
third of what this prints will still miss. That is a fixed tax, not a sign
the list is exhausted.
"""

import glob
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ASM = os.path.join(ROOT, "asm", "nonmatchings", "31D8")
LIBRARY_REGION = 0x80073840

BRANCH = re.compile(r"\b(b(eq|ne|gez|gtz|lez|ltz|eqz|nez)?|j|jal|jr)\b")
# `break` and writes to $sp/$gp/$fp are the C runtime stubs (crt0, the
# constructor walker): assembly by construction, and two of them were
# offered as candidates before this was added.
HAND_WRITTEN = re.compile(r"wc2|rtps|mfc2|mtc2|\bmult\b|\bdiv\b|jr\s+\$v|jr\s+\$a"
                          r"|\bbreak\b|\bor\s+\$sp\b|\$fp,\s*\$sp|\$gp,\s*%hi")


def parked():
    """Names recorded as parked in the docs, so they are not re-offered."""
    path = os.path.join(ROOT, "docs", "PARKED.txt")
    if not os.path.exists(path):
        return set()
    return {l.split("#")[0].strip() for l in open(path) if l.strip()
            and not l.startswith("#")}


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
        if any(c in lib or not c.startswith("func_")
               for c in re.findall(r"jal\s+(\S+)", joined)):
            continue
        # Neither of the old drop rules is a "cannot match" any more.
        #
        # The range-check fold was retracted: it happens on the `&&`, and
        # writing the condition as nested `if`s keeps both comparisons. Three
        # functions came out of the park that way, so the filter is gone.
        #
        # Duplicate %hi for one symbol means retail materialised the address
        # twice, which config/symbol_aliases.txt plus a -G0 assembler can
        # reproduce. It is harder, not impossible, so these are listed last
        # and tagged rather than hidden -- 41 candidates were invisible while
        # the small bands looked depleted.
        dup = has_duplicate_hi(both)
        if dup:
            dropped["dup_hi"] += 1
        rows.append((dup, len(body), name, both))

    rows.sort()
    print(f"{len(rows) - dropped['dup_hi']} clean candidates in "
          f"{lo}-{hi} instructions, plus {dropped['dup_hi']} needing a symbol "
          f"alias (listed last, tagged dup-%hi)")
    if "--count" in sys.argv:
        return 0
    for dup, count, name, both in rows[:show]:
        tag = "  [dup-%hi: needs a symbol alias + -G0 assembler]" if dup else ""
        print(f"\n--- {name} ({count}){tag}")
        for _, text in both:
            print("   ", text)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
