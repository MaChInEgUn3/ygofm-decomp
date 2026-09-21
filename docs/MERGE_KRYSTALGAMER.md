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
