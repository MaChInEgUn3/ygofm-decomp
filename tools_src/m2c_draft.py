#!/usr/bin/env python3
"""First-draft C for one function, via m2c (simonlindholm/m2c).

    tools_src/m2c_draft.py func_8004C5C8 [m2c flags...]

What it is for and what it is NOT for
-------------------------------------
m2c reads the splat listing and produces structurally-correct C: the loop and
switch shapes, the case groupings, reciprocal multiplies read back as `/ 3`,
the field offsets, the signedness of each load. On a 167-instruction function
that is the ten to fifteen minutes of hand-decoding the listing, done in a
second.

It does **not** close a match. Every lever in docs/WORKFLOW.md -- which
register holds a value, where a `lui` sits, whether a store sinks into a delay
slot -- is invisible to it, and that is where the hours go. Treat its output
as the draft you would have typed, then work the WORKFLOW list against it.

Two of its comments are worth reading rather than deleting:
  * "Duplicate return node #N. Try simplifying control flow for better match"
    -- it has spotted a tail that retail shares and it does not. That is the
    cross-jumping question (WORKFLOW step 5), and the answer is usually to
    write the tail out per arm instead of once after the switch.
  * "irregular" on a switch -- the case values are sparse, so gcc built a
    comparison tree rather than a jump table. No rodata hole to worry about.

m2c lives in `tools/m2c` with its own virtualenv, because it pins
pycparser 2.x and the permuter in the same tree needs 3.x. `tools/` is
gitignored; see docs/DECISIONS.md for the fetch.
"""
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
M2C = os.path.join(ROOT, "tools", "m2c")
PY = os.path.join(M2C, ".venv", "bin", "python")
ASM = os.path.join(ROOT, "asm", "nonmatchings", "31D8")
OUT = os.path.join(ROOT, "build", "m2c")

# m2c parses the context with pycparser, which is a C99 parser and knows
# neither of these GNU extensions. Both are noise for type extraction.
STRIP = (
    # One level of nested parentheses, for section(".data"): the lazy .*?
    # stopped at the first "))" inside the attribute and left a stray ")".
    (re.compile(r"__attribute__\s*\(\((?:[^()]|\([^()]*\))*\)\)"), ""),
    (re.compile(r"^\s*__asm__\s*\(.*?\)\s*;\s*$", re.M), ""),
)


def build_context():
    """Preprocess common.h into something pycparser will accept."""
    os.makedirs(OUT, exist_ok=True)
    ctx = os.path.join(OUT, "ctx.c")
    headers = [
        os.path.join(ROOT, "include", h)
        for h in ("common.h", "variables.h", "functions.h", "types.h")
    ]
    headers = [h for h in headers if os.path.exists(h)]
    if os.path.exists(ctx) and all(
        os.path.getmtime(ctx) > os.path.getmtime(h) for h in headers
    ):
        return ctx

    src = os.path.join(OUT, "ctx_in.c")
    with open(src, "w") as f:
        f.write('#include "common.h"\n')
    pre = subprocess.run(
        ["cpp", "-nostdinc", "-I" + os.path.join(ROOT, "include"), "-I" + ROOT,
         "-D__CHAR_UNSIGNED__", src],
        capture_output=True, text=True,
    )
    if pre.returncode != 0:
        sys.exit("cpp failed building the m2c context:\n" + pre.stderr)

    text = "\n".join(l for l in pre.stdout.split("\n") if not l.startswith("#"))
    for pat, rep in STRIP:
        text = pat.sub(rep, text)
    with open(ctx, "w") as f:
        f.write(text)
    return ctx


def _strip(src, dst):
    """splat's listings carry three bare words gas never sees: a
    "nonmatching <sym>, 0x1B4" header that m2c parses as an instruction, and
    endlabel/enddlabel terminators."""
    with open(src) as f, open(dst, "w") as g:
        for line in f:
            if line.startswith(("nonmatching ", "endlabel ", "enddlabel ")):
                continue
            g.write(line)
    return dst


def sanitise(func):
    path = os.path.join(ASM, func + ".s")
    if not os.path.exists(path):
        sys.exit("no listing: " + path)
    os.makedirs(OUT, exist_ok=True)
    return _strip(path, os.path.join(OUT, func + ".s"))


def rodata():
    """Jump tables. Without these m2c emits nothing at all for a `switch`
    compiled to a table -- it cannot see where the arms go. That is 5 of
    every 60 in-scope functions, and it is the `jr $v0` class WORKFLOW calls
    the largest one open."""
    out = []
    data = os.path.join(ROOT, "asm", "data")
    if not os.path.isdir(data):
        return out
    os.makedirs(OUT, exist_ok=True)
    for name in sorted(os.listdir(data)):
        if name.endswith(".rodata.s"):
            out.append(_strip(os.path.join(data, name),
                              os.path.join(OUT, name)))
    return out


def main():
    if len(sys.argv) < 2:
        sys.exit(__doc__)
    func = sys.argv[1]
    if not os.path.exists(PY):
        sys.exit(
            "m2c is not set up. See docs/DECISIONS.md; in short:\n"
            "  git clone --depth 1 https://github.com/simonlindholm/m2c.git tools/m2c\n"
            "  python3 -m venv tools/m2c/.venv\n"
            "  tools/m2c/.venv/bin/pip install 'pycparser>=2.21,<3' 'graphviz>=0.20'"
        )

    cmd = [PY, os.path.join(M2C, "m2c.py"), "-t", "mipsel-gcc-c",
           "--context", build_context(), "-f", func]
    cmd += sys.argv[2:]
    cmd.append(sanitise(func))
    cmd += rodata()

    env = dict(os.environ, PYTHONWARNINGS="ignore")
    r = subprocess.run(cmd, capture_output=True, text=True, env=env)
    sys.stdout.write(r.stdout)
    err = "\n".join(
        l for l in r.stderr.split("\n") if l.strip() and "SyntaxWarning" not in l
        and not l.strip().startswith(("f\"", "w.format", "c_label", "asm_label", "label ="))
    )
    if err:
        sys.stderr.write(err + "\n")
    return r.returncode


if __name__ == "__main__":
    sys.exit(main())
