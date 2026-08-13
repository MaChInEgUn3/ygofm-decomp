# Yu-Gi-Oh! Forbidden Memories — matching decompilation

Byte-exact recompilation of `SLUS_014.11`. **Not** a reimplementation: every
function must assemble to the retail bytes. `DECISIONS.md` in this directory is the
full reference and is long; this file is the operational minimum — read it
first, then reach for DECISIONS.md when you need the reasoning behind a rule.

## Verify everything with the build

```
.venv/bin/python tools_src/build.py && echo GREEN
```
It exits non-zero on any failure, so **check the exit status, not the last
lines of output**. Piping it through `tail -2` reads as green when the build
died early, because the last thing printed is then the function count. Two
commits in this project went in red that way, one of them the commit that
noticed the first.
sha1 `84747e64f6da8e764206ec203e489acf8c9dcf7d`. Always the project `.venv`,
never a bare `pip install` — installing globally once broke another tool's pins.

## Toolchain: PsyQ 4.5 (gcc 2.8.1, aspsx 2.79)

Not 4.6. That was assumed for the project's first 219 functions and produced a
byte-identical build anyway, because most functions are too small for the two
versions to differ. `YGOFM_PSYQ=46` selects 4.6 for comparison. `tools/` is
gitignored and must be re-fetched per machine.

## Adding a function

Write `src/func_XXXXXXXX.c` and rebuild; placement is automatic. Get candidates
from `tools_src/candidates.py`, and from `tools_src/siblings.py`, which pairs
each unmatched candidate with the decompiled function it most resembles. Run
siblings at 0.70, not 0.90 — the loose end of that list is as good as the tight
end, and skip the `[PARKED]` rows, which are sorted last for a measured reason.

`candidates.py` no longer hides anything as "cannot match": five drop rules
have been retracted in turn, each after being measured, and each was hiding
functions that matched. The fifth, `break`, was the first that was a
**toolchain** gap and not a misread target: `break 7`/`break 6` are the checks
aspsx wraps around a real `div`, and maspsx only emits them with
`--expand-div`, which build.py now passes globally. A real division in C is
ordinary. What is still filtered on `break` is the two-operand form
(`break 0,260`), which is the BIOS syscall stubs.
The sixth, `jr $v`/`jr $a`/`jr $t`, went the same day: those are `switch` jump
tables. Write the `switch`; build.py splits splat's rodata at the table and
puts the compiled object's `.rodata` in the hole. try_func normalises the
symbol so the fast loop still works, but **only the full build can prove the
table landed** — a jump-table function that try_func calls MATCH still has to
be built. 37 functions and 62 KB, the largest class the project has opened.
Two things to know before writing one: **a jump-table function cannot take
`-mno-split-addresses`** (under it the table load itself goes through `$at`
where retail has an ordinary register), so a function that also needs `$at`
stores was called blocked — 17 of the remaining 34 contain no `lui $at` and are
the ones to take first. That block is **narrower than it looks**: a `$at` store
to a *scalar* comes from a `-G0` assembler, not from the compiler flag (see the
four addressing forms below), and that composes with a jump table. But the -G0
assembler is **not per-symbol** — it takes every scalar in the file out of
`%gp_rel` — so `-G0` only works on a function with no `%gp_rel` at all. Check
with `grep -c '%gp_rel' asm/nonmatchings/31D8/<func>.s` before spending
anything. func_8002D458 is the measured counterexample: 79 differences under a
-G0 assembler.
Nonzero `%gp_rel` used to mean only the aggregate + `-mno-split-addresses`
route was left, which *is* closed for jump tables. It does not: `-G` is a
threshold and the **declaration is per symbol**, so give the symbol that needs
the bare form a declared size above the threshold and leave the gp-relative
ones below it. The usable window is `max(gp symbol size) <= G < 8`, and since
the widths here are 1, 2 and 4, it nearly always exists — check it rather than
assuming, because one 8-byte gp-relative symbol closes it.
And the **case range follows what is written, not what is
reachable**: retail's `sltiu $v0,$a0,0xB` for a switch whose cases 1 and 10 do
what `default` does means both are spelled out in the source (func_8002D458).
It tags instead. Two tags matter:
- **`dup-%hi`** — retail materialised one address twice. Try
  `-mno-split-addresses` **first**; all 96 instances in the binary are the bare
  form and an alias makes them worse. A quarter of them also want a hoisted
  split address in the same unit — that was recorded here as "cannot have
  both", and it is **wrong**. The flag is per *file*; the declaration is per
  *symbol*. Give the symbol that wants the bare form a scalar or sized
  declaration, leave the one that wants cc1psx's split pair unsized (an
  unsized array is never bare, whatever `-G` says), and pick the assembler
  `-G`. Which of the three cases you are in is decided by
  `grep -c '%gp_rel'` and the symbol widths, and getting this wrong is how
  the barrier looked real in the first place:
  - **no `%gp_rel` at all** — any `-G` is free. Use the symbol's *real*
    declaration (usually the plain scalar arm) and `as -G0`. func_8004BBBC and
    func_8003D46C, the two standing examples of the barrier and in opposite
    directions — a bare *load* beside a hoisted split pair, and a bare *store*
    through `$at` beside a split load — both matched this way with no source
    change beyond dropping an `_IS_AGGREGATE` their candidates were forcing.
  - **`%gp_rel` present, and the bare-wanting symbol is *wider* than every
    gp-relative one** — real declarations, and a `-G` between the two widths.
  - **`%gp_rel` present, and the bare-wanting symbol is *narrower*** (the
    common case: a one-byte flag beside four-byte gp scalars) — no real
    threshold exists, so **inflate the declaration**: `u8 sym[8]` and `as -G4`.
    Eight still clears cc `-G8`, so cc1psx keeps emitting the bare symbol,
    while `8 > 4` takes it out of small data at the assembler.
    func_800175A0 is the worked example, func_8003CCD8 the second.
  The usable window is `max(gp symbol size) <= G < 8`; the widths in this
  codebase are 1, 2 and 4, so it nearly always exists — but check, because one
  eight-byte gp-relative symbol closes it with no warning.
  **`-mno-split-addresses` is also a delay-slot lever, and that use leaves no
  trace in the addressing.** A bare symbol is *one* instruction to gcc's
  delay-slot filler, so it cannot be half-hoisted into a branch's slot; the
  slot stays a `nop` and the assembler expands the pair after it. With the
  split pair, reorg puts the `lui` in the slot. Both spellings assemble to the
  same two instructions through the same register — the *only* difference is
  retail's `nop`. func_80041D60 was one instruction short for exactly this and
  matched on the flag alone. So when a candidate is byte-identical except that
  the target leaves a delay slot empty in front of a global's address, reach
  for this flag before re-reading the source. **Two routes give the same
  bytes**, and which you pick is a judgement about the smaller claim:
  func_8001BD48 matches either with `-mno-split-addresses` (a compiler flag
  over the whole file) or with the symbol's real scalar declaration plus
  `as -G1` (the second recipe branch — the bare-wanting `u16` is wider than
  the one-byte gp-relative symbol beside it). The `-G` route keeps the
  compiler at default flags, so it is the one installed. **Observed once**,
  and it does *not* generalise to a plain constant: func_80030D5C is the same shape with a
  `lui` for 0x2000000 instead of an address, already has the flag, and is still
  two off.
**A call that sets only `$a0` is not always a missing prototype.** Twice it
was (func_800878D0, func_80046FA0, both fixed with a per-file guard) and once
it was gcc reusing a constant that another instruction had just put in `$a1`
for its own purpose — `func_8003B6AC(0, 2)` next to `D_8009B290 = q + 2`,
where the 2 was already live. The tell that separates them: look a few
instructions back for something that *sets* the argument register for an
unrelated reason. Cheap to check, and it saves adding a guard that is not
needed.

- **`lib-call`** — calls a PsyQ library function. An implicit declaration is
  enough; do not write a prototype unless a float or struct is involved — or
  unless the callee **does not return**. A function whose listing sets up a
  frame, saves `$ra` and then just *ends* after a `jal`, with no `lw $ra`/`jr`
  at all, is gcc dropping the epilogue behind a noreturn call: declare the
  callee `void f(...) __attribute__((noreturn));` (func_80030FD0). `volatile
  void f();` does **not** do it.

