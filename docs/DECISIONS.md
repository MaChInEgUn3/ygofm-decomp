# Decisions & confirmed facts

Single source of truth for project state. Update this whenever a decision changes or a new fact is confirmed — this file (plus the rest of `docs/`) is meant to let anyone (or any future agent session) pick the project back up without re-deriving everything from scratch.

## Scope decision

**Matching decompilation, not reimplementation.** The goal is byte-exact recompilation of the original executable against the original PsyQ toolchain, in the style of OpenDriver2/sotn-decomp/mgs_reversing. A reimplementation (new code, equivalent behavior, not byte-matching) was explicitly considered and rejected.

## Legal posture

**Never committed:** the disc image (`.ccd`/`.img`/`.sub`), the extracted executable, original game assets (`MRG`/`STR`/`XA`), and downloaded toolchain binaries (Ghidra, the PsyQ 4.6 SDK). Anyone building/verifying against this repo needs their own legally-owned copy of the disc and their own copy of the PsyQ SDK.

**Committed:** disassembly output (`asm/`, `src/`) as it's generated/matched. This is the actual deliverable of a matching decomp project, and every comparable project (sotn-decomp, mgs_reversing, OpenDriver2) commits exactly this — publishing disassembly of a binary you don't redistribute is standard, long-tolerated practice in this community, distinct from redistributing the binary/media assets themselves. One exception for now: `asm/data/carddata.data.s` (~26MB, mostly zero padding — see the "trailing region" note below) is gitignored until we know what's actually in it; not worth the repo bloat yet.

This is the same posture that has kept OpenDriver2, Severed Chains, and sotn-decomp alive under Konami's historically aggressive C&D pattern. GitHub repo is **private** for now.

## Target executable

- Region/version: **SLUS_014.11** (NTSC-U) — matches the version DataCrystal's community RAM/ROM maps target.
- Entry point: `0x800129d8`. Load address: `0x80010000`. Image base used by Ghidra: `0x80000000` (2MB PS1 RAM).
- Executable size: 1,902,592 bytes (incl. 2048-byte PS-EXE header) → 1,900,544 bytes of actual code/data.
- Disc `DATA/` layout (confirms community documentation): `MASTER.XA`, `MODEL.MRG` (351MB — card 3D models), `MOVIE.STR`, `SD_BGM.DAT`, `SD_SE.DAT`, `SU.MRG`, `WA_MRG.MRG`. Single session, single Mode 2/2352 data track — no CD-DA audio tracks, no unusual copy protection observed.

## Toolchain

