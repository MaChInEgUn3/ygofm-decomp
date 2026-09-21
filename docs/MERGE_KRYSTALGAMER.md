# Offering functions to krystalgamer/memories-decomp

On 2026-09-04 krystalgamer said in #general, replying to Unchiga: *"btw don't
wait to get a bulk of data, feel free to throw smaller PRs"*, and answered
"claro" when asked directly whether matched functions from this tree should
come as PRs too. The repo owner here confirmed that as a go-ahead the same
afternoon. It is recorded because the standing rule in this project is that a
relayed permission is not one — the go-ahead has to come from the repo owner,
every time, and this is that record for this round.

## The measurement

His `config/slus_01411/functions.csv` carries a per-function `status` column.
Cross it against `src/func_*.c` here:

| his status | count |
|---|---:|
| `matching_c` | 806 |
| `unmatched_asm` | 327 |
| `sdk_asm` | 598 |
| `handwritten_asm` | 63 |

**166 functions are matched here and `unmatched_asm` there**, totalling
63,688 bytes. The list is `docs/merge/krystalgamer_gap.txt`, smallest first.
A further 72 of this tree's parked candidates sit in his unmatched set too;
those are not matches and are not offerable as code, though their PARKED.txt
diagnoses may still be worth something to him.

## Why the C should port, and why that is not yet proven

His `config/slus_01411/attempts.csv` logs each attempt with its compiler
profile, and the rows read `gcc-2.8.1-psx`, `profile=gcc_2_8_1_g8`. That is
**the same compiler this tree uses**, which removes the objection that
sank the earlier assumption about the other tree — WORKFLOW's toolchain
section is emphatic that a different pipeline can reach the same bytes from a
different SDK, and equally that a shared compiler is not by itself a shared
pipeline. He splits at a different game/SDK boundary (0x80073704 against
0x80073840 here, per LIBRARY_FUNCS.txt) and organises `src/` by real source
names — `ai_fusion.c`, `duel_field_display_objects.c` — not by
`func_XXXXXXXX.c`, so every port also needs a home and a declaration.

**And the compiler is not the whole toolchain: his assembler emulation is
maspsx at `MASPSX 2.81`, where this tree runs `--aspsx-version=2.79`.** Read
off his own `attempts.csv`, which prints the version on every row. That is
exactly the layer WORKFLOW's toolchain section says the differences live in --
delay-slot insertion, `$at` expansion for non-small-data references, the
macros the assembler expands rather than the compiler emits -- so a function
that matches here can still miss there, and by a `nop`. His
`compiler_profiles.json` also carries gcc 2.7.2 profiles at `-G0` and `-G8`
alongside the 2.8.1 ones, i.e. he selects per file where this tree has one
global setting. So "same compiler" is a reason to *try* the port, not a
reason to expect it: the sentence above is about cc1psx alone, and the
calibration step below is what tests the rest.

**Nothing is offered until it has been built in HIS tree and seen to match
there.** Sending unverified C would be precisely the failure he raised in the
same conversation, that half the community tools "rely on a partial
understanding of the game". His `make match` bootstraps its own toolchain
under `tools/environments`, which is the next piece of work and is not
instant on this box.

## Order of work

1. Bootstrap his build here and reproduce his stated SHA-256
   `84a54ed7…` before touching anything.
2. Calibrate: compile a handful of functions he ALREADY matches, from his
   sources, and confirm byte-identical output. That proves the harness, not
   the port.
3. Take the smallest gap functions first — `func_80030FA0`, `func_8005C5D4`,
   `func_8004A764` — port this tree's C into his file layout, and build.
4. Only what matches there goes in a PR, in small batches, as he asked.


## Bootstrap, measured 2026-09-04

His tree builds here. What it cost, so nobody re-derives it:

* **The executable is byte-identical.** `config/slus_01411/target.yaml` wants
  sha256 `84a54ed7…` at `game/SLUS_014.11`, and our `extracted/SLUS_014.11`
  hashes exactly that. `make verify-target` passes. `game/` is gitignored in
  his tree, so nothing retail is at risk of being committed.
* **His python bootstrap pins CPython 3.10 exactly** (`tools/bootstrap/tools.json`,
  `major_minor: [3, 10]`, enforced with `sys.version_info[:2] != expected`).
  This box has only 3.14. `uv python install 3.10` provides one in three
  seconds without touching the system, and
  `make python-tools BOOTSTRAP_PYTHON=<that>` then succeeds.
* **`make toolchain-system` is unusable here**: it pins
  `binutils-mips-linux-gnu` to `2.38-1ubuntu1cross2` and Ubuntu 26.04 ships
  `2.45.90`. So the from-source `make toolchain` (binutils 2.42,
  `mipsel-none-elf`) is the only route.
* **binutils 2.42 does not compile under GCC 15**, which is Ubuntu 26.04's
  default: `opcodes/mips-formats.h:86: error: expected identifier or '('
  before 'static_assert'`, because C23 is the default dialect and
  `static_assert` became a keyword. `CFLAGS=-std=gnu17` in the environment
  builds it. This is a real portability bug in his bootstrap, reproducible in
  one command, and it is the kind of thing worth telling him — it is about a
  pin against a newer distro, not about his method.
* `make compiler-281-prebuilt` works unmodified.

## The addressing knob his profile set does not have

`compiler_profiles.json` carries sixteen profiles, and they are *better* than
this tree's flag table on one axis we only recently opened: he already has
`gcc_2_8_1_cc_g8_as_g0` and `gcc_2_8_1_cc_g0_as_g8`, i.e. the compiler's `-G`
and the assembler's `-G` set independently. WORKFLOW records that our own
`sweep_flags.py` tied the two together for months.

What he does not have is an assembler `-G` strictly *between* 0 and 8, and the
very first gap function needs one. func_80030FA0 reads two one-byte scalars
`%gp_rel` while storing to two symbols through `lui $at` — so the assembler
threshold has to sit above 1 and below the sized symbols' 4. This tree
assembles it at `-G2` (`PER_FUNC_AS_FLAGS["func_80030FA0"] = "-G2"`).

That does **not** mean the function cannot port: WORKFLOW's fourth addressing
form reaches the same bytes from the other side — an *unsized* extern array
carries no `.extern` size, so the assembler will not treat it as small data at
any `-G`, and `-mno-split-addresses` makes cc1psx emit the bare symbol for it.
That is his existing `gcc_2_8_1_g8_no_split`. Whether the two routes agree
byte-for-byte is the first thing the calibration measures, and it is the
single most useful thing to learn from this port: if they do, most of the 166
need no new profile at all.


