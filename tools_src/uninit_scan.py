#!/usr/bin/env python3
"""Find a local that is READ but never assigned, in src/ and parked/.

    tools_src/uninit_scan.py

Why this exists
---------------
The permuter's most productive reject shape is a variable read before it is
written: WORKFLOW records three of them (an assignment placed between a
`break;` and the next `case:`, a `new_var` compared before assignment, a
deleted initialiser) and calls each a diagnosis rather than a candidate.
Nothing stopped one being INSTALLED, because an uninitialised read compiles,
scores, and can even score well.

One was. parked/func_800222F4.c stored through `g`, a name declared and never
written anywhere in the function, carried in from the permuter output the park
was decomposed from, and it sat there for four days at 24 differences. The
honest reading -- the call result -- is 23, so the unsound spelling was not
even buying the difference it appeared to cost nothing for.

This is the detector that would have caught it on the day. First run
(2026-09-07) over 89 parked candidates and 1107 sources: that one hit, and
three false positives it now filters (two locals assigned through an
`__asm__` output operand, one struct field called `pad0`).

A hit is not automatically a bug -- read it. What it is, always, is a claim
about the original source that nobody made on purpose.

The first version of this tool reported ZERO on the very file that motivated
it, and a control probe -- break a file on purpose, check the tool says so --
is what caught that. `*(u16 *)g = 0xA0;` contains the characters `g = 0xA0`,
so the naive "is NAME ever followed by `=`" test excuses a store THROUGH the
pointer, which is the commonest way an uninitialised pointer is used. Whenever
this file changes, re-run the probe: add `u8 *zz;` to a candidate, store
through it, and confirm the tool names it. A filter that cannot say "yes" has
not said "no".
"""
import glob
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DECL = re.compile(r'^\s{4}(?:u8|s8|u16|s16|u32|s32|f32)\s+\*?\s*(\w+)\s*;', re.M)


def strip_type_bodies(s):
    """Remove every `struct`/`union` body, braces matched.

    A field declared in a typedef looks exactly like a local to the regex
    below, and the two struct fields both called `pad0` in
    src/func_80045334.c are why this is done by brace matching rather than
    by a non-greedy pattern: a nested body ends the wrong `}`."""
    out, i = [], 0
    for m in re.finditer(r'\b(?:struct|union)\b[^;{]*\{', s):
        if m.start() < i:
            continue
        out.append(s[i:m.start()])
        d, j = 0, m.end() - 1
        while j < len(s):
            if s[j] == '{':
                d += 1
            elif s[j] == '}':
                d -= 1
                if d == 0:
                    break
            j += 1
        i = j + 1
    out.append(s[i:])
    return ''.join(out)


def assigned(s, n):
    """True if NAME is written as a whole lvalue anywhere in S."""
    for m in re.finditer(r'(\S?)\s*\b' + n + r'\s*(?:=[^=]|\+\+|--|[-+*/&|^]=|<<=|>>=)', s):
        # `)` is a cast (`*(u16 *)g = ...`), `*` a dereference, `.`/`>` a
        # member, `-` the tail of `->`. None of those write the name itself.
        if m.group(1) not in (')', '*', '.', '>', '-'):
            return True
    return False


def suspects(path):
    s = open(path).read()
    s = re.sub(r'/\*.*?\*/', '', s, flags=re.S)
    s = re.sub(r'//[^\n]*', '', s)
    s = strip_type_bodies(s)
    out = []
    for m in DECL.finditer(s):
        n = m.group(1)
        # A struct field, not a local: the file declares a type whose member
        # has this name and reaches it through `.` or `->`.
        if re.search(r'[.>]\s*' + n + r'\b', s):
            continue
        # Assigned, incremented, or compound-assigned somewhere -- but a
        # STORE THROUGH the name is not an assignment TO it, and that is the
        # whole difficulty. `*(u16 *)g = 0xA0;` contains the characters
        # `g = 0xA0`, so a bare `name =` test excuses exactly the shape this
        # tool exists to find; the first version of it did, and a control
        # probe that deliberately broke a file was what said so. Require the
        # character before the name to be one that can precede an lvalue.
        if assigned(s, n):
            continue
        # Address taken -- an out-parameter writes it.
        if re.search(r'&\s*' + n + r'\b', s):
            continue
        # Written by an inline asm output operand.
        if re.search(r'"[^"]*"\s*\(\s*' + n + r'\s*\)', s):
            continue
        if len(re.findall(r'\b' + n + r'\b', s)) > 1:
            out.append(n)
    return out


def main():
    hits = 0
    files = sorted(glob.glob(os.path.join(ROOT, 'parked', '*.c')))
    files += sorted(glob.glob(os.path.join(ROOT, 'src', 'func_*.c')))
    for f in files:
        for n in suspects(f):
            hits += 1
            print(f'{os.path.relpath(f, ROOT)}: `{n}` is read and never assigned',
                  flush=True)
    print(f'{len(files)} files checked, {hits} suspect(s)', flush=True)
    return 1 if hits else 0


sys.exit(main())