- **PsyQ SDK version: 4.6.0**, auto-detected by `ghidra_psx_ldr`'s real signature-matching engine (`DetectPsyQ`) during headless import — not just narrowed to a family, an exact version.
  - A homemade regex-based fingerprint (bypassing Ghidra) had only narrowed this to "PsyQ 4.x family" and was later confirmed unreliable for anything more precise (match rate was ~flat across all versions — mostly shared-prologue noise). Do not resurrect that approach; trust the plugin's detection instead.
  - ~~**CONFIRMED: cc1/assembler is PsyQ 4.6.0 too**~~ — **this was wrong; see "The compiler is PsyQ 4.5, not 4.6" below.** The evidence was decomp.me (https://decomp.me/scratch/VnW0l) exposing `\backend\compilers\ps1\psyq4.6\cc1psx` for the preset "gcc 2.95.2 + aspsx 2.86 (CCPSX)". That shows which binaries *that scratch* used, which is a configuration someone chose, not a measurement of this game. Left in place rather than deleted, because the reasoning error is the useful part: "the tool names the version" was mistaken for "the version is verified". aspsx 2.86 is unaffected and still correct.
  - Note for future function-matching work: decomp.me's Cloudflare bot-challenge ("Just a moment..." interstitial) blocks plain HTTP fetches and non-warmed Playwright sessions intermittently — a fresh page load that fails with HTTP 403 typically succeeds a few seconds later on retry (the JS challenge auto-resolves). Don't conclude "blocked" from a single failed attempt.
  - Getting new scratches to 100% match still requires the normal per-function iteration (compiler flags for frame-pointer omission, gp-relative small-data threshold, etc. — our first test scratch compiled correctly but showed a stack-frame + `%hi/%lo` addressing mismatch against the target's frameless `%gp_rel` leaf-function shape, purely a flags/options issue, not a toolchain issue). That tuning is ordinary task-#6 grind, function by function, not a separate open question anymore.
  - Test scratch used as proof: `FUN_80015010` (0x80015010), 40 bytes / 10 instructions, gp-relative read-modify-write: `DAT_8009b112 = (DAT_8009b112 & 0x3ffc); DAT_8009b112 = (DAT_8009b112 | 2);` (two separate statements — matches the target's re-load-between-ops shape; decomp.me's auto-seeded m2c guess got this structural detail right). See `docs/FUNCTION_INVENTORY.txt` for more candidates.

## Ghidra analysis findings

- Import + auto-analysis is **fully scriptable headless**, no GUI/dialogs needed — confirmed empirically. The plugin's `PsxAnalyzer` (PsyQ Signatures analyzer) does automatic version detection + signature application + GTE macro segment creation entirely within Ghidra's normal auto-analysis pass.
  - Gotcha: passing `-loader "PSX Executables Loader"` explicitly to `analyzeHeadless` throws `Invalid loader name specified` (looks like a bug in headless loader-name validation for extension-provided loaders). **Fix: omit `-loader` entirely** and let auto-detection pick it up from the `PS-X EXE` magic — this works correctly and is confirmed by the log (`Using Loader: PSX Executables Loader`).
- **495 functions matched to PsyQ libraries** (LIBGTE, LIBAPI, LIBGPU, LIBCD, etc. + GTE macro pseudo-functions at `0x20000000`+) — these are NOT part of the decompilation target, the original libs are linked as-is.
- **1,336 game-specific functions** remain to actually decompile. This is the real scope of the project — a bounded, tractable number (much smaller than e.g. SOTN or MGS), consistent with FM being a turn-based card game rather than an open-world/3D-heavy title.
- Memory layout after analysis: `.rdata` (0x80010000–0x800129d7), `.text` (0x800129d8–0x800906df, ~515KB), `.data`, `.sdata`, `.sbss`, `.bss` (ends ~0x800fe727) — all one contiguous flat image within the 2MB RAM window.
- **No PsyQ code overlays.** Confirmed by searching game code for CD-read call sites and indirect-jump patterns: the only `CdGetSector` callers in game code are data-streaming routines (`DSREAD_OBJ_164`, `DSREADY_OBJ_FC` — "Disc Stream Read"), which load asset data (`MODEL.MRG` card models, textures) into buffers on demand, not code into the text segment. All `jalr`/`jr` indirect branches found in game code are either ordinary callback dispatch or the classic PS1 BIOS syscall trampoline pattern (`jr $t1`/`jr $t2`, i.e. the A0/B0/C0 jump tables) — no overlay dispatch pattern anywhere. Combined with the single contiguous `.text` (no gaps, no address reuse), the whole game keeps all ~1,336 functions resident in RAM at once and only streams data assets from CD. **The splat/build harness does not need overlay support.**

## Local PsyQ 4.6 toolchain

Obtained from the PS1 preservation/homebrew community archive `psx.arthus.net/sdk/Psy-Q/Psy-Q_46.zip` (referenced by psx.dev's official getting-started guide — a standard, widely-used source for this kind of project, same posture as sotn-decomp/mgs_reversing which also don't bundle the SDK themselves and expect contributors to source it). **Not committed to the repo** (`/tools/` is gitignored) — same reasoning as the disc image: proprietary Sony dev tooling, everyone building this needs their own copy.

- Extracted to `tools/psyq46/Psy-Q - 46/`. Key binaries: `BIN/CC1PSX.EXE` (C compiler backend), `BIN/CPPPSX.EXE` (preprocessor), `BIN/ASPSX.EXE` (assembler), `BIN/CCPSX.EXE` (compiler driver), `BIN/PSYLINK.EXE` (linker), `BIN/PSYLIBD.EXE`, `BIN/ASMPSX.EXE`, `BIN/PSYMAKE.COM`. Plus `INCLUDE/` (all the LIB*.H headers) and `DOCS/` (LIBREF46.PDF, LIBOVR46.PDF).
- **Confirmed to run natively on Windows 11 (no DOSBox needed)**: these are genuine 32-bit Win32 console PE binaries (`machine=0x14c`, `subsystem=3`), not 16-bit DOS executables as one might expect from a late-90s SDK. `CC1PSX.EXE` invoked directly and behaved as expected (reads preprocessed C from stdin, emits MIPS assembly, prints the standard GCC2 pass-timing footer).
- This means local matching decomp iteration (compile candidate C → compare bytes) no longer strictly depends on decomp.me's hosted compiler — decomp.me is still useful for quick one-off tests and its diff UI, but the local toolchain is what a real splat-based build harness will drive.

## The trailing "carddata" region (vram 0x800fe728–0x801dffff, 923,864 bytes)

Ghidra's naive loader heuristic first labeled this whole span `.text` (a fallback guess, not a real determination — see the `PsxLoader.createCompilerSegments` fallback: "if there's leftover file content past where the heap-struct heuristic thinks bss ends, call it `.text`"). Investigated directly against the raw file bytes rather than trusting that label:

- It is **not** meaningfully code: Ghidra's auto-analysis only found ~29 tiny "functions" scattered across the whole 923KB span, each in near-total isolation (huge gaps between them) — consistent with false-positive disassembly of what's actually data, not with real code density.
- Most of the region (all but ~46 of 225 checked 4KB chunks) is literally all-zero in the ROM file.
- **One dense, real data block**: roughly vram `0x801ab728`–`0x801d9728` (~188KB), 85–90% non-zero bytes — the density profile of a packed binary table, not code. Strong candidate for the card database (722 cards).
- DataCrystal's community-documented fusion-table address (`0x8017C2D8`, within this span) is **all-zero on disc** — confirms it's a runtime-computed cache (built from card data at boot/on first use), not a shipped table. Not a bug on our end; matches expected behavior for a computed lookup.
- **Splat config fix**: declared this span as its own `type: data` top-level segment (`carddata`, explicit `vram: 0x800fe728` override) rather than folding it into `main`'s fallback `.text` guess, so splat doesn't waste effort trying to disassemble it as MIPS instructions. The real `.sbss`/`.bss` gap (1048 + 406144 = `0x63698` bytes, no file content) between `.sdata` and this region is handled via `bss_size` on the `main` segment.
- **Open question, not yet answered**: what exactly is in that dense ~188KB block, and what (if anything) lives in the remaining sparser parts of the 923KB span. Worth a dedicated pass once we're further into decompiling `main`'s actual functions (may become obvious once we decompile whatever code reads from this region).

## Local build harness (splat)

Set up in `config/SLUS_014.11.yaml`, using `splat64[mips]` (installed in a **project-local venv**, `.venv/` — see the note below about why that matters) plus the real local PsyQ 4.6 toolchain.

- `splat create_config` auto-generated a starting config from the raw executable and — good cross-check — independently computed `gp_value: 0x8009AF08`, matching what we'd already derived by hand from Ghidra's `DAT_8009b112` gp-relative addressing (`0x8009b112 - 0x20a`).
- The auto-generated segment boundaries were rough estimates; replaced with the exact boundaries Ghidra already gave us (`.rdata`/`.text`/`.data`/`.sdata`/bss-gap/`carddata`, see above).
- `splat split config/SLUS_014.11.yaml` (run from repo root) produced:
  - `asm/nonmatchings/31D8/func_*.s` — **1,794 individual function assembly files** (splat's own function count for the main code segment; in the same ballpark as Ghidra's 1,336 game + 495 library split, difference expected from different heuristics — worth reconciling later but not blocking).
  - `src/31D8.c` — one stub C file with an `INCLUDE_ASM("asm/nonmatchings/31D8", func_XXXXXXXX);` line per function. This is the file that gets edited function-by-function during actual decomp work (each `INCLUDE_ASM` line gets replaced with real matched C).
  - `asm/data/*.data.s` / `.rodata.s` — the `.rdata`, `.data`, `.sdata` segments as raw data dumps, plus `carddata.data.s` (huge, gitignored — see Legal posture section).
  - Splat also flagged a rodata/jumptable file-split suggestion (rodata segment `800` has jump tables suggesting further splits at `0x844`, `0x8C0`, `0xA24`, `0xB48`, `0x100C`, `0x1FD8`, `0x214C`, `0x22D8`) — not applied yet, worth revisiting once we're deep into functions that reference jump tables in that area.
### Build harness: DONE and verified byte-exact

`tools_src/build.py` (run from repo root: `.venv/Scripts/python.exe tools_src/build.py`) rebuilds the whole executable and **reproduces the retail binary exactly** — sha1 `84747e64f6da8e764206ec203e489acf8c9dcf7d`, matching `extracted/SLUS_014.11` byte for byte.

That single check validates the entire setup at once: segment boundaries, `gp_value`, `subalign`, the linker script, and the whole toolchain. Any future change that breaks byte-exactness will be caught immediately by re-running it.

Pipeline per C file: `CPPPSX.EXE` (preprocess) → `CC1PSX.EXE` (compile) → `maspsx` (rewrite PsyQ asm quirks to GNU as syntax) → `mipsel-none-elf-as`. Raw `.s` files (header, data segments) go straight to the assembler. Everything links via a generated linker script, then `objcopy -O binary`.

**Layout is driven by the linker script, never by compiler emission order.** Walking the address-ordered function list, the build emits:
- one object per decompiled function, from `src/<func_name>.c`;
- one object per *run* of consecutive not-yet-decompiled functions, from a generated stub in `build/gen/` that `.include`s each function's `.s`.

It then rewrites splat's linker script (`config/slus_014.11.ld` → `build/gen/slus_014.11.ld`), replacing the single `build/src/31D8.o(.text);` line with that ordered list. This is what makes `-G8` usable — see the gp-relative section below for why it is essential rather than a stylistic choice. **Do not collapse this back into one object per segment.**

Decompiling a function is therefore just: create `src/<func_name>.c`, and re-run the build. Nothing else needs updating; the placement follows automatically.

Two consequences worth knowing:
- **`src/31D8.c` is a splat artifact we deliberately don't use** (it is the monolithic `INCLUDE_ASM` file). The build ignores it — it only looks for `src/func_*.c`. It is gitignored so it doesn't reappear as noise after a `splat split`. The per-function `.s` files it comes bundled with *are* used, which is why the subsegment stays `c` rather than `asm`.
- **Per-function compiler flags** live in `PER_FUNC_FLAGS` in `build.py`. `func_80015010` needs `-O1` where the project default is `-O2`; expect this table to grow, since the game's per-file `-O` levels are unknown.

### Platform support (Windows and Linux)

`build.py` detects the platform and adapts; there is no fork.

- **PsyQ SDK** is 32-bit Windows executables. Native on Windows; prefixed with `wine` elsewhere (`PSYQ_RUNNER`). **Verified byte-identical**: `cc1psx` output under Wine 10.0 matches native Windows exactly, checked across three functions including one built at `-O1`. Wine is not an approximation here.
- **MIPS binutils** come from the distro on Linux (`mips-linux-gnu-*`, `apt install binutils-mips-linux-gnu`) and from the prebuilt toolchain under `tools/mips/` on Windows (`mipsel-none-elf-*`).
- **venv path** differs (`.venv/bin/python` vs `.venv/Scripts/python.exe`).

Linux is the better long-term host: every tool in this ecosystem (splat, decomp-permuter, maspsx, and every reference decomp project) is Linux-first, and the Windows workarounds documented elsewhere in this file — four of them for decomp-permuter alone — are the cost of being the odd platform out. Measured trade-offs, if useful: Wine adds per-invocation overhead to ~278 PsyQ calls per full build; WSL with the repo on `/mnt/d` is *not* a good middle ground, since reading the 1794 asm files took 6.2s there versus 0.87s on native Windows.

**Why a Python script and not a Makefile:** `make` is not available in this Windows environment (no make, no ninja). The dependency graph is shallow (a handful of asm files + one C file today), so a plain script is sufficient and avoids adding a build-tool dependency.

Note it rebuilds **everything** on every run — there is no incremental/mtime checking. That is fine at one C file, but splitting into the ~234 original translation units (see below) is exactly the trigger for revisiting this; whoever does that split should expect the full-rebuild cost to become annoying and may want to add dependency tracking at the same time.

`splat split` is safe to re-run: it skips `.c` files that already exist, so hand-decompiled work in `src/` is never clobbered (verified empirically).

Toolchain components (all gitignored, must be re-fetched by anyone cloning):
- **MIPS binutils**: prebuilt Windows `mipsel-none-elf` toolchain (GNU Binutils 2.46.1) from `https://static.grumpycoder.net/pixel/mips/g++-mipsel-none-elf-16.1.0.zip`. URL taken from pcsx-redux's own `mips.ps1` installer + its `index.json`, so it stays correct as versions move. Extracted to `tools/mips/`.
  - GNU binutils is **not optional**: splat emits GNU-as syntax (`glabel`, `%gp_rel`, `.section`), which PsyQ's own `ASPSX.EXE` cannot assemble.
- **maspsx** (`https://github.com/mkst/maspsx`, cloned to `tools/maspsx/`): bridges cc1psx's asm output to GNU as. Not on PyPI — must be cloned, then run as `python tools/maspsx/maspsx.py`. Invoked with `--aspsx-version=2.86` (the ASPSX bundled with PsyQ 4.6) and `--macro-inc`.
  - Chose maspsx over the more "authentic" `ASPSX.EXE` + `psyq-obj-parser` path (what decomp.me runs internally) because maspsx is pure Python, needs no extra binary, and is what every modern splat-based PS1 decomp uses (sotn-decomp, Silent Hill, MediEvil, Soul Reaver, Croc…).

Two non-obvious things that had to be fixed to reach byte-exactness:

1. **`ld_align_section_vram_end` / `ld_align_segment_vram_end` must both be `False`** (splat defaults both to `True`). They emit `. = ALIGN(., 16)` after each section/segment. The retail binary has no such padding — `.text` starts at `0x800129D8`, which is deliberately *not* 16-byte aligned. With the defaults, `.text` landed 8 bytes late, which surfaced as **every jumptable entry in `.rodata` pointing 8 bytes too high** (e.g. `0x80014698` built as `0x800146A0`) and a binary 16 bytes too long. Worth remembering as the signature of this class of bug: uniform small offset in pointer-valued data = section placement, not bad code.
2. **Assembler needs `-I.` *and* `-Iinclude`.** The `.include "macro.inc"` chain resolves relative to the include search path, and `macro.inc` itself pulls in `gte_macros.inc`. Without `-Iinclude`, the GTE macros never load and assembly fails with a flood of `unrecognized opcode 'rtps' / 'ncds'` errors — which look like missing CPU support but are really just a missing include path.

Assembler flags: `-EL -march=r3000 -mtune=r3000 -no-pad-sections -O0 -G0` (`-no-pad-sections` and `-O0` are both required for byte-exact section contents/sizes).

Compiler flags currently `-quiet -O2 -G0`. `-O2` is the near-universal choice for retail PS1 titles, but this is **not yet proven for this game** — the all-`INCLUDE_ASM` build doesn't exercise the compiler's codegen at all. Expect to revisit per-file (or per-function) once real C starts getting matched.

### First real decompiled functions (the loop is proven end-to-end)

Two functions are now real C in `src/31D8.c` and the build **still reproduces the retail sha1 exactly**. This is the proof that matters: the harness doesn't just reassemble the original bytes, it can take hand-written C through the real compiler and land byte-identical output.

- `func_80042AD8` — steps a value toward a limit by a step size, clamping so it never overshoots; the sign of the limit picks the direction. Matched on the first attempt.
- `func_80082780` — the game's own out-of-line copy of PsyQ's `GetTPage()` macro (packs a texture-page attribute word from `tp`, `abr`, `x`, `y`). All 15 instructions matched on the first attempt.

Both matched with the existing `-O2 -G0`. That is *weak* evidence for those flags, though — both are nearly flag-insensitive (straight-line bit manipulation, and a shallow branch chain), with few enough live values that register allocation never has to make an interesting choice. They would very likely match at `-O1` too. **Do not treat `-O2` as confirmed**; the discriminating test is a function with enough live values to force real register-allocation decisions, and that hasn't been run yet.

### gp-relative globals vs. compiler output ordering — SOLVED

This was the project's main blocker. It is now fixed by the per-function layout described under "Build harness" above: `-G8` is enabled globally and `func_80015010` (a gp-relative read-modify-write) is decompiled and matching. The analysis is kept below because it explains *why* the harness is shaped the way it is — do not "simplify" the build back into one object per segment.

Most game functions touch state gp-relatively, e.g. `lhu $v0, %gp_rel(D_8009B112)($gp)`. Reproducing that requires a non-zero `-G` on cc1psx (`-G8`). What was established:

1. **`-G0` cannot produce gp-relative addressing at all.** cc1psx emits an explicit `lui %hi(sym)` / `%lo(sym)` pair; there is no bare-symbol "macro" form left for the assembler to turn into a gp-relative access. Dead end, confirmed by inspecting the emitted asm.
2. **`-G8` produces exactly the right instructions.** With `-G8` and `extern volatile unsigned short D_8009B112;`, cc1psx + maspsx emit the target's 10 instructions verbatim.
3. **But `-G8` makes cc1psx defer *all* C function output to the end of the file.** With small-data enabled the compiler buffers text output (it must emit `.extern sym, size` declarations before use), so the generated `.s` becomes `[every top-level inline asm block][then every C function, in source order]` instead of source order throughout. Verified by a controlled sweep: the deferral tracks `-G`, **not** `-O` (`-O2 -G0` and `-O1 -G0` interleave correctly; `-O2 -G8` and `-O1 -G8` both defer).
4. **No compiler flag turns it off.** `-mno-file-switching` / `-mfile-switching` are rejected outright by cc1psx; `-mno-gpopt`, `-mgpopt`, `-mno-split-addresses`, `-mrnames`, `-mno-abicalls` are all accepted but leave the deferral in place.

**Why this breaks us specifically:** it is only a problem because `INCLUDE_ASM` (top-level inline asm) and real decompiled C functions live in the *same* translation unit. The original build never hit this — each original `.c` was pure C, so "all C functions in source order at the end" *was* the correct order. For us, deferring the C functions moves them out of their address slots and scrambles `.text` (measured: 23% of the binary differs, `.text` alone taking ~56,000 divergent runs).

Note the corollary: the deferral is harmless for a translation unit that is either **fully** `INCLUDE_ASM` (no C functions to defer) or **fully** decompiled (order among C functions is preserved). It only bites a *partially* decompiled unit — which is every unit, during the entire grind.

**The fix, now implemented:** stop relying on compiler emission order for layout. `tools_src/build.py` places every function individually via the linker script, in address order — each decompiled function as its own object from `src/<name>.c`, and each *run* of consecutive not-yet-decompiled functions gathered into one generated `.s` in `build/gen/`. Emission order inside any single object no longer matters, because no object spans a decompiled/undecompiled boundary.

Grouping the undecompiled functions into runs (rather than one object per function) keeps the object count proportional to how much has been decompiled: 24 decompiled functions currently produce 44 `.text` entries, not 1794. Build time stays reasonable and degrades gracefully.

Three incidental findings from that work, all worth keeping:
- **`volatile` matters.** Without it, gcc merges the read-modify-writes into a single load/store pair; the retail code stores and reloads between the two operations, which only `volatile` reproduces. Expect many game-state globals to need it.
- **`-O1` vs `-O2` changes register allocation here.** At `-O2` gcc uses `$v1` for the second load; the original (and `-O1`) uses `$v0` both times. So the game's `-O` level is still genuinely unknown, and may well vary per translation unit — do not assume `-O2` globally.
- **The assembler's `-G` must match the compiler's, in both directions.** With cc1psx at `-G8` but `as` at `-G0`, the assembler cannot assume a bare symbol is small data and expands each reference into a `lui`+`%lo` pair, making the function 4 bytes *longer* per reference (this is what first showed up as "16 bytes too long"). The reverse also bites: at `-G0` cc1psx sometimes emits the bare form `lw $3,sym` and leaves expansion to the assembler, and an assembler still at `-G8` decides the symbol *is* small data and collapses the pair into one gp-relative instruction, leaving the function an instruction *short*. `PER_FUNC_AS_FLAGS` is therefore derived from the `-G0` function lists rather than maintained separately -- do not let them drift apart. Note the shortfall only appears when gcc chose the bare form; where it emitted an explicit `%hi`/`%lo` pair the assembler passes it through and the mismatch is invisible, which is why this took a while to spot.

### The order to work in, when a function does not match

Learned the hard way, and worth following in this order because each step makes
the next one meaningful:

1. **Is the instruction count right?** If not, nothing else is diagnostic. A
   sweep over a wrong-length function tells you only that the length is wrong.
2. **Does the source's read order match the target's?** More functions have
   come down to this alone than to anything else — `func_80049F10`, `func_80037CE0`,
   `func_800373C8`. Declaration order *is* read order. Thirty seconds to check.
3. **Is the branch polarity right?** Look at which path retail falls through
   into; cc1psx emits the fall-through for the branch written as not-taken.
4. **Count the materialisations** of each value. One per write in the source.
5. **Then** sweep flags.

**And know when to stop.** Stop when the only remaining difference is which
register holds a value — that class is closed (no flag in gcc 2.8.1, permuter
saturates at 16k iterations, see below), so any further C shapes are wasted.
Stop also when the target has *more* duplicated tails than you produce
(cross-jumping) or keeps two comparisons where cc1psx folds a range check.
Park, record which class, move on.

I spent a long time doing 5 before 2 and 3, which is why this list exists — and
a while after that grinding shapes against differences no shape could reach,
which is why the stopping rule is here too.

### Decompilation conventions (learned from the first 64 functions)

**Declare every global in `include/variables.h`, never locally.** Two files disagreeing about a global's type or qualifiers silently changes codegen and breaks matching somewhere far away. The header carries the shared `u8`/`u16`/`s32` typedefs (`include/types.h`) too.

**Scalar vs. unsized-array is a codegen decision, not a style one.** We build at `-G8`, so a small scalar goes in small data and is reached gp-relative (`lhu $v0, %gp_rel(sym)($gp)`). A symbol the retail code reaches with an explicit `%hi`/`%lo` pair was *not* small data in the original build. Two different causes, and they need different fixes:
- it was genuinely an aggregate → declare it unsized (`extern u8 D_800EAE90[];`) and index it;
- it was a scalar in a unit built with `-G0` → keep the scalar declaration and give the *function* a `-G0` override.
Getting this backwards produces a right-sized function whose registers are subtly wrong.

**`volatile` where the retail code stores and reloads.** Without it the compiler folds consecutive read-modify-writes of the same global into a single load/store pair.

**Flags genuinely vary per translation unit.** `PER_FUNC_FLAGS` in `build.py` already holds `-O1` and `-G0` overrides, and it will keep growing — that is the game being built from ~234 units with different settings, not a defect in the harness. `PER_FUNC_AS_FLAGS` does the same for the assembler, which is possible only because each decompiled function is its own object.

**Function declarations live in `include/functions.h`**, for the same reason globals live in `variables.h`: a signature mismatch between two files changes codegen silently. A function listed there need not be decompiled -- the declaration only has to agree with how it is used, since the definition can still come from assembly (e.g. `func_80019BA0` takes the address of `func_80019B2C`, which is still asm).

**Useful idioms observed so far:**
- `return *p = 1;` does *not* reproduce store-and-return; gcc emits the constant twice. `s32 v = 1; *p = v; return v;` does.
- `sltiu $v0, $v0, 1` after a load is `return x == 0;`; `sltu $v0, $zero, $v0` is `return x != 0;`.
- `srl $r, $r, 31` extracts a sign bit: `(u32)x >> 31`.
- `lw`/`addiu`/`sw` on the same global around a load is a post-increment: `return *ptr++;`.
- A function ending in `jr $ra` with the real work in the delay slot is just ordinary scheduling, not something to reproduce deliberately.

**With a ~2s incremental build, `build.py` is now the fast loop.** `try_func.py` existed to avoid a 9-minute rebuild and carries known blind spots (it cannot see assembler-level macro expansion). Prefer editing a candidate and re-running the build: it is the authoritative check, reports which functions differ, and costs about as much as the comparator did.

**A base address formed once, then reached by offsets, means a struct.** When the retail code does `lui` + `addiu` and *then* stores at `0(reg)` and `2(reg)`, indexing an unsized array in C will not reproduce it -- gcc folds the offset into the second `%lo` and the function comes out an instruction short. Modelling the object as a struct and using field access fixes it (`func_8007058C`). Two cautions learned the hard way: a struct of 8 bytes or fewer becomes small data at `-G8` and the link then fails with `relocation truncated to fit: R_MIPS_GPREL16` because the address is far from `$gp`; and taking the base into a local pointer instead is *not* equivalent — gcc CSEs it back.

**Branch polarity follows which case you write as the `if` body.** The retail code for a test-and-set reads `beqz` (branch when the bit is *clear*), with the set case falling through. Writing `if (v & 0x80) return 1; ...` produces `bne` instead. Write the clear case as the `if` body and the polarity matches:

```c
if (!(v & 0x80)) { D_8009B220 = v | 0x80; return 0; }
return 1;
```

**Store order is worth copying literally.** `func_800151B0` writes offsets 6, 4, 5, 7 in that order -- not ascending. Writing them in the natural order does not match; there is no need to explain why the original is out of order, just reproduce it.

**A `u8` read that gets sign-extended by `sll`/`sra` is a cast, not an `s8` load.** Where the retail code does `lbu` then `sll 24` / `sra 24`, assigning to an `s8` local lets gcc collapse the whole thing into a single `lb` and the function comes out two instructions short. Cast at the point of use instead: `D_8009AF76 - (s8)arg0[0x16]`.

### An unfilled delay slot means `-fno-delayed-branch`

**This cracked what had looked like an unbeatable register-allocation class.** Read the tell first: if the retail code leaves a branch's delay slot as a `nop`, gcc did *not* schedule that code -- gcc fills delay slots itself, so an empty one means the original unit was compiled with delay-slot filling off and the assembler left the slot alone.

`-fno-delayed-branch` reproduces it. And it does far more than add a nop: with the slot unfilled, gcc's whole register assignment changes, which is why sweeping `-O` levels never helped. Everything that had failed on `func_800498F8` -- all four `-O` levels crossed with both `-G` values, the deref form, and ~7 minutes of decomp-permuter that only reached score 10 with a meaningless `D_8009B458 += 0;` -- came down to a missing flag.

Two other things were needed for that function, both generalisable:

- **A value still live in `$v0` at exit means the function returns it.** The retail code loaded the halfword into `$v0` and never used it again, which only makes sense as a return value. Declaring the function `void` forced gcc to pick a different register; giving it the return type put the value where the original had it.
- **`-mno-split-addresses` plus a `-G0` assembler** to reproduce `lui $v1` / `lw $v1,%lo(sym)($v1)`, where the address computation reuses the destination register. gcc's own expansion uses a separate temp; the assembler's reuses the destination, so the address has to be left in macro form for `as` to expand.

So the checklist for a function that is structurally right but has the wrong registers: look for an empty delay slot, look for a value sitting in `$v0` at exit, and check whether the address computation reuses its destination register. Try these before reaching for the permuter.

**But the flag alone is not a mechanical fix, and it is worth being precise about that.** Thirteen already-parked functions were identified as having an empty delay slot in their target, and every one of them was swept across eleven flag combinations (all four `-O`/`-G` pairings, each with and without `-fno-delayed-branch`, plus the macro-form variants). **None matched.** `func_800498F8` only fell because the flag was combined with a *correct signature* -- spotting that it returns the loaded value -- and finding that still takes per-function reasoning about what the code means.

Read the checklist as "these are the knobs that exist", not "these will unlock the parked set".

### The `jal` class is open, and it is the richest vein left

Every batch up to 179 functions avoided `jal` entirely. That was a mistake:
calls are most of the ~1160 remaining targets, and the shapes that involve
them turn out to be *easier* than the tiny leaf functions, because a call
pins down register usage that a 9-instruction leaf leaves free.

Start with **thunks** — one call, no other work. Filter to callees inside the
game's own code (a call into a PsyQ library function needs that function's
real prototype, which we do not have). 64 single-call candidates remain in
the main body alone.

Two things make them cheap:

**Argument forwarding costs no instructions.** `void f(int a) { g(a); }`
compiles to exactly the same code as `void f(void) { g(); }`, because `$a0` is
already in place. So the thunk's own arity cannot be read off its asm; infer
it from the *callee's* asm (which `$aN` it reads before writing) and forward
everything. The bytes match either way, so getting arity wrong costs
correctness, not the match — worth being careful about anyway.

**`include/functions.h` is the safety net, and it earned its place.** Two
callees in the first thunk batch were already decompiled with a different
return type, and cc1psx refused to compile rather than silently emitting
different code. That is exactly why cross-file declarations are centralised.

### Signedness at the point of store, again

`func_80039FD4` sets a byte to -1 through a `u8 *`. Written as
`arg0[0x30] = -1;` cc1psx narrows the constant and emits `li $v0,255`; the
retail code has `addiu $v0,$zero,-0x1`. The fix is to store through the
signed type at the point of use, `*(s8 *)(arg0 + 0x30) = -1;`, keeping the
parameter `u8 *` so it still agrees with the callee. Same lesson as the
earlier `(s8)` cast rule: **the cast goes where the value is used, not on the
declaration.**

### A third aspsx behaviour maspsx does not reproduce — now emulated

cc1psx ends a small frame with the stack restore in the `jr` delay slot:

    lw    $31,16($sp)
    .set  noreorder
    j     $31
    addu  $sp,$sp,24

`lw $31` followed by a `jr $31` is a load-delay hazard. maspsx inserts a `nop`
after the `lw` and leaves `addu $sp` in the branch delay slot. Real aspsx
instead **hoists `addu $sp` into the load-delay slot** and leaves the branch
delay slot empty. Same cycle count, two instructions swapped, mismatch.

Both shapes exist in the retail binary from *byte-identical cc1psx output* —
verified by hashing, so it is an assembler difference, not a compiler flag.

**I first wrote this off as out of scope on five samples, and that was wrong.**
The claim was "the hoisted form is only in the library region, so it needs no
post-pass". Scanning all 1794 functions instead of five: the hoisted form
appears in **106** functions spanning `0x800742E8..0x800901EC`, the maspsx form
in **207** spanning `0x80012D4C..0x80072F54`. Zero overlap, and the seam sits
exactly where `docs/FILE_BOUNDARIES.txt` begins — two independent signals
agreeing on the same boundary, which is worth more than either alone.

But "only in the library region" does not imply "out of scope": **53 of those
106 are not in `docs/LIBRARY_FUNCS.txt`**, out of 250 non-library functions
above the seam. So the post-pass is worth writing, and
`hoist_epilogue_out_of_delay_slot()` in `build.py` now does it, opt-in per
function via `HOIST_EPILOGUE_FUNCS` because the two shapes must not be mixed.
It immediately recovered the five thunks that had been dropped.

The general lesson, which has now cost time twice in this project: **a split
observed on a handful of samples is a hypothesis. Scan the whole binary before
letting it justify not building something.**

### The compiler is PsyQ 4.5, not 4.6. This was wrong from the first commit.

**Result first.** With the same 220 sources, PsyQ 4.5's `cc1psx` builds a
byte-identical binary and 4.6 does not. No function matches under 4.6 that
fails under 4.5. Switching versions then unlocked **eight** parked functions
immediately, and they were the entire collapsed park class. `build.py` now
defaults to 4.5; `YGOFM_PSYQ=46` still selects 4.6 for comparison.

**How it was found.** `func_800495A4` was the discriminator. Its flags are
pinned by two matching neighbours 0x10 and 0x38 away (`func_80049594`,
`func_800495DC`, both `-O1 -G0`), and at those flags 4.6 gets the *registers*
right but not the ordering, while at `-O2` it gets the ordering right and the
registers wrong. Then the measurement that closed it:
`-O1 -G0 -fschedule-insns2` emits output **byte-identical** to `-O2 -G0` under
4.6 — enabling the post-reload scheduler changes register numbers too, so
ordering and allocation are one switch and 4.6 *cannot* produce retail's
combination. 4.5 produces it directly at `-O2 -G0`:

    retail:                        4.5 -O2 -G0:          4.6 -O2 -G0:
    lui   $v0,%hi(D_8009B458)      lui  $2,%hi           lui  $2,%hi
    lw    $v0,%lo($v0)             lw   $2,%lo($2)       lw   $3,%lo($2)   <- $3
    addiu $sp,$sp,-0x18            subu $sp,$sp,24       subu $sp,$sp,24
    sw    $ra,0x10($sp)            sw   $31,16($sp)      sw   $31,16($sp)
    lbu   $v0,0x814($v0)           lbu  $2,2068($2)      lbu  $4,2068($3)  <- $4

**What it unlocked.** `func_800495A4`, `func_80024954`, `func_80038388`,
`func_800383B0`, `func_8007368C`, `func_800598E4`, `func_80042874`,
`func_8003FCD8`. Three separately-named park classes — the coupled-ordering
wrappers, the `$a0`-as-scratch group, and assorted "register allocation"
misses — were **all one thing: the wrong compiler.** Every hour spent hunting
C shapes and flags for those was spent on an artefact.

**What it cost.** 4.5 narrows a `u8` return value with an extra
`andi $v0,$v0,0xFF` where 4.6 does not, which broke `func_8007058C` and
`func_8003B7E0`. Both are fixed by returning `s32` — the value comes from an
`lbu` and is already zero-extended, so the raw type is the honest one. This is
the point-of-use casting rule applied to *return* types: declare the raw
value, narrow at the use site.

**Why "confirmed twice" was not confirmation.** The original note claimed the
toolchain was double-confirmed by `ghidra_psx_ldr`'s detection and by decomp.me
exposing `psyq4.6/cc1psx` for this title. Neither is evidence of the kind
needed: the first is a heuristic over library signatures, which 4.5 and 4.6
largely share, and the second is someone else's configuration, not a
measurement. **And a byte-identical build was not evidence either** — 219
functions matched under the wrong compiler, because most are small enough that
the two versions emit identical code. A whole-binary match only tests the
functions that can discriminate, and until `func_800495A4` there were none in
the corpus.

The general form is worth keeping: **a passing global check does not validate
every assumption feeding it.** It validates them only where they were exercised.
The way to test a foundational assumption is to find the *one case that
discriminates* and run it, not to count successes elsewhere.

**Still failing under 4.5** — and these are now honest unknowns rather than
suspected version artefacts. Wrong size: `func_80035DF4`, `func_800428EC`,
`func_80049200`, `func_8005B5FC`. Differing: `func_8003F7D4`, `func_80070988`,
`func_80071424`, `func_80071460`. Everything recorded about them before this
commit was measured under the wrong compiler and should be re-derived, not
trusted.

**Provenance.** PsyQ 4.5 came from the same preservation archive as 4.6
(`psx.arthus.net`), as `PSYQ.SDevTC.Developers.Toolkit.For.PSX.v4.5-MFD.zip` →
nested `mfdpsx*.zip` → a multi-part RAR3 that needs the non-free `unrar`
(`7z` and `unrar-free` both extract it as zero-byte files, silently). Binaries
live in `tools/psyq45/BIN/`, which `/tools/` in `.gitignore` keeps out of the
repo along with everything else that is not ours to redistribute.

### Re-deriving the pre-4.5 park: 4 of 5, and a fourth stale-input bug

Five functions parked in earlier sessions were rewritten from their target asm
and retested under 4.5. Four landed (231 total): a little-endian halfword
stream read, a `qsort`-style comparator, a stream accumulator, and a flag
store. None of them needed anything exotic — the comparator only wanted its
**branch polarity** inverted (`if (a >= b) return 1;` rather than
`if (a < b) return -1;`), which is a rule already in this document and was
simply never applied to it.

`func_800855B0` and `func_80070988` both landed too — see the next section, they
turned out to share a fix.

**A `-G8` compiler with a `-G0` assembler is a real configuration.** The note
above says the two `-G` settings must match in both directions, and that is the
usual case. `func_800495EC` is an exception: at `-G8` cc1psx emits the bare
symbol form `lw $3,D_8009B458` and leaves expansion to the assembler, and a
`-G0` assembler expands it to `lui`/`lw` where a `-G8` one collapses it to a
single gp-relative load. The mismatch is what reproduces retail.

**And the fourth instance of the same failure — this one in `sweep_flags.py`
itself.** It reported `func_800495EC` matching at plain `-O2 -G8`; removing the
override broke the build. Cause: the sweeper set `"cc"` for each combination but
only set `"as"` when the combination named one, so a combination labelled
"O2 G8" inherited whatever `PER_FUNC_AS_FLAGS` already held — here a leftover
`-G0`. The verdict was true of what it actually built and false of what it
claimed to build. Fixed by always writing `"as"`, using the null-means-default
value that the audit work added.

Four bugs, one shape: **an input that varies without the mechanism knowing it
varied.** The override file that the staleness check ignored, the flag whose
effect was never verified, the env var missing from the stamp, and now a tool
that set one half of a pair. Worth checking any new knob against this list
before trusting its first result.

### Local declaration order picks the callee-saved registers

`func_80039F90` differed only in its prologue: retail saves `$s1` before `$s0`
and initialises the counter before the pointer, while ours did the reverse.

    retail:                        ours:
    sw    $s1,0x14($sp)            sw    $16,16($sp)   <- $s0 first
    addiu $s1,$zero,0x2            addu  $16,$4,8
    sw    $s0,0x10($sp)            sw    $17,20($sp)
    addiu $s0,$a0,0x8              li    $17,2

**cc1psx assigns `$s0`, `$s1`, … in order of first use, so swapping the two
local declarations swaps the registers and the save order with them.** Writing
the counter first matched with no other change. This is cheap to try and easy to
read off the target: whichever value ends up in `$s0` was used first in the
source.

That makes three distinct things local *declaration* order controls, all found
in this project: which callee-saved register a value gets (here), where a
constant is materialised (`func_80044FFC`), and whether an address is folded or
built in a register (`func_8002E370`). Declaration order is not cosmetic in this
codebase.

### Declaring an array by its record type closes the reassociation gap

The base-formation gap recorded two sections ago — `base + (scaled index +
constant)`, where cc1psx reassociates and folds both constants into the
addressing mode — has a fix after all, and it is the obvious one in hindsight:
**declare the array as an array of its record type instead of bytes.**

`D_801AB000` holds twelve-byte records and was declared `u8 D_801AB000[]`, so
every access spelled its own `index * 12` and cc1psx was free to reassociate.
Declared as `Rec12 D_801AB000[]`, the index scales as part of the array access
and the base lands in a register exactly where retail has it.
`func_80073480` matched with no other change, and the first ten instructions of
`func_800708C4` went from wrong to identical.

This makes it a fifth variant of the recipe rather than a gap:

| what retail does | what works |
|---|---|
| base, then one field access | a plain struct |
| base, then two different offsets | unsized array of the struct, indexed `[0]` |
| base, then a variable index | index in a local **and** the element address in a pointer local |
| base, then a constant non-zero offset | base in one local, offset added in a separate statement |
| **base, then scaled index plus constant** | **declare the array by its record type** |

Worth doing eagerly rather than reactively: any symbol accessed with a repeated
`index * N` is a record array, and typing it that way removes a whole class of
addressing mismatch before it happens.

`func_800708C4` remains parked, now on the loop shape rather than the base.

### Sampling the 35+ band: the misses change character

The 16-26 pool is down to about 38 clean candidates while **555 clean functions
sit at 35+**, untouched. Two samples from 35-45, both straight-line
initialisers, both parked:

- `func_80035AF0` fills a 100-byte record: registers swapped between the base
  pointer and the constants, plus the argument mask placed differently.
- `func_80059134` fills eighteen fields: retail hoists the two reused constants
  (`0x1388`, `0x80`) into registers early and interleaves them with the first
  stores, while cc1psx materialises each constant immediately before its own
  store. Naming them in locals does not move them.

**The character of the misses is different from the small band.** There, a miss
was usually one rule away — polarity, declaration order, a cast. Here both
misses are the compiler distributing a dozen constants and a base pointer across
registers over thirty-plus instructions, and one disagreement anywhere in that
spread kills the function. Longer really is harder, but not for the reason
assumed earlier: not because large functions are more likely to hit a *closed*
class, but because they offer more independent chances for the allocator to
choose differently.

Two samples is not a rate. Recorded so the next attempt at this band starts from
"expect allocator spread, look for the least-branchy and least-constant-heavy
candidates first" rather than from scratch.

### `sll 16` versus `andi 0xffff` is another signedness tell

`func_800379F8` decrements a halfword counter and tests it against zero. Retail
emits `sll $v0,$v0,16` then `bnez`; casting the value to `u16` gives
`andi $v0,$v0,0xffff` instead. Casting to `s16` matched.

Both test the low sixteen bits, so the choice carries no semantics at this point
— it carries the *declared type*. **`sll`-then-branch is a signed short; `andi`
is unsigned.** Same family as `slt` versus `sltiu`, and the two together mean
signedness is readable off the instruction selection in both comparisons and
zero-tests.

### Statement order inside a loop body decides delay-slot filling

`func_8005A468` took three passes, each a statement-order question and each
visible in the same place — which instruction lands in a delay slot.

1. `s32 i = 0;` as an initialiser put the zero at the top of the function;
   retail has it in the `beqz` delay slot. Assigning it *after* the pointer
   setup moved it.
2. Inside the loop, `i++` written before `p++` let cc1psx fill the `lw`'s
   load-delay slot with it; retail leaves that slot as a `nop` and increments
   later. Writing `p++` first matched.

Neither is a semantic difference, and both are the kind of ordering most C
style guides would call arbitrary. **In this codebase the order of independent
statements is load-bearing**, because it decides what is available to fill a
delay slot. When a function is the right size but a `nop` sits where an
instruction should be — or vice versa — reorder the independent statements
around it before anything else.

### A base-formation case the recipe does not cover

`func_8004A8E4` indexes `base[arg0 * 40 + 0x180 + 3]`. Retail adds the constant
to the *scaled index* first, then the base, then uses `3` as the access offset:

    sll   $v0,$a0,2 / addu / sll $v0,$v0,3     v0 = arg0 * 40
    addiu $v0,$v0,0x180
    addu  $a1,$a2,$v0
    lbu   $v1,0x3($a1)

cc1psx reassociates: it adds the base first and folds `0x180 + 3` into the
access offset, `lbu $v1,387($v1)`, two instructions shorter. Naming the offset
in a local, splitting the pointer assignment from its declaration, and both
together all fail — the reassociation happens regardless of how the source
groups the additions.

So the recipe's four variants cover *base plus a constant* and *base plus a
variable index*, but not **base plus (scaled index plus constant)**, where the
constant can migrate past the base into the addressing mode. Recorded as a gap
rather than a fifth variant, since nothing found so far closes it.

`func_8004CA60` is parked for the same reason, with `base[off + 0x53C]` inside a
loop.

### Two zeros: cc1psx chains what retail materialises twice

`func_8003CEB8` is a CRC-16/CCITT loop that matched instruction for instruction
except for its second initialiser. Retail emits two independent zeros:

    addu $v1,$zero,$zero      crc = 0
    blez $a1,.L…
    addu $a3,$zero,$zero      i = 0   (delay slot)

cc1psx emits one and copies it: `move v1,zero` then `move a3,v1`. Swapping the
declarations swaps which is the source and which the copy, and never produces
two independent zeros. Four shapes tried, including a `for` loop and assigning
`i` inside the guard.

Same family as the register-allocation class — cc1psx deciding a value is
already available and reusing it — but visible as a *chained copy* rather than a
different register, which is a distinct enough symptom to name.

**A reading warning, for the second time in one session.** I read this function
as matching line for line and it did not: at line 3 ours was `addu $7,$3,$zero`
against retail's `addu $a3,$zero,$zero`, and the difference is `$3` versus
`$zero`. When comparing a numbered listing against a named one, `objdump` output
with symbolic names on both sides is the reliable move — I only saw it after
disassembling the object rather than reading the assembly text.

### A loop with two entry points is not reachable from structured C

`func_800358A0` walks backwards zeroing bytes above a threshold. Retail's loop
has **two labels**: one at a decrement and one at the test, and the two paths
through the body enter at different points — the "byte is small" path jumps to
the test with its own decrement in the delay slot, while the "byte is large"
path jumps to the decrement and shares it with the loop entry.

Four C shapes — `if`/`else`, swapped arms, `continue`, and a walked pointer —
all come out two instructions long, because each produces a single loop entry
and duplicates what retail shares. The literal transcription needs two `goto`s
into different points of the same loop, which is what the original almost
certainly had but which this project does not write.

Recording it as its own reason rather than filing it under the closed classes:
those three are cc1psx transformations, and this is a *source construct* we are
choosing not to use. If the parked pile grows several more of these, `goto` may
be worth reconsidering — sotn-decomp and similar projects do use it. For one
function it is not worth the precedent.

### `slt` versus `sltiu` is a signedness question in the source

`func_80021894` compares a byte counter against `0xFB`. Retail uses `sltiu`;
declaring the value `s32` gives `slt`. Making it `u32` matched — and the
comparison is genuinely unsigned in the original, since the value is a byte
counter that saturates.

Worth adding to the reading list because the two are one character apart in a
listing and easy to skim past: **`slt`/`slti` mean at least one side is signed
in the source; `sltu`/`sltiu` mean both are unsigned.** With a masked byte the
compiler cannot tell which the author meant, so it follows the declared type.

The same function also needed its index in a local: `base + arg0 + 0x4F` folds
the `0x4F` into each access offset, while `s32 idx = arg0 + 0x4F; base + idx`
computes the sum first, which is what retail does. Third variant of the
base-formation recipe to come up, after the two-local split and the array index.

### A struct copied to a local, not passed by value

`func_80059A50` copies seven words from a pointer argument into its own frame
and passes the copy's address on. The obvious reading — passing a struct *by
value* and letting the o32 ABI lower it — is wrong: gcc then splits the struct
across `$a2`/`$a3` and the stack, reading from offset 8 onward. Retail copies
all seven words to the frame and passes `$sp+0x10`, which is what an explicit
local copy produces:

    Words7 local = *arg2;

    func_80058A7C(arg0, arg1, &local);

The frame size is the tell. By-value lowering gave `0x30`; the explicit copy
gives `0x38`, matching retail, because the local occupies its own space rather
than reusing the outgoing-argument area.

**Parked anyway, on the allocator.** With the copy right, all 22 instructions
line up and the registers are uniformly shifted by one — ours uses
`$v0`/`$v1`/`$a3`/`$t0` where retail uses `$v1`/`$a3`/`$t0`/`$t1`.

A reading error worth recording: I first read the two listings as identical
because I matched `$2` against `$v1`. `$2` is `$v0`. When comparing a numbered
listing against a named one, translate one side properly or the eye will pair
them up in order and see agreement that is not there.

### An `if`/`else` join can cost a callee-saved register

`func_8005988C` opens a handle, uses it twice, and returns either `-1` or the
middle call's result. Written with an `if`/`else` assigning to one variable — the
shape the join rule usually calls for — it came out two instructions long,
because gcc kept the result in a *second* callee-saved register (`$s1`) across
the last call. Written with an early `return -1;` it matched, with the result
living in `$v0` until the very last moment and moving into `$s0` in the final
call's delay slot.

So the earlier rule — *an explicit `j` to a join means the source assigned to a
variable* — has a limit worth recording: **it holds when the two arms produce
values, and misleads when one arm is an early exit.** Retail here does have a `j`
to a join, but only because the non-error path has to funnel its result out; the
error path is a plain early return. Read the join as evidence of a shared exit,
not automatically of a shared variable.

The tell for which one: count the callee-saved registers the target saves. Two
values live across calls means two `$s` registers in the prologue. This function
saves only `$s0`, so only one value survives a call, so there is no second
variable.

### One function needing three different mechanisms

`func_8002D62C` took four passes and each failure named a mechanism already in
the toolbox but not applied. Worth writing out, because the three interact and
none alone was enough:

1. **Wrong declaration form.** `D_8009B269` was an unsized array, so
   `D_8009B26C = D_8009B269;` stored its *address*. Indexing `[0]` fixed the
   value but not the addressing.
2. **Wrong addressing.** Retail reaches it `%gp_rel`, which needs the scalar
   declaration — the per-file guard, now on its third symbol.
3. **Missing load-delay `nop`.** With both symbols gp-relative, maspsx omitted
   the `nop` between the `lbu` and the `sb`, because it discards
   `.extern sym,size` and cannot tell the symbol is small data.
   `SMALL_DATA_NOP_FUNCS` exists for exactly that.

The lesson is about *order of diagnosis* rather than any one mechanism: a wrong
declaration masks an addressing problem, which masks a post-pass problem. Each
fix revealed the next, and none of the three was visible from the first diff.

### Naming intermediate results fixes scheduling, and a cascade nearly hid it

`func_80022F98` computes two coordinate differences and stores them, then reads
a byte and writes three more fields. cc1psx interleaved the second subtraction
with the function-pointer store; retail keeps the two subtract-and-store pairs
together, then the byte read, then the rest. Naming each intermediate — the two
differences and the byte — in its own local fixed it exactly.

That is the same lever as hoisting reads, from the other end: **naming a value
pins where it is computed.** An unnamed subexpression is free to float, and
cc1psx floats it.

**A process note worth more than the function.** The fix was applied in the same
build as another candidate that turned out to be the wrong size, so the report
said "differs" for both and I nearly parked a function that was already correct.
Lining the two listings up side by side showed all 22 instructions matching.
The rule already in this document — *remove the wrong-sized function first, then
read the list* — applies to a function being **fixed** as much as to one being
written, and I did not apply it here until the diff forced me to.

**Parked: `func_80070870`.** A linear search returning 1 on a hit. Retail places
the `return 1` inline after the compare, falling through into it; cc1psx moves
that block past the loop and branches to it. Instruction counts and registers
match. Three loop forms tried. Block placement, like cross-jumping, is not
something the source can direct.

### `u16` loop counters cost an `andi` per iteration

`func_80019A08` walks a table of groups — key, member count, then that many
members — and came out two instructions long. Both were `andi $v0,$a2,0xFFFF`:
once before the loop-continuation test and once before using the count as a
pointer increment. Declaring the counter `s32` instead of `u16` removed both.

The value is loaded with `lhu`, so it is already zero-extended and the mask is
redundant — but C says a `u16` wraps at 16 bits, and after `n--` cc1psx has to
prove it. It cannot, so it masks.

This is the same rule as the `u8` local feeding a wider parameter, the `u8`
return value, and the `-1` stored into a `u8` array: **hold the raw value in the
widest natural type and let the store or call narrow it.** Four instances now, in
four different positions — parameter, return, local, and loop counter — which is
enough to treat "a narrow type in a computation" as a smell rather than a
detail.

### Filtering out the closed-class signatures restores the rate

First batch drawn from the *clean complement* — candidates with neither a
same-basic-block duplicate `%hi` nor an adjacent `blez`/`slti` — landed **3 of
3** after several batches at 1-2. The filter costs nothing to apply and should be
part of candidate selection from now on:

    exclude: duplicate %hi within one basic block   (needs an alias, and often
                                                     an allocator disagreement
                                                     on top)
    exclude: blez/bgtz followed within 2 by slti    (the range-check fold)

Three shapes worth recording from this batch:

**A stack buffer passed to a callee** shows up as a frame much larger than the
locals need, with `addiu $a0,$sp,0x20` and nothing initialising that area. The
frame layout gives the size: outgoing args below, buffer, then `$ra`.

**A nested `switch` inside an `if`** — `func_8005C768` tests the high half of a
word, then switches on the low half. Both levels read exactly as the earlier
`switch`-versus-`if`-chain rule predicts: consecutive comparisons branching *to*
their cases, with the default as the fall-through.

**Two `lui`s for one symbol in different delay slots is normal**, not the
duplicate-`%hi` signature. `func_8005A0DC` fills two branch delay slots with the
same `lui $v1,%hi(D_800F2B22)`, which cc1psx does on its own. The signature that
needs an alias is two materialisations in *one* basic block; the detector already
distinguishes them, and this batch confirms the distinction is real.

### How much is actually left, measured rather than guessed

Yield dropped to 1-2 per batch and my first reading was "the 16-23 band is
worked out, move up". That reading was wrong twice over. Moving to 24-34 did not
help, and it could not have: **one difference kills a function regardless of its
length**, so a longer function has *more* chances to contain a closed-class
disagreement, not fewer.

The discriminating measurement is how many remaining functions carry a
closed-class signature. Two of the three are detectable in the target:

| | count |
|---|---|
| non-library main-body functions not yet decompiled (≥9 instructions) | **905** |
| …with a same-basic-block duplicate `%hi` | 62 |
| …with an adjacent `blez`/`slti` range check | 7 |
| …with **neither** | **837** — 141 at 16-23, 141 at 24-34, 555 at 35+ |

So the two detectable closed classes account for about **7.5%** of what remains,
not most of it.

**The honest caveat: the third class is not detectable.** Register-allocation
disagreements are about what cc1psx *would* emit, not about anything visible in
the target, so 837 is an upper bound. From the last six batches, roughly a third
of attempts hit the allocator, which puts the reachable remainder nearer 550-600.

The useful correction is to the *story*, not the number: **the rate is not
declining, it is stable at roughly half to two-thirds per batch**, and the
misses are a fixed-rate tax rather than a sign of exhaustion. Band choice barely
matters. Keep mining wherever the candidates read most clearly.

**A wording correction while here:** earlier commits say things like "123
candidates remain in this band". That is candidates *matching the current
filter* — which excludes calls into PsyQ library functions, GTE routines, and
`mult`/`div` shapes — not functions remaining. The real remaining count for the
main body is the 905 above.

### The range-check fold is a class, not a one-off

`func_80049640` fails exactly as `func_80049544` did: the source tests
`v > 0 && v < 4`, and cc1psx folds it into the unsigned range check
`(v - 1) < 3` where retail keeps two branches (`blez`, then `slti`).

    retail:                 ours:
    blez  $v0,.L…           addu  $2,$2,-1
    slti  $v0,$v0,0x4       sltu  $2,$2,3
    beqz  $v0,.L…           beq   $2,$0,.L…

Nested `if`s, a local for the base, and reordering all still fold — the
transformation happens in `fold` on the `&&` itself, before anything the source
can influence. Two members now, and both are otherwise complete: same count,
same registers, same structure.

**This is a third closed avenue**, alongside the register allocator and
cross-jumping. All three are cc1psx doing something the source cannot ask it not
to do, and none has a flag in 2.8.1. Worth keeping them named separately rather
than as one "hard" bucket, because they fail differently and a future lever
would likely only touch one.

`func_800466C8` also parked, on the allocator: `p` and `q` land in `$a0`/`$v1`
where retail has `$v1`/`$a0`, and swapping the declarations does not move it.

### Two more for the working order, both from step 2

`func_80044544` computes `v / 8192` in a loop and subtracts the total from 15.
It differed only in which of `$a2`/`$a3` held the counter and which the total —
fixed by swapping the two local declarations, exactly the step-2 check. Worth
noting the signed-division idiom it contains, since it reads as noise otherwise:

    bgez  $v1,.L…       if (v >= 0) use v
    addiu $v0,$v1,0x1FFF  else use v + 8191
    sra   $v0,$v0,13    then >> 13

That whole sequence is `v / 8192` for a signed `v` — the bias corrects the
rounding direction. Seeing it as division rather than as three separate
operations is what makes the C obvious.

**Parked: `func_8003A198` and `func_80038334`.** The first is a three-level
offset-table walk where retail returns through a join with `0` materialised at a
label; the accumulator form loses one instruction and the early-return form
loses two, so neither of the two shapes the counting rule distinguishes fits.
The second differs only in whether `$v0` or `$v1` carries the index through a
`lb`/`sll`/`addu` triple, twice — the allocator class again, and the class is
closed.

### The register-allocation class: a negative that finally counts

`func_8004BAE4` ran **16,206 permuter iterations** under PsyQ 4.5, with the
compile flags verified as `-O2 -G0` and `target.o` confirmed to hold the same 20
instructions as retail. Best score **10**, hit 7,570 times, never 0. The earlier
25,000-iteration run on `func_8007368C` was against 4.6 and told us nothing;
this one is measured against the right compiler and a validated target, so it is
the first negative for this class that means anything.

Together with the flag scan, the class now has three independent closures:

- **Not flag-reachable.** gcc 2.8.1 accepts 23 `-f` options and the ones that
  steer allocation — `-fno-regmove`, `-fno-optimize-register-move`, `-fno-gcse`
  — do not exist in it.
- **Not C-shape reachable.** 16k permuter variants plus roughly six reasoned
  hand-written forms, all saturating at "structurally identical, one register
  wrong".
- **Not source-reachable where cross-jumping is involved** (`func_800601D0`):
  `jump_optimize` merges identical tails unconditionally and `-fno-crossjumping`
  arrives in gcc 3.

That is eighteen parked functions whose remaining difference is one register or
one fused block, with no lever currently known. Recording it as a closed avenue
rather than a to-do, so the next session does not re-run the same searches.

**Also parked: `func_80035A64`**, after five shapes including the
positioned-pointer-with-negative-offsets idiom that solved `func_800373C8`.
cc1psx keeps a second base register alive (`$3 = $2 - 12`) to hold the four
store offsets, where retail uses one pointer and offsets `0`…`0xC`. Addressing
optimisation, not source shape.

### Read order in the source is read order in the object

`func_800373C8` had the right instruction count, the right registers and the
right structure, and differed only in the order of its first four instructions:
retail reads the index at `+0x5C`, then the count at `+0x5E`, then forms the
table base. Ours took the base first and the two fields in the other order —
because that is the order the locals were declared in.

Reordering the three declarations to match matched the function with no other
change. This keeps happening and is cheap to check, so it is worth treating as a
first move rather than a last resort: **when the count is right and the order is
not, line the source's reads up with the target's.**

**Parked: `func_80035A64`**, one instruction long. It clears four fields at
`+0x28`…`+0x34` of `0x64`-byte records, and cc1psx biases the loop pointer by 4
so the highest offset becomes `8` instead of `0xC`, folding an add. Retail keeps
the pointer at `+0x28` and uses `0xC`/`8`/`4`/`0`. The two-local base recipe, a
single-local form, and separating the counter's initialiser all fail; a struct
would fold the `+0x28` into each store, which is a different shape again.

### Declaring versus assigning a local are different instructions

`func_8002E00C` differed only in *when* the constant `-1` was materialised —
retail puts it between the two callee-saved register saves, we put it after
both. The fix was moving the counter's initialiser out of its declaration:

    s32 i = 0;              ->      s32 i;
    *(s16 *)(a + 0x3C) = -1;        *(s16 *)(a + 0x3C) = -1;
                                    i = 0;

**A declaration with an initialiser and a bare declaration followed by an
assignment are not the same to cc1psx.** The initialiser is evaluated in
declaration order, so it competes with the function's first statements for the
prologue slots; a separate assignment happens where it is written. This is a
fourth thing local declarations control, alongside callee-saved register
choice, constant placement, and address folding — and it is the one that is
purely stylistic in normal C, which is why it is easy to miss.

### Cross-jumping: two identical returns the compiler insists on merging

`func_800601D0` has an early `return -1;` before a search loop and another after
it. Retail keeps both inline — two separate `jr $ra` / `addiu $v0,$zero,-0x1`
pairs. cc1psx merges them into one shared exit reached by a branch, which is two
instructions shorter.

The counting rule says two materialisations means two `return` statements, and
the source *does* have two. **This is the first case where the right source
shape is not enough**: gcc's `jump_optimize` cross-jumps identical tails
unconditionally, and 2.8.1 has no flag to disable it — `-fno-crossjumping` does
not arrive until gcc 3.

So the counting rule needs a caveat: it tells you what the source had, but the
compiler may collapse what the source wrote. When the target has *more*
duplicated tails than we produce, source structure is not the lever, and there
is currently no other one.

### The allocation-flag space is smaller under 4.5, not larger

Every allocation-flag scan in this document was run against **4.6's** cc1psx,
before the version was corrected. `sweep_flags.py` carries about eighteen
hand-picked combinations and none of those allocation options is among them, so
the space had never actually been explored under the compiler the game used.
Re-run under 4.5 against two parked functions:

| flag | 4.5 |
|---|---|
| `-fno-regmove` | **rejected** |
| `-fno-optimize-register-move` | **rejected** |
| `-fno-gcse` | **rejected** |
| `-fno-move-all-movables`, `-fno-reduce-all-givs`, `-fssa`, `-fno-strict-aliasing`, `-fno-if-conversion` | **rejected** |
| `-fcaller-saves`, `-fno-caller-saves`, `-fno-expensive-optimizations`, `-fno-peephole`, `-fno-cse-follow-jumps`, `-fno-thread-jumps`, `-fno-force-mem`, `-fforce-addr`, `-fno-strength-reduce`, `-fno-function-cse`, `-fno-defer-pop`, `-fno-rerun-cse-after-loop`, `-fno-cse-skip-blocks`, `-fno-unroll-loops`, `-fno-inline-functions` | no effect |
| `-fno-delayed-branch`, `-fno-schedule-insns2` | change output (both already swept) |

**gcc 2.8.1 accepts 23 `-f` options; 2.95.2 accepts 29.** The options that could
plausibly steer register allocation simply do not exist in the compiler this
game was built with. That is a firm negative rather than an untried avenue:
**the register-allocation park classes are not flag-reachable, by construction.**

What remains is C-shape search, and the permuter has never run under 4.5 — its
25,000 iterations on `func_8007368C` were spent against the wrong compiler and
tell us nothing.

**Also retested and still not fixed:** `func_8003594C`, against the
`-O2 -G8 -mno-split-addresses` behaviour discovered *after* it was parked. That
flag makes cc1psx materialise the address once (`la $5,D_8009B0F4`) and use it
twice, which is the opposite of the two materialisations retail has. Worth having
tried — parked functions had not been re-tested against mechanisms found after
them since the compiler switch, and that is a gap worth closing routinely rather
than once.

### A batch that mostly did not land, and what it says about the band

One of four. This is the worst yield since the toolchain fix, and the three
misses are all *one* difference each — which is worth recording as a picture of
where the 16-22 band actually is now.

**`func_80019CC8`** leaves a `bgez` delay slot empty where we fill it with the
next `lui`. Sixteen flag combinations including `-fno-delayed-branch`, plus the
nested-to-sequential rewrite, no match. The unfilled-delay-slot symptom that
`-fno-delayed-branch` was found for does not always answer to it.

**`func_80049544`** tests `v > 0 && v < 4` and cc1psx folds it into the unsigned
range check `(v - 1) < 3`, while retail keeps two branches (`blez` then `slti`).
Nested `if`s and a local for the base both still fold. Instruction counts are
equal, so this is a *transformation* difference rather than a shape one — the
source clearly had two comparisons and there is no obvious way to stop cc1psx
combining them.

**`func_8004BAE4`** is one register: retail reuses the `lui` register for the
loaded pointer, ours uses a separate one. Already at `-O2 -G0`, which is the
setting that produces that reuse elsewhere.

The three together suggest the remaining functions in this band are not blocked
on shapes I have not learned, but on a small number of allocator and
transformation behaviours I cannot yet steer. That is a different problem from
the first 150 functions, and it argues for spending the next focused effort on
those behaviours rather than on more candidates.

### Counting materialisations generalises beyond `return`

Three functions have now been fixed by the same act of counting, and it is worth
stating as one rule rather than three special cases:

**Count how many times the target materialises a value. That is how many times
the source writes it.**

| function | target | source |
|---|---|---|
| `func_8004BAA0` | one `subu` reached by two paths | one `return` |
| `func_80047B68` | two `addiu $v0,$zero,1` | two `return 1;` |
| `func_8005A878` | one `addiu $v1,$zero,1` at a join, copied to `$v0` at the end | one variable, one assignment, one `return` |

`func_8005A878` is the version that shows it is not about `return` at all. Retail
zeroes `$v1` in the first branch's delay slot, sets it to `1` at a shared label,
and copies it to `$v0` on the way out — which is `s32 r = 0; if (…) r = 1;
return r;`. Written as three early returns it produced three separate `li $v0,1`
and did not match, even though the instruction *count* happened to be identical.

The corollary is the useful part: **an accumulator variable and a set of early
returns are distinguishable in the object code**, so the target tells you which
one the original used. Look for a value written at a join label and copied to
`$v0` at a single exit — that is an accumulator.

### The shared-exit rule runs both ways

`func_80047B68` returns `1` from both paths and was one instruction short with a
single `return 1;` after the join. Retail materialises the `1` **twice** — once
in the branch delay slot for the early path and once after the call, which
clobbers `$v0`. Two separate `return 1;` statements produce exactly that.

This is the mirror of `func_8004BAA0`, where retail had *one* `subu` serving two
paths and the fix was to merge two returns into one. The rule is symmetric and
reads directly off the target: **count the materialisations of the returned
value. One means one `return`, two means two.** It applies even when both returns
are the same constant, which is where intuition says "surely the compiler shares
it" — after a call it cannot, because the callee owns `$v0`.

**Parked one register assignment away.** With two returns the count is right and
the difference is `addu $a1,$a0,$zero`: retail keeps `arg0` in `$a0` and the
masked copy in `$a1`, while ours puts the masked value in `$a0` and copies
`arg0` out. Three mask forms and sixteen flag combinations. Same `$a0`-as-scratch
symptom as `func_80038498` from the previous batch, which makes two in a row and
suggests it is common in functions that keep both a value and a masked version
of it live.

### Hoisting reads in the source, then letting `-O1` do the rest

`func_80037CE0` needed both halves of a fix that has come up separately before.
First the reads had to be hoisted in the *source* to match retail's order —
naming the `0x34` halfword and the `D_8009B34C` byte in locals, assigned exactly
where retail loads them, took it from two instructions long to the right count.
Then `-O1 -G8` fixed the last difference, a register choice plus one swapped
pair.

Worth noting the order of operations, because doing it the other way round
wastes time: **fix the shape until the instruction count is right, then sweep.**
A sweep over a wrong-length function tells you nothing, and the sweeper cannot
distinguish "wrong flags" from "wrong C".

**Parked: `func_80038498`.** One instruction short, and the missing one is
`addu $a1,$a0,$zero` — retail copies the parameter to another register up front
because it reuses `$a0` for a loaded byte. Ours keeps the parameter in `$a0` and
puts the byte in `$a1`. Four C shapes and sixteen flag combinations. This is the
`$a0`-as-scratch symptom from much earlier in the project, which the 4.5 switch
resolved everywhere it had appeared before — so its reappearance under the right
compiler means it was never purely a version artefact.

### Macro-form addressing does not imply `-G0`

`func_80030E30` and its sibling reach one symbol gp-relatively and another
through the assembler's `$at` macro form, in the same function:

    sb  $v0,%gp_rel(D_8009B2EB)($gp)     <- small data, gp-relative
    lui $at,%hi(D_8009B254)              <- aggregate, assembler-expanded
    sb  $v0,%lo(D_8009B254)($at)

Every earlier macro-form function in this project was `-G0`, so `-G0` and macro
form had become linked in my head. They are not. **`-O2 -G8
-mno-split-addresses` makes cc1psx emit the bare symbol for *every* global and
lets the assembler choose the form per symbol** — gp-relative for small data,
`lui $at` + `%lo` for aggregates. That is the only way to get both in one
function, and it is exactly what these two needed.

This also means the earlier per-file declaration guards are not always the
answer to mixed addressing. The guard changes what one *symbol* looks like; this
flag changes what *all* of them look like while leaving the assembler to
discriminate by size. Try the flag first — it needs no header surgery.

Both combinations are now in `sweep_flags.py`, which had only ever paired macro
form with `-G0` and so could never have found this.

**This is not another instance of the six bugs listed under the sweep-void
section, and the difference matters.** Those were tools reporting on things they
had not measured — a stale object, a flag whose effect was never checked, a
crashed build read as clean. The sweeper here was not broken: it searched the
space I defined for it, and the space was too narrow because I had encoded an
observed correlation ("macro form goes with `-G0`") as if it were a rule.
A tool that lies about what it measured and a tool that measures a space you
drew too small need different remedies — verify the measurement in the first
case, widen the space in the second — so lumping them together would lose what
makes the first six actionable.

### The `$v0`/`$v1` swap class, sixth member and a sharper description

`func_80049CB0` loads the `D_8009B458` pointer twice in one basic block, and the
alias produces both loads correctly. What remains is one register choice, and it
is worth stating precisely because the class keeps growing:

    retail:                            ours:
    lui $v1,%hi(sym)                   lui $2,%hi(sym)
    lw  $v1,%lo(sym)($v1)   <- reuses  lw  $3,%lo(sym)($2)   <- does not
    …
    lui $v0,%hi(sym)                   lui $2,%hi(sym)
    lw  $v0,%lo(sym)($v0)   <- reuses  lw  $2,%lo(sym)($2)   <- reuses

**The second load reuses its address register in both; only the first differs.**
In ours the `lui` register is needed later for a constant, so the pointer goes
elsewhere; retail keeps the pointer in the `lui` register and puts the constant
in `$v0`. Three C shapes and the alias on either side of the pair all fail.

That makes the pattern across the class: **cc1psx and retail disagree about
which of `$v0`/`$v1` holds a value that stays live across a branch.** The one
member solved so far (`func_8003CE74`) was solved by making the live value the
*return* value, which forces it into `$v0`. Where the function has no return
value to give — as here, `void` with two stores — there is no lever yet. Six
members now, and worth a focused attempt rather than one-off guessing when the
mining slows.

### Two idioms worth recognising on sight

**`andi` / `xori` / `sltiu $v0,$v0,1` is `(x & M) == M`.** cc1psx has no
compare-equal instruction, so it xors against the expected value and tests for
zero with `sltiu …,1`. `func_80042960` ends this way and matched first try once
read that way; the sequence is unambiguous.

**A `jalr` through a loaded register is a function pointer in a struct field.**
`lw $v0,0x24($s0)` / `beqz` / `jalr $v0` is a null-checked callback, which is
`VoidFn fn = *(VoidFn *)(arg0 + 0x24); if (fn != 0) { fn(); }`. Note the guard is
in the source — cc1psx does not insert null checks.

Two batches of four have now landed with no iteration at all, which had not
happened before in the 16-26 band. The rules accumulated over the last several
batches — polarity from the fall-through, declaration order, cast at the point of
use, base formation — are now covering most of what these functions need on the
first write.

### `if`/`else` with a join versus an early return

`func_8003D2B8` came out two instructions short as an early return and the right
size as an explicit `if`/`else` assigning to one variable. The two shapes are
distinguishable in the target:

    if/else with a join (retail):     early return (ours):
    beqz  $v0,.L…EC                   beq   $2,$0,$L3
    nop                               addu  $2,$0,$zero   <- return value in
    …work…                                                   the delay slot
    j     .L…F0        <- join        …work…
    sltiu $v0,$v0,0x1                 $L3:
    .L…EC:
    addu  $v0,$zero,$zero

**An explicit `j` to a join label, plus a separate block for the other arm,
means the source assigned to a variable and returned it once.** An early return
lets cc1supply the return value from the branch delay slot and needs no join, which
is the two-instruction saving. Same family as the shared-exit rule from
`func_8004BAA0`, in the opposite direction: there one instruction served two
paths and the source had one `return`; here two paths each get their own block
and the source has one *variable*.

**Parked one register-swap away.** With the `if`/`else` shape the instruction
count, structure and control flow all match; the two loads land in `$v1`/`$v0`
where retail has `$v0`/`$v1`. Swapping the `xor` operands, naming both values in
temporaries in target order, and sixteen flag combinations all fail. Fifth member
of the `$v0`/`$v1`-swap class, and the return-value trick that solved
`func_8003CE74` does not apply — this function already returns the value in
question.

### The alias needs a `-G0` assembler to be worth anything

`func_80044DA0` loads the `D_8009B45C` pointer twice in one basic block. Two
symbols produced the two loads correctly — and the function was still *two*
instructions short, because at `-G8` cc1psx emits the bare-symbol form
`lw $2,D_8009B45C` and a `-G8` assembler collapses each one into a single
gp-relative load instead of `lui`+`lw`. The alias created the second reference
and the assembler then threw away half of each.

`PER_FUNC_AS_FLAGS[...] = "-G0"` fixes it. **So the alias and the `-G0`
assembler are a pair**: the alias makes the second address exist, the `-G0`
assembler makes each one cost the two instructions retail spends. Worth knowing
before concluding an alias "didn't work".

**Size of the unblocked class, revised down again.** Of the 82 same-basic-block
duplicates, only **two** are under 27 instructions, and both are now handled.
The rest are large functions where the duplicate is one detail among many, so
the alias is a prerequisite for them rather than the whole fix. That is still
worth having — it removes a blocker that no amount of C rewriting could clear —
but "unlocks 82 functions" would overstate it, and this is the third time in
two hours that the honest number has been smaller than the first one.

**Parked: `func_8003594C`**, one instruction short and instructive about the
alias's limits. Retail reads `D_8009B0F4` in split form (`lui $v0,%hi` +
`lw %lo($v0)`) and writes it through the assembler's `$at` macro form
(`lui $at,%hi` + `sw %lo($at)`) — mixed addressing modes for one symbol in one
function. An alias gives two split-form materialisations, not one split and one
macro, so the instruction count comes out right but the registers do not.
Reproducing that needs the store emitted as a bare symbol while the load stays
split, and `-mno-split-addresses` is per-function, not per-reference.

