# GameShark codes — Yu-Gi-Oh! Forbidden Memories (SLUS-01411)

Every code I could find, with a one-line description each. Addresses were
checked against the retail executable; the **Notes** at the end say how, and
credit the people who wrote the codes.

Format is the standard PS1 one, `TTAAAAAA VVVV`, where the address is
`0x80000000 | AAAAAA`. A `50xxxxxx` line is a repeat directive for the line
after it; a `D0`/`C0` line is a condition guarding the line after it.

**Do not trust these blindly.** Unchiga hit incorrect Free Duel record codes
while building the rematch mod for the recomp, and two of the duelist codes
below are provably wrong — see that section.

---

## Life points

| code | what it does |
|---|---|
| `800EA004 270F` | player's LP fixed at 9999 |
| `800EA004 0000` | player's LP to zero |
| `800EA024 270F` | opponent's LP fixed at 9999 |
| `800EA024 0000` | opponent's LP to zero |

## Cards you own

| code | what it does |
|---|---|
| `301D0250 0063` … `301D0521 0063` | 99 copies of one card — 722 codes, one per card. Card *N* is at `0x801D0250 + (N-1)`, one byte each |
| `5000FF02 0000` / `801D0250 C8C8` / `50006A02 0000` / `80105F96 C8C8` | 200 copies of every card at once (GameShark 2.2+) |
| `B1050002 0000` / `801D0250 C8C8` | the same, for Caetla |
| `5000FF02 0000` / `801D0250 0505` / `50006A02 0000` / `801D044E 0505` | all 722 cards owned and marked seen in the Library |
| `50001202 0101` / `80105D98 0101` (+11 more pairs) | unlimited use of every card |

## Starchips and passwords

| code | what it does |
|---|---|
| `801D07E0 423F` / `801D07E2 000F` | 999999 starchips — one 32-bit value written as two halves |
| `50005B01 0000` / `801D0698 0000` | passwords can be entered without limit |
| `D0038C60 3021` / `80038C60 000F` / `D0038C62 0080` / `80038C62 3406` | password entry costs no stars — **patches an instruction**, see below |
| `D016A87C 1823` / `8016A87E 2400` | buying cards does not subtract stars |
| `D016A882 1480` / `8016A882 2400` | bought cards arrive immediately at the password screen |
| `D016A6E0 0005` / `8016A6E0 A9BE` / `D016A6E2 1040` / `8016A6E2 0805` | no limit on re-buying a card you already own |

## Duelists

Each duelist has a 4-byte record: **wins** at the base, **losses** two bytes
later. 39 of them from `0x801D0720`, stride 4.

| wins / losses | duelist |
|---|---|
| `801D0720` / `801D0724` | Simon Muran |
| `801D0726` / `801D0728` | Teana |
| `801D072A` / `801D072C` | Jono |
| `801D072E` / `801D0730` | Villager 1 |
| `801D0732` / `801D0734` | Villager 2 |
| `801D0734` / `801D0736` | Villager 3 |
| `801D0738` / `801D073A` | Seto |
| `801D073C` / `801D073E` | Heishin |
| `801D0740` / `801D0742` | Rex Raptor |
| `801D0744` / `801D0746` | Weevil Underwood |
| `801D0748` / `801D074A` | Mai Valentine |
| `801D074C` / `801D074E` | Bandit Keith |
| `801D0750` / `801D0752` | Shadi |
| `801D0754` / `801D0756` | Yami Bakura |
| `801D0758` / `801D075A` | Pegasus |
| `801D075C` / `801D075E` | Isis |
| `801D0760` / `801D0762` | Kaiba |
| `801D0764` / `801D0766` | Mage Soldier |
| `801D0768` / `801D076A` | Juno 2nd |
| `801D076C` / `801D076E` | Teana 2nd |
| `801D0770` / `801D0772` | Ocean Mage |
| `801D0774` / `801D0776` | High Mage Secmeton |
| `801D0778` / `801D077A` | Forest Mage |
| `801D077C` / `801D077E` | High Mage Anubisus |
| `801D0780` / `801D0782` | Mountain Mage |
| `801D0784` / `801D0786` | High Mage Atenza |
| `801D0788` / `801D078A` | Desert Mage |
| `801D078C` / `801D078E` | High Mage Martis |
| `801D0790` / `801D0792` | Meadow Mage |
| `801D0794` / `801D0796` | High Mage Kepura |
| `801D0798` / `801D079A` | Labyrinth Mage |
| `801D079C` / `801D079E` | Seto 2nd |
| `801D07A0` / `801D07A2` | Guardian Sebek |
| `801D07A4` / `801D07A6` | Guardian Neku |
| `801D07A8` / `801D07AA` | Heishin 2nd |
| `801D07AC` / `801D07AE` | Seto 3rd |
| `801D07B0` / `801D07B2` | Nitemare |
| `801D07B4` / `801D07B6` | Darknite |
| `801D07B8` / `801D07BA` | Duel Master K |