**A second stack-allocating prologue partway through a listing is two
functions**, and candidates.py tags it `[MERGED]`: splat missed the boundary
because nothing in `.text` references the second entry — look for its address as
a `.word` in `asm/data/` and you will usually find the pointer table that calls
it. Splitting is just editing `asm/nonmatchings/31D8/`: truncate the first `.s`
at the boundary and write the tail into `func_<addr>.s` with its own
`glabel`/`endlabel`. build.py globs that directory and orders by address, so
nothing else has to change; add the `INCLUDE_ASM` line to `src/31D8.c` to keep
it in sync. The first half being epilogue-less is the *reason* splat merged
them, and it is also the noreturn tell above.

**When it does not match, work in this order.** Each step makes the next
meaningful, and skipping to the last one wastes hours:

0. **Read the addressing before writing any C.** Not a debugging step — a
   first step, and it has decided the last four functions without a single
   round. Count `%gp_rel` and `lui $at,%hi(` in the listing, read the symbols'
   widths out of `variables.h`, and pick the form from the four-forms list
   below before typing anything. Most functions come back `gp>0, at=0`, which
   means default flags and no addressing work at all; knowing that in a minute
   is worth more than any lever further down this list.
1. **Instruction count right?** Nothing else is diagnostic until it is. If a
   function is the wrong size, remove it before reading the rest of the report —
   the linker script is regenerated from object sizes, so one wrong size can
   move functions placed *earlier* as well as later.
2. **Read/declaration order.** The most common single fix here. Declaration
   order controls which callee-saved register a value gets, where a constant is
   materialised, whether an address is folded, and whether an initialiser
   competes with the prologue. Specific shape: **a table read through a local
   declared before anything else has its address materialised before anything
   else** — that is what put func_80019A60's `la` ahead of the argument swap.
   The mirror matters as much: when the target materialises the base **after**
   the index computation, the local is wrong and the inline
   `&D_801A7AD8[p[0x6A] * 28]` is right — func_8001EFD4 went 62 differences to
   4 by *removing* the local that had just matched func_80019BD0. Read which
   comes first in the target and write that.
   It only works if the local replaces *every* reference to the symbol;
   a local that merely names one operand stays live and costs a register
   everywhere (func_8005A8C4, parked). **Where the local is assigned decides
   which register it gets**, and both ends have bitten: assigned at the top of
   a function with calls in it, it goes callee-saved and costs a register
   everywhere (func_800234E4, 57 differences; func_8005C388, 44); assigned
   immediately before the expression that uses it, it stays caller-saved and
   dies where retail's does. Scope it to the block that needs it. The same local is also what stops
   cc1psx folding the *first* reference's constant offset into the base —
   without it func_800300C8 gets `%lo(D_800EB15C+60)` and every later offset
   is 60 too small.
   **A base local also decides how a large constant offset is spelled.**
   `*(u16 *)(D_8015C424 + 0x1BD0C)` written against the symbol folds the whole
   offset into `%hi`; against a local it becomes retail's `lui/ori 0x18000`
   plus `0x3D0C` in the load — gcc splitting the constant because the base is
   now a register. func_80024734, 40 differences to 4, and the local is the
   same one the function stores at the end anyway.
   **A chain of pointer steps wants one name per step, not one cursor.**
   Where the target walks a table by re-reading a 16-bit offset at each stage
   — `q = t + rd16(q + p[k] * 2)` three times over — writing it against a
   single reused `q` makes one long-lived pseudo, which takes an argument
   register and pushes the table base out of the one retail uses. Five distinct
   locals, each assigned once, gives five short-lived pseudos that ping-pong
   through `$v0`/`$v1` the way retail does: func_80041D60, 34 differences to 7.
   Fully inlining the chain into one expression is *not* the same thing and was
   worse (29) — the names have to exist, they just must not be reused. This is
   the counterpart of the reuse rule below: one name for two unrelated values
   costs a register, and here it cost the allocation of every value in the
   block.
   Before inventing a name for a copy, **check whether the copy is the return
   value**: retail's `addu $v0,$s0,$zero` before a tail that works through
   `$v0` is `return p;` on a function whose prototype only says `void`
   (func_80019564, func_8002ABB4).
   The tell for a missing name: **a copy from a caller-saved register into a
   callee-saved one, right where the value is defined** — retail's
   `lbu $a0,0($v0)` … `addu $s0,$a0,$zero` means `s32 c = *p; … op = c;`, not
   `s32 op = *p;` (func_800386B8). An extra copy in the target is almost
   always an extra name in the source; allocation does not invent one.
   **A global read, then stores, then written back is a local.** Retail loading
   `D_8009B0F4` *above* the two halfword stores that precede the mask is not
   the scheduler being clever — a load cannot move across stores through a
   pointer. It is `v = D_8009B0F4; …stores…; v &= mask; D_8009B0F4 = v;`, and
   the compound assignment is separate from the local: it makes the value its
   own destination, which is what `and $v0,$v0,$a0` shows. func_8003B808 went
   95 differences to 82 and func_80020BE4 74 to 62 on those two together.
   **A literal and a variable holding the same value are two materialisations;
   one variable used twice is one.** `D_8009B408[0] = v; D_8009B37D = 1;`
   matched func_8003C7A0 where `= v; = v` and `= 1; = 1` both gave 54 — the
   third member of the one-name/two-names family, and the first where the
   *spelling of the constant* is the knob rather than a name.
   **One name reused across two statements blocks a fold.** Retail's
   `andi / sltu $zero / sll 6` for `(x & 0x100) != 0` shifted left is three
   instructions; every one-expression spelling — `!= 0` shifted, `* 64`, `!!`,
   a ternary, unsigned `0 < …` — lets gcc combine it to `srl / andi`, two
   instructions, and the shortfall cascades. `f = x & 0x100; f = f != 0;`
   against the same `f` reproduces retail: func_80048920, 57 differences to 20.
   The mirror of the two-names rule (func_8004318C, two multiplies of one
   value need two names): **two unrelated values must not share one name.**
   Reusing a `y` for both halfword results in func_800300C8 swapped a
   `$v0`/`$v1` pair; splitting it into `y` and `z` was 11 differences to 7.
   **A plain statement written before the others moves with them.** A loop
   counter's `i = 0` sitting above the four stores that precede the loop is not
   cosmetic: it lands before them in the prologue, where the `for`-init form
   lands after (func_80061008). Read the prologue's order and write that order.
   What will *not* move that way is anything the compiler puts in the loop
   preheader — a hoisted invariant, a biased induction variable. Naming those as
   source locals makes it worse: `s16 *q = (s16 *)(p + 6);` alongside `p` gave
   func_80061008 a *third* induction variable and went 10 differences to 51.
   **Split an address computation out when the target keeps it.** `p + (i+1)*8`
   followed by a load at `+4` gets distributed into `i*8` with `12($v0)` on the
   load; assigning `e = p + (i + 1) * 8;` first and loading `*(u8 **)(e + 4)`
   reproduces retail's `addu; lw 4(...)` — func_800593D0, 39 differences to a
   match. Grouping is the same lever one level down: `arg1 + ((i << 2) + 0x1E0)`
   adds the constant before the base, `arg1 + (i << 2) + 0x1E0` after
   (func_8005C6A0, the last two differences).
3. **Branch polarity and loop form.** cc1psx emits the fall-through for the
   branch written as not-taken — look at which path retail falls into. But check
   the **loop statement first**, because it decides block layout on its own:
   - a backward unconditional `j` means the loop was *not* rotated — write
     `while (1)` with the exit inside, never `while (cond)`. 85 in-scope
     functions have that `j`;
   - a *forward* `j` into the loop's bottom test is the **unrotated** `while`:
     gcc did not copy the header, and no `while`/`do` spelling reproduces it.
     Write `goto test;` at the top with the test at the bottom (func_8003BC40).
     Once you do, gcc tail-merges the two copies of the test's own load into
     the test block; put a statement *after* that load in the advance block
     (`e++; v = *e; idx++;`, not `e++; idx++; v = *e;`) and the merge cannot
     fire. That was 42 differences to 28;
   - an out-of-line arm the target places **before** the loop body is a label
     the source reached with a `goto`, not an `else` — no polarity edit moves
     a block across the loop head;
   - a rotated `for` puts an interior `return` **inline**, between the test and
     the loop-back; an explicit `do`/`while` puts it after the loop-back. Same
     loop, different layout, and no polarity edit reaches across the difference.