### Two `lui`/`addiu` pairs for one symbol means two symbols — and we can now say so

`func_80036BCC` walks two pointers over the same base, one by 2 and one by
`0x1E`, and retail materialises the *same* address twice:

    lui   $v0,%hi(D_801D9174)
    addiu $a2,$v0,%lo(D_801D9174)
    lui   $v0,%hi(D_801D9174)      <- again, same basic block
    addiu $a1,$v0,%lo(D_801D9174)

cc1psx will not emit that from one symbol — it CSEs the address — so
`u8 *rec = D_801D9174; u8 *key = D_801D9174;` comes out an instruction short.
**Two independent materialisations of one address in one basic block mean the
original source saw two distinct objects at the same place.**

`config/symbol_aliases.txt` now exists for exactly this, in the same
`NAME = 0xADDR;` format as splat's own files and read by the same code path.
splat only ever emits one symbol per address and regenerates its auto files, so
the aliases need a file of their own. `func_80036BCC` matches with `key` pointing
at an alias.

**How much this is worth, measured rather than assumed.** A first scan found 343
functions that materialise some symbol's `%hi` more than once, which would have
been a wildly overstated claim: cc1psx reproduces that naturally when the uses
sit in *different basic blocks*, since CSE does not cross them. Restricting to
duplicates with no branch or label between them gives **82** functions, none of
which currently match. The same symbols recur heavily — `D_8009B0F4`,
`D_8009B45C`, `D_8009B458` — which suggests a handful of aliases will cover most
of them.

Worth noting the shape of the near-miss: the difference between 343 and 82 is
the difference between "the pattern appears" and "the pattern needs this fix".
Counting the first and reporting it as the second is the same error as reading a
green build as evidence for an assumption, and it was one refinement away.

### One shared exit in the target means one `return` in the source

`func_8004BAA0` is a `memcmp`: compare `arg2` bytes, return the difference at
the first mismatch. Two natural C shapes came out two instructions long; the
matching one has a **single** `return`.

    while (--arg2 != 0 && *arg0 == *arg1) {
        arg0++;
        arg1++;
    }

    return *arg0 - *arg1;

The tell is in the target: both the mismatch branch and the loop-exhausted path
land on the *same* `subu $v0,$v1,$v0`. **Two paths reaching one instruction means
one `return` statement, not two returns that happen to compute the same thing.**
Writing `if (*arg0 != *arg1) return *arg0 - *arg1;` inside the loop and a second
`return` after it duplicates the subtraction and the loads, which is the two
extra instructions.

Corollary worth stating: folding the comparison into the loop condition with
`&&` is what merges the two exits. A `break` would not — it leaves the loop
condition and the mismatch test as separate branches.

### A `$v0`/`$v1` swap can mean the function returns a value

`func_8003CE74` was parked with structure, instruction count and every `$s`/`$a`
register correct, and `$v0`/`$v1` swapped. Four declaration orders and sixteen
flag combinations found nothing.

**It returns its result.** `$v0` is the return register, so declaring the
function `u32` and returning the mixed value puts that value in `$v0` and
everything else falls into place — no other change. Matched immediately.

This is the mirror of the wrong-return-type problem recorded earlier. There, a
prototype claiming `s32` for a `void` function was invisible because the callers
ignored the value. Here the same invisibility runs the other way: **a function
whose callers all ignore its return value looks like `void` in every call site,
and the only evidence it returns something is `$v0` holding a live value at
exit.** So when the registers are right except for a `$v0`/`$v1` swap, check
whether one of them holds a result at the return.

Tried on the other two members of that park class and it does not fit them, so
this is a specific tool rather than a general one — `func_80037D2C` and
`func_80071424` both come out longer when given a return value.

### Forcing base formation, complete recipe

This has now come up six times and each instance needed a slightly different
shape, so here is the whole ladder in one place. The symptom is always the same:
**one instruction short, around an address built from a symbol plus an offset.**
cc1psx folds the offset into the `%lo` where retail forms the base in a register
first.

| what retail does | what works |
|---|---|
| base, then one field access | a plain struct is enough |
| base, then *two* different offsets | declare the object as an unsized array of the struct and index `[0]` |
| base, then a *variable* index | index in a `u8`/`s32` local **and** the element address in a pointer local |
| base, then a *constant non-zero* offset | assign the base to one local, then add the offset in a **separate statement** |

The last one is `func_8002E370`, and it is the least obvious: `Rec4C *p =
&D_800EB010[2]` folds, and so does `p = D_800EB010; p += 2`. What works is

    Rec4C *base = D_800EB010;
    Rec4C *p;

    p = base + 2;

Two locals and a separate assignment. Splitting the declaration from the
arithmetic is what stops the fold — the base becomes a value in its own right
rather than part of an address expression.

**A note on measuring this.** `func_8002E370` was one instruction short and
three functions *before* it in address order showed up in the differing list.
That looked like real breakage from the header changes in the same batch and was
not: `build.py` regenerates the linker script from per-function object sizes, so a
wrong size shifts run boundaries and can move objects placed *earlier* in the
script than the culprit. **The "everything after it" wording in the size warning
is too weak** — with linker-driven layout, one wrong size can perturb anything.
Remove the wrong-sized function first, then read the list.

### The sweeper counted failed builds as matches — sixth of the same shape

`sweep_flags.py` reported `func_8001755C` matching at
`-O2 -G8 -fno-schedule-insns2 -fno-delayed-branch`. That configuration does not
**link**: at `-G8` the compiler makes `D_80010000` gp-relative, which overflows
the small-data section, and the linker says

    small-data section too large; lower small-data size limit
    src/func_8001755C.c:(.text+0x24): relocation truncated to fit: R_MIPS_GPREL16

The sweeper's logic was: if the byte-identical line is absent, check whether the
function is named in the output; if not, call it clean. A link error names the
*file* as `src/func_8001755C.c:(.text+0x24): …`, which matches none of the
patterns it looks for. **So a crashed build read as a clean one.** Every `-G8`
combination in the sweep was failing to link, and the first of them was reported
as the answer.

Fixed by requiring the build to have completed — non-zero exit or a missing
`sha1  :` line is now `build failed`, never a match. Re-swept honestly, the real
answer is `-O2 -G0 -fno-schedule-insns2 -mno-split-addresses` with a `-G0`
assembler, and the log now shows eight `build failed` lines above it, which is
itself the useful information that this symbol cannot be `-G8` at all.

**Absence of a complaint is not evidence of success when the thing that would
have complained never ran.** That is the sixth instance in this project of one
failure shape (a seventh, `try_func.py`, is at the end of the table), and the second inside `sweep_flags.py` alone. The running list:

| where | what varied unnoticed |
|---|---|
| `config/flag_overrides.json` | not in the staleness check |
| `-fno-schedule-insns` | effect "verified" against the wrong SDK |
| `YGOFM_DROP_POSTPASS` | not in the flag stamp |
| `sweep_flags.py` (as-flags) | set `cc` but inherited `as` |
| prototype reconcile regex | silently skipped pointer returns |
| `sweep_flags.py` (build status) | treated a failed build as clean |
| `try_func.py` | kept its own stale copy of every toolchain path |

