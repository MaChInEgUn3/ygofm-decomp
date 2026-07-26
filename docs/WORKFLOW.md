# Yu-Gi-Oh! Forbidden Memories — matching decompilation

Byte-exact recompilation of `SLUS_014.11`. **Not** a reimplementation: every
function must assemble to the retail bytes. `DECISIONS.md` in this directory is the
full reference and is long; this file is the operational minimum — read it
first, then reach for DECISIONS.md when you need the reasoning behind a rule.

## Verify everything with the build

```
.venv/bin/python tools_src/build.py     # must end "OK: build is byte-identical"
```
sha1 `84747e64f6da8e764206ec203e489acf8c9dcf7d`. Always the project `.venv`,
never a bare `pip install` — installing globally once broke another tool's pins.

## Toolchain: PsyQ 4.5 (gcc 2.8.1, aspsx 2.79)

Not 4.6. That was assumed for the project's first 219 functions and produced a
byte-identical build anyway, because most functions are too small for the two
versions to differ. `YGOFM_PSYQ=46` selects 4.6 for comparison. `tools/` is
gitignored and must be re-fetched per machine.

## Adding a function

Write `src/func_XXXXXXXX.c` and rebuild; placement is automatic. Get candidates
from `tools_src/candidates.py`, which filters out signatures that cannot match.

**When it does not match, work in this order.** Each step makes the next
meaningful, and skipping to 5 wastes hours:

1. **Instruction count right?** Nothing else is diagnostic until it is. If a
   function is the wrong size, remove it before reading the rest of the report —
   the linker script is regenerated from object sizes, so one wrong size can
   move functions placed *earlier* as well as later.
2. **Read/declaration order.** The most common single fix here. Declaration
   order controls which callee-saved register a value gets, where a constant is
   materialised, whether an address is folded, and whether an initialiser
   competes with the prologue.
3. **Branch polarity.** cc1psx emits the fall-through for the branch written as
   not-taken — look at which path retail falls into.
4. **Count materialisations** of each value: one per write in the source. One
   `subu` reached by two paths means one `return`; two identical constants mean
   two `return`s; a value written at a join and copied to `$v0` at one exit is
   an accumulator variable.
5. **Then** `tools_src/sweep_flags.py`.

**Stop and park** when the only remaining difference is which register holds a
value, or when the target has more duplicated tails than you produce. Record the
name in `docs/PARKED.txt` with its class **and keep the candidate in
`parked/<func>.c`**.

Before parking on "one register differs", check whether a **call** separates the
definitions of the two values. gcc prioritises pseudos by frequency over live
range, so the longer-lived one lands in the later register: moving one definition
across the call flips the pair, and it flips nothing else in the output, which is
why this hides so well. That is verified on `func_80022FF0`. The class is closed
only for values with equal live ranges.

The third class this list used to name — the target keeping two comparisons
where cc1psx folds a range check — **is not closed**. The fold happens on the
`&&`; write it as nested `if`s and both comparisons survive.

Before parking anything, run `tools_src/sweep_try.py <func>`. It is the flag
sweep through try_func rather than a full build per combination, so it costs
seconds instead of half an hour, and two functions were parked for hours today
on a combination that had been in the table for weeks.

## Types and declarations

- Every global once in `include/variables.h`, every cross-file function in
  `include/functions.h`. Two files disagreeing breaks matching far away.
- **Hold values in the widest natural type; cast at the point of use.** A narrow
  type inside a computation costs an `andi` or a sign-extend — this has bitten
  parameters, return values, locals and loop counters.
- Scalar vs unsized array is a codegen choice. Three knobs when one function
  needs different addressing from another: `-G0`, an unsized-array declaration,
  or a per-file `#ifdef SYM_IS_SCALAR` guard in `variables.h`.
- `config/symbol_aliases.txt` gives an address a second name, for when retail
  materialises it twice inside one basic block. Needs a `-G0` assembler to be
  worth anything.

## Two habits that cost real time when skipped

**A tool's answer only counts if it measured what you think.** Six bugs in this
project were tools reporting confidently on something they had not measured — a
stale object, an unverified flag, a crashed build read as clean. When a tool
says "no", ask whether it could have said "yes"; when it says "yes", ask whether
the run it judged completed.

**Measure before concluding.** Claims here have been wrong by 4x from reasoning
over a handful of samples. Scan the whole binary before letting a pattern
justify a decision.

Run `tools_src/sync_count.py` before committing a batch — the count has been
typed wrong twice.
