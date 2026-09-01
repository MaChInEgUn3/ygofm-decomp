# GameShark codes, decoded

krystalgamer asked on 2026-09-01 for a compilation of GameShark codes as
reference material for the agents. They are worth more than they look, and
they are the **complement** of `community_offsets.md`:

| source | points at | names |
|---|---|---|
| community file offsets | an instruction | a **function** |
| GameShark codes | a RAM address | a **variable** |

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