Every one of them was a tool reporting confidently on something it had not
actually measured. When a tool says "no", the next question is whether it could
have said "yes" — and when it says "yes", whether the run it judged completed.

### `switch` and an `if` chain are distinguishable, even with two cases

`func_800603DC` selects one of three function pointers by comparing against two
constants. Written as two `if`s it comes out an instruction short; written as a
`switch` it matches. The shapes differ in where the *returns* live:

    switch (retail):                    if chain (ours):
    beq  $a0,$v0,.L…E40                 bne  $4,$2,$L2
    nop                                 nop
    ori  $v0,$v0,1                      lui  …E40        <- return inlined
    beq  $a0,$v0,.L…ED0                 j    $31            in the fall-through
    nop                                 addiu …E40
    j    .L…E20        <- default       $L2:
    lui  …E20 (delay)                   ori  $2,$2,1
    .L…E40: …                           …

**A `switch` puts every case in its own block and branches *to* them, leaving
the default as the fall-through. An `if` chain inlines the first body into the
fall-through.** So if the target's comparisons are consecutive with nothing
between them, the source was a `switch` — even with only two cases, where one
might assume gcc would degenerate to the same code. It does not.

Also visible here: gcc shares a `lui` between two constants that differ only in
the low half, comparing against `0x2000000` and then `ori`-ing to get
`0x2000001`. That is a hint the two case labels are adjacent values, which is
worth knowing when the constants look arbitrary.

### A reconciliation regex that missed pointer return types

The prototype-vs-definition sweep added earlier silently skipped any function
returning a pointer. Its pattern required whitespace between the return type and
the name, and `u8 *func_80089E20(...)` has none — the `*` binds to the name. So
`func_80089E20` kept a wrong `void func_80089E20(void)` prototype through a
sweep that reported success. Fixed. **A cleanup pass that cannot fail loudly is
another unwatched input**; the same shape as the four bugs listed above, and the
fifth time in this project. The tell was that it reported "reconciled: 0" while a
conflict existed — a zero from a tool that should have found something is a
result, not a non-result.

### Branch polarity is the most common single fix, and it has a tell

Two of four functions in one batch failed on nothing but branch polarity, which
makes it the most frequent single cause in this project so far. It also has a
reliable tell, worth stating as a procedure rather than a rule of thumb:

**Look at which path falls through in the target.** cc1psx emits the
*fall-through* path for the branch that is written as not-taken. So if retail
falls through into the body of an `if`, the source tested the positive
condition; if it branches away into the body, the source tested the negation.

- `func_80049600`: retail does `beqz $v0,.L…` on `(v < 0x15)`, i.e. it branches
  away when the test *fails* and falls through into the work. So the source is
  `if (v < 0x15) { … }` with the `0xFF` return as the outer else — not two
  sequential early returns, which invert it.
- `func_8005F588`: retail does `bnez $a0` to the store-zero path, so the source
  tests `arg0 == 0` first and stores `-1` in that branch. Writing the `!= 0`
  case first swaps both arms.

### `-O2 -G0` versus `-O1 -G0` has a visible signature

Both appear in the tables and picking wrong costs an instruction. The tell is
where the prologue sits relative to a global load:

    -O2 -G0:                       -O1 -G0:
    lui   $v0,%hi(sym)             addiu $sp,$sp,-0x18
    lw    $v0,%lo(sym)($v0)        sw    $ra,0x10($sp)
    addiu $sp,$sp,-0x18   <- fills lui   $v0,%hi(sym)
    sw    $ra,0x10($sp)      the   lw    $v0,%lo(sym)($v0)
    lh    $v1,0x7E2($v0)     delay nop             <- maspsx must insert one

If the target loads a global *before* the prologue, `-O2` scheduled the prologue
down into the load-delay slot and there is no `nop`; `-O1` leaves the prologue
first and needs the `nop`. `func_80049F10` was one instruction long as `-O1 -G0`
purely because of that `nop`, and matched at `-O2 -G0` unchanged.

One more from this batch: `func_80049F10` also needed its `0x7E2` read hoisted
*above* the two stores, matching retail. A read whose result is only used later
still has a position, and the source order fixes it.

### Stack-built structs, and source order deciding codegen order

`func_80044FFC` builds a record in its own frame and passes its address on. The
frame is `0x48`: the struct at `+0x10`, `$ra` at `+0x40`, so the struct is
`0x30` bytes — **the frame layout gives the struct's size**, which is often the
only way to know it.

Getting it byte-exact took three passes, and each failure was informative:

| version | result |
|---|---|
| `m.unk2 = arg1` with a `u16` field | one instruction short — no `andi` |
| add `& 0xFF`, assign `unk8` first | right size, `li` for the constant two slots late |
| assign `kind` first, then `unk8`, `unk2`, `unk1` | matches |

Two rules out of that. **A `u16` field does not imply a `u16` value**: retail
masks the argument to `0xFF` before storing it into a halfword, so the mask is
in the source and has to be written. And **the order of field assignments in the
source decides the order of the setup instructions**, including where a constant
is materialised — it is not just the stores that move. When a function is the
right size but one instruction sits in the wrong slot, reordering the source
statements is the first thing to try.

Also landed: two record-scan loops (`func_8004002C`, `func_8004006C`) over
`0x70`-byte records, returning an index or `-1`. Both wanted a pointer walked
alongside an independent counter rather than one derived from the other, which
is what the retail code does — `$a0` advances by `0x70` while `$v1` counts.

### The byte-stream cursor idiom, and `u8` locals costing an instruction

A shape that recurs across the script interpreter: a byte read through a table
of cursors indexed by a signed byte at +0x58 of the object.

    u8 **pp = (u8 **)(arg0 + *(s8 *)(arg0 + 0x58) * 4);
    u8 *p = *pp;

    *pp = p + 1;
    /* ...use *p... */

`func_8003B7E0` established it and `func_80038094` and `func_80038898` reuse it
unchanged. Worth recognising on sight — the `lb 0x58` / `sll 2` / `addu` /
`lw 0(...)` / `lbu 0(...)` / `addiu +1` / `sw` sequence is this and nothing else.

**A `u8` local costs an instruction when it feeds a wider parameter.** In
`func_80038094` the byte comes from `lbu`, already zero-extended, but holding it
in a `u8` and passing it to an `s32` parameter makes cc1psx emit a redundant
`andi $a1,$a1,0xFF`. Declaring the local `s32` matches. This is the same
narrowing behaviour that forced `func_8007058C` and `func_8003B7E0` to return
`s32`, now showing up for a local rather than a return value: **hold the raw
value in the widest natural type and let the store or call narrow it.**

**Parked from this batch:** `func_80030F40` and `func_80037D2C`, both on
instruction *order* with the right count. Retail hoists all four argument
registers above two global stores in the first, and interleaves a gp-relative
load into a load-delay slot in the second. Sixteen flag combinations and two C
reorderings each; no match. These are scheduling differences of a kind not yet
understood — distinct from the old coupled-ordering class, which the 4.5 switch
resolved.

### A third knob for the `-G` symptom: per-file declarations

`func_8001BD48` reaches `D_8009B398` through `%hi`/`%lo` **and** `D_8009B164`
gp-relatively, in the same function. That rules out both existing knobs: `-G0`
cannot emit gp-relative addressing at all, and declaring `D_8009B398` unsized
globally would break the functions that reach it gp-relatively. The *declaration*
has to differ per file — which is exactly what the original build had, with a
header per translation unit.

`include/variables.h` now supports that:

    #ifdef D_8009B398_IS_AGGREGATE
    extern u16 D_8009B398[];
    #else
    extern u16 D_8009B398;
    #endif

and a file opts in with `#define D_8009B398_IS_AGGREGATE` before
`#include "common.h"`. Verified to produce the right addressing.

**The function itself is still parked, for an unrelated reason**, and the
distinction matters: the guard fixed what it was for. What remains is control
flow. Retail leaves the first branch's delay slot empty and materialises the
constant `1` twice, once for the store and once for the return. Nested `if`s
come out one instruction short, sequential early returns one long, and the
sweeper finds nothing — including `-fno-delayed-branch`, which is the obvious
candidate for an empty delay slot and does not help here.

The mechanism is kept despite its first intended user being parked, because the
situation it solves is structural: any function mixing gp-relative and
`%hi`/`%lo` access to *small* symbols will need it, and there is no other way to
express that in a single central header.

### A wrong *return* type hides exactly like a wrong arity

Three prototypes generated from a loose heuristic — "the asm mentions `$v0`,
so it returns something" — declared `s32` where the real definition is `void`.
cc1psx caught it the moment those functions were decompiled, because the
defining file includes the header.

**But the thunks that call them had already matched byte-for-byte with the
wrong prototype.** Returning a value costs no instructions when the caller
ignores it, for the same reason forwarding arguments costs none: `$v0` is
already where it needs to be. So a wrong return type is invisible until
something depends on it, exactly like a wrong arity.

Two consequences. The `/* PROVISIONAL */` marking should cover return types and
not just parameters — a prototype is a guess in both halves. And "the asm
mentions `$v0`" is not evidence of a return value; `$v0` is the general scratch
register. Evidence is `$v0` live at *every* exit, or a caller that uses it.

Prototypes are now reconciled against real definitions whenever one is written,
which is worth doing as a sweep rather than waiting for cc1psx to object one
file at a time.

### The `jal` class after the version fix: three batches, 21 of 21

With the right compiler, the flag tables 40% smaller, and a sweeper that no
longer lies, hit rate went from ~60-85% to **100% across three batches** —
`func_800159D8` and five siblings (two-call thunks), `func_80038690`,
`func_80042A78`, `func_80047278`, `func_80059C9C`, `func_8005C530`, the `func_80015C0C` family, three multi-call thunks, and
`func_800493F8`. Only the last needed a flag override.

**One of them is a reminder that C form and flags are not independent.**
`func_800493F8` came back empty from a full sixteen-combination sweep, then
matched at `-O2 -G0` once the C was fixed. The C had materialised a constant
before the call, pinning it in `$s0` across the call and adding a register
save; no flag can undo that. **Sweep after the shape is right, not instead of
getting it right** — a sweep over a wrong shape only tells you the shape is
wrong, and it looks exactly like "unreachable". That is the clearest
measure of what the wrong compiler was costing: not just the parked functions,
but a third of every batch.

Two practical notes from writing them:

**A thunk's parameters come from its callee's prototype, not from its own asm.**
Six two-call thunks looked argument-free; two of them call functions that read
`$a0`, and cc1psx refuses to compile the call rather than silently forwarding
nothing. Deriving the thunk's signature from `include/functions.h` — after
filling in the callee from *its* asm — is the reliable order of operations.

**`D_800E9EC8[6] |= 2` matches without any struct trick**, even though it is a
read-modify-write of one byte and the retail code forms the base with
`lui`/`addiu` before both accesses. So the struct-array pattern is for the case
where two *different* offsets are touched; a single offset read and written
folds correctly on its own. Four existing functions already use this symbol as a
plain `u8` array, and leaving that alone was right.

### The struct-array pattern generalises, and the park is nearly dry

Four more parked functions fell to the pattern from the previous section plus
one loop-shape fix, taking the total to 237 and leaving three parked.

`func_80035DF4` walks 0x26C records with a 0x1C stride, clearing bytes at +0x11
and +0x18. It was one instruction short because cc1psx folded the `+0x18` into
the `%lo` where retail forms the base and then adds `0x18` separately. Declaring
the object as `Rec1C D_800EB288[]` — an array of the record struct, with the two
cleared bytes as named fields — and walking `p++` matched immediately. **Same
mechanism as the two-halfword store: indexing forces the base into a register
before any field offset applies.** It is worth reaching for this shape whenever
a function is exactly one instruction short around a based address.

`func_800428EC` was one instruction long, and the fix was to *stop* helping.
`D_8009AF74[arg0[0x17]]` inline matches; hoisting the table into a local `u16 *`
first adds an instruction. The same is true of the index. A local variable is
not free — it can force an address to materialise that retail folded.

`func_8005B5FC` was two instructions long as a `for` loop and matches as a
`do`/`while(--i != -1)`. The `-1` sentinel lives in a register across the loop
in retail, which is what the `do`/`while` form produces and the `for` form does
not. `while (arg2-- != 0)` does not work either — the counter's *form* matters,
not just its trip count.

`func_80049200` needed only `-O2 -G0`, found by the sweeper. Worth noting that
this is the same function whose sixteen-combination sweep came back empty
earlier in the project: that sweep ran under the staleness bug, against the
wrong compiler, with the sweeper's own inherited-`as`-flag bug. Three
independent reasons the old answer was worthless.

**Still parked: `func_8003F7D4`, `func_80071424`, `func_80071460`** — from ~50 at
the session's start. The last two are the `D_800F5B98` store family and differ
only in which register holds a temporary; their two siblings match.

### Two field accesses: index an unsized array of the struct, not the struct

The rule recorded earlier was that modelling an object as a struct reproduces
retail's base-then-offset addressing. That holds for **one** field access. With
two, cc1psx folds the first offset into the `%lo` and forms the base only for
the second, coming out an instruction short:

    ours:                          retail:
    lui   $2,%hi(D_800FE040)       lui   $v0,%hi(D_800FE040)
    sh    $4,%lo(D_800FE040)($2)   addiu $v0,$v0,%lo(D_800FE040)
    addiu $2,$2,%lo(D_800FE040)    sh    $a0,0x0($v0)
    sh    $5,2($2)                 sh    $a1,0x2($v0)

**The fix is to declare the object as an unsized array of the struct and index
element 0**, `extern ScreenPos D_800FE040[];` with `D_800FE040[0].x = ...`.
Indexing forces the base into a register before any field offset is applied.
Both stuck functions then came down to flags, and both were found by
`sweep_flags.py`.

What *doesn't* work, recorded because each looks plausible: a plain struct
(folds), a local `ScreenPos *` (folds), retyping the symbol as a struct
(folds), and `volatile` — which does materialise the base but adds an
instruction. And a local pointer declared *before* a call keeps the base in
`$s0` across it, adding a register save retail does not have; the call has to
come first.

**A claim from two commits ago needs correcting.** I deleted the
`-fno-schedule-insns2` flag lists after the 4.5 switch, saying every function
that needed them under 4.6 matches without them. That was true of the corpus at
that moment and false in general: `func_800855B0` needs
`-O2 -G0 -fno-schedule-insns2 -mno-split-addresses`. Restored. The accurate
version: the flag was *usually* compensating for 4.6, most entries went away,
and it is still occasionally what retail wants. "No current function needs it"
is not "nothing needs it" — the same shape of error as reading a passing build
as proof of an assumption.

### Auditing the flag tables after the version fix — and walking into the same trap a third time

Every entry in `PER_FUNC_FLAGS`, `PER_FUNC_AS_FLAGS`, and the three post-pass
sets was derived under PsyQ 4.6, so each was an untested inherited assumption.
`tools_src/audit_flags.py` drops them one at a time and rebuilds. To make that
possible `config/flag_overrides.json` now accepts a `null` value meaning "use
the default" — before, it could only add or change an entry, never remove one,
so no entry could be falsified.

**Result: 29 of 71 flag overrides were unnecessary, and 22 could be deleted
outright.** The tables went from 71 entries to 42 compiler + 40 assembler.
Notably *every* `-fno-schedule-insns2` entry vanished — that flag existed
purely to work around 4.6 running the post-reload scheduler before register
allocation, and nothing needs it under 4.5. The flag lists for it are gone;
`sweep_flags.py` still tries it, since a search space costs nothing to keep
wide.

**Decoupling that the audit exposed.** Membership of `DELAY_SLOT_MACRO_FUNCS`
used to imply `-O1 -G0 -mno-split-addresses` *and* a `-G0` assembler *and* the
post-pass. All seven members match with **default** flags under 4.5 while still
needing the post-pass, so the set now means only what its name says. The
coupling was compensating for the wrong compiler.

**Then the same bug for the third time, and it is worth being blunt about.**
The post-pass audit needed a way to drop a post-pass, which the override file
cannot express, so it got an env var: `YGOFM_DROP_POSTPASS`. It reported **8 of
15 post-pass entries unnecessary**. All eight were false. The flag stamp
recorded compiler flags, assembler flags, and the SDK path — but not post-pass
membership. So the env var changed no stamp and no mtime, the stale object was
reused, and the audit read a correctly-built object as proof that the transform
producing it was unnecessary.

I had already written the rule for this — *"when a tool's input is not a file
the build system watches, the build system will lie to you and the tool will
look like it is working"* — and then introduced a **new** unwatched input and
believed the output. The first instance was `config/flag_overrides.json`, the
second was reading a green build as evidence a spurious flag did something,
this was the third.

The fix is structural rather than another patch: the stamp now names **every**
input that shapes an object — compiler flags, assembler flags, SDK path, and
post-pass membership. With it, the honest answer is **0 of 15 post-pass entries
are unnecessary.** All three post-passes are real, including the epilogue
hoisting, so the "two assemblers in one binary" reading survives.

The generalisable part: an audit tool is only as trustworthy as the build's
dependency tracking, and *adding a knob to a tool adds an input to the build*.
Any new way to vary a build has to be registered with the staleness check in
the same commit, or the tool will confidently report that nothing matters.

### Every flag sweep before this commit was void. Read this before trusting one.

`config/flag_overrides.json` feeds `PER_FUNC_FLAGS`, but it was **not** an
input to the staleness check. `compile_c()` rebuilt an object when `src/*.c`,
`build.py`, or a header changed — never when only the override file changed.

So `sweep_flags.py`, whose entire method is "rewrite the override file, run the
build, look at the result", **reused the stale object on every combination
after the first.** Its first combination is `-O2 -G8`, the default, which is
what the existing object was already built with. Every later combination
reported that same default result. The tool printed sixteen lines and tested
one thing.

That invalidates every "no combination matched" in this document that came
from a sweep, including the thirteen parked candidates and the batches after
them. Those results say nothing. They need re-running.

It also produced a wrong conclusion I had already written down. `func_80071424`
and its three siblings were one instruction short; `-fno-schedule-insns2`
fixes them, and the sweep said no. Checking cc1psx output directly showed the
flag *did* change the output and *did* produce the right shape — the build
simply never recompiled. Two of the four then matched immediately.

**Why an mtime dependency is not the fix.** Adding `_OVERRIDES` to the
dependency list looks right and is wrong: `is_stale()` deliberately treats a
missing dependency as stale, so with no override file present — the normal
state — every function would rebuild on every run, turning a 1-second
incremental build back into a 3-6 minute one.

**What is the fix.** The resolved flags are themselves an input, so they are
now recorded in `<obj>.flags` beside each object, and the object is stale when
that stamp is absent or differs. This is exact in both directions: adding,
changing, and *removing* an override all trigger a rebuild of exactly the
affected functions.

The general lesson is narrower and sharper than "verify your tools". It is:
**when a tool's input is not a file the build system watches, the build system
will lie to you and the tool will look like it is working.** Both earlier rules
in this document — the false negative on `-fno-schedule-insns`, and the
spurious override that a green build seemed to justify — were the same failure
wearing different clothes. The stamp closes the whole family.

### A sub-pattern inside the register-allocation class: `$a0` as scratch

Three functions parked in one batch (`func_80042874`, `func_800495A4`,
`func_8007368C`) turned out to share something specific, and it is worth
writing down because the register-allocation class has been treated as
structureless until now.

In all three the instruction sequence is identical to retail — same opcodes,
same order, same offsets — and only the register *assignment* differs. And it
differs the same way each time: **we use `$a0`/`$t0` as a scratch temporary
where retail uses `$v0`/`$v1`.**

    retail:  lbu  $v0, 0x814($v0)      ours:  lbu  $4, 2068($3)
    retail:  lbu  $v1, 0x0($v0)        ours:  lbu  $4, 0($2)
    retail:  lw   $v0,0x38($sp) / $v1,0x30 / $t0,0x34
    ours:    lw   $3,48($sp)   / $8,52     / $2,56

cc1psx knows the argument registers are dead after the call and reuses them;
retail's build preferred the return registers. Whatever causes that, it is
*systematic*, not random — so this is a candidate for a single fix that
unlocks a group rather than three separate puzzles. The obvious guesses
(`-O1`, `-fno-schedule-insns2`, and the rest of the sweeper's sixteen
combinations) do not do it.

**The permuter was pointed at it and could not reach it either.**
`func_8007368C` ran 25,274 iterations over 40 minutes: best score **10**, hit
7,859 times, never 0. Score 10 is the floor for "structurally identical, one
register wrong" — the search saturated there immediately and stayed. Combined
with a sixteen-combination flag sweep (run *after* the staleness fix, so this
one counts) and four hand-written C shapes, the evidence is now:

- not reachable by compiler flags — **but note this line was measured against
  4.6's cc1psx, before the version was corrected.** It is left as written
  because the conclusion happened to survive re-measurement under 4.5; see
  "The allocation-flag space is smaller under 4.5, not larger" below for the
  scan that actually counts
- not reachable by C-level rewriting — 25k random variants and 4 reasoned ones
- structurally exact otherwise — same opcodes, order, and offsets

**That combination points somewhere specific, and it is worth stating as a
hypothesis rather than leaving the class as "hard".** If no C and no flag can
make *this* cc1psx emit retail's allocation, the likeliest remaining
explanation is that some translation units were not built by *this* cc1psx.
Mixed SDK versions across objects were normal for PS1 titles.

There is already independent evidence pointing the same way: the epilogue
hoisting above is a case of *byte-identical cc1psx output* assembling into two
different shapes depending on address region. That is two assemblers in one
binary. If the assembler differed between regions, the compiler plausibly did
too — and the affected functions would show exactly this symptom, a correct
structure with an allocation this compiler will not produce.

**This is untested.** Testing it means obtaining another PsyQ version's cc1psx
(decomp.me exposes several) and checking whether one of them reproduces a
parked function directly. Cheap to falsify, and if it holds it reclassifies
this whole park rather than one function.

### `ByteReader` and the limit of the struct trick

`func_80070988` reads the field at +4 and writes the field at +8 of
`D_800F5BE8`. The existing note in `include/variables.h` says modelling that
object as a struct is what makes the retail base-then-offset addressing come
out, and that is true when there is *one* field access. With *two*, cc1psx
uses a single `lui` and folds both `%lo` offsets, dropping the `addiu` that
forms the base — two instructions short.

Three C forms were tried: the direct expression, a local `ByteReader *` before
the call, and the same local after the call. The middle one keeps the base in
`$s0` across the call, which adds a register save retail does not have; the
other two both fold. Parked. The struct field at +4 was added to the typedef
anyway, since it is now known to exist.

### The coupled-ordering park: one flag, two orderings, opposite directions

A recurring shape now has four members (`func_80024954`, `func_80038388`,
`func_800383B0`, and the `func_80024060` family that *did* match). All are
`$s0`-saving wrappers: save `$s0`, call, then store something through `$s0`.

The mismatch is one swap in the epilogue. Retail:

    sb   $zero,0x60($s0)      <- jal delay slot
    sb   $v0,0x61($s0)
    lw   $ra,0x14($sp)

Ours at `-O2 -G8` schedules the `lw $ra` up one slot, before the last store.
`-fno-schedule-insns2` fixes exactly that — **and flips the prologue**, emitting
`sw $ra` before `sw $s0` where retail has `sw $s0` first. `-O1` behaves like
`-fno-schedule-insns2` (byte-identical cc1psx output, checked). So:

| | prologue order | epilogue order |
|---|---|---|
| `-O2 -G8` (default) | correct | wrong |
| `-fno-schedule-insns2`, `-O1` | wrong | correct |

Retail wants both. No combination in the sweeper produces it, and `volatile`
on the store does not stop the reorder either. **This is a distinct class from
plain register allocation** — the register assignment is already right, and the
instruction *set* is right; only two positions are swapped, and the one flag
that governs them moves both at once. Worth recording separately, because a
future fix here unlocks several functions at once rather than one.

### Casting at the point of use, third confirmation

`func_8003FF58` negates a value then passes it on. All three forms were tried
and only one matches, which is a clean illustration of a rule that keeps
recurring:

| form | result |
|---|---|
| `s32` parameter, plain call | 2 instructions short — no truncation emitted |
| `s16` parameter | 2 instructions long — extends on entry *and* after the negate |
| `s32` parameter, `(s16)` cast at the call | matches |

**The conversion belongs where the value is used, not on the declaration.**
Same rule as the earlier `(s8)` and the `-1`-into-`u8` cases.

### Signatures without evidence, and how they will bite

Argument forwarding costs no instructions, so a pure thunk's asm is silent
about its callee's arity. Nine prototypes added while opening the `jal` class
are therefore guesses; they are marked `/* PROVISIONAL */` in
`include/functions.h` with the reasoning inline.

Evidence for a signature comes from two places, and only these: the callee
reads `$aN` before writing it, or some *call site* sets `$aN` up. The second
matters — `func_80038024` never reads `$a1`, but `func_80038070` loads it, so
the two-argument declaration is supported by the caller even though the callee
ignores it. An arity scanner that only looks at the callee will under-report;
do not trust it alone.

This costs nothing today, because forwarding is free and the bytes match. It
bites at the first function that calls one of these *with* real argument setup:
that function will be blamed for a mismatch that is really a stale prototype.
Widen the prototype then, do not fight the caller.

### Predicting `-G0` before writing the C, and why it cannot be exact

The original game was built from ~234 translation units, and the `-G` model is
a property of the *unit*, not the function. So flags ought to be predictable
from position. Two attempts, both now in `tools_src/predict_flags.py`:

**`docs/FILE_BOUNDARIES.txt` is not what its header claims.** All 233
boundaries fall in `0x80073840..0x800906E0`. The game's own code, everything
below `0x80073840`, has **zero** detected boundaries — the 16-byte-padding
heuristic only fires in the library region, because those objects were linked
with alignment padding and the game's were not. The file is still valid for
what it covers, and the predictor is *consistent* there: of the three
library-region units holding several decompiled functions, all three looked
like they disagreed on flags, and in every case the odd function out also
matched under its unit's majority flags. Those were underdetermined, not
contradictory. Tiny functions often compile identically at `-O1 -G0` and
`-O2 -G8`, so a match does not pin the flags down.

**For the main body, `%gp_rel` gives a high-recall negative filter.** A
function using `%gp_rel` was certainly `-G8`. Maximal runs of consecutive
functions with no `%gp_rel` that still touch globals are candidate `-G0`
units: 19/19 recall on the known `-G0` main-body functions, but ~51%
precision. Use it the negative way — **outside such a run, do not waste a
sweep on `-G0`.** That halves the search space.

**The exact-looking test is contaminated by our own declarations, and this is
the useful finding.** A symbol reached via `%gp_rel` anywhere must fit inside
the `-G8` threshold, so a `%hi`/`%lo` access to that same symbol looks like
proof of `-G0`. It is 97% precise but only 27% recall, and the four false
positives explain both numbers. `func_80044CFC` stores to `D_8009B450` via
`%hi`/`%lo` and matches at **`-G8`** — because we declare `D_8009B450` as an
*unsized array*, and cc1psx cannot place an object of unknown size in small
data. Other functions reach the same symbol gp-relative.

So there are **two independent knobs for the same symptom**: compile the
function `-G0`, or declare the symbol unsized. Both produce `%hi`/`%lo`. The
flag tables in `build.py` are therefore a record of *a* byte-exact
configuration, not a reconstruction of the original build — those are
different things, and only the first is required. Worth keeping in mind
before treating `PER_FUNC_FLAGS` as evidence about the game's real makefile.

**Corpus answer on `-O2`:** across 179 matching functions, 113 are at `-O2`
and 66 at `-O1`. `-O2` stays the default because it is the plurality and
because the two are indistinguishable for many small functions, but 66
overrides is too many to keep calling `-O2` "confirmed". It is not.

### `-fno-schedule-insns2` — the load-delay counterpart

There are **two** schedulers, and only the second one matters to us.

`func_8001B780` was parked because cc1psx hoisted an unrelated `lw` into the
load-delay slot of a `lb`, where the retail code leaves the slot empty. I first
recorded `-fno-schedule-insns` as tried-and-useless, then corrected that to
"accepted but byte-identical, so a non-matching build says nothing about it."

