# GameShark codes, decoded

krystalgamer asked on 2026-09-01 for a compilation of GameShark codes as
reference material for the agents. They are worth more than they look, and
they are the **complement** of `community_offsets.md`:

| source | points at | names |
|---|---|---|
| community file offsets | an instruction in the FILE | a **function** |
| GameShark codes | an address in RAM | a **variable** -- or a function |

**That table's second row was wrong when first written here, and the
correction is the interesting part.** A GameShark address in the 0x800Exxxx
range and up is data, but PS1 RAM holds the executable too: an address below
the game/SDK split is an INSTRUCTION, and a code writing to one is a runtime
binary patch. `hugopocked`'s "All cards in library" is the specimen:

```
D002C322 1040        only if the halfword at 0x8002C322 is 0x1040
8002C322 2400        write 0x2400 there
```

`0x8002C320` holds `beqz $v0, .L8002C358`, whose upper halfword in memory is
`0x1040`. Writing `0x2400` makes the word `0x2400000D` -- `addiu $zero, $zero`
-- which is a no-op. The cheat deletes the branch so the code always falls into
the arm that displays the card. The conditional first line is a guard that the
byte is what the hacker expected, which is also a version check.

So the function containing it, **`func_8002BFCC`** (not decompiled here), is
the Library's per-card display gate, and the `beqz` at +0x354 is the
"have you seen this card" test. Neither the GMS idb nor Unchiga's roster names
it. It sits immediately after `setLibraryUsed` (0x8002BF3C), which is the
cluster you would expect.

A code is a claim that writing one value to one address produces one named
effect in the running game, tested by everyone who ever used it. Same standing
as a cheat offset and the same caveat: nobody here has run one.

`tools_src/gameshark.py` decodes them against `include/variables.h` and the
name files, reporting the covering symbol and the offset into it.

## What the first batch gives

```
8009B062 0101   D_8009B062              skips the intro FMV; the "somewhat mastercode"
800EA004 270F   D_800E9FF0 + 0x14       player life points  (0x270F = 9999)
800EA024 0000   D_800E9FF0 + 0x34       CPU life points
801D0250 C8C8   D_801D0250              trunk: 0xC8 = 200 copies, two cards per write
801D07E0 423F   D_801D07DC_w + 0x4      starchips, low half
801D07E2 000F   D_801D07DC_w + 0x6      starchips, high half (0x000F423F = 999999)
801E1B88 08B7   D_801E0000 + 0x1B88     silences music
80092AC8 CBB5   D_80092A90 + 0x38       "slow motion mode"
```

## The structural finding

**Life points are a per-side record with stride 0x20.** The player's LP sit at
`D_800E9FF0 + 0x14` and the CPU's at `+0x34` — the same field, one stride
apart. Unchiga's Field Guide lists only the CPU side (`cpuLp 0x800EA024`,
`cpuDisplayedLp 0x800EA022`); the codes supply the player's and, with it, the
layout. `cpuDisplayedLp` two bytes below the real value means each side's
record carries both the true LP and the ticking on-screen figure.

## Confirmations of names nobody had verified

Two of Unchiga's data names are confirmed from an unrelated direction:

* `trunk = 0x801D0250` — the "Have All Cards" code writes `0xC8C8` there, two
  adjacent one-byte counts of 200. That both confirms the address and says the
  trunk is a byte-per-card array.
* `starchips = 0x801D07E0` — written as two halfword codes making one 32-bit
  999999, so the field is 4 bytes.

## Reading them safely

The `50NNNNII 0000` prefix is a repeat-block directive, not an address, and
`D0`/`E0` lines are conditionals guarding the next line. The decoder skips
both rather than reporting a bogus symbol. Master/device codes vary per
GameShark version and say nothing about the game.

Sources: gamehacking.org/game/90203, almarsguides.com. Codes are the work of
the hackers credited on those pages (StalkerX, 00Kevin and others).


## The full compilation (2026-09-01)

Harvested exhaustively rather than sampled, because breadth is what tells you
which codes are worth reading.

| source | codes | access |
|---|---:|---|
| gamehacking.org, 70 groups | **1960** | `POST /modules/game.php` with `gamID`+`grpID`, the endpoint `fillGroup()` calls |
| almarsguides.com, 5 pages | 296 | plain fetch |
| kodewerx forum | 8 | plain fetch |
| **total** | **~2264** | |

cheatcc returns 403 with no clean fallback and is the one source not covered.
Headless Playwright is blocked by Cloudflare on gamehacking.org while plain
`urllib` with a browser UA is not, which is the opposite of the usual and
worth knowing before anyone spends an hour on a browser.

### Four structures, derived from the bulk rather than listed

**The trunk is 722 cards, not 250.** Max Card Codes parts 1–6 are byte writes
from `0x801D0250` to `0x801D0521`, **every consecutive gap exactly 1**. That is
0x2D2 = 722 entries, and gamehacking has a category literally named "722 Slot
Chest Card Deck Codes". The earlier note here said 250 because almarsguides
only publishes 250 — a sampled source gave a wrong constant and only the full
harvest caught it.

**The Library flag shares that array.** `801D0250 0505` with a `5000FF02`
repeat (255 iterations, step 2) plus `801D044E 0505` with `50006A02` (106 more)
covers exactly the same 722-byte span. So the per-card byte carries both the
count and the seen-in-Library flag.

**Opponents are a 4-byte record array at `0x801D0720`, 39 of them.** One code
pair per duelist, `270F` then `0000` two bytes later. Sorted by address the
stride is 4 with exactly two breaks — and **both breaks are errors in the
source**, provable from the arithmetic alone:

* Simon Muran's pair is `0720`/`0724`, a gap of 4 where every other duelist's
  pair is 2 apart. His second address should be `0722`.
* Villager 3's `0734` collides with Villager 2's second address. It should be
  `0736`/`0738`.

With those two corrected the array is stride-4 with no gaps from `0x801D0720`
to `0x801D07BC`, exactly 39 slots. The full table is in
`third_party/gameshark/opponents.tsv`.

**Monster records are stride 0x1C with ATK at +0xE and DEF at +0x10.** From the
Card 1–5 codes: `801A7B72`, `801A7B8E`, `801A7BAA`, `801A7BC6`, `801A7BE2` —
0x1C apart, and against Unchiga's `playerMonsters 0x801A7B64` that puts ATK at
+0xE. A second block at `801A7D16` follows the same stride until card 5, where
`801A7D82` breaks it by 4; expected is `801A7D86`. Third source error found the
same way.

## The verification gate, and its honest limit

`tools_src/gameshark.py` now checks every `D0`/`E0` guard against
`extracted/SLUS_014.11`, and the distinction matters more than the check:

* **a guard on a CODE address** asserts an instruction halfword, which never
  changes. Mismatch proves the code targets another build → `REJECTED`. That is
  what keeps PAL/JP codes out of a list labelled NTSC-U.
* **a guard on a DATA address** asserts a runtime value the game overwrites,
  and the file holds only its initial value. Mismatch there means nothing, so
  those report `UNCHECKABLE` rather than a verdict the tool did not earn.

Measured: `D002C322 1040` (the Library patch) is `VERIFIED` — our image really
does hold `0x1040` there. The three runtime guards in the Free Duel and In-Duel
codes come back `UNCHECKABLE`, correctly. A deliberately wrong guard on the
same address comes back `REJECTED`, which is the control: a gate that cannot
say no is not a gate.