Write `270F` to a wins address, `0000` to a losses address.

**Two rows above are wrong as published, and this is where Unchiga's warning
bites.** He found incorrect Free Duel record codes while building the rematch
mod; the stride says which ones:

* **Simon Muran's losses should be `801D0722`.** His pair is 4 apart where
  every other duelist's pair is 2 apart.
* **Villager 3's wins should be `801D0736`, losses `801D0738`.** As published,
  his wins address is Villager 2's losses field.

Corrected, the array is stride 4 with no gaps from `0x801D0720` to
`0x801D07BC` — exactly 39 slots, which is the right number of duelists.

| code | what it does |
|---|---|
| `801D06F4 FFFF` / `801D06F6 FFFF` | every duelist unlocked in Free Duel |
| `D00E9E28 C000` / `D009B390 0100` / `8009B36C 0000` | Free Duel against glitched duelists for guaranteed drops — Select to enable, Triangle to leave |

## During a duel

| code | what it does |
|---|---|
| `801A7D1E 0000` | opponent never plays a card |
| `801A7D1E 8402` | opponent attacks repeatedly until you lose |
| `C009B168 9000` / `800FE068 0050` / `800FE06A 0000` | hold Up when placing a monster to put it on the opponent's field |
| `D009B390 0140` | Select+X on an opponent's monster takes control of it; O and move the cursor to exit |
| `801A7B72 270F` / `801A7B74 270F` | your first monster — ATK / DEF to 9999 |
| `801A7D16 270F` / `801A7D18 270F` | opponent's first monster — ATK / DEF to 9999 |
| `801A7D16 0000` / `801A7D18 0000` | opponent's first monster — ATK / DEF to zero |
| `801A7AE6 270F` / `801A7AE8 270F` | first card in your hand — ATK / DEF to 9999 |

Those are one slot of a repeating record. **Cards in play are a single array at
`0x801A7AD8`, 28 (`0x1C`) bytes each, ATK at `+0xE` and DEF at `+0x10`.** Ten
slots per side: yours are records 0–9, the opponent's are records 20–29. So the
second monster is 28 bytes after the first, and the whole set of per-slot codes
follows from that one fact.

There are also 25 "slot machine" codes that cycle a card's ATK/DEF through
1000-step values. They are 32–145 lines each and all target these same
addresses.

## Presentation and debug

| code | what it does |
|---|---|
| `8009B062 0101` | skips the intro FMV — needed for many other codes to work |
| `80184594 000B` | opens the Debug Menu |
| `801E1B88 08B7` | no music |
| `80092AC8 CBB5` | slow motion |
| `800F284A 4468` | the 3D card viewer stops rotating |
| `D002C322 1040` / `8002C322 2400` | every card shows in the Library — **patches an instruction**, see below |
| `D0168188 023A` / `8016818A 1000` | enable code, version 1 (must be on) |
| `D0168100 000A` / `80168102 1000` | enable code, version 2 |
| `D01683D4 0002` / `801683D4 A0F8` / `D01683D6 1440` / `801683D6 0805` | all Free Duel opponents unlocked |

## The codes that patch instructions

Two of them write into the main executable, and those name functions.

**`D002C322 1040` / `8002C322 2400` — "all cards in library"** (hugopocked).
`0x8002C320` holds `beqz $v0, .L8002C358`, whose upper halfword is `0x1040`.
Writing `0x2400` makes the word `0x2400000D` — an `addiu $zero, $zero`, a
no-op. The branch is deleted so every card displays. The containing function is
**`func_8002BFCC`**, and that `beqz` is the "have you seen this card" test.

