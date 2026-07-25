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
2. **Does the source's read order match the target's?** Three functions in one
   session came down to this alone — `func_80049F10`, `func_80037CE0`,
   `func_800373C8`. Declaration order *is* read order. Thirty seconds to check.
3. **Is the branch polarity right?** Look at which path retail falls through
   into; cc1psx emits the fall-through for the branch written as not-taken.
4. **Count the materialisations** of each value. One per write in the source.
5. **Then** sweep flags.

I spent a long time doing 5 before 2 and 3, which is why this list exists.

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
failure shape, and the second inside `sweep_flags.py` alone. The running list:

| where | what varied unnoticed |
|---|---|
| `config/flag_overrides.json` | not in the staleness check |
| `-fno-schedule-insns` | effect on output never verified |
| `YGOFM_DROP_POSTPASS` | not in the flag stamp |
| `sweep_flags.py` (as-flags) | set `cc` but inherited `as` |
| prototype reconcile regex | silently skipped pointer returns |
| `sweep_flags.py` (build status) | treated a failed build as clean |

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
recorded `-fno-schedule-insns` as tried-and-useless. **That entry was wrong, and
the way it was wrong is worth remembering:** the flag is *accepted* by cc1psx
(passing `-fnoschedule-insns` errors, so option parsing does work) but produces
**byte-identical output**. It changes nothing, so a non-matching build says
nothing about it. Verified by hashing cc1psx output with and without it.

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

339 of 1794 functions decompiled and byte-matching.

The 1794 total is misleading as a denominator, though. Subtract 342 library functions and ~116 hand-written GTE/COP2 routines that will likely never become C, and the real target set is closer to **~1340 functions**, of which ~339 are done. Instruction count is probably the better measure of remaining work: ~128,000 still in assembly.

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

**Known limitation:** it compares branch labels literally, so any function with internal branches (gcc emits `$L2`, the disassembly has `.L80042B28`) reports spurious differences. Treat a "differs" result on a branching function as inconclusive and fall back to the full build, which is the real authority. Straight-line functions are reported accurately.

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

## Repo layout / tooling plan

- `tools_src/ghidra_scripts/` — `FunctionInventory.java` (dumps library vs. game function lists + memory map), `DumpFunction.java` (dumps disassembly + Ghidra's decompiler guess for one function, given a hex address as `-postScript` arg), `OverlayCheck.java` (searches for CD-read call sites and indirect-jump patterns, used for the overlay investigation above). All run via `analyzeHeadless ... -process SLUS_014.11 -noanalysis -scriptPath tools_src/ghidra_scripts -postScript <Name>.java [args]`.
- Ghidra + `ghidra_psx_ldr`, the PsyQ SDK, and `asm-differ` are NOT vendored in the repo (`/tools/` gitignored) — anyone picking this up needs to redownload/reclone all three themselves (see the sources cited above for each).
- Next concrete task: the Makefile/compile-and-diff wiring described above, then start actually matching functions, prioritizing ones DataCrystal's RAM map already gives us names/context for.
