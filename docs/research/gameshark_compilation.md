# GameShark codes for SLUS-01411, decoded and verified

Compiled from the public cheat archives and checked against the retail
executable. Contributed by MaChInEgUn3; the codes themselves are the work of
the hackers credited in the tables — **Police NYPD**, **roughnight**,
**hugopocked**, **StalkerX**, **00Kevin**, **Mantidactyle**, **M1CR0H4CK3R**.
This cites and decodes their work, it does not redistribute the archives.

## Why these are worth having

They are the complement of the community file offsets:

| source | points at | names |
|---|---|---|
| community file offsets (`tutorials.7z`) | an instruction in the FILE | a **function** |
| GameShark codes | an address in RAM | a **variable** — and sometimes a function |

That last part is easy to miss. PS1 RAM holds the executable, so a code writing
below the game/SDK split is a **runtime binary patch**, and those name
functions.

A cheat is a claim that changing one value produces one named effect, and it
has been tested by everyone who ever used it. That is not proof, but it is
better sourced than a guess.

## Harvest

| source | codes | access |
|---|---:|---|
| gamehacking.org, 70 groups | 1960 | `POST /modules/game.php` with `gamID`+`grpID` — the endpoint `fillGroup()` calls; the codes are **not** in the served HTML |
| gamehacking.org, master codes table | 23 | in the served HTML, and a **separate table from the 70 groups** — easy to miss, and it holds the most useful codes |
| almarsguides.com, 5 pages | 296 | plain fetch |
| kodewerx forum thread | 8 | plain fetch |

cheatcc 403s with no clean fallback and is the one source not covered.

Practical note: **headless Playwright is Cloudflare-blocked on gamehacking.org
while plain `urllib` with a browser UA is not** — the opposite of the usual,
and worth knowing before spending an hour on a browser.

## The verification gate, and its limit

Every `D0`/`E0` conditional line asserts what a value already is, so it is
checkable against `SLUS_014.11`. But the check is only meaningful for one of
the two cases, and conflating them would be reporting a verdict we did not earn:

* **guard on a CODE address** — asserts an instruction halfword, which never
  changes. A mismatch proves the code was written for another build, so it is
  **REJECTED**. This is what keeps PAL/JP codes out of a list labelled NTSC-U.
* **guard on a DATA address** — asserts a runtime value; the file holds only
  its initial form, so a mismatch means nothing and it reports **UNCHECKABLE**.

Result over 232 code lines: **3 VERIFIED, 0 REJECTED**, 11 UNCHECKABLE, 10
outside the loaded image, plus writes and repeat directives. Control: a
deliberately wrong guard on a verified address does come back REJECTED, so the
gate can say no.

## The three verified code patches

**`func_8002BFCC` — the Library's per-card display gate** (not decompiled in
my tree, and unnamed in both the GMS idb and Unchiga's roster).

```
D002C322 1040     guard: the halfword at 0x8002C322 is 0x1040
8002C322 2400     write 0x2400                       -- hugopocked, "All cards in library"
```

`0x8002C320` holds `beqz $v0, .L8002C358`. Its upper halfword in memory is
`0x1040`; writing `0x2400` makes the word `0x2400000D`, which is
`addiu $zero, $zero, 0xD` — a no-op. The branch is deleted and every card
displays. So the `beqz` at that address is the "have you seen this card" test.

**`func_80038BF0` — password-entry card purchase** (decompiled in my tree).

```
D0038C60 3021 / 80038C60 000F
D0038C62 0080 / 80038C62 3406     -- hugopocked, "You don't need stars to buy cards"
```

`0x80038C60` holds the word `0x00803021` = `addu $a2, $a0, $zero`. The patch
writes `0x3406000F` = `ori $a2, $zero, 0xF`. So `$a2` at that point carries the
star cost and the cheat pins it to 15.

Several other master codes patch `0x8016xxxx`–`0x8018xxxx`, which reads as zero
in the main executable — those are **overlay** code, and verifying them needs
the overlay binary rather than `SLUS_014.11`.

## Structures derived from the bulk

Rather than pasting 700 near-identical rows, these are the layouts the bulk
codes pin down. Each is derived from the address arithmetic, so a wrong one is
visibly wrong.

**Card trunk — 722 entries, one byte each, from `0x801D0250`.**
Max Card parts 1–6 are byte writes from `0x801D0250` to `0x801D0521` with
**every consecutive gap exactly 1**. 0x2D2 = 722. Note the count: sources that
publish only 250 give the wrong constant, and gamehacking has a group named
"722 Slot Chest Card Deck Codes" plus a cheat literally called "Have All 722
Cards".

**The Library seen-flag shares that same array.** `801D0250 0505` under a
`5000FF02` repeat (255 iterations, step 2) plus `801D044E 0505` under
`50006A02` (106 more) covers exactly the same 722-byte span, so the per-card
byte carries both the count and the seen flag.

