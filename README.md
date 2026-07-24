# Yu-Gi-Oh! Forbidden Memories — Matching Decompilation

Matching decompilation of the PS1 game *Yu-Gi-Oh! Forbidden Memories* (NTSC-U, `SLUS_014.11`), in the same style as [OpenDriver2](https://github.com/OpenDriver2/REDRIVER2), [sotn-decomp](https://github.com/xeeynamo/sotn-decomp), and [mgs_reversing](https://github.com/FoxdieTeam/mgs_reversing): the goal is byte-exact C recompilation of the original executable using the original PsyQ SDK toolchain, not a reimplementation.

**The disc image, extracted executable, and downloaded toolchain binaries (Ghidra, PsyQ SDK) are never committed** — you need your own legally-owned copy of the disc and your own copy of the PsyQ SDK to build/verify anything here. This matches the posture of every comparable community project (sotn-decomp, mgs_reversing, OpenDriver2, Severed Chains).

The disassembly output itself (`asm/`, `src/`) **is** committed, same as those projects do — publishing disassembly/decompilation-in-progress of a binary you don't redistribute is the whole point of a project like this, and is the long-standing, untouched practice across the PS1 decomp community. See `docs/DECISIONS.md` for the exact line between what's in and what's out.

## Status

See `docs/DECISIONS.md` for the current state of the project (toolchain, confirmed facts, open questions) and `docs/FUNCTION_INVENTORY.txt` for the current function-by-function breakdown.

## Layout

- `docs/` — RAM/ROM map notes, decisions log, function inventory (source of truth, kept in sync with the code as the project evolves)
- `tools_src/ghidra_scripts/` — our own Ghidra headless-analysis scripts (Java)
- `config/` — splat config (once toolchain is confirmed)
- `asm/` — disassembly output (once splat is set up)
- `src/` — matched C source, function by function, as it's proven byte-exact
