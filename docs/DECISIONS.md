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
  - **CONFIRMED: cc1/assembler is PsyQ 4.6.0 too**, via decomp.me (https://decomp.me/scratch/VnW0l): platform PS1, compiler preset **"gcc 2.95.2 + aspsx 2.86 (CCPSX)"**. Compiling against this preset produces build-log lines referencing `\backend\compilers\ps1\psyq4.6\cc1psx`, `...\psyq4.6\cpppsx`, `...\psyq4.6\aspsx` directly — i.e. that preset *is* PsyQ 4.6's real compiler/assembler binaries, not just an equivalent GCC version. Toolchain is pinned: **PsyQ 4.6.0**.
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

**A recurring unsolved class: the retail code overwrites the source pointer's register with its last load.** Where the original reads `lbu $a1, 0x0($a1)` -- destroying the pointer because it is dead afterwards -- gcc allocates a fresh register instead. Structure and instruction count are otherwise identical. Seen in `func_8003006C` and `func_8004143C`; `-O1`/`-G0` and the deref form do not shift it. (`func_8006C30C` looked like this class but was in fact plain register alternation, and `-O1` did fix that one, so check whether the pointer is genuinely being overwritten before assuming.)

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

172 of 1794 functions decompiled and byte-matching.

The 1794 total is misleading as a denominator, though. Subtract 342 library functions and ~116 hand-written GTE/COP2 routines that will likely never become C, and the real target set is closer to **~1340 functions**, of which ~172 are done. Instruction count is probably the better measure of remaining work: ~128,000 still in assembly.

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