**Both of those were wrong.** `-fno-schedule-insns` changes cc1psx 4.5's output
for 15 of 60 sampled `src/func_*.c` files — a quarter of them. The
byte-identical measurement was taken with `try_func.py`, which at the time
still pointed at psyq46 and `--aspsx-version=2.86`; it was hashing the output
of *the wrong compiler*. `func_80013B04` is the counter-example that finally
surfaced it: 25 differing instructions out of 25 with the flag on.

The lesson survives the correction, only sharper. The rule was "a negative
result only counts if the flag actually changed the output" — and the check
that was supposed to enforce it was itself run against the wrong toolchain.
Verify the flag changed the output *and* verify the thing doing the verifying
is the build's own toolchain. `try_func.py` now imports every constant from
`build.py` for that reason.

`-fno-schedule-insns2` — the *post-reload* scheduler — is the one that governs
load-delay slot filling in gcc 2.7.x MIPS. With it, `func_8001B780` compiles to
the target instruction-for-instruction *and* register-for-register:

    lb   $3,14($4)      <- slot left empty, aspsx fills the nop
    sll  $2,$3,4
    ...

**A negative result only counts if the flag actually changed the output.** Before
recording "flag X does not help", hash cc1psx's output with and without X. This
is the same class of mistake as the silent string-substitution failures in
`build.py`, and it is worse, because a false "already tried" entry closes off a
real avenue permanently.

`-fno-delayed-branch` remains useful for *branch* delay slots, but only
alongside a correct signature. The two flags are independent; the sweeper now
tries `-fno-schedule-insns2` on its own, with `-G0`, with `-fno-delayed-branch`,
and with `-mno-split-addresses`.

**Sweep one candidate at a time.** A wrong-sized function shifts everything after it, so with several broken candidates in `src/` at once the difference list is mostly cascade and a function can look like it matches when it does not. Two of the thirteen appeared to match while swept together and did not when swept alone. `tools_src/sweep_flags.py` runs one function's combinations; keep only matching candidates in `src/` between runs.

**A specific sub-case: the retail code overwrites the source pointer's register with its last load.** Where the original reads `lbu $a1, 0x0($a1)` -- destroying the pointer because it is dead afterwards -- gcc allocates a fresh register instead. Structure and instruction count are otherwise identical. Seen in `func_8003006C` and `func_8004143C`; `-O1`/`-G0` and the deref form do not shift it. (`func_8006C30C` looked like this class but was in fact plain register alternation, and `-O1` did fix that one, so check whether the pointer is genuinely being overwritten before assuming.)

**Three recurring causes of a wrong-sized function** (all cost an extra instruction, all cheap to fix once recognised):
- *Reloading a global.* Dereferencing the same global pointer twice makes gcc reload it. The retail code loads once — assign it to a local first (`u8 *p = D_8009B45C;`).
- *An over-narrow parameter.* A `u8` parameter makes gcc mask with `andi $a0,$a0,0xff` before storing. Where the retail code stores `$a0` straight through, the parameter was word-sized — use `s32`.
- *Pointer arithmetic written the wrong way round.* `arg0 += arg1 * 4; return arg0[0x56];` matches where `return arg0[arg1 * 4 + 0x56];` picks a different register.

**`-O1` vs `-O2` shows up constantly**, and the tell is usually scheduling or register reuse: at `-O2` gcc hoists constants into separate registers, at `-O1` it computes one, uses it, then computes the next into the same register. When a function is the right size but the registers differ, try `-O1` before rewriting the C.

### Two aspsx behaviours maspsx does not reproduce (both now emulated)

maspsx exists to make cc1psx output acceptable to GNU `as`, but it does not cover everything the original assembler did. Two gaps each blocked a whole class of functions; both are now handled by post-passes in `build.py`, applied only to the functions listed in `DELAY_SLOT_MACRO_FUNCS` / `SMALL_DATA_NOP_FUNCS`.

**1. Address macro split across a branch delay slot** (`fill_delay_slot_with_macro_tail`). cc1psx with `-mno-split-addresses` emits a bare-symbol store like `sw $4,D_800F5F80` and leaves expansion to the assembler. aspsx expanded it *and* scheduled the second half into the following delay slot, producing three instructions:
```
lui $at,%hi(sym)
jr  $ra
sw  $a0,%lo(sym)($at)
```
GNU `as` treats the expansion as indivisible, so it emits four and the function is one instruction too long. maspsx passes this case straight through. Recognising the exact `memop / jump / nop` sequence and doing the expansion ourselves recovered 7 previously-parked functions at once.

**2. Load-delay nops for extern small-data symbols** (`insert_small_data_load_delay_nops`). On the R3000 a loaded value is not available to the next instruction. maspsx normally inserts the nop, but skips it when the following instruction will be expanded through `$at` -- the `lui` of that expansion fills the delay naturally. To decide, it needs to know whether the symbol is small data, and it **deliberately discards `.extern sym,size`** when building that set (it tracks only `.comm`/`.lcomm` and explicit `.sdata` sections). Every global we declare is extern, so maspsx assumes `$at` expansion for all of them -- but at `-G8` the assembler emits a single gp-relative instruction with no `lui`, and the nop really is needed. The function then comes out several instructions short.

We recover the sizes from the `.extern` directives the compiler already emits and insert the nops ourselves. This one is not a one-off: *any* sequence that loads a gp-relative global and immediately uses it hits it, which is ordinary game code.

**Known unmatched pattern — parked, 5 functions.** Simple global stores like `D_800F5F80 = arg0;` where the retail code reads:
```
lui $at, %hi(sym)
jr  $ra
sw  $a0, %lo(sym)($at)      <- second half of the macro, in the delay slot
```
**Solved** — see `fill_delay_slot_with_macro_tail` above. The seven functions this blocked (`func_8007A628`, `func_8007BEBC`, `func_8007BEC8`, `func_8007BED4`, `func_8007BEE0`, `func_8007CD04`, `func_800862C0`) are all decompiled and matching.

Note the *same* pattern with the store **not** in the delay slot does match fine (`func_80082A80`, `func_8008D1E0/F4/208`) — those just need `-G0 -mno-split-addresses` plus `-G0` on the assembler. Only the delay-slot split is the blocker.

Also parked: `func_800495EC` (register allocation refuses to match across every `-O`/`-G` combination and several C formulations) and `func_800136D4` (an empty function that nonetheless allocates and immediately frees a stack frame).

### What counts as a target

`docs/LIBRARY_FUNCS.txt` lists **342 PsyQ library functions that live inside `.text`** but are out of scope — they stay as assembly and link as-is. They are easy to spot and easy to waste time on: a large cluster around `0x80073840`+ are BIOS syscall trampolines of the form
```
addiu $t2, $zero, 0xB0
jr    $t2
addiu $t1, $zero, <index>
```
which cannot be expressed in C at all. Filter these out before picking targets.

### Build performance

Wall time is dominated by process-startup latency, not computation -- a full rebuild spends seconds of CPU across minutes of real time, and under Wine every PsyQ invocation pays that cost (~278 per full build). `build.py` therefore does two things:

- **Concurrency.** Planning (which objects exist, and their `.text` order) is separated from building, so compiles are order-independent and run in a thread pool. The default `-j` deliberately oversubscribes the cores, since the work is latency-bound. On the 2-core Linux VM a full rebuild went from **9m27s to 21s**.
- **Incrementality.** An object is skipped when it is newer than its inputs. For a C file those are its source, every header in `include/`, and `build.py` itself -- the per-function flag tables live there, so editing it can change any object's contents. Run stubs are rewritten only when their contents change, because rewriting unconditionally would bump the mtime and defeat the check. A rebuild with nothing changed takes **0.95s**.

`is_stale()` treats a missing dependency as stale rather than ignoring it, so a mistake costs a rebuild and never a wrong binary. The sha1 check remains the backstop.

### splat must stay idempotent

`splat split` regenerates `asm/` *and* rewrites `config/undefined_syms_auto.txt` (which it opens with `"w"` -- it is output, not accumulated state). Both artifacts must be committed **from the same run**, or re-running splat produces churn that looks like a platform or version difference and is neither.

This was broken once: the config changed several times during setup without `asm/` being regenerated alongside it, so a clean-tree `splat split` reproducibly dirtied five files. The symptom was cosmetic -- the old asm spelled `0x8009B48F` as `D_8009B48E + 0x1`, offsetting from a symbol that existed when it was generated, where a fresh run emits `D_8009B48F` directly. The build produces the same sha1 either way. Fixed by regenerating and committing both together; verify with: clean tree, `splat split`, `git status` shows nothing.

### Progress

751 of 1794 functions decompiled and byte-matching.

The 1794 total is misleading as a denominator, though. Subtract 342 library functions and ~116 hand-written GTE/COP2 routines that will likely never become C, and the real target set is closer to **~1340 functions**, of which ~751 are done. Instruction count is probably the better measure of remaining work: ~128,000 still in assembly.

### Tooling: `tools_src/permute.py` (decomp-permuter)

For the failure mode the manual loop cannot solve: logic and instruction count correct, registers allocated differently. The permuter randomly rewrites the candidate C -- reordering declarations, introducing temporaries, changing types -- recompiles each variant through our real pipeline and scores it against the target object (0 = match).

    python tools_src/permute.py func_80035598          # prepare only
    python tools_src/permute.py func_80035598 --run     # prepare and search

It needs a candidate at `src/<func>.c` already: it refines a near miss, it cannot decompile from nothing. Output candidates land in `build/permuter/<func>/output-<score>-N/`.

**Getting it running on Windows took four fixes**, all handled automatically by `permute.py` but worth knowing about, since re-cloning decomp-permuter reverts the patched ones:

1. *Executable-bit check* (patch to `src/main.py`). It refuses to start unless `compile.sh` has mode bit `0o100`. Windows cannot set that -- `os.chmod` is a no-op and `os.stat` reports `0o100666` for any writable file -- so the check fails for everyone on this platform. Relaxed to apply only off Windows.
2. *Executing a shell script* (patch to `src/compiler.py`). It runs `compile.sh` directly, which Windows cannot do. Routed through `bash` on Windows.
3. *Tool names.* It finds objdump via `shutil.which()` against a fixed list (`mips-linux-gnu-objdump` and friends) and shells out to a bare `cpp`. Ours are prefixed `mipsel-none-elf-*`, so copies are made under the expected names. These copies must go **inside the toolchain's own bin directory**: `cpp` is a driver that locates its `cc1` relative to its own path, so a copy anywhere else dies with `cannot execute 'cc1'`.
4. *PATH resolution.* Windows resolves a child process's program name against the **parent's** PATH, not the `env` passed to it, so the shim directory has to be added to `os.environ` before launching, not just handed to the subprocess.

`compile.sh` is generated from the same flag tables the build uses, so a variant that matches under the permuter also matches under `build.py`. If those ever drift, permuter results become worthless -- keep them in step.

**Use it to learn *whether* a match is reachable, not to get the C you commit.** It searches for any program that assembles identically, and what it returns is usually unusable: its winning variant for `func_800156B8` indexed the array with `i & 0xFFFFFFFFFFFFFFFFu` repeated *twelve times*. That is byte-exact and completely meaningless -- committing it would mislead every future reader about what the original code did.

The productive workflow is: let the permuter prove the allocation is reachable, then find a defensible route to it. For `func_800156B8` the essential trick reduced to a 64-bit promotion of the index, and from there to something entirely idiomatic:

```c
*(p + i + 0xA) = arg0;   /* matches */
p[i + 0xA] = arg0;       /* does not */
```

Those are the same thing to C, but gcc canonicalises the addition differently -- it emits `addu counter,base` for the index form and `addu base,counter` for the deref form, and the operand order is visible in the encoding. **Worth trying the deref form on any near-miss whose only defect is a swapped `addu`.** It does not generalise to every register-allocation miss, though: it failed on `func_8003006C` (target reuses the pointer register) and `func_800855B0` (target overwrites the hi register with the base).

Earlier record, for calibration: a first attempt on `func_80035598` ran ~1000 iterations and got the score to 120 without ever reaching 0. The tool is genuinely useful but not a guarantee.

### Tooling: `tools_src/try_func.py`

Single-function matching loop, so you don't need a full build per attempt:

```
.venv/Scripts/python.exe tools_src/try_func.py func_80015010 candidate.c -O1 -G8
```

Compiles the snippet with the real toolchain and diffs the instructions against the target's disassembly. Trailing arguments pass straight through to cc1psx, so optimisation levels can be swept quickly.

Branch labels are renumbered positionally on both sides, so branching functions
compare correctly. The full build is still the authority; try_func only tells
you where to look next.

**This file has been the single largest source of wrong conclusions in the
project, and every one had the same shape: it reported on something it had not
measured.** Four separate bugs, all found on the same day:

| bug | what it claimed |
|---|---|
| kept its own copy of every toolchain path (psyq46, aspsx 2.86, Windows venv, no post-passes) | that `-fno-schedule-insns` was inert — measured on the wrong compiler |
| no `subiu` → `addiu -n` rule | a phantom diff on the frame setup of *every* function with a stack frame |
| `slt $r,$r,20` normalised to `sltiu` | a signed/unsigned mismatch that did not exist |
| symbol aliases compared as text | every deliberate alias use reported as a difference |

The toolchain constants now come from `build.py` by import, so that class of
drift cannot recur. The normalisation table is the remaining risk: each
register-form mnemonic has exactly one immediate form and they are *not*
derivable by a shared rule (`add`→`addiu`, `and`→`andi`, `slt`→`slti`,
`sltu`→`sltiu`). Before believing a one- or two-instruction difference in a
mnemonic's *spelling*, write the three-line function that isolates it and check
the tool is not inventing it.

### "The permuter saturates" is a claim about a search that finished

Two park notes written today say the permuter saturated. Neither search
finished. `func_800732A0`'s run was SIGTERMed by its own `timeout 1200`
(exit 143) and `func_800594C0`'s I killed with `pkill` because it was
competing for cores. Both notes read as though the search had exhausted the
space, and one of them is in a commit message.

This is the same failure this project keeps auditing out of its tools --
reporting on something that was not measured -- except here the tool was
honest and the *conclusion* was not. A killed search tells you the best score
so far and nothing about what a completed one would find. Write "killed at
Ns, best score N" or run it to completion; do not write "saturates".

The re-measurement that prompted this: after the `slt`→`sltiu` normalisation
bug was fixed, `func_800732A0`'s diff no longer shows the signedness
difference it was partly parked on. The real gap is smaller and different --
one instruction, a redundant copy of the base pointer that retail makes and we
do not. Its candidate is in `parked/` and is now at 22 differing instructions
with the correct loop body and guard, from initialising the loop index *from*
the write count (`s32 i = n;`), which is what retail's `addu $a0,$a1,$zero`
literally does.

### A narrow return type is free in the callee and expensive at every caller

`func_8005F174` and `func_8005F18C` each return one `u8` global, and both were
written `u8 f(void)`. That is byte-identical to `s32 f(void)` in the callee --
the value comes from an `lbu` either way, and nothing masks it.

At the *caller* it is not free. gcc does not trust a callee to have extended
its return value, so every use of a `u8`-returning function emits
`andi $r,$r,255` first. func_80059FAC calls both and retail masks neither, so
retail's translation unit declared them int-width. Widening both definitions to
`s32` left the callees byte-identical and let the caller match.

Two tells, one for each direction:

  - **A caller one instruction long, with an `andi $r,$r,255` right after a
    `jal` that retail does not have** -> the callee's return type is too
    narrow. Widen the callee.
  - **A caller one instruction short, with retail carrying an
    `andi $r,$r,255` after a `jal` that we do not emit** -> the callee's
    return type should be narrow. This is the one to expect from here on,
    because wide is now the default in `src/`.

Either way the callee itself is byte-identical and stays green, so the
symptom always appears at the caller and always looks like the caller's fault.

**How far this is actually evidenced.** Only `func_8005F174` and
`func_8005F18C` are proven: widening them *changed func_80059FAC's bytes* from
not-matching to matching. The other 22 were widened in a sweep justified by
"the build stays green", and that is not evidence -- the build is equally green
with them narrow. Every one of them has a decompiled caller, but no caller's
bytes differ between the two spellings, which is exactly what "undetermined"
looks like. They are widened because wide is the better default to be wrong
in (a redundant mask is easier to spot than a missing one), not because the
build says so. `func_800451E0` is the one that is proven *narrow*: as `s32` it
comes out an instruction short, so its `s16` is doing real work.

### The source-shape levers, consolidated

These came out of roughly seventy functions matched on 2026-07-25/26. They now
solve more than the flag sweep does. Try them in this order; the first four
are cheap enough to apply speculatively.

**Where a local is declared decides register allocation and scheduling.**
- *Inside the block that uses it* -- eight functions. Works in if/else arms, in
  straight-line code (three copies of a stream-read idiom), and in a loop body,
  where it stops gcc hoisting an address formation to the top of the function
  while still hoisting it out of the loop.
- *Named before the first call* keeps a base in a callee-saved register across
  that call; named after, gcc forms it later.
- *Order of first assignment*, not of declaration, is what the allocator
  follows. Splitting declaration from assignment does not separate the two.

**Reusing a variable versus introducing one.**
- Retail keeps one register across a transformation -> the source reused the
  variable (`v &= 0xFFFF; v |= v << 16;`, not a new local).
- Retail's loop counter shares a register with a value that is dead by then ->
  the source reused *that* variable as the counter.
- Retail makes a copy we do not -> introduce something that forces one: a
  narrower intermediate (`s32 raw = *p; s16 c = raw;`), or a post-increment in
  an argument (`f(p, (*n)++)`), which needs both the old and new value live.

**Addresses.**
- *Byte offset into a local* (`o = i * 4;` then `p + o`) takes the multiply out
  of the address and fixes `addu` operand order -- in straight-line code.
- *In a loop, leave the index arithmetic in* and let strength reduction build
  the induction variable; hand-advancing a pointer makes gcc fold the constant
  offset into it.
- *Name the array before indexing it* (`b = Arr; &b[i * 64]`) to get the base
  formed before the index.
- *Record type for a strided table* keeps a field offset as a displacement
  where a cast folds it into the symbol -- and does it without moving the
  address computation, which a pointer local cannot.
- *A second base pointer* in the source when the target forms one with no use
  of its own.

**Declarations.**
- Per-file `#ifdef X_IS_AGGREGATE` for a symbol reached gp-relatively in one
  unit and through %hi/%lo in another. Five symbols now.
- `volatile` when retail reads back a value it just stored, keeps two
  read-modify-writes in order, or pins a store against a volatile read.
- A narrow return type is free in the callee and an `andi` in every caller.

**Reading the target.**
- Read to `endlabel`. A store in the return's delay slot is the easiest
  instruction to miss.
- `$at` means the assembler expanded a bare symbol: `-mno-split-addresses`.
  `$at` on *some* symbols and a compiler-split address on others in the same
  function means a -G8 compiler with a -G0 assembler instead.
- `lui $r,%hi(sym)` followed by a load into `$r` itself is the same tell.
- A register reused across a branch belongs to whichever predecessor reaches
  the use, not to the nearest assignment in the listing.
- Retail reloading a pointer before every access means the source read it
  again. The local you would rather write is not what was compiled.

### try_func is validated in both directions now, and how

A green build makes every file in `src/` a known-good case, and every file in
`parked/` a known-bad one. `tools_src/check_try_func.py` runs both:

    450/450 of src report MATCH
    18/18 of parked report a difference

-- one run, current code, both phases. Two earlier full passes were run
against older builds of the tool and are superseded; the addend fix and the
bare-gp-offset resolution both landed after them, and the addend fix in
particular could only have been validated by a pass that came after it.

That is the first time any claim about this tool has been checked rather than
assumed, and it immediately paid: ten normalisation gaps across three rounds,
plus a regression I introduced *while* fixing one of them (reordering two
branches of the `li` rewrite silently broke every 0xFFFF0000 mask), plus a
scratch-file collision that made two concurrent runs report a diff belonging
to neither candidate.

**Run it after touching try_func.py. Every time.** The stride argument samples
`src/`; stride 1 takes about twenty minutes and the parked half is always
checked in full.

### Two more members of the base-formation recipe

Both found on func_8002497C and func_8002CCE4, both now generalisable.

**Declare a strided table by its row type.** `D_800909D4` is 20 rows of 6
bytes indexed by a 1-based counter. Written flat as
`D_800909D4[counter + arg0 * 6 - 1]`, gcc reassociates and puts the `-1` on
the counter; retail puts it on the row product. Declared `s8 D_800909D4[][6]`
and written `D_800909D4[arg0][counter - 1]`, the whole index chain matches
*including its register allocation* — from seven differing instructions to
one register. This is the same lever as the record-typed struct array, applied
to a plain 2-D table.

**Declare locals inside the block that uses them.** (Originally written as
"inside the arm"; it is not about branches at all.) With `u8 *p` and `s32 m`
declared at the top of func_8002CCE4, gcc hoists the second base's `lui` above
the branch and the schedule of both arms shifts: 18 differing instructions.
Block-scoped inside each arm: 3. Nothing else changed. When two arms do the
same shape of work on different symbols, scope the locals to the arm.

Six functions now, and the last one had no branches: func_8002E9A0 reads
three little-endian halfwords from a byte cursor. With one `u8 *p` reused
across the three reads, gcc keeps one base register and addresses everything
off it; with `p` declared fresh inside a `{ }` around each read -- which is
what three copies of the same idiom look like -- it keeps the old cursor and
the new one live together and addresses the odd bytes off the newer, exactly
as retail does. Nineteen differing instructions to a match, with no other
change.

A third, smaller: **read an aliased base into a local before the guard.**
`u8 *n = Base2_8009B364;` ahead of the early-return test was the last step
from six differing instructions to a match on func_8002497C. The permuter
found it; it is not something to guess at, but it is worth trying by hand
before reaching for the permuter.

### Original translation-unit boundaries (discovered, not yet applied)

While matching `func_80082780` its build came out 4 bytes short, which turned out to be a structural discovery rather than a codegen bug.

**233 of the ~1792 functions are followed by padding, and in every case that padding runs to the next 16-byte boundary.** That is the signature of an object file's `.text` ending: the original game was built from ~234 separate translation units, and the linker padded each object's `.text` to 16 bytes. Functions in the *middle* of a source file have no padding at all (1559 of them).

`docs/FILE_BOUNDARIES.txt` lists every detected boundary (derived address + the last function of the preceding unit). Note the earliest boundaries cluster in the `0x80073xxx`+ range as runs of consecutive 16-byte functions — those are the PsyQ library stubs, where each library function genuinely is its own object inside a `.LIB`, which independently corroborates the interpretation.

**Current stopgap:** `func_80082780` is the last function of its unit, so `src/31D8.c` emits its padding explicitly via `__asm__(".space 4");` immediately after it. (`.align 4` does *not* work here — it aligns to 16 and over-padded by a full 16 bytes.) This is a deliberate placeholder, marked as such in the source.

**The proper fix**, and the clear next structural task: split `src/31D8.c` into multiple `c` subsegments in the splat config matching the real boundaries, so each object's `.text` gets padded naturally by the linker and the source tree mirrors the original file layout. This is mechanical now that the boundaries are known, but it is a large config change and was deliberately left for a separate pass rather than bundled into the harness work.

### Splat config gotchas worth remembering

- `base_path` resolves relative to **the yaml file's directory**, not the CWD. With the yaml in `config/`, `base_path: ..` makes everything else (`asm_path: asm`, `src_path: src`, `generated_asm_macros_directory: include`) resolve naturally against the repo root. Getting this wrong the first time scattered generated files into `config/asm/`, `config/src/`, `config/include/`.
- splat generates the asm macro definitions itself (`include/macro.inc`, `gte_macros.inc`, `labels.inc`, `include_asm.h`) — no need to hand-write them. But it does **not** generate `include/common.h`, which every generated `.c` file includes; that one is ours to write. It defines `INCLUDE_ASM_USE_MACRO_INC 1` (we assemble with modern GNU as, so we need the gas-flavored macros from `macro.inc`, not the original-assembler `labels.inc`) and includes `include_asm.h`.

## Tooling gotcha: use a project-local venv, not the global Python