## What the first port actually found, 2026-09-04

**He is already consuming this tree, and has been for a long time.** His
`external_attempts.csv` records 1601 `reference_match` rows against
`tmp/references/ygofm-decomp/src/func_XXXXXXXX.c`, and **1734 of those
reference paths hash to this repo's current `src/` bytes exactly, with zero
mismatches**. `tmp/references/ygofm-decomp` is us. His
`record_external_attempt.py` hardcodes exactly two reference roots --
`ygofm-decomp` and `ygofm-decomp-unchiga` -- so the three-way collaboration is
built into his tooling rather than being an idea.

That reframes the 166. They are not functions he has not seen. Of the 166,
**he has already attempted 135**, across 597 `nonmatch` and 113 `deferred`
rows, and every one of those attempts used a profile with the assembler at
`-G0` or `-G8`. Only 31 are genuinely new to him, and those are the ones
matched here since his last sync.

**So the useful thing to send is not C, it is the knob.** Cross-referencing
`PER_FUNC_AS_FLAGS` against his `unmatched_asm` set: **24 of the 166 assemble
here at an intermediate `-G`** -- nine at `-G2`, seven at `-G1`, eight at
`-G4` -- and *no profile in his set can express that*. He has
`gcc_2_8_1_cc_g8_as_g0` and `gcc_2_8_1_cc_g0_as_g8`, so the two `-G`s are
already independent knobs for him; what is missing is a value between 0 and 8.

