# NAMING.md — where every symbol name comes from, and how much to trust it

Names in this repo are **semantic claims layered on top of a byte-perfect
build**. The oracle (byte-identical rebuild of `SLUS_014.11`, MD5
`dab1b3c9a6b8a56558b5ca8f807339c3`) is name-blind: renaming a symbol can never
make a wrong build pass or a right build fail, and every naming change here
was still verified by a full re-split + rebuild + SHA1 (`pass 2:
byte-identical. OK`). What a name CAN do is mislead a reader, so every name
carries an evidence tier, and the tier tells you how hard you may lean on it.

## Where names physically live

`config/symbol_addrs.txt` is **generated — never hand-edit it**. The sources,
in `tools/gen_symbols.py`, resolve per address as
`KNOWN.get(addr) or libsyms.get(addr) or func_ADDR`:

| store | holds | wins over |
|---|---|---|
| `KNOWN` dict (gen_symbols.py) | hand-assigned function names | libsyms |
| `DATA_KNOWN` list (gen_symbols.py) | all named data symbols | — |
| `libsyms/libsyms_470.txt` | PsyQ signature identifications | the `func_` default |
| default | `func_ADDR` / `D_ADDR` | nothing |

`reference/idb_raymond_2018/rename_plan.json` is the authoritative old→new
record of the 2026-08-31 import (173 entries); `tools/gen_vars_peer.py`
replays it whenever the peer header is regenerated. Unit **file** names are a
separate namespace (yaml + `gen_build.py`): `src/func_80021598.c` still
defines `calcRankScore` — a file rename pass ("stage B") is pending and
purely cosmetic.

## Evidence tiers, strongest first

### Tier 1 — real SDK symbols (PsyQ library + BIOS)
*Style:* whatever Sony wrote — `SpuSetReverbModeParam`, `_spu_FsetRXX`,
`CdIntToPos`, `EnterCriticalSection`.
*Evidence:* byte-signature matches against the shipped PsyQ 4.7 libraries
(`libsyms/libsyms_470.txt`, each row citing its origin, e.g. `LIBCD.LIB/SYS.OBJ
len=128`), and for `bios_a0_*/bios_b0_*` trampolines the documented PSX BIOS
call tables. These are the **actual original names** — the only tier that is
not an interpretation.
*Trust:* highest, but not infallible — FLIRT-style signature collisions exist
(see Conflicts below).

### Tier 2 — idb_raymond_2018 import (camelCase)
*Style:* `calcRankScore`, `aiInstBestCombo`, `duelLoop`, `fusionTable`,
`aiMemory`.
*Evidence:* extracted from a third-party IDA 6.8 database (author "Raymond",
2018) whose **recorded input MD5 is byte-identical to our target** — every
address maps 1:1, no cross-game inference. The names are a deep community
reverser's semantic reads (they align with FM wiki / AI-scripting lore), NOT
Konami debug symbols. Adopted **verbatim** — including the camelCase and the
author's own hedges (`u_maybe_endOfDuel`, `maybe_loadMonsterModel`) — so that
every one of these names is traceable to `reference/idb_raymond_2018/` rather
than silently laundered into house style. 145 renames + 28 new data symbols
applied (commits `0a58f74`, `fd158f6`, and the NEW_ADDR batch), each batch
byte-verified.
*Trust:* high for game-logic meaning; zero authority on what Konami called it.

### Tier 3 — behavior-derived names (snake_case)
*Style:* `upload_tpage_and_clut`, `mask_test_call_800eb26c`,
`backward_word_copy_with_tail_dispatch`, `weighted_random_pick`.
*Evidence:* the matched C body itself — the name describes verified mechanics,
nothing more. Written by this fleet during matching. Deliberately mechanical:
a Tier 3 name never claims game meaning it can't see (which is why Tier 2
displaced 145 of them or their `func_` neighbors — `spawn_fade_teardown_dispatch`
was correct mechanics, `tradeLoop` is what it's *for*).
*Trust:* reliable about WHAT the code does, silent about WHY.

