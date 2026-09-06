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
**And gate the commit on the exit status with `&&`**, not on reading it: on
2026-09-05 a build printed `EXIT=1` with 903 differing functions and the
commit on the next line went out anyway (04c466a), because the two commands
were merely sequential. A transcription's `__asm__` block is NOT flag-proof,
which is what that build was saying: func_8002C7E8's needs its
-mno-split-addresses row until real C replaces it.
sha1 `84747e64f6da8e764206ec203e489acf8c9dcf7d`. Always the project `.venv`,
never a bare `pip install` — installing globally once broke another tool's pins.

## Toolchain: cc1psx 2.8.1, maspsx emulating aspsx 2.79

**The SDK number is not the compiler version, and calling it "PsyQ 4.5" here
was wrong.** krystalgamer made the correction on 2026-08-31 -- *"psy-q 4.5 e a
biblioteca de runtime, o compilador e diferente; para o decomp nao interessa o
runtime, mas interessa saber que compilador eles teriam usado na altura"* --
and it holds up under `strings`, which is the whole cost of checking it:

| what the build actually runs | version |
|---|---|
| `tools/psyq45/BIN/CC1PSX.EXE` | **gcc 2.8.1**, `SN32 BUILD 4.0.0010` |
| `tools/psyq46/.../CC1PSX.EXE` | **gcc 2.95.2**, `19991024 BUILD 4.0.0030` |
| the assembler | **maspsx**, `--aspsx-version=2.79`, then GNU `as` |

**And the directory names are archive names, not CD contents -- a second
label, corrected the same day.** krystalgamer, relaying mkst: the compilers
shipped on the retail Psy-Q 4.5 and 4.6 CDs were **gcc 2.8.1 and gcc 2.7.2**,
and mkst mislabelled this 2.95.2 as "psy-q 4.6" in the `mkst/esa` releases.
Our `tools/psyq46` came from `psx.arthus.net/sdk/Psy-Q/Psy-Q_46.zip`, and its
only compiler is an October-1999 gcc 2.95.2 -- later than the name implies.
Nothing here can verify what a CD contained; `strings` verifies what these
files contain, and those are different claims. Say "the archive we have as
psyq46", not "PsyQ 4.6".

**Untested here, and cheap: gcc 2.7.2.** If the period CDs carried 2.7.2
beside 2.8.1, it is a compiler this tree has never run once. 2.8.1 reproduces
all 1050 functions so it is not in doubt as the main one -- but no parked
residue has ever been put in front of 2.7.2, and the 93 in `docs/PARKED.txt`
are exactly the population where a second period compiler would show up if it
were going to. Getting one: the `mkst/esa` releases ship compilers.

Three consequences, all of them things this file used to get wrong:

  * `ASPSX.EXE` (2.79 in the 4.5 bundle, 2.86 in 4.6) is **never executed**.
    maspsx emulates its quirks and `mipsel-none-elf-as` does the assembling, so
    the assembler version in the heading was decoration.
  * `YGOFM_PSYQ=46` swaps `CPPPSX.EXE` and `CC1PSX.EXE` and **nothing else**.
    The environment variable is misnamed: it selects a *compiler*.
  * `tools/psyq47.zip` contains `DOCS/`, `INCLUDE/`, `LIB/` and **zero `.EXE`
    files**. A PsyQ release does not necessarily ship a compiler at all, which
    is the correction in its cleanest form -- the number names a library
    release, and library releases are exactly what a matching decomp does not
    care about.

So the measurement below is real and reproducible, and its **label** was the
error. It is not "4.5 beats 4.6"; it is **gcc 2.8.1 against gcc 2.95.2**, two
compilers seven years apart, and of course they differ. Stated that way it
stops sounding like a claim about Sony's version numbering and starts being
what it is: evidence about which compiler the 1999 build used.

`YGOFM_PSYQ=46 .venv/bin/python tools_src/build.py` puts **288 functions at
the wrong size**, with deltas up to ±28 instructions, while the same tree at
2.8.1 hashes `84747e64...`. It was assumed to be interchangeable for the
project's first 219 functions and produced a byte-identical build anyway --
most functions are too small for two compilers to differ on, so a small sample
cannot tell them apart. The largest discriminators, i.e. the test cases to
settle it with anyone who believes otherwise:

    func_80041068  +28    func_80022D94  -24    func_80059AF8  -21
    func_80040DD8  +28    func_8005A98C  -22    func_80058838  -21

This matters beyond bookkeeping, because the other decompilation of this
binary (docs/MERGE_UNCHIGA.md) states that 4.6 is required. Both can be true:
**750 of his functions compile to the retail bytes under cc1psx 2.8.1**, so
his C is not tied to a later compiler -- his whole pipeline differs (ASPSX >=
2.56 semantics emulated through maspsx, plus an asm round-trip fixup), and a
different pipeline can reach the same bytes from a different SDK. What is
*not* true is that this tree can be moved as a formality. Migrating it is a
re-derivation of 288 functions, and the number is the argument.

**The general lesson is the one this file already teaches about the repo's own
visibility: a label repeated for a month is not a measurement.** "PsyQ 4.5"
sat in this heading, in `build.py`'s comments, in the environment variable's
name and in a draft written for other people, and one `strings` call settles
what it actually meant. When a version number is load-bearing, read it off the
binary that runs.

`tools/` is gitignored and must be re-fetched per machine; it holds psyq45,
psyq46 and psyq47 side by side, so the comparison above costs one command.

## Adding a function

**Start with the m2c draft.** `tools_src/m2c_draft.py func_XXXXXXXX` prints
structurally-correct C for the listing in about a second: loop and switch
shapes, case groupings, reciprocal multiplies read back as `/ 3`, field
offsets, the signedness of each load. On a 767-instruction function that is
the ten to fifteen minutes of hand-decoding, gone. Measured on a random 60 of
the open in-scope functions: **60/60 produce a draft** (median 147
instructions), and 25/25 already-matched ones still do, so it is not
size-limited. The wrapper passes `asm/data/*.rodata.s` automatically -- five
of that sample were `jr $v0` switches that emit *nothing* without their jump
table, which is the class this file calls the largest one open.

It closes no matches. Every lever below -- which register holds a value,
where a `lui` sits, whether a store sinks into a delay slot -- is invisible
to it, and that is where the hours go. Two of its comments are worth reading
rather than deleting:
- **"Duplicate return node #N. Try simplifying control flow for better
  match"** -- it found a tail retail shares and it does not. That is step 5's
  cross-jumping question; on func_8004C5C8 the answer was to write the shared
  tail out per arm instead of once after the `switch`.
- **`var_s1`, `var_s1_2`, `var_s1_3`** -- the suffix is the register. Three
  names on one register is a standing hint that the source had *one* name;
  func_8002C9B4 matched exactly that way, one variable for the selector and
  the loop counter both.
Its types are guesses and its `unkNN` field names are its own. Nothing it
prints is evidence; try_func is.

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
ordinary — and it also *tells you something*: see the divisor rule in step 4,
because a `break 7` means the divisor was a variable rather than a literal.
What is still filtered on `break` is the two-operand form
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
    **The window is `G_as < N <= 8` and it is bounded at BOTH ends** -- a
    size that is merely "big enough to be non-small" fails, because it also
    clears cc1psx's own `-G8` and cc1psx then emits its own splittable pair
    instead of the bare symbol. func_8002FD10 wants `u8 D_800EAE98[8]`; the
    *honest* `[0x40]` for a table that reaches +0x3C is worth nothing at all.
    So when you inflate a size, inflate it to eight, not to the truth.
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
it.
**It is not always a pointer table: it can be a callback argument, and then
the address is already declared as a data symbol.** func_8002DDFC was
`extern u8 D_8002DDFC[];` in variables.h, passed as the fifth argument of a
`func_80014EEC` call by a function that already MATCHES. Splitting it meant
renaming the symbol to a prototype in functions.h and editing that caller —
and the build staying byte-identical through the rename is the proof the
split was right, because the address is emitted the same way either way. Splitting is just editing `asm/nonmatchings/31D8/`: truncate the first `.s`
at the boundary and write the tail into `func_<addr>.s` with its own
`glabel`/`endlabel`. build.py globs that directory and orders by address, so
nothing else has to change; add the `INCLUDE_ASM` line to `src/31D8.c` to keep
it in sync. The first half being epilogue-less is the *reason* splat merged
them, and it is also the noreturn tell above.

**When it does not match, work in this order.** Each step makes the next
meaningful, and skipping to the last one wastes hours:

