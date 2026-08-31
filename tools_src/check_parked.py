#!/usr/bin/env python3
"""
Hold PARKED.txt to its own claim: an entry with no resolution marker must name
a function that is still open.

The park list is a work list -- WORKFLOW.md tells you to re-read it whenever a
new source-shape lever is measured -- and a work list whose entries are
silently already done is worse than no list, because it costs a reader's time
in exactly the state where they are looking for something to do. It rotted to
58 stale entries out of 214 before anyone counted, which is the same shape as
every other miscount in this project: nothing goes red when documentation
drifts, so only a check that runs finds it.

TWO STATES, AND CONFLATING THEM IS THE TRAP. "src/<f>.c exists and the build
is green" does NOT mean the function was decompiled: a transcription
(docs/ASM_DEBT.md) is byte-exact by construction and passes that test
identically. Ten of those 58 were transcriptions, and marking them RESOLVED
would have reproduced, inside the park list, the exact overcount krystalgamer
called out on 2026-08-31.

    .venv/bin/python tools_src/check_parked.py
"""

import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import asm_debt  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DONE = re.compile(r"MATCH(ED)?\b|RESOLVED|unparked")


def entries():
    """name -> full text, an entry running to the next column-0 func_ heading."""
    txt = open(os.path.join(ROOT, "docs", "PARKED.txt"), errors="replace").read()
    starts = [(m.start(), m.group(1))
              for m in re.finditer(r"(?m)^(func_[0-9A-Fa-f]{8})", txt)]
    out = {}
    for i, (pos, name) in enumerate(starts):
        end = starts[i + 1][0] if i + 1 < len(starts) else len(txt)
        out[name] = out.get(name, "") + txt[pos:end]
    return out


def main():
    unmarked_done, mismarked = [], []
    for name, body in entries().items():
        path = os.path.join(ROOT, "src", name + ".c")
        if not os.path.exists(path):
            continue
        real = asm_debt.classify(path) != "debt"
        if real and not DONE.search(body):
            unmarked_done.append(name)
        if not real and re.search(r"RESOLVED", body):
            mismarked.append(name)

    for name in sorted(unmarked_done):
        print("STALE   %s is matched in src/ but the entry does not say so" % name)
    for name in sorted(mismarked):
        print("WRONG   %s is marked RESOLVED but src/%s.c is a TRANSCRIPTION"
              % (name, name))
    print("%d entries; %d stale, %d mismarked" %
          (len(entries()), len(unmarked_done), len(mismarked)))
    return 1 if unmarked_done or mismarked else 0


if __name__ == "__main__":
    raise SystemExit(main())