**Duelist records — `[wins:u16][losses:u16]`, stride 4, 39 slots from
`0x801D0720`.** Each duelist has a "Max Wins" code at the record base and a
"0 Losses" code at +2. Sorted by address the stride is 4 throughout, with
exactly two breaks — and **both are errors in the source**, provable from the
stride and confirmed by the labels:

* Simon Muran's pair is `0720`/`0724`, a gap of 4 where every other duelist's
  is 2. His losses field should be `0x801D0722`.
* Villager 3's "Max Wins" is `0734`, which is Villager 2's losses field. It
  should be `0736`, with losses at `0738`.

Corrected, the array runs `0x801D0720`..`0x801D07BC` with no gaps, exactly 39
duelists.

**Card records — one array at `D_801A7AD8`, stride `0x1C` (28), ATK at `+0xE`,
DEF at `+0x10`.** Three separate code blocks land on the same array:

| block | first address | = base + | record |
|---|---|---|---|
| in-hand cards | `0x801A7AE6` | 0xE | 0 |
| player's monsters | `0x801A7B72` | 0x9A | **5** |
| opponent's monsters | `0x801A7D16` | 0x23E | **20** |

Record 5 for the player's first monster matches Unchiga's
`playerMonsters 0x801A7B64` exactly (`base + 0x8C`), and stride 28 on
`D_801A7AD8` is what my own tree already compiles against — so the cheats and
two independent decomps agree on the layout.

**Ten record slots per side, not five.** The "All Opponent Monsters" code
touches `801A7D16`, `7D32`, `7D4E`, `7D6A`, `7D86`, `7DA2`, `7DBE`, `7DDA`,
`7DF6`, `7E12` — ten consecutive records at 0x1C stride, i.e. records 20–29.
The player side is the same shape, records 0–9. The per-slot codes only expose
five each, so the ten-slot extent is visible only in the "All …" variants.

**The player's ten split into two halves that the cheats treat as one card.**
"Monster Card On Player Field Slot 1" writes **both** `801A7AE6` (record 0) and
`801A7B72` (record 5); slot 2 writes records 1 and 6, and so on. So records 0–4
and 5–9 hold two copies of the same five cards. Unchiga's
`playerMonsters 0x801A7B64` is the base of record 5, which makes 5–9 the field
copy and 0–4 the other one.

**A source error, confirmed twice over.** Police NYPD's "Card 5" codes use
`801A7D82`, which breaks the 0x1C stride by 4; the expected address is
`801A7D86`.

* roughnight's "Opponent Field Slot 5" codes use **`801A7D86`**. Two hackers,
  same field, one typo.
* And the wrong addresses do not fit the field layout either: `801A7D82` and
  `801A7D84` land on record 24 at offsets `+0xA` and `+0xC`, where every other
  ATK/DEF pair in the array sits at `+0xE`/`+0x10`.

One other offset in the array is real rather than a typo: `801A7D1E` is record
20 at `+0x16`, the field Police NYPD's "Enemy Can Never Lay Any Cards Down"
code writes.

**Life points — per-side record, stride `0x20`.** Player LP at `0x800EA004`,
CPU LP at `0x800EA024`.

## Other addresses worth naming

| address | what the cheats say it is | credited to |
|---|---|---|
| `0x80184594` | menu selection — writing `0x0B` opens the Debug Menu | Mantidactyle |
| `0x801D07E0` | starchips, 4 bytes (written as two halfwords making 999999) | StalkerX, 00Kevin |
| `0x801D06F4`–`F6` | free-duel opponent unlock bitmask | Police NYPD |
| `0x801D0698` | password-use counter | M1CR0H4CK3R |
| `0x801A7D1E` | opponent AI behaviour (`0` = never lays cards, `0x8402` = attack loop) | Police NYPD |
| `0x8009B062` | writing `0x0101` skips the intro FMV | Police NYPD |
| `0x800F284A` | 3D card viewer rotation | Police NYPD |
| `0x801E1B88` | music track (writing `0x08B7` silences it) | Police NYPD |
| `0x80092AC8` | slow-motion mode | Police NYPD |
| `0x800FE068`/`6A` | in-duel monster placement side | roughnight |

## Files

* `gameshark-codes.tsv` — **1090 rows**: category, name, hacker, code, gate
  status, resolved address, note. Every one of the **890 distinct addresses**
  that appears anywhere in the harvest is present, so an address search finds
  it. That includes all 722 Max Card writes in full, and the 25 Slot Machine
  records expanded to one row per target address — each of those expands to
  32–145 lines that differ only by a 0x3E8 value step, which an address search
  cannot use.

kodewerx was checked and adds nothing: its 8 codes duplicate the starchip and
password codes already here.

Nobody has run a patched binary here, so the *effects* remain the hackers'
claims. What is verified is the address, the guard byte, and the instruction.