**`D0038C60 3021` / `80038C60 000F` / `D0038C62 0080` / `80038C62 3406` — "no
stars needed at the password screen"** (hugopocked). `0x80038C60` holds
`addu $a2, $a0, $zero`; the patch writes `ori $a2, $zero, 0xF`. So `$a2` there
carries the star cost. The containing function is **`func_80038BF0`**.

The other patch codes target `0x8016xxxx`–`0x8018xxxx`, which is not in the
main executable — that is **overlay** code, loaded at runtime from
`WA_MRG.MRG`. The password-shop overlay has since been located on the disc
(`docs/DISC.txt`, 2026-09-02), and three of those codes verify against it, all
by hugopocked:

**`D016A87C 1823` / `8016A87E 2400` — "buying cards does not subtract
stars".** `0x8016A87C` holds `subu $v1, $v1, $s0`, the subtraction of the
card's star cost; the patch makes it `addiu $zero, $zero, 0x1823`, a no-op.

**`D016A882 1480` / `8016A882 2400` — "bought cards arrive immediately".**
`0x8016A880` holds `bnez $a0, +3`; the patch turns the branch into a no-op.

**`D016A6E0 0005` / `8016A6E0 A9BE` / `D016A6E2 1040` / `8016A6E2 0805` —
"no limit on re-buying a card you already own".** `0x8016A6E0` holds
`beqz $v0, +5`; the patch replaces it with `j 0x8016A6F8`, taking the
already-owned path unconditionally.

The Free Duel unlock patch (`D01683D4 0002` …) and the two "enable" codes
guard a *different* overlay loaded to the same region, and that one was not
found in raw form on the disc; those three remain unverified.

## From other sources

Found outside the main archives, so worth less confidence:

| code | what it does | where |
|---|---|---|
| `8009B364 00??` | field terrain — 00 normal, 01 forest, 02 wasteland, 03 mountain, 04 meadow, 05 sea, 06 dark | NightMare185, a 2002 GeoCities page |
| `300EA02D 0002` | opponent spams one card and draws badly | Legend of Dark, neoseeker 2012 |
| `D00EF6CA ????` | "reverse joker command" | almarsguides' Action Replay page |

**These I would not trust at all yet.** Posted to the gamehacking forum in 2013
by "Duncan Idaho", who says himself that they crash the game, and six of them
write 16-bit values to odd addresses:

```
Trigger Trap:        800F1C01 0020 / 800E9FF6 0020 / 801D5678 0020
Cards used by CPU:   800EA00E 0028 / 800EA028 0028 / 80103F00 0028
                     801060B7 0028 / 801AB491 0028 / 801D560C 0028
Cards used by you:   800EA008 0023 / 801060F6 0023 / 801AB3F5 0023
                     801AB449 0023 / 801AB49D 0023 / 801D5608 0023
```

---

## Notes

**Layout facts these codes establish.** Beyond the card array above: the trunk
is 722 one-byte entries from `0x801D0250` — sources publishing only 250 give
the wrong count; the Library's seen-flag lives in that same array; life points
are a per-side record at stride `0x20`.

**How the checking worked.** Every `D0`/`C0`-family line states what a value
already is, so it can be compared against `SLUS_014.11`. That is conclusive
only on a **code** address, where the halfword is an instruction that never
changes — a mismatch there proves the code was written for a different build.
On a **data** address the file holds only the power-on value, so a mismatch
means nothing. Three code guards checked out, none failed, and a deliberately
wrong guard does fail, so the check is real rather than decorative.

Nobody here ran a patched binary, so what a code *does* remains its author's
claim. What was verified is the address and the instruction.

**Sources.** gamehacking.org (70 code groups plus its separate master-codes
table), almarsguides.com (its GameShark *and* Action Replay pages — they differ),
kodewerx, neoseeker, a 2002 GeoCities page, and a 2013 gamehacking forum
thread. cheatcc and gamefaqs are Cloudflare-blocked. `ps2-home.com` thread 8745
is titled "[GAME FIX CODES] SLUS_014.11" and is the one source I could not read
— by its title it is patch codes, which is the most valuable class here, so it
is worth another attempt.

**Credit.** The codes are the work of **Police NYPD**, **roughnight**,
**hugopocked**, **StalkerX**, **00Kevin**, **Mantidactyle**, **M1CR0H4CK3R**,
**NightMare185** and **Legend of Dark** — those are the handles the archives
credit each code to. This decodes and cites their work; it does not
redistribute the archives.
