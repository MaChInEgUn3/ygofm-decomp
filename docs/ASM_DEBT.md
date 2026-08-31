# Assembly debt

53 of the functions in `src/` are **transcriptions, not decompilations**. The
body is the retail instruction stream written out as inline `__asm__`. Every
one of them is byte-exact, which is precisely why they need a file of their
own: `build.py` cannot tell transcribed assembly from real C, so nothing
except an explicit marker stops them being counted as finished work.

    grep -l 'ASSEMBLY DEBT' src/*.c | wc -l

All 53 came in with the port from Unchiga's tree, where they are tracked as
known debt and intended to be paid back before that project calls itself done.
He said so before anyone asked, and his own `OVERSEER.md` ranks it second of
three priorities, above speed:

> *"A function matched as real C and one transcribed into an inline `__asm__`
> block are both 0-diff — the oracle cannot tell them apart. Only the first is
> readable, portable, or usable by anything that has to run this code later."*

That is the right framing and this file exists to hold us to the same standard.
The point was made sharply by krystalgamer on 2026-08-30, who spotted one on
sight in the shared repo; the honest response is not to argue about it but to
count them, mark them, and say the number out loud.

## What is NOT debt

**Inline asm for the GTE is legitimate and stays.** 44 further files carry
`lwc2` / `swc2` / `mtc2` / `rtps` and similar coprocessor-2 instructions, which
C has no operators for — the PsyQ SDK ships them as inline-asm macros itself,
and this repo has `include/gte_macros.inc` for the same reason. A file is debt
here only when ordinary MIPS — loads, stores, arithmetic, branches, a `.word`
stream, a `.global`, branch labels — appears inside the asm.

The split, counted mechanically rather than by eye:

| | files |
|---|---|
| real C, no inline asm | 953 |
| C plus GTE coprocessor asm | 44 |
| **assembly transcription (debt)** | **53** |
| total in `src/` | 1050 |

So the honest headline is **997 decompiled**, not 1050, and of the 926 counted
in scope by `README.md`, 53 are transcriptions. All 53 are below the
`0x80073840` cut, so none of them is out-of-scope library code that would
excuse the shortcut.

## Paying it back

A transcription is a *better* starting point than nothing: the extent is
carved, the symbol is right, the flags are known, and the listing is already
beside it. Rewriting one is the ordinary matching loop with the answer's shape
visible — `tools_src/msearch.py` and the levers in `docs/WORKFLOW.md` apply
unchanged.

The order to take them in is by size, smallest first, and the list regenerates
itself:

    grep -l 'ASSEMBLY DEBT' src/*.c \
      | sed 's|src/||;s|\.c$||' \
      | while read f; do printf '%6d %s\n' \
          "$(grep -c '' asm/nonmatchings/31D8/$f.s)" "$f"; done | sort -n

When one is rewritten, delete the marker comment with the asm — the count
above is the progress meter, and it should only ever go down.
