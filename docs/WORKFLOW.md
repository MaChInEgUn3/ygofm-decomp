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
meaningful, and skipping to the last one wastes hours:

1. **Instruction count right?** Nothing else is diagnostic until it is. If a
   function is the wrong size, remove it before reading the rest of the report —
   the linker script is regenerated from object sizes, so one wrong size can
   move functions placed *earlier* as well as later.
2. **Read/declaration order.** The most common single fix here. Declaration
   order controls which callee-saved register a value gets, where a constant is
   materialised, whether an address is folded, and whether an initialiser
   competes with the prologue.
3. **Branch polarity and loop form.** cc1psx emits the fall-through for the
   branch written as not-taken — look at which path retail falls into. But check
   the **loop statement first**, because it decides block layout on its own:
   - a backward unconditional `j` means the loop was *not* rotated — write
     `while (1)` with the exit inside, never `while (cond)`. 85 in-scope
     functions have that `j`;
   - a rotated `for` puts an interior `return` **inline**, between the test and
     the loop-back; an explicit `do`/`while` puts it after the loop-back. Same
     loop, different layout, and no polarity edit reaches across the difference.
4. **Which operand receives the result?** `addu $a1,$a1,$v1` and
   `addu $v0,$v0,$a1` compute the same sum into different registers. Swapping the
   operands of a `+` changes nothing. `a += b;` makes `a` the destination *and*
   the first operand; `t = a + b;` into a fresh variable keeps the tree order.
   Pick by which one retail shows — this unparked four functions in one direction
   and matched `func_80035748` in the other.
   Related, same pass: an expression the target recomputes in several blocks was
   **not** a variable in the source. gcc 2.8 has no global CSE, so write it inline
   in each block.
5. **Count materialisations** of each value: one per write in the source. One
   `subu` reached by two paths means one `return`; two identical constants mean
   two `return`s; a value written at a join and copied to `$v0` at one exit is
   an accumulator variable.
6. **Then** `tools_src/sweep_flags.py`.

**Stop and park** when the only remaining difference is which register holds a
value, or when the target has more duplicated tails than you produce. Record the
name in `docs/PARKED.txt` with its class **and keep the candidate in
`parked/<func>.c`**.

Before parking on "one register differs", check whether a **call** separates the
definitions of the two values, and if it does, try moving one definition across
it. That took `func_80022FF0` from seven differences to a match, and it changes
nothing else in the output, which is why it hides so well. **Observed once.**
Probed afterwards on every parked candidate with a call in it and it moved none
of them, so treat it as one more thing to try, not as a rule — and note that most
"one register differs" parks are `$v0`/`$v1` inside a single basic block, where
there is no call to move anything across.

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
- Scalar vs unsized array is a codegen choice, and the mechanism is a size hint.
  Three addressing forms can appear in one function; pick each by declaration:
  - **scalar** — cc1psx knows the size, treats it as small data and emits
    `%gp_rel($gp)` itself. The assembler's `-G` never enters into it.
  - **unsized array** — not small, so cc1psx emits an explicit `%hi`/`%lo` pair
    into an ordinary register.
  - **unsized array + `-mno-split-addresses`** — cc1psx emits the bare symbol and
    the *assembler* expands it: through the destination register for a load,
    through `$at` for a store, which has no spare register. `lui $at` in the
    target means this one.
  A per-file `#ifdef SYM_IS_SCALAR` guard in `variables.h` lets two functions
  disagree about the same symbol.
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
justify a decision — and then **filter the scan by scope**: anything at or above
`0x80073840`, or listed in `docs/LIBRARY_FUNCS.txt`, is PsyQ library code that
stays as assembly. `candidates.py` applies that filter; a hand-rolled grep over
`asm/` does not, and three functions were parked as matching failures before
anyone checked.

Run `tools_src/sync_count.py` before committing a batch — the count has been
typed wrong twice.
