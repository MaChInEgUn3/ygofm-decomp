# Yu-Gi-Oh! Forbidden Memories — Matching Decompilation

Matching decompilation of the PS1 game *Yu-Gi-Oh! Forbidden Memories* (NTSC-U,
`SLUS_014.11`), in the same style as
[OpenDriver2](https://github.com/OpenDriver2/REDRIVER2),
[sotn-decomp](https://github.com/xeeynamo/sotn-decomp) and
[mgs_reversing](https://github.com/FoxdieTeam/mgs_reversing): the goal is
byte-exact C recompilation of the original executable using the original PsyQ
SDK toolchain — **not** a reimplementation. Every function must assemble to the
retail bytes.

## Status

| | functions | instructions |
|---|---|---|
| decompiled and matching | **817** (72.8%) | **28,175** (34.4%) |
| remaining | 305 (27.2%) | 53,703 (65.6%) |

Both columns are worth reading, because they disagree sharply. Function count
is well past halfway; **instruction count is not, and it is the honest
number.** The functions matched so far average 32 instructions and the ones
remaining average 173 — the short bands get emptied first and refill only when
a rule is retracted. Scope is the 1,122 game functions below `0x80073840`,
excluding PsyQ library code (`docs/LIBRARY_FUNCS.txt`) and hand-written
assembly (77 GTE-block functions, filtered by `candidates.HAND_WRITTEN`). An
earlier revision of this table said 1,198: that number excluded the library
list but not the hand-written block its own caption claimed to exclude — the
same skipped-filter class `docs/WORKFLOW.md` documents for the `lui $at` pool
miscounts.

`src/` holds 869 files; 817 of them are in scope and the rest are library or
above-scope functions matched along the way.

### Where the remaining work is

| size (instructions) | remaining | parked | unclaimed |
|---|---|---|---|
| ≤ 25 | 20 | 20 | **0** |
| 26–50 | 59 | 59 | **0** |
| 51–100 | 64 | 64 | **0** |
| 101–200 | 77 | 61 | 16 |
| 201–400 | 58 | 1 | 57 |
| > 400 | 27 | 0 | 27 |

**The short bands are exhausted.** Every remaining function up to 50
instructions is already parked, which is why `tools_src/candidates.py` reports
zero clean candidates in its default band — that is the tool being correct, not
broken. As of this revision the lowest unclaimed function is **150**
instructions: everything shorter is either matched or parked, and the bulk of
what is left is the 101–200 band.

"Parked" means a candidate is known to be close but not exact, with a
per-function diagnosis in `docs/PARKED.txt` and, for 201 of them, the actual
candidate in `parked/`. These are a source of matches rather than a graveyard:
a park records that a shape was not found, not that none exists, and re-reading
them whenever a new lever is measured has repeatedly produced matches years
into the same file.

Every number in this section is derived, not typed:
`.venv/bin/python tools_src/status.py` prints them and `--write` rewrites the
two tables in place. Run it in the same batch as `tools_src/sync_count.py`
before committing. It imports candidates.py's scope filters rather than
restating them, because both of the past miscounts in this repo came from an
ad-hoc scan that skipped a filter the tool already applied.

## What is and is not committed

**The disc image, the extracted executable, and the downloaded toolchains
(PsyQ SDK, Ghidra, binutils) are never committed.** You need your own
legally-owned copy of the disc and your own copy of the PsyQ SDK to build or
verify anything here. `asm/data/carddata.data.s` (~27 MB of mostly zero
padding) is gitignored too, so **a fresh clone cannot reconstruct the
executable** — you regenerate it from your own dump with splat.

The disassembly and decompilation output (`asm/`, `src/`) **is** committed, as
in every comparable project. Publishing disassembly of a binary you do not
redistribute is long-standing practice in the PS1 decomp community and is
distinct from redistributing the binary or its media assets.
`docs/DECISIONS.md` records the exact line between what is in and what is out.

## Building

The build reproduces the retail executable **byte for byte** (sha1
`84747e64f6da8e764206ec203e489acf8c9dcf7d`). That check is the whole regression
suite: if it passes, nothing has drifted.

It exits non-zero on any failure, so **check the exit status, not the last
lines of output** — piping through `tail` reads as green when the build died
early, because the last thing printed is then the function count.

```
.venv/bin/python tools_src/build.py && echo GREEN
```

A fresh clone cannot build until you supply the game and the toolchains:

1. **Provide the executable.** Dump your own disc and extract `SLUS_014.11`
   from it.
2. **Fetch the toolchains** into `tools/` (gitignored, and must be re-fetched
   per machine): the **PsyQ 4.5** SDK, MIPS binutils,
   [maspsx](https://github.com/mkst/maspsx),
   [decomp-permuter](https://github.com/simonlindholm/decomp-permuter) and
   [m2c](https://github.com/simonlindholm/m2c). See `docs/DECISIONS.md` for exact
   sources and expected paths. The PsyQ binaries are 32-bit Windows
   executables; `build.py` runs them under Wine on Linux and natively on
   Windows, and the two are byte-identical (verified by hashing `cc1psx`
   output on both).
3. **Set up Python tooling** — always the project-local venv, never a bare
   `pip install`:
   ```
   python3 -m venv .venv
   .venv/bin/pip install "splat64[mips]"
   ```
4. **Generate the disassembly** from the repo root:
   ```
   .venv/bin/splat split config/SLUS_014.11.yaml
   ```
   Required even though `asm/` is committed, because the large data dumps are
   gitignored and the linker script references them. Safe to re-run at any
   time — decompiled sources live in per-function `src/func_*.c` files that
   splat never touches.
5. **Build and verify** with the command above.

On Windows the venv paths are `.venv/Scripts/python.exe` and
`.venv/Scripts/splat.exe`; `build.py` detects the platform and picks
`mips-linux-gnu-*` or `mipsel-none-elf-*` accordingly.

### Toolchain

**PsyQ 4.5** (gcc 2.8.1, aspsx 2.79), not 4.6. 4.6 was assumed for the first
219 functions and produced a byte-identical build anyway, because most
functions are too small for the two versions to differ; `func_800495A4` is the
discriminating case. `YGOFM_PSYQ=46` selects 4.6 for comparison. Pipeline is
`CPPPSX → CC1PSX → maspsx → as → ld → objcopy`.

Layout is linker-driven and load-bearing: `build.py` emits one object per
decompiled function plus one per run of consecutive undecompiled ones, then
rewrites splat's linker script to place them in order. This is because `-G8`
makes cc1psx defer all C function output to the end of a translation unit, so
mixing `INCLUDE_ASM` with real C in one file scrambles `.text`.

## Decompiling a function

**Start with `tools_src/m2c_draft.py func_XXXXXXXX`.** It runs
[m2c](https://github.com/simonlindholm/m2c) over the splat listing and prints
structurally-correct C in about a second: loop and switch shapes, case
groupings, reciprocal multiplies read back as ordinary division, field offsets,
load signedness. Measured on a random 60 of the open in-scope functions it
drafts 60 of 60. It has also caught things a hand-read missed — that
`func_8004A940` takes four parameters and returns a value, not two and void.

It closes no matches. Everything in `docs/WORKFLOW.md` — which register holds a
value, where a `lui` sits, whether a store sinks into a delay slot — is
invisible to it, and that is where the time goes. Treat it as the draft you
would have typed.

Then write `src/func_XXXXXXXX.c` and rebuild — placement is automatic.

**Read `docs/WORKFLOW.md` first.** It is the operational minimum: the ordered
list of what to check when a function does not match, the four global
addressing forms and how the `-G` size threshold picks between them, and the
source-shape levers that have actually been measured on this binary.
`docs/DECISIONS.md` is the long-form reasoning behind those rules, including
the ones that were retracted.

Both documents are written to a specific standard that is worth knowing about
before contributing: **a claim about mechanism has to name the counterexample
that was checked, or say explicitly that it was not established.** Every
"cannot match" filter this project has written has eventually been retracted —
six of six — each one reasoned from a couple of samples instead of counted.
If a claim is about the whole binary, scan the whole binary.

### Tooling

| tool | what it does |
|---|---|
| `build.py` | full build + sha1 verify; the only arbiter |
| `try_func.py` | fast single-function loop, no full rebuild |
| `check_try_func.py` | validates try_func both ways: every `src/` file must MATCH, every `parked/` file must not |
| `candidates.py` | ranked list of remaining work, with tags (`dup-%hi`, `[MERGED]`, `[PARKED]`) |
| `siblings.py` | pairs each unmatched candidate with the decompiled function it most resembles, on instruction n-grams |
| `m2c_draft.py` | first-draft C for one function, via m2c; start here |
| `permute.py` | wraps decomp-permuter; mandatory below ~25 instructions before parking |
| `sweep_try.py` / `sweep_flags.py` | flag sweeps, the fast one through try_func and the confirming one through the build |
| `sync_count.py` | derives the function count; run before committing a batch |
| `status.py` | recomputes the Status tables above from the tree; `--write` rewrites README.md |
| `disc.py` | reads the retail CD image and measures MIPS density per file; answers "is there code outside the executable?" |
| `sweep_guards.py` | tries every per-file declaration guard against each parked candidate |
| `sweep_borrow.py` | tries every same-type local-name substitution, block by block; mechanises the borrow lever |
| `score_permuter_outputs.py` | re-scores every stored permuter output through try_func |

## Layout

- `docs/` — `WORKFLOW.md` (operational), `DECISIONS.md` (reasoning),
  `PARKED.txt` (per-function diagnoses), `DISC.txt` (what is on the retail CD,
  and why the 24 off-executable `jal` targets are not the next thing to do),
  `EXTERNAL_LEADS.txt` (naming guesses from outside this repo, all UNVERIFIED
  and never used to justify a line of C), function inventory, RAM/ROM map
- `src/` — matched C, one file per function (`src/func_XXXXXXXX.c`)
- `parked/` — best-known-but-not-matching candidates, paired with `PARKED.txt`
- `include/` — `variables.h` and `functions.h`; every global and every
  cross-file function is declared once, because two files disagreeing about a
  type breaks matching somewhere far away
- `asm/` — disassembly (`asm/nonmatchings/` per function, `asm/data/`)
- `config/` — splat config and the generated linker script
- `tools_src/` — the tooling above, plus `ghidra_scripts/` (Java) and
  `hooks/pre-push`, which refuses to rewrite already-published history.
  `.git/hooks/` is not tracked, so install it after cloning:
  `ln -sf ../../tools_src/hooks/pre-push .git/hooks/pre-push`

## License

Deliberately split, and there is no repository-root license file because a
single one would claim more than this project can.

- **`tools_src/` is MIT** — see `tools_src/LICENSE`. The build harness and the
  matching tools are original work, and several of them (`try_func.py`,
  `siblings.py`, the flag sweeps) are useful to any PsyQ-era decompilation.
  Take them.
- **`asm/` and `src/` are not licensed by this project.** They are derived
  from a copyrighted executable and are published as reverse-engineering
  research. Nobody here is in a position to grant you rights to them.