### Tier 4 — placeholders
*Style:* `func_80012B50`, `D_8009B338`.
*Evidence:* none; the address is the name. Any `func_`/`D_` symbol is an open
invitation — check `reference/idb_raymond_2018/idb_crossref.txt` first before
inventing a Tier 3 name for one.

## Modifiers and disambiguators

- **`Name_ADDR` suffix** = a *second linked copy* of a library routine.
  `CdIntToPos_8007E600` / `CdPosToInt_8007E710`: libsyms owns the bare names
  at `0x8007A710`/`0x800781F0`; the binary genuinely links libcd twice.
  (`gen_symbols.py` also auto-suffixes any accidental duplicate this way.)
- **`_a/_b/_c`, `_arr`, `_raw`, `_b` alias families** + `// allow_duplicated:true`
  = multiple typed views of one address (scalar vs array vs raw byte view).
  Splat requires BOTH sides of a shared address to carry the attribute.
- **`u_` / `maybe_` prefixes** = uncertainty markers inherited from the IDB
  author; kept, not cleaned up, because deleting a hedge manufactures
  confidence no one earned.
- **`// absolute:True`** = symbol past the image end (file spans to vram
  `0x801E0800`; `musicTrack = 0x801EA800` is runtime arena), so splat cannot
  place it in a segment.
- **`// type:func`** on data-like addresses is itself a claim to audit:
  `func_80100000`/`func_80140000` are marked func in our config but the IDB
  says they are the player/enemy monster **model buffers** — left unrenamed
  pending review.

## Conflicts: 31 rows where two names claim one address

`reference/idb_raymond_2018/idb_crossref.txt` section `CONFLICT`. Policy
(operator ruling 2026-08-31): **leave them; the build stays 1:1 and neither
side gets bulk-applied.** They split into recognizable classes:

- *IDA FLIRT noise (ours wins):* `GsGetWorkBase_0/_1/_2` — one tiny signature
  matching three different functions; the `_ExitCard`/`_ExitCard_0` pair.
- *Probably ours wrong (IDB wins, pending byte-check):* `FntLoad` at
  `0x8007E910` vs our `upload_tpage_and_clut` — uploading the debug-font
  tpage+clut is literally FntLoad's job, and the IDB agrees with us on the
  adjacent `SetDumpFnt`/`FntOpen`/`FntFlush`/`FntPrint` cluster.
- *Genuinely undecided (needs bytes vs real PsyQ libs):* `SpuInit` vs
  `SsUtReverbOff` at `0x80074E60`; `SpuWrite` vs `SpuRead` at `0x80077150`;
  `DecDCTin` vs `DecDCTBufSize` at `0x8008FD38`.
- *Semantic vs mechanical (both true, one address):* `calcStats` vs
  `calc_clamped_pair`, `checkFusion` vs `fusion_table_lookup`,
  `randInterval` vs `call_8e590_mod` — Tier 2 meaning vs Tier 3 mechanics.
  Adjudicating these is a style decision, not an evidence question.

The standard for flipping any conflict row: byte-level comparison against the
real PsyQ library object, or behavior proof from the matched C — never
"the other database says so."

## Rules of engagement

1. Never hand-edit `config/symbol_addrs.txt`; edit `KNOWN`/`DATA_KNOWN` in
   `tools/gen_symbols.py` and re-run the pipeline.
2. Before naming ANY `func_`/`D_` symbol, grep
   `reference/idb_raymond_2018/idb_crossref.txt` for its address.
3. Every rename batch goes through commit → `tools/setup.sh` → byte-identical
   check. `prebuild_gate` will (correctly) refuse a large uncommitted sweep —
   commit first, never `PREBUILD_GATE=0`.
4. In `INCLUDE_ASM("asm/nonmatchings/<dir>", sym)` the dir is the **unit**
   name and only the `.s` file is the **symbol** name — rename only the
   symbol half, and purge stale old-name `.s` files after a re-split.
5. New names must not collide with any existing symbol, declaration, or
   common identifier; suffix duplicates with `_ADDR`.
6. Preserve inherited hedges; add your own (`maybe_`) when the evidence is
   partial.