4. **Which operand receives the result?** `addu $a1,$a1,$v1` and
   `addu $v0,$v0,$a1` compute the same sum into different registers. Swapping the
   operands of a `+` changes nothing. `a += b;` makes `a` the destination *and*
   the first operand; `t = a + b;` into a fresh variable keeps the tree order.
   Pick by which one retail shows — this unparked four functions in one direction
   and matched `func_80035748` in the other.
   The inverse too: where the target reads something **once** and you read it
   twice, look for a store between your two reads that gcc must assume aliases
   — `if (q[7]) x = q[7] << 4;` reloads across a store through another
   parameter, and one local was the whole of func_80059000.
   **A pointer just stored into a struct, then used, wants reading back.**
   Where the target has a register copy of an address it has just stored --
   `sw $a1,K(base)` then `addu $a0,$a1,$zero` and a store through `$a0` --
   write the second use as `*(u16 *)(*(s32 *)(base + K))`, not as the literal
   and not as a local holding it. Both of those give no copy, and two locals
   holding the same address give no copy either; only the read-back does
   (func_80048F14, 45 differences to 15). Related: a halfword store of
   `0xFFFF` through `s16` gets folded into a `-1` the function already has in
   a register, which is one instruction short; `u16` materialises it.
   **The mirror: a load the target does *not* hoist wants an address the
   compiler cannot disambiguate.** Where retail stores a constant into a stack
   struct and *then* loads from a global, gcc hoists the load above the store
   to cover its latency — it knows an array indexed by name is a different
   object from the local. Writing the same read as a computed byte address,
   `*(s32 *)((u8 *)tbl + i * 4)` instead of `tbl[i]`, keeps the store first.
   func_80049CF8, 4 differences to a match; permuting the four stores, naming
   the loaded value, and naming it before or after the constant store all
   stayed at 4, and an explicit `s32 *` cursor is much worse (43) because it
   becomes a second induction variable.
   **It is the cast, not the escape.** The obvious reading is that the local's
   address escaped to the callee so the byte-address load might alias it — that
   is wrong, and a two-line probe says so: the same loop storing into a
   *global* struct, where nothing escapes, still hoists the load in the indexed
   form and still keeps the store first in the byte-address form. So reach for
   this spelling wherever a load is being hoisted past a store, not only where
   something escaped.
   **The same marking works in reverse: a cast store loses its struct
   membership and the scheduler moves genuinely aliasing accesses across
   it.** func_800592AC stores two halfwords into a stack packet and then
   copies the whole packet; spelled `*(s16 *)(src.b + 4) = …` the whole-
   struct copy's lwl/lwr hoist *above* the stores into the very bytes they
   read — volatile does not pin it and no flag row reaches it. Spelled as a
   member through a view struct, `((HalfView *)&src)->h2 = …`, the access
   carries the in-struct MEM marking, the dependency is seen, and the order
   holds. One mechanism, two directions: strip the marking to *allow* a
   move retail has (func_80049CF8), keep it to *forbid* one retail lacks.
   **Write that same double read where there is no aliasing store and you get a
   register copy instead of a second load** — and that copy is often the
   instruction the target schedules into a branch's delay slot. func_80057E20's
   last 12 differences were retail putting `addu $v1,$v0,$zero` in the delay
   slot and the `sll` after the load, where every single-read spelling puts the
   `sll` in the delay slot and a `nop` after the load. `if (e[7] != 0) { v =
   e[7] << 4; … }` matched; `v = e[7]; if (v != 0)`, `v <<= 4`, and a second
   name for the shift result all stayed at 12. So an unexplained
   register-to-register copy is not always an extra *name* (step 2's rule) — it
   is also what CSE leaves behind when the source read the same lvalue twice.
   Related, same pass: an expression the target recomputes in several blocks was
   **not** a variable in the source. gcc 2.8 has no global CSE, so write it inline
   in each block. Also here: `tbl[i + K]` emits `addu index,base` and
   `(tbl + i)[K]` emits `addu base,index` — same address, opposite operands.
   **gcc folds a scaled dividend and an intermediate assignment blocks it.**
   `(x * 8 + 0x7FF) / 2048` comes out as `(x + 255) / 256` — two instructions
   short of retail's `sll 3` / bias / `sra 11`, and the shortfall cascades
   through the whole prologue. Splitting it in two against the same name —
   `n = x * 8;` then `n = (n + 0x7FF) / 2048 + 1;` — reproduces retail.
   `<< 3` for the multiply does not block it, and splitting at the `+ 0x7FF`
   instead is worse (func_80047788, 48 to 18). This is the same family as the
   `(x & 0x100) != 0` fold in step 2: one name reused across two statements
   is what stops the combiner.
   **A named offset flips it the other way.** Where the base is a *parameter*
   rather than a symbol, no index spelling reaches `addu base,index` — four
   were tried on func_8004DB14 (`p + i * 4 + 0x1E0`, `((u8 **)p + i)[0x78]`,
   `((u8 **)p)[i + 0x78]`, the cast-to-`s32` sum) and all four give
   `addu index,base`. Assigning the scaled index to a local first —
   `off = i * 4; e = *(u8 **)(p + off + 0x1E0);` — gives retail's
   `addu $v0,$a0,$v0`, and it was the last difference in that function. The
   tell is in the same listing: a loop giv added to the same parameter
   (`addu $v0,$a0,$a3`) already came out base-first, so when one `addu` in a
   function has the base first and another has it second, the difference is
   that one index is a variable and the other is an expression.
   **When no `+` spelling gives `addu base,index`, try a subtraction of a
   negation.** `p + K - -(i * 2)` instead of `p + i * 2 + K` is
   arithmetically identical and puts the base first. On func_80047CC4 seven
   `+` spellings all came out index-first — the offset grouped with the base,
   the constant written first, `((u16 *)p + i)[K]`, `((u16 *)p)[i + K]`, an
   `(s32)` cast sum, a base local, and a named scaled index — and the
   permuter found the negation at iteration 79. **Observed once**, and write
   the plain `+` first: it is *not* true that a base which is a pointer value
   forces index-first, because func_80049CF8 and its clone func_80049DD8 get
   `addu base,index` out of a plain `D_8009B458 + i * 0x28` on exactly that
   kind of base. What differs between them is not established; in the two
   that worked the index is a loop giv and the base is reloaded per
   iteration, and in func_80047CC4 it is `(u8)i * 2` computed inside a
   conditional.
   **The opposite direction has its own route: cast the sum to integer
   arithmetic.** When retail wants the *index* first and every pointer `+`
   spelling gives `addu base,index` — `(i + o) + base` and `&base[i + o]`
   both did on func_80058938 — the base being a pointer is itself the
   canonicalisation, and `(u8 *)((i + o) + (s32)base)` takes it out of
   pointer arithmetic: the plain integer PLUS keeps the written order and
   the addu comes out `sum,base`. **Observed once**, the last hand lever in
   that function.
   **But only when `tbl` is the symbol.** Through a *base local* every
   spelling gives `addu base,index`: four were tried on func_8002778C
   (regrouping the index, `x * 28 + rec`, a named index variable, `&rec[…]`)
   and none recovers the first form. Writing the symbols inline matched, and
   gcc hoists them into the same two registers by itself — so a target that
   materialises a table base once before a loop does *not* imply a source
   local. Second time D_801A7AD8 has punished a base local for a different
   reason; func_8001EFD4 is the other.
   And the order of two increments in one `for` clause decides which is
   available to fill a load-delay slot at the top of the body:
   `for (i = 0; i < 10; p++, i++)` matched func_80021480 where `i++, p++`
   left a stray `nop` and 39 differences.
   **A counter incremented inline moves its `addiu` to the use.** Where the
   target bumps the counter in the middle of the body — before the call, not
   after it — write `e[0x6A] = i++;` and drop the `for`'s third clause
   (func_80061008). The induction variable for the loop's *other* pointer
   follows it: with the bump inline, gcc placed both before the `jal`, which is
   what retail does.
   **gcc 2.8 keeps an address-taken local in memory, always.** A value the
   function passed by address to an out-parameter call and then uses as a loop
   counter reloads and re-stores every iteration, where the target holds it in
   a register — there is no "the address cannot escape past here" analysis in
   this compiler. Passing separate variables to the call and copying them into
   the loop's own locals afterwards does fix the reload. It is not
   automatically the answer, though: on func_80071EB8 it cost more elsewhere
   than it saved, and which shape is right is still open. Recognise the reload
   for what it is before spending on anything else in the block.
   **A pointer that walks up while the counter walks down is a real `*q++`.**
   gcc reverses the counter after strength reduction has left it live only in
   the exit test, so the address giv keeps going forward: no index expression
   reproduces it in either direction, and an explicit cursor does
   (func_800533D8, 55 differences to 10).
   **Where an independent store lands is decided by what precedes it.** A store
   written *after* a multiply gets scheduled into the `mult`→`mflo` latency;
   written before, it stays before. That is the whole of func_80044DC0's last
   three differences: `sp10[3] = 0;` after `sp10[0] = …` rather than before, and
   the two arms of the `if` both writing index 1 first.
5. **Which test is written first**, when the target has more exit blocks than
   you produce. `if (x == 0) return 0;` then the body, versus the body under
   `if (x != 0)` with `return 0` after it, are *different layouts*: the first
   keeps both exits, the second gets cross-jumped into one with the value in a
   delay slot. Rule of thumb: whichever condition the target **branches out on**
   is the one to write first. Confirmed on `func_80033500` and `func_800440B4`.
   **And the case order decides *which* of several identical arms gets
   merged.** func_80024C1C's `case 0x14` and `case 0x17` both store 1; retail
   merges 0x14 into the shared block with 0x15 and 0x16 and leaves 0x17
   standalone. Written in numeric order gcc merges 0x17 instead — two
   differences, and no flag reaches it because cross-jumping is closed.
   Writing `case 0x17:` first and the rest ascending matches. Three orders
   tried, one works: when two arms are identical and the target merges only
   one of them, permute the case order.
   **Permuting is also how you move an address giv's bias.** A run of stores
   to one record inside a loop gets one biased giv, and every store is a
   displacement off it — so if the bias is wrong, *all* of them differ and it
   reads like a much bigger problem than it is. The bias follows the store
   written **last** in the group: func_800175A0 stores at +0x12, 0x14, 0x16,
   0x18, 0x19 and 0x1F, and retail biases at +0x1F. With `+0x16` written last
   the bias is 0x16 and six displacements are wrong; moving the `+0x1F` store
   to the end of the group gives retail's bias and costs nothing else (34
   differences to 27). Writing it *first* instead is 36, as is putting `+0x16`
   first — so it is the last position that decides, not the first. **Observed
   once.**
   **The same pass from the other side: do not block a cross-jump.** gcc merges
   two arms only when their instruction sequences are *identical*, and two arms
   computing the same value from different expressions — one from a global, one
   from a struct field — produce identical instructions only once the value is
   in a named local. Written inline, the tail is emitted twice; assigned to one
   local first, it merges to the target's shared block. func_8003A01C, 54
   differences to 33. Step 5's rule is about creating a shared exit; this is
   about not preventing one.
   **A value put in an argument register and then apparently unused is the
   next call's argument.** Retail's `addu $a0,$zero,$zero` followed by stores
   that use `$zero` directly reads as a wasted instruction; it was the argument
   to a `jal` after the join, whose own delay slot is a bare `nop`. When a
   register is set and nothing in its block reads it, look at the next `jal`
   before concluding anything else — func_8003C7A0, 65 differences to 1.
   **A named byte read schedules where you put the name, and one statement
   either way is the whole difference.** Where the target interleaves a load
   between two stores — `sb`, `lbu`, `sb`, `sb` — writing the read inline in
   its own store leaves it after both, and gcc will not hoist it because the
   constant it just materialised is in the register the load would want.
   Naming it moves it, and then *where the name is assigned* is the knob:
   before the first store is too early, after the first store is retail.
   func_80036C14, 37 differences to 12 to 2 on that one line's position in
   three arms. The last 2 were the third instance of the two-names rule, and
   it is narrower than "one local per arm": one `b` shared by all three arms
   takes a register that has to survive all three, so the *middle* arm — the
   one where retail reuses the just-freed `$v0` — gets `$v1` instead. Giving
   that arm alone its own name matched. A third name for the last arm also
   matches and changes nothing, so two is the measured shape and what is
   installed.
   **Hoist a call's arguments into locals when the target evaluates them
   early.** Where retail sets up `$a0` and loads `$a1` *before* the stores that
   precede the call, assigning both to locals at the top of the block
   reproduces it: func_800289BC, 53 differences to 13. It works only for the
   values that cross the call — naming the field reads as well made it 36 —
   except where the target issues one read before the base pointer's own load,
   which needs its own local to get there (the last 13).