func_80030FA0 is the worked case and it is a clean one. He spent twelve
attempts on it across both ledgers and deferred it. External attempt 6,
`gcc_2_8_1_g8_split`, **already had the correct source and the correct
compiler flags** and came out `0x2C` instead of `0x30`; his summaries read
that as store ordering. It is a small-data threshold: `-G1`, `-G2` and `-G3`
all give exact linked text, `-G4` gives `0x28` and `-G8` gives `0x2C`. PR
[#371](https://github.com/krystalgamer/memories-decomp/pull/371) carries the
function and the profile.

**The other pipeline difference, and it is the one that decides how the C is
written.** His 2.8.1 is `mips-sony-psx-gcc`, a gcc 2.8.1 *built from source*,
not Sony's `CC1PSX.EXE` (`SN32 BUILD 4.0.0010`) that this tree runs. They
differ in at least one default that matters everywhere: cc1psx emits split
`%hi`/`%lo` pairs by default, and his gcc does not -- so **his `*_split`
profiles are the default-equivalent of this tree's flags**, and a port that
does not switch to one will be an instruction short at every address
materialisation. That is a mechanical translation rule, not a per-function
question, and it should be the first thing applied to the remaining 165.

**The gate held and it was worth having.** `make match` reproduces
`84a54ed7...` in his tree on this box, so nothing goes out unverified. The
probe harness is `tmp/port/probe.py` in the clone: it imports his own
`audit_unchiga_candidates.compile_candidate` and `link_candidate`, so a
candidate is measured through *his* compiler, *his* maspsx and *his* linker,
and it sweeps every profile plus synthetic ones in about a minute.


## The portable gap is 94, not 166 -- and the first one measured does not port

Two corrections to the numbers above, both from actually working the list.

**65 of the gap functions are ASSEMBLY DEBT and cannot be offered at all.**
Filtering our `src/func_*.c` for `asm`/`__asm__` outside comments against his
`unmatched_asm` set: of 159 (it was 166; he has matched seven himself since),
**94 are pure C and 65 are transcriptions**. His `audit_unchiga_candidates.py`
raises `AuditError("preprocessed candidate contains asm")` and his
copilot-instructions require pure C, so those 65 are correctly unofferable --
they are our debt, not his gap. func_8005C5D4 was the smallest of them and is
Unchiga's transcription with three `__asm__` blocks. **Run this filter first
every time**; the raw gap number is meaningless without it.

**And the smallest pure one, func_80013B04, reaches exact length and stops.**
25/25 words under `gcc_2_8_1_g8_split`, 11 differing, all of them in the first
twelve instructions -- instructions 13 through 25 are byte-identical. The
target preserves *both* arguments in `$a2`/`$a3` before the condition and fills
the `beqz` delay slot with `lui $a1,0x10`, the first half of the 0x100010
constant; his gcc sinks the `arg1` copy into that delay slot instead and
materialises the constant afterwards. Same instructions, different placement.
Six spellings -- the `do { } while (0)` constant pin at three positions, the
sum written as one expression, and named locals for one or both arguments --
all score 11 or worse, which is the wrong-axis tell.

**The part that matters: our tree matches this function with cc1psx at default
flags and no source tricks whatsoever.** `src/func_80013B04.c` is plain C with
no guards and no `PER_FUNC_AS_FLAGS` line. So the difference is between the two
2.8.1 builds -- Sony's `CC1PSX.EXE` and his from-source `mips-sony-psx-gcc` --
in where the delay-slot filler takes its instruction from. That is the first
hard evidence that **some of the 94 will not port at any source spelling**, and
it bounds the whole exercise: the compiler difference recorded further up this
file as "a mechanical translation rule" is only mechanical for the addressing
half. Candidate and full evidence are preserved in his tree at
`tmp/port/rotated/func_80013B04.{c,diff,notes}`; nothing was written to his
ledger, because his external history for that address is already terminal at
`deferred` and `post_terminal_resolution` is only for an exact result.

## The other direction: his C ports HERE, and 67 parks fell in one afternoon (2026-09-21)

The section above measured that this tree's C does not move into his tree as a
formality. The reverse was never measured, and it is the direction that
matters once his tree reached 1134/1134 on 2026-09-21: every park here has a
matched function there. Measured on all of them in one sweep:

| | functions |
|---|---:|
| parked here (`parked/*.c`) | 107 |
| of those, `matching_c` in his tree (commit 3dfeb592f) | 105 |
| byte-identical here on the first try, no C edited | **67** |
| exact length, 1 to 6 differences | 12 |
| the rest (larger residues, 4 compile failures, 1 port failure) | 26 |

The recipe, `tools_src/port_kg.py` and `tools_src/port_sweep.py`: preprocess
his unit with his gcc from his tree (so his per-TU headers and guards are
exactly what his build saw), rename every symbol of his tree to this tree's
spelling using his `functions.csv` and `symbols.txt`, move the target
definition to the end of the unit (try_func reads the object from the symbol
to the end), prune the unit to the declarations the function reaches (a
fixpoint over the names each declaration DEFINES, not the names it mentions;
called `static` helpers are kept, other functions become prototypes), and
measure through try_func with his compiler profile spelled as a build.py row
(`-quiet -O2 -G{0,8}`, `-msplit-addresses` or `-mno-split-addresses`, any
`-fno-*`) and his assembler `-G` as the `PER_FUNC_AS_FLAGS` row. The full
build is the arbiter: try_func does not link, so a pruned unit that still
carried another TU's definition, or that referenced one of his linker-script
aliases (`D_8009B0F4_abs`, `D_8009B134_abs`, now in `config/symbol_aliases.txt`),
passed try_func and broke the link. Both are fixed in the pruner and the
build hashes `84747e64...` with all 67 installed.

Three things the sweep says beyond the count. The two pipelines agree: his
`mips-sony-psx-gcc` 2.8.1 profile and this tree's `cc1psx` 2.8.1 produce the
same bytes from the same C on 67 of 67 units tried at the same flags, so the
"C does not port between the trees" reading was about the SOURCE (types,
names, guards), never about the compilers. Five of the 67 were assembly-debt
transcriptions here, now real C. And the installed files carry HIS types
(preprocessed and pruned, in the file, with a header saying so), not this
tree's `variables.h` declarations; folding them into the shared headers is
the follow-up, and until then those 67 files are the measured state, not a
style choice.

What is left: the 12 at 1 to 6 differences are worth a look each (the
residue is usually the assembler `-G` this tree's row wants against his
profile, or a guard his unit had that the pruner cannot see). The 26 larger
ones are the parks where his source uses a structure this tree's symbol map
renames badly, or where his unit needs a `static inline` this tree does not
have; each is a port question first and a matching question second.

**Second batch, same afternoon: the 12 at 1 to 6 differences were all NAMES,
and the build takes every one of them (79 of 105).** Three residues, none of
them codegen: symbols his `c_symbols.ld` names but his `symbols.txt` does
not (`gBuildDeck_pState`, `gDuel_wBgmId` -- the port now reads all three of
his symbol files, and keeps a second name for an address that already has
its `D_` name as an alias to add to `config/symbol_aliases.txt`, which is
what `D_800E9EC8_arr` and the two `_abs` are); splat's interior symbol
against his array index (`D_8009B11C+1` for `D_8009B11D`, the same word);
and `%lo(.rodata+N)` on a jump-table load, which is try_func's renderer
(WORKFLOW already says a jump-table function has to be proven by the
build). So a port that try_func leaves at a handful of differences whose
rows are all symbol names is a MATCH until the build says otherwise, and
the build said 84747e64 with all twelve installed. `tools_src/port_install.py`
does the install; the count went 1171 -> 1182 (one of the twelve,
func_80018608, replaced a transcription, so the debt is 3).

**Third batch: the four compile failures and the port failure were three
shapes of HIS source the tool did not read (84 of 105).** A K&R definition
(`void f(id, value, word)` then `u32 id;`), which the unit splitter cut at
the parameter declarations' semicolons; one address prototyped under two of
his names with two parameter lists (an SDK header's `PACKET *` and his own
`void *`), which both rename to one `func_` and then conflict, so the first
prototype wins; and tentative definitions of the globals his TU owns
(`u8 D_8009B0A8;`, placed by maspsx `--use-comm-section` in his `_comm`
profiles), which here become `extern` because every global is a linker
symbol -- as a definition the unit lost the gp-relative form and was +12.
Five more byte-identical in the build: 1182 -> 1187. Left: 21 parks whose
port measures a real residue, and the two parks his tree does not have as C.

**Fourth batch: the 21 "larger residues" were the same tool defects, and 18
of them match (102 of 105).** Nothing in that group was a codegen question:
once the splitter, the prototype dedupe, the tentative-definition rule and
a target regex that backtracked for minutes (a unit that prototypes the
target before defining it, `(?:[^;{}]*;)*` in front of the `{`) were fixed,
the re-sweep came back 18 MATCH. 1187 -> 1202 in the build, and the
assembly debt is ZERO: the last three transcriptions were in this batch.
Left: func_80030294 (an anonymous `enum` constant the pruner does not see
as a definer), func_800222F4 (a name his `data_c.json` owns, not his symbol
files), func_8004E7B0 (a store into small data one slot early -- the
`SMALL_DATA_NOP_FUNCS` shape), and the two parks his tree has no C for.

**Fifth batch: two of the last three, and the one that stays is a build.py
question (104 of 105).** func_800222F4 declares a global his TU defines with
an initialiser and a section attribute (`u8 g[6] __attribute__((section(".sdata"))) = {0};`);
the port now strips that to an `extern` and the name gets an alias line
(`gDebugEffect_abPreviewState = 0x8009AF2A`). func_8004E7B0 was one `nop`
short: aspsx puts a nop between `mfhi $v0` and a gp-relative `sh $v0`, and
maspsx does too when it knows the symbol is small data -- it learns that
from `.comm` (his unit, where the TU owns the symbol) and never from
`.extern` (ours). His pipeline was checked instruction by instruction:
same cc1 output, his maspsx prints `nop # DEBUG: Reuse of '$2'`, ours does
not; updating our maspsx to his commit changes nothing here (the corpus
stays byte-identical at 746b895, now the pin) because the knowledge, not
the version, is what differs. `insert_small_data_load_delay_nops` treats
`mfhi`/`mflo` as a load now and func_8004E7B0 is in SMALL_DATA_NOP_FUNCS.
What stays parked is func_80030294: three local `const` arrays go into the
object's own `.rodata`, which the link discards (`.rodata referenced in
.text ... defined in discarded section`); build.py places an object's rodata
only for jump tables, so this is the same hole one class over, and it is
a build.py change, not a port question. The two parks his tree has no C
for (func_80012AE8, func_80073758) are untouched by any of this.

**And the last one (105 of 105): func_80030294's three local `const` arrays
are `D_80010250`, `D_80010264` and `D_80010274` in splat's rodata, and the
object's `.rodata` holds exactly those 56 bytes in declaration order.**
`plan_rodata` derives a hole's owner from a jump table's entries and had no
way to own a plain `dlabel` block, so build.py now has `RODATA_OWNED`, a
list of (function, blocks) pairs merged into the owner map; the hole spans
the three contiguous blocks and the compiled object's `.rodata` lands in
it, byte-identical. One trap on the way: the first spelling was a dict
keyed `"func_80030294":`, and `port_install.py` deleted that line as a
stale flag row, which is why the table is a tuple of pairs. Every parked
function his tree has as C is now in `src/`; the two parks left,
func_80012AE8 (`__do_global_dtors`) and func_80073758 (`PCread`), are
`sdk_asm` in his tree and library code by this tree's own scope rule.

**Beyond the parks: the 34 functions his tree matches that this tree never
attempted are the same route, and 15 of them went in on the first sweep
(1205 -> 1220).** They are the big ones this tree's candidate pool had left
(348 to 2319 instructions, 25.6k in total): `port_sweep.py` takes explicit
names, so the queue is `matching_c` in his tree minus `src/func_*.c` here.
First pass: func_8001B170, func_8002ACA4, func_80042188, func_80042C08, func_80045514, func_8004ADE8, func_8004CB0C, func_80051350, func_800559D4, func_80056D7C, func_8005D378, func_8006AF74, func_8006C37C, func_8006CD78, func_8006F1B4. The 19 others read as the known residues
(jump-table labels, interior symbols, rodata blocks to own) plus a pruner
gap on one typedef, one transient wine failure and a handful with real
differences to read.

**Second sweep of the 34: 11 more (1220 -> 1231), and the residues sort into
this tree's own knobs.** Two `RODATA_OWNED` pairs (func_80035E20's `s32
tbl[30]` is `D_800102B8`; func_8004DE24's `CVECTOR colors[5]` and
`BackgroundNormals` are `D_800114C4` and `D_800114D8`), five more
`SMALL_DATA_NOP_FUNCS` members (a load or `mfhi`, then a gp-relative store
of the same register, `sym+2` included -- his maspsx knows the symbol from
`.comm`, ours needs the pass), one interior-symbol alias (`D_8009B2A6`),
one pruner fix (a `} __attribute__((packed)) Name;` typedef read as a K&R
head and glued to the next unit). Two were installed on a misread of
try_func's line and backed out by the build, which is the arbiter for
exactly that: func_8001F55C is five nops short even with the nop pass, and
func_8001BD88 schedules a `lw` through a pointer above a gp-relative `sh`
where retail keeps it below, in the full unit as well as the pruned one --
a real question, not a naming one. Four GTE functions wait on his
`normalize_psyq_rtps.py` / `normalize_psyq_gte.py` assembly filters, which
his profiles apply after cc1 and this tree has no hook for yet; and
func_80028B08 differs by one `sw` moved five instructions under the same
flags in both compilers' output, which is the first codegen disagreement
between his gcc 2.8.1 build and cc1psx seen on this port.

**The two gcc 2.8.1 builds DO disagree, on three of the 34 -- measured on
the same unit through both.** `$SP/cc1_s.py`-style: run cpppsx+cc1psx the
way try_func does on the ported unit, run his `mips-sony-psx-gcc -S` with
his profile on the same file, align the instruction streams. func_8001BD88
(1130/1130, 6 hunks), func_8001F55C (1069/1069, 6 hunks) and func_80028B08
(368/368, 2 hunks): in each, cc1psx hoists a load through a pointer above
a gp-relative store (or moves one `sw` five instructions) where his
compiler keeps source order. Same C, same flags, different scheduler
tie-break between SN's build and the decompals build of 2.8.1. They are
parked with the pruned units as candidates and the diagnosis in the
header; the only way to close them here is his compiler binary, which
would be a per-function compiler knob in build.py and a decision, not a
port. func_800534B8 was the last naming residue (`D_8009B48C` as
`D_8009B488+4`) and went in on the build (1231 -> 1232).

**RETRACTED the same day: the three are a SPELLING, not a compiler (1236 ->
1239).** "The only way to close them here is his compiler binary" was
written one paragraph up and it is wrong. gcc 2.8.1's `true_dependence`
(sched.c) lets a load or store move across another memory reference only
when exactly one of the two carries the struct marking (`MEM_IN_STRUCT_P`)
at a varying address and the other is unmarked at a fixed address -- a
member access through a pointer against a scalar global. The disagreement
is in how the two front ends mark `*(T *)&p->member`: cc1psx keeps the
marking (the load is free to hoist above `sh D_8009B20C`, the store is free
to sink below `sh D_8009B1D0` into a delay slot), his mips-sony-psx-gcc
build does not, and `*(T *)((u8 *)p + K)` is unmarked in both. So the
lever is WORKFLOW's func_80013B68 / func_80049CF8 byte-address cast, one
expression per site: func_8001BD88 two copy statements (20 differences ->
10 and 16 with one site, 6 with both, all six the renderer's `sym+2`
spelling), func_8001F55C the case-8 copy's load and the 0xBF arm's store
(-1/352 -> 347 -> exact length and byte-identical; casting that arm's load
too is +1, because retail DOES hoist it), func_80028B08 the extent store
(5 -> MATCH; moving the statement after the `xy.h.y` line also matches,
the member spelling `PRM->extent.word` stays at 5). Each installed file
says in its header which statements differ from his and why, since the
provenance line otherwise claims his C verbatim. The measured shapes that
did NOT move: a named read of the copy's source before the flag store
(347 either side of the `&=`), the member spelling of the store. Not
measured: `volatile` on either side, his compiler as a knob. Every ported
function is in; `parked/` holds the two SDK stubs only.

**`volatile` measured afterwards, two-sided, from his original bodies
(2026-09-21, record only; the casts stay installed).** func_8001F55C:
volatile on the copy's source and on the `D_8009B174` store at the case-8
site, and on the copy's destination and the `D_8009B1D0` store at the 0xBF
arm, is a MATCH too -- a second spelling of the same dependence.
func_8001BD88: the same pairing closes the first site and not the second
(20 -> 4, the four being the `restore:` block's `lw 44($s3)` still above
the two `sw $zero` to `D_8009B18C`/`D_8009B188`, both marked); the load
alone marked is 14. func_80028B08: volatile on the extent store, alone or
with the `field_32` load, stays at 5 -- there the residue is not a
dependence the scheduler settles by disjointness, so volatile is inert
(WORKFLOW's func_80048F14 bound). The byte-address cast closes all three
and says what it does; it is the one installed.

**The declarations fold, step one: types (2026-09-21).** The 139 ported
files carried 1851 typedefs, 43 tag definitions and 138 forward declarations
at file scope, one copy per unit (`tools_src/kg_decls.py census`). Folding
them is mechanical only if no name has two definition texts, and the census
says 240 names, 0 conflicts -- his per-TU guards change no struct's shape in
the units this tree took. `kg_decls.py fold-types` writes
`include/kg_types.h` (236 units, first-seen order over the sorted file
names, the six fixed-width names from types.h) and replaces each file's
inline copies with one `#include`; only the ported units include it, so a
non-ported unit cannot have changed, and the build stayed at 84747e64 for
the ported ones. Two things the first run taught: an anonymous
`enum { K = 3 };` is a type unit too (it was classified "other" and the
header lost the constant two array typedefs need, 278 errors), and a
`#include` line has no `;`, so the census has to split directives out
before counting or it loses one declaration per file (139 short, exactly
the file count, which is what made it visible).