`pip install splat64` was first tried **globally** and it downgraded `tqdm` (4.67.3 → 4.67.1), breaking a pinned dependency of `aider-chat` (another tool on this machine) — caught and reverted (`pip install tqdm==4.67.3`) before it caused real damage. Fixed properly with `python -m venv .venv` at the repo root and installing `splat64[mips]` (needs the `[mips]` extra — `spimdisasm`, `rabbitizer`, `n64img`, `crunch64`, `pygfxd` — the bare package doesn't ship these) plus `asm-differ`'s deps there instead. **Always use `.venv/Scripts/python.exe` / `.venv/Scripts/splat.exe` for this project's Python tooling, never bare `pip install` into the system Python.**

### Live-range length picks the callee-saved register — the first lever into the allocation class

`func_80022FF0` walks five 12-byte records, calling `func_80022F98` on the
pointer at `+0` and the pointer at `+4` of each. Retail uses two induction
variables, `$s1` for the base and `$s0` for base+4, plus `$s2` for the counter.

Writing it with one base and offsets `0`/`4` gives 39 differences: cc1psx keeps a
single iv. Writing two explicit pointers gives **10**, then reordering the two
increments and the counter init gives **7** — at which point the two functions
are instruction-for-instruction identical and the only difference is that my base
pointer is in `$s0` and retail's is in `$s1`. Textbook register-allocation class,
and the flag sweep agrees: all thirteen viable combinations sit at 7.

It is not the allocation class. The fix is **where the derived pointer is
computed**:

```c
    a = *(u8 **)(arg0 + 8);
    if (a == 0) return;
    i = 0;
    func_80022F98(arg0, *(u8 **)(arg0 + 4));   /* a is live across this call */
    *(u8 **)(arg0 + 4) = 0;
    b = a + 4;                                 /* b is not */
```

With `b = a + 4` before the call, both pointers are live across it; with it after,
only `a` is. Moving that one statement past that one call flips `$s0`/`$s1` and
the function matches exactly.

**The mechanism below is a reconstruction and it does not predict the corpus.**
The natural story is that gcc 2.8.1's global allocator sorts pseudos by a
priority that divides usage frequency by live-range length, so the longer-lived
pointer sorts later and takes the later hard register. `func_8004733C` contradicts
it: there `arg1` is copied to a callee-saved register in the prologue and used
last, `arg0` is copied eleven instructions later, and it is `arg1` — the earlier
and longer-lived one — that retail puts in `$s0`. So take the lever as an
empirical move, not as a predictive rule, and do not reason forward from the
priority formula.

The instruction that computes `b` still ends up in the `jal`'s delay slot in both
forms — reorg pulls it back across the call — so **the emitted order is identical
either way and the diff shows nothing at that line**. That is why this looked
like an allocation difference: the statement that decides the allocation does not
move in the output.

This is the first lever anyone has found into the class recorded above as closed,
and so far it is the only function it has moved. Probing it afterwards on every
parked candidate that contains a call — `func_800709C0`, `func_80070AC0`,
`func_80070B3C`, `func_8005F7B0`, `func_8004733C`, `func_80031EE4`,
`func_8005A618` — moved none of them, and three variants on `func_8004733C`, the
one whose difference really is a callee-saved pair swap, went 10 → 12, 17, 10.

Two things that fall out of that probe and are worth more than the lever itself:

- **Most "one register differs" parks are `$v0`/`$v1` inside one basic block.**
  `func_8002CCE4` (3 out) and `func_800709C0` (5 out) are both a caller-saved
  pair swapped between an address and a value loaded through it, with no call
  anywhere near. Nothing can be moved across nothing.
- The triage I used to find candidates counted each file's own definition line as
  a call, so the first six functions I tested had **zero** calls in them. Grep for
  call sites with the *defining* line excluded, or the sample is off by one
  everywhere.

And one non-tell, measured rather than assumed while `-mno-split-addresses` was
solving two functions in a row: **`lui $at` in the target does not predict the
macro flag.** Across the 482 matched functions, 31 have `lui $at, %hi` in retail
and 21 of those build with the default flags; of the 17 built with a macro flag
set, 7 have no `lui $at` at all. It is not a tell in either direction — sweep.

### A backward `j` means `while (1)` with an interior exit, and 100 functions have one

`func_80031F7C` searches a 0x10-byte record array for one whose halfword at `+4`
equals the argument. Written as `while (*(s16 *)(p + 4) != arg1) p += 0x10;` it
came out 29 instructions wrong, because cc1psx **rotates** the loop: it copies the
test above the body, ends the body with the conditional branch, and there is no
unconditional jump anywhere. Retail does not rotate:

```
.L80031FB4:
    lh    $v0, 0x4($v1)
    beq   $v0, $s2, .L80031FCC
    addu  $v0, $s1, $s2          # delay slot: loop-invariant, hoisted into it
    j     .L80031FB4
    addiu $v1, $v1, 0x10         # delay slot
```

Test at the top, exit branch out of the middle, unconditional `j` back. The source
shape that produces it is an infinite loop with the exit written inside:

```c
    while (1) {
        if (*(s16 *)(p + 4) == arg1) break;
        p += 0x10;
    }
```

With that and one operand-order fix — `(arg0 + arg1)[0x5D97]` rather than
`arg0[arg1 + 0x5D97]`, which decides whether the `addu` reads `$s1,$s2` or
`$s2,$s1` — it matches exactly.

**The tell is a backward unconditional `j`**, and it is worth stating as a rule
because it is not rare: scanning all 1794 functions for a `j` to a label defined
earlier in the same function finds **105**, of which only 5 are decompiled and 85 are in scope (the rest are above `LIBRARY_REGION` or listed in `docs/LIBRARY_FUNCS.txt`). Of
those 5, four are `while (1)` with an interior `return` or `break`
(`func_80021558`, `func_80019A08`, `func_80031F7C`, `func_80036BCC`) and the
fifth, `func_8003FE80`, is `while (func_8004703C() & 8)` — a condition gcc will
not duplicate because it contains a call. Both forms defeat rotation, and one of
them is nearly always what a backward `j` means.

So: a rotated loop in your output against an unrotated one in the target is not a
scheduling difference to chase with flags. It is the loop written the other way
round in the source.

### `x = a + b` picks a destination register, and `+=` is how you choose it

Five functions in `src/hirata/H_mctrl1.c` end the same way: read a byte offset,
add it to a base pointer, store the result as a cursor. Written the obvious way

```c
    u8 *p = D_800F5BE8[0].base;
    D_800F5BE8[0].cursor = c + p;          /* or p + c -- identical output */
```

every one of them was **five instructions out**, and the five were always the
same: the address of the object in `$v1` instead of `$v0`, the loaded base in
`$v0` instead of `$v1`, and `addu $v0,$v0,$a1` where retail has
`addu $a1,$a1,$v1`. Both compute the same sum. The difference is *which operand's
register receives it*: retail accumulates into the register holding the offset,
cc1psx accumulates into the register holding the freshly loaded base. Swapping
the operands in the source does nothing, because for a commutative `+` gcc has
already canonicalised the tree by the time it picks a destination.

What does work is writing the accumulation as an assignment to the offset:

```c
    c += (s32)D_800F5BE8[0].base;
    D_800F5BE8[0].cursor = (u8 *)c;
```

Now `c` is the destination of the `+` at tree level and the register allocation
follows. `func_80070D00` went from 5 to MATCH, and the same edit matched
`func_800709C0`, `func_80070AC0` and `func_80070B3C` unchanged — all three had
been **parked**, two of them under "scheduling / rematerialisation", which they
were not. `func_80070A40` needed one more thing: it compares two array elements,
and retail forms the *left* operand's address first, so `D_800F5B98[b] <
D_800F5B98[a]` has to be written `D_800F5B98[a] > D_800F5B98[b]`. Then it matched
too.

So the generalisation, which is worth reaching for before parking anything on
register naming: **when two registers are swapped around an arithmetic
instruction, look at which operand the result lands in, and rewrite the statement
so that operand is the assignment target.** A pure expression `t = a + b` leaves
the choice to gcc; `a += b; t = a;` takes it away.

The provenance is worth recording too. `func_80070DA8` and `func_80070D00` both
call the printf at `func_8008E870` with `"%s:%d\n"`, the string
`"src/hirata/H_mctrl1.c"` and a line number — 403 and 379 — so these are
`assert`-style bailouts and they name their translation unit outright. That is
the only embedded source path in the whole binary: grepping every `.asciz` in
`asm/data/` for a `.c` suffix returns exactly one string, referenced by exactly
these two functions. No other unit can be named this way.

### `x & (1 << i)` in a loop, and an afternoon spent inside the library region

**Naming the mask stops the bit-test rewrite.** In `func_80077090`, written
`if (arg0 & (1 << i))`, cc1psx's combiner rewrites the test to
`((arg0 >> i) & 1) != 0` and emits `srav`/`andi`. Retail keeps `1` in a register
and shifts *left*: `addiu $a2,$zero,1` before the loop, `sllv $v0,$a2,$v1` in the
branch delay slot, `and $v0,$a0,$v0`. Giving the mask a name is enough to prevent
the rewrite:

```c
        s32 m = 1 << i;

        if (arg0 & m) { ... }
```

That took the function from 34 differences to 7, and it is a stronger form of the
older "naming intermediate results fixes scheduling" note — it blocks a combiner
transform, not a schedule.

**The remaining 7 were not reachable, and the reason is that the function is not
ours.** Retail returns `-1` with `j <exit>` into a single trailing `jr $ra`;
cc1psx emits `j $31`, checked in the raw `.s` before maspsx runs. Nothing in the
flag space moves it — `-fno-cse-follow-jumps`,
`-fno-expensive-optimizations`, `-fno-rerun-cse-after-loop`, `-fno-peephole`,
`-fno-inline`, `-fno-caller-saves`, `-fno-function-cse`, `-fno-thread-jumps`,
`-fno-delayed-branch`, and PsyQ 4.6 — and the same difference is the whole of what
stopped `func_80075CB0` and `func_80075D30`, both one instruction short.

**`func_80075D30` and `func_80077090` are listed in `docs/LIBRARY_FUNCS.txt`,
which says in its header "Do not write C for these."** All three sit above
`LIBRARY_REGION = 0x80073840`, the boundary `candidates.py` already filters on;
`func_80075CB0` walks the PsyQ heap block list, `{header, size}` pairs with bit 31
free and bit 30 end-of-list. I found them by scanning the whole binary for a
pattern and never re-applied the project's own scope filter to the result, so the
"jump-to-return threading is a wall" finding is really "Sony's compiler was not
this compiler". All three are out of the park, and `func_80075CB0` is now in
`LIBRARY_FUNCS.txt` with its evidence.

The transferable lesson is about the ad-hoc scan, not the threading: **any list of
targets derived by grepping `asm/` has to be filtered by `LIBRARY_REGION` and
`LIBRARY_FUNCS.txt` before it is a list of candidates.** The backward-`j` vein
recorded above is 105 functions binary-wide but **85** in scope; that is the number
to plan from.

### Where a constant offset lands, and the $at asymmetry

Three levers from the 10-20 instruction band, all about placement of a constant
rather than control flow.

**%lo folding follows the shape of the address expression.** For a load at
`sym + i*K + C`, retail keeps `%lo(sym)` bare and puts `C` in the memory
operand's offset field. `*(u16 *)&D_800F2C40[i * K + 0xE06]` instead folds
`0xE06` into the `%lo` and then adds it again to form the index -- same address,
one instruction's worth of different split. Naming the base as its own statement
fixes it:

```c
    u8 *p = D_800F2C40;             /* forces the symbol to be materialised bare */

    return *(u16 *)(p + arg0 * 3616 + 0xE06) >> 4;
```

The same choice appears in clear loops. `p = (u16 *)((u8 *)D_800F5BE8 + 0x3E);`
then `p[i]` folds the 0x3E into the base; `p = (u16 *)D_800F5BE8;` then
`p[i + 0x1F]` gives retail's split, with the base register holding `sym + 2*i`
and 62 in the store. When the target's base register does *not* include the
struct/array offset, move that offset into the index expression.

**A bare-symbol load reuses its destination as the `%hi` temp; a store takes
`$at`.** `func_8004545C` has both in ten instructions:

```
    lui  $v1, %hi(D_8009B45C)
    lw   $v1, %lo(D_8009B45C)($v1)     # load: destination doubles as the temp
    ...
    lui  $at, %hi(D_8009B128)
    sw   $v0, %lo(D_8009B128)($at)     # store: no spare register, so $at
```

That is one mechanism, not two: the assembler expanding bare symbols. Getting it
needs the compiler to emit bare symbols for both -- a **scalar** declaration at
`-G8` -- with a `-G0` assembler so neither is treated as small data. I reached
for `-mno-split-addresses` and an unsized-array declaration first and neither was
needed; `lui $at` next to an explicit `%hi`/`%lo` pair in the same function is
not evidence of two addressing modes.

**`&&` folds two bit tests, not just range checks.** `func_8001700C`'s
`(f & 0x8000) && !(f & 0x4000)` compiled to `andi 0xC000; xori 0xC000; sltiu` --
one test for the pair. Nested `if`s keep both, exactly as for the range-check
fold. Read the fold as being about the `&&`, whatever the operands are.

### `do`/`while` and a rotated `for` are not the same block layout

Three search loops in the 14-15 instruction band -- `func_8002C5CC`,
`func_8002EE5C`, `func_80033998` -- all had the same 6-7 differences, and all of
them were block *placement*, not polarity in the usual sense. Retail puts the
early-return inline, between the test and the loop-back:

```
    lhu  $v0, 0x0($a0)
    bne  $v0, $zero, .L8002EE80    # branch when the loop continues
     addiu $v1, $v1, 0x1
    jr   $ra                       # the `return 0`, inline
     addu $v0, $zero, $zero
  .L8002EE80:
    slti $v0, $v1, 0x28
    bne  $v0, $zero, .L8002EE68
```

Written as a `do { if (...) return X; ...; } while (cond);` cc1psx branches the
other way and puts the return block *after* the loop-back, which costs the
branch and the block order -- 7 differences with everything else identical.
Written as a plain

```c
    for (i = 0; i < 0x28; i++) {
        if (*p == 0) return 0;
        p++;
    }
```

it matches exactly, even though gcc rotates the `for` into the same
test-at-the-bottom loop the `do`/`while` produced. So the two forms are *not*
interchangeable: gcc lays out a rotated `for` with the interior return inline and
an explicit `do`/`while` with it out of line. Hoisting the increment above the
test, which is what the delay slot suggests, changes nothing -- the shape of the
loop statement is the whole of it. An `if`/`else` with the return in the `else`
also matches, which is the same layout by another route.

**Check the loop statement before reading anything into the branch direction.**
Two of these three had already been through a polarity edit that did nothing.

### The base-materialisation switch, stated as a rule

Five functions this session turned on *when* a global's address is formed
relative to the index arithmetic that will be added to it, and the switch is a
one-line source edit either way:

| target shows | write |
| --- | --- |
| `lui`/`addiu` for the symbol **before** the index arithmetic | name the base in its own statement: `u8 *base = D_800F2C40; u8 *p = base + i * K;` |
| the index arithmetic **first**, symbol formed after | fold it into one expression: `u8 *p = D_800F2C40 + i * K;` |
| the constant offset in the memory operand (`lbu $v1,3602($v0)`) | one named pointer, offset at the access: `p[0xE12]` |
| the constant folded into the index (`addiu $v0,$v0,3602`) | offset inside the subscript: `D_800F2C40[i * K + 0xE12]` |

`func_80059590` and `func_80059AA8` are the same helper over the same 3616-byte
record and they want *opposite* rows of the first pair; `func_80058E68` and
`func_80058E94` are another such pair. So this is not a per-file or per-unit
property to be predicted — read it off each function.

Two related notes, both learned the expensive way:

- **Remove every intermediate the source does not need before diagnosing a
  register problem.** `func_80033CC4` was parked as a three-register rotation
  with a flat sweep; deleting one `u8 *t = D_80090DD8;` matched it exactly.
  `func_8004545C` and `func_80058E94` were the same story. Three in one session.
- **And add one when the target materialises early.** The same edit in the other
  direction is what matched `func_80059AA8`. The intermediate is a positioning
  tool, not a style choice.

### `if (x == 0) return 0;` and `if (x != 0) return y;` are different layouts

`func_80033500` returns a field or zero. Written with the non-zero test first —

```c
    if (p[0xD] != 0) return *(s16 *)(p + 4);
    return 0;
```

— cc1psx cross-jumps the two exits into one `jr $ra` and puts the zero in the
branch's delay slot: 13 instructions against retail's 15. Written the other way
round,

```c
    if (p[0xD] == 0) return 0;
    return *(s16 *)(p + 4);
```

it keeps both exits and leaves the delay slot empty, which is retail. An
`if`/`else` with the same two returns does not help (3 differences).

This is the same lesson as the loop-form note above: when the target has more
exit blocks than you produce, the fix is which test is written first, not the
polarity of a single branch and not a flag. Both orders express the same
function; only one of them survives cross-jumping.

### Array subscripts get reassociated; explicit byte arithmetic does not

`func_8003B6AC` reads `t[arg0]` and `t[arg0 + 1]` from a halfword table.
Written that way, cc1psx computes `arg0 * 2` once and gets the second address as
`arg0 * 2 + 2` — and in doing so clobbers `$a0`, which changes the register
assignment for the rest of the function. Retail keeps `arg0` and computes both
products from it:

```
    sll   $v0, $a0, 1
    addu  $v0, $v0, $v1
    addiu $a0, $a0, 0x1
    sll   $a0, $a0, 1
    addu  $a0, $a0, $v1
```

Writing the scaling out by hand on a byte pointer is what stops the
reassociation:

```c
    u8 *t = D_80090E58;
    u8 *lo = t + arg0 * 2;
    u8 *hi = t + (arg0 + 1) * 2;
```

That was 5 of the 17 differences. The rest were the two levers already recorded
— naming the second base (`D_800EB288`) so it is materialised before the index
multiply, and moving `i++` to the end of the loop body so the reload of the limit
can fill its own load-delay slot instead of taking a `nop`.

**Two adjacent subscripts of the same array are a reassociation risk.** When the
target recomputes the scaling instead of adding the stride, write the scaling
explicitly.

### The duplicate-%hi class is mostly not a symbol-alias problem

`tools_src/candidates.py` dropped every function that materialises one symbol's
`%hi` twice, on the grounds that it "cannot match" without
`config/symbol_aliases.txt`. That cost 41 candidates and it was wrong for the
first one tried.

`func_8002A660` reads `D_8009B148`, writes `D_8009B146`, then writes
`D_8009B148` twice — four `%hi` materialisations of two symbols, three of them
for the same one. There is no second symbol involved. All four are the
**assembler** expanding a bare-symbol memory op, and getting them is the
declaration lever again:

- **scalar** declarations for both globals, so cc1psx emits `lh $v1,sym` and
  `sh $zero,sym` rather than forming an address;
- `PER_FUNC_AS_FLAGS[...] = "-G0"` so the assembler does not make them
  gp-relative and expands each one separately.

With unsized-array declarations instead, cc1psx forms the address once into a
register and uses `0($a1)` for all three accesses — one materialisation, 21
differences. With `-mno-split-addresses` on top of that it is the same, because
the address is still a value gcc can common up. **A repeated `%hi` for one symbol
usually means each access was a separate bare-symbol op, not that the source had
two names for the address.**

**And the alias rule, measured across all five existing entries rather than
reasoned about.** I first wrote "reach for an alias when the two materialisations
are in the same basic block", which `func_80044DA0` disproves immediately — two
stores, one block, and it matches with both naming `D_8009B45C`. The real
condition is about *pointer values*:

| alias | still needed? |
| --- | --- |
| `Base2_8009B364` (`func_8002497C`) | **yes** — 13 differences without. Holds one address in a `u8 *` while reading through the other. |
| `KeyTable_801D9174` (`func_80036BCC`) | **yes** — 16 differences without. Walks two pointers over one base. |
| `Base2_8009B45C` (`func_80044DA0`) | no — MATCHes without it. Two plain stores. |
| `Base2_801D0000` (`func_8002CCE4`) | no — 3 differences either way. |
| `Base2_8009B458` (`func_80049B4C`/`func_80049C40`) | no — `func_80049C40` MATCHes without it, and it looked like the textbook case. |

So **three of the five were dead weight**, and the surviving condition is
narrower than "two pointer values". `func_80049C40` has exactly two pointer
values into `D_8009B458` inside one basic block and still needs no alias, because
a *store through the first pointer* sits between the two reads — and
`D_8009B458` is itself a pointer living in memory, so that store might alias it
and gcc has to reload regardless.

What is left for `Base2_8009B364` and `KeyTable_801D9174` is: **two reads of one
address with nothing in between that could have changed it.** Everything else the
compiler reloads on its own. The three dead entries are deleted.

That is the second wrong version of this rule in one hour — "same basic block"
first, then "two pointer values" — and both were written from a single function
before the others were tested. The table above is the deliverable; the sentence is
just its summary.

`func_80049F50` is the second confirmation of the mechanism: three `lui`/`lw` of
`D_8009B458` in three basic blocks, all from the scalar declaration plus a `-G0`
assembler, no alias. Its one remaining difference was a type question — retail
stores the *sign-extended* return of `func_8004CABC`, so the local has to be
`s32 v = (s16)func_8004CABC();` and not `s16 v = func_8004CABC();`, which keeps
the raw value and extends only for the comparison.

The last two differences after that were ordinary: the read of the halfword the
first `if` uses had to be written after the store to `D_8009B146` — one statement
later than felt natural — so it lands in the delay slot of the comparison instead
of ahead of it, and that also settles which of the two values gets `$a1`.

### `volatile` blocks the bare-symbol form, and a third dup-%hi mechanism

`func_8003D0F4` needed all three addressing forms at once and taught two things
the earlier dup-%hi functions did not.

**`volatile` forces cc1psx to form the address as a value.** `D_8009B0C4` is
declared `volatile s32` and retail stores it through `lui $at` + `%lo` — the
assembler expanding a bare symbol. Under `-mno-split-addresses` with a volatile
unsized-array declaration, cc1psx emits `lui`/`addiu` into an ordinary register
and stores at `0($v0)` instead. Dropping the volatile in the aggregate arm of the
declaration guard is what gets the bare form. Worth knowing before spending time
on the flag: **a volatile access is never a candidate for the macro form.**

**Two accesses to one symbol in one function will be commoned even across a
branch.** `D_8009B408` is read before an `if` and written inside it, and cc1psx
formed the address once into `$a1` and used it for both, where retail expands
each separately. That is the alias case — the surviving condition from the table
above, "two reads of one address with nothing in between that could have changed
it", holds here even though a conditional branch separates them. `Base2_8009B408`
is the third live entry in `config/symbol_aliases.txt`.

The last two differences were the ordinary lever: naming the two struct fields
being copied out (`a` and `b`) so both loads are emitted before either store,
instead of letting the second load fill a delay slot the `D_8009B408` read had
already taken.

### The alias rule, third and final version: count the accesses

Three more dup-%hi functions settle what `config/symbol_aliases.txt` is for, and
it is simpler than either sentence I wrote earlier today.

**Under `-mno-split-addresses`, one access to an aggregate is a bare-symbol
memory op the assembler expands; two or more accesses to the same aggregate get
their address commoned into a register** — a callee-saved one if a call is in the
way, which also grows the frame. That is the whole rule. It does not matter
whether the accesses are loads or stores, in one basic block or across a branch:

- `func_8002EB48`, `func_8003D0F4` — one access per aggregate, no alias.
- `func_8003D0F4`'s `D_8009B408` — read then write across a branch. Commoned.
  One alias fixes it.
- `func_8003767C` — two stores each to `D_8009B2AA` and `D_8009B2A8`, one before
  a call and one after. Commoned into `$s1` and `$s2`, frame grown by 8, 41
  differences. One alias each: MATCH.

So **give the symbol one extra name per extra access.** `func_8003771C` proves
the arithmetic: it touches `D_8009B2AA` *four* times, two extra names left two
accesses sharing one and it went 26 → 36; **three** extra names took it to 19,
and it matched once the last two differences were fixed. Those were ordinary
scheduling — the signed read has to come first so the unsigned one fills its
load-delay slot, which means naming the *raw* second read and leaving the
subtraction inside the `if` so reorg can sink it into the branch delay slot.
Writing `w - 0x1000` outside the `if` keeps both loads but reorders them.

And the scalar route is the alternative when no `%gp_rel` symbol is in the way:
`func_8002A660`, `func_80049F50`, `func_80049C40`, `func_80049308` and
`func_80049BAC` all have a symbol accessed two to four times and need no alias at
all, because a **scalar** declaration never produces an address expression for
gcc to common — the accesses are bare symbol ops from the start, and a `-G0`
assembler expands each. Prefer that; reach for an alias only when the function
also needs a genuinely gp-relative symbol, which forces the assembler back to
`-G8` and the aggregate declarations with it.

### Repeated reads with nothing in between mean `volatile`, not an alias

`func_80023FBC` reads `D_8009B3A4` **five times** in a row, testing a different
bit each time, and retail reloads it every time. That is not the address being
materialised five times — it is the *value* not being commoned, and no
declaration form or alias reaches it: a scalar declaration gives five bare-symbol
loads that gcc still CSEs into one, and an alias per read would be five names for
what is obviously one variable.

The only thing that makes gcc reload is `volatile`, and that is almost certainly
what the original said — a hardware or interrupt-updated flag word. One
`#ifdef D_8009B3A4_IS_VOLATILE` guard and it matches.

**So distinguish the two failure modes before reaching for `symbol_aliases.txt`:**

- repeated `lui`/`%hi` for one symbol, each feeding a *different* access →
  address CSE. Scalar declaration, or one alias per extra access.
- the same *value* loaded repeatedly with nothing in between that could change
  it → value CSE. `volatile`.

`func_8003D0F4` earlier today is the reverse warning: `volatile` there *blocked*
the bare-symbol form and had to be dropped from the aggregate declaration. The
two uses of the keyword pull in opposite directions, so decide which one the
target is showing before using it.

### A shared `%hi` with two `%lo`s is the *absence* of an alias

`func_8003CC38` reads one record at `+0` and again at `+0x22`, and retail has:

```
    lui   $v0, %hi(D_800EF668)
    addiu $a0, $v0, %lo(D_800EF668)      # first pointer
    ...
    lui   $v0, %hi(D_800EF668)           # in a branch delay slot
    addiu $v1, $v0, %lo(D_800EF668)      # second pointer
```

Two `%hi`s, so `candidates.py` called it a duplicate-`%hi` function — but the
first branch out of block one jumps **past** the second `lui`, because `$v0`
still holds the high part from the top. That only works if both pointers name
the *same* symbol. Giving the second one an alias makes them two symbols gcc
cannot prove equal, so it can no longer skip the `lui`, and the branch lands one
instruction earlier: three differences that are entirely branch offsets, with the
instruction stream identical. Plain `-O2 -G8` with two locals off one symbol
matches.

So the tell is finer than "two `%hi`s":

- two `%hi`s where a branch can **skip** one → one symbol, no alias, plain
  `-G8` and two pointer variables;
- two `%hi`s where **both are always executed** → gcc would common them; alias.

And the diagnostic habit that caught it: try_func reported the three differences
as label names, which looks like a normalisation artefact. It was not — the build
disagreed too.

**But label-name differences can also be a try_func bug, so let the build
arbitrate.** `func_80040814` reported four of them and was byte-identical. The
cause: objdump prints a branch target as a bare hex offset, and the offsets
`a0`–`a3` are valid hex *and* register names, so register normalisation rewrote
`bltz s1,a0` into `bltz $s1,$a0` before the branch-target pass could label it.
Fixed by labelling branch targets first; the two passes were in the wrong order
from the start and only a branch to +0xa0 exposes it.

### `lui`/`lw` into the same register is a bare symbol, even for a volatile

Two functions, `func_8002622C` and `func_8003798C`, compute
`(D_8009B0F4 & 0x2000030) | D_8009B134` and both sat at exactly nine
differences: the mask constant in `$a0` where retail has `$v0`, the second
`%hi` hoisted above the first `lw`, and three registers rotated with it. I
parked one of them saying the sweep was flat, which it was.

The tell was in the pair that *did* match:

```
    lui  $v1, %hi(D_8009B0F4)
    lw   $v1, %lo(D_8009B0F4)($v1)     # destination is also the %hi temp
```

cc1psx emitting its own `%hi`/`%lo` pair uses a **separate** temp register, so
the two instructions can be scheduled apart. Retail reuses the destination,
which only the *assembler* does when expanding a bare-symbol load — and that
makes the pair inseparable, which is the whole of the nine differences.

Getting it needed the aggregate declarations plus `-mno-split-addresses`, and
one more thing: **`D_8009B0F4` is declared `volatile`, and a volatile access is
never emitted in bare form.** Making the aggregate arm of its guard
non-volatile (the scalar arm, used everywhere else, keeps it) matched both
functions, one of them straight out of the park.

So `lui $r,%hi(sym)` immediately followed by a load *into `$r`* is a
positive identification: that is the assembler, so the compiler emitted a bare
symbol, so the declaration is an aggregate under `-mno-split-addresses` and
nothing in the access is volatile. A separate temp means the compiler emitted
the pair itself.

Probed afterwards on every parked candidate whose target shows the pattern —
`func_8002C604`, `func_800338E4`, `func_80045484`, `func_80045BE8`,
`func_80048C0C`, `func_800496C4`, `func_8004A854`, `func_8004C84C`,
`func_80070710` — and the macro form moved none of them (`func_80048C0C` got
worse, 3 → 22). Their remaining differences really are register assignment, so
the tell identifies the *addressing* and nothing more.

### `(x & C) == C` gets a register; `((x & C) ^ C) == 0` gets two immediates

`func_80040BF8` and `func_80040814` are the same list walk and both test a
two-bit flag the same way. Retail:

```
    andi $v0, $v0, 0xC0
    xori $v0, $v0, 0xC0
    bnez $v0, <skip>
```

Two immediates and no register. Written as `(p->flags & 0xC0) == 0xC0`, cc1psx
materialises `0xC0` in a register and compares against it — and inside a loop it
hoists that register out, which costs a callee-saved register, a save, and a
bigger frame. `func_80040BF8` was **43 differences** for exactly that, and I
parked it.

Writing the comparison the way the target computes it fixes both:

```c
    if (((p->flags & 0xC0) ^ 0xC0) == 0) { ... }
```

**A comparison against a non-zero constant and a comparison against zero are
different instruction selections.** When the target shows `xori` before the
branch, the source compared to zero after an explicit xor. The equivalent
`== C` form is not a spelling difference.

The same two functions also needed the index-first address form
(`(Slot70 *)(i * 112 + (s32)base)` rather than `&base[i]`), which is the
operand-order lever again.

## Three drop rules retracted, in one session, all by measurement

`candidates.py` used to hide functions it judged unmatchable. Every one of those
judgements was wrong, and each had been reasoned from a couple of samples rather
than counted. The pattern is worth naming: **a filter that says "cannot match"
is a claim about the whole binary, so it needs a scan of the whole binary.**

**The range-check fold.** Retracted earlier: the fold happens on the `&&` (or
`||`), and nested `if`s keep both comparisons. Still real as codegen --
`v == 0 || v == -1` becomes `sltiu v+1,2` on the nose, which is what
func_8005C4F0 does -- but never a reason to skip.

**Duplicate %hi is not an alias problem.** All 96 dup-%hi candidates in the
binary use the *bare* form: `lui $r,%hi(s)` with the memory op through the same
`$r`, which is the assembler expanding a bare symbol. Zero of the 96 use
cc1psx's own `%hi`/`%lo` pair with a separate temp. So they want
`-mno-split-addresses`; an alias actively hurts, because with two names gcc
hoists both `%hi` values into callee-saved registers and grows the frame.
`Base2_8009B458` went back into `symbol_aliases.txt` on the alias theory and
came straight back out.

25 of the 96 also contain a `%hi` whose `%lo` is completed in another block --
a loop-invariant *split* address, which the same flag turns off. One file flag
cannot serve both shapes; `func_8004BBBC` is parked as the example, with
D_8009B458 exactly right and D_8009AF80 exactly wrong under the flag, and vice
versa without it. `func_8003D46C` is the same barrier with the roles reversed:
a bare *store* through `$at` next to a cc1psx split *load*.

**Correction, measured afterwards: an alias is sometimes needed, but only
alongside the flag and only inside a loop.** The claim above -- that an alias
makes dup-%hi candidates worse -- is true without `-mno-split-addresses`, where
two names give gcc two invariants to hoist. *With* the flag and inside a loop it
is the opposite: two references to one name make gcc form the address as a loop
invariant and hoist it into a callee-saved register even though each reference
would otherwise assemble to a single `lw symbol`. func_80047EC4 reads
D_8009B45C twice in its loop and went from 29 differences to MATCH on
`Base2_8009B45C` plus the flag. So the rule is: macro flags first; if the
address then appears hoisted out of a loop, add a name per extra reference.

**volatile is a real per-symbol escape from the bare form, with a catch.**
`-mno-split-addresses` is per file, but `volatile` on one symbol brings back
cc1psx's own `%hi`/`%lo` pair for that symbol alone. It also blocks folding the
`%lo` into the memory operand, so what comes back is
`lui $r,%hi(s)` + `addiu $r,$r,%lo(s)` + `lbu $d,0($r)`, the address completed
in a register. That is only useful when the target itself shows the unfolded
form. func_8003D46C wants the folded one, which is why it stays parked.

**`mult` and `div` were never a reason to skip one either.** The rule called
them "hand-written or needing idioms not yet worked out". Neither is true: `a *
b` in C compiles to `mult`/`mflo`, and division or modulo by a constant compiles
to a `mult` by a magic number followed by `mfhi` and a shift. func_8002C484 is
21 instructions of that idiom and its source is
`return (arg0 / 10) * 178 + (arg0 % 10) * 16 + 14;` -- the `0x66666667`
multiply, the `mfhi`, the `sra 2` and the sign correction are all gcc expanding
`/ 10`. func_8005FBC4 is three plain multiplications. Both matched first try.

All 66 in-scope functions the rule hid pair their `mult` with an `mflo` or
`mfhi`. What is genuinely hand-written is the GTE intrinsics -- `wc2`, `rtps`,
`mfc2`, `mtc2` -- and those are still filtered. **That is four retracted drop rules out of four ever written** -- and the
pattern has a precise boundary, which matters more than the count.

All four were **target-side signature heuristics**: "this instruction, or this
pair of instructions, means the function cannot be matched", reasoned from a
handful of samples. Every one was wrong, and a heuristic of that shape should
now be treated as wrong until a scan of the whole binary says otherwise.

The **closed classes are a different kind of claim** and they still hold. They
are compiler-capability facts established by enumeration, not signatures:
gcc 2.8.1 has 23 `-f` options and none of them touches register allocation
(and the permuter saturated at 16k iterations against a validated target), and
`-fno-crossjumping` does not exist before gcc 3. Do not re-open those on the
strength of the four retractions -- the retractions say nothing about them.

**"Calls a PsyQ library function" was never a reason to skip one.** The stated
reason was that such functions "need prototypes we do not have". They do not:
gcc 2.8 accepts an implicit declaration and passes integer and pointer
arguments correctly. `func_8008E870`, `func_8007D3F0`, `func_80073880`,
`func_8008AD50`, `func_8008FB8C`, `func_80077240`, `func_8007E7F0` and
`func_80077C70` were all called with no prototype and matched. What a missing
prototype would actually cost is a float or struct argument, and that shows up
as a wrong instruction count on the first attempt. Dropping the rule took the
16-26 band from 0 candidates to 12 and 27-40 from 1 to 25, and 9 of the first
12 matched.

## Narrow locals compare in their own mode, and that mode is unsigned

`u8 v = p[i]; if (v >= 0xB)` emits `sltiu`, not `slti`. The integer promotion
in the C standard says the comparison is signed `int`, but cc1psx compares in
QImode and a QImode compare of an `unsigned char` is unsigned. Holding the same
byte in an `s32` gives retail's signed `slti`. Same for `u16` and HImode:
func_80047A68 compares two `u16` fields and gets `sltu`.

This is the "hold values in the widest natural type" rule with a *direction*:
the narrow type does not merely cost an `andi`, it changes the comparison.
func_80073220 turned on it.

## Loop reversal, and the two things that stop it

gcc reverses a counted loop into a countdown when the counter is dead after the
loop and the trip count is known -- `addiu $v0,$v0,-1` with `bgez`, where retail
counts up and compares. Two levers, and they are not interchangeable:

- **`u32` instead of `s32`** for the counter. func_800494F4 counts to 0x212 and
  retail compares `sltiu`; with `s32 i` gcc reverses it, with `u32 i` it does
  not. This works when retail's own comparison is unsigned.
- **`-O1`**. func_80047A68 counts to 4 with a signed `slti`, so `u32` is not
  available, and no source shape stops the reversal at -O2: `u32 i`, a `for`,
  and `i = mask` as the initialiser all leave it reversed. At `-O1 -G0` the loop
  is exact. 23 differences to 6.

If retail counts up and you are counting down, check the signedness of retail's
comparison first -- it tells you which of the two levers is even applicable.

## Two call sites are cheaper than a pointer variable

When the same function is called in both arms of an `if` with different
arguments, write it as two calls. gcc's cross-jumping merges them into the
single `jal` retail shows, leaving the argument setup in each arm -- and the
argument is materialised straight into `$a0`, which for an address means
`lui $a0,%hi(s)` / `addiu $a0,$a0,%lo(s)` through one register.

Hoisting the choice into a variable (`p = A; else p = B; f(p);`) produces the
same instruction *count* and a different register: the address goes through a
separate temp, `lui $v0,%hi(s)` / `addiu $a0,$v0,%lo(s)`. func_80022618 is four
differences apart on exactly that, and func_800498BC needs the same shape to
get retail's branchy 0/1 -- `f(x != 0)` gives `sltu` instead.

Corollary for the `lui`/load tell: **cc1psx's own pair does not always use a
separate temp.** The reliable direction is the other one -- a separate temp is
always cc1psx's pair, but one register can be either.

## A prologue save in a call's delay slot means nothing else was available

func_80043E68 fills the delay slot of its first `jal` with `sw $s0,16($sp)`.
That only happens when the scheduler has nothing else to put there, so an
initialisation written *before* the call (`s32 i = 8;` as an initialiser) fills
the slot instead and the save moves up. Writing `i = 8;` after the call is the
whole difference.

## maspsx expands `li` differently from aspsx when the low half is negative

Retail materialises 0x7FFFFFFF as `lui $v1,0x8000` + `addiu $v1,$v1,-1`
(encodings 3C038000, 2463FFFF). cc1psx emits `li $v1,0x7fffffff` and maspsx's
`expand_load_immediate` turns that into `lui 0x7FFF` + `ori 0xFFFF`. Same value,
different bytes, and no source shape reaches across it -- aspsx evidently splits
a `li` the `%hi`/`%lo` way whenever the low half has bit 15 set.

Why it has stayed invisible: splat renders such a pair as `%hi(D_x)`/`%lo(D_x)`
and defines the symbol, so when the constant happens to look like an address,
writing `&D_x` reproduces the bytes by accident. 0x7FFFFFFF does not look like
one, and splat's own entry for it (`D_7FFFFF = 0x7FFFFF`) does not match the
encodings either. func_8005C5D4 is the only in-scope function that exercises it,
which is why this is documented rather than fixed: one observation is not enough
to justify a post-pass that would touch every function. If a second one appears,
patch `expand_load_immediate` to use the `lui`/`addiu` form when
`operand & 0x8000`.

## siblings.py ranked its own list upside down

`tools_src/siblings.py` pairs each unmatched candidate with the decompiled
function it most resembles. It originally sorted parked candidates *first*, on
the theory that a park predating its sibling's decompilation is the best lead.
Measured over one session: eleven non-parked leads gave eleven matches, most
first try, while the two `[PARKED]` leads at the top of the ratio list (0.933
and 1.000) took more attempts than anything else that day and stayed parked.

The mechanism is clear once stated. A park in the register-allocation class
asserts that the *shape* is already right; a matching sibling proves the same
thing, so it carries no new information. Parked entries now sort last.

The other half of the same measurement: the loose end of the ratio list is as
good as the tight end. func_800134E0 pairs with func_800599FC at 0.700 and
shares nothing with it but a `jal`, and it matched. What the ratio finds down
there is small functions of a shape already solved, which is the same thing by
a different route.

## A narrow local can be the whole difference, and it is not the mode this time

`docs/WORKFLOW.md` says to hold values in the widest natural type and cast at
the point of use, because a narrow type costs an `andi` or a sign-extend and
because it changes the *mode* a comparison happens in. func_80027060 is the
case that needs the rule stated more carefully, because there the narrow local
is what matched and the wide one did not — and no instruction changed.

The function reads a signed byte out of a structure and takes it modulo 5:

```c
s8 v = sp10[0][0x18];      /* matches */
s32 v = (s8)sp10[0][0x18]; /* 18 differences */
```

Both spellings emit exactly the same instructions in exactly the same order —
`lbu`, `sll 24`, `sra 24`, then the reciprocal multiply. The count is identical
and nothing is reordered. What differs is that with the `s32` spelling *every*
register in the block is rotated by one: retail's `$a1`/`$a2`/`$a3` become our
`$a2`/`$a3` and the D_800EAE88 base slides from `$a3` to `$a1`. The rotation
starts at the top of the block, where retail has `addu $v0,$zero,$zero` — the
function's `return 0` — as the *first* instruction, and we emit it seventh,
after `$v0` has been used as the scratch for `lw 0x10($sp)`.

So the lever is register birth order, not mode. The `(s8)` cast creates a
conversion pseudo that is born before the load's own pseudo; the `s8` local
does the conversion at the point of use and lets the load's pseudo be born
first, which frees `$v0` for the constant zero and un-rotates everything after
it. The general form: **when the only remaining difference is that every
register in a block is shifted by one, the fix is a pseudo that should not
exist, and a redundant cast is the commonest source of one.** This does not
retract the width rule — it is about a cast that changes no instruction, where
the width rule is about casts that change one.

## A store in a `j`'s delay slot can be a real second store

func_800402A0 ends an `if` branch with `j` into a join block, and the delay
slot holds `sh $v0,0($s0)` — a store the join block performs again three
instructions later, to the same address, with the same value. The obvious
reading is that gcc filled the slot by copying the join's first instruction and
should have branched past it, and that reading is wrong: gcc only does that
with the branch adjusted to target+4, and this branch targets the join's first
instruction.

It is simply a second store, and the source has it twice:

```c
if (v < 0) {
    *(u16 *)(D_800F2878 + arg1 * 2) = arg0->unkA[0];
    arg0->unk2 = -1;
    arg0->unk0 = -1;     /* here */
} else {
    D_800EFE48[v].unk0 = arg0->unkA[0];
    arg0->unk2 = *(u16 *)(D_800EFE38 + arg1 * 2);
}
arg0->unk0 = -1;         /* and again */
```

Writing it the tidy way — the store once in each arm, nothing after — costs 18
differences and an instruction. Writing it redundantly matches. The tell is the
`-1` materialisation: retail computes `addiu $v0,$zero,-1` at the *end* of the
else arm, immediately before the join, which only makes sense if the join is
what consumes it. When a join block reads a constant that each predecessor
materialises for itself, the statement lives after the `if`, whatever the arms
also do.

## Giving a table its own local moves its address to the top of the function

func_80019A60 sorts its two arguments and then indexes a table. Retail
materialises the table address in the first two instructions, *before* the
comparison that drives the swap; writing the table reference where it is used —
`D_8017C2D8[arg0]`, after the swap — puts the `la` after the swap instead, and
that is 7 differences with everything else already right.

```c
u8 *base = (u8 *)D_8017C2D8;   /* first local, first statement */
...
off = *(u16 *)(base + arg0 * 2);
p = base + off;
```

matches. This is declaration order (working-order step 2) with a specific
shape worth naming: **a table read through a local declared before anything
else has its address materialised before anything else.** The failed attempt
that looks similar is giving the *base* of a subtraction its own local
(func_8005A8C4, parked) — there the extra local stayed live and cost a register
everywhere. The difference is that func_80019A60's local replaces every
reference to the symbol, so nothing extra is live.

Same function, second lever: the order of the two updates at the bottom of the
loop. gcc emits the derived induction variable's update relative to the
counter's in source order, so `p += 5; n -= 2;` and `n -= 2; p += 5;` differ by
two instructions being swapped, and only one of them is retail's.

## `NULL` is not declared, and a filtered grep of try_func reads a crash as a match

`common.h` does not pull in a definition of `NULL`; write `(u8 *)0`. That is a
one-line fact, but the way it cost time is the part worth recording. The
candidate was checked with

    try_func.py func_80014EEC cand.c | grep -E '<<|differing|MATCH'

which printed nothing — and nothing is what a clean match with no trailing
summary looks like at a glance. The compile had failed on `NULL undeclared`;
the grep dropped the error text because it matched none of the three patterns.
This is the same failure the "a tool's answer only counts if it measured what
you think" habit is about, arriving through a filter rather than through a
stale object. **Read try_func's last lines, not a grep of them** — the word
MATCH is printed on success and nothing stands in for it on failure.

## One name per value, in both directions

func_8004318C needed a *second* name for one value: two multiplies of the same
quantity are two pseudos in retail, and writing the quantity once produced one.
func_800300C8 is the mirror image and cost more to find, because the symptom
looks like plain register allocation.

The function computes four halfword pairs. Two of them are unrelated values,
and writing both through one local:

```c
y = x + h;                       /* stored at +0x40 and +0x30 */
...
y = *(u16 *)(b + 0x40) + m * 16; /* stored at +0x32 and +0x2A */
```

gives 11 differences, all of them a `$v0`/`$v1` pair swapped inside the second
division-by-two. Declaring `z` for the second value and changing nothing else
is 7 — and the seven that remain are one more pair swap in the same block, the
class we stop on.

So the rule has two halves and they are not symmetric restatements: **the
number of names in the source must equal the number of pseudos in the target,
and both directions of the mismatch are common.** One name for two values costs
register pairs; one name reused for a value the target recomputes costs
instructions. Counting materialisations (working-order step 6) answers the
second; the first only shows up as allocation noise, which is why it reads as
a park and is not one.

Second lever from the same function, worth stating separately because it looks
like a symbol-declaration problem and is not. cc1psx builds the `%hi`/`%lo`
pair from the *first* reference to a symbol, constant offset included:
`*(s16 *)(D_800EB15C + 0x3C)` as the first use gives
`addiu $a3,$v0,%lo(D_800EB15C+60)`, and every subsequent offset in the function
is then 60 too small against retail's. Assigning the symbol to a local first —
`u8 *b = D_800EB15C;` — materialises the bare base and leaves the offsets in
the memory operands. Same one-line fix as func_80019A60's hoisted table
address, a different reason to reach for it.

## A clamp written as `if`/`else if` is not the clamp retail compiled

func_800595C8 clamps three arguments to [-0x1000, 0x3000] and stores each. The
obvious spelling

```c
if (arg1 < -0x1000) arg1 = -0x1000;
else if (arg1 > 0x3000) arg1 = 0x3000;
```

assigns straight into the parameter's register: `addiu $a1,$zero,-4096`. Retail
computes into `$v1` in every arm and then does `addu $a1,$v1,$zero` — a
temporary and a copy back, three times over. That is what a **conditional
expression** produces, because its value has to land somewhere before the
assignment consumes it:

```c
arg1 = (arg1 < -0x1000) ? -0x1000 : ((arg1 > 0x3000) ? 0x3000 : arg1);
```

42 differences to a match, with nothing else changed. Worth trying whenever a
target assigns a value into a scratch register and immediately copies it to the
variable's own register in every arm of a branch — that copy is the tell, and
it is free information because an `if` chain never emits it.

## The unrotated `while`, and the tail-merge that hides behind it

func_8003BC40 searches a word table for a halfword key. Its inner loop enters
with a *forward* `j` to a test at the bottom:

```
  lw   $v0, 0($v1)        # preheader loads the first entry
  j    .test
  ...body...
.advance:
  addiu $v1,$v1,4
  lw   $v0, 0($v1)        # and the advance block loads the next
  addiu $a3,$a3,1
.test:
  bnez $v0, .body
```

No spelling of `while` or `do`/`while` produces that. Every one of them gets
gcc's copied loop header — a duplicate of the test as an entry guard, then a
bottom test. The shape above is the *uncopied* header, and the only way to
write it is to say so:

```c
goto test;
body:
    ...
    e++;
    v = *e;
    idx++;
test:
    if (v != 0) goto body;
```

The second half of this is the part that cost the time. Write the advance block
as `e++; idx++; v = *e;` — load last, the natural order — and gcc tail-merges
the two `v = *e` insns into the test block, because they are then identical
final instructions of both predecessors. The test block ends up doing its own
load and the preheader's disappears. Moving one unrelated statement after the
load (`e++; v = *e; idx++;`) makes the two blocks end differently and the merge
cannot fire. 42 differences to 28, and the statement moved changes nothing else.

Two more from the same function, both about placement rather than content:

- **An out-of-line arm the target places before the loop body is a `goto`.**
  The `idx >= 0xF0` case sits physically between the preheader and the loop
  body in retail. Written as the `else` of an `if` inside the body — either
  polarity, either arm inline — gcc always emits it *after* the body, and the
  12 remaining differences were nothing but that. A label before the body and
  a `goto` to it is exact. Branch polarity decides which arm falls through; it
  does not decide which side of the loop head a block lands on.
- **One index variable for two sequential loops.** The trim loop and the encode
  loop both use `$t0` in retail. Two separate locals gave two registers and 28
  differences; one local reused gave 14. This is not in tension with
  func_800300C8's "two unrelated values must not share one name" — there the
  two values were live in the same stretch of code, here the loops are
  disjoint. The count that matters is *simultaneously live* values, not
  distinct roles.

## `-fno-schedule-insns` enters the table, and volatile does not substitute for it

func_80014A5C is the project's first `-fno-schedule-insns` user. It sets one
global then reads another:

```c
D_8009B124 = 1;
if (D_8009B0E8 != 0) return;
```

gcc's first scheduling pass hoists `lw D_8009B0E8` above `sh D_8009B124` so the
store fills the load's delay slot. Retail leaves the `nop` there and fills the
following branch's slot instead, so that pass did not run on the unit.

The thing worth recording is that **`volatile` is not an alternative here.**
Marking the loaded object volatile still hoists it; marking the stored object
volatile still hoists the load above it. gcc 2.8's scheduler treats volatile as
an ordering constraint among volatile references only, so a plain load moves
freely across a volatile store and a volatile load moves freely across a plain
one. Both were tried and produced the identical 46 differences, which is also a
reminder to read the output rather than the count — two different edits giving
the same number is what "the edit did nothing" looks like.

## The order of two increments in a `for` clause decides a delay slot

func_80021480 walks a pointer table with a counter and a pointer, both advanced
in the `for` clause. Written the way anyone writes it:

```c
for (i = 0; i < 10; i++, p++)     /* 39 differences */
for (i = 0; i < 10; p++, i++)     /* 1 */
```

That is the whole edit. With `i++` first, gcc emits `addiu $a0,$a0,1` at the
top of the body, ahead of the `lhu` that starts it, and the load's delay slot
then needs a `nop`. With `p++` first, the counter increment lands after the
load and fills the slot, which is retail. Nothing else in the function moves.

The pointer increment is the one that ends up in the loop-back branch's delay
slot in both versions, so the clause is not simply emitted in order — but the
*relative* order of the two decides which of them is available to the scheduler
at the top of the body. Cheap to try, and invisible from the diff, which just
reports a stray `nop` and everything after it shifted.

## Widening a callee's parameter is sometimes the caller's whole fix

func_80021480 passes its own `s32` argument straight to func_80040410, whose
prototype said `void func_80040410(u8 *arg0, u8 arg1)`. That `u8` forces an
`andi $a1,$s0,255` at every call site, and retail has none.

The parameter was never really a byte: the callee's only use of it is
`arg0[0x69] = arg1`, a byte store, which truncates on its own. Widening the
prototype to `s32` left func_80040410 itself byte-identical and left
func_80029108 — the other decompiled caller, which passes an `s32` too —
byte-identical as well, while removing the `andi` that was blocking the new
caller.

This is the width rule ("hold values in the widest natural type; cast at the
point of use") applied one level up: **the narrowness usually belongs to the
memory access, not to the parameter that feeds it.** A `u8` parameter is only
right when the target actually shows the mask at the call site. Before widening
one, run try_func over every decompiled caller and the callee itself — the
prototype is shared, so this is the same hazard as adding one, and the same
`grep -rn <callee> src/` finds the files.

Also from this function, and covered by the reassociation section above but
worth the concrete pair: `D_8009B1E8[arg0 + 0x34]` folds the constant into the
load and emits `addu $v0,$s0,$v0` — index plus base. `(D_8009B1E8 + arg0)[0x34]`
emits `addu $v0,$v0,$s0` — base plus index. Same address, same instruction
count, different destination operand order, and it was the last difference.

## gcc computes `symbol & 0xFFFF0000` with the `lui` it already has

func_800383DC builds a far pointer as `((u32)tbl & 0xFFFF0000) + tbl[index]`,
where `tbl` is one of two symbols chosen by a preceding `if`. In the arm that
selects `D_801C0000` gcc never materialises 0xFFFF0000 at all: it reuses the
`lui $v0,%hi(D_801C0000)` from the address formation as the masked value, and
the join's `and` becomes `tbl & %hi(tbl)`. It does *not* do this in the arm
that selects `D_801D5800`, which gets a real `lui $v0,65535`.

The asymmetry is the giveaway: `%hi(sym) << 16` equals `sym & 0xFFFF0000` only
when the symbol's low half has bit 15 clear, and 0x801C0000's low half is zero
while 0x801D5800's is not. Retail emits the constant in *both* arms and does
the `and` at the join, so the compiler that built it did not take the shortcut.
Nothing tried from the source side blocks it — `tbl` as `u32` instead of
`u8 *`, a separate `base` local at the join, both assignment orders inside the
arms, both declaration orders. Parked one instruction short.

Worth carrying: a function that is exactly one instruction short with no other
fault is not automatically a park in the register class. Count what is
*missing*, not what differs — here the missing instruction is a constant that
gcc proved it did not need, and that reads as noise in a positional diff.

The two levers that did work on it are ordinary and worth restating together,
because both were worth several instructions each:

- **`s32 v = D_8009B32E;`, not `u16 v`.** A `u16` local makes every subsequent
  comparison `sltu`; retail's are `slt`. This is the same rule as the QImode
  note in WORKFLOW.md, and it cost 6 differences here before anyone looked at
  the interesting part.
- **The odd arm out goes after the shared tail.** Two of three branches share
  a tail and the third has its own; retail's layout is
  [arm1][arm2][shared tail][arm3][store]. Writing the third arm as a plain
  `else` puts it before the tail and adds a `j` to arm2, which no longer falls
  through. A `goto` out of the `else` to a label placed after the tail is what
  reproduces it.

## A copy into a callee-saved register at the point of definition is a second name

func_800386B8 reads a byte out of a bytecode stream and tests it against five
masks, with calls in between, so the value has to live in a callee-saved
register. Retail loads it and then copies it:

```
lbu  $a0, 0($v0)
addiu $v0, $v0, 1
sw   $v0, 0($v1)
addu $s0, $a0, $zero      # <- the copy
andi $v0, $s0, 63
```

Loading straight into the long-lived variable — `s32 op = *p;` — gives no copy
and is one instruction short. Two names give it:

```c
s32 c = *p;
*pp = p + 1;
op = c;
```

The rule this belongs to is already in WORKFLOW.md step 2 (func_8004318C: two
uses of one value can need two names). What is new is the *tell*: a copy from a
caller-saved register into a callee-saved one, right where the value is
defined, is not register allocation being clumsy — it is a second name in the
source. gcc allocates the short-lived one to the load's natural register and
the long-lived one across the calls. This is the same shape as the temporary a
conditional expression forces (func_800595C8), from the other end: **an extra
copy in the target is almost always an extra name in the source, and it is
free information because neither register allocation nor scheduling invents
one.**

One trap on the way: `u8 c = *p;` gets the copy in the right place but spells
it `andi $s0,$a0,255` — the widening to `s32 op` is a real conversion for a
QImode pseudo even though the `lbu` already zero-extended. `s32 c` is the one
that matches.

## A byte read twice around a store through another pointer is read twice

func_80059000 overrides three halfwords conditionally:

```c
if (q[7] != 0) *(u16 *)(arg1 + 0) = q[7] << 4;
```

gcc emits two `lbu`s of `q[7]`, because between them is a store through `arg1`
and it cannot prove `arg1` does not alias `q` — both are pointers reaching the
function from outside. Retail has one load with the shift in the branch's delay
slot, so the source held the byte:

```c
t = q[7];
if (t != 0) *(u16 *)(arg1 + 0) = t << 4;
```

That was the whole function: 43 differences to a match. The general form is the
inverse of "an expression the target recomputes was not a variable" — when the
target reads something **once** and you read it twice, look for a store between
your two reads that gcc has to assume aliases. One local fixes it, and unlike
most local-introducing edits it costs no register, because the value dies at
the branch.

## One symbol read `lb` in one place and `lbu` in another

func_800375A4 decrements a counter and then tests it:

```
lbu $v0, %gp_rel(D_8009B32C)($gp)   # the decrement reads it unsigned
...
lb  $v0, %gp_rel(D_8009B32C)($gp)   # the test reads it signed
```

One declaration cannot produce both. `extern u8` gives `lbu` twice; `extern s8`
gives `lb` twice, and a `(s8)` cast on the u8 does not change the load — for a
comparison against zero gcc has no reason to sign-extend, so it keeps `lbu`.

What works is casting the *lvalue*, not the value: `*(s8 *)&D_8009B32C == 0`
emits `lb`. That was the last difference in the function.

This belongs next to the `_IS_AGGREGATE` / `_IS_SCALAR` guards in
variables.h as a third way two uses of one symbol can disagree. The guards
handle *addressing* disagreements between files; this is a *signedness*
disagreement inside one function, and a per-file guard cannot express it. Reach
for the lvalue cast, and say in a comment which load it is buying — otherwise
it reads as noise and someone simplifies it away.

## Re-run the park list when a lever lands

func_8004C0AC was parked at 6 differences, all of them the loop counter's
increment: retail increments once in the preheader and once in the bottom
branch's delay slot and tests the pre-increment value, and three loop spellings
(`do`/`while` with `i++ < n`, a rotated `for`, `while (1)` with two breaks)
gave 6, 23 and 15.

The answer is the increment at the *top* of a `do`/`while` body:

```c
u32 i = 0;
u32 n = func_8004BB34(arg0);
do {
    i++;
    if ((func_8004BAE4(arg0) & 0xFF) == 0xF7) break;
} while (i < n);
```

gcc moves that increment to the end of the previous iteration — one copy peeled
into the preheader, one in the back-edge's delay slot — which is exactly the
shape the park describes and none of the three spellings tried could produce.
Match, first attempt, on a function that had been parked for weeks.

The process point is the one worth keeping. **A park records that a *shape* was
not found, not that no shape exists**, and the closed classes (register
allocation, cross-jumping) are the only ones where that distinction collapses.
Every time a new source-shape lever is measured, the park list becomes stale in
a specific way: entries whose diagnosis names *placement of instructions* —
a counter incremented somewhere unexpected, a copy that appears from nowhere, a
block on the wrong side of a loop head — are candidates for a free match.
Entries that say "$v0 versus $v1 in one basic block" are not.

Reading PARKED.txt for the phrase, not the count, is how func_8004C0AC came
back: its diagnosis said "all six are where the loop counter is incremented",
and by then "an increment in an unexpected place is a loop-form question" had
been written down twice that week.

## Three off the park list in one pass, and the shape that did two of them

The re-read of PARKED.txt described above paid three times the same afternoon.
Two of the three came from one new source shape.

**func_80026BA4** — a three-way select where the last two arms are one
instruction each. Retail:

```
bne  $a0, $v0, .join
 addiu $v1, $a0, -0x259     # delay slot: the taken arm's value
addiu $v1, $zero, 0x64      # fall-through overwrites it
```

Written as `else if (arg0 != 0x2D1) v = arg0 - 0x259; else v = 0x64;` — either
polarity, nested or chained — gcc puts the *other* value in the delay slot and
the pair never lines up. The shape that matches assigns unconditionally and
then overrides:

```c
v = arg0 - 0x259;
if (arg0 == 0x2D1) {
    v = 0x64;
}
```

This is func_800402A0's duplicated store in register form. The tell is the
same: **a value computed in a branch's delay slot that the fall-through then
overwrites is an unconditional assignment followed by a conditional one, not
two arms of an `if`.** A delay slot executes on both paths, so anything gcc
puts there it has already decided is harmless when overwritten — which is a
statement about the source, not about the scheduler.

**func_80019564** — one instruction: retail copies the object pointer out of
`$s0` into `$v0` and does the last read-modify-write through the copy. The park
had tried three spellings of a second pointer variable, all of which collapsed
back. The copy is not a second variable at all: it is `return p;` on a function
whose prototype said `void`. gcc materialises the return value early enough to
use it as the base for the tail. func_8002ABB4, matched the same week, shows
the same thing and was read correctly there only because its `$v0` base was
obviously the return register.

So the copy-means-a-second-name rule has a second reading worth carrying:
**check whether the copy is the return value before inventing a variable for
it**, and check the prototype rather than trusting it — `void` is what a
provisional signature says when nobody has read the callers.

**func_8004C0AC** is written up above; it is the loop-increment one.

## The fifth drop rule, and the first one that was a toolchain gap

`break` was in candidates.py's HAND_WRITTEN filter from early on, with the
stated reason that `break` and writes to `$sp`/`$gp`/`$fp` are the C runtime
stubs. That is true of the two-operand form — `break 0,260` and friends are the
BIOS syscall stubs sitting just under the library boundary — and false of
everything else. `break 7` and `break 6` are the divisor-is-zero and
`-1 / 0x80000000` overflow checks that aspsx wraps around a real `div`:

```
div   $zero, $v0, $s0
bne   $s0, $zero, .L1
 nop
break 7
.L1:
addiu $at, $zero, -1
bne   $s0, $at, .L2
 lui  $at, 0x8000
bne   $v0, $at, .L2
 nop
break 6
.L2:
mfhi  $v0
```

`func_800358FC` is that sequence and nothing else. Its source is
`return func_8008E590() % arg0;`.

**What made this different from the four retractions before it: the C was never
the problem.** Writing the modulo gets you `div` and `mfhi` and none of the
checks, because maspsx only emits them when passed `--expand-div` and build.py
did not pass it. maspsx even labels the region it is *not* filling in —
`# EXPAND_ZERO_DIV START` around a bare `div`/`mfhi` pair — which is as close
to a signed confession as a tool gets, and it went unread for months because
nothing ever looked at the intermediate for one of these functions. The filter
and the missing flag covered for each other: the filter meant no division
function was ever offered, so the flag was never exercised, so nothing ever
failed in a way that pointed at it.

`--expand-div` is now on globally in build.py, and the whole 667-function build
is still byte-identical, so retail expanded them everywhere. 41 in-scope
functions were hidden. Three matched the same hour: func_800358FC,
func_8004149C, func_80070E20.

The generalisation worth carrying is not about division. It is that **a drop
rule and a toolchain gap can hide each other indefinitely**, and the tell is a
filter whose population has never been *sampled*. Every previous retraction
came from measuring the population the rule excluded; this one came from the
same habit applied one level further — not "how many does it hide" but "what
happens if I write one".

## `jr $v0` is a `switch`, and the obstacle is the table, not the C

The same scan turned up 37 in-scope functions filtered on `jr $v`/`jr $a`/
`jr $t`. They are `switch` jump tables — splat has already named the tables
`jtbl_...`, and func_80070738 is a seven-case switch over `arg0` with a
`sltiu $v0,$a0,0x7` range check in front of it, which is exactly gcc's output.
The C for these is trivial.

The obstacle is real but is *not* a claim about C: splat emits the jump table
as data at its own address, and a compiler-generated table would be a second
copy competing for that space. Solving it means teaching build.py to suppress
splat's copy for the functions we compile, the way it already regenerates the
linker script from object sizes. **The rule stays in the filter with that
reason written down instead of the old one** — a measured obstacle, revisitable,
not "hand-written by construction".

## The sixth drop rule: splitting splat's .rodata so a `switch` can have its table

`jr $v0` was filtered as hand-written from the start. It is a `switch` jump
table, and the C is ordinary — func_80070738 is a seven-case switch and
matches to two instructions the moment it is written as one. The two are the
table reference: cc1psx puts its table at offset 0 of the object's own
`.rodata` and reaches it as `%hi(.rodata)`/`%lo(.rodata)`, where the target
names `jtbl_8001194C`, splat's symbol for the same bytes at the same address.

So the whole class was blocked on layout, not on source. build.py dropped
every non-`.text` section our objects produced — a comment even said "our
objects have no rodata/data/bss to contribute", which was true only because
nothing that produced any had ever been compiled.

**What it took, in the order the build told me:**

1. *Split splat's rodata at the owned tables.* Ownership comes from the
   table's own entries — `.word .L800XXXXX` targets land inside exactly one
   function — not from the owner's disassembly, which stops being read once it
   is decompiled. All 58 tables have a unique owner and all 47 owners' tables
   are contiguous blocks, so a hole is always one span.
2. *Copy everything outside a hole through verbatim.* The first version carved
   out only the `dlabel`..`enddlabel` spans and lost the 16 bytes the file ends
   with.
3. *Do not assemble the undivided object at all.* It defines every `jtbl`
   symbol a second time.
4. *Reinstate the hole's original extent.* cc1psx aligns each table to 8
   relative to its own section, so two tables that shared a translation unit
   have padding between them that separate objects cannot reproduce:
   jtbl_8001194C is seven live words and one word of padding that belongs to
   the table after it. The padding is `. = . + N` with N measured from the
   compiled object after it exists — an absolute `. = 0x8001196C` instead moves
   `_gp` and every gp-relative relocation in the binary overflows.
5. *Strip `.align 3` from the generated chunks.* This is the one that took the
   longest to see. Those directives are no-ops in splat's file, because splat
   lists every padding byte explicitly — but only while the segment starts
   8-aligned. A chunk starting at 0x8001196C is 4 mod 8, and the same directive
   then emits four real bytes, which pushed `.text` four bytes down and made
   every pointer in rodata wrong by four. The symptom was 639 "differing"
   functions and one byte in four differing from the very start of rodata;
   the cause was one directive that had never had to mean anything.

The class is 37 in-scope functions and **62 420 bytes — more code than
everything matched in the project before it**. Two are done (func_80070738,
func_800707C4); the rest average 421 instructions, so the unlock buys the
right to start, not the functions themselves.

try_func normalises `%hi(jtbl_X)` to `%hi(.rodata)` so the fast loop is usable
on them; only the full link can actually prove the address, and the sha1 does.

## objdump abbreviates repeated words, and try_func was eating nops

func_800357E8 converts a number to decimal digits. Written out it came to two
instructions short, both `nop`, in the one place the MIPS `mflo`/`mult` hazard
requires them:

```
mflo $v1
nop
nop
mult $t0,$t1
```

maspsx emits those nops — the scratch `.maspsx.s` has them, plainly. `as`
assembles them. They are in the object. What lost them was the *reader*:
`objdump -d` collapses a run of identical words into a line reading `...`, and
try_func's parser skipped the line and moved on two instructions poorer.

`objdump -z` disables the abbreviation. With it the function matches.

This is the seventh time in this project a tool has reported confidently on
something it had not measured, and the shape is the same every time: **a layer
between the artefact and the answer, doing something reasonable for a human
reader.** The nops were never missing; the diff was. Worth adding to the habit
in WORKFLOW.md: when a difference is a small number of `nop`s, suspect the
reader before the compiler — and read the intermediate, which took two minutes
and would have taken two more anywhere in the previous hour.

Every parked candidate was re-run afterwards, since a park at "two
instructions" could have been this and nothing else. **None of the 90 changed**
— a clean negative, and worth the twenty minutes it took: without it the
suspicion would have sat over the whole park list indefinitely. The closest
parks are still func_80038798 at 1 and func_80047864, func_80071424,
func_80071460 at 2.

## A fourth addressing form: a scalar plus a -G0 assembler

WORKFLOW listed three ways a symbol reference can be spelled and said of the
first, the scalar, that "the assembler's `-G` never enters into it". That was
never measured. It is wrong, and the four-line probe that shows it costs one
command:

```c
extern short A[];  extern short C;
void f(void) { A[0] = 0; C = 0; }
```

`CC1PSX -quiet -O2 -G8` emits

```
lui  $2,%hi(A)
sh   $0,%lo(A)($2)
sh   $0,C            # bare, with .extern C,2 above
```

The array gets cc1psx's own `%hi`/`%lo` pair. The **scalar gets the bare
symbol**, and it is the *assembler* that decides what to do with it: at `-G8` it
knows `C` is small data and renders `%gp_rel($gp)`; at `-G0` it cannot assume
that and expands through `$at`. So `lui $at` has two sources, not one:

- **aggregate + `-mno-split-addresses`** — a compiler flag, and it applies to
  every symbol in the file, including the ones that must keep their split pair;
- **scalar + `PER_FUNC_AS_FLAGS[f] = "-G0"`** — an assembler flag, and it only
  reaches symbols cc1psx already emitted bare, which is exactly the scalars.

func_80061008 is the case that separates them. It stores zero to two scalars
through `$at` *and* materialises two addresses (`D_801A8000`, and the address of
`func_80060B38`) with `lui $v0,%hi(...)` / `addiu $s4,$v0,%lo(...)` — a separate
temp, which is cc1psx's own pair and is destroyed by `-mno-split-addresses`
(under it the assembler expands `la $s4,sym` through `$s4` itself). No compiler
flag serves both. The `-G0` assembler serves both, and the function matches.

**The `-G0` assembler is not per-symbol, and that is the constraint that
decides it.** It takes *every* scalar in the file out of `%gp_rel`, not just
the ones you wanted bare. func_8002D458 is the counterexample already on
record: it wants four `$at` stores and three gp-relative scalars in the same
function, and the -G0 assembler gives it 79 differences by taking
D_8009B268/D_8009B26C/D_8009B26D out of the gp-relative form retail has.
All three functions this route matched (func_80061008, func_800610E0,
func_80024734) contain **no `%gp_rel` at all**, and that is the test:

```
grep -c '%gp_rel' asm/nonmatchings/31D8/<func>.s
```

Nonzero means the -G0 assembler is out and the aggregate plus
`-mno-split-addresses` route (func_80037A58's) is the only one left; that route
in turn is closed for jump-table functions, because the table load goes through
`$at` under it.

With that qualifier, the claim made when the jump-table class opened — that a
jump-table function needing `$at` stores is blocked — narrows rather than
disappears. It still holds for `$at` stores to aggregates, and for any function
that also has gp-relative scalars. It does *not* hold for a jump-table function
whose only bare accesses are scalars and which has no `%gp_rel`: there the -G0
assembler composes, because it changes nothing cc1psx emitted as a `%hi`/`%lo`
pair. That is a one-command filter over the 17 candidates, not a day of work.

## No epilogue at all means the last call does not return

`func_80030FD0` sets up a frame, saves `$ra`, makes four calls and then simply
stops: no `lw $ra`, no `jr $ra`, no stack release. That is not a truncated
listing and not a tail call. It is gcc emitting a barrier after a call it knows
cannot return, which deletes the epilogue while leaving the prologue (the
prologue is still needed — `$ra` is clobbered by the *first* call).

`void func_8008FB8C(u8 *, s32) __attribute__((noreturn));` reproduces it
exactly. `volatile void func_8008FB8C();`, the older gcc spelling, does not —
it parses, and it changes nothing.

The same property is why splat merged the function with its successor: with no
epilogue there is no boundary to find, and nothing in `.text` referenced
`0x80031000` because it is reached through a pointer table
(`asm/data/80EE0.data.s` has the `.word`). Both halves matched once split.

## The park filter had not filtered since the entries grew diagnoses

`candidates.py`'s `parked()` read `PARKED.txt` as one name per line. Entries
have carried `func_XXXXXXXX -- <diagnosis>` inline for a long time now, so the
set it built held whole sentences, and the only names still being excluded were
the oldest entries from before the format changed. Everything parked since was
being offered as a fresh candidate.

It never announced itself, because a filter that matches nothing and a filter
with nothing to match produce the same output. What made it visible was the
opposite symptom: three candidates in the 46-60 band, two of which had detailed
park entries. Fixed by anchoring on the leading `func_[0-9A-Fa-f]{8}` of any
line that starts at column 0. The set went from 437 sentences to 132 names.

## try_func dropped the addend on gp-relative relocations

`D_8009B348[1]` and `D_8009B348[0]` came out of try_func as the same
instruction. The target's `.s` writes `sh $a0,%gp_rel(D_8009B348 + 0x2)($gp)`;
our object has `sh $a0,2($gp)` with an `R_MIPS_GPREL16` relocation against
`D_8009B348` and an addend of 2 in the immediate field. try_func's
reattachment rewrote the immediate to `%gp_rel(D_8009B348)` and threw the 2
away.

This is the same bug that was already fixed for `R_MIPS_LO16` — the comment
above that branch even says so, and names func_80039E9C as the case that
caught it. The GPREL16 branch three lines below was left alone. Both forms of
the branch (`N($gp)` and `addiu $r,$gp,N`) now keep a non-zero addend, and the
normaliser collapses `sym + 2` to `sym+2` so the two spellings compare.

Worth noting what the failure looked like: two stores to *different* halfwords
reported as two stores to the *same* one, which reads as a source bug in the
candidate and not as a tool bug. The tell was that the target had `+ 0x2` and
we did not — visible in the diff, and easy to read past.

## An old park that had quietly become correct

`check_try_func.py` runs in two directions: everything in `src/` must MATCH,
and everything in `parked/` must not. The second direction is the one that
gets ignored, and it is the one that paid: after the GPREL16 fix it reported
`func_80015078: reported MATCH for a parked near miss`. The candidate was
right. It built green with no edit at all.

The obvious suspect was the GPREL16 fix itself — it is a *loosening*, and so
is the `sym + 2` → `sym+2` collapse that went in with it, so either could turn
a false difference into a match. **Measured, not assumed**: the pre-fix
try_func out of `git show HEAD~1` reports MATCH on the same file. The tool
change is not the cause. The candidate had simply been correct for some time
and nobody had re-run it; the entry is one of the oldest, from before the
keep-the-candidate rule was written down, and carries no diagnosis, just the
name. Which earlier change made it correct is not recoverable and is not
claimed here.

Two limits on reading this as "the park list is now swept". check_try_func can
only reach the ~100 entries that *have* a candidate file, and about a third of
PARKED.txt predates that rule and is invisible to it. And a MATCH from
try_func is still only a MATCH from try_func — this one was confirmed by a
green build before the entry was removed.

## The jump-table $at block, scanned instead of assumed

With the `-G0`-assembler form in hand, the 32 remaining jump-table candidates
sort by two greps -- `%gp_rel` and `lui $at` -- into three groups, and the
sort is the whole answer:

| `%gp_rel` | `lui $at` | count | route |
|---|---|---|---|
| 0 | 0 | 2 | nothing special needed |
| >0 | 0 | 14 | nothing special needed |
| 0 | >0 | 10 | **scalar + `-G0` assembler** -- newly available |
| >0 | >0 | 6 | still blocked |

The ten are func_8003B808, func_8003BF00, func_8005B64C, func_8002BD0C,
func_80057544, func_800577B0, func_800171A8, func_80042188, func_80056D7C and
func_8002ACA4, from 109 to 895 instructions. func_8003B808 was written as the
test: under a `-G0` assembler its dispatch block and all four `$at` stores come
out exactly as retail has them. It is parked on case-body *scheduling*, which
has nothing to do with the addressing question the class was blocked on.

The six that are still blocked (func_8001B170, func_800262D4, func_8003DC1C,
func_8001F55C, func_8001BD88, func_8001D670) want gp-relative scalars *and*
`$at` stores in one function, which is func_8002D458's situation exactly: two
knobs, three forms.

Note what this cost: two greps over 32 files. The previous estimate -- "17 of
the remaining 34 contain no `lui $at` and are the ones to take first" -- was
counting the wrong thing, because `lui $at` was being read as a single blocked
class rather than as two.

## -G is a size threshold, and that dissolves the three-forms barrier

The `-G0` assembler was written up as a file-wide switch: either every scalar
keeps `%gp_rel` or none does. That is what `-G0` does, but it is not what `-G`
*is*. `as` calls a symbol small data iff its declared size is `<= -G`, and
cc1psx writes the size out with the reference:

```
.extern E, 4      /* extern int E;      -> sw $2,E     bare */
.extern D, 8      /* extern int D[2];   -> sw $2,D     bare */
.extern B, 16     /* extern int B[4];   -> lui/%lo pair, cc1psx's own */
                  /* extern int A[];    -> lui/%lo pair, cc1psx's own */
```

So the bare form (the one the assembler gets to choose for) is emitted for
anything whose size cc1psx knows and considers small at *its* `-G8`; an array
of unknown size, or a known size over 8, gets cc1psx's own pair and the
assembler never sees a choice. For everything bare, the assembler's own `-G`
decides between `%gp_rel($gp)` and the `$at`/destination-register expansion.

Set the two `-G`s to different numbers and the split is **per symbol, by
size**. func_800136E4 is the first case: it wants `%gp_rel` for the `u8`
D_8009B0E0, `lui $at` for the `s32` D_8009B10C, and cc1psx's own `%hi`/`%lo`
pair for the unsized D_800E9DF0 and D_800E9EA8 — the three-forms-two-knobs
barrier this file has recorded twice as unmatchable. Compiling at `-G8` and
assembling at `-G2` gives all three, because 1 <= 2 < 4.

Two consequences worth chasing:

- Where the symbols happen to be the same width, the *declared* size is a knob
  in its own right. D_80010038 is declared `[4]` in this function's unit for
  exactly that reason, and the comment in variables.h says so — the size is a
  codegen choice, not a claim about the object, in the same way scalar-vs-array
  already is.
- It gives a fourth thing to try on every park whose diagnosis reads "needs
  three addressing forms and there are only two knobs" — func_80030FA0 and
  func_8002D458 both said that in those words, and **both matched the same
  afternoon** the threshold was measured. func_8002D458 was 42 differences and
  the first jump-table function to hit the barrier; func_80030FA0 was 7 and had
  eight source forms tried against it. Neither needed a source change beyond
  giving four one-byte symbols a declared size of 4 and assembling at -G2.
  The scan that finds the rest has to run over the **names in PARKED.txt**, not
  over `parked/*.c` — a third of the list has no candidate file, and globbing
  the directory silently skips them. It also must not require `%gp_rel`:
  `%gp_rel` *and* `$at` together is the case that needs an intermediate `-G`,
  but `$at` with no gp-relative access at all is the plain `-G0`-assembler
  case, which is what four of today's matches were. The right signature is
  simply `lui $at`:

```
.venv/bin/python -c "
import sys, os, re; sys.path.insert(0,'tools_src'); import candidates as c
for n in sorted(c.parked()):
    p = os.path.join(c.ASM, n + '.s')
    if os.path.exists(p) and re.search(r'lui\s+[$]at', open(p).read()): print(n)
"
```

  That returns nine, four of which had no candidate file and had never been
  re-read: func_800129D8, func_80030F40, func_8003594C, func_8003F7D4. **Three
  of those four matched immediately** — two on a plain `-G0` assembler with the
  symbols redeclared as scalars, and func_8003594C on `-G2`, because it wants
  `%gp_rel` for the one-byte D_8009B318 and `$at` for the four-byte D_8009B0F4.
  All three had been sitting on the glob's blind spot, not on any difficulty.
  The fourth, func_800129D8, is the C runtime entry stub (`or $sp`, `break
  0,1`) and was never a matching failure.
  The same loop with the park filter inverted sizes the *unattempted* pool at
  167 functions. func_8003D03C is the one counterexample among the nine — see
  below.

**It is not free.** func_8003D03C wants the same split and gets *worse* under
it: 10 differences to 39. The bare form is one pseudo-instruction when cc1psx
schedules, and maspsx only expands it afterwards, so every bare load ends up
with a `nop` in its load-delay slot where retail has a real instruction. When
the threshold fixes the addressing and the count goes up, that is what
happened, and the old route is the one to keep.

**A third signature, which neither scan catches.** The D_80010038 half of
func_800136E4 has no `$at` in it at all. The tell there is `lui $r,%hi(s)` /
`addiu $r,$r,%lo(s)` through the *same* register, re-materialised inside a
loop — where an unsized declaration makes cc1psx emit its own pair and hoist
the `%hi` into a callee-saved register instead. Any park whose diagnosis
mentions a hoisted `%hi` or one spare callee-saved register is a candidate on
that signature; func_8001BD48's entry ("retail hoists %hi(D_800A5768) between
them") reads exactly that way.

The other half of func_800136E4 was the same size threshold read the other
way. Retail re-materialises `%hi(D_80010038)`/`%lo` *inside* the loop; with the
symbol unsized, cc1psx emits its own pair and hoists the `%hi` into a
callee-saved register, costing a register and every offset after it. Sized at
4 with `-G2` it becomes one bare `la`, which is a single pseudo-instruction at
schedule time and cannot be split — 63 differences to 12.

## func_80058838 is variadic, and that is why it was set aside

Not parked -- it never reached a difference count -- but the reading cost an
hour and it will come back as a fresh 64-instruction candidate.

The frame is `-0x28`, so `sp+0x28` upward is the caller's outgoing area:
`sp+0x30`/`0x34` are arguments 3 and 4, `sp+0x38` is 5, `sp+0x3C` is 6. The
function takes the *address* `sp+0x3C` and walks upward four bytes at a time
reading `s32`s until one is negative, setting a bit per value in an eight-byte
bitmap it just cleared on the stack. That is a `...` list, not an array
argument.

Arguments 3 and 4 are `Word4` by value: they are spilled to `0x30`/`0x34` on
entry, one byte of argument 3 is overwritten (`sb $v0,0x33($sp)` = `arg1 &
0x7F`), and both are then reassembled byte by byte into `$a2`/`$a3` for the
call to func_80058938 -- which functions.h already declares as taking two
`Word4`s. The byte-wise reassembly around a call is the documented tell.

The one thing not explained: `and $a3,$a3,0xFFFFFF` sits between the third and
fourth byte of argument 4's reassembly, and is a no-op there (only 24 bits are
set at that point). Something in the source produces it and a plain struct
copy does not.

## The three-cycle register permutation: one class, five members, two negatives

Five parked functions now differ from retail by nothing except which register
holds which value, in the same shape each time. Keeping the shared facts here
rather than repeating them in five PARKED entries, so the next lever gets
tested against the class instead of against whichever member is in front of
you.

**The members.** func_8003B808 (82), func_80020BE4 (62), func_800434F4 (62),
func_8002F4C0 and func_8003C328 (untried, same body) are one family: a
three-case dispatch on arg1 that writes D_8009B0F4, D_8009B118 and a handful of
struct fields. func_800135FC (16) and func_8001352C (38) are a different body
with the same symptom. func_800245EC (68) and func_8005B4D8 (42) are leaves
with the same symptom and more registers in play.

**The shape.** In the switch family retail puts the 32-bit mask in `$a0`, the
loaded D_8009B0F4 in `$v0` and the small constant in `$v1`; we get `$v1`, `$a0`,
`$v0`. Instruction for instruction the two sides agree, including the `lui` of
case 0's mask hoisted into a branch delay slot, so every reported difference
is positional.

**What is ruled out, measured:**

- *Declaration order.* All 720 orderings of func_800135FC's five locals swept
  through try_func. 16 is the floor and the natural order is one of the
  winners.
- *The number of pseudos a global reference costs.* func_8002E470 matched
  partly by declaring its globals `[2]`, making each reference one
  pseudo-instruction at schedule time. Applied to func_8003B808 -- the one
  member where `-mno-split-addresses` is closed, so the sized route had never
  been tried -- it goes 82 to 94 at -G4 and 91 at -G2.
- *Flags.* Full sweep on every member; none beats the plain setting.
- *Extra names for the copies.* Two-name and literal-vs-variable spellings
  tried on func_80020BE4 and func_8003C7A0's neighbours; they move the count
  by a few and never the allocation.

**The permuter, tried at last, and it wins.** `python tools_src/permute.py
func_800135FC` found a zero score in 66 iterations -- about ninety seconds on
six threads -- after this same function had survived a 720-permutation
declaration-order sweep. The whole change:

```c
    x = w;
    func_800134E0(p, x, y, z);
```

Assigning the last value to a variable whose live range ended two statements
earlier. It computes nothing; it is a hint to the allocator, and it is what
retail's allocation shows. The declaration sweep could not reach it because it
is not a declaration, and reading the listing cannot suggest it because the
instruction it produces is one retail does not have (the copy is coalesced
away).

**And a measured limit.** The same search on func_8001352C -- the sibling, same
body, 27 differences after the hint was applied by hand -- ran 2155 iterations
without finding a zero and was stopped. func_800135FC took 66. Two cores is
part of it, but the honest reading is that the permuter closes some members of
this class and not others, and it is not a substitute for understanding the
shape. The typemap failure rate is also worth knowing: 91 in 2155, about 4%,
all from implicitly-declared callees.

**The permuter's score is not the difference count, and it will reward a
semantically broken source.** func_8001352C's best output scored 160 and
reports 19 differences through try_func -- better than the 27 the hand
candidate gets. It arrives there by wrapping one of the two `+ 0x400`
arguments in `(char)`, which under this project's `-D__CHAR_UNSIGNED__` is
*zero*: the `addiu $a0,$a0,0x400` the target has simply disappears. The
function is one instruction short and computes something else.

Two things follow. The score is a weighted diff, not an instruction count, so
a permuter number cannot be compared against a PARKED entry's number without
running the output through try_func. And try_func does not shout about a
length mismatch -- its aligner absorbed the missing instruction into the
positional diff, so "19" looked like progress. WORKFLOW's first debugging step
is "instruction count right? nothing else is diagnostic until it is", and it
applies to permuter output as much as to hand-written C.

The class is four members after func_800135FC came out, and five again with
func_8002FB78 added on a checked rotation rather than a resemblance. Applied by hand to the sibling
func_8001352C it gives 38 differences to 27, so the shape generalises but is
not the whole story there; a permuter search is running on it.

Two things learned wiring the harness, both in tools_src/permute.py's
docstring: `prelude.inc`'s `.set gp=64` is rejected by our assembler on a
32-bit processor, and implicitly-declared callees make the permuter's typemap
raise KeyError during some randomizations -- three failures in sixty-six
iterations, survivable, but prototypes in the candidate cost nothing.

## The $at pool, partitioned

The remaining pool was suspected to be mostly clones of two families. Counted
rather than eyeballed, over the 62 candidates that pass both filters:

| family | signature | count |
|---|---|---|
| three-case switch clone | `%hi(D_8009B0F4)` + `%hi(D_8009B118)` + `%hi(D_801AF000)` | 4 |
| display-list leaf | `%hi(D_800FE240)`, no `addiu $sp` | 2 |
| genuinely distinct | — | 56 |

func_8003A01C was checked against the signature by hand because it *looks*
like a family member -- three-case dispatch, the same `0xFFDDFFFF` mask. It is
a genuine variant: no `%hi(D_801AF000)` anywhere, case 0 computes
`0x340 - n * 192` into a field the family does not touch, and case 2 reads
`*(s32 *)(p + 0x3C)`. The signature was right to exclude it, so the count
stands at four.

So the clone worry was largely unfounded: six of sixty-two. The four switch
clones are func_8002F4C0, func_8003C328, func_8003C120 and func_8003BF00, and
they belong to the permutation class above; the two leaves are func_8005B260
and func_8005B36C. Everything else is independent work.

## Repo layout / tooling plan

- `tools_src/ghidra_scripts/` — `FunctionInventory.java` (dumps library vs. game function lists + memory map), `DumpFunction.java` (dumps disassembly + Ghidra's decompiler guess for one function, given a hex address as `-postScript` arg), `OverlayCheck.java` (searches for CD-read call sites and indirect-jump patterns, used for the overlay investigation above). All run via `analyzeHeadless ... -process SLUS_014.11 -noanalysis -scriptPath tools_src/ghidra_scripts -postScript <Name>.java [args]`.
- Ghidra + `ghidra_psx_ldr`, the PsyQ SDK, and `asm-differ` are NOT vendored in the repo (`/tools/` gitignored) — anyone picking this up needs to redownload/reclone all three themselves (see the sources cited above for each).
- Next concrete task: the Makefile/compile-and-diff wiring described above, then start actually matching functions, prioritizing ones DataCrystal's RAM map already gives us names/context for.