6. **Count materialisations** of each value: one per write in the source.
   **A return constant in a branch's delay slot *and* again at the join can be
   one `return`, not two.** On func_8004B734 two explicit `return 0;`
   statements were merged into a single materialisation and the function came
   out an instruction short; writing the last test as a nested `if` with one
   trailing `return 0;` — `if (p[0x501] == 0) { body } return 0;` — gave
   retail's pair, gcc copying the constant into the branch's slot and keeping
   it at the join. Nine differences to a match. **Observed once**, and it does
   *not* mean two explicit returns are wrong in general: func_800497E0's two
   `return -1;` statements produce exactly the shared block retail has, and
   there it was the accumulator spelling that broke. Read which shape the
   target has before choosing. This is the duplicated-store rule below applied
   to the return register.
   A value computed in a **branch's delay slot that the fall-through then
   overwrites** is an unconditional assignment followed by a conditional one,
   not two arms of an `if` — `v = a; if (c) v = b;`, never
   `if (c) v = b; else v = a;` (func_80026BA4). Register form of the
   duplicated-store rule below. One
   `subu` reached by two paths means one `return`; two identical constants mean
   two `return`s; a value written at a join and copied to `$v0` at one exit is
   an accumulator variable. Same counting applies to *stores*: a store in a
   `j`'s delay slot that the join block repeats is a genuine second store, not
   a delay-slot copy of the join (gcc only copies a target instruction with the
   branch moved to target+4). The confirming tell is a constant the join
   consumes but each predecessor materialises for itself — func_800402A0.
   Writing that store once per arm instead costs 18 differences.
7. **Then** the flags — `tools_src/sweep_try.py` first, `sweep_flags.py` to
   confirm. Do not leave this to last when the target shows a **loop counting
   the other way**: gcc reverses a counted loop whose counter is dead after it,
   and `-O1` is sometimes the only thing that stops it (func_80047A68, 23
   differences to 6). If retail's loop comparison is *unsigned*, try a `u32`
   counter before reaching for a flag (func_800494F4). Also flags, not source:
   a **load hoisted above a store to a different global** to fill its own
   load-delay slot is `-fno-schedule-insns` (func_80014A5C, the first user).
   `volatile` does not stop that hoist on either object — gcc 2.8 moves a load
   across a volatile store and moves a volatile load too.
   And a **struct assigned by value through a pointer inside a loop** is a
   `-fno-strength-reduce` case: the block-move expansion forces the
   destination address into a register, strength reduction anchors a giv on
   it, and every neighbouring store gets rebased on the anchor (`sh -8/-6/-10`
   off a cursor+20 register where retail has plain displacements). No source
   spelling removes the anchor — index-only loop, derived cursor, struct
   members and a goto-out-of-line arm were all measured on func_80058938, the
   flag's second user after func_80017708 — because the address computation is
   the expander's, not the source's.

