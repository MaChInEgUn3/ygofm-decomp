# Community cheat offsets, converted

The Brazilian/Spanish/Vietnamese FM modding scene has been publishing byte
patches for years. Every one is stated as a **file offset** into
`SLUS_014.11`, never a virtual address — krystalgamer's observation on
2026-09-01, and the reason that corpus has never been usable by a decomp.

It is one conversion away from being usable. `tools_src/offset.py` does it:
`offset + 0x8000F800` → vram → the containing function → the instruction the
byte belongs to.

Source: `tutorials.7z`, 53 files, shared by krystalgamer. Third-party work by
that community and not redistributed here; `third_party/` is gitignored. The
individual credits below are theirs.

**22 of the 30 offsets cited in the `.txt` files land on an in-scope
function.** The rest are asset or table offsets past the code region.

## Why this outranks a wiki row

A cheat is a claim that changing **one byte** produces **one observable
effect**, it points at the instruction implementing that effect, and it has
been tested by everyone who ever used it. That is closer to evidence than a
name in a database. It is still a hypothesis in the sense `EXTERNAL_LEADS.txt`
means — nobody here has run a patched binary.

## The confirmation that makes the rest credible

`func_80021598` is named **`calcRankScore`** in the GMS idb, and the community
cheat that lands on it is *"Exodia Sempre S-Tec"* — force an S-Tec rank. A
2018 IDA database and a Brazilian forum post, neither aware of the other,
pointing at the same function for the same reason.

## Five functions the community understands and neither RE source named

| function | what the cheat does | credit |
|---|---|---|
| `func_800175A0` | change life points | Jael Rivera |
| `func_80018CF8` | disable Exodia (two offsets) | — |
| `func_80025D30` | Shadow Spell / Spellbinding Circle (four offsets) | — |
| `func_8003CCD8` | remove Trade, block B. Quadrado and 2P | — |
| `func_80018004` | Millennium Eye: reveal the opponent's hand | Markin Marcal |

`func_800175A0` and `func_8003CCD8` are already worked examples in
`docs/WORKFLOW.md` for the `u8 sym[8]` + `as -G4` addressing trick, so we knew
how to compile them and not what they were.

`func_80018004` is the fully traced one: file `0x8864` → `0x80018064`, the
immediate of `addiu $v0, $zero, 0xFF` followed by `sb $v0, 0x67($a0)`, guarded
by a sign test on the card record's `+0x1F`. So **`+0x67` is a card's
visibility marker**, `0xFF` meaning hidden.

## One name sharpened

`func_800218F0` is `u_maybe_endOfDuel` in the idb — hedged, with the author's
own `maybe`. The cheat on it is *"Alterar Starchips"* (Wladmir Ghost).
Starchips are awarded at the end of a duel, so the two agree and the cheat
narrows the guess to the reward path specifically.

## Read with care

Two of the 22 sit at suspiciously round offsets — `0x54000` ("Apontador
Cartas") and `0x55C00` ("Numeral Carta Fusao"). Both land inside functions
Unchiga's roster names as GTE rendering helpers, which is compatible with
drawing a cursor and a fusion numeral, but a round offset is what an asset
patch looks like. Verify before using either.

Ambiguity worth knowing: the tutorials never say whether an offset is decimal
or hex. Where they also state the byte value, that settles it for free —
`offset.py --expect FF` picks the reading that matches, which is how `8864`
was resolved to hex rather than decimal.
