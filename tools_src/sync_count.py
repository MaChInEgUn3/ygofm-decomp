#!/usr/bin/env python3
"""
Rewrite the function count in docs/DECISIONS.md from the actual source tree.

    python tools_src/sync_count.py

Typed by hand twice and wrong both times -- once claiming 338 when the build
said 337, once 356 when it said 355. The count changes on every batch and is
easy to update from the number you expected rather than the one you got, so it
is now derived from `ls src/func_*.c` instead.
"""

import glob
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DOC = os.path.join(ROOT, "docs", "DECISIONS.md")


def main():
    n = len(glob.glob(os.path.join(ROOT, "src", "func_*.c")))
    text = open(DOC, encoding="utf-8").read()
    new, hits = re.subn(r"\d+ of 1794 functions decompiled and byte-matching\.",
                        f"{n} of 1794 functions decompiled and byte-matching.", text)
    new, hits2 = re.subn(r"of which ~\d+ are done", f"of which ~{n} are done", new)
    if new != text:
        with open(DOC, "w", encoding="utf-8", newline="\n") as f:
            f.write(new)
    print(f"{n} functions; {hits + hits2} mention(s) synced")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