**Assigning to an already-dead local before a call is a register-allocation
hint.** `x = w; func_800134E0(p, x, y, z);` where `x`'s live range ended two
statements earlier computes nothing and matched func_800135FC, which had been
parked at 16 through a 720-permutation declaration-order sweep. The permuter
found it; it is now a shape to try by hand, and it took the sibling
func_8001352C from 38 to 27 on its own.

**The permuter's score and try_func's difference count are different
measurements — do not cross-read them.** On func_80013360 the permuter took a
base of 625 down to 195 by wrapping the whole body in `do { … } while (0);`,
which is semantically a no-op; try_func calls both candidates 7, on the same
seven prologue instructions, just permuted. Its score weights a register
mismatch differently from an instruction mismatch, so a large drop can mean
nothing to the build. Run the winner through try_func before believing it is
closer.

**When the permuter's better-scoring candidate is semantically wrong, ask
what the *target* does before discarding it.** func_8001352C sat parked for
weeks because its best output "inserted `(char)0x400`, which is zero under
`-D__CHAR_UNSIGNED__`, deleting the `addiu $a0,$a0,0x400` the target has" —
and the target has no `0x400` at all. The candidate had been adapted from a
sibling and carried the bias across; the permuter could not delete the term so
it neutralised it, and its "wrong" 19 was closer than our "honest" 27. So:
**diff the two listings before trusting any constant an adapted candidate
inherited**, and read a wrong-but-better candidate as a pointer at the target
rather than as noise.
The whole park was swept for that error afterwards — every constant `>= 8` in
every `parked/*.c` checked against its own target's listing, allowing for
`lui`/`ori` halves and byte-vs-element scaling. Eleven flags, all false:
offsets we had folded a `0x8000` base into (func_8001944C), a negative
constant the listing spells as its two's complement (`arg1 - 0xD000` is
`ori 0xFFFF3000`), a 32-bit constant split across a pair, and a *biased
induction variable* — func_80026D18 reads `r + 0x16` and `r + 0xC` in source
while retail walks a second cursor at `base + 0xC` and reads `0xA(cursor)`
and `0(cursor)`, so neither offset appears in the listing at all. **That last
one is the trap**: a missing constant is as often gcc's giv as it is a real
error. The sweep is worth running after any adapted candidate; the false-flag
rate is high and each one takes a minute to clear.

**Read what the permuter actually changed before believing its score.**
One genuine instance: on func_8005B260 it hoisted `new_var = &*(s32 *)src;`
out of a copy loop and read `*new_var` inside, so every iteration copies the
same word while the cursor advances — a score of 365 against a base of 1000
for code that does not do what the function does. `diff.txt` in the output
directory is three lines to read. func_8001352C used to be cited here as a
second instance and **is retracted**: the term it neutralised was one the
target never had, so that candidate was directionally right and the entry
calling it wrong is what kept the function parked. The score is a weighted
diff, not an instruction count — run any candidate it produces through
try_func and read the diff, not the number.

**Two levers can be coupled, and each one measured alone reads as a
regression. Observed twice.** func_80026D18 sat at 4 through nine shapes, one of which was the
declaration order that turns out to be half the answer — alone it is *6*, so
it was correctly rejected every time it was tried. The other half is a
`do { } while (0);` around an `if` body, which is 2 on its own; together they
match. A bare `{ }` or `if (1) { }` is 6, so it is the loop node gcc's loop
pass sees, not the block. **This is the specific thing the permuter is for**:
it mutates from a base that already carries one lever, so it can find the
partner that a one-at-a-time sweep by hand never will. func_80038334 is the
second instance and the cleaner one: two extra names, `d = *slot; q = d;` and
`a = p + …; slot = (u8 **)a;`. Alone they are 6 (no change) and 14 (worse);
together they match. When a park says "N
shapes measured, all the same", that is evidence about N shapes *individually*
and none at all about pairs.

**Scoring the permuter's stored output is a separate act, and nobody was doing
it.** The permuter writes every improvement it finds to
`build/permuter/<func>/output-<score>-<n>/source.c` and exits; reading those
files is not part of running it. `tools_src/score_permuter_outputs.py` walks
every directory and re-scores each output through try_func against the
installed `parked/<func>.c`. Its first run over 72 directories found **ten**
functions whose stored output beat what was installed — including
func_80031EE4, which was a complete MATCH sitting unread, and func_800472A8 at
20 differences down to 1. A directory existing is not evidence anyone looked
inside it. Run this after any batch of permuter work and whenever picking up an
old park.
Two cautions the same run established. The dirname score is the permuter's own
weighted metric and does not track try_func's count, so re-score everything.
And a better count is **not** a better candidate: two of the first seven finds
were semantically wrong and scored far better than the correct source — one
deleted a store the target has (func_8004C84C, 14 against a correct 25), the
other cast an index the target does not mask (func_8003B744, 8 against 18).
Both would have gone in as silent bugs on the number alone.

**The permuter is the lever for the register-allocation class, and it works.**
`python tools_src/permute.py <func>` sets up `build/permuter/<func>/` from
`parked/<func>.c` and runs it; func_800135FC took 66 iterations, about ninety
seconds on six threads. Reach for it as soon as a candidate is
instruction-for-instruction right and only the allocation is wrong — that is
precisely the state the park rule below describes.

**The "mandatory below 25 instructions" rule below became a *never above 25*
rule, and that was costing matches.** Checked on three parked functions of 54,
76 and 102 instructions, every one of them diagnosed as a register or
scheduling problem: the permuter had **never been run on any of them**. It was
run on the 102-instruction one and went 7 differences to 5 immediately. The
size threshold is about when the permuter is *required*, not about when it is
*allowed* — if the diagnosis says "one register" or "one scheduling decision",
run it whatever the size. Also **rerun it from an improved base**: it mutates
from what it is given, so a run that saturated against the old candidate says
nothing about the new one (func_8004CA60 went 9 to 1 that way after an earlier
run from 12 returned 12).

**Stop and park** when the only remaining difference is which register holds a
value, or when the target has more duplicated tails than you produce. Run the
permuter *before* writing the park entry, not after — and for anything under
about 25 instructions treat that as mandatory rather than advisory. It is
3-for-3 on matches in that band (func_80047CC4, func_80026D18, func_80038334)
and improved two more parks the same afternoon (func_8004CABC 15→9,
func_800601D0 14→12). Two of the three wins were **coupled pairs**, which a
one-at-a-time hand sweep cannot reach by construction. Record the
name in `docs/PARKED.txt` with its class **and keep the candidate in
`parked/<func>.c`**.

**And re-read the park list whenever a new source-shape lever is measured.** A
park records that a shape was not found, not that none exists. Entries whose
diagnosis names the *placement* of an instruction — a counter incremented
somewhere unexpected, a copy from nowhere, a block on the wrong side of a loop
head — are candidates for a free match; entries that say `$v0` versus `$v1` in
one basic block are not. func_8004C0AC sat at 6 differences for weeks and
matched first try once "an increment in an unexpected place is a loop-form
question" had been written down.

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
- **A `u8` parameter is only right when the target masks at the call site.**
  The narrowness usually belongs to the store inside the callee, which
  truncates anyway. Widening `func_80040410`'s second parameter to `s32` left
  the callee and its other caller byte-identical and removed the `andi` that
  was blocking func_80021480. Re-run try_func over every decompiled caller
  when you change one — same hazard as adding a prototype.
- **A prototype can need a per-file guard too.** func_80017F04 takes three
  parameters and func_80018004 calls it with one — retail sets neither `$a1`
  nor `$a2` at that call, so the caller's translation unit never saw the real
  declaration. functions.h guards it on `FUNC_80017F04_FULL`, defined only by
  the file that defines the function. When a caller matches while passing
  fewer arguments than the callee reads, that is not a bug to fix: it is the
  original build's missing prototype, and forcing one signature on both breaks
  whichever side you did not measure.
- **Before adding a prototype, `ls src/<callee>.c`.** Three times in one session
  a callee was already decompiled with a different signature, and the added
  prototype made the *existing* file stop compiling. `grep -rn <callee> src/`
  finds the callers that also need updating.