**Step two, the externs, is per-symbol and is not started.** Same census:
451 extern symbols, 46 declared two ways across the ported units (volatile
or not, `u8[4]` against `volatile u8`, a typed struct against `u16[]`), 109
absent from variables.h and 157 declared with a type variables.h does not
have; 612 prototypes, 14 disagreeing. Two shapes are possible and the choice
is the user's: arms in variables.h/functions.h selected by a per-unit define
(one declaration world, WORKFLOW's "every global once", ~200 arms to write
and each ported unit then includes common.h), or a `kg_variables.h` /
`kg_functions.h` pair included only by the ported units, arms only for the
46 + 13 internal disagreements (isolated by construction, two declaration
worlds for one binary). Either way the build is the gate per batch and the
census line is the definition of done.

**The four GTE functions: his assembly filter, ported as a per-function pass
(1232 -> 1236, and the 34 are done: 31 in, 3 parked on the compiler).**
Psy-Q's `inline_c.h` is written for DMPSX and its GTE macros emit marker
words (`.word 0x0000007f` for RTPS, `0x00000fff` NCDS, `0x0000117f` NCLIP)
that DMPSX rewrites after assembly; his `psyq_rtps`/`psyq_gte` profiles run
`tools/project/normalize_psyq_gte.py` over the `.s`. build.py and try_func
now carry the same table and the same refusal rule as
`expand_psyq_gte_markers`, applied to `PSYQ_GTE_MARKER_FUNCS` before the
other post-passes; try_func's residue for all four had been the `rtps`
sitting where a marker word was (func_80015EF4, func_80033DB0,
func_80029934, func_80034830 -- 386, 672, 351, 858 instructions). The
debt counter had to learn the marker too: a `.word` whose opcode field is
not COP2 reads as transcribed MIPS, and these four were counted as debt
until `is_debt` recognises the marker shape (four controls in the commit).

