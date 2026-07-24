# Yu-Gi-Oh! Forbidden Memories — Matching Decompilation

Matching decompilation of the PS1 game *Yu-Gi-Oh! Forbidden Memories* (NTSC-U, `SLUS_014.11`), in the same style as [OpenDriver2](https://github.com/OpenDriver2/REDRIVER2), [sotn-decomp](https://github.com/xeeynamo/sotn-decomp), and [mgs_reversing](https://github.com/FoxdieTeam/mgs_reversing): the goal is byte-exact C recompilation of the original executable using the original PsyQ SDK toolchain, not a reimplementation.

**No copyrighted material (disc image, extracted executable, game assets) is ever committed to this repo.** You need your own legally-owned copy of the disc to build/verify anything here. See `docs/DECISIONS.md` for why this matters and how it's enforced (`.gitignore`).

## Status

See `docs/DECISIONS.md` for the current state of the project (toolchain, confirmed facts, open questions) and `docs/FUNCTION_INVENTORY.txt` for the current function-by-function breakdown.

## Layout

- `docs/` — RAM/ROM map notes, decisions log, function inventory (source of truth, kept in sync with the code as the project evolves)
- `tools_src/ghidra_scripts/` — our own Ghidra headless-analysis scripts (Java)
- `config/` — splat config (once toolchain is confirmed)
- `asm/` — disassembly output (once splat is set up)
- `src/` — matched C source, function by function, as it's proven byte-exact
