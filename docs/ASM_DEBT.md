# Assembly debt

**76** of the functions in `src/` are **transcriptions, not decompilations**. The
body is the retail instruction stream written out as inline `__asm__`. Every
one of them is byte-exact, which is precisely why they need a file of their
own: `build.py` cannot tell transcribed assembly from real C, so nothing
except an explicit marker stops them being counted as finished work.

    .venv/bin/python tools_src/asm_debt.py

All of them came in with the port from Unchiga's tree, where they are tracked as
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

**Inline asm for the GTE is not debt.** Five further files reach coprocessor 2
-- `lwc2` / `swc2` / `mtc2` / `rtps` -- which C has no operators for. A file is debt here only when ordinary MIPS — loads,
stores, arithmetic, branches, a `.global`, or a `.word` whose opcode field is
not COP2/LWC2/SWC2 — appears inside the asm.

**But "not debt" is not "right", and that correction came from outside.**
krystalgamer pointed out on 2026-08-31 that the PsyQ SDK ships these as macros
— `GTEMAC.H` and `INLINE_C.H` give `gte_ldv0()`, `gte_rtps()`, `gte_stsxy()` —
so a decomp calls those instead of hand-rolling the same instructions. All 21
of ours were hand-rolled. **Converted on 2026-08-31, build still hashing**:
`include/gte.h` keeps the SDK's names and operand conventions and routes them
through the mnemonics in `include/gte_macros.inc`. The SDK header itself cannot
be included -- `INLINE_C.H` is the DMPSX macro set and its command macros emit
a *cookie*, `nop; nop; .word 0x0000007f`, which our pipeline would assemble as
a literal word because it does not run Sony's `dmpsx` pass.

The split, counted mechanically rather than by eye:

| | files |
|---|---|
| real C, no inline asm | 969 |
| reaches the GTE (all via `gte_*` macros) | 5 |
| **assembly transcription (debt)** | **76** |
| total in `src/` | 1050 |

So the honest headline is **974 decompiled**, not 1050.

**This number was published wrong twice before it was published right, and the
two mistakes are worth more than the number.** The first pass classified by
"contains a `.word` stream and a `.global`" and missed a hand-encoded seven-word
call sequence in func_8004B854 that had neither: 53 counted, 54 true. The
second pass scanned every string literal in the file, so the *constraints and
clobbers* of legitimate GTE blocks (`"=r"`, `"r"`, `"memory"`, `"v0"`) were read
as instructions and it reported 96 of 97 files as debt. Only the instruction
template counts -- the strings before the first `:` at paren depth one.

**A third instance arrived with the GTE conversion itself**, and it is the
subtlest: converting a file to `gte_*` macros removes the word `__asm__` from
it, so sixteen files silently moved into the "real C" bucket and the split
drifted while the total stayed right. An empty template --
`__asm__ volatile("" ::: "memory")`, a compiler barrier that emits no words --
did the same thing from the other side, surviving every test because it
contains no offending mnemonic. A count with no oracle behind it is exactly
where a wrong answer lives; the classifier now keys on macro calls and on
non-empty templates, and the three-way control is in the script.

Both are the same failure this repo documents everywhere else: a tool
answering confidently about something it did not measure. The check that would
have caught either in a minute is the one now built into
`tools_src/asm_debt.py` -- run the classifier against a file you know is clean,
one you know is debt, and one you know is GTE, and see that it can say all
three words.

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


## Two counts, two questions -- do not mix them

`asm_debt.py` answers "how many functions are transcriptions rather than
decompilations", and its answer is **76**. That is the honest-progress number
and it is the one this file's headline uses.

It is **not** the number that decides what can be offered upstream, and reading
it as though it were cost a wrong figure in a pull-request comment on
2026-09-04. krystalgamer's external-candidate harness
(`tools/project/audit_unchiga_candidates.py`) rejects on

    ASM_PATTERN = re.compile(r"\b(?:asm|__asm|__asm__)\b")

applied to the **preprocessed** candidate, so anything carrying that token is
refused -- a register pin (`register s32 v1 asm("v1")`), an empty scheduling
barrier (`asm volatile("" :: "r"(v))`), and a GTE macro that expands to one,
none of which are transcription. By that criterion **155** of our 1089 files
are unofferable, twice the debt count.

So: 76 is what we owe ourselves, 155 is what we cannot hand over. A crude
`grep -c asm` answers the second question and gets mistaken for the first,
which is exactly the miscount this tool's own docstring was written to prevent
-- committed twice already, and now a third time from the other direction.
Quote the tool for debt and the pattern for portability, and say which you
mean.