**The extern fold's shape is decided (2026-09-21): `kg_variables.h` and
`kg_functions.h`, included only by the ported units, with arms only for
the 46 + 13 internal disagreements.** The 46 extern disagreements were
measured into their axes, and every one of them is a codegen knob this
file already documents rather than an accident: **14** are the `.data`
attribute (the fifth addressing form), **13** a type or width, **9**
`volatile`, **9** array-versus-scalar, **1** `const` (the sixth form,
D_80011434). So the arms are not tidying: two ported units really do want
that symbol spelled two ways, which is what `variables.h`'s own per-file
guards already say for the same addresses. The 13 prototype disagreements
are the opposite: **12 are cosmetic** (parameter names, `int` against
`s32`, `struct X *` against `X *`) and one declaration serves both once
the build says so, and exactly **one** is real -- `func_8002348C`, typed
`(DuelFieldDisplaySource *)` in one unit and `(void)` in another, which
is the missing-prototype case WORKFLOW documents on func_80017F04 and
must stay two declarations.
**When you re-count these, do NOT normalise `__attribute__((...))` away.**
Stripping it makes the 14 `.data` pairs read as a difference of one space
before the semicolon, i.e. as noise to be collapsed, and collapsing them
is a silent codegen change. (The suspicion that the census's non-greedy
`__attribute__\s*\(\(.*?\)\)` was inflating the count was checked with a
balanced-paren stripper and four controls, and it was **unfounded**: both
give 46 and 13. The instrument was right; the reading of its output was
the thing at fault.)

**DONE, 2026-09-21, in three batches against the full build.**
`kg_decls.py fold-externs [N]` folds the first N agreed symbols, so each
batch is measurable; 100, then 400, then the remaining 501, and the build
hashed `84747e64` after every one. `include/kg_variables.h` ends at 422
lines and `include/kg_functions.h` at 706, included only by the ported
units exactly as `kg_types.h` is. The census went 450 extern symbols
inline to **47** and 612 prototypes to **14**, against 46 and 13
disagreements -- and the one extra of each is not a leftover: a unit is
folded only when EVERY name it declares agrees, so a symbol that agrees
but shares its declaration with a disagreeing neighbour rides along
inline. That was checked rather than assumed: **zero** inline units
declare only agreeing names.
Two things worth keeping from the doing of it. The header write has to be
**additive** -- a later batch only sees what is still inline, so
rewriting the header from that deletes every declaration an earlier batch
moved there and leaves those symbols undeclared; the control is that the
files grow (56 and 76 lines, then 221 and 354, then 422 and 706) instead
of shrinking. And the hazard to measure BEFORE folding prototypes is a
unit that calls a function it deliberately does not declare, which is
WORKFLOW's missing-prototype case: of 1061 names, six were mentioned by a
unit that declares nothing for them, and five of those were prose in a
provenance header or a `goto` label the name regex matched, the sixth an
`asm()`-labelled view of a symbol that disagrees anyway. No new case, so
the fold could go in batches at all. WORKFLOW's "every global once" exists
to stop silent codegen drift between files, and for the ported units that
hazard is closed by the build gate rather than by header unity; the ported
units are his type world and the header says so, the way `kg_types.h`
already does. It folds mechanically into `variables.h` arms later if that
is ever wanted. It is second priority behind the Japanese lane below, which
is matching work with a live race; the fold is style.

## The Japanese build, from here (2026-09-21)