- **A struct copy's expansion is decided by the type's *alignment*, and an
  all-`u8` record has alignment 1.** gcc expands `*dst = *src;` with aligned
  `lw`/`sw` only when it can prove alignment 4; otherwise it emits an
  `lwl`/`lwr` + `swl`/`swr` pair per word, which is exactly twice as many
  instructions and reads like a completely different function. So when a
  record type invented for this project turns up in a by-value copy, the
  question is not the field names but whether its head is really bytes:
  `Rec1C`'s was `u8 unk0[0x11]`, and retail's seven aligned `lw`/`sw` say it
  is four `s32`s plus one `u8`. Same byte offsets, alignment 4, and every
  other user of the type is unaffected — but **re-run try_func over them**,
  because alignment is a codegen input everywhere the type appears, not only
  in the copy (func_80039D64; four users rechecked, all still MATCH).
- **Hold values in the widest natural type; cast at the point of use.** A narrow
  type inside a computation costs an `andi` or a sign-extend — this has bitten
  parameters, return values, locals and loop counters. It also changes
  *comparisons*: a `u8` local compares in QImode and a `u16` local in HImode,
  and both are **unsigned**, so `u8 v = p[i]; if (v >= 0xB)` gives `sltiu` where
  the same byte in an `s32` gives retail's `slti`. The narrowness is also the
  only source of a redundant-looking `andi 0xFFFF`: a `u16` local's HImode
  `== 0` test normalises through the mask, where an `s32` holding the same
  `lhu` folds an explicit `(u16)` cast away because gcc knows the load's
  upper bits. One declaration was all 17 differences of func_8002FA54.
- **Signedness at the same width is a third axis, and it decides whether gcc
  narrows at all.** Both `s32 f` and `u32 f` are word-sized, so the
  widest-natural-type rule says nothing between them — but with `s32 f`, gcc
  narrows `f | 0x80` to QImode because the result only feeds a byte store, the
  constant becomes a signed `-128` that no longer fits an `ori` immediate, and
  it gets hoisted into a callee-saved register as a loop invariant. `u32 f`
  keeps retail's `ori $v0,$v1,128`. That one word was 87 differences to a match
  on func_80043BCC. Two negatives worth knowing before you doubt the
  diagnosis: `f |= 0x80` gets to 4, and an explicit `(u8)` cast changes nothing
  at all.
- The reverse also happens: a narrow **return type** is sometimes the whole
  function. `u16 func(s32 arg0)` holds the value unmasked and puts the `andi` at
  the return, which is why retail copies the argument to `$v0` before clobbering
  `$a0` with the test — func_80047C50.
- And a narrow **local** can be the whole function without changing one
  instruction. `s8 v = p[0x18];` matched func_80027060 where
  `s32 v = (s8)p[0x18];` gave 18 differences — same instructions, same order,
  every register in the block rotated by one, because the redundant cast is a
  pseudo born before the load's own. **When the only difference left is that a
  whole block's registers are shifted by one, look for a pseudo that should not
  exist**; a cast that changes no instruction is the commonest source.
- **A symbol read at one width in one file and another width elsewhere** takes
  the same per-file guard as an addressing disagreement: D_8009AF76 is a
  halfword read gp-relatively almost everywhere and a *byte* read through
  %hi/%lo in func_8003D518, and the aggregate arm of its guard plus
  `-mno-split-addresses` gives both. The mechanism is that an unsized extern
  carries no `.extern` size, so the assembler will not treat it as small data
  even at -G8, while the scalars around it stay gp-relative.
- **A symbol read `lb` in one place and `lbu` in another** needs an lvalue
  cast, not a value cast: `*(s8 *)&D_8009B32C == 0` gives `lb` where
  `(s8)D_8009B32C == 0` still gives `lbu` (gcc has no reason to sign-extend
  before a compare against zero). The `_IS_AGGREGATE` guards cover addressing
  disagreements between files; this is signedness inside one function and no
  guard expresses it (func_800375A4).
- `common.h` does not define `NULL`. Write `(u8 *)0`.
- Scalar vs unsized array is a codegen choice, and the mechanism is a size hint.
  **Four** addressing forms can appear in one function; pick each by declaration
  size and by the assembler's `-G`, which compare against each other:
  - **scalar** — cc1psx emits the *bare* symbol (`sh $0,D_8009B148`) and marks it
    `.extern sym,2`. A `-G8` assembler knows it is small data and renders
    `%gp_rel($gp)`.
  - **scalar + a smaller `-G` in the assembler** (`PER_FUNC_AS_FLAGS[f]`) — same
    compiler output, but now the assembler cannot assume small data and expands
    it: through `$at` for a store, through the destination register for a load
    or an `la`. **`-G` is a size threshold, not a switch**, and that is the
    thing to know: a symbol is small data iff its declared size is `<= -G`.
    **The comparison is `<=`, so a size has to *clear* the threshold, not equal
    it**: a two-byte symbol at `-G2` is still small data. That has now cost two
    functions a round each (func_80024200, func_80012B50).
    `-G0` takes every scalar in the unit out of `%gp_rel` at once, which is
    only usable where there is no gp-relative access left to lose
    (func_8002D458 wants both and gets 79). But an intermediate `-G` splits the
    file **by size**: func_800136E4 assembles at `-G2`, where the `u8`
    D_8009B0E0 (1 byte) stays gp-relative and the `s32` D_8009B10C (4 bytes)
    goes through `$at`, in the same function. Read the sizes out of the
    declarations, pick a threshold between them, and the "three forms, two
    knobs" barrier is not one. Where the two groups are the same width, giving
    one of them a *declared* size it does not need is the same kind of codegen
    knob as scalar-vs-array (D_80010038 is `[4]` for exactly that reason).
    **And that knob is also how you stop a loop-invariant address being
    hoisted.** func_8003CCD8 reads one byte of a four-byte symbol inside a
    loop where retail re-materialises `lui %hi` every iteration; the unsized
    array gives cc1psx's own pair and gcc hoists the `%hi` out as an
    invariant, which is one instruction too many in the preheader and one too
    few in the body. Declaring the symbol `u8 sym[8]` — a size it does not
    have — and assembling at `-G4` makes it non-small (8 > 4) while the real
    four-byte scalars beside it stay gp-relative, and a bare reference is
    *one* instruction to gcc, so the invariant pass has nothing to hoist. 28
    differences to 6, and no other threshold separates the two groups:
    -G0/-G1/-G2 take the gp-relative symbols out with it (+20, +18, +12).
    **Same knob, second use the same day: it is the delay-slot lever for a
    symbol that cannot take `-mno-split-addresses`.** func_800175A0 tests a
    one-byte flag on three paths; with the unsized array cc1psx emits a
    %hi/%lo pair, gcc CSEs the `%hi` from the entry test into a later arm and
    hoists another into a branch delay slot retail leaves as a `nop`. The flag
    would fix it and cannot be used, because the same file needs cc1psx's own
    *split* pair for a table base in two different registers. Declaring the
    flag `s8 sym[8]` and assembling at `-G4` gives the bare form for that one
    symbol and leaves everything else alone: MATCH, where two symbol aliases
    had got it only to within one instruction. **Prefer this to an alias** —
    an alias makes each reference a separate two-instruction pair, which stops
    the CSE but not the delay-slot fill.
    **And the two `-G`s are independent knobs, which the sweep table did not
    know.** Every row in `sweep_flags.py`'s COMBOS used to tie the compiler's
    `-G` to the assembler's, so "default compiler, smaller assembler" — the
    exact combination this bullet describes — was unreachable through the
    tool. It is also a **delay-slot** lever, the same one `-mno-split-addresses`
    gives for a symbol: a scalar small enough to stay gp-relative at `-G8` is
    one instruction to gcc's delay-slot filler and gets hoisted into a branch
    slot, while at as `-G0` it is still one instruction to gcc but a macro to
    the assembler, so retail's `nop` survives. func_8001944C went from 62
    differences with a length mismatch to 32 with equal lengths on that row
    alone. Four as-only rows are now in the table.
    The scalar-with-a-smaller-assembler-`-G` form is the one that matters
    when a function needs `lui $at` on one symbol while keeping cc1psx's own
    split pair on another — `-mno-split-addresses` would wreck the second
    (func_80061008: `lui $at` on two scalars, `lui $v0,%hi / addiu $s4,$v0,%lo`
    on a function address, no compiler flag can do both).
    This list used to say "the assembler's `-G` never enters into it" for
    scalars. That was never measured; running cc1psx on a four-line probe
    disproves it in one command.
  - **unsized array** — not small, so cc1psx emits an explicit `%hi`/`%lo` pair
    into an ordinary register.
  - **unsized array + `-mno-split-addresses`** — cc1psx emits the bare symbol and
    the *assembler* expands it: through the destination register for a load,
    through `$at` for a store, which has no spare register.
  **A declared size is also a scheduling knob, and it cuts both ways.** A bare
  reference is *one pseudo-instruction* when cc1psx schedules — maspsx expands
  it afterwards — so sizing a symbol out of small data does not only change the
  addressing, it takes away the scheduler's freedom to split the `%hi` from the
  `%lo`. func_8002E470's last nine differences were two globals whose `lui`s we
  interleaved and retail did not; `[2]` (eight bytes, non-small at -G4) made
  each reference indivisible and it matched. The same indivisibility *cost*
  func_8003D03C 29 differences (10 to 39), because there the split halves were
  what filled a load-delay slot. Read which way the target wants it before
  reaching for the size.
  **Run this check before writing any C — it is cheap and it keeps paying.**
  Two of the last three matches went in without an addressing round at all,
  one of them first-try, because counting `%gp_rel` and `lui $at,%hi(` in the
  listing and reading the widths out of variables.h settles the question in a
  minute.
  **Eliminate before reaching for the threshold.** If the symbol that needs the
  non-small form is *narrower* than one that needs `%gp_rel` in the same
  function, no `-G` exists between them and the answer is the unsized array —
  cc1psx's own pair, default flags. func_8003C950 wants `lui/sb` on a one-byte
  symbol and `%gp_rel` on a four-byte one; running that check first made it a
  first-try match with no iteration at all.
  A per-file `#ifdef SYM_IS_SCALAR` guard in `variables.h` lets two functions
  disagree about the same symbol. `lui $at` therefore means *either* of the two
  bare forms; separate them by what else the function needs, and prefer the
  `-G0` assembler when a `la` in the same function wants a separate temp.
  The tell for the fourth form is `lui $r,%hi(s)` with the memory op through the
  **same** `$r`; but read it in one direction only — a *separate* temp is always
  cc1psx's own pair, while one register can be either (func_80022618 splits its
  own pair across a delay slot using one register).
