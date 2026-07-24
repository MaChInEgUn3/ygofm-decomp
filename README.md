# Yu-Gi-Oh! Forbidden Memories — Matching Decompilation

Matching decompilation of the PS1 game *Yu-Gi-Oh! Forbidden Memories* (NTSC-U, `SLUS_014.11`), in the same style as [OpenDriver2](https://github.com/OpenDriver2/REDRIVER2), [sotn-decomp](https://github.com/xeeynamo/sotn-decomp), and [mgs_reversing](https://github.com/FoxdieTeam/mgs_reversing): the goal is byte-exact C recompilation of the original executable using the original PsyQ SDK toolchain, not a reimplementation.

**The disc image, extracted executable, and downloaded toolchain binaries (Ghidra, PsyQ SDK) are never committed** — you need your own legally-owned copy of the disc and your own copy of the PsyQ SDK to build/verify anything here. This matches the posture of every comparable community project (sotn-decomp, mgs_reversing, OpenDriver2, Severed Chains).

The disassembly output itself (`asm/`, `src/`) **is** committed, same as those projects do — publishing disassembly/decompilation-in-progress of a binary you don't redistribute is the whole point of a project like this, and is the long-standing, untouched practice across the PS1 decomp community. See `docs/DECISIONS.md` for the exact line between what's in and what's out.

## Building

The build reproduces the retail executable **byte for byte** (sha1 `84747e64f6da8e764206ec203e489acf8c9dcf7d`). That check is the project's regression test — if it passes, nothing has drifted.

A fresh clone cannot build until you supply the game and the toolchains, because none of them are committed. Full sequence:

1. **Provide the executable.** Dump your own disc, then extract `SLUS_014.11` from it into `extracted/`.
2. **Fetch the toolchains** into `tools/` — the PsyQ 4.6 SDK, a `mipsel-none-elf` binutils build, and `maspsx`. See `docs/DECISIONS.md` ("Local PsyQ 4.6 toolchain" and "Build harness") for exact sources and expected paths.
3. **Set up Python tooling** (project-local venv, never the system Python):
   ```
   python -m venv .venv
   .venv/Scripts/python.exe -m pip install "splat64[mips]"
   ```
4. **Generate the disassembly**, from the repo root:
   ```
   .venv/Scripts/splat.exe split config/SLUS_014.11.yaml
   ```
   This is required even though `asm/` is committed: the large data dumps (notably `asm/data/carddata.data.s`) are gitignored, and the linker script references them. It is safe to re-run at any time — decompiled sources live in per-function `src/func_*.c` files that splat never touches.
5. **Build and verify:**
   ```
   .venv/Scripts/python.exe tools_src/build.py
   ```

## Status

See `docs/DECISIONS.md` for the current state of the project (toolchain, confirmed facts, open questions) and `docs/FUNCTION_INVENTORY.txt` for the current function-by-function breakdown.

## Layout

- `docs/` — RAM/ROM map notes, decisions log, function inventory (source of truth, kept in sync with the code as the project evolves)
- `tools_src/ghidra_scripts/` — our own Ghidra headless-analysis scripts (Java)
- `config/` — splat config and the generated linker script
- `asm/` — disassembly output (per-function `.s` under `asm/nonmatchings/`)
- `src/` — matched C source, one file per decompiled function (`src/func_XXXXXXXX.c`)
- `tools_src/` — our own tooling: `build.py` (build + sha1 verify) and `try_func.py` (fast single-function match loop)

## Decompiling a function

Write `src/func_XXXXXXXX.c` and re-run the build. Placement is handled automatically — the harness positions every function via the linker script, so a decompiled function slots into the address the original occupied with no further bookkeeping.

`tools_src/try_func.py` gives a faster inner loop while hunting for the right C, without a full rebuild.