His tree's SLPM-86398 lane (#5551) reuses the US `.c` files: a Japanese
match is three config lines per function -- `config/slpm_86398/matching_c.json`
entry, a `split.yaml` subsegment pair, and `symbols.txt` lines
`USName = 0xJPaddr;` for every symbol the unit reaches at a different
address (function names come from `config/slus_01411/functions.csv`, which
is what the C defines; three link errors said so on the first try).
`tools_src/jp_promote.py scan|apply 0xUSaddr` derives all of it from the
bytes: the US words of the unit and the JP words at the paired address are
compared word by word, and a differing word must be a `lui`/`lo` half, a
gp-relative offset or a `jal`/`j` target, each yielding one symbols line;
any other difference means the code is not the same and the unit is
skipped. Pairs come from the issue's list (`config/jp_matches.csv`,
address = JP, address2 = US), and a function the list lacks is inferred
from a paired neighbour by contiguity and then judged by the same
comparison. Named symbols at an EQUAL address are recorded too, because
JP splat only auto-labels `D_`/`func_` names; a `D_` name at an equal
address that the link still wants is one `symbols.txt` line and a retry,
never a non-match verdict. Units with a US `.rodata` subsegment are
flagged and not applied -- the comparison covers `.text` and the JP table
placement is not derived. First scan at his dd9cd44: 73 clean units of 118
queued (four merged upstream during the analysis: his agents run this lane
too, so fetch, reset and rescan before every apply). The only proof is
`make japanese-match` on the exact tree (`MATCH tmp/project-build/SLPM_863.98`,
sha `ee3f4558…`, 13 s); the first PR is #5632. `tools_src/variants.py`
(exact substitutions, try_func in parallel, outputs under `build/variants/`)
is the instrument the three-park closure above was measured with, and it
lives here for the same reason: a scratch directory does not survive a
reboot, and both tools are load-bearing now.

**What the first batch of ten measured (2026-09-21, all on the gate).**
Three classes the word comparison cannot see, each first read as a
non-match and each a tool gap:
  * **A US default name collides with the JP build's own default name.**
    `D_8009B314` in the US is at 0x8009B204 in the JP executable, but JP
    splat also labels *its* 0x8009B314 `D_8009B314`, and the linker keeps
    splat's definition: sorted_entry_relink built `lo 0xB314` where the JP
    bytes have `0xB204`, in a function the unit does not even contain. The
    same wall in a second shape: a JP address that `symbols.txt` already
    names refuses a second name ("clashes with gJapanese_bActiveMainMode").
    His tree's answer is the regional-alias wrapper, `src/game/japanese/
    <unit>.c`, with `#define USname JPname` above the headers; the tool
    writes one (types.h first, because `make basic-types` insists, then the
    defines, then `#include "../<unit>.c"` -- the US source included, not
    copied, which is the one place this departs from his five hand-made
    wrappers) and names the JP side `gJapanese_<USname>`, or reuses the
    name JP already has. The JP data block around 0x8009B1xx-B4xx sits
    0x110 below the US one, so this is the common case, not the odd one.
  * **An equal word still names a symbol.** Through `gp` it is the same
    offset from a different `gp` (US 0x8009AF08, JP 0x8009AE48), so the
    symbol moved by -0xC0 and needs its line; through a `lui`/`lo` pair
    with equal halves it is an equal address that a *named* symbol still
    needs declared, because JP splat only auto-labels `D_`/`func_` names
    (`undefined reference to gDuel_awPlayerDeck`).
  * **A stale `lui` entry pairs a displacement off a LOADED pointer as a
    symbol half** (`D_FFFF0058`, which splat could place nowhere). The
    register a word writes now drops its `lui` entry, one word late because
    `lw $v0, lo($v0)` reads the base first.
Two classes stay out until they are worth a source change in his tree: a
US name defined only in `config/slus_01411/c_symbols.ld`
(`D_800E9EC8_arr`, fade_runtime), which the JP link never sees, and an
address spelled as a *literal* in the C (mem_card_io_result_callbacks
writes `(u8 *)0x800A0000 - 0x4BB0`), which no symbol line can move.
And the race is the dominant cost: his agents merged nine Japanese PRs in
the hour the first one here was open, every one on the same three files,
so the PR was merged with master four times (take master's three files,
re-apply the unit, re-gate, merge commit -- never a rewrite of a reviewed
head). A batch of ten pre-verified units waits on a local branch for the
first to land, one PR open at a time.

**And the race is won on LATENCY, not on content -- the advisor's reading
after six re-merges landed nothing.** His agents detect a landing, rebase and
go green in about four minutes; a cycle of "poll up to a minute, run four
minutes of gates, push, wait three and a half minutes for CI" reaches
mergeable-and-green after the next landing has already happened, so it loses
every round by construction. Three changes fixed it and the next PR landed:
drop the 130-second unittest suite from a *re-merge* (the diff is the same
additive lines already verified, and CI runs the suite anyway), wake on the
event instead of a heartbeat (a Monitor on `git ls-remote origin master`),
and make the re-merge one script with no thinking in it. The re-merge now
pushes about 40 seconds after a landing. Two other things the race teaches:
**two landings can each declare the same `jal` target, and master's own
`japanese-split` then fails** on splat's "Duplicate symbol detected" (#5593
after #5649 on `DisplayObject_SavePosition`) -- the merge drops the duplicate
line and says so; and **his open PRs are named by Japanese address or
function and take ONE function of a multi-function unit**, so overlap is only
visible by comparing the addresses each open PR adds to `matching_c.json`,
never by file name (four units left one batch that way).

**Two blocked classes, both measured, and both the same answer: an
INCLUDING wrapper cannot reach them.** The wrapper this tree writes
`#include`s the US source under `#define USname JPname`; that reaches a
symbol whose US name is simply taken in the Japanese build, and nothing
else.
  * **An object with two US names that the unit uses both of.** 76 addresses
    carry more than one US name, and the second usually lives in
    `config/slus_01411/c_symbols.ld` -- which the US link takes
    (`build_baseline.py`) and the Japanese link does not. `fade_runtime`
    reads 0x800E9EC8 as `gFade_State` and as `u8 D_800E9EC8_arr[]`; the
    Japanese address 0x800E9DA8 already answers to `gJapanese_FadeState`,
    and `symbols.txt` refuses a second name for one address, so both US
    names have to become that one identifier. That does not compile:
    `conflicting types for 'gJapanese_FadeState'` at `fade.h:12`. So the
    tool REJECTS the unit with that reason rather than writing a wrapper
    that fails, which keeps "the scan says clean" equal to "this builds".
    31 functions, the largest unit left, and only a copied wrapper reaches
    it.
  * **An `asm` label.** `sound_output_state` reaches the sound root through
    `extern SDValue *volatile g_SDValue_output_level asm("g_SDValue");`, and
    the label is a string that `#define` does not rename, so the alias never
    applies and the link asks for `g_SDValue`. One unit of the queue has
    this shape, and 14 US sources carry an `asm` label at all.
