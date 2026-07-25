#!/usr/bin/env python3
"""
Make every prototype in include/functions.h agree with its definition.

    python tools_src/reconcile_protos.py

Prototypes get written from a guess when a caller is decompiled first, and the
guess is invisible until the callee itself is written -- at which point cc1psx
refuses to compile. That has happened five times, always costing a build. This
sweeps them instead.

The regex allows a `*` to bind directly to the name (`u8 *func_X(...)`). An
earlier version required whitespace there and silently skipped every
pointer-returning function while reporting success; see docs/DECISIONS.md.
"""

import glob
import io
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
HEADER = os.path.join(ROOT, "include", "functions.h")

DEFN = r"^([\w ]+?[\w \*]*?)\s*\b{}\((.*?)\)\s*\{{"
DECL = r"^[\w ]+?[\w \*]*?\b{}\(.*?\);(\s*/\* PROVISIONAL \*/)?$"


def main():
    text = open(HEADER, encoding="utf-8").read()
    fixed = []
    for path in sorted(glob.glob(os.path.join(ROOT, "src", "func_*.c"))):
        name = os.path.basename(path)[:-2]
        m = re.search(DEFN.format(name), open(path, encoding="utf-8").read(), re.M)
        if not m:
            continue
        ret, args = m.group(1).strip(), m.group(2).strip()
        want = (f"{ret}{name}({args});" if ret.endswith("*")
                else f"{ret} {name}({args});")
        pat = re.compile(DECL.format(name), re.M)
        found = pat.search(text)
        if found and found.group(0) != want:
            text = pat.sub(want.replace("\\", "\\\\"), text, count=1)
            fixed.append(name)
    if fixed:
        with io.open(HEADER, "w", encoding="utf-8", newline="\n") as f:
            f.write(text)
    print(f"{len(fixed)} prototype(s) reconciled"
          + (": " + ", ".join(fixed) if fixed else ""))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