- **`volatile` is also an ordering constraint between stores.** A run of
  stores to unrelated globals that the target keeps in source order and we
  reorder is usually not the scheduler: gcc sinks a non-volatile store past a
  volatile one, so a block that mixes the two comes out shuffled. In
  func_80012B50 two of four adjacent stores were volatile and two were not;
  marking all four volatile was the last six differences. Check which
  neighbours are already volatile before reaching for anything else — and
  check the symbol's *other* users still match, since the original had one
  declaration (func_80012DB4 matches either way, which is what makes the
  volatile credible rather than a knob).
  **Both stores may need it, and neither alone is enough.** func_80037D2C
  writes a `u16` global and then an `s32` one and gcc emits them in the other
  order; marking *either* volatile leaves it at three differences and marking
  **both** matches. Swapping the source order, naming the constant, and four
  other shapes all stay at three. So when a pair of adjacent stores to
  unrelated globals comes out reversed, try the pair, not one at a time — and
  note this is a different case from the rule above, where one neighbour was
  already volatile.
- **`volatile` when the function's point is re-reading.** gcc commons a repeated
  read with the one in the entry guard and then propagates the value, which
  deletes the test: func_8005C5D4's spin loop needs it, and func_80058E1C needs
  a second *name* for the same reason where volatile would be wrong.
- `config/symbol_aliases.txt` gives an address a second name, for when retail
  materialises it twice inside one basic block. Needs a `-G0` assembler to be
  worth anything.

## Semantic search over the prose (rag-gpu)

A RAG server on the LAN GPU box indexes this repo into the collection
**`ygofm-code`**, kept in sync by four git hooks. Use it for the one question
grep is bad at: *"did we already measure this, and what happened?"* —
`DECISIONS.md` is 4181 lines and is **not** preloaded, `PARKED.txt` is 1817
lines of prose diagnoses, and the recurring cost here is a retraction that was
already written down somewhere. It also answers across languages, which grep
cannot: a Portuguese query against this English prose retrieves correctly.

**Ask it in this project's own vocabulary, not about the project.** Three
queries measured: naming the mechanism — "two adjacent stores to globals come
out reversed, mark both volatile", "PsyQ 4.5 versus 4.6, which function
discriminates" — scores 0.60–0.65 and returns the exact paragraph, and in the
volatile case it also returned the PARKED.txt entry that is a *counterexample*
to the WORKFLOW rule, which is the whole reason to have it. A meta question
about the work — "we claimed something could not match and later retracted it,
what was the real mechanism" — scores 0.44 and returns tool comments. So it
retrieves on the terms a listing would use, not on the shape of the argument.