Which is to say the including wrapper was the right default and is not
universal; the five wrappers his tree already had are copies, and that is
the route for these two if he wants them.

**And the name the tool SYNTHESISES is not the name the source uses --
which turned one of those two "classes" into a bug of mine.** `symbols.txt`
does not name every address, so the promoter falls back to `D_<addr>`; when
the unit's own C calls that address something else, the second name is not
a disagreement, it is the only real name. `card_list_sort` reads
`gBuildDeck_pState` twice and `D_8009B2FC` **zero** times -- not even in a
comment, because that name exists only as an alias in
`config/slus_01411/c_symbols.ld` and has no C declaration anywhere -- and
the tool was rejecting the whole unit for a type conflict that cannot
exist. The rule now: count the address's US names that appear in the unit's
CODE, with comments stripped (a provenance header naming a sibling, or a
`goto func_80073900;` label, reads as a reference and is not one -- five of
six such names were false), emit the line under the one name the code uses,
and refuse only at two or more. With that, `card_list_sort` promotes and a
clean `make japanese-match` matches; it is shelved only because two of his
open PRs claim its range.
Two habits fall out of the same afternoon, and both are about believing an
instrument that measured something adjacent. **A pinned three-number diff
shape is wrong for `symbols.txt`**: when upstream lands a PR declaring a
function this batch reaches by `jal`, the re-apply correctly stops writing
that line and the count drops -- and the same fact makes the CI fail, since
checks run the head MERGED with master where both copies exist, so the
re-merge is the cure rather than the symptom. **And a local
`japanese-match` run incrementally cannot see what a clean split sees**, so
a clean `make clean && make japanese-match` belongs once per PR even though
the fast incremental gate is what keeps the re-merge cadence under a
minute.

## The absorption: a landed single-function unit forecloses its whole TU

Measured 2026-09-21 18h. His agents match one function at a time, and when a
function's translation unit cannot be wrapped as a whole they write that one
function out by hand as its own Japanese unit -- `src/game/japanese/sd_clear_busy_flag.c`
is sixteen bytes of hand-written C, `gJapanese_SDValue->busy = 0;`, where the
other six functions of the same US TU stayed as assembly. krystalgamer noticed
the shape himself ("i see for jap decomp it's breaking down the TUs again") and
left it.

**That single entry blocks the whole TU, permanently, by construction.** A
regional-alias wrapper `#include`s the shared US source, so the object carries
every function the TU defines; the split `c` line has to cover all of them, and
the landed single-function entry overlaps that range. `jp_promote.py` reports it
as `already in JP matching_c` -- which reads exactly like "somebody already did
this unit" and means the opposite: one seventh of it is done and the other six
sevenths are now unreachable by the cheap route.

The way back is to **absorb**: remove the single-function manifest entry, its
split line and its hand-written file, then promote the whole unit. Measured on
`sound_output_state`: 7 functions, `make clean` then `make japanese-match` gives
MATCH at sha256 ee3f4558, the US side untouched, and one hand-written copy of
shared logic deleted. `SD_ClearBusyFlag` keeps its address and its symbols line
-- it is now compiled from the shared source instead of a copy that could drift.
`$SP/jp_remerge6.sh` does the re-merge for this shape, and it CANNOT be
`jp_remerge.sh`: that one takes master's three config files wholesale, which
silently restores the entry the patch removes, and the re-apply then refuses.

