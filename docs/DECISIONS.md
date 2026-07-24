# Decisions & confirmed facts

Single source of truth for project state. Update this whenever a decision changes or a new fact is confirmed — this file (plus the rest of `docs/`) is meant to let anyone (or any future agent session) pick the project back up without re-deriving everything from scratch.

## Scope decision

**Matching decompilation, not reimplementation.** The goal is byte-exact recompilation of the original executable against the original PsyQ toolchain, in the style of OpenDriver2/sotn-decomp/mgs_reversing. A reimplementation (new code, equivalent behavior, not byte-matching) was explicitly considered and rejected.

## Legal posture

No copyrighted files (disc image, extracted executable, `MRG`/`STR`/`XA` assets) are ever committed. Only code, config, and tooling live in this repo. Anyone building/verifying against it needs their own legally-owned copy of the disc. This is the same posture that has kept OpenDriver2, Severed Chains, and sotn-decomp alive under Konami's historically aggressive C&D pattern. GitHub repo is **private** for now.

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
- **No overlay evidence found so far** — the loader created a single flat set of segments, no separate overlay regions. This is a preliminary signal, not a proof: PS1 overlays are often a runtime behavior (game code CD-reads a chunk into the same RAM address at a different time), which wouldn't show up in static segment layout. Needs confirmation once we're actually reading game code (look for CD-read-then-jump-to-fixed-address patterns). Task not closed yet.

## Repo layout / tooling plan

- `tools_src/ghidra_scripts/` — `FunctionInventory.java` (dumps library vs. game function lists + memory map) and `DumpFunction.java` (dumps disassembly + Ghidra's decompiler guess for one function, given a hex address as `-postScript` arg). Both run via `analyzeHeadless ... -process SLUS_014.11 -noanalysis -scriptPath tools_src/ghidra_scripts -postScript <Name>.java [args]`.
- Next: splat config once toolchain confirmed, then per-function matching against `decomp.me` / local asm-differ, with `src/` filling in as functions are proven byte-exact.
- Ghidra + `ghidra_psx_ldr` binaries themselves are NOT vendored in the repo (`/tools/` gitignored) — anyone picking this up needs to redownload Ghidra 12.1.2 and the matching `ghidra_psx_ldr` release themselves.