**`asm/` is deliberately excluded, and widening the scope would break it.**
The allowlist in `~/.config/rag-gpu/rag_sync.py` is `docs include src parked
tools_src config` — roughly a third of the tracked files, about 1 MB. The rest
are the `.s` listings, ~89% of the tree, and they are the worst possible embedding
target: 1799 files of `lui`/`lw`/`addiu`/`jr $ra` collapse into near-identical
vectors and would drown every real hit. They are also exactly where this
project's retrieval must be **exact** — `grep -c '%gp_rel'`, `grep -l
'lui $at,%hi('`, the `0x80073840` scope cut, `candidates.HAND_WRITTEN`. A
semantic layer that answers those *approximately* is not a neutral addition;
it is a new way to be confidently wrong, in the same failure mode as the
167 → 136 → 66 miscount. Read a listing with grep, never with search.
And note `siblings.py` already *is* the similarity search over listings, on
instruction n-grams — the right metric for this domain, and better than any
general-purpose embedder would be.

**The community's RAM map is a second collection, `ygofm-community`, and it is
kept separate on purpose.** Data Crystal documents ~27 NTSC-U addresses, ten of
which are already symbols here — `D_8009B361` is "opponent ID", `D_8009B364` is
"terrain type", `D_8017C2D8` is the 64 KB fusion table. That is worth having,
and it is worth *nothing* for matching: every blocker in this file is codegen
shape, and no community note touches a delay slot or a `-G` threshold. What it
buys is comprehension, which starts to matter now that the remaining functions
average 167 instructions instead of 26 — knowing a loop walks the fusion table
tells you its bounds before you write a line.

It must never be merged into `ygofm-code`. Several entries are literally `?`,
and a wiki guess ranked beside a measured paragraph, with no visible
difference, is the same failure mode that keeps `asm/` out of the index. So
every document is ingested under a `source` label beginning **`UNVERIFIED
datacrystal/`** and with that word in its body, because the label is what comes
back on every hit. The same marker is on the ten annotations in `variables.h`.
Treat all of it as a hypothesis to check against a listing, never as evidence —
the wiki's own function offsets do **not** resolve: `0x218F0` under this
binary's confirmed `0x8000F800` file-to-vram delta lands at `0x800310F0`, which
is not a function boundary in `asm/nonmatchings/`, and neither is any other
delta tried. Names are annotated, offsets are not.

Ingest is manual and has no git lifecycle, so it is deliberately outside the
hook path. TCRF blocks scripted fetches with a bot interstitial — `curl` and
the MediaWiki API both fail — and a browser `User-Agent` alone does not clear
it; the fetch has to go through a client that renders.

Hooks are `post-commit`, `post-merge`, `post-checkout` (branch switches only),
`post-rewrite`; they are synchronous but cost **0.1s** on a typical 4-file
commit, and every path out is `exit 0` — a RAG index is a convenience, a
commit is not.

**When the box is down it degrades, and that was measured rather than
assumed.** An IPS that *drops* packets makes `urlopen` block for its whole
timeout — a closed port and a blackholed IP both cost the full 8s — so the
`initialize` probe gets 3s of its own, a breaker file mutes the box for 300s
after a failure (second and later commits cost 0.1s), and the changes skipped
while muted are **queued and replayed** on the next run that connects. Without
that queue the mute would silently drop every commit made while the box was
down, which is the staleness the whole design exists to prevent. Do not
"fix" a slow hook by backgrounding it: a detached `rag_sync` outlives the
commit and this repo's cadence would stack them against one collection.

**`git reset` is still their blind spot** (no hook fires at all), so
resync by hand now and then:

```
RAG_GPU_DEADLINE=900 python3 ~/.config/rag-gpu/rag_sync.py bulk-code ygofm-code
```

`.git/hooks/` is not tracked, so a fresh clone has none —
`~/.config/rag-gpu/install-hooks.sh <repo> <collection>` reinstalls them and
skips any hook that already exists. The log is `.git/rag-sync.log`, and the
endpoint comes from `RAG_GPU_URL`.
If the MCP connection times out, suspect a content-inspecting firewall or IPS
cutting the long-lived SSE stream rather than the server: ask for an exception
on the RAG host and port. An open TCP port does **not** clear this —
inspection kills the stream after connect, so a clean handshake proves
nothing.

## Two habits that cost real time when skipped

**The GitHub repo is private again** (it was public for a few hours on
2026-08-07). Two consequences worth knowing. Pushing over HTTPS needs a
credential helper now that anonymous access is gone -- `gh auth setup-git`
configures it and the existing token already has `repo` scope; without it
`git push` fails with a bare 403. And the traffic figures from the public
window are worth reading correctly: 0 forks, 0 stars, 7 unique visitors, but
115 clones from 69 unique sources. That ratio is scraper bots, which hit new
public repos within minutes -- not human interest, and not undoable. Going
private stops future exposure; it does not recall what was already mirrored.

**A tool's answer only counts if it measured what you think.** Nine bugs in
this project were tools reporting confidently on something they had not
measured — a
stale object, an unverified flag, a crashed build read as clean. When a tool
says "no", ask whether it could have said "yes"; when it says "yes", ask whether
the run it judged completed. The cheapest way to fall into this is a **filter**:
`try_func.py ... | grep -E '<<|differing|MATCH'` prints nothing both for a clean
match and for a compile error, because the error text matches none of the three
patterns. Read try_func's last lines, not a grep of them.
**And never rank candidates by the difference count alone.** The diff is
positional — line *i* against line *i*, no alignment pass — so one missing
instruction marks every line after it as differing. A candidate one `nop` short
scores as badly as the length of its tail; a candidate with seven genuine
register disagreements scores seven. Ranking inverts the truth exactly when you
are closest: func_80041D60's winner scored **15** against a **7** that was
seven real differences, and pruning by score would have thrown the match away.
try_func now prints both instruction counts on every run and shouts when they
differ — read that line first, and when the lengths differ read the *first*
difference rather than the total. And when the difference is a
small number of **`nop`s**, suspect the reader: `objdump` collapses a run of
identical words into `...`, which cost func_800357E8 two nops that were in the
object all along (fixed with `-z`, but the class of bug recurs).
The same class, ninth instance: `$30` has two ABI names. The target's `.s`
writes `$fp` and objdump prints `s8` for the same register, so every function
that reaches $30 showed four phantom differences (func_80060E70 surfaced it).
try_func's register table only rewrote the *numbered* form. Fixed, and
check_try_func run in both directions afterwards -- 105/105 of src still
MATCH and 106/106 of parked still differ, so the loosening ate nothing.

The same class, seventh instance: `candidates.py`'s park filter took the whole
line of `PARKED.txt` as the function name, so it stopped working the day entries
started carrying `-- diagnosis` inline. Only the oldest name-only entries were
still excluded; everything parked since was being re-offered as a fresh
candidate, and the tool said "0 clean candidates" in a band where it meant
"none *left*". A filter that silently matches nothing looks exactly like a
filter with nothing to match — print the size of the set once in a while.

**A scan is only as good as the filters it copies.** The `lui $at` pool was
counted three times and was wrong twice, each time because the ad-hoc scan
skipped a filter `candidates.py` already applies. 167 became 136 when the
signature was tightened from `lui $at` to `lui $at,%hi(` — the loose form
catches the overflow check aspsx wraps around a `div` — and 136 became **66**
when `candidates.HAND_WRITTEN` was applied, because 62 of the remainder are
the GTE block (`lwc2`/`rtpt`/`avsz3`). func_80069E44 is the specimen: it saves
`$s0`-`$s2` into the *caller's* struct rather than the stack. Import the
filters rather than re-deriving them.

**Never write *why* past what you measured, and never write "nothing else
works".** Four times in one session a mechanism was asserted one step beyond
the evidence, and three were falsified by something already in the repo: "gcc
will not build the giv for a *stack* array" (it is store-destination versus
load-source, the frame is irrelevant); "the byte-address load may alias the
*escaped* local" (a global destination behaves identically, so it is the cast);
"a base that is a pointer *value* fixes the `addu` order" (two matches from the
same afternoon are plain `+` on exactly that); and "reachable only by making
gcc want $a1" after two shapes. The rule that costs nothing: when a sentence is
about to say *why*, either name the counterexample you checked, or write
"**N shapes measured, discriminator not established**". A control probe is one
try_func run — cheaper than the retraction.

**Measure before concluding.** Claims here have been wrong by 4x from reasoning
over a handful of samples. Scan the whole binary before letting a pattern
justify a decision — and then **filter the scan by scope**: anything at or above
`0x80073840`, or listed in `docs/LIBRARY_FUNCS.txt`, is PsyQ library code that
stays as assembly. `candidates.py` applies that filter; a hand-rolled grep over
`asm/` does not, and three functions were parked as matching failures before
anyone checked.

**A name-only park may still carry stale flag-table entries, and they are
worse than none.** func_80049CB0 had `PER_FUNC_FLAGS[...] = _O2_G0` from an
attempt that predates every lever here, so try_func silently compiled at
`-O2 -G0` and the candidate read 12 differences; at default compiler flags
with the same `as -G0` it was 8, and two names later a match. The header line
try_func now prints is what surfaces it — **read the flags before the count**,
and when picking up a name-only park, `grep <func> tools_src/build.py` first.

**The name-only park entries are the richest seam left.** A bare name in
PARKED.txt with no `parked/<f>.c` and no diagnosis is the oldest kind, it
predates every lever in this file, and `check_try_func`'s parked direction
cannot even see it. Four fell in two iterations — func_80037D2C, func_8002C518,
func_80035A64, func_8003B9BC — three of them straight off `siblings.py`, and
two needed nothing but a correct reading of the listing. Cross `siblings.py`
against the entries that are just a name and work that list first.

**`check_try_func.py` is also a park re-reader.** Its second direction — every
file in `parked/` must still report a difference — reaches only the ~100
entries that have a candidate file, so it is a sweep of that set and not of
PARKED.txt. It is what surfaced func_80015078: an old name-only park entry whose candidate had been correct for
some time, because the declarations around it changed after it was parked. It
built green on the first try. Run it after touching try_func, and read the
parked failures as candidates rather than as tool bugs.

**A scripted paragraph replace must be bounded at both ends.** Rewriting one
PARKED.txt entry with `s[:i] + new + s[j:]`, where `j` scanned forward for the
next `# ---` separator, deleted **720 lines** — every entry after it, because
the newer entries are appended without that separator. The build stayed green
and `git status` showed one modified file, so nothing flagged it; it surfaced
only when a later `grep` for an entry that should exist came back empty.
Bound the end on whichever comes first of the separator *and* a blank line,
assert the resulting slice is the size you expect, and check the file's line
count before and after. Recovered with `git show HEAD~6:docs/PARKED.txt`, and
the useful diagnostic was `for i in 0..10; do git show HEAD~$i:<file> | wc -l;
done` — the drop is obvious in one column.

**`git checkout -- .` is not "undo my last file".** It reverted four files of
uncommitted work in this project once, to remove one bad `src/` file that
`rm` would have handled. The untracked candidate in `parked/` survived and
everything tracked did not, which is the worst shape for noticing. Name the
path.

Run `tools_src/sync_count.py` before committing a batch — the count has been
typed wrong twice.