**The census, because it is the whole remaining mechanical lane.** Nine units
pair cleanly against the Japanese bytes and 40 functions sit in them; every one
is held by one or two claimed addresses from an open PR of his, each PR taking a
single function: display_effect_update_callbacks 7 (#5628), file_transfer_flags 7
(#5636), save_data_payload 9 (#5652), display_effect_lifecycle 5 (#5626/#5625),
card_list_sort 4 (#5619/#5635), sorted_entry_relink 2 (#5600), func_8001B7AC 2
(#5627), duel_deck_lookup 2 (#5607), display_object_fade_helpers 2 (#5595). As
each lands, that unit enters the state above and needs an absorption.

**And the lesson about the instrument, which is this file's recurring one:** the
refusal was read for three ticks as the wrapper problem I was expecting, and
published twice as "waiting on the maintainer's decision". The early-return
branch carries no addresses, so the collision was invisible until the derivation
was replicated by hand -- `analyze` returns `dict(ok=False, why=...)` and nothing
else. A rejection that names no address is not a diagnosis.

**The same build also settled the asm-label precedence question**, which had been
published as a second thing needing his decision. The source declares
`extern SDValue *volatile g_SDValue_output_level asm("g_SDValue");` and a
`#define` cannot rename a string literal -- so the wrapper pre-declares the same
identifier with the Japanese label, and that one binds: gcc 2.8.1 makes an
extern's RTL at its FIRST declaration and does not discard it on redeclaration
(`varasm.c`, `make_decl_rtl`). No copied wrapper, and no US header change.

### Three corrections to the absorption entry, all from one afternoon

**"Forecloses permanently" was too strong, and his own #5695 is the
counterexample.** His route for taking one function of a shared unit is NOT a
hand-written copy -- that was one instance. It is **region guards in the shared
US source**: `#if !defined(VERSION_JAPAN) || defined(VERSION_JAPAN_<GROUP>)`
around the function being taken, `#ifndef VERSION_JAPAN` around the rest, and a
Japanese wrapper that defines both macros before including the source. So a
landed single function blocks only the WHOLE-UNIT wrapper, and the remaining
functions stay reachable by a wrapper that defines `VERSION_JAPAN` plus the
opt-in macros for exactly those. Two exits, not one: absorption (fewer units,
deletes hand-written copies, needs his agreement because it removes his entry)
and region guards (nothing of his removed, more units, region machinery in the
source). He asked for absorption on #5697. Both claims were corrected publicly.

**Absorbing means removing every split boundary STRICTLY INSIDE the range, not
just the absorbed unit's `c` line.** #5695 shipped `[0x34f28, c,
game/japanese/func_8004503C]` and `[0x34f40, asm, func_80044740]`. Removing only
the first leaves that asm range assembled beside the wrapper's own objects, and
the link fails with `multiple definition of func_80045334`, the same for
`SD_ClearBusyFlag`, and a `.initialized_data` / `.main` VMA overlap behind them.
Derive the range from the manifest (min address, max address+size, minus
0x80010000 plus 0x800) and drop every boundary between the ends.

**A LINE COUNT CANNOT EXPRESS THE MANIFEST INVARIANT.** Absorbing two entries
and adding seven is arithmetically +42 -12, and git renders it **+37 -7**,
because it coalesces identical lines when an insertion sits adjacent to a
deletion -- both describe the same net 30. The re-merge asserted the arithmetic
and failed a correct tree. Assert on the PARSED manifest instead: exactly seven
entries for the unit, no repeated address anywhere, each absorbed unit absent
from the manifest and from disk. Same family as this file's rule about reading a
census rather than a length.

**And the absorbed-address filter must be able to say yes.** The first version
uppercased the address, turning `0x80044B38` into `0X80044B38`, so the manifest
regex matched nothing and the script printed "no longer in master's manifest --
nothing to remove" and carried on to a patch that duplicated an address. Every
removal now carries a positive control: if the plain address string is in the
file, the entry regex MUST match exactly once, or the run fails.

### Finding the absorbable units, and four traps in doing it

**The promoter's `already in JP matching_c` hides the whole remaining seam.** It
means two different things: a unit fully promoted, and a unit where one or two
functions landed as units of their own and the rest are still assembly. Counting
them apart (derive each US unit's JP addresses, count how many are in the JP
manifest, keep `0 < landed < total`) gave **ten partially-promoted units on
2026-09-21**, none of them claimed by any open PR, holding 86 functions. The
word-level comparison had never run on one of them, because the occupancy check
refuses first: run `analyze` with the occupancy map EMPTIED to get the pairing
verdict, with controls at both ends (a unit known to pair must say ok, a unit
known to differ must not). Five pair cleanly, five differ in code.

**A symbol declared only in a C header has no name for the promoter to emit, and
the fix is an alias, not a symbols line.** `display_object_runtime` calls through
`gDisplayObject_ListRenderers`, defined in another TU that the JP build does not
compile, so the link says `undefined reference`. The promoter saw the difference
(US `0x24420fb0` against JP `0x24420e60`, the table shifted -0x150) and had
nothing to write, because no config names `0x80090fb0`. Adding
`gDisplayObject_ListRenderers = 0x80090E60;` is WRONG: that address is already
named `D_80090FB0` and splat refuses a second name for one address. The wrapper
renames the identifier instead -- `#define gDisplayObject_ListRenderers
D_80090FB0` -- and the header then declares the name the linker already knows.
Decode the address from both executables at the site the linker names
(`.text+0x5d0` is word 372 of the unit); do not assume the table is unshifted.

**A per-unit script CANNOT be correct when each run re-takes master's config.**
Running an absorb-one-unit script twice on one branch silently undid the first
unit's absorptions, because step one is `git checkout origin/master -- <config>`
and master still carries every landed single-function unit. The second run then
restored four entries beside the branch's own whole-unit `c` line, splat
regenerated their nonmatching stubs, and the assembler met `glabel` with no
macros. That reads exactly like a stale artifact, and wiping `tmp/splat` changes
nothing. **Declare the batch once and apply it once**; the driver resets to
`origin/master` and redoes everything, so it doubles as the re-merge.

**Removing the LAST manifest entry leaves a dangling comma** before the closing
bracket and the file stops being JSON. `re.sub(r',(\s*\])', r'\1', t)` after
each removal is a no-op on valid JSON and fixes it.

**The overlap check must count ABSORBED addresses, not only free ones**, and its
control must fit what it measures. An absorbing PR is the wrong positive control
for a pure-addition harvest: it re-adds the addresses it absorbs, so those lines
are unchanged CONTEXT rather than additions (6 of 7 rows, not 7). The control
that works is that every open "Match Japanese" PR contributes at least one
manifest address, exempting the PRs that are not matching PRs at all. On
2026-09-21 the race removed two of three units from one batch between building
and pushing: #5654 claims an address one unit absorbs (and is itself stale --
that address is already in master), and #5705 opened minutes before the push and
claims a free address in another.

### The Japanese queue was never exhausted: the PAIR LIST was stale

Measured 2026-09-21 20h. Every "the mechanical queue is empty" line written
about the Japanese lane was an artefact of `config/jp_matches.csv`, which
`jp_promote.py` starts from. That file was written by hand in one commit
(4a0f518) and never regenerated, while his US config moves under it daily.
Against his master that day: **306 entries, 127 naming a US address that no
longer exists, and 351 US units with no coverage at all.**

**The mechanism is his translation-unit splitting, and it removes units
silently.** #5600 split `sorted_entry_relink.c` from two functions to one; the
function that moved out carried the unit's only pair entry, so the remaining
unit began reporting `no function of the unit has a JP pair` -- which reads as
missing data and is an upstream reshape. Any unit can leave the queue this way
without anything going red.

**`tools_src/jp_pairs.py` recovers them, and it is self-verifying.** Both
executables lay the same code out in the same order, so the displacement between
a US function and its counterpart is locally constant and changes only at region
boundaries. For an uncovered unit: take the displacement of the nearest known
pair and its two neighbours, predict the target address, and hand the two word
streams to `pair_words` -- the SAME check the promoter runs before writing any
config. A wrong prediction therefore yields no pair rather than a wrong one.
First run: **223 units, 384 functions recovered**, against 316 Japanese
functions in the whole of master at that moment.

**The negative control is the part that makes the number mean anything**, and it
is built into the tool (`--check`, implied by `--write`): a sample of the
recoveries is re-tried at the predicted displacement off by one instruction,
minus one instruction, and off by the whole first function. **120 deliberately
wrong displacements, 0 wrongly accepted.** Without that, "223 recovered" is a
method that has never been shown capable of saying no -- which is the failure
this file already records for the `lui $at` grep and the park filter.

The deltas cluster by region exactly as a correct alignment should: `-0x13f0`
across every `ai_script` unit, `-0x920`/`-0x914`/`-0x944` across sound,
`+0x2e30` across the file and model-scene units.