0. **Read the addressing before writing any C.** Not a debugging step — a
   first step, and it has decided the last four functions without a single
   round. Count `%gp_rel` and `lui  *\$at, %hi(` in the listing (splat writes a
   space after the comma -- the pattern without it matches **zero** files, and
   that silent zero survived in this document for months), read the symbols'
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
   **The base local for that split must be assigned where the base is
   materialised, and the whole sum written as ONE expression.**
   func_80018DB4 has func_8001B938's shape exactly -- `D_8015C424 + idx * 28 +
   0x48000` read at `+0x36B8` -- and the difference between 21 differences and
   a MATCH is only how it is spelled. `g = &D_8015C424[idx * 28]; g = g +
   off;` with `off` a named local reassociates to `(base + off) + idx * 28`
   and splits the constant's `lui`/`ori` pair across the block; `base =
   D_8015C424;` immediately before, then `g = base + idx * 28 + 0x48000;` as
   one expression, is retail's `(idx * 28 + base) + off` with the pair
   adjacent. Assigning the base earlier (before the preceding call) is 24, and
   writing the symbol inline with a named `off` is 24. A named `off` is fine
   *if* the base is a local and the sum is one expression -- that spelling
   also matches -- so the lever is the base local and the single expression,
   not the constant's name. Six placements of the `off` assignment, a `u32`
   declaration and two `do { } while (0);` groupings were measured first and
   every one of them is 21 or worse.
   **And a large offset can want splitting in two, which one local cannot
   do.** func_8001B938 reads `D_8015C424 + idx * 28 + 0x4B6B8`. Against the
   symbol the whole thing folds into `%hi`/`%lo`; against a base local gcc
   materialises 0x4B6B8 with `lui`/`ori` and leaves the load at `0($v0)`;
   retail materialises **0x48000** and leaves **0x36B8** as the load's
   displacement. Getting that needs a second name — an intermediate pointer
   `g = b + idx * 28 + 0x48000;` read as `*(s32 *)(g + 0x36B8)`, or the
   0x48000 assigned to its own variable — because as one expression gcc
   folds the two constants before it ever picks a split. 84 differences to
   5 on the base local, 5 to 3 on the second name.
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
   **One name for two SEQUENTIAL constants is how you make the second reuse
   the first's register.** Retail holds 0xFFDDFFFF and then 0x10000 in `$a0`,
   the second materialised into the register the mask has just vacated. No
   ordering of two separate literals reaches that, and neither does naming
   them separately -- gcc allocates each a register by its own live range, and
   the short one wins `$v0`/`$v1`. Writing both against **one** name does:
   `m = 0xFFDDFFFF; … D_8009B0F4 = v & m; w = D_8009B0F4; m = 0x10000;
   *(s32 *)(p + 0x1C) = m; D_8009B0F4 = w | m;` is func_80020BE4's 14
   differences to 11. The two values never coexist, so one pseudo is legal;
   one pseudo is one register, and gcc then places it where the *sum* of the
   two live ranges says rather than where either alone would. This is the
   two-names rule read backwards: two unrelated values must not share a name
   when the target gives them different registers, and they **must** share one
   when it gives them the same register. Read the listing, then count.
   **A switch can want the local form in one arm and the direct form in the
   others**, which is the same rule at arm granularity. func_8003B808's case 0
   needs `v = D_8009B0F4; v &= mask; D_8009B0F4 = v;` and its cases 1, 3 and 4
   need the plain `D_8009B0F4 = D_8009B0F4 & mask;`; writing all four the same
   way is 45 differences and splitting them is 15.
   **And a local shared by several arms usually wants ONE NAME PER ARM, which
   is a bigger lever than any single arm's spelling.** One name is one pseudo
   whose live range spans the whole `switch`, so the global allocator gives it
   a register of its own and every arm's allocation rotates behind it; one
   name per arm is several short block-local ranges that land where retail's
   do. func_80057544 reads D_8009B0F4 in five arms and went 53 differences to
   29 on five names, and func_8002BD0C 51 to 41 on splitting one shared
   constant out of one arm. **The mirror was measured in the same minute and
   is what makes it a sweep rather than a rule**: splitting the *mask* the
   same way is 29 to 42 and splitting the *record pointer* is 29 to 34,
   because retail really does carry those two in one register across every
   arm. So which variables want it differs *within one function*, and the
   only way to know is to try each -- `tools_src/sweep_arm_split.py` does
   exactly that, one variable at a time and then all its arms together. It
   reads `goto`-labelled arms as well as `switch` arms, which matters because
   most of the D_8009B0F4 family is an `if`/`else` chain with `goto m0;` and
   the arms are the same thing one level down; it offers a split on a
   label-delimited arm only when the arm ends in `return`/`break` with no
   `goto`, or when the name appears nowhere after it. It
   deliberately cannot find the other shape, a name shared by a *group* of
   arms that `goto` one join label (func_8002BD0C's `n` wants one name for
   the join1 group and another for the join2 group, 41 to 35); do that by
   hand.
   **And the unit is the distinct VALUE, not the arm.** The line above says
   the mask wants one shared name; that is a step on the way and not the end
   of it. func_8003A01C's arms use 0xFFDDFFFF once and 0xFFDCFFFF twice, and
   retail holds them in two different registers -- so the source has two
   names, one per constant, each shared by the arms that use it. One name for
   all three arms is 13 differences and two names is 7. It carried to
   func_8002F4C0 (35 to 24) and func_8002BD0C (32 to 27), and was worth
   nothing on func_8002FB78 or func_80057544, so check rather than assume.
   The reading that makes it obvious in hindsight: a mask constant in the
   original was almost certainly a `#define`, and two different `#define`s
   are two different values however many arms use each.
   **And the rule runs in both directions -- read which register retail
   uses before splitting anything.** func_8003DA40 has two pointers that
   never coexist, one per half of the function, and retail keeps both in
   `$s1`. Two names is 29 differences, every one of them `$s0` against `$s1`;
   *one* name is a MATCH. Six declaration orders moved nothing, which is the
   usual tell. So the question is never "how many names" in the abstract: it
   is whether the target's registers say two live ranges or one.

   **But register reuse in the listing is NOT evidence of name reuse in the
   source, and believing it is expensive.** func_8002E128 reuses `$s1` for the
   argument, then the decoded index, then a flag byte read in the *other* arm
   of the function's top-level `if` -- so the obvious reading is one name for
   all three. Writing it that way is 49 differences, every one of them a
   register; giving the flag byte its own name is 22, and the split fixes the
   whole function's allocation rather than just that block. The rule above
   ("read which register retail uses") tells you when to *stop* splitting; it
   does not tell you to merge. Two values that never coexist *may* share a
   register without sharing a pseudo, because the allocator is free to reuse a
   dead register whether or not the source did.
   **The commonest cheap instance is a scratch name reused for the same
   *kind* of value in three unrelated places.** func_800154E4 computes
   `0xFF - x` in a loop, again after it, and a clamped difference three times
   in a third block; one `v` for all of them is 22 differences, every one of
   them that name's register, and three names is a first-try MATCH. Retail
   gives each a different caller-saved register precisely because each is
   short-lived. When a diff is nothing but one variable's register repeated,
   count how many *unrelated* values are wearing that name.

   **The rule scales to whole *phases* of a function, and there it rotates
   every register rather than one pair.** func_8004D75C is two sequential
   loop nests over the same record: reusing the first nest's index, cursor
   and counter in the second is 63 differences, and giving the second nest
   its own three names is 40 -- the entire drop is allocation, no instruction
   moved. A name reused across two phases lives from the first phase's start
   to the second's end, which raises its allocation priority above values
   that genuinely need a good register, and every register downstream shifts.
   The two nests never overlap, so nothing forced the sharing; it was tidiness
   in the source and it cost a register class. When a function has two clearly
   separate halves and the whole allocation is rotated, count the names that
   cross the boundary before reaching for the permuter.
   **And two arms of a branch are two values, even though only one runs.**
   func_800250C8 accumulates into a field in two mutually exclusive blocks,
   `+ c * 100` in one and `- c * 100` in the other; one `v` for both is 13
   differences, entirely the `$v0`/`$v1` rotation that follows the `addu`'s
   destination, and a second name for the second arm is a MATCH. The arms
   never both execute, so nothing forces them to share — but one name makes
   one pseudo, and the pseudo is numbered before the branch. Compound
   assignment gets the destination right for a different reason and costs
   more than it saves: `v += c * 100;` gives retail's `addu $v1,$v1,$v0`
   and then lets gcc sink the store that follows it into the branch's delay
   slot, which is -1 or -2 instructions.
   **A plain statement written before the others moves with them.** A loop
   counter's `i = 0` sitting above the four stores that precede the loop is not
   cosmetic: it lands before them in the prologue, where the `for`-init form
   lands after (func_80061008). Read the prologue's order and write that order.
   What will *not* move that way is anything the compiler puts in the loop
   preheader — a hoisted invariant, a biased induction variable. Naming those as
   source locals makes it worse: `s16 *q = (s16 *)(p + 6);` alongside `p` gave
   func_80061008 a *third* induction variable and went 10 differences to 51.
   That is about a preheader gcc *builds*; the two rules below are about a
   preheader whose contents you can order, and both were measured on
   func_8005611C in one afternoon.
   **A preheader constant is a name, and where you assign it decides the
   preheader's order.** A loop storing a literal 1 hoists the `addiu` into the
   preheader, and its position among the other preheader instructions follows
   the source: `n = 1;` written *above* `i = 3;` emits retail's
   `addiu $a2,1` / `addiu $a0,3` / `addu $a1,$s0,$a0`, and written below it
   emits the same three in the other order. Two differences, one line's
   position, and the loop is otherwise identical. Related, same function:
   a cursor initialised `q = p + 3` folds to one `addiu`, where `i = 3;
   q = p + i;` keeps retail's `addu` through the counter's register — write
   the cursor against the counter, not against the constant.
   **A run of stores sharing one constant wants to be written next to the
   other such run, not where it is emitted.** Three `sw` of 0x1000 and three
   of 0x800 come out separated by an unrelated run of byte stores; written in
   *emission* order the 0x1000 is materialised late and shares `$v0` with the
   bytes, written next to the 0x800 group it gets `$v1` of its own and lives
   across to a fourth use further down, which is what retail does. That is
   func_8005611C's 24 differences to 2 — and it rotated the register of every
   value downstream, both loop cursors included, so it read like a loop
   problem and was an ordering one. **When a whole function's registers are
   shifted and the instructions are right, look for a constant whose live
   range should span a neighbouring block.**
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
   - a loop whose FIRST instruction is an exit test that the target keeps,
     and whose back edge is still conditional, is **`while (1)` with an
     `if (…) goto after;` at the top and `break`s at the bottom** -- a third
     form, and neither of the two above. `do { if (c == 0) break; … }
     while (a && b);` is not it: gcc rotates that head test to the bottom and
     merges it into the loop-back, so the head's own load and branch vanish.
     Writing the head test with a `goto` label instead keeps it and destroys
     the loop -- the loop pass stops recognising a natural loop, so a
     jump-table base or any other invariant is no longer hoisted into the
     preheader. `while (1)` is the only spelling that keeps the head test AND
     the hoist (func_80046294, -10 then +2 then +1 then 151/151).
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
   **For a *commutative* operator the destination decides the operand order,
   and undoing that needs a fresh name AND a copy back.** gcc's expand_binop
   swaps a commutative operator's operands when the destination is one of
   them, so `t = d * t`, `t = t * d` and `t *= d` all emit `mult t,d` — no
   spelling of the multiply reaches retail's `mult d,t` while `t` is the
   destination. A fresh name does (`u = d * t`), and is then allocated the
   register of whichever operand dies at the multiply, which is the *other*
   one. So each half is reachable alone and they do not compose: fresh name
   gives the order and loses the register, `t` as destination gives the
   register and loses the order, both are three differences. `u = d * t;
   t = u;` takes both — the copy links the new pseudo to `t` and coalesces
   away. func_8005F27C and func_8005F5C8 matched on it together, having sat
   at exactly one difference each through nine hand shapes, a full flag
   sweep and two permuter runs. **The identical residue in two
   independently written functions is what said it was systematic**; a
   one-instruction difference in a single function reads like local pressure
   and would have been parked.
   The inverse too: where the target reads something **once** and you read it
   twice, look for a store between your two reads that gcc must assume aliases
   — `if (q[7]) x = q[7] << 4;` reloads across a store through another
   parameter, and one local was the whole of func_80059000.
   **And the same shape run forwards stops a store being sunk.** A field
   bumped and then tested — `c = p[K] + 1; p[K] = c; if ((s8)c < 6)` — gives
   gcc a second register for the result and it sinks the `sb` into the test's
   branch delay slot; written with no local at all, `p[K] = p[K] + 1;` then
   `if ((s8)p[K] < 6)`, the second read forces the store to stay where it is
   and CSE folds the read back into the stored value, so it costs nothing.
   func_8003B378, the last difference. `c = p[K]; c += 1;` and `c = c + 1;`
   are both still 16, so it is the second *read*, not the compound
   assignment.
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
   **Third direction, and it is a STORE-ORDER lever against a scalar
   global.** func_80013B68 stores three words and three bytes through a
   record pointer and then does `D_8009B0F4 |= 0x20`; retail has the bytes,
   then the flag's load, then the words, then the flag's `ori`/`sw` sunk into
   the epilogue. Written as cast stores, `*(s32 *)(p + 0x24) = arg0`, every
   store conflicts with the scalar global in gcc 2.8's dependence test, so
   the emitted order is the source order and no source order reaches retail
   -- and bytes-first costs the parameters their registers (14). Written as
   struct members through the same pointer, the flag's load and store are
   free to move across them, the scheduler puts the load where retail has it,
   and the words-first source order keeps the parameters in `$s1`-`$s4`.
   7 differences to a MATCH on the declaration alone. So when a global's
   read-modify-write sits among stores through a pointer and retail
   interleaves them, the stores were members. **It does not transfer to the
   D_8009B0F4 dispatcher family**, whose arms have the same shape on paper:
   rewriting every `*(T *)(p + K)` there as a member is 14 -> 43 on
   func_8002BD0C, 26 -> 61 on func_80057544 and 77 -> -2/161 on
   func_80019608 (a scratch `structify.py` did the rewrite mechanically).
   Those arms want the cast stores' conflicts, which is what keeps their
   named reads where they are. Read which way the target wants it.
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
   **A named read-back of a stack slot is how you get a store-then-reload that
   gcc would otherwise forward.** Where the target stores a computed value into
   an address-taken local and then loads it *twice* -- `lh` for a comparison
   and `lhu` for the arithmetic -- gcc's own output keeps the value in a
   register and sinks the store into the branch's delay slot. `r = b[1];`
   written after the store, with the comparison still reading `b[1]` and only
   the arithmetic reading `r`, splits the two: func_8005D994, 11 differences
   to 5. Naming it for *both* corrections is 9, and a borrowed local rather
   than a fresh one is 7, so this one wants a fresh name used exactly once --
   the opposite of func_8002E128, where the borrow beat the fresh name by 7.
   The permuter reached the same 5 by wrapping the store in
   `if (arg0) { A } else { A }`; the named read is the spelling anyone would
   write.
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
   **The partial sum inside a modulo-wrap wants to be gcc's OWN temp.** The
   idiom `x = (v + d + 0x1000); x -= x / 0x1000 * 0x1000;` shows up wherever
   this binary wraps an angle. Writing the partial sum as a second named local
   -- `a = v + d; t = a + 0x1000;` -- is the obvious decomposition and it is
   *wrong*: `a` then takes the register gcc wants for the division's own
   temporary and both halves of the expansion rotate (func_80058434, 11
   differences on two identical blocks). One name for the whole sum,
   `t = v + d + 0x1000;`, is a MATCH, and so is naming only the *load*
   (`a = v; t = a + d + 0x1000;`). Writing it with no name at all -- the
   whole thing twice in one expression -- is +6, because gcc then computes the
   sum twice. So: name the value the division consumes, and nothing else.
   **And the mirror, measured the same hour: in func_8005D994 the same wrap
   wants its OUTER subtraction inline.** `b[1] = (t - x) - (t - x) / 0x1000 *
   0x1000;` is 11 differences where `t = t - x;` first is 17. So this is not a
   rule about naming in general -- it is a rule about *which* value the
   division consumes getting a register of its own. Read the target's
   registers before choosing, and expect the two functions to want opposite
   spellings of the same idiom.
   **gcc folds a scaled dividend and an intermediate assignment blocks it.**
   `(x * 8 + 0x7FF) / 2048` comes out as `(x + 255) / 256` — two instructions
   short of retail's `sll 3` / bias / `sra 11`, and the shortfall cascades
   through the whole prologue. Splitting it in two against the same name —
   `n = x * 8;` then `n = (n + 0x7FF) / 2048 + 1;` — reproduces retail.
   `<< 3` for the multiply does not block it, and splitting at the `+ 0x7FF`
   instead is worse (func_80047788, 48 to 18). This is the same family as the
   `(x & 0x100) != 0` fold in step 2: one name reused across two statements
   is what stops the combiner.
   **A read-modify-write on a byte global wants NO local, because the
   second read is where the zero-extend comes from.** `D_8009B066 =
   (D_8009B066 + 1) & 1;` followed by a use of `D_8009B066` in arithmetic
   emits `addiu` / `andi 1` / `sb` / **`andi 0xFF`** -- the last one is the
   QImode-to-SImode conversion of the value read back. Written with a `u8 m`
   local for the same value the `andi 0xFF` does not appear at all, because
   gcc knows `(x + 1) & 1` already fits a byte and the local never crosses a
   mode boundary. func_8005BFC8 was one instruction short and 58 differences
   on exactly that, and dropping the local was -1 to 0 and 41. This is the
   mirror of the narrow-local rules above: there a narrow declaration
   *creates* a mask, here reading the global back does.
   **And the read-back can want its arithmetic in the SAME expression.**
   func_80024E58 stores a byte global and the next statement masks the value
   for a decrement: `n = v & 0xFF; call(); n = n - 1;` sinks the `andi` into
   the call's delay slot, `n = D_8009B364[0]; n = n - 1;` before the call is
   4, and `n = D_8009B364[0] - 1;` before the call is a MATCH -- the andi is
   the read-back's zero-extend and retail keeps it in front of the `jal`
   with the `addiu -1` in the slot. Two statements is not the same as one
   here, which is the func_80047788 scaled-dividend rule read backwards.
   **A `bgez` / `addiu` / `sra` triple around one value is a signed DIVIDE,
   not a shift, and writing it as a shift costs delay slots.** gcc expands
   `x / (1 << k)` as "if x is negative add (1 << k) - 1, then arithmetic
   shift right by k" -- so `bgez; addiu 0xFFF; sra 12` is `/ 4096` and
   `bgez; addiu 3; sra 2` is `/ 4`. Hand-expanding it into `if (x < 0) x +=
   0xFFF; x >>= 12;` computes the same thing but leaves the shift a separate
   statement, and gcc then does not have it available to fill the *next*
   test's delay slot the way retail does: func_8003A990 went ten differences
   to a match on writing `/ 4096` instead, after three attempts at moving
   the hand-written shift around. Read the bias constant -- it is always
   `(1 << k) - 1` -- and write the division.
   **A real `div` in the listing means the divisor was a *variable*.** This
   is the strongest single tell in the arithmetic family and it costs nothing
   to check: gcc emits a runtime `div` — the one aspsx wraps in
   `break 7` / `break 6` — only when the divisor is not a compile-time
   constant. Division by a literal that is not a power of two becomes a
   reciprocal multiply (`lui`/`ori` of a magic number, `mult`, `mfhi`, `sra`,
   `subu`), which is a completely different instruction sequence and about
   seven instructions longer, so the whole tail of the function reads as
   wrong. Write the divisor as a local: `k = 750;` then `/ k`. **Where you
   assign it matters** — inside the block that divides gives retail's
   `addiu $a0,$zero,0x2EE` scheduled into the preceding branch's delay slot,
   at the top of the function it is a length mismatch (func_8005F27C, 34
   differences to 1). The divisor being a literal in the *source* is
   therefore not what the listing shows; read the `break 7` and stop
   guessing.
   **A value gcc can PROVE fits sixteen bits loses its mask, and the fix is an
   initialiser it cannot bound.** Retail masking with `andi $v0,$t0,0xFFFF`
   before a compare means the source wrote a `(u16)` cast that survived; write
   `s32 bestv = 0xFFFF;` and gcc folds that cast away, because every value the
   variable can hold -- the literal, or a `u16` load -- provably fits. `-1` is
   the SAME value through the cast and is not provably bounded, so the mask
   comes back: func_8004A854, 13 differences to 11. It costs something in
   exchange, which is why it is not a free win: `-1` and the neighbouring
   `best = -1` are then one value, so gcc materialises it once and copies where
   retail has `addiu $t1,$zero,-1` and `ori $t0,$zero,0xFFFF` separately. A
   `u16` or `u32` declaration reaches neither half (13 both). **Observed once**,
   and the discriminator that would give both halves at once is not
   established.

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
   permuter found the negation at iteration 79. **Observed twice** now --
   func_8003353C's last index went 3 differences to 2 on
   `e + 0xD - -(n * 0x10)`, after the plain `+`, the base-first
   `(e + n * 0x10)[0xD]` spelling and a named scaled index all left the
   `addu` index-first. Write the plain `+` first: it is *not* true that a base which is a pointer value
   forces index-first, because func_80049CF8 and its clone func_80049DD8 get
   `addu base,index` out of a plain `D_8009B458 + i * 0x28` on exactly that
   kind of base. What differs between them is not established; in the two
   that worked the index is a loop giv and the base is reloaded per
   iteration, and in func_80047CC4 it is `(u8)i * 2` computed inside a
   conditional.
   **The `(s32)` cast route works on THREE sites in one function, and one of
   them needs the index named as well.** func_8002538C indexes a byte table
   by a loop counter, a second table by a computed index, and a record array
   by the byte it just read, and retail puts the *index* first in all three
   `addu`s. `*(u8 *)(i + (s32)cb)` fixes the first and
   `(u8 *)(… * 0x1C + (s32)rb)` the third, but the middle one --
   `tb[D_8009B1AE + D_8009B1D5 * 0x14]` -- still comes out base-first inside
   the cast until the index is a named local of its own:
   `ix = D_8009B1AE + D_8009B1D5 * 0x14;` then
   `*(u8 *)(ix + (s32)tb)`. 5 differences to 3 to a MATCH.
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
   **A symbol added last is emitted last; a base local is how you move it.**
   func_800255FC computes `(idx + 5) * 4 + d * 80` and adds a table base.
   Retail groups the two products first and the base last — `D_80090800 +
   (…)` reassociates to `A + (B + base)` and is wrong — but it also
   *materialises* the base first, right after the preceding call, where
   writing the symbol as the last term emits its `lui`/`addiu` immediately
   before the `addu`. Assigning it to a local after the call and adding the
   local gives both: grouping from the source, position from the
   assignment. The same function's other index wants the mirror treatment —
   `D_800907D8[idx + (d * 20 + 5)]` still lets gcc re-associate the `+ 5`
   onto `idx`, and a named `n = d * 20 + 5;` is what pins it.
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
   **A `nop` in a branch's delay slot can mean the value the filler wanted is
   still live on the branch's other path.** func_8004D75C extracts a field
   with `srl`/`andi` right after a `bgez`, and retail leaves the slot empty.
   Written as one expression the shift lands in a fresh temp that is dead on
   the taken path, so the filler may legally hoist it into the slot; written
   as two statements against the *same* name -- `s = (u32)v >> 16; s = s &
   0x7F;` -- both instructions write `s`'s own register, `s` is read on the
   taken path, and the hoist is illegal. Same two instructions, and the `nop`
   comes back. This is the `(x & 0x100) != 0` fold rule read for its
   *scheduling* effect rather than its instruction count: one name across two
   statements does not only block a combine, it pins the value's register.

   **A constant subtraction on a call's result can belong on the far side of
   the *next* call.** func_8005A6A8 takes a square root and subtracts 700
   from it. Written next to the call, gcc fuses the call-result move and the
   subtraction into one `addiu $s0,$v0,-700` and the function is an
   instruction short; retail has `addu $s0,$v0,$zero` followed by
   `addiu $s0,$s0,-700`, which only appears once the raw result has to
   survive a *second* call in a callee-saved register before anything is done
   to it. Ten spellings at the near position -- two statements against one
   name, `-=`, a fresh name, a fresh name plus a copy, four placements among
   the neighbouring statements -- are all identical, which is the usual tell
   that the axis is wrong; moving the subtraction after the next call is the
   whole fix. So when a call result and an arithmetic on it come out fused
   and retail keeps them apart, ask which side of the *following* call the
   arithmetic sits on.

   **`(x & M) / K * K` is a real divide in the source and gcc will fold it
   away if you write it as one expression.** func_80036DBC computes
   `(D_8009B34C & 0x30) / 16 * 0x10`; written whole, gcc proves the result
   equals `x & 0x30` and emits one `andi`, and the function comes out twelve
   instructions short. Split against one name -- `a = D_8009B34C & 0x30;
   a = a / 16 * 0x10;` -- and the `bgez` / `addiu 15` / mask expansion
   survives. Then **two names rather than one is a further four
   instructions**: retail keeps the masked value and the quotient in
   different registers, and one name makes the no-bias path a register copy
   where retail duplicates the mask into the branch's delay slot. Same family
   as func_80047788's scaled dividend, and the two levers stack.
   **And the shift's *kind* follows the intermediate's declared width.** With
   the masked value in an `s32` the quotient shifts `sra`; declared `s16` it
   shifts `srl`, which is what retail has -- gcc only proves the sign bit
   clear when the narrower type bounds it. `u32` is not the answer: that
   makes the divide unsigned and deletes the bias, which is eight
   instructions. 5 differences to 2 on one keyword.

   **Which side of a comparison the loaded value sits on decides which
   operand is loaded first.** `if (c[hi] < x)` loads `c[hi]` first;
   `if (x > c[hi])` loads `x` first. The two are the same expression to a
   reader and the same `sltu` to the assembler, and on func_8005A98C the
   difference was 24 against 20. So when two loads feeding one comparison
   come out in the wrong order, flip the comparison rather than reordering
   anything.
   **And when one side is a CALL, the same flip decides whether the other
   side's load is hoisted ACROSS it.** `*(u16 *)(p + 0xA0) < f(n, 0)` makes
   gcc issue the load first, which means keeping it live over the call in a
   callee-saved register; `f(n, 0) > *(u16 *)(p + 0xA0)` calls first and
   loads after, which is what retail does. Two sites in func_800727C0, 104
   differences to 41 on that one flip, and it is the same rule as the two
   loads above read for a much larger effect.
   **And a hardware address written inline gets its field offset folded into
   the constant.** `((u8 *)0x1F8002A0)[3]` becomes a `lui`/`ori` of
   0x1F8002A3, and a block with six fields becomes six constants -- nine
   instructions of overhead on func_8002A9C0. A base local per block, used
   with displacements, is the fix; but keep the *call arguments* as literals,
   because retail materialises the same address twice when the source names
   it once and passes it once.

   **A local holding an address expression can cost a delay-slot fill, by
   making a `%hi`/`%lo` pair indivisible in practice.** func_80038EB0 reads a
   byte twice through `p + p[0x58] * 4`; with a `u8 **c` local for that
   address, cc1psx emits `lui`/`addiu %lo(D_800EB010)` *after* the address
   computation and the `lb`'s own load-delay slot takes a `nop`. Written
   inline at both sites -- `e = *(u8 **)(p + p[0x58] * 4);` and
   `*(u8 **)(p + p[0x58] * 4) = e + 1;` -- the scheduler straddles the pair
   across the `lb`, `addiu %lo` fills the slot, and the `nop` is gone. Same
   two instructions either way; only the freedom to separate them changes.
   **Observed once.** The reason it matters more than one instruction: it took
   the function from +1 to exact length, and the +1 reading had *fewer*
   differences (134) than the correct one (149), which is the
   never-compare-across-length-errors trap in its purest form.
   **A giv init that retail emits AFTER the cursor's init, with the counter
   kept, is a per-iteration TEMPORARY derived from the counter -- and the
   base of the index form must be an INTEGER so the counter survives.**
   func_8002BFCC's second loop walks two things off one counter `n` (from
   1): a record cursor with stores at +0x54/+0x56, and a word table read at
   `(n-1)*4`. Retail's preheader is the hoisted constants, then `$a0 = r +
   4`, then `$a1 = 0`, and the loop keeps `slti $s3,0x2D3` on `n`. Three
   spellings each get one third of it. An explicit `off = 0; ... off += 4;`
   biv is a source statement and no placement of it (before the stores,
   after them, in a `for` clause, pinned) moves its `addu $a1,$zero,$zero`
   below the giv init -- the scheduler puts a source statement first (9
   differences, six placements identical). `D_801D4244[n - 1]` makes `off`
   gcc's own giv and lands the init where retail has it, but the array
   symbol gives the load a known base and gcc hoists it above the `sh
   $zero,0x54($s5)` that precedes it. `*(s32 *)((u8 *)D_801D4244 + (n - 1)
   * 4)` folds the -4 into the symbol and reduces the whole address into one
   register (-3). What matches is `off = n * 4 - 4;` as a statement inside
   the loop, read through `(u8 *)D_801D4244 + off`: `off` is a DEST_REG giv
   (init emitted at loop start, after the cursor's), the sum is a pseudo of
   two registers whose base gcc cannot name, so the store stays first --
   and `(n - 1) * 4` / `(n - 1) << 2` for the same value are 268 (-1), so
   the spelling of the subtraction is load-bearing too. The other half:
   the cursor written `*(s16 *)(r + n * 4 + 0x54)` against the `u8 *r`
   eliminates the counter (retail's `slti` becomes a giv compare against
   `r + 0xB4C`), because a giv whose add_val is a POINTER-flagged register
   is allowed to replace the biv's exit test; against `rb = (s32)r` the same
   giv is not eligible, `n` survives, and the cursor comes out unbiased
   (`addiu $a0,$s5,4` with 0x54/0x56 displacements), where an explicit `e
   += 4` cursor with the same uses is biased to +0x54 (`addiu $a0,$s5,88`).
   The third loop wants the same index form through the plain `r`, since
   its counter is a call argument and cannot be eliminated anyway. And the
   `switch` on the field is a comparison TREE with four cases (gcc 2.8's
   table threshold is five on this target), whose 0x14/0x17 arm is one
   shared arm -- that is why 0x170 is hoisted into `$a2` and the other
   three constants are not.
   **A pointer that walks up while the counter walks down is a real `*q++`.**
   gcc reverses the counter after strength reduction has left it live only in
   the exit test, so the address giv keeps going forward: no index expression
   reproduces it in either direction, and an explicit cursor does
   (func_800533D8, 55 differences to 10).
   **A modulo whose only use is a byte store must be written INLINE, not
through a local.** `c = *(s8 *)(e + 0x18) % 5 + 0xB; D_800EAE88[0] = c;`
makes gcc compute the modulo in QImode -- the local's only use is the byte
store, so it narrows -- and re-narrow with a second `sll 24`/`sra 24` pair
after the `subu`. Written inline in the store it stays SImode and matches.
Two instances in func_80027508, +5 to +1. This is the func_80027060 rule
about a narrow local read from the other end: there a redundant cast was a
pseudo that should not exist, here a redundant LOCAL is.

**And the abs inside a division wants the TERNARY, not the `if`.**
`v = (d < 0 ? -d : d) / 24 + 1;` and `v = d; if (d < 0) v = -v; v = v / 24 +
1;` compute the same thing, and gcc schedules the reciprocal constant
differently: with the `if` it emits the `lui`/`ori` pair after the
subtraction and leaves a `nop` in the preceding load's delay slot, with the
ternary it straddles the two loads the way retail does. func_8002BAB4, +1
and 106 differences to exact length and 31.

**A named read is how you let two independent DIVIDE chains interleave, and
the second name's POSITION is the lever rather than the naming.**
func_80026DC8's hit blocks each do two or three signed `% 5` reciprocal
expansions on bytes read from different records. Written inline, gcc finishes
one chain before starting the next and leaves a `nop` in the second `lbu`'s
delay slot. `u = *(s8 *)(f + 0x18);` at the top of the block and
`w = *(s8 *)(e + 0x18);` **after the store that consumes `u`** is +1 and 114
differences to exact length and 25; both names at the top is 67. And the
identical edit on the sibling block in the same function is worse (42 and
57), because retail really does leave the `nop` there -- the third instance
of one idiom wanting opposite spellings in one function.
**Then the store ORDER inside such a block is worth permuting**: the last 25
were two moves, `[0]` written before `[1]` in one block and `[6]` written
before `[7]`/`[8]` in the other, and the second was a first-try MATCH. The
permuter found the first; the second is the same idea applied by hand.

**Where an independent store lands is decided by what precedes it.** A store
   written *after* a multiply gets scheduled into the `mult`→`mflo` latency;
   written before, it stays before. That is the whole of func_80044DC0's last
   three differences: `sp10[3] = 0;` after `sp10[0] = …` rather than before, and
   the two arms of the `if` both writing index 1 first.
   **The general form, and it decides a `%hi` pair as well as a schedule:
   in a run of stores to ONE symbol, the store whose value starts a MULTIPLY
   goes FIRST.** func_800279BC writes `D_800EAE88[9]`, `[0xA]` and `[0xB]` in
   one arm, where `[9]` is a `% 5` reciprocal expansion. With the two constant
   stores written first, gcc materialises a SECOND `%hi(D_800EAE88)` pair --
   the census carries `lui +1` and the whole arm reads as an addressing
   problem. With the modulo first, one pair covers all three and the constant
   stores fall into the `mult` latency exactly where retail schedules them:
   161 differences to 143, and the census from three opcodes to one.
   **Then permute the position of the remaining constant store among the
   others**, which is a second lever and a bigger one -- moving
   `[0xB] = 0;` after `[0xA]` was 57 to 30 in one arm and 30 to 14 in
   another. That move had been measured on an EARLIER base as 185 against
   180, i.e. clearly worse, and was correctly rejected then; five levers
   later it is clearly better. It is the sharpest instance yet of the rule
   that a spelling rejected while another fault was open has not been
   measured at all.

   **An increment written BEFORE a call is sunk into the call's delay slot,
   and the cost lands on the NEXT branch.** In func_800279BC's search loop
   `pb++;` sits above `if (func_80019A08(...) != 0) goto hit;`; gcc puts the
   `addiu` in the `jal`'s slot, and the delay-slot filler then has nothing
   left for the following `bne`, so it takes the *target block's* first
   instruction instead -- here a `lui` of the `% 5` reciprocal, which reads
   in the diff as a constant hoisted into the loop as an invariant. It is
   not: retail leaves the `jal`'s slot a `nop` and fills the `bne`'s with
   the increment. Writing `pb++;` after the call is 180 differences to 67,
   and `*(++pb)` and `pb = pb + 1;` are identical to it. **The tell is a
   constant belonging to a block AFTER the loop appearing INSIDE it** --
   look at what filled the delay slot before it, not at the constant.
5. **Which test is written first**, when the target has more exit blocks than
   you produce. `if (x == 0) return 0;` then the body, versus the body under
   `if (x != 0)` with `return 0` after it, are *different layouts*: the first
   keeps both exits, the second gets cross-jumped into one with the value in a
   delay slot. Rule of thumb: whichever condition the target **branches out on**
   is the one to write first. Confirmed on `func_80033500` and `func_800440B4`.
   **A branch immediately in front of a counted loop is usually the loop's
   own entry guard, not a test the source wrote.** Writing both — `if (n !=
   0) { for (i = 0; i < p[K]; i++) … }` — emits *two* branches even when gcc
   knows `p[K] == n` from the store above, because `n != 0` and `0 < p[K]`
   are still different expressions and it tests each. One instruction too
   many, and the shortfall cascades (func_80072DC0, 58 differences to a
   match on deleting the `if`). The tell is what the single branch tests:
   retail masks the call's return with `andi 0xFF` and branches once, which
   is a guard comparing zero against the *byte field* just written, not
   against the word the call returned. Count the branches in front of the
   loop before inventing a guard for it.
   **A switch that retail compiles to a comparison tree and you compile to a
   jump table wants a CASE RANGE that shares the default label.** gcc 2.8
   takes the table when `count >= 4` and `range <= 10 * count`, so the way to
   push it back to a tree is to widen `range` -- and the way to widen it
   without changing behaviour is `case LO ... HI:` written immediately above
   `default:`, for values that already reach default. Read the bounds off the
   listing: retail's tree for func_8004BE88 opens with `bltz $a1` and
   `slti $a1,0x10`, which are the lower-bound tests for a case node at 0
   spanning to 0xF, so the source is `case 0 ... 0xF:` and the switch's range
   is 89 rather than 42. That one line took the dispatcher from
   instruction-for-instruction wrong to byte-for-byte right (127 differences
   to 86). The GNU case-range syntax is gcc 2.8's own, and in that function it
   is also what the code means -- it is a MIDI meta-event dispatcher and
   0x00..0x0F is the text-event range.
   **The case order also decides the arm ORDER IN MEMORY, and the target's
   order is worth reading off the listing rather than guessed.**
   func_8005FC1C dispatches on twelve values and retail's arms are laid out
   9, 0x209, 0x11, 0x211, 0xD, 0x20D, 0x15, 0x215 -- an interleaving of two
   0x200-apart ranges, not a sort. The arm addresses are in the listing next
   to their `%lo(func_...)`, so the order is free to recover: grep the arm
   labels in address order and write the cases that way. 30 differences to
   27, and every label then lands where retail's does.

   **A comparison TREE whose pivot sits one node too low means the source
   has a case you have not written -- and that case's VALUE is
   unrecoverable.** gcc builds a binary search tree for a sparse `switch` and
   `balance_case_nodes` picks the pivot from the number of nodes in the
   sub-list, so a missing case shifts the pivot and every comparison after
   it. func_8004B49C dispatches on nine values and retail pivots its upper
   group at 0x62 where we pivoted at 0x5B; the instruction *count* is the
   same either way, which is why it does not read as a missing case. Adding a
   tenth empty case is a MATCH -- and **every value from 0x7F up gives
   byte-identical code**, because gcc emits no test at all for the largest
   leaf once both bounds are established by its ancestors, and an empty arm
   is the default's code anyway. (0x64 is not free: the range then fits gcc's
   `count >= 4 && range <= 10*count` jump-table rule and the whole switch
   changes shape.) So read the *pivot*, not the count: if the target tests a
   different case value at the same position, add a case rather than
   re-reading the arms, and write down that its value is a guess.
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
   **A block the target places between an early `return` and the rest of the
   function is a `goto` target written INSIDE the returning branch.**
   func_8002538C's `D_8009B220 = 0; return;` is the exit of a loop forty
   instructions later, and retail emits it immediately after the *other*
   arm's `return` -- before the second half even begins. Written where it
   runs, gcc puts it at the end of the loop and everything between shifts by
   three instructions. Written as `goto done;` with `done:` labelled inside
   the first branch, after that branch's own `return`, gcc emits it exactly
   where retail does: 33 differences to 9. A label inside a block reached by
   a `goto` from outside it is legal C and is the only spelling that moves
   the block. Same family as the out-of-line-arm rules below, but the block
   belongs to a *different* branch of the function entirely.
   **A three-way dispatcher with out-of-line arms is `goto`, and the
   instruction count says so before you guess.** func_8003C328 tests one
   parameter against 1, then <2, then 0, then 2, and the arms sit after the
   dispatcher in address order. Written as nested `if`s with the bodies
   inline it is -6, and the six missing instructions are exactly the jumps a
   fall-through layout cannot emit: two `j epilogue`/`nop` pairs in the
   dispatcher, plus one terminal jump from each arm that does not fall into
   the shared tail. Flipping the polarity does nothing -- gcc canonicalises
   both spellings, and two attempts that differ only in `!=` versus `==`
   scoring identically is the tell that you are on the wrong axis entirely.
   Lay the arms out as `goto` targets in retail's own address order, with an
   explicit `goto tail;` on any arm that must reach the shared tail rather
   than fall into its neighbour: 83 differences to 60, and the length
   error from -6 to -2. Same lever as func_8003B378's single out-of-line
   arm, one level up.
   **And the mirror: a `return X;` after each inner switch emits a RETURN
   BLOCK that retail shares.** Two nested-switch dispatchers, func_8005FE44
   and func_8005FC1C, map an id to one of a dozen function addresses; with
   `return arg0;` written after each inner `switch` gcc emits a second
   `jr $ra` / `addu $v0,$a0,$zero` pair, and `break;` in each arm with ONE
   `return arg0;` after the outer switch is a MATCH for both. func_8005FC1C
   had been parked since 2026-08-28 at +2 with exactly that residue written
   in its entry, and the fix took one substitution once its sibling was
   written. So: when a dispatcher is +2 and the extra pair is an epilogue,
   count the `return`s before reading anything else -- and note that a grep
   of PARKED.txt for other shared-return residues found none in this class,
   so it is a two-instance lever, not a sweep.
   **A switch whose arms share a tail may want that tail written out per
   arm, not once after the switch.** func_8004C5C8 has six arms that all end
   `field18 = field1C & mask; field1C >>= shift;` with three different
   (mask, shift) pairs, and retail keeps a full copy of the load/mask/shift
   sequence in every arm, sharing only the two stores and the `jr`. Hoisting
   the pair into `a`/`b` locals assigned in each arm and stored once after
   the `switch` lets gcc cross-jump the three arms that share a (mask,
   shift) all the way back, which is six instructions short and two join
   labels instead of one. Written inline in each arm it is a first-try
   MATCH. So when a switch's arms look repetitive, count the target's copies
   before factoring them out.
   **And when two arms genuinely DO share one copy, which arm holds it is
   decided by a `goto` into the other's block.** func_80044608 has two such
   pairs. Written out in both arms, gcc keeps the LATER copy and jumps to it
   from the earlier arm; retail keeps the EARLIER one. Labelling the earlier
   block and writing `goto shared;` in the later arm puts it where retail
   has it -- +3 and 74 differences to 140/140 and 38. **It does not always
   work**: the same edit on that function's other pair is -1, because retail
   reaches that copy with a `bgtz` whose delay slot holds a duplicated `lui`
   of the call's argument, and an explicit `goto` gives a plain branch with
   nothing to duplicate. So the lever is for a shared tail whose entry does
   not need the target's first instruction copied into a delay slot.
   **COUNT THE STACK-ARGUMENT STORES AGAINST THE `jal`s. That one grep decides
   whether a shared `goto join` call is right, and it costs nothing.** A call
   with five or more arguments stores the fifth at `0x10($sp)`, once per
   textual call site -- so `grep -cE 'sw +\$[a-z0-9]+, 0x10\(\$sp\)'` counts
   SOURCE call sites while `grep -c 'jal +<callee>'` counts what survived
   cross-jumping. func_80016784 has TEN against NINE: two textual calls were
   merged into one `jal`, and the shared `join:` we had written cannot
   produce that, because a label in C puts every argument store *after* it
   and retail's `.L80016C64` sits ON the `jal` with the other arm's
   `sw $s3,0x10($sp)` before its own `j`. Writing both calls inline and
   deleting the join variable was 242 differences to 150, the largest single
   step in that function. Equal counts mean the call really is shared. This
   is the same family as func_80030998 and func_80052694 -- a call written in
   both arms with only the tail cross-jumped -- but here the evidence is a
   number rather than a reading, so check it *first* on any callee with more
   than four arguments.
   It also settles the copy that usually gets chased instead: retail's
   `addu $a0,$fp,$zero` before a run of stores through `$a0` is the call's own
   argument setup scheduled early, and the stores follow it because
   post-reload CSE rewrites a base to an equivalent hard register. No
   source-level copy produces it -- four spellings of `pk = z` (before the
   stores, after them, with three, five or nine routed through it) came out
   BYTE-IDENTICAL, which is what a closed axis looks like.

      **A call whose ARGUMENT SETUP is duplicated into both arms of an `if`,
   with only the tail shared, is a call written in BOTH arms.** func_80030998
   picks one of two tables and calls func_80030250 with seven arguments;
   retail sets `$a1`, `$a2`, `$a3` and the first stack slot separately in each
   arm -- identical instructions, duplicated -- and shares only the last two
   stack stores, one global store and the `jal`. Written once after the join
   gcc emits the constant arguments once and the function is -4. Written in
   both arms, gcc's cross-jump walks back from the `jal` and stops exactly
   where the arms first differ (the second stack slot, 3 against 2), which
   reproduces retail instruction for instruction. Same family as
   func_80052694, read from the other side: there a vanishing constant local
   said a call site should have been two copies, here the duplicated argument
   setup says it.

**And a constant argument held in a callee-saved register is the same
   question read backwards.** func_80052694 keeps 0 in `$s3` across two calls
   and passes a literal 0 to two others. Written as `z = 0;` with one textual
   call site the local is constant-propagated away, all four sites become
   identical, gcc cross-jumps them into one and the function is *eleven*
   instructions short. Writing the call out in both arms of the inner `if`
   gives the two sites their own argument setup, `z` then has somewhere to
   live, and the length comes right -- 124 differences and -11 to 13 and 0.
   So when a local holding a constant vanishes, the question is not how to
   make gcc keep it; it is which call site was supposed to be a second copy.
   **Which of several identical arms gets merged is decided by the block that
   PHYSICALLY PRECEDES THE LABEL, and that is the mechanism behind the
   "permute the case order" rule above.** gcc 2.8's `find_cross_jump`
   compares the insns before a jump against the insns before the jump's
   LABEL -- not against every other block that reaches it -- so an arm merges
   only with whichever block happens to sit immediately above the join.
   func_800229F4 has two `if (flag)` finish blocks whose four arms all end
   `sw` + jump-to-join; retail merges the two ELSE arms (the second one is
   the block above the join) and leaves the two THEN arms with their own
   copies, which no amount of reordering *inside* an arm reaches. The lever
   is a local: with one name assigned in both arms of each `if` and the store
   after them, all four arms end identically and gcc merges the then-arms too
   -- three instructions short. Writing the store directly in each arm keeps
   retail's layout. So when a length error is a small negative and the missing
   instructions are a duplicated store-and-jump, look for a local that made
   two arms identical, and delete it.
   **A store retail keeps and you lose is a DEAD-STORE elimination, and the
   fix is another store between the two.** `m[i] = m[i] + q[i]; m[i] = m[i]
   / 2;` reads as two statements and two stores, and it is one: gcc forwards
   the first store into the second read and then drops it, because nothing
   reads the slot in between. That the array's address ESCAPES to a later
   call does not save it -- the escape is after both stores, so the
   elimination is legal and gcc takes it. No name, cast or `volatile` on the
   local changes this. What does is separating the two groups so another
   store sits between them: on func_8006BCA4's three midpoints, writing all
   three sums and then all three divides keeps both stores per component and
   is a MATCH, where per-component pairs are three instructions short. The
   scheduler then interleaves them back into retail's own order (sum0, sum1,
   div0, sum2, div1, div2), which is why the emitted code looks like the
   per-component spelling and is not.
   **And the same local decides whether a following read is FORWARDED.**
   gcc 2.8 has no global CSE, so a load is forwarded from a store only inside
   one basic block. A store written at the join is already in the join block
   when CSE runs, and the read after it is folded into the stored value; a
   store written inside each arm is still in the arm's own block, and only
   cross-jumping -- a much later pass -- moves it down, so the read stays a
   real reload. Two arms of func_800229F4 want the reload and two want the
   forward, in the same function, and the tell is whether the target has an
   `lhu` of the address it has just stored.
   **A sum of two `lhu` shifted right is UNSIGNED in the source.** Both
   operands promote to `int`, so the natural `s32` gives `sra`; retail's
   `srl` needs the value to be `u32`. An `(u32)` cast at the use is not the
   same thing and was measured worse -- the declaration is the lever.
   **And a negative constant stored to a halfword wants an `s16` lvalue.**
   `*(u16 *)(p + K) = -0x3F80;` is the HImode constant 0xC080 and gcc
   materialises it `ori $v0,$zero,49280`; `*(s16 *)(p + K) = -0x3F80;` is
   const_int -16256 and gives retail's `addiu $v0,$zero,-16256`. The same
   sixteen bits are stored either way, so nothing but the instruction says
   which the source had.
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
   **The same rule catches a *computation* that should have been folded
   away.** Retail sign-extends a halfword countdown into `$a3` and then
   branches on it, where gcc drops the `sra` entirely: after `sll 16` the
   value's sign and zeroness are already what `bgtz` wants, so `(s16)x > 0`
   needs no extension and the instruction has nowhere to come from. It comes
   from the value *also* being the next call's fourth argument, which is what
   `$a3` says. So when your build is one instruction short and the missing one
   computes something the branch does not need, read the register it writes as
   an argument number and check the callee's real parameter count —
   func_80043230 takes four and the call site appeared to set three, because
   the fourth was already in place (func_8003D614, one difference to a match).
   This is the missing-prototype tell read backwards: there a caller passes
   too few arguments because it never saw the declaration, here it passes all
   of them and the listing hides one.
   **A GROUP of loads batched before a group of stores has to come from the
   source, and it is the general form of the rule below.** gcc cannot hoist a
   load through one `u8 *` above a store through another, so where retail
   issues four or five `lw` and *then* the stores that consume them, the
   source read them into named locals first. func_80040DD8 has two instances
   in one function: `w0..w3` before a four-store group took it 170/164 and 121
   differences to 165/164 and 109, and `x0`/`x1` in a later arm took it to
   164/164 by removing two load-delay `nop`s. The partner rule is that where
   the group is *followed* by a test, the tested value wants naming too --
   `fl = *(u16 *)(e + 8);` written before the last store lets that store sink
   into the test's branch delay slot, which is another 104 differences to 56.
   The tell for both is a `nop` in a load delay slot next to a store that
   retail has in a branch delay slot. Same mechanism as func_800400AC below,
   one level up: there it is one read that has to exist as a statement, here
   it is a whole group.
   **A single named read fixes the mirror case, and it transfers across
   siblings.** Where retail loads a global *before* a store that the source
   writes first -- `lui`/`lw D_8009B118` ahead of `sh 0x10,6($s0)`, so the
   load covers its own delay slot -- writing `d = D_8009B118;` above that
   store is the whole fix. func_800434F4 went 91/90 and 62 differences to
   90/90 and 42 on that one line, and the same line is worth 62 -> 37 on
   func_80020BE4 and 82 -> 77 on func_8003B808, which are the same body
   compiled into three functions. **Do not share the name across two switch
   arms**: one `d` for cases 0 and 1 of func_8003B808 is +6 and 85.
   **A cursor copy written as the loop body's FIRST statement is rotated into
   both the preheader and the back edge's delay slot.** Retail's
   `addu $a0,$s1,$zero` appears twice -- once before the loop and once in the
   `bnez`'s own delay slot -- which reads like two source statements and is
   one: `for (i = 0; i < n; i++) { p = q; q += 0x28; f(p); }`. Writing the
   copy before the loop *and* at the end of the body instead gives the
   preheader copy in the wrong place (func_8005F91C, 5 differences to a
   MATCH); the explicit-guard `do`/`while` spelling of the same loop is 7.
   So when a copy appears both in a preheader and in a delay slot, write it
   once, at the top of the body, and let gcc's rotation make the two.
   **Two independent chains interleave only if the source order lets them,
   and a name is how you give the scheduler both.** A counter's read-add-write
   on a global and a load from a record address just computed are independent,
   so retail issues *both loads*, then both computations, then the store,
   filling the second load's delay slot with the first chain's `addiu`. Write
   the second read inline in the `if` that tests it and gcc finishes the whole
   counter chain before the record address even exists — the two never overlap,
   the delay slot gets a `nop`, and the function is one instruction long and 86
   differences out. `f = *(u16 *)(r + 8);` above the increment is the entire
   fix (func_800400AC, 86 to a match). The tell is a `nop` in a load delay slot
   where the target has an instruction belonging to a *different* computation:
   that is not a missing name in the usual sense, it is a read that has to
   *exist as a statement* before the other chain starts.
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
   **A constant argument cannot be hoisted by naming it — name something
   else in the block instead.** func_80025F3C's whole 16-difference residue
   was retail materialising `addiu $a0,$zero,0x23`, the argument to the call
   that *ends* the first block, fifteen instructions earlier at the top of
   it, and holding it in $a0 throughout — which pushes the address load and
   both store constants into $a1. A local for the argument does nothing at
   either position: gcc constant-propagates it back to the call. What moves
   it is naming an unrelated *read* in the same block — `d = D_8009B1D5;`
   assigned in front of the store before the call, where the source had the
   symbol inline twice. One line, and every register in the block falls into
   place. The permuter found it paired with a dead `q = p;` copy that turns
   out to be unnecessary and costs 7 on its own, so **decompose a permuter
   win before installing it**: half of this one was the whole answer.
   **Second instance, and it is a delay slot rather than an argument.**
   func_8003C328 builds a mask constant whole inside a dispatcher arm where
   retail puts the constant's `lui` half in the branch's own delay slot and
   completes it with `ori` at the top of the arm -- the filler can only take
   that `lui` if it is the arm's first instruction, and it is only first if
   the constant is materialised before the arm's stores. Naming the constant
   does nothing, for the reason above. Naming an unrelated *read* in the same
   arm -- `t = D_8009B0F4[0];` where the source had the symbol inline -- moves
   it: 60 differences to 57, and to 49 once the name sits *after* the arm's
   first store rather than before it. Where the borrowed name is assigned is
   as much of the lever as the name. It does **not** generalise to the
   sibling func_8003C120, whose arm stores in a different order: there the
   same edit is worth nothing at all.
   **Hoist a call's arguments into locals when the target evaluates them
   early.** Where retail sets up `$a0` and loads `$a1` *before* the stores that
   precede the call, assigning both to locals at the top of the block
   reproduces it: func_800289BC, 53 differences to 13. It works only for the
   values that cross the call — naming the field reads as well made it 36 —
   except where the target issues one read before the base pointer's own load,
   which needs its own local to get there (the last 13).
   **A constant mask used in several switch arms wants a NAME, and that is an
   allocation lever rather than a CSE one.** Three sibling dispatchers all
   `and` a global against `0xFFDCFFFF`; written inline the constant lands in a
   temp register and every store around it rotates, and a local -- `m =
   0xFFDCFFFF;` then `v = D_8009B0F4; v &= m;` -- puts it in the argument
   register retail uses. func_80043328 went 38 differences to 18 on that one
   line, func_8003BF00 95 to 90. One name for all the arms, not one per arm:
   five separate names is *worse* (92 against 90), because the point is a
   single long-lived pseudo, not five short ones.
   **And the borrowed-name lever scales to whole switch arms.** In an arm that
   can never run at the same time as the arms feeding a shared tail, borrow the
   tail's own variables rather than inventing new ones: func_80043328's
   `mode == 0` arm reads D_8009B118 into `q` (the tail's pointer, 18 to 13)
   and materialises 0x18000 into `b` (the name the other two arms use for
   their reads, 13 to 12). Fresh names at the same positions are worth
   nothing, and *separate* names per arm are worse (40) -- the mutual
   exclusion is the whole mechanism, and it is the func_8002596C rule read one
   level up.
   **A second name for the record pointer is what makes a parameter copy
   survive -- when the dispatch frees the argument registers.** Where retail
   holds the pointer in `$a2` and copies it into `$a0` for a call, while gcc
   keeps it in `$a0` and needs no copy, write `e = p;` at the top, every store
   through `e`, and the *call* through `p`: func_8003BF00, 90 differences to
   62. Routing the call through `e` as well coalesces the copy away and it is
   90 again, so the split use is the lever. **It does not always fire**:
   func_8002DDFC has the same residue and the same shape but an `if`-chain
   dispatch rather than a jump table, so `mode` stays live in `$a1` throughout
   and copy propagation folds `e` back into `p`. The discriminator is whether
   the dispatch frees an argument register early.

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
   **A large constant a loop compares against is not hoisted by gcc's loop
   pass, and where you assign it decides where the `lui`/`ori` land.**
   func_80060220 compares a field against `0x2000001` inside a `do`/`while`;
   retail materialises the pair into `$t6` in the *prologue*, ahead of even
   the `i = 0`, and gcc emits it inside the loop head from every inline
   spelling. A local for the constant is not enough on its own -- assigned
   just before the loop it is still emitted in the loop head -- but assigned
   as the function's **first statement** it comes out exactly where retail
   has it. 113 differences to 4 on moving one line up two statements. The
   tell is a `lui`/`ori` pair in your loop where the target has the constant
   already live in a callee-clobbered register on entry.
   **And a constant term must not be allowed to fold into a loop-invariant
   sum.** `*(u16 *)p - 0x280 + sh`, with `sh` invariant, is reassociated to
   `x + (sh - 0x280)` and gcc hoists that sum into the preheader; retail
   recomputes `addiu -0x280` / `addu sh` at each of the two sites. Naming the
   loaded value first and grouping the subtraction with it -- `w = *(u16 *)p;`
   then `(w - 0x280) + sh` -- blocks it, and the *two sites want two different
   names*: one `v` shared between them was the last two differences
   (func_80060220). Same family as the `(x & 0x100) != 0` fold and the scaled
   dividend: one name across two statements is the knob, and two unrelated
   values must not share one.
   **An explicit guard plus `do`/`while` is how you give the loop body its own
   copy of a pointer.** Where retail reads the loop bound through one register
   before the guard and through *another* inside the body -- with an
   `addu $a2,$t0,$zero` sitting in the guard's own delay slot -- a plain
   `for` cannot reproduce it, because gcc's rotation emits one expression for
   both tests. Writing `if (*(s16 *)(q + 6) > 0) { rec = q; do { … } while (j
   < *(s16 *)(rec + 6)); }` gives retail's copy and its delay-slot position.
   On func_80060220 that also made `-fno-schedule-insns` **unnecessary**: the
   flag had reproduced the same three instructions (two load-delay `nop`s the
   default scheduler was filling from the other load), and once the source
   shape was right the default flags gave them too. A flag that buys back
   exactly the instructions a missing name would have bought is a warning to
   look for the name first.


   **An explicit byte-offset cursor is usually gcc's giv, not a source
   variable, and writing it by hand is expensive.** func_800727C0's listing
   keeps `$fp` = D_801AB000 and `$s6` starting at 0x84 and stepping 0xC,
   added together at each use -- which reads as two source variables and is
   one index expression: `D_801AB000[i + 0xB].unk0`, where the record is 12
   bytes and 0x84 is 11 * 12. Writing the cursor and the base as locals is
   104 differences; writing the index form is 16, and the whole difference is
   that gcc's strength reduction places the giv's initialisation AFTER the
   source's own preheader statements while a hand-written cursor lands among
   them. The tell is a base-plus-offset pair whose offset's initial value is
   a multiple of the record size.
   **Two reads of one record at different offsets want a base local and the
   index form, not a cursor.** func_80071CB0's second scan reads `+6` and
   `+2` of the same 0xC-byte record. Against the symbol, gcc hoists
   `sym + 6` out of the loop as an invariant (+4 instructions); as an
   explicit cursor stepping 0xC it gives the cursor a *bias* of +2 (+1); as
   `e = sym;` before the loop with `e + i * 0xC + 6` and `+ 2` inside, it is
   retail's single cursor with two plain displacements. All three spellings
   are the same C; only the third reproduces the target.

   **CLOSED 2026-09-05: an invariant that retail leaves INSIDE a call-bearing
   loop, and gcc hoists into a callee-saved register, is a loop written with
   `goto`.** gcc 2.8's loop pass runs only between the NOTE_INSN_LOOP_BEG /
   LOOP_END notes the front end emits for `for`, `while` and `do`; a loop
   made of a label and a conditional `goto` back to it has no notes, so no
   invariant motion and no strength reduction happen on it at all. Two
   functions, same shape, same fix, same day: func_8004B374 (retail masks
   `arg1` with `andi` every iteration in a delay slot; gcc hoisted it into
   `$s4`, 21 differences, all downstream of that) and func_8004A518 (retail
   materialises the literal 0x63 per iteration; gcc hoisted it into `$s6`,
   a seventh callee-saved register and +2). Rewritten as
   `top: ...body...; if (++i < n) goto top;` both are exact length at once
   and the residue is register names only (29 and 51, then 11 and 11 on
   ordinary naming levers). Measured and dead before that on both: a `u8` or
   `s32` local for the value inside or before the loop, a `u8` parameter, a
   `do { } while (0);` pin, the literal instead of a name, both scheduler
   flags, and `while (1)` with a `break` -- which still carries the notes and
   is still +2. So: **when retail keeps an obviously invariant instruction
   inside a loop that also contains calls, the source's loop was a `goto`**,
   and the same spelling is what WORKFLOW's "unrotated `while`" rule above
   already reaches for a different reason. The cost to know is one variant.
   **And the bound, measured the same hour: it is for a loop where retail
   hoists NOTHING.** func_8007214C's park says "gcc hoists three loop
   invariants that retail keeps inside the loop", which reads like the same
   case and is not -- retail hoists the constants 1, 3 and 6 and a `%hi`
   into the preheader and keeps only the 8 and a `slti` inside, so its loop
   was a real loop and the `goto` form, which hoists nothing, is -7 there.
   What decides which invariants a real loop hoists is loop.c's cost test
   (`threshold * savings * lifetime >= insn_count`, with the threshold
   halved when the loop contains a call); which source spelling moves one
   constant across that line is not established. Read the preheader before
   reaching for the `goto`: some invariants hoisted means a real loop.

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
   **The same flag, third user, and a much plainer trigger: two reads at one
   constant offset inside a search loop.** func_800722CC reads `e->unk6`
   twice per iteration and gcc gives that offset its own biased giv, which
   costs a callee-saved register and five instructions -- 112 differences to
   37 on the flag alone. So it is not only the block-move shape: whenever a
   loop's cursor picks up a *second* register that is the first plus a
   constant, and retail has one cursor with plain displacements, reach for
   the flag.

**A plain copy also survives when the two names want different register
classes.** The rule below is that `e = o;` coalesces and only a *derived*
value produces a copy — true when both names live in the same place.
func_8007308C is the exception that shows the boundary: a base local used
once before a loop and then throughout it comes out as a single `addiu
$s3,$v0,%lo(sym)`, where retail has cc1psx's pair into `$v0` and then
`addu $s3,$v0,$zero`. Splitting it into two names — `a` for the pre-loop
store, `s = a;` for the loop — gives retail's copy and matched, because `a`
dies before the loop and gets a caller-saved register while `s` has to
survive it. Same value, same spelling, two live ranges, and the copy is the
class change. So before reaching for a derived offset, ask whether the copy
sits on a boundary where the register class changes.

**A parameter copy as the function's FIRST instruction means there is NO
local -- write the cast inline at every use.** The rule above is about making
a copy appear; this is the mirror, and it is the commoner mistake. Retail's
`addu $t1,$a0,$zero` sitting between the `addiu $sp` and the `sw $ra` is the
allocator giving the parameter's pseudo a `$t` register, and gcc emits it in
the prologue. Writing `p = (u8 *)arg0;` as a local does **not** reproduce it:
gcc coalesces the copy, then splits the live range itself and sinks the copy
into the entry guard's branch delay slot -- where retail has an unrelated
`lui`. Writing `(u8 *)arg0` inline at every reference gives retail's copy at
instruction two and frees the delay slot for the `lui`. func_8005CEF0, and
the tell is a copy you *do* produce but in the wrong place, which reads as a
scheduling problem and is a naming one.

**A dead assignment only works if gcc cannot prove it redundant, and that is
usually an offset.** Where the target has a plain copy of a pointer into a
caller-saved register and you have none, `e = o;` will not produce it --
gcc coalesces every source-level copy of a value into itself, and so do
`(u8 *)(s32)o`, `o + 0` and `&o[0]` (all measured, all identical).
`o = e + 8;` does: the store is dead, `o` is never read again, but the
address is *derived* rather than equal, so gcc allocates it, and allocating
it is the copy. Any non-zero offset works -- 4, 8, 0x18, 0x1A, 0x24 and
0x44 all give the same result -- and `+ 0` folds back to the plain copy.
**Where you put it decides where the copy lands**: at the top of the block
it is retail's position, at the bottom (inside the last expression, which
is where the permuter first found it) the copy is emitted after all the
stores instead. func_80031574, 24 differences to 14. This is the sharpest
form of the rule below.

**A comparison shared across a CALL takes a callee-saved register, and no
spelling of the same comparison breaks the sharing -- an ARITHMETIC on the
operand does.** func_80038EB0 tests `cmd >= 0x41` before and after a call;
gcc computes it once, keeps the result live across the call in a sixth
callee-saved register that retail does not have, and the extra `sw`/`lw` pair
shifts the whole prologue -- 147 differences, of which almost all were the
shift. Retail recomputes `slti $v0,$s3,0x41` after the call. `cmd > 0x40`,
`!(cmd < 0x41)` and `0x40 < cmd` are all canonicalised back to the same RTL
and score identically, which is the usual sign of a wrong axis and is
misleading here: the axis is right and the spelling is too weak.
`cmd + 1 >= 0x42`, `(cmd + 1) > 0x41` and `cmd - 1 >= 0x40` are 147 -> 37,
because the compared value is then a different expression and there is
nothing to share. All three are contrived and equally correct, so which one
goes in is a judgement call; the mechanism is the thing. **The tell is a
prologue that saves one more register than the target's, where the extra one
holds a comparison result rather than an address** -- the address version of
the same tell is the `%hi`-in-$s0 case above.

**gcc 2.8 lays stack locals out in DECLARATION order, so the frame is free.**
Locals go at increasing offsets starting just above the 16-byte outgoing-args
area, in the order they are declared. Read the `sp+NN` constants out of the
listing, declare the locals in that order with sizes that fit the gaps, and
the whole frame comes out right with no iteration -- func_800580D4 has seven
stack objects between `sp+0x10` and `sp+0xB8` and every one landed on the
first draft. Do this before anything else on a function with a big frame: it
is free, and getting it wrong makes every stack reference in the diff wrong at
once, which reads like a much larger problem.

**And when the target sets up a call's arguments BEFORE the stores that
precede it, the name goes at the TOP of the arm, not next to the call.**
func_8002FB78's case 2 materialises `D_8009B118` and copies `p` into `$a0`
ahead of all four halfword stores; `c = D_8009B118;` written after those
stores is worth nothing and written as the arm's FIRST statement is 22
differences to 15. Same lever in func_8003A01C, where the right position is
between two of the stores -- so read which store the load sits above and put
the assignment there.

**A store whose value the next statement also uses can be a chained
assignment.** Retail keeps `sw 8` and the `addiu 0x800` that feeds `sw 0xC`
adjacent, and every ordering of `t = D_8009B118; *(s32 *)(p + 8) = t;
*(s32 *)(p + 0xC) = t + 0x800;` -- all three permutations of the three
statements -- puts the `addiu` first. `t = (*(s32 *)(p + 8) = D_8009B118);`
does not: the store's own value becomes `t`, and the pair comes out in
retail's order. func_8002FB78, 15 differences to 9. The permuter found it;
it is ordinary C and reads as source.

**A call argument or a field read that the target loads EARLY wants a fresh
named local, and here the borrow rule runs backwards.** func_8003A01C's last
six differences were retail loading D_8009B118 and copying `p` into `$a0`
*between* two of the four stores that precede the call, where every inline
spelling emits them after all four. A local for the argument, written at that
point in the source, moves them -- and a **fresh** name is 6 while
**borrowing** the arm's own dead `t` is 17. The same again one line later for
the `p + 0x3C` read the arm's arithmetic consumes: a fresh `k` is the MATCH
and borrowing `n` (the name case 0 uses for the same field) is 17. Two
instances in one function, both in the same direction, against a rule that
usually says the opposite -- so when a borrow makes things much *worse*, try
the fresh name at the same position before concluding the axis is wrong.

**SWEEP the borrow candidates rather than guessing which one.** Which dead
name a value borrows is the whole lever, and the difference between two
candidates is not reasoned about -- it is measured. func_800220B8's step
constant borrowed `a` (the other arm's step) for 11 -> 9 and `v` (the first
block's value) for 9 -> **MATCH**; `y` is -7 and much worse. Three
substitutions in one command, using a word-boundary regex over the block's
text so the rename cannot leak. Do the same on func_8005BFC8-style residues:
five candidates were swept there too (`t` 26, `cnt` 26, `lim` +1, `cap` 24,
`t2` 18). Guessing one name and moving on is how these sat parked.

**But check the borrowed name's TYPE before crediting the borrow.** On
func_8002E128 an index written inline is 18 differences, with a fresh `s32`
name 19, borrowing the mutually exclusive arm's `s32` local 12 -- and with a
fresh **`s16`** name 8. The borrow was a partial proxy for a narrowing, not
the mechanism; the permuter then found the borrowed local declared `short`,
which is not installable there because the same name holds a pointer in the
other arm. When a borrow helps, try the same name narrowed, and try a fresh
name narrowed, before writing down which lever it was.
**Two initialisations to the same constant want ONE name holding it.**
Retail zeroes a loop counter's register and *copies* it into the offset's;
writing `off = 0; i = 0;` gives two independent zeroings, and so does the
other order, `i = off = 0;`, `off = i = 0;`, `off = i;` after `i = 0;`, a
declaration-order swap, a type change and three `do { } while (0);`
groupings -- twelve spellings, all 2 or 6 differences. `z = 0;` at the top of
the block with `off = z; i = z;` is a MATCH (func_8004BE88). Same family as
the one-name-for-two-sequential-constants rule in step 2, read for a constant
that is used twice at once rather than twice in sequence.
**A permuter's parenthesised embedded assignment is usually a CHAINED
assignment, and the chain's ORDER is load-bearing.** func_800243F4 sat parked
at 10 differences with a note saying six spellings of its halfword swap had
been measured and none moved it. The scorer found a complete MATCH sitting
unread in an output directory, and the whole edit was one line: the permuter
had written `t16 = (t8 = *(u16 *)(b16 + x * 2));`, where `t8` is the byte
swap's temp four lines later and is dead at that point. Written as ordinary C
it is `t16 = t8 = *(u16 *)(b16 + x * 2);` and that is also a MATCH -- but the
other order, `t8 = t16 = ...`, is 4. So when a permuter output wraps an
assignment in parentheses, rewrite it as a chain and measure BOTH orders;
one of them is the source and the other is not. Same family as the
"assigning to a local that is not yet live" hint, with a spelling anyone
would write.

**And that hint has a PLAUSIBLE spelling: assign the load inside the
condition that tests it.** func_80045C98's second clamp is
`if ((b = *(s16 *)(D_8009B45C + 0x1580)) >= D_8009B45C[0x1584])`, where `b`
is a call argument three blocks later and dead at that point. It is -1 and
63 differences to 169/169 and 9. **The exact parenthesisation is the
finding**: assigning the COMPARISON instead -- `b = (x >= y);` or
`if ((b = x >= y) != 0)` -- is 45. So when a permuter output contains an
embedded assignment, read which subexpression it wraps, and do not run its
diff through a paren-stripping normaliser.

**Assigning to a local that is not yet live is the same hint, and a fresh
name is not.** func_8002A4A8 sat at 14 through nine hand shapes. The
permuter's fix was to write `y = a;` in one arm of an `if` and take the
modulo of `y` — where `y` is the function's *second* result variable, whose
real assignment is forty instructions later. Semantically a no-op, and it is
7. A brand-new local in the same position is 14, so it is specifically
borrowing a name whose live range resumes downstream: that ties the temp's
pseudo to that variable's allocation. Applied a second time to the other
residue — `y = (…) << 16; x = y / n;` for a value retail runs through a
caller-saved temp — it went 7 to 3. Two instances in one function, and both
came from reading what the permuter changed rather than from the number.
**And the name you borrow can be one that is only live in a *mutually
exclusive* arm.** func_8002596C's call result has to land in `$s0` --
`addu $s0,$v0,$zero` right at the definition, which is step 2's tell for a
second name. A fresh local does not produce it: `x = call(); p = x;` coalesces
away at both placements tried, and the function is one instruction short.
Writing `q = call(); p = q;`, where `q` is the *other* branch's allocation
pointer and can never be live at the same time, gives retail's copy and
matched. The two live ranges do not overlap, so nothing forces them apart --
but they are one pseudo, and the pseudo is numbered before the branch, which
is the same mechanism as the two-arms-are-two-values rule read backwards.

**That lever and the `do { } while (0);` pin COMPOSE, and each is worth
about half.** func_80046294 carries `i` in `$t0` and `boff` in `$a3` where
retail has them the other way round; all six declaration orders of the three
loop variables score identically, which is the usual tell. `do { i = 0; }
while (0);` swaps the pair (12 differences to 6) and hoisting that same
pinned assignment ABOVE the function's entry guard is another one (6 to 5).
Neither alone reaches the other's result.

**And the mirror: assigning a loop variable its initial value BEFORE the
function's early-return guards fixes which callee-clobbered register it
gets.** func_8004D914 carries an outer counter and a record cursor that
retail keeps in `$t6` and `$t7`; every declaration order, both assignment
orders, and dropping either of the two parallel induction variables leave
them exchanged. Writing `o = 0;` -- a *third* variable, the byte offset --
as a statement above the first `if (… == 0) return;` is a MATCH, because it
numbers that pseudo before the guards and shifts the whole `$t` allocation
by one. The permuter found it as `if (… == (o = 0))`, which is the same
thing spelled where nobody would write it; the plain statement one line
earlier scores identically. Reach for it when a whole register *class* is
rotated and no ordering inside the loop moves it.
**And a THIRD zero pseudo is a tie-break of its own.** func_80049920 sat at
5 with `i` and `mask` holding $s3/$s4 exchanged -- both zeroed, one copied from
the other in the guard's delay slot, and no declaration order, `do { } while
(0);` pin or borrow moved which won $s3. `z = 0;` before the entry guard and
`if (*(s16 *)(base + 0x510) > z)` instead of `> 0` is a MATCH: the literal
becomes a pseudo numbered before the two counters and the allocator's
tie-break falls the other way. The permuter found it as an uninitialised
`new_var`, which is unusable as written; the initialised spelling scores
identically, and that is the general move for that reject class -- read what
the uninitialised name is *compared against* and give the constant a name.

**Two more instances the same hour, and it is now the first thing to try
when a residue is nothing but register names.** func_800727C0 sat at 16
differences that were entirely the prologue -- retail copies the parameter
into `$s7` before the symbol pair and puts `i = 0` in the guard's own delay
slot -- and moving `i = 0;` above `if (a[0x9C] == 0) return;` is a MATCH.
func_80056250 sat at 2 and matched on `i = sum;` moved above
`if (sum < p[0xE1B])`, which the permuter found in 1524 iterations. Both are
one line moved up one line, and in both cases every ordering INSIDE the loop
had already been measured and was worthless.

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

**The phase rule runs backwards too: a second loop's cursors may want the
FIRST loop's names.** The rule above says two sequential loop nests want
separate names. func_800339D0 is the counterexample that bounds it: retail
carries `$a0` through both of its loops for one role and `$v1` for the other,
so the second loop's record cursor wants the *same name* the first loop's
destination cursor used -- 11 differences to 3 on that one substitution --
while its other cursor needs a name of its own type. Reusing the first loop's
*source* name instead is 30. So the question is the same one as always: read
which registers the target carries across the boundary before choosing, and do
not assume that "two phases" always means "two names".
   Third instance, and the plainest: func_80071CB0 zeroes a stack array in a
   nested loop and then runs a search loop, and retail carries the zeroing
   loop's outer counter and the search loop's counter in the *same* register,
   resetting it to 0 between them. One variable for both is 20 differences to
   6 -- the largest single step in that function -- where two is the obvious
   spelling. Count the registers the target reuses across the boundary before
   deciding.

**A permuter win that depends on an UNINITIALISED read is a fourth class, and
it is worth decomposing even though you cannot install it.** On func_80046768
its two best outputs re-score at 5 and 7 against a base of 46, and both do the
same thing: read a local before it is assigned -- once as
`if (D_8009B45C || new_var)` wrapped round a loop body with identical arms,
once as a store through `new_var` one line before `new_var` is set. Neither is
installable. What they are worth is the *diagnosis*: the gain is entirely that
gcc then has one pseudo live at function entry, which is what shifts the whole
block-copy register assignment. Decomposing the plausible halves of the same
candidate -- hoisting a `(arg0 & 0xFF) != 0` into a local, narrowing another
local to `u16` -- was worth **exactly nothing**, alone or together, which is
what proves the uninitialised read is the whole lever rather than a passenger.
So: decompose these too, and write down the mechanism even when no legitimate
spelling of it has been found.

**And an unusable permuter output can still name a lever that beats its own
score -- twice in one session.** The rule above is about rejecting a bad
candidate; this is the other half. On func_80032370 the best output scored 7
against a base of 17 and is an uninitialised read: it deletes `r = t;`, walks
`r` while dereferencing `t`, and wraps the stale comparison as
`new_var = r != w;`. What it was *doing* is dropping the separate read cursor
and walking `t` itself, which is ordinary C and semantically identical because
`t` is dead after the loop. Written honestly that is **3**, not 7. On
func_8004A8E4 the best output scored 12 by making three edits at once, and
dropping the one that is worth nothing alone gives **11**. So the routine is:
score the outputs, read the diff of the best, and then write what it was
reaching for -- the permuter optimises a weighted diff and will happily reach
a mechanism by an illegal route, or carry a passenger to get there.

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
pass sees, not the block.
**And it is a scheduling lever in its own right, not only a partner.**
func_80052528's last two differences were which of `v - 0x10` and
`v + 0x10` lands in a reload's delay slot; all six orderings of the three
statements, both declaration orders and deriving one from the other emit
them the same wrong way round, and wrapping just the two assignments in
`do { … } while (0);` matched. Reach for it whenever a pair of adjacent
statements comes out in the wrong order and no permutation of them moves it
— and read it as a **macro** in the original, which is what that idiom is
for.
**Four matches in one hour on the same two `do { } while (0);` placements,
and they are worth naming separately.** The D_8009B0F4 dispatcher family
writes the same block over and over, and its last two residues are always
one of these:
  * **round a lone `*(s16 *)(p + 0x30) = 0;` between a named constant and the
    store that consumes it.** Retail emits `lw D_8009B0F4` / `addiu 0x40` /
    `sh $zero,0x30` / `sh $v1,4`; every ordering of the three source
    statements puts the zero store first or last, and `f = 0x40;` plus
    `do { *(s16 *)(p + 0x30) = 0; } while (0);` plus `*(s16 *)(p + 4) = f;`
    reproduces it. func_80020BE4 (4 -> MATCH), func_800434F4, func_8005B64C
    (2 -> MATCH). **The mask assignment has to be the arm's FIRST statement
    for it to fire**: the identical shape with `m = 0xFFDDFFFF;` written last
    is 13.
  * **round a lone constant that must be materialised into the branch delay
    slot ahead of the arm.** gcc's filler takes the arm's first instruction,
    so the constant has to be first *and* survive the block; a plain
    `hun = 0x100;` is constant-propagated and re-materialised late, and
    `do { hun = 0x100; } while (0);` is not. func_800434F4's `m2` went 7 to
    MATCH on that one line, and func_8003BA14's identical arm 17 to 8.
And the partner rule, same family: **a constant the arm ORs in wants its own
name assigned immediately BEFORE the `do`/`while`, not inside it.**
func_8003BA14's `n = 0x10000;` written inside the block that stores
`p + 0x1C` is 8 and written on the line above it is a MATCH, because retail
materialises the `lui` before the store rather than after.

**And the recipe is not a recipe.** func_80043328 is the same body with the
same globals, and the family's named-read shape is 12 -> 22 there while the
compound `D_8009B0F4 &= m;` it already had is right. Read the arm's own
listing before transferring anything.

**Nine uses in ONE function, five of them round a SINGLE statement.**
func_8005B64C is the seventh member of the D_8009B0F4 dispatcher family and
went from 104 differences and -7 to 2 almost entirely on this idiom. What each
one does is worth knowing separately:
  * round a single constant assignment (`do { n = 0x800; } while (0);`) it
    stops that arm's stores being cross-jumped with an identical arm's;
  * round a single `lui`/`ori` constant it stops the scheduler splitting the
    pair and moving the `lui` back, which otherwise shortens the value's live
    range and flips its register;
  * round a single global *load* it puts the load in the register retail uses
    and pushes the neighbouring constant into the other one.
A function that needs nine of them is a function whose arms were **macros** in
the original, which is what the idiom is for -- so when a dispatcher's arms
all rhyme, reach for it early rather than after every naming lever.
**Fourth use, and the first on a run of FIVE statements.** func_80020BE4's
last 11 differences closed to 4 on a `do { … } while (0);` wrapped round the
five statements between a constant store and a named global read -- no
statement moved, no name changed. The permuter found it paired with a
`unsigned int` declaration that is worth **nothing** on its own, which is the
decompose rule paying for itself again. It then transferred unchanged to two
siblings (func_800434F4 18 -> 11, func_8003B808 15 -> 8). It is **not**
universal inside one function: round a two-statement pair in another arm of
func_8003B808 the same idiom is +6, because it breaks a cross-jump that merges
three arms.
**Third use, and this one is register allocation, not scheduling.**
func_8005F3B8 held the fifth parameter and a call result in $s1 and $s2
exchanged, ten sites wrong, through declaration order, a local copy of the
parameter, a moved store and three borrowed-local hints. Wrapping the two
calls that start the function in `do { … } while (0);` matches. The permuter
reached the same allocation by duplicating those two calls into both arms of
an `if` whose arms are identical — semantically a no-op that gcc merges back,
and a shape nobody writes; the `do`/`while` gets there and reads as source.
When a permuter win is *correct* but implausible, look for the plausible
shape with the same effect before installing what it found. **This is the specific thing the permuter is for**:
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
**And the re-score has to rank by `(abs(length error), differences)`, which
the tool did not do until 2026-09-03**: it reported func_8004803C's stored
output as "137 -> 98" and the 98 was a 158/157 candidate -- the positional
count read as a win only because it was being compared across a length
error. Decomposed on its own base, no half of that output moves the parked
137 at all. Same class as the never-compare-across-length-errors trap in
try_func, one tool further out.
**Reconstruct a permuter win from its FULL diff, not from the head of it.**
func_800222F4's `diff.txt` opens with a duplicated call and a deleted `b = g;`,
and reconstructing just those two is +2 and 201 -- nowhere near the stored
24. The rest of the file renames seven later `b` uses to `g`, and the point
is that `b` was serving TWO unrelated values: `&D_8009AF2C` in an earlier
block and a copy of `g` in this one. Split at the right place it is 24;
renaming *every* `b`, including the earlier block's, is -1 and 47. Two things
follow. Run the stored `source.c` through try_func FIRST to confirm the
number, so a failed reconstruction is visibly a reconstruction failure and
not a scorer bug. And read the whole diff: the duplicated call decomposed to
worth exactly nothing, so the entire gain was the rename the head of the diff
did not show.

**Half of what the scorer flags is unusable, and the rejects have exactly
three shapes.** One scorer run on 2026-09-04 produced six "better" outputs:
two were real (func_80019608's borrowed read, func_800222F4's redundant copy),
one was a complete MATCH (func_800243F4), and THREE had to be thrown away --
which is the rate to expect, not an unlucky batch. The shapes:
  * **an assignment placed between a `break;` and the next `case:`**, i.e. in
    unreachable code, with the variable then read in a later arm. That is an
    uninitialised read wearing a `new_var` name. func_8004D134 and
    func_80045208 both did it, and both scored an exact length that way.
  * **a cast dropped from an lvalue**, which can be a width change --
    func_80029EC4's `*((s32 *) pkt)` became `*pkt` on a `u8 *`.
  * **an assignment embedded in an expression that clobbers the LOOP
    COUNTER**, or a cursor read replaced by the fixed buffer it walks.
    func_8005EBF4's 226 -> 209 was entirely those two, and its two legitimate
    edits (`+=` and a rewritten loop test) are worth nothing on their own.
So: read `diff.txt` in full, ask of every `new_var` whether the line that
assigns it can actually execute, and check the declared type of anything that
loses a cast. The score is a weighted diff and it cannot see any of this.

**A permuter output that drops a cast can be a WIDTH change, and that is the
false-zero trap wearing its plainest disguise.** func_80029EC4's best output
rewrote `*((s32 *) pkt) = 0x8000000;` as `*pkt = 0x8000000;` and scored
len2/145 -> len0/190 -- an exact length, which the ranking rule prefers.
`pkt` is `u8 *`, so that is a BYTE store: the two instructions it "saved" are
the ones the word store needs, and the code no longer does what the function
does. Read the pointer's declared type before crediting any output that
removes a cast from an lvalue.

And a better count is **not** a better candidate: two of the first seven finds
were semantically wrong and scored far better than the correct source — one
deleted a store the target has (func_8004C84C, 14 against a correct 25), the
other cast an index the target does not mask (func_8003B744, 8 against 18).
Both would have gone in as silent bugs on the number alone.

**The per-file guards in `variables.h` are a sweepable pool, and nobody was
sweeping them.** Each one exists because some *other* function needed that
symbol spelled differently, and each carries a comment naming the symptom it
fixed. A park whose residue describes the same symptom is a free match.
`tools_src/sweep_guards.py` tries every guard belonging to a symbol a parked
candidate references but does not already define, and prints only strict
improvements on `(abs(length_error), differences)`. First run: **one match** --
func_8003353C, 2 differences to 0 on `D_8009B3A4_IS_VOLATILE` -- plus three
park improvements.
**Third run, 2026-09-05, after the .data sweep added 29 `_IN_DATA` arms to the
pool: zero hits over the 98 parked candidates at or below 30 differences.**
A clean negative worth having -- the new arms reach the bare form that the
inflated sizes already reached, so no park that had the size was waiting
for the attribute, and no park that lacked it wanted the bare form.
**Second run, weeks later: another match, on the same guard.** func_800336F0
was parked at 2 with the residue "retail materialises the 0x2000 it compares
D_8009B3A4 against inside the test's own block and we hoist it into the
preceding branch's delay slot" -- `D_8009B3A4_IS_VOLATILE` closes it. So the
sweep is not a one-off: **re-run it after every batch of park work**, because
each newly parked candidate is a fresh chance for a guard that already
exists. The guard's comment said "retail reloads each time, which
only a volatile does"; the park's own residue said "retail leaves a `nop` in
the preceding volatile load's delay slot". The same sentence, written twice,
weeks apart, in two files nobody read together. Run it after any batch of park
work, and read a hit as a lead: a guard changes what the symbol *is*, so check
its comment against the listing before installing it.

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
- **A `u8` parameter is also right when the CALLEE loads its stack slot with
  `lbu`.** The rule below is about the call site; the fifth-and-later
  arguments give you the callee's own evidence, because a byte parameter is
  read out of the frame with `lbu` and a word one with `lw`. Getting it wrong
  costs more than the load: the `lw` lands in an argument register and forces
  a copy of a *real* argument out of its own, which shifts every register
  after it. func_8005ABA0's PROVISIONAL prototype said `s32` and the listing
  says `lbu` -- read the callee before trusting a PROVISIONAL signature, and
  re-run try_func over the callers when you change one.
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
- **Count the callee's arguments against a caller that already MATCHES.**
  func_8004E9A0 passed four arguments to `func_8007FA38` and the matched
  `src/func_800582C0.c` passes three -- so the fourth was invented, and it
  pinned `$a3` where retail lets the allocator reuse it. The instruction
  count does not move when you drop it (the extra argument was free), so
  nothing flags it; `grep -rn <callee> src/` does, in one command, and it is
  worth running on every call in a draft rather than only when adding a
  prototype. **Second instance the same day**: func_80032184 passed FOUR
  arguments to `func_80081DE8`, which every one of its eight matched callers
  calls with two. There it was not free -- dropping the two took the function
  from 19 differences to 12 once the invented `p` and `1` stopped pinning
  `$a2` and `$a3`, and the candidate had been carrying a permuter hint
  (`one = 0x100;` written dead in the *previous* arm) that existed only to
  compensate for them. **A permuter hint that has to be explained in a
  comment is a sign the source around it is wrong**; delete it and re-measure
  before writing it down as load-bearing.
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
- **`sll 24` instead of `andi 0xFF` on a byte global's read-modify-write
  means the value was NAMED.** `D_8009B43C = D_8009B43C - 1; if (…)` reads
  the byte back and gives `andi 0xFF` -- that is the func_8005BFC8 rule. When
  the target has `sll $v0,$v0,24` there instead, the source kept the SImode
  result in a local: `c = D_8009B43C - 1; D_8009B43C = c; if ((s8)c != 0)`.
  A `(s8)` cast on the global itself does not do it, because the read-back is
  still a `u8` load. Same shape with `bgtz` for `> 0` (func_80044608).
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
- **A narrow local can also be what *creates* an instruction, and with it a
  whole register.** func_8005AE68 masks a selector with `& 0xFF` after an
  `& 7`; as `s32` gcc folds the mask away entirely -- correctly, the value
  already fits -- and the function comes out five instructions short. As
  `u8` the truncation survives, the later `< 7` test becomes `sltiu` in
  QImode, and the value now needs a callee-saved register across a call,
  which was the seventh saved register retail had and we did not. So when a
  function is short by a few instructions *and* saves fewer registers than
  retail, look for a redundant-looking mask that a narrow declaration would
  keep. This is the mirror of the func_80027060 entry below, where a
  redundant *cast* was the pseudo that should not have existed.
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
- **A symbol read `lh` where you get `lhu` wants a NAMED LOCAL, not a cast.**
  `*(u16 *)(g + 8) = *(u16 *)(g + 8) - D_8009B146;` with `D_8009B146` declared
  `s16` still emits `lhu` for the symbol: C promotes both to `int`, and combine
  then narrows the whole subtraction to HImode, where the extend is dead and
  the sign of the subtrahend cannot matter. `(s32)D_8009B146` does not stop it
  and neither does storing through `(s16 *)`. `d = D_8009B146;` into an `s32`
  local **does** -- the extend now has a pseudo of its own with several uses,
  so combine cannot substitute it away, and the load stays `lh`. A four-line
  control probe through cc1psx settles this in one command, and it is worth
  running: the same probe **falsified** the entry that had stood here, which
  guessed the discriminator was four subtractions versus two (it is not -- a
  bare symbol gives `lhu` at any count). func_80040DD8 and func_80041068.
- **splat's interior symbol is a different name for the same address, and the
  relocation shows it.** `D_800EFE42` is the second halfword of `D_800EFE40`;
  written `D_800EFE40[1]` the relocation comes out `%lo(D_800EFE40+2)`, which
  assembles to the identical word and reads as two differences against the
  listing's `%lo(D_800EFE42)`. Declare the interior symbol in variables.h and
  use it. The tell is a diff where only the symbol *name* differs and the
  offset makes up the gap.
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
    **Third use, and the tell is an EXTRA SAVED REGISTER rather than a
    delay slot.** A bare symbol is one instruction to gcc, so there is
    nothing for CSE to share either -- where the aggregate form's `%hi` half
    gets commoned across a call or a branch into a callee-saved register,
    the bare form re-materialises the pair at each reference, which is what
    retail does. func_80012E5C reads two one-byte flags twice each with a
    call between; under `_IS_AGGREGATE` gcc hoists both `%hi`s into `$s0`
    and the function saves a *fifth* register retail does not have, which
    rotates every callee-saved allocation downstream and reads as a loop
    problem. `u8 sym[8]` plus `as -G4` on each of them is the fix. So when
    your prologue saves one more register than the target's and the extra
    one holds a `%hi`, size that symbol out of small data -- and note the
    arms have to go in **together with the rest of the block being right**:
    each was measured as +1 and worse earlier in the same function's life,
    and only became correct once the allocation around it was.
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
  one of them first-try, because counting `%gp_rel` and `lui  *\$at, %hi(` in the
  listing and reading the widths out of variables.h settles the question in a
  minute.
  **The `dup-%hi` pool is productive, and its own tag points the wrong way
  when `gp > 0`.** candidates.py tags those candidates "try
  -mno-split-addresses", which is right for the `gp == 0` branch and wrong
  here: the flag is per *file* and cannot separate two symbols of the same
  width. func_8002A788 is the first match out of that pool (25 candidates
  that had been skipped for weeks) and it wanted the per-symbol route
  instead -- `as -G1`, `D_8009B26C_SIZED` and `D_8009B269_SIZED` to push two
  one-byte symbols out of small data while the one-byte D_8009B258/D_8009B259
  beside them keep `%gp_rel`, plus `D_8009B3A4_IS_VOLATILE` for eight reloads
  of one halfword. Run `grep -c '%gp_rel'` and the widths BEFORE reading the
  tag.
  **cc1psx will not hoist a BARE symbol's memory reference into a delay slot,
  and that is how you get an empty one back.** It will happily hoist the `lui`
  half of its own `%hi`/`%lo` pair, because that half is an ordinary
  instruction; a bare reference is one pseudo-instruction the assembler
  expands, and the filler leaves it alone. So when retail leaves a branch's
  delay slot empty in front of a block whose first instructions are global
  references, size **every** such symbol out of small data -- **one at a time
  is not enough**, because the filler simply takes the next candidate's `lui`.
  func_8002CEE8's last difference was exactly this: `D_8009B362` sized alone is
  15 differences (the filler switches to `%hi(D_8009B370)`), `D_8009B370`
  sized alone is 15 (it switches back), and the two together are a MATCH. The
  same function needed five other symbols sized or scalared; the recipe that
  decided all of them is below, and the gp side here is two one-byte flags, so
  `as -G1` with `[8]` inflations on the byte-wide symbols is the whole
  addressing story.
  **`gp == 0` is a first-line check, not a last resort.** When the listing has
  *no* `%gp_rel` at all, recipe branch 1 says any `-G` is free — and in one
  session that single fact decided four functions, three of them from the
  **delay-slot / splitting** side rather than the addressing side:
  func_800151D8 (a `nop` retail leaves in front of the pair), func_8002C7E8
  (a `lui` hoisted into a search loop's load delay slot), func_8003AAE4 (the
  `lui` hoisted thirty instructions back into an earlier block, halves ending
  up nowhere near each other) and historically func_8003CCD8. The shape is
  always the same: **retail keeps `%hi` and `%lo` adjacent or leaves a slot
  empty in front of them, and we split them or fill it.** Both declarations
  assemble to the same two instructions; only the scalar is *one* instruction
  to gcc, so there is nothing to hoist, split or schedule. So when a function
  greps `gp=0` and the remaining differences are about where the halves of an
  address sit, reach for the scalar arm plus `as -G0` before re-reading the
  source — it is two lines and it has never yet been wrong in that state.
  **When every gp-relative symbol in the function is one byte, the window is
  as wide as it gets and the *real* declarations fit.** func_800371A8 reads
  four one-byte scalars gp-relatively and needs D_8009B398 -- a real `u16` --
  bare, so `1 <= G < 2` and `as -G1` does it with no inflated size and no
  guard at all. The residue that pointed here was the usual one: retail
  leaves a `nop` in a `bnez`'s delay slot in front of the `%hi`/`%lo` pair and
  we hoist the `lui` into it, because the aggregate arm is two instructions to
  the delay-slot filler and the bare symbol is one. So run the widths *before*
  assuming the `gp > 0` case is hard -- one-byte flags are the commonest
  gp-relative symbol in this binary, and against them almost anything is
  non-small.
  **Both sizes are yours to set, and that is what opens a closed window.**
  The window is `max(gp symbol size) <= G < size(bare symbol)`, and the rule
  above treats the gp side as fixed. It is not. func_80025D30 needs
  D_8009B260 bare while D_8009B20C stays `%gp_rel`; D_8009B20C is declared
  `s16 [4]`, eight bytes, so `8 <= G < 8` is empty and the function looks
  blocked. The unit only ever touches element [1], so a per-file guard
  declaring it `s16 [2]` moves the gp side to four and `-G4` fits. Check what
  the *unit* actually reaches before believing a threshold does not exist.
  **Eliminate before reaching for the threshold.** If the symbol that needs the
  non-small form is *narrower* than one that needs `%gp_rel` in the same
  function, no `-G` exists between them and the answer is the unsized array —
  cc1psx's own pair, default flags. func_8003C950 wants `lui/sb` on a one-byte
  symbol and `%gp_rel` on a four-byte one; running that check first made it a
  first-try match with no iteration at all.
  **A FIFTH form, and it is the honest spelling of the third: place the symbol
  in `.data`.** `extern u8 sym __attribute__((section(".data")));` takes the
  symbol out of small data at the **compiler**, with its *true* size and no
  assembler `-G` at all -- so it reaches the bare form that the
  inflate-the-size-and-lower-`-G` recipe reaches, without either half of that
  recipe. cc1psx 2.8.1 accepts the attribute on an `extern`, which is not
  obvious and is the thing to check first if this ever stops working.
  func_80030FA0 is the worked example and it is now installed that way:
  `D_8009B365` and `D_8009B26C` declared into `.data`, `D_8009B2F1` and
  `D_8009B2B2` left plain so they keep `%gp_rel`, default assembler flags, and
  the `PER_FUNC_AS_FLAGS["func_80030FA0"] = "-G2"` line deleted. The control
  says the attribute is doing the work rather than something else: the same
  source with plain scalars at default flags is **10 instructions against 12**.

  **And it is the BARE form only -- where retail wants cc1psx's OWN split pair
  beside a gp-relative symbol, `.data` is the wrong arm.** func_80015DFC sat
  at -1 with D_800E9D98 in `.data`: the assembler expanded it adjacent and
  self-referencing, and retail has the `lui` at the top of the join block,
  copied into a branch's delay slot, with the `%lo` load two instructions
  later. That is the compiler's pair, scheduled apart, and the way to get it
  next to a one-byte `%gp_rel` flag is the second recipe branch: real scalar
  declarations and `-G1` at BOTH the compiler and the assembler (2026-09-05,
  a first-try MATCH once measured). So before converting a symbol to `.data`,
  read whether retail's pair is adjacent-and-self-referencing (bare) or split
  through a temp (cc1psx's own).

  **The sweep's first three conversions (2026-09-05) took the SIZE out and
  could not take the FLAG out.** func_8003D74C, func_8002DC38 and
  func_8003C7A0 each carried one `[N]` inflation and `as -G1`; with the
  symbol in `.data` and the same `-G1` all three still MATCH, and with the
  assembler back at `-G8` they are -2, -5 and -4 -- because the `-G1` was
  also what kept the unit's two-byte scalars (D_8009B234/236/230 in
  func_8002DC38, rendered `la`) out of small data. So a conversion is two
  separate claims: the declaration's truth (the attribute buys it) and the
  flag's redundancy (only when the inflated symbol was the ONLY non-small one
  the threshold served). Read the unit's other scalars before expecting the
  `PER_FUNC_AS_FLAGS` line to go; when it cannot, the honest declaration is
  still the change to make.

  **Why this matters beyond one function, and where it came from.** It is
  krystalgamer's route, raised as a review objection on our first PR to his
  tree, and the objection is one this file should have made itself. `u8
  D_8009B365[4]` is a *mechanism written as a measurement*: four is simply the
  number that clears the assembler threshold, and it spans `0x8009B366` and
  `0x8009B367`, which are two separate symbols his tree has already named
  (`gFreeDuel_bCursorColumn`, `gFreeDuel_bCursorRow`). Nothing breaks -- it is
  an `extern`, only `[0]` is read -- but the declaration states something false
  about the object in the one file a reader would trust. Every `[8]` in the
  recipe above has the same defect, including the ones this file argues *for*
  ("when you inflate a size, inflate it to eight, not to the truth" is advice
  to write a falsehood, and it was correct only because no alternative had been
  measured).

  **The sweep this opens -- DONE for the inflated sizes on 2026-09-05.** 56
  functions carried an intermediate `PER_FUNC_AS_FLAGS` (30 at `-G4`, 17 at
  `-G1`, 9 at `-G2`) and another 124 carry `-G0`. Every `[N]` inflation in
  `src/` behind an intermediate row was converted that day in six batches of
  three to five units against the full build: 27 units, 29 symbols given
  `_IN_DATA` arms with their real scalar types, and 14 assembler rows deleted
  (20/17/5 remained after that pass). The two `_SIZED` guards left in `src/` are real arrays --
  D_8009B370 (`u16[]`, indexed by D_8009B362) and D_80010038 (passed by
  address) -- and are not inflations. Three things the sweep measured:
  the row goes only when the inflated symbol was the ONLY non-small symbol
  it served (13 units kept theirs); two conversions exposed source that had
  been leaning on the inflated arm (`*(s32 *)D_800FE0D0` reading through an
  array's address, a byte store on a `u16`), both fixed as lvalue casts; and
  the `-G0` rows are a different population, with scalar arms rather than
  sizes -- which converts by the same route where the scalar was the ONLY
  reason for the row: seven units whose one guard was a single `_IS_SCALAR`
  (func_80070710, func_8003F7D4, func_80030F40 and four D_8009B0D8 users)
  build byte-identical with the symbol in `.data` at the default threshold,
  and their `-G0` rows are gone (129 -> 122 by `grep -c` on build.py; the 124
  this file used to quote was never re-counted). **And that is where this
  route ends**: of the 122 units left at `-G0`, 93 carry NO guard at all and
  have no `%gp_rel` in their listings -- the row is the honest statement
  "nothing in this unit is small data", serving the default scalar arms of
  every symbol they touch, and there is no inflated size or per-file
  disagreement to remove. Putting each of those symbols in `.data` would
  trade one per-function flag for a per-symbol attribute on declarations
  that are already true, which is not a gain. The remaining handful mix
  scalar guards with `_IS_AGGREGATE` or `lui $at` stores and were not
  measured. Each conversion removes a
  per-function assembler flag *and* an inflated size only when both claims
  hold, and they are separate claims.
  **The second route, the same afternoon, took the rows the first could not:
  put the unit's OTHER non-small scalars into `.data` too.** A row that
  survived the first pass was serving real-width scalars (a `u16` flag, a
  `volatile u16`, a pointer, an `s32` beside one-byte `%gp_rel` neighbours).
  With each of those in `.data` under its real type, 21 more units build
  byte-identical at the default threshold and their rows went: 17/6/1
  remain, and of those the ones with source in `src/` stay for a measured
  reason each -- a file-local `extern sym[]` redeclaration (func_800339D0,
  func_80040588), an array use `D_8009B408[16]` (func_8003C628), a real
  array on a sized arm (func_8002CEE8, func_800136E4), the compiler's own
  pair wanted beside a gp flag (func_80015DFC), and one -1 (func_8002DC38).
  The other 13 rows belong to parked candidates. The recipe for a unit:
  list every symbol the listing does NOT read `%gp_rel`, and if each is a
  plain scalar (used without `[i]`, and with `*(T *)sym` rewritten as
  `*(T *)&sym`), give it an `_IN_DATA` arm and measure at as `-G8`.
  Six guarded `-G0` units went the same way that afternoon (129 -> 116
  rows). **One pitfall, hit three times in one hour:** when a symbol's plain
  `extern T sym;` sits inside an existing `#ifdef sym_IS_SCALAR` chain, a
  generic wrapper around that line nests the new arm UNDER the scalar guard,
  and a unit that defines only `sym_IN_DATA` falls through to the aggregate
  arm -- "has an incomplete type". The `.data` arm has to be the HEAD of the
  chain (`#ifdef sym_IN_DATA ... #elif defined(sym_IS_SCALAR) ...`). One
  conversion is measured; 179 are not. Do them a few at a time against the full
  build, not in a batch -- `-G0` takes every scalar in a unit out of `%gp_rel`
  at once, so those are the ones most likely to need more than a declaration
  change. And note the flag is not always replaceable: `.data` moves *named*
  symbols, where `-G0` moves everything, so a function that genuinely wants the
  whole unit non-small still wants the flag.

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
- **`volatile` also blocks a read-modify-write fold, and that is a different
  use from re-reading.** Two RMWs on one global back to back with no store
  between them -- `g &= a; g |= b;` -- let gcc fold the second read into the
  value it just wrote, and a whole load/or/store disappears. Nothing in the
  source blocks it: a name for either read folds too, and only an intervening
  store through a pointer gcc must assume aliases will do it. Where retail
  keeps both, declare the global volatile. func_80032184 went 81 differences
  to 33 on that word alone. It composes with the bare-symbol form at `-G0`
  (the `lui $at` stores survive), which the note in variables.h had said it
  would not -- that note is about `-G4`.
  Probed on the three sibling dispatchers the same afternoon and it moved
  none of them: func_8003C328 is unchanged at 21 because its arms already
  have stores between the two read-modify-writes, so there is no fold to
  block; func_8003C120 is -7 and much worse, because it assembles at `-G4`
  where volatile really does cost the bare form; func_8004BCE8 never touches
  the symbol. The lever is for the back-to-back shape specifically, not for
  the family.
- **`volatile` is also how you let a reload be HOISTED, which is the opposite
  of every other use of it here.** gcc 2.8 will not move a load of an ordinary
  global above a store through a pointer, but it will move a *volatile* one --
  so where retail reads a global back after a store and puts the read's own
  delay-slot filler before that store, a non-volatile declaration leaves a
  `nop` and a length error. func_8003C120 was +1 on exactly that, and the
  sized-plus-volatile arm (new: `D_8009B0F4_SIZED_VOLATILE`) fixed the length.
  It also **narrowed the standing claim that volatile blocks the bare-symbol
  form at -G4** for the second time: it does not, at either threshold, on the
  *sized* arm -- the original note was about the aggregate arm.
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
'lui  *\$at, %hi('`, the `0x80073840` scope cut, `candidates.HAND_WRITTEN`. A
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

A third source sits in `docs/EXTERNAL_LEADS.txt` under the same contract:
eleven function-name guesses lifted from a static *recompilation* of the same
binary. Same rules -- hypothesis, never evidence, never promoted by citation --
and the same caution earned the hard way: both structural claims in it that
were worth checking turned out to be things this repo already had, and the one
apparent error in it was a misreading on our side.

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

**The GitHub repo is PUBLIC again, since 2026-08-31** -- reopened at krystalgamer's request ("deixa o teu repo publico, mais facil para referenciar") so the two other people working on this binary can cite it. He also has write access. **Check this with `gh repo view --json visibility` before repeating it**, which is the whole point of the paragraph and is the thing that failed last time.

Before it was reopened the history was audited rather than assumed: no `.img`/`.ccd`/`.sub`/`.bin`/`.zip`, no `SLUS_014.11`, no `orig/`, `extracted/` or `third_party/` path was ever ADDED in any commit, and there is no blob over 2 MB anywhere in the history. `git log --all --diff-filter=A --name-only` and a `git rev-list --objects --all` size scan are two commands and they are what makes "safe to publish" a measurement instead of a belief. Run them before any future visibility change -- gitignore protects the working tree, not the history, and the two are not the same question.

**The earlier version of this paragraph said "private
again ... it was public for a few hours on 2026-08-07" for three weeks while
`gh repo view` reported `"visibility":"PUBLIC"` the whole time -- it went back
public and nobody updated the line. It surfaced only because a second decomper
opened with "I'm surprised you're posting the converted C files publicly".
**A fact about the outside world rots faster than anything else in this file;
check it with the command, not with the paragraph.** Two consequences worth
knowing. Pushing over HTTPS needed a
credential helper while anonymous access was gone -- `gh auth setup-git`
configures it and the existing token already has `repo` scope; without it
`git push` failed with a bare 403. And the traffic figures from the public
window are worth reading correctly: 0 forks, 0 stars, 7 unique visitors, but
115 clones from 69 unique sources. That ratio is scraper bots, which hit new
public repos within minutes -- not human interest, and not undoable. Going
private stops future exposure; it does not recall what was already mirrored.

**`timeout` on `git push` can leave the remote ahead of your tracking ref.**
The transfer completes, the server accepts, and the client is killed during
the final ack -- so `git status` still says "ahead 1" and the retry fails
with `cannot lock ref 'refs/heads/master': is at <new> but expected <old>`.
That message means **the push already worked**: `git fetch origin` fixes it,
and re-pushing or force-pushing would be wrong. Read the two hashes in the
error before doing anything.

**Never run a background job that rewrites `build.py` (or any shared config)
while you are measuring.** `score_permuter_outputs.py` is one: it writes and
then deletes `config/flag_overrides.json`, which try_func and build.py both
read, so a manual measurement that needs its own override can silently fall
back to the default assembler flags while the scorer runs. It now says so at
the top. A sweep that patches `SMALL_DATA_NOP_FUNCS` per
candidate and restores the file afterwards restores the copy it read at
*start-up* -- so every `PER_FUNC_AS_FLAGS` line added while it ran was
silently deleted when it finished. The build then went red with 550
"differing" functions, all fallout from one function that had matched an hour
earlier. `git diff tools_src/build.py` showed it in one line. Two rules: have
such a sweep write to a *copy* of the tree or hold the file for the whole run,
and when a build goes red with hundreds of diffs, read `git diff` on the
tooling before reading any of the functions. The sweep itself was a clean
negative -- 43 short parked candidates, no hits -- so the missing-nop gap is
rarer than the one instance suggested.

**When a length error is all `nop`s, scan the whole binary for the sequence
you are producing before hunting for a source shape.** func_80015310 came out
three instructions short in one block, and the built code was
`lbu $v0,0($a0)` followed straight by `sb $v0,%gp_rel(...)` -- a load-delay
violation. Twenty lines of Python over all 1799 listings found **zero**
adjacent `lbu`->`sb` pairs on one register anywhere in the retail binary, so
the sequence cannot be right and it is a toolchain gap, not codegen. It is
the one `SMALL_DATA_NOP_FUNCS` already exists for: maspsx assumes the
instruction after a load will expand through `$at` and fill the slot, which
is false when the symbol is small data. Adding the name to that set was -3 to
0. A four-line control probe reproduced it in isolation first, which is what
turned "gcc scheduled differently" into "the assembler did not insert a nop".
**The general move: when your build contains an instruction pair, ask whether
the target contains that pair anywhere.** It costs one command and it
distinguishes "wrong source" from "wrong tool", which nothing else does.

**And a long sweep must FLUSH, or a run that is killed reports nothing.**
`sweep_borrow.py` ran twenty minutes on func_800408D0, was stopped, and left
a zero-byte log: Python buffers stdout when it is redirected, so every hit it
had printed died with the process. Both sweeps now pass `flush=True`. This is
the same failure as the others in this paragraph wearing different clothes --
the run happened, the answer did not survive, and nothing said so.

**`pkill -f '[p]attern'` protects the shell only from the PATTERN's own text;
a plain occurrence of the same word anywhere else in the command kills it.**
On 2026-09-05 a command that ran `pkill -9 -f '[p]ermute.py'` and, three
lines later, `nohup ... tools_src/permute.py func_X` killed its own shell
twice in a row: the regex `[p]ermute.py` matches the literal `permute.py` in
the nohup line, which sits in the same `bash -c` argv. Put the kill and the
restart in separate commands, or anchor the pattern to something the restart
line does not contain (`'tools_src/[p]ermute\.py'` still matched; the kill
has to run alone). Related: `grep -c` exits 1 on a zero count, so a
`... ; ps | grep -c pattern` as the LAST command makes a healthy result read
as a failure.

**Killing a permuter mid-compile can leave the wine prefix in
`wineboot --init`, and the try_func that was running blocks behind it
forever.** The tell is that ONE try_func hangs while another, started
afterwards, completes normally -- so the toolchain is fine and it is that
process. `ps | grep wineboot` and kill both. Twenty minutes went into this
before the second try_func proved the toolchain was up.

**try_func OVER-REPORTS a difference when one address is spelled two ways,
and that hid 59 finished functions.** It compares the rendered text, so
`lui $v0,%hi(D_80011434)` / `addiu %lo(D_80011434)` and `lui $v0,32769` /
`addiu $v0,5172` read as two differences -- and they are the SAME TWO WORDS.
So does `%lo(D_80010538+3836)` against `%lo(D_80011434)`: 0x80010538 + 0xEFC
is 0x80011434, and splat's interior-symbol note further up this file is the
same observation from the other side. On 2026-08-31, sixty-seven ported
candidates sitting at one to four "differences" were fed to `build.py`
instead, and **fifty-nine of them were byte-identical**. Two rules follow,
and the second is the one that costs:
  * when a residue is nothing but `%hi`/`%lo` against a bare `lui`/`addiu`
    pair, or two symbols whose offsets make up the gap, **confirm with the
    full build before believing the number**. That is one command and it is
    the only arbiter there is.
  * and never let a park entry record a difference count that was never
    checked against the build. Several of those fifty-nine had prose here
    diagnosing a residue that did not exist.
  * and a park entry's "measured and dead" list is worth NOTHING while the
    candidate has a length error. func_80022674 was parked at -1 with an
    `s16` store for a negative halfword constant listed among the shapes
    that had been tried and had not moved the count -- it was the last
    difference, and it read as dead only because a positional diff on a
    223/224 candidate is already shifted past it. When you pick up a park
    whose length is wrong, fix the LENGTH first and then re-try everything
    the entry says is dead; the list was compiled with a broken instrument.

**Both spellings are now resolved in try_func, and a third was found the same
hour.** `canon_addr()` turns `%hi`/`%lo` of any resolvable symbol into the
immediate it assembles to -- splat's `D_XXXXXXXX` names ARE their addresses,
so the map is exact by construction and an unresolvable name still compares
strictly. And `GTE_OPS` maps the coprocessor-2 mnemonics the listings use
(`rtpt`, `avsz3`, `avsz4`) onto the `c2 <imm>` objdump prints, reading the
encodings out of `include/gte_macros.inc` so the two cannot drift.
`check_try_func` went from 141/150 to **145/150** on the src direction and
stayed at **93/93** on the parked direction -- the loosening ate nothing,
which is the half that matters.
**Five are still wrong and it is a fourth instance of the same class**:
`renumber_labels` numbers the two sides differently on GTE-heavy functions,
so every branch reads as a difference at a constant offset (`j L3` against
`j L4`). Those five build byte-identical. When a whole function's branches
differ by a constant label offset, that is the renderer, not the code.


**try_func's trailing arguments REPLACE the compiler flags; they do not
append.** `try_func f cand.c -msplit-addresses` compiles with only that flag --
no `-O2`, no `-G0` -- and on func_8004B854 read as +31 before anyone looked at
the `flags:` line it prints. Pass the whole set (`-quiet -O2 -G0
-msplit-addresses`), and read that header line before the count, which is the
same rule as the stale-flag-table one below wearing the other shoe.

**try_func costs FOUR SECONDS, not forty, and it parallelises -- so sweep by
the handful, not one at a time.** Measured on 2026-09-04: a cold candidate
(content changed, so no cache hit) is 4.2s; three cold candidates started
together finish in 6.0s against 12.6s serial, on a box whose four permuters
are already using half of its eight cores. A repeat of an unchanged candidate
is 0.1s, because there is a cache -- which is why an accidental re-measurement
looks instant and a real one does not.

This matters because the cost of a measurement decides the *shape* of the
work. Believing it was forty seconds, I was testing two or three spellings of
a lever and then reasoning about the rest; at four seconds the right move is
to write eight and measure them in one command:

    ( for v in v1 v2 v3 v4 v5 v6 v7 v8; do
        .venv/bin/python tools_src/try_func.py <func> $SP/$v.c > $SP/r_$v.txt 2>&1 &
      done; wait )

Each run gets its own `build/scratch/tryNNNNNN`, so they do not collide. Eight
variants against func_8005EBF4's remaining giv came back in about fifteen
seconds, six of them tied and two worse -- which is the wrong-axis tell, and it
is worth far more as a *complete* negative than as three inconclusive probes.
The sweep tools in `tools_src/` already work this way; hand measurement had not
caught up.

**A tool's answer only counts if it measured what you think.** Nine bugs in
this project were tools reporting confidently on something they had not
measured — a
stale object, an unverified flag, a crashed build read as clean. When a tool
says "no", ask whether it could have said "yes"; when it says "yes", ask whether
the run it judged completed. The cheapest way to fall into this is a **filter**:
`try_func.py ... | grep -E '<<|differing|MATCH'` prints nothing both for a clean
match and for a compile error, because the error text matches none of the three
patterns. Read try_func's last lines, not a grep of them.
**Three cancellations in ONE function, and each one hid the largest lever
left.** func_80016784 sat at -2 while four missing sign-extends at a call
offset two extra instructions elsewhere; at +1 while two extra unsigned
reciprocal divides offset a shortfall of the same size; and it rejected the
`s32 c = (s8)e[0x18];` declaration at -1/134 in favour of `s8 c` at +2/124 --
where the `s8` was wrong, and once everything else was right the same `s32`
went to 352/352. Every one of those read as "nearly right" and every one was
a stop sign. The rule that falls out: **a length error smaller than about
five is not evidence of anything, and a candidate rejected while ANOTHER
fault was still open must be re-measured once that fault closes.** Keep the
rejected spellings; they are not dead, they were measured on a broken
instrument.

**The `(abs(length_error), differences)` order assumes the length error is
ONE fault, and when it is two faults cancelling it inverts.** func_80027508
reached 161/161 with 95 differences while two errors offset each other -- the
`t[idx - 1]` fold is -2 and an un-interleaved pair of `% 5` chains is +2 --
and the corrected source is +1 with 25. A permuter output found that false
zero and the ordering rule would have installed it. So when a length error
appears or disappears after an edit you can explain, check whether the
*other* fault moved too: a zero that arrives without you fixing anything is
worth one structural diff before you trust it.

**And the census is what breaks the tie between two candidates at the SAME
length: read whether its deltas point ONE way or cancel.** func_800279BC
reached 271/271 twice with different sources. One scores 177 and its census
is `addiu -1, addu +2, j +1, nop +1, sll -2, sra -1` -- four extra against
four missing, i.e. two faults that happen to sum to zero. The other scores
196 and its census is `addiu -1, lui +1`. The difference COUNT prefers the
first and it is the worse candidate; the second is two opcodes from correct.
So the ranking rule `(abs(length_error), differences)` needs a third key
that comes BEFORE differences: **the number of opcodes whose delta is
non-zero.** A candidate whose census is nearly empty is close even when its
positional diff is large, because one wrongly-placed value rotates every
register downstream and the diff charges for all of them.

**An edit worth ZERO differences can still be the right edit, and only the
opcode census says so.** func_800528AC's flags word declared `u32` rather
than `s32` scores 249 either way -- but the census turns two `sra` into two
`srl` and all four shifts then match retail exactly. The difference count
cannot see it, because the register names around the shift are wrong in both
and a positional diff charges for those regardless. So run
`collections.Counter` over the first token of both columns after every batch
and read the OPCODE deltas, not the total: an edit that moves an opcode from
the wrong mnemonic to the right one is progress even at an unchanged count,
and an edit that leaves the census untouched is a passenger however good the
number looks.

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

**The `lui $at` grep in this file was wrong for months, and it failed
silently.** Every prose copy of the step-0 check said `grep 'lui $at,%hi('`;
splat writes `lui        $at, %hi(`, with a space after the comma, so that
pattern matches **zero** of the 1799 listings. Anyone following step 0
literally got `at=0` for every function in the binary -- which reads exactly
like "this one needs no addressing work", the most common and most welcome
answer. The real counts are 392 files with a loose `lui $at` and 346 with the
tight form. No *tool* used the broken pattern, only the prose, which is why
nothing ever went red. Surfaced on func_8002FD10, whose two `$at` stores the
check had just told me did not exist. Same lesson as the park filter and the
`| grep -E` hazard: **when a filter says zero, prove it can say one.**

**Second instance of the same trap, and it cost a wrong conclusion:
`grep -c 'break 7'` returns ZERO on func_8005EBF4, which contains seven.**
splat writes `break      7` with padding, so the single-space pattern matches
nothing -- and "no `break 7`" reads as "no runtime division", which is a
*positive* finding about the source and sends you looking for reciprocal
multiplies that are not there. Use `grep -cE 'break +7'`. The general form is
the rule below and it is worth stating as a habit rather than a list: **every
grep against a splat listing must allow runs of whitespace**, because splat
column-aligns its mnemonics and operands.

**A scan is only as good as the filters it copies.** The `lui $at` pool was
counted three times and was wrong twice, each time because the ad-hoc scan
skipped a filter `candidates.py` already applies. 167 became 136 when the
signature was tightened from `lui $at` to `lui $at, %hi(` — the loose form
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
