# Assembly debt

**11** of the functions in `src/` are **transcriptions of compiler output** that are owed as C (18 when this section was written on 2026-09-04; `tools_src/asm_debt.py` is the count, this line is a copy) -- the assembly debt proper. A further **52** are transcriptions of code that was **hand-written assembly in the original** and can never be C; they stay as asm by design and are not debt (see the 2026-09-04 section below; the headline used to read 76 and lumped the two together). The
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


## The port DELETED the pure C it replaced, and git still has it

**22 of the 76 transcriptions had a `parked/<func>.c` that the Unchiga merge
removed.** Fourteen of those are pure C with no `asm` of any kind, they still
compile, and re-measured on 2026-09-04 they rank:

    2   func_8005A98C  133/133      13  func_8004A854  36/36
    3   func_8003A198   21/21       16  func_80024D34  37/37
    6   func_8004A764   23/23       17  func_8004A8E4  23/23
    8   func_80070710   10/10       18  func_8002C7E8  84/84
    11  func_80016DDC   37/37       18  func_80032370  34/34
                                    22  func_8002ABB4  60/60
                                    24  func_8002C604  34/34

plus four carrying a length error (func_8004CA60, func_8002CBF4,
func_8001D5B4, func_8004BCE8). All fourteen are restored to `parked/`.

**func_8005A98C came back and was retired the same hour**, on one line -- see
its PARKED.txt entry. A 133-instruction function sat as transcribed assembly
for five days while C that was two register names away sat in git history.

Two things follow, and the second is the one that costs.

**Recover before you re-derive.** func_8003A198 was re-derived from scratch
first: four independent pure-C shapes, all at exact length, best **8**. The
recovered candidate is **3**, and its two levers -- nested `if`s for a shared
exit, and a dead store acting as an allocation hint -- are not reachable by
inspection. An unaided rewrite lands nowhere near what was already known.

**A merge that improves the headline number can destroy work silently.** The
port took the function count up and the honest count down, and it deleted the
evidence in the same commit, so nothing in the tree recorded the trade. The
only reason it is visible now is `git log --diff-filter=D`. Run that sweep
against `parked/` after ANY bulk import, not five days later.


## Two populations, and only one of them is debt (2026-09-04)

`asm_debt.py` counted 70 transcriptions. Reading their retail listings rather
than their C files splits them cleanly, on a criterion no C compiler crosses:

| | frame (`addiu $sp`) | `sw $ra` | `jal` | `$s` saved off-stack | distinct s/t regs | cop2 insns |
|---|---|---|---|---|---|---|
| 52 functions, all `0x8006xxxx` | **none** | **none** | **0** | **4 to 10** (into the caller's struct) | 13-18 | 8-39 |
| 18 functions | frame or call in every one | | | 0 | | 0-4 |

gcc 2.8.1 never saves callee-saved registers into a data structure, never
emits a leaf with ten live `$s`/`$t` registers and no frame, and never writes
a 39-instruction coprocessor sequence. The 52 are the GTE ordering-table
inserters the original shipped as hand-written assembly, exactly as WORKFLOW's
`candidates.HAND_WRITTEN` note said of the block. They are not owed as C and
they are not "unfinished": they are finished, as asm, the way the original
was. krystalgamer's inventory reached the same verdict independently -- all
52 carry `handwritten_asm` in his `functions.csv`, and none of our 18 do.

So the honest count moves from 1019 to **1071**, and the debt from 70 to
**18**, of which 14 already have real C in `parked/` (one at a single
difference). `asm_debt.py` now applies the criterion itself
(`hand_written_original`) and reports the two buckets separately.

**The trap this corrects.** `candidates.HAND_WRITTEN` is a mnemonic regex
(`wc2|rtps|mfc2|mtc2|...`), and it puts func_80015DFC and func_800177C4 on
the hand-written side -- both are compiled code that reaches the GTE through
what became `include/gte.h`, and both now have real C (one retired, one at
-1). A function that USES the coprocessor is not a function that WAS written
by hand; the frame and the call are the tell, not the mnemonic. Four of the
18 are matched as C in krystalgamer's tree, which is the next thing to look
at.
