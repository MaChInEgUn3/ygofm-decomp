# Yu-Gi-Oh! Forbidden Memories — a clean-room description of the whole game

This is a specification of the game as it behaves, written so that someone —
or an agent — who has never played it can be handed "decompile the campaign"
and know what the campaign *is*: which screens it owns, what it reads from the
save, what it writes back, which shared systems it calls into, and where it
hands control to. Every screen and every mechanic is described, and every
section ends with the same block:

> **Entered from · Exits to · Persistent state read · Persistent state written
> · Shared systems used**

so the relationships are on the page next to the behaviour, not in an
introduction nobody scrolls back to.

**How to read the brackets.** A bracketed item like [`duelLoop` `0x8002CEE8`]
is something *located in `SLUS_014.11`* (NTSC-U) and measured there: an
address, a function, a table, a stride. Those are the parts an agent can grep
for. Everything else — the flow of the story, what a screen looks like, what a
card does — is the game as it plays, written from the game itself and from the
community's twenty years of documentation of it (the sources are listed at the
end). Where a sentence is a *reading* rather than a measurement it says so.
Nothing here is copied from a guide; the dialogue option labels quoted in
angle brackets are the game's own text.

**What this replaces.** An earlier version of this document was a research
note with code pointers. It also carried three errors that are corrected here
and called out where they appear: the rank table's category labels, the names
attached to the per-duelist drop blocks (which were off by one), and the seven
-rank list (there are ten).

---

## 1. The system in one page

The program is one loop that runs whichever **mode** is current [`mainLoop`
`0x8002DD74`, mode table `0x80090B64`, 17 entries]. A mode is a screen or a
whole activity; changing screen is changing the mode index [`0x80184594`, the
byte the debug-menu cheat writes]. The modes, in table order:

| slot | mode | what it is |
|---|---|---|
| 0 | `debugMenuLoop` [`0x8002CE08`] | developer menu (unreachable normally) |
| 1 | `animatedBattleLoop` [`0x8002D180`] | the 3-D battle cut-scene inside a duel |
| 2 | `campaignLoop` [`0x8002CE64`] | story dialogue scenes and scripted events |
| 3 | `duelLoop` [`0x8002CEE8`] | a duel, any kind |
| 4 | `libraryMenuLoop` [`0x8002D0E0`] | the card Library |
| 5 | `campaignOverworldLoop` [`0x8002D2D8`] | the campaign's location map |
| 6 | `freeDuelMenuLoop` [`0x8002D3F8`] | Free Duel opponent select |
| 7 | `buildDeckMenuLoop` [`0x8002D370`] | Build Deck |
| 8 | `mainMenuLoop` [`0x8002D588`] | title screen and both main menus |
| 9 | `nameEntryLoop` [`0x8002D62C`] | name entry for a new game |
| 10 | `passwordMenuLoop` [`0x8002D684`] | the Password shop |
| 11 | `optionsMenuLoop` [`0x8002D6C8`] | Options |
| 12 | `gameOverLoop` [`0x8002D730`] | campaign loss |
| 13 | `hirataLoop` [`0x8002D7C4`] | an eight-byte stub, a cut test duel |
| 14 | `tradeLoop` [`0x8002D7CC`] | Trade and 2P Duel setup |
| 15 | `creditsLoop` [`0x8002DA1C`] | the ending |
| 16 | slot 16 [`0x8002DC38`] | unnamed |

The names are the developers' own, recovered from an IDA database of this
binary; the addresses are measured here and every one matches.

**What persists.** Everything the player accumulates lives in one save block
[`0x801D0200` onward] and is written to the memory card as one file:

| what | where | shape |
|---|---|---|
| the deck | `0x801D0200` | 40 × u16 card ids |
| the trunk (chest) | `0x801D0250` | 722 bytes, one per card: copies owned |
| the **flag array** | `0x801D0618` | 256 bytes = 2048 one-bit flags, numbered 0–0x7FF, MSB first within each byte [tested by `func_8002CCA8`, set/cleared by `func_8002CCE4`]. Known ranges: `0x20`–`0x45` a per-duelist flag set together with the unlock (`0x1F + id`; reading: defeated in campaign — nothing that tests it was traced); `0x47`–`0x6F` the story's own flags, mapped one by one in §7.11; `0x121`–`0x3F2` card *seen* for the Library (`0x120 + card`); `0x401`–`0x6D2` password *already used* (`0x400 + card`, tested and set by the shop); `0x6E1`–`0x706` Free Duel *unlocked* (`0x6E0 + id`, bytes `0x801D06F4`–`0x801D06F8`). |
| duelist win/loss records | `0x801D0720` (= `0x801D0534 + 0x1EC`) | 39 × {u16 wins, u16 losses} |
| last cards dropped | `0x801D07BC` | 10 × u16 (UNVERIFIED, Data Crystal) |
| starchips | `0x801D07E0` | u32 |
| player name, duelist code | in the same block | (offsets not measured) |

Campaign progress — where the story is, which shrines are cleared, which
Millennium Items are held — is not a variable but **flags in that array**,
set and tested by the campaign's event script and by the dialogue texts
themselves (§7.10, §7.11).

**What is shared.** Four systems are used by more than one mode and are worth
knowing by name before reading any of them:

* the **card database** — 722 records of stats, type, level, guardian stars,
  password and cost [packed stats at `0x801D4244`, names at `0x801D6001`,
  levels at `0x801D5332`, passwords and costs on disc];
* the **duel engine** — the field, the hand, fusion/equip/ritual lookup, the
  battle resolver, the scoring counters [cards in play `0x801A7AD8`, 28-byte
  records; per-side record `0x800E9FF0`, stride `0x20`];
* the **AI interpreter** — a bytecode VM that runs each opponent's script
  [`aiMain` `0x80070650`, 67 handlers at `0x800916E0`, VM state `0x800F5BE8`];
* the **disc loader** — everything that is not in the executable comes in as
  sector ranges of `WA_MRG.MRG` through one request function
  [`func_80014E1C`] with a per-screen callback that routes the chunks (§12).

**How the modes connect** (arrows are the exits described in each section):

```
 boot ─► title/main menu ─► New Game ─► name entry ─► campaign
                         ├► Load ──────────────────► loaded menu ─┬► Campaign ─► overworld ◄─► dialogue scenes ◄─► duel ─► (win) back / (loss) game over
                         ├► 2P Duel ─► trade/2P setup ─► duel     ├► Free Duel ─► opponent select ─► duel ─► back
                         ├► Trade   ─► trade/2P setup             ├► Build Deck ─► back
                         └► Option  ─► options ─► back            ├► Library ─► back
                                                                  ├► Password ─► back
                                                                  └► Save ─► back
 campaign final duel won ─► ending ─► credits ─► (save prompt) ─► title
```

Every duel, whatever started it, runs in `duelLoop` and returns to whoever
started it; the 3-D battle animation is a sub-mode the duel enters and leaves.
The card shop inside the campaign is not a mode of its own: it is a dialogue
scene whose menu jumps into Build Deck, Save and the "loaded" main menu.

---

## 2. Boot, title and the two main menus

**Boot.** The console shows the licence screens, the game plays an intro movie
[`MOVIE.STR`; the random-number seed is set during the Konami logo and starts
advancing during the intro — UNVERIFIED, Data Crystal], and the title screen
appears. Pressing Start on the title opens the **initial menu**:

* **New Game** — start from nothing: goes to name entry (§2.1), then into the
  campaign's opening scene with a freshly generated starter deck (§4.3).
* **Load** — read a save from a memory card (§10), then show the loaded menu.
* **2P Duel** — a duel between two saves on two memory cards (§9.1).
* **Trade** — move cards between two saves (§9.2).
* **Option** — sound settings (§2.2).

Once a game is running — after New Game or Load — leaving the campaign's
card shop with "Return to Title" shows the **loaded menu** instead:

* **Campaign** — resume the story where it was (§7).
* **Free Duel** — pick any unlocked duelist and duel (§8).
* **Build Deck** (§4.1) · **Library** (§4.4) · **Password** (§4.5) · **Save**
  (§10).

The two menus are the same mode [`mainMenuLoop`]; which set is offered depends
on whether a game is loaded. The Data Crystal menu-ID list (UNVERIFIED) numbers
them 00 New Game, 01 Load, 02 2P Duel, 03 Trade, 04 Option, 05 Campaign, 06
Free Duel, 07 Build Deck, 08 Library, 09 Password, 0A Save, 0B Debug Menu —
which is why writing `0x0B` to the menu byte opens the developer menu.

> **Entered from:** boot; every other mode's "back". **Exits to:** name entry,
> campaign, Free Duel, Build Deck, Library, Password, trade/2P, options, save.
> **Reads:** whether a game is loaded; the save block after Load. **Writes:**
> nothing itself. **Uses:** memory-card I/O for Load; the disc loader for each
> screen's assets.

### 2.1 Name entry

A keyboard screen where the player types the save's name (the prince's name;
the game addresses him by it — "Prince ____" — and it is also the name shown
on the 2P Duel and Trade screens). Confirming goes straight into the
campaign's first scene. [`nameEntryLoop` `0x8002D62C`; scene text "Player's
Name" is Data Crystal scene 002.]

> **Entered from:** New Game. **Exits to:** campaign opening. **Reads:** —.
> **Writes:** the name in the save block; a new save block is initialised here
> or just before (starter deck, empty trunk apart from the deck, 0 starchips,
> no unlocks, no records). **Uses:** the starter-deck generator (§4.3).

### 2.2 Options

Sound output: mono or stereo. (The guides mention nothing else on this
screen; the mode's code reach is large only because it shares the menu
framework.) [`optionsMenuLoop` `0x8002D6C8`]

> **Entered from:** initial menu. **Exits to:** initial menu. **Reads/writes:**
> the sound setting (whether it is saved is not verified). **Uses:** the sound
> driver.

### 2.3 Memory-card dialogues

Every save, load, trade and 2P-duel path goes through the same card dialogue,
whose messages are the complete list of what can happen (Data Crystal scene
IDs 0BA–0DF, UNVERIFIED as IDs, the texts are the game's):

* prompts — `LOAD? YES NO`, `SAVE? YES NO`, `OVERWRITE? YES NO`, `FORMAT? NO
  YES`, `DOWNLOAD? YES NO`, `BACKUP DATA LOAD? START QUIT`;
* progress — `ACCESSING MEMORY CARD`, `LOADING...`, `SAVING...`,
  `DOWNLOADING...`, `NOW FORMATTING...`, `NOW TRADING CARD(S)`;
* results — `LOAD COMPLETE!`, `SAVE COMPLETE!`, `FORMAT COMPLETE!`,
  `DOWNLOAD COMPLETE!`, `TRADE COMPLETE!`, and the failures `LOAD
  INCOMPLETE!`, `SAVE INCOMPLETE!`, `DOWNLOAD INCOMPLETE!`, `FORMAT
  INCOMPLETE!`, `TRADE FAILED!`;
* conditions — `MEMORY CARD NOT PLUGGED!`, `MEMORY CARD REQUIRED!`, `MEMORY
  CARD NOT FORMATTED!`, `NOT ENOUGH FREE MEMORY BLOCKS!`, `UNABLE TO ACCESS
  MEMORY CARD!`, `UNABLE TO LOCATE LOAD DATA!`, `NO DATA!`, `ILLEGAL DATA!`,
  `MEMORY CARD slot 1 HAS BEEN REPLACED!`, `DO NOT PLUG/UNPLUG MEMORY CARD IN
  slot 1`.

A save takes one memory-card block.

---

## 3. The cards

There are **722** cards, numbered 1–722; the number is the card's identity
everywhere (deck, trunk, tables, passwords). By kind [counted from the card
table in the executable]:

| kind | count | ids |
|---|---|---|
| Monster | 621 | 1–300, 351–650, 701–720, 722 |
| Magic | 33 | 320, 329–350 (incl. the 6 field cards 330–335), 653, 655–656, 660–664, 669, 672 |
| Equip | 34 | 301–319, 321–328, 651–652, 654, 657–659, 668 |
| Ritual | 24 | 665–667, 670–671, 673–680, 691–700, 721 |
| Trap | 10 | 681–690 |

Non-monster ids sit in three runs, 301–350, 651–700 and 721 — a fact that
matters to anyone scanning a table for "equip keys": they are not all below
350. Card 721 is Dark Magic Ritual and 722 is Magician of Black Chaos, the two
added over the Game Boy predecessor's 720. There is also an unusable story
card, the Millennium Card, that is not one of the 722.

**A monster** has ATK and DEF (0–5000, stored in tens), a level (1–12 stars),
a **type** — one of twenty: Dragon, Spellcaster, Zombie, Warrior, Beast-
Warrior, Beast, Winged Beast, Fiend, Fairy, Insect, Dinosaur, Reptile, Fish,
Sea Serpent, Machine, Thunder, Aqua, Pyro, Rock, Plant [type ids 0–19 in that
order; Magic/Trap/Ritual/Equip are 20–23 in the same field] — and **two
guardian stars**. The stats are one packed word per card [`0x801D4244`: ATK
bits 0–8 ×10, DEF bits 9–17 ×10, second star bits 18–21, first star bits
22–25, type bits 26–30]. There is no attribute/element in this game.

**Guardian stars** are ten, in two cycles that never touch:

* Mars → Jupiter → Saturn → Uranus → Pluto → Neptune → Mars (six);
* Mercury → Sun → Moon → Venus → Mercury (four).

"A → B" means A is strong against B. A monster's two stars are whatever its
card lists — 181 of the 621 monsters have both stars in the same cycle, the
rest one in each.
The bonus is decided at battle time (§5.8) [`0x8002CB80`: +500 if the
attacker's star immediately precedes the defender's in its cycle, −500 if it
immediately follows, 0 otherwise or across cycles].

**Passwords and starchip costs.** Every card has an eight-digit password
(the number printed on the real card) and a cost in starchips, from 5 up to
999,999 [on disc: `WA_MRG.MRG` @ `0xFB9808`, u32 cost + 4-byte reversed BCD
password, 722 records]. The 999,999 cards are the ones the Japanese version
obtained through the PocketStation lottery; in the NTSC-U release they can
only be dropped or traded, and 24 of them carry a sentinel password.

**Names** are stored as a custom-encoded, 0xFF-delimited blob
[`0x801D6001`]; the picture and the flavour text come from the disc.

> **Used by:** every mode. **Written by:** nothing — the card database is
> read-only; what changes is the trunk (§4.2).

---

## 4. Your cards: trunk, deck, Library, Password

### 4.1 Build Deck

Two lists side by side: the **trunk** (everything you own, left) and the
**deck** (right). Moving the cursor onto a card and pressing × moves one copy
across; ○ leaves the screen. △ shows the card's full detail. L1/R1 jump ten
cards, L2/R2 jump a hundred. Start or Select cycles the sort order, shown as
icons along the top; the orders are, left to right: by number, by name, by
ATK+DEF, by ATK, by DEF, by type, and by most recently acquired — and the deck
side has one extra, the game's own "as dealt" order.

Rules the screen enforces:

* the deck must hold **exactly 40** cards to be usable — leaving with fewer
  is allowed, but every mode that starts a duel refuses (`YOUR DECK ISN'T
  READY!`, `YOU MUST PREPARE A DECK TO PLAY THE CAMPAIGN MODE!`, and for the
  second player `1P'S DECK IS NOT READY`);
* at most **3 copies** of one card, and at most **1** of each of the five
  Exodia pieces [both limits are immediates in the executable — the hacking
  community's "card limit" patch changes the 3 at file offset `0x24070` and
  the Exodia 1 at `0x24020`];
* you can only put in what the trunk holds; a card in the deck is not in the
  trunk count shown.

The campaign's card shop opens this same screen. [`buildDeckMenuLoop`
`0x8002D370`]

> **Entered from:** loaded menu; card shop. **Exits to:** whoever opened it.
> **Reads:** trunk, deck, card database. **Writes:** deck and trunk counts.
> **Uses:** card database, disc loader (card pictures).

### 4.2 The trunk

One byte per card [`0x801D0250`, 722 bytes]: the number of copies owned.
(The Library's "seen" test reads flag `0x120 + card` in the save's flag
array, §1, not this byte; whether the byte also carries a bit was not
checked.) Cards move in
through duel drops, passwords and trades; they move out only through trades
(nothing in the game destroys a card permanently — a "temporary" card seen
in a duel, §4.4 and §5.4, is never in the trunk at all).

### 4.3 The starter deck

A new game deals **40 random cards** from seven pools, by ATK+DEF band: 16
monsters below 1100, 16 from 1100 to 1599, 4 from 1600 to 2099, 1 of 2100 or
more, plus **one magic card, one field card and one equip** — so every
starter has a Raigeki or a Dark Hole, one terrain, and one equip. The game's
own generator works from pointer tables of card groups [Data Crystal's ROM
map names the routine and its group tables; UNVERIFIED here]. Resetting until
the magic card is Raigeki is the community's standard opening.

### 4.4 Library

A catalogue of all 722 cards in number order. A card you have **seen** shows
its picture, name, type, level, guardian stars, ATK/DEF and text, and its
password; a card you have not is an unknown entry. "Seen" is set by owning
the card and also by having it appear in a duel — a fusion result or a ritual
summon you made counts, and those show with a semi-transparent icon because
you saw them without owning them [the mark is flag `0x120 + card` in the
flag array, set by `func_8002BF3C` and by the shop on purchase]. The
completion figure counts both. From a
card's page, pressing right or × shows the card in **3-D**, rotating [a cheat
freezes the rotation by writing `0x800F284A`]. [`libraryMenuLoop`
`0x8002D0E0`; the "have you seen it" test that decides whether a card is
displayed is the branch at `0x8002C320` inside `0x8002BFCC`, which the
"all cards in Library" cheat deletes.]

> **Entered from:** loaded menu. **Exits to:** loaded menu. **Reads:** trunk
> bytes (count + seen flag), card database. **Writes:** nothing. **Uses:** card
> database, disc loader (pictures, 3-D model).

### 4.5 Password

The shop. The screen shows your starchips (`STARCHIP ×N`) and asks
`Please enter 'PASSWORD'`: type a card's eight digits. If the number is a real card's password, its cost is
shown; confirming deducts the starchips and puts one copy in the trunk.
Three rules:

* a card can be bought **once** — a second entry of the same password is
  refused [the shop tests flag `0x400 + card` and, on purchase, sets it
  "used" and `0x120 + card` "seen" in the flag array; the
  "buy again" cheat patches the test's branch at `0x8016A6E0`, and the
  "unlimited passwords" cheat zeroes exactly the bytes those flags occupy,
  `0x801D0698`–`0x801D06F3`];
* you must be able to afford it; the cost is deducted [the subtraction is
  `subu $v1, $v1, $s0` at `0x8016A87C` in that overlay];
* the bought card is delivered when you leave the screen [the "arrive
  immediately" cheat removes the branch at `0x8016A880`].

Costs run from 10 starchips (the cheapest cards) to 999,999 for the lottery cards;
a starchip is earned only by winning duels (§6.3), 1–5 per win, so a 999,999
card is not a realistic purchase — the cost exists to say "obtain this some
other way". The password-use counter in the save [`0x801D0534 + 0x164`] is
what the "unlimited passwords" cheat zeroes. [`passwordMenuLoop`
`0x8002D684`; the executable's own part of the flow is `0x80038BF0`, where
`$a2` carries the star cost.]

> **Entered from:** loaded menu. **Exits to:** loaded menu. **Reads:**
> starchips, trunk, password/cost table (disc). **Writes:** starchips, trunk,
> the password-use record. **Uses:** card database, the password-shop overlay
> loaded from disc (§12).

---

## 5. The duel

Every duel — campaign, Free Duel, two-player — is the same engine
[`duelLoop` `0x8002CEE8`] with the same rules. This section is the rules in
full, in the order things happen.

### 5.1 Setup

* Each side has **8000 life points** [player LP at `0x800EA004`, opponent
  `0x800EA024`; each side's record is 32 bytes, `0x800E9FF0 + side * 0x20`,
  and carries the on-screen ticking figure two bytes below the true value].
* Each side's 40-card deck is shuffled [permutation tables at `0x80177F94`
  (player) and `0x80177FBC` (CPU), the shuffled decks at `0x80177FE8` /
  `0x80178038` — UNVERIFIED, Data Crystal] and each draws five.
* The **player always moves first** against the computer.
* The terrain starts as **normal** unless the opponent is fought on a home
  terrain: Sebek and Neku are fought on Yami (sourced); the five shrine
  mages on their shrine's field and the finale on Yami (readings from the
  guides' strategy notes, not stated outright). The terrain byte is also what
  selects which of the seven disc copies of the duel data is loaded (§12)
  [`0x8009B364`].
* A duel that is entered with an incomplete deck never starts (§4.1).

The field is two rows of five per side: a **monster row** (up to five
monsters) and a **magic/trap row** (up to five magic, trap, ritual or equip
cards) [cards in play are one array of 28-byte records at `0x801A7AD8`:
player records 0–9, opponent 20–29, ATK at +0xE, DEF at +0x10, so the second
monster is 28 bytes after the first]. The player's hand is five slots
[`0x801A7E20`, UNVERIFIED].

### 5.2 A turn

1. **Draw** up to five cards. If the deck is empty when a draw is due, that
   player has **lost** (§5.10).
2. **Play exactly one card** — or one *combination* — from the hand (§5.3).
   One card must be placed every turn, even onto a full field (it then lands
   on a card already there, §5.4); the way to "pass" is to play something
   face-down in defence.
3. **Battle**: any monster in attack position may attack once (§5.8); attack
   positions may be changed, magic cards on the field activated, rituals
   attempted, in any order, until Start ends the turn.
4. **End of turn** (Start). Timed effects tick down; the AI takes its turn
   (§5.11).

There is no tribute/level requirement to play any monster, no summoning
sickness — a monster played this turn may attack this turn [reading from
play; not traced in code] — and no limit on how many cards may sit in the
magic/trap row beyond the five zones.

### 5.3 Playing cards from the hand

Move the cursor over the hand; **up** on the d-pad raises a card and gives it
a number (1, 2, 3…) — the order in which the raised cards will be combined.
× confirms. With one card raised it is simply played; with several, the game
**combines them in order** (§5.4). L2/R2 show the field before choosing.

Then the placement choices, in order:

* which **zone** — an empty zone of the right row, or **on top of a card
  already on your field** (which is another way to combine: the played card
  is fused with, equipped to, or replaces the one it lands on);
* **face-up or face-down**;
* **attack or defence** position (L1/R1 toggle; attack is upright, defence is
  sideways);
* for a monster, **which of its two guardian stars** to use for as long as it
  stays on the field.

A face-down monster is hidden from the opponent (except from Pegasus, whose
script reads your hand and field; §5.11). A face-down magic/trap card stays
hidden until it activates.

### 5.4 Combining cards — fusion, equip, and failure

When two cards meet — two raised in the hand, or one played onto the field —
the game tries, in this order:

1. **Fusion.** The pair is looked up in the **fusion table**
   [`checkFusion` `func_80019A60`, table at `0x8017C2D8`, 64 KB, indexed by
   the *smaller* id: a `u16 offset[723]` then packed 5-byte records holding
   two (partner, result) pairs each]. If a recipe exists, the two become the
   result card, face-up, with the result's stats. **25,131 recipes** exist,
   producing 204 distinct results. Some are specific (Thunder Dragon +
   Thunder Dragon → Twin-headed Thunder Dragon); most are by type and
   strength (any Dragon with a Thunder monster → Twin-headed Thunder Dragon;
   Time Wizard with any Dragon → Thousand Dragon), which is why the same few
   results — Nekogal #2 (1,200 recipes lead to it), Mystical Sand (1,174),
   Cyber Soldier (1,008) — keep appearing when a beginner fuses at random.
2. **Equip.** If one card is an equip and the other a monster, the **equip
   table** is consulted [`checkEquip` `func_80019A08`, table at
   `0x8017A1D8`: for each of the 34 equips, the list of monsters it fits —
   4,041 pairs in all; Megamorph fits 621 monsters, Legendary Sword 63]. A
   valid equip raises the monster's ATK and DEF by 500 per level of the
   equip (most are one level, Megamorph two, so +500 or +1000), permanently
   for that monster. The equip card is consumed.
3. **Ritual** (§5.7) is not a combination: it is activated from the field.
4. **Failure.** If neither applies: when only one of the two is a monster,
   the monster stays and the other card is discarded; when both are monsters
   (or neither), the card played **first** is discarded and the second
   remains. So a failed two-monster fusion costs you the first card, and a
   wasted equip costs the equip.

A chain of three or more raised cards is processed pairwise: first two, then
the result with the third, and so on — each step can succeed or fail by the
same rules, and the survivor of the whole chain is what gets placed.
Combining on the field (playing onto a monster) follows the same table but
the result keeps the field zone, position choices are asked again, and — for
scoring — it counts as a *field* fusion rather than an initiated one (§6.1).

**Playing a non-monster onto your own monster** with no valid equip/fusion is
how a magic card is wasted; **playing a monster onto your magic/trap row** is
not allowed — the zone choice only offers legal rows.

### 5.5 Magic cards

Magic cards are played into the magic/trap row (face-up or face-down) and
**activated** later from there by selecting them, on your turn. The game does
not read the card's text; it reads its **number**: a placement state machine
[`func_80019608`] hands the id to a guard [`func_80026BA4`] that accepts
301–350, 651–700 and 721, converts it to an index, and a per-tick dispatcher
[`func_80026B34`] looks that index up in a 104-byte table [`0x80090AD4`] to
get an **effect group**, 0–13, and calls the group's handler pair from a
30-entry table [`0x80090A5C`]. So every spell is one of fourteen behaviours,
and which cards share a behaviour is data:

| group | cards | effect |
|---|---|---|
| 0 | all 34 equips and all 10 traps | nothing at play time — equips resolve when attached, traps when triggered |
| 1 | Forest, Wasteland, Mountain, Sogen, Umi, Yami | sets the **terrain** for both sides and recomputes every monster's bonus (§5.6) |
| 2 | Mooyan Curry, Red Medicine, Goblin's Secret Remedy, Soul of the Pure, Dian Keto the Cure Master | restores your LP by 200 / 500 / 1000 / 2000 / 5000 (per-card parameter) |
| 3 | Sparks, Hinotama, Final Flame, Ookazi, Tremendous Fire | deals 50 / 100 / 200 / 500 / 1000 damage to the opponent's LP |
| 4 | Dark Hole, Dragon Capture Jar | one handler that walks every monster on the field (as read); Dark Hole's own text says it "sucks up every card in play", Dragon Capture Jar (special-cased by id) takes the opponent's Dragons |
| 5 | Warrior Elimination, Eternal Rest, Stain Storm, Eradicating Aerosol, Breath of Light, Eternal Draught, Crush Card | destroys the opponent's monsters selected by a per-card parameter: Warriors, Zombies, Machines, Insects, Rocks, Fish respectively — and Crush Card takes every opposing monster with **ATK ≥ 1500** (its parameter is a threshold, not a type) |
| 6 | Stop Defense | flips one opposing defending monster to attack position |
| 7 | Raigeki | destroys every monster on the opponent's field |
| 8 | Dark-piercing Light | reveals the opponent's face-down monsters |
| 9 | Spellbinding Circle, Shadow Spell | lowers **all** opposing monsters by one level (−500) / two levels (−1000), on a timer |
| 10 | Swords of Revealing Light | reveals the opponent's field and stops their monsters attacking for three turns |
| 11 | Cursebreaker | cancels every level reduction on your monsters (undoes Spellbinding Circle / Shadow Spell) |
| 12 | all 24 rituals | validates the tributes and performs the summon (§5.7) |
| 13 | Harpie's Feather Duster | destroys every magic/trap card the opponent has in play |

Groups 6, 7, 8, 10, 11 and 13 share one animated zone-by-zone scan, which is
why they play out visibly one slot at a time. A magic card that has nothing
to act on is simply consumed.

### 5.6 Terrain

The field has one terrain for both sides — normal, or one of **Forest,
Wasteland, Mountain, Sogen (meadow), Umi (sea), Yami (dark)** [`0x8009B364`,
values 0–6 in that order]. Playing a field card replaces the terrain; it
stays until replaced. Each monster **type** is helped or hurt by each
terrain by exactly **±500**, looked up per type per terrain
[`getTerrainBoost` `func_8002497C`, an `s8[20][6]` at `0x800909D4` × 10].
The whole table, read from the executable:

| type | Forest | Wasteland | Mountain | Sogen | Umi | Yami |
|---|---|---|---|---|---|---|
| Dragon | · | · | +500 | · | · | · |
| Spellcaster | · | · | · | · | · | +500 |
| Zombie | · | +500 | · | · | · | · |
| Warrior | · | · | · | +500 | · | · |
| Beast-Warrior | +500 | · | · | +500 | · | · |
| Beast | +500 | · | · | · | · | · |
| Winged Beast | · | · | +500 | · | · | · |
| Fiend | · | · | · | · | · | +500 |
| Fairy | · | · | · | · | · | −500 |
| Insect | +500 | · | · | · | · | · |
| Dinosaur | · | +500 | · | · | · | · |
| Reptile | · | · | · | · | · | · |
| Fish | · | · | · | · | +500 | · |
| Sea Serpent | · | · | · | · | +500 | · |
| Machine | · | · | · | · | −500 | · |
| Thunder | · | · | +500 | · | +500 | · |
| Aqua | · | · | · | · | +500 | · |
| Pyro | · | · | · | · | −500 | · |
| Rock | · | +500 | · | · | · | · |
| Plant | +500 | · | · | · | · | · |

Reptile is the one type no terrain touches. The bonus is applied to the
monster's displayed ATK/DEF while the terrain holds and removed when it
changes; it stacks with equips and the guardian-star bonus.

### 5.7 Traps and rituals

**Traps** (ten cards, ids 681–690) are set face-down in the magic/trap row
and fire by themselves on the opponent's action; the player never chooses
when. Their triggers, from the cards' own text:

| trap | fires when… | effect |
|---|---|---|
| House of Adhesive Tape | an opposing monster with ATK ≤ 500 attacks | attacker destroyed |
| Eatgaboon | … ATK ≤ 1000 attacks | attacker destroyed |
| Bear Trap | … ATK ≤ 1500 attacks | attacker destroyed |
| Invisible Wire | … ATK ≤ 2000 attacks | attacker destroyed |
| Acid Trap Hole | … ATK ≤ 3000 attacks | attacker destroyed |
| Widespread Ruin | any opposing monster attacks | attacker destroyed |
| Goblin Fan | the opponent plays a direct-damage magic (Sparks … Tremendous Fire) | the damage is reflected onto them |
| Bad Reaction to Simochi | the opponent plays an LP-recovery magic | the recovery becomes damage |
| Reverse Trap | the opponent plays a power-up | the power-up becomes a power-down |
| Fake Trap | it is attacked or targeted | nothing — a decoy that absorbs the opponent's trap-removal |

The six "attacker destroyed" traps only fire on an attack whose ATK is within
the limit; a stronger attacker is unaffected and the trap stays. One trap
fires per attack, and once fired it is gone.

**Rituals** (24 cards) are played to the magic/trap row and **activated**: if
the three specific monsters the ritual names are face-up on your field, they
are removed and the ritual monster is summoned in their place; otherwise the
card is consumed with no effect [`checkRitual` `func_8002C7E8`, table at
`0x801799D8`: 24 records of {ritual, tribute, tribute, tribute, result}].
The full list is on the disc and is decoded by the extractor (§12.2); three
examples:
Black Luster Ritual = Beaver Warrior + Gaia the Fierce Knight + Kuriboh →
Black Luster Soldier; Ultimate Dragon = three Blue-eyes White Dragon →
Blue-eyes Ultimate Dragon; Gate Guardian Ritual = Sanga of the Thunder +
Kazejin + Suijin → Gate Guardian. Dark Magic Ritual (721) is the 24th and
makes Magician of Black Chaos (722).

### 5.8 Battle

An attack-position monster attacks one target on the opponent's field, or —
**if the opponent has no monsters at all — attacks directly**, and the
attacker's full ATK is taken from the opponent's LP. Before comparing stats
the game applies, in this order, the terrain bonus (already in the displayed
stats), any equip (already in the stats), and the **guardian-star bonus**:
if the attacker's star is strong against the defender's, the attacker gets
**+500 ATK and DEF for this battle**; if the defender's star is strong
against the attacker's, the defender gets it [`0x8002CB80`; the label under
the card reads yellow for advantage, red for disadvantage]. Then:

* **against an attack-position monster** — the higher ATK wins; the loser is
  destroyed and the *difference* is taken from its owner's LP; equal ATK
  destroys both, no damage;
* **against a defence-position monster** — attacker's ATK against defender's
  DEF; if ATK is higher the defender is destroyed and nobody loses LP; if ATK
  is lower the attacker survives and the difference is taken from the
  *attacker's* LP; equal, nothing happens;
* a **face-down** defender is flipped by the attack and resolved as above;
  its identity and stars are revealed.

Pressing □ instead of × on the attack plays the battle as a **3-D
animation** [`animatedBattleLoop` `0x8002D180`] — cosmetic; the result is the
same. A monster that has attacked cannot change position again that turn.
Each monster attacks at most once per turn.

### 5.9 The 3-D battle and the "Poly Mode"

The animation mode loads the two monsters' models, plays the attack, and
returns to the duel [`0x8002D180`; a separate 3-D player is used for the
Library viewer and for the finale's Poly Mode duels]. It reads nothing but
the two combatants and writes nothing.

### 5.10 Winning and losing

A duel ends the moment one of these holds, checked after every action:

* a side's **LP reaches 0** — the message is `TOTAL ANNIHILATION`;
* a side **cannot draw** at the start of its turn — the other side wins by
  `VICTORY BY ATTRITION` (the deck-out; this is the route to the TEC ranks,
  §6.2);
* a side holds **all five Exodia pieces in its hand** — instant win,
  `SUMMON Exodia` [the check exists in the executable; the community's
  "disable Exodia" patch flips two bytes at file offsets `0x952C`/`0x959C`].

Start during a duel offers `QUIT DUEL? NO YES`; what quitting counts as is
not verified (§13). What a win or a loss *means* is decided by the
caller (§6, §7.12, §8).

### 5.11 The opponent

The computer's turn is played by a **bytecode script** per opponent,
interpreted by a small VM [`aiMain` `0x80070650`]: the loop fetches an opcode,
dispatches through a **67-entry handler table** [`0x800916E0`], and stops
when the handler it just ran was one of three terminal ones (end of hand
phase, end of field phase, field play); every sixteenth of a second it yields
to the video sync. The instruction set is real: `aiInstJump`, `aiInstJumpGe`,
`aiInstJumpEq`, `aiInstJumpNeq`, `aiInstJumpRand`, `aiInstCall`,
`aiInstRetn`, `aiInstRand`, `aiInstSub`, `aiInstStrongest`,
`aiInstBestCombo`, `aiInstFindFirst`… [VM state `0x800F5BE8`; the script
area is `0x801A8000`, which the duel loader fills with a 6 KB chunk of the
per-terrain disc blob — that the chunk *is* the script is a reading; the
source file the VM's asserts name is `src/hirata/H_mctrl1.c`]. What the
scripts *do*, as observed by every guide since 1999:

* the opponent fuses aggressively from its hand and with its field, and
  fuses **more** when you open with a face-down card or a face-down
  magic/trap — the standard TEC-farming trick is to open face-down so the
  opponent burns cards fusing;
* it changes the terrain back to its home terrain whenever you change it
  (the five High Mages);
* Pegasus's script reads your face-down cards, so hiding is useless against
  him;
* Duel Master K's script plays a **copy of your own deck** (§8);
* the scripts differ per duelist in aggression and in what they fuse for,
  and each opponent's deck is drawn from a per-duelist **weight table**
  rather than being a fixed 40 (§6.4).

> **Entered from:** campaign scenes, Free Duel select, 2P setup, the debug
> menu. **Exits to:** the caller, with win/loss and the scoring counters
> filled. **Reads:** both decks, the opponent id [`0x8009B361`], the terrain
> [`0x8009B364`], the rule tables (fusion, equip, ritual, terrain), the AI
> script. **Writes:** the per-side records, the cards-in-play array, the
> statistics record that scoring reads (§6.1); nothing persistent — the
> trunk and starchips are touched by the *caller* after the duel. **Uses:**
> the duel engine, the AI VM, the card database, the 3-D battle mode, the
> disc loader (the per-terrain blob and the per-duelist block, §12).

### 5.12 Controls (duel)

| button | in the duel |
|---|---|
| × | select / confirm |
| □ | confirm an attack with the 3-D animation |
| ○ | cancel / back |
| △ | card details |
| L1 / R1 | toggle attack/defence position |
| L2 / R2 | view the field before playing |
| d-pad up | raise a hand card into the combination order |
| Start | end turn; quit-duel prompt |

---

## 6. After a duel: score, rank, starchips, the dropped card

What happens after a duel is decided by whoever started it (campaign §7,
Free Duel §8, two-player §9). Against the computer in either single-player
mode the sequence is always: **score → rank → starchips → one card**, then
the win/loss record and the unlock bit.

### 6.1 The score

During the duel the engine keeps a **statistics record** per side [it is the
per-side record at `0x800E9FF0 + side * 0x20`: the counters are bytes at
+1…+9 and +0x18, the LP the halfword at +0x14 — the player's `0x800EA004`
cited everywhere — so "cards used" is the byte at `0x800EA008`, which is
exactly the address a long-dismissed GameShark code labels "cards used by
you"]. At the end [`calcRankScore` `func_80021598`] the score starts at
**50**, a signed byte at the record's +0 is added to it directly (this is
where the way-the-duel-ended adjustment enters), and each counter is run
through one row of a **ten-row table** [`rankScoreChange`
`func_80021558`; the table is 200 bytes at `0x801798A8`, loaded from the
per-duelist disc block and identical for all 39 duelists]: a row is five
(threshold, value) pairs walked upward, and the first threshold above the
counter supplies the value added to the score. The rows, measured:

| row | counter (record offset) | value by count | category |
|---|---|---|---|
| 0 | +0x01 | 0–4: +12 · 5–8: +8 · 9–28: 0 · 29–32: −8 · 33+: −12 | **turns** taken |
| 1 | +0x02 | 0–1: +4 · 2–3: +2 · 4–9: 0 · 10–19: −2 · 20+: −4 | **effective attacks** (attacks that destroyed an attack-position monster and dealt damage) |
| 2 | +0x03 | 0–1: 0 · 2–5: −10 · 6–9: −20 · 10–14: −30 · 15+: −40 | **defensive wins** (your defender survived an attack) |
| 3 | +0x04 | 0: 0 · 1–10: −2 · 11–20: −4 · 21–30: −6 · 31+: −8 | **face-down plays** |
| 4 | +0x05 | 0: +2 · 1–3: −4 · 4–6: −8 · 7–9: −12 · 10+: −16 | **pure magic** cards used |
| 5 | +0x06 | 0: +2 · 1–2: −8 · 3–4: −16 · 5–6: −24 · 7+: −32 | **traps** triggered |
| 6 | +0x18 | 0–8: +15 · 9–12: +12 · 13–32: 0 · 33–36: −5 · 37+: −7 | **cards used** |
| 7 | +0x14 (halfword) | 0–99: −7 · 100–999: −5 · 1000–6999: 0 · 7000–7999: +4 · 8000: +6 | **remaining LP** |
| 8 | +0x08 | 0: +4 · 1–4: 0 · 5–9: −4 · 10–14: −8 · 15+: −12 | fusions initiated from the hand |
| 9 | +0x09 | same as row 8 | equips used |

The +0 byte is the **way the duel ended**: +2 for taking the LP to 0, −40
for a deck-out, +40 for Exodia (that it is added is measured; the three
values are the community's). The thresholds, values and the counter each row reads are measured;
the *names* of the categories are the community's, matched row for row to
the published rank guide — and this corrects the earlier version of this
document, which had rows 4, 5, 8 and 9 labelled as fusions, equips, magic
and traps in the wrong order. Which of rows 8 and 9 is fusions and which is
equips is not settled (their values are identical, so the score does not
care).

### 6.2 The rank

The score picks one of **ten ranks** [`func_800218F0`, right after the
score: a score below 50 sets the TEC flag and is mirrored as 99 − score;
anything at 100 or above is clamped to 99; then (score − 50) / 10 selects the
letter]:

| score | 90+ | 80–89 | 70–79 | 60–69 | 50–59 | 40–49 | 30–39 | 20–29 | 10–19 | ≤9 |
|---|---|---|---|---|---|---|---|---|---|---|
| rank | S-POW | A-POW | B-POW | C-POW | D-POW | D-TEC | C-TEC | B-TEC | A-TEC | S-TEC |
| starchips | 5 | 4 | 3 | 2 | 1 | 1 | 2 | 3 | 4 | 5 |
| drop pool | POW | POW | BCD | BCD | BCD | BCD | BCD | BCD | TEC | TEC |

**POW** is a fast, clean win: few turns, few tricks, full LP. **TEC** is the
opposite — win slowly, use magic and traps, or deck the opponent out (a
deck-out alone is −40, and "have fewer than 28 cards left plus one wasteful
act" is the community's recipe for a B/C/D). The theoretical range is −140 to
+139. The earlier version of this document listed seven ranks; there are ten.

### 6.3 Starchips

Added to the save's counter [`0x801D07E0`, u32] by the table above: 1 to 5
per win, symmetric, so an S of either kind pays 5. They are spent only in the
Password shop (§4.5). Losing costs nothing.

### 6.4 The dropped card

One card is drawn from the beaten duelist's **pool for that rank group**
[`cardDrop` `func_80021810`: roll `(rand & 0x7FF) + 1`, i.e. 1–2048, then
walk the pool's 722 u16 weights accumulating until the sum reaches the roll;
the index reached is the card]. Every pool's weights **sum to exactly 2048**,
so a card's weight is its chance out of 2048 — the "a 20" and "a 32" the
speedrunners talk about. The three pools per duelist are the per-duelist disc
block's tables at +0x5B4 (POW), +0xB68 (BCD) and +0x111C (TEC) [runtime
copies `0x8017878C`, `0x80178D40`, `0x801792F4`], and the fourth table in
that block at +0 is the opponent's **deck weights** — the deck the AI plays is
itself drawn from a weighted pool, not fixed (§5.11). The card is added to
the trunk and marked seen.

**Which block is which duelist** was settled by matching every block's pools
against an independent list of what each duelist has been recorded dropping
(the Neoseeker guide's "cards won" lists, 3,000 card entries): every duelist
matches one block at 92–100 %, and the order is the opponent id
[`0x8009B361`], **1-based**:

| id | duelist | id | duelist | id | duelist |
|---|---|---|---|---|---|
| 0 | (unused; a copy of 1) | 13 | Shadi | 26 | High Mage Atenza |
| **39** | **Duel Master K** | | | | |
| 1 | Simon Muran | 14 | Yami Bakura | 27 | Desert Mage |
| 2 | Teana | 15 | Pegasus | 28 | High Mage Martis |
| 3 | Jono | 16 | Isis | 29 | Meadow Mage |
| 4 | Villager 1 | 17 | Kaiba | 30 | High Mage Kepura |
| 5 | Villager 2 | 18 | Mage Soldier | 31 | Labyrinth Mage |
| 6 | Villager 3 | 19 | Jono 2nd | 32 | Seto 2nd |
| 7 | Seto | 20 | Teana 2nd | 33 | Guardian Sebek |
| 8 | Heishin | 21 | Ocean Mage | 34 | Guardian Neku |
| 9 | Rex Raptor | 22 | High Mage Secmeton | 35 | Heishin 2nd |
| 10 | Weevil Underwood | 23 | Forest Mage | 36 | Seto 3rd |
| 11 | Mai Valentine | 24 | High Mage Anubisius | 37 | **DarkNite** |
| 12 | Bandit Keith | 25 | Mountain Mage | 38 | **Nitemare** |

Two things fall out of that table on their own. Blocks 8 and 35 —
Heishin's first and second duels — share the same three drop pools and rank
table but carry different deck weights. And **Duel Master K is block 39**:
its three drop pools are byte-identical to Villager 3's (which is why the
community's list of what he drops matches Villager 3's block at 100 %), and
its stored deck is a placeholder identical to Simon Muran's, because his
script plays a copy of the player's deck instead (§8). It also corrects the
earlier version of this document, which named the blocks by the GameShark
record order and was off by one from Teana onward — and it means the two
**GameShark win/loss labels for Nitemare and DarkNite are probably swapped**
(their records at `0x801D0720 + 4·(id − 1)` would put DarkNite at 36 and
Nitemare at 37, the archives publish the reverse). The bound for those two:
the block order is measured, the record order is the archives' claim.

### 6.5 Records and unlocks

After a single-player duel the caller updates the beaten (or beating)
duelist's **win/loss record** [`0x801D0720`, 39 × {u16 wins, u16 losses}]
and, in the campaign, sets the duelist's **Free Duel unlock bit**
[`0x801D06F4`]. Free Duel shows the record as `WIN n LOSS n` on its select
screen. A duel lost in Free Duel records a loss and nothing else happens; a
duel lost in the campaign is game over (§7.12), except the one scripted loss.

> **This stage — entered from:** the duel's exit, by its caller. **Reads:**
> the statistics record, the rank table and drop pools (disc block), the RNG.
> **Writes:** starchips, trunk (+ seen), records, unlock mask — all in the
> save block, not yet on the memory card until the player saves. **Uses:** the
> RNG [`0x8008E590`], the card database.

---

## 7. The campaign

The story mode is two modes working together — **dialogue scenes**
[`campaignLoop` `0x8002CE64`] and the **location map** [`campaignOverworldLoop`
`0x8002D2D8`] — that call into the duel for every fight and into the shared
menus for every shop. It is strictly linear with one branch (§7.6) and one
point of no return (§7.8). Losing any campaign duel is **game over** except
the one scripted loss (§7.12).

**How a campaign screen works.** A location shows a picture, the characters
present, and a dialogue with the current speaker; when the player has a
choice, a small menu of options appears (quoted below as `<Option>`). Duels
are always offered as `<Duel>` / `<Pass>` (or `<Decline>`); most story duels
cannot be refused — refusing simply repeats the prompt. Between scenes the
**map** shows the reachable locations; ○ backs out of a location to the map.
Every location that has a **card shop** offers the same four-entry menu:
`Save` (memory card), `Build Deck` (§4.1), `Return to Title` (the loaded main
menu — the way to reach Free Duel, Library and Password from inside the
story), and `Leave Shop` (back to the story). This is the *only* place the
campaign lets you save, which is why the guides say "save at every shop".

### 7.1 The duelists, in order

Thirty-nine opponents exist [the opponent id byte `0x8009B361`, 1–38 in the
campaign order below, plus Duel Master K who is Free-Duel-only]. "Forced"
means the story does not proceed until the duel is won; "optional" duels can
be declined and repeated. Every duelist **defeated** in the campaign becomes
available in Free Duel (§8), with two exceptions noted.

| id | duelist | where | forced? | notes |
|---|---|---|---|---|
| 1 | Simon Muran | Pharaoh's Palace (Egypt I) | optional | your tutor; challenges you when you return to the palace before the dueling grounds |
| 2 | Teana | Duel Ground (Egypt I) | optional | also at the hidden grounds later as Teana 2nd |
| 3 | Jono | Duel Ground, after the festival | optional | |
| 4 | Villager 1 | Duel Ground | optional | present before and after the tournament |
| 5 | Villager 2 | Duel Ground | optional | present before and after |
| 6 | Villager 3 | Duel Ground | optional | **only before the festival** — one of the two duelists you can miss for Free Duel (the other is Seto 2nd); Duel Master K's drop pools are a copy of his (§6.4) |
| 7 | Seto | Duel Ground, after the festival | forced | the first real challenge |
| 8 | Heishin | Palace, after Seto | forced **loss** | the only duel you must lose; winning it repeats it, and beating him even once unlocks him for Free Duel |
| 9 | Rex Raptor | KaibaCorp tournament, preliminaries | forced | |
| 10 | Weevil Underwood | preliminaries | forced | |
| 11 | Mai Valentine | preliminaries | forced | |
| 12 | Bandit Keith | preliminaries | forced | |
| 13 | Shadi | finals | forced | gives the Millennium Key and Scales |
| 14 | Yami Bakura | finals | forced | Millennium Ring |
| 15 | Pegasus | finals (quarter-final) | forced | Millennium Eye; reads your face-downs |
| 16 | Isis | semi-final | forced | Millennium Necklace |
| 17 | Kaiba | final | forced | Millennium Rod; the tournament ends |
| 18 | Mage Soldier | Pharaoh's Palace (Egypt II) | forced | guards the map to the Forbidden Ruins |
| 19 | Jono 2nd | hidden Dueling Grounds | optional | until the High Mages are all beaten |
| 20 | Teana 2nd | hidden Dueling Grounds | optional | |
| 21 | Ocean Mage | Sea Shrine gate | forced (to enter) | home field Umi (reading) |
| 22 | High Mage Secmeton | Sea Shrine | forced | returns the Millennium Necklace |
| 23 | Forest Mage | Forest Shrine gate | forced | home field Forest (reading) |
| 24 | High Mage Anubisius | Forest Shrine | forced | Millennium Key |
| 25 | Mountain Mage | Mountain Shrine gate | forced | home field Mountain (reading) |
| 26 | High Mage Atenza | Mountain Shrine | forced | Millennium Ring |
| 27 | Desert Mage | Desert Shrine gate | forced | home field Wasteland (reading) |
| 28 | High Mage Martis | Desert Shrine | forced | Millennium Scales |
| 29 | Meadow Mage | Meadow Shrine gate | forced | home field Sogen (reading) |
| 30 | High Mage Kepura | Meadow Shrine | forced | Millennium Eye |
| 31 | Labyrinth Mage | Labyrinth (Vast Shrine) | forced; repeats on a wrong turn | |
| 32 | Seto 2nd | end of the labyrinth | forced | **only** if you enter with 2–4 shrines cleared (§7.6) |
| 33 | Guardian Sebek | Vast Shrine, past the labyrinth | forced | Yami terrain; start of the no-save run |
| 34 | Guardian Neku | Vast Shrine | forced | Yami terrain |
| 35 | Heishin 2nd | Vast Shrine, Heishin's chamber | forced | same tables as id 8 |
| 36 | Seto 3rd | Forbidden Ruins | forced | three Blue-eyes Ultimate Dragon |
| 37 | DarkNite | Forbidden Ruins | forced | magic- and trap-heavy |
| 38 | Nitemare | Forbidden Ruins | forced | the final duel |
| — | Duel Master K | Free Duel only | — | always available; plays a copy of your deck |

The five shrines may be taken **in any order**; everything else is in this
order.

### 7.2 Egypt, the first time

*Opening.* You are the prince. Simon Muran, your tutor, lectures you in your
room; the first choice is `<Run away>` / `<Keep listening>` — insisting on
listening three times sends you to bed and skips the evening. Running away
puts you on the city map: **Pharaoh's Palace**, **Card Shop**, **Duel
Ground**, **Town Plaza**, **Shrine**.

*Pharaoh's Palace.* Simon offers `<Duel>` / `<Pass>` (id 1) — the
walkthroughs place this before the festival, the Neoseeker guide's unlock
note after meeting Jono; both are reported. Passing gets
`<Don't go>` / `<Go>` (to bed). Losing to him is **game over** like any
other campaign loss [event 97 of the event script: dialogue 504 "Simon Muran
(lose)", then the game-over opcode]; the guides that say otherwise are
wrong.

*Card Shop.* The shop menu (save, build deck, title, leave).

*Duel Ground.* Teana and the three villagers. Talking to anyone gives
`<Duel>` / `<Talk to someone else>` / `<Go outside>`; each can be dueled any
number of times. Villager 3 is here **only now**. `<Go outside>` after the
duels sends you and Teana to the **festival** in Town Plaza (the "mages'
procession" scene).

*Town Plaza — the festival.* You find Jono losing to **Seto**, Heishin's
prodigy. Whatever you answer, Seto agrees to duel you later at the Duel
Ground and is called away. Save at the shop (the Shrine now has High Mages
gossiping about Seto — optional dialogue).

*Duel Ground again.* Jono offers `<Duel>` / `<Pass>` (id 3) while you wait.
Then Seto arrives with his aides: forced duel (id 7). Winning it, Seto
recognises the prince and leaves. You may now train at the Duel Ground or
return to the palace.

*The palace, Heishin's coup.* Simon sends you to bed; a guard reports that
High Mage Heishin has invaded with a strange power. Seto corners you and
threatens the King and Queen for the Millennium Puzzle; whatever you choose,
Simon arrives beaten, hands you the Puzzle and tells you to `<Run>`. Heishin
blocks the way and forces a duel (id 8) — **you must lose it**; every win
just replays the duel. On the loss Heishin demands the Puzzle; the one
option is `<Shatter the Puzzle>`. Simon seals you both inside it. A thousand
years pass.

### 7.3 The KaibaCorp tournament

You are now **Yugi**, in the present. Every round starts in the **Card Shop**
(save; `<Leave Shop>` goes to the next opponent) and each win returns you to
it. The preliminaries are Rex Raptor, Weevil Underwood, Mai Valentine and
Bandit Keith (ids 9–12), forced, one after another. Between the preliminaries
and the finals Shadi appears, opens Yugi's mind with the Millennium Key,
Yugi meets the prince inside the Puzzle and receives **six blank cards**. The
finals are Shadi, Yami Bakura, Pegasus, Isis and Kaiba (ids 13–17); each win
forces that finalist's **Millennium Item** into a blank card — Key and Scales
from Shadi, Ring from Bakura, Eye from Pegasus, Necklace from Isis, Rod from
Kaiba. With all seven the prince can return to his own time. (During this
section the loaded menu's Free Duel already works — the guides recommend
farming Rex and Mai before Keith.)

### 7.4 Egypt, the second time

*Shrine of Glory.* Simon wakes the prince inside the Puzzle, explains that
Heishin holds six Items and rules from the Vast Shrine, that the five High
Mages guard one Item each in five shrines, and that the way to beat them is
in the **Forbidden Ruins** — then dies. You appear at the ruined Shrine of
Glory. The map now: **King's Valley** (left), **Metropolis** (right, twice).

*King's Valley.* Sadin the tomb-keeper: `<Go to parents' tomb>` / `<Go to
Forbidden Ruins>` / `<Leave this place>`. He will not show you the ruins
without proof; leave.

*Metropolis.* Sub-locations: **Old Duel Ground** (destroyed; Jono finds you
and takes you underground), the **hidden Dueling Grounds** (Teana, Jono 2nd,
Teana 2nd, villagers — `<Duel with Jono>` / `<Duel with Teana>` / `<Decline>`
on arrival, then the usual `<Duel>` / `<Talk to someone else>` / `<Go
outside>`), the **Hiding Card Shop** (`<Card Shop>` — the shop menu, i.e. the
save point — / `<Dueling Grounds>`), and **Pharaoh's Palace**: `<Enter>` /
`<Don't enter>`; inside, the Mage Soldier: `<Duel>` / `<Pass>`, forced (id
18); then `<Search>` / `<Don't search>` in your old room finds the **map to
the Forbidden Ruins**.

*King's Valley again.* `<Give Map>` / `<Leave this place>`. Sadin leads you
to the **Forbidden Ruins**: `<Look at map>` / `<Look at drawing>`. Looking at
the map brings Seto, who reads it: the five shrines and their Items. Sadin
throws him out and warns you he is not to be trusted. `<Return>` leaves, and
**five shrines open on the map**: Sea, Forest, Mountain, Desert, Meadow.

### 7.5 The five shrines

Each shrine is the same shape. At the gate a **Low Mage** (Ocean / Forest /
Mountain / Desert / Meadow Mage) blocks the way: forced duel on the shrine's
home terrain. Winning gives `<Proceed>` / `<Return>` — returning to save
means fighting the gate mage again next time. Inside, the **High Mage**
(Secmeton / Anubisius / Atenza / Martis / Kepura), forced, on the same home
terrain; the High Mage's script resets the terrain to the home field whenever
you change it. Winning recovers that shrine's Millennium Item (Necklace, Key,
Ring, Scales, Eye respectively) and the shrine is done. Any order; the map
shows which remain.

### 7.6 The labyrinth — the one branch

After **two to four** shrines, going to the hidden Dueling Grounds triggers
Jono: Teana has been kidnapped as bait for the Puzzle. You and Jono enter the
**Vast Shrine**'s labyrinth; the **Labyrinth Mage** (id 31) forces a duel. Then
four forks — `<Go right>`, `<Go right>`, `<Go left>`, `<Go right>` is the
way through [read off the menus' jump tables, §7.11]; any wrong turn means
another Labyrinth Mage duel and a restart from the first fork. At the end,
Heishin and **Seto 2nd** (id 32): forced duel; Seto was "testing" you and
frees Teana. Back to the shrines for the rest.

If you clear **all five** shrines first, this scene does not happen: Seto
2nd is never fought (and never unlocked for Free Duel), and the labyrinth is
entered only as part of the finale below. If it did happen, then after the
fifth shrine Seto appears at the Dueling Grounds to say Heishin is in the
Vast Shrine.

### 7.7 The finale, part one — the Vast Shrine

With all five Items back (six with the Puzzle), save at the Hiding Card Shop
— **this is the last save before the end**. Enter the Vast Shrine (the
labyrinth path again if you have not been through it, then Seto at a secret
door): `<Go ahead>` / `<Ignore the chance>`. Beyond it, in order, with no
chance to save between them:

1. **Guardian Sebek** (id 33), on Yami terrain;
2. **Guardian Neku** (id 34), Yami;
3. **Heishin 2nd** (id 35), in his chamber.

### 7.8 The finale, part two — the Forbidden Ruins

Seto arrives with the Rod: all seven Items are together; to the Forbidden
Ruins, where he reveals he wanted the Items for himself and opens the
chamber of DarkNite's statue. Forced duel: **Seto 3rd** (id 36). Beaten, he
leaves you the choice `<Destroy Items>` / `<Don't destroy>` — moot, because
Heishin appears, seizes Seto and demands the Items for his life: `<Hand over
the Items>` / `<Refuse>` (refusing repeats the prompt). Heishin places the
Items in the statue and summons **DarkNite**, who refuses to obey him and
turns him into a card. Seto reminds you of the Millennium Card; DarkNite
agrees to leave if beaten: forced duel (id 37). Beaten, he
reneges and becomes **Nitemare**: the last duel (id 38).

### 7.9 The ending

Nitemare vanishes, Seto flees, the ruins are sealed and the prince takes the
throne. The game offers a **save** (the completed-game flag is what enables
the Japanese PocketStation password menu) and rolls the **credits**
[`creditsLoop` `0x8002DA1C` → the 3-D sequence `func_8006CD78`, the largest
function in the game]. Afterwards the title returns; a completed save
continues in Free Duel with every campaign duelist available.

### 7.10 What the campaign reads and writes

> **Entered from:** name entry (new), loaded menu (Campaign). **Exits to:**
> duel (every fight), Build Deck / Save / loaded menu (every card shop), game
> over (every loss but Heishin's), credits (the end). **Reads:** the campaign
> progress state — where the story is, which shrines are cleared, which
> Items are held, whether the labyrinth scene has fired — plus the deck
> (refused if not 40) and the unlock/record tables it updates. **Writes:**
> progress state; after each duel the starchips, trunk, records and unlock
> bits (§6.5) through the shared post-duel path; the terrain byte
> [`0x8009B364`] and opponent id [`0x8009B361`] before each duel. **Uses:**
> the duel engine, the disc loader (scene pictures and the per-terrain duel
> blob), the card shop's menus, the memory card. **Where progress lives:** in
> the save's **flag array** [`0x801D0618`, §1], and the whole story is
> data-driven at two levels:
>
> * an **event script** — 4 KB loaded to `0x801A8000` as the third chunk of
>   the 49-sector blob at `WA_MRG.MRG` sector `0x1E57` [`func_8002FD10(scene)`
>   loads it, callback `func_8002FB78`]. It begins with a `u16 offset[199]`
>   table, one entry per event, and each event is a byte stream run by
>   `func_8002FA54` through a 23-opcode table [`0x80090C50`, opcode = byte &
>   0x1F]. The opcodes that matter for the flow: 1 = show location picture,
>   2 = run dialogue N, 3 = flag (set/clear, or "if flag, jump")
>   [`func_8002E918`], 8 = go to map location N, 12 = jump, 18 = game over,
>   19 = credits, 21 = "if the deck is not 40 cards, jump" (the deck check),
>   22 = title. Almost every event is "picture, dialogue, then map / game
>   over": the event script is the campaign's dispatcher, and it tests flags
>   to pick the variant of a location (events 33–46, 51 and 79 test `0x20`,
>   `0x26`, the five High Mages' flags, `0x47`, `0x48`, `0x4D`, `0x5A`,
>   `0x6F`);
> * the **dialogue texts**, which are in the executable [160 KB at
>   `0x801B11D6`–`0x801D859F`; text id `0x5xx` → `u16` table at `0x801C0000`
>   index `id − 0x100`, pointer = `0x801B0000` + offset, per
>   `func_800383DC`]. Bytes below `0xF0` are characters (the community's
>   `table.tbl` decodes `0x00`–`0x5B`); `0xF0`–`0xFF` are control codes
>   dispatched through a 16-entry table [`0x80090F18`, `func_800393B0`]:
>   `F8 op` selects a 27-entry sub-table [`0x80090EAC`] whose op `0x19` is
>   `func_80038AB0`, **unlock duelist** (sets `0x1F + id` and `0x6E0 + id`);
>   `F9 u16` is the **flag** code [`func_80038D2C`: bit 14 set/clear, else
>   "if flag, jump"]; `FA` wait, `FB` menu, `FC` insert a word, `FD` jump,
>   `FE` newline, `FF` end. So every SET of a story flag is inside a line of
>   dialogue, and every duelist's unlock is inside their "you won" line.
>
> The loaders read the flags too — the Egypt map loader [`func_8003C0C0`]
> picks the blob at sector `0x1FD9` or, if flag `0x47` is set, the one at
> `0x2077`. §7.11 lists every story flag with the dialogue that sets it;
> `tools_src/campaign_script.py` (in `MaChInEgUn3/ygofm-decomp`) reproduces
> both parses and the table.

### 7.11 The story flags

Read off the event script and the dialogue texts (§7.10): "set by" and
"tested by" are dialogue ids (Data Crystal's names where it has them), plus
the event-script events that test the flag. The "what it records" column is
what the setting line of dialogue says, so it is a reading of the game's own
text rather than of code.

| flag | set by (dialogue) | tested by | what it records |
|---|---|---|---|
| `0x20` | (unlock opcode, with `0x6E1`) |  + events 46 | Simon Muran beaten |
| `0x21` | (unlock opcode, with `0x6E2`) | 508 | Teana beaten |
| `0x23` | (unlock opcode, with `0x6E4`) | 50B | Villager 1 beaten |
| `0x24` | (unlock opcode, with `0x6E5`) | 50F | Villager 2 beaten |
| `0x25` | (unlock opcode, with `0x6E6`) | 513 | Villager 3 beaten |
| `0x26` | (unlock opcode, with `0x6E7`) |  + events 42,44,46 | Seto beaten |
| `0x31` | (unlock opcode, with `0x6F2`) | 57D | Mage Soldier beaten |
| `0x34` | (unlock opcode, with `0x6F5`) | 58C | Ocean Mage beaten |
| `0x35` | (unlock opcode, with `0x6F6`) | 595,596,59F,5A0,5A9,5AA,5B3,5B4,5BD,5DA,5DB,5DC,5DD,5DE,5E3,5E4,5E5,5E6,5E7,5E8,5E9,5EA + events 36 | High Mage Secmeton beaten |
| `0x36` | (unlock opcode, with `0x6F7`) | 596 | Forest Mage beaten |
| `0x37` | (unlock opcode, with `0x6F8`) | 58C,595,59F,5A0,5A9,5AA,5B3,5B4,5BD,5DA,5DB,5DC,5DD,5DE,5E3,5E4,5E5,5E6,5E7,5E8,5E9,5EA + events 33 | High Mage Anubisius beaten |
| `0x38` | (unlock opcode, with `0x6F9`) | 5A0 | Mountain Mage beaten |
| `0x39` | (unlock opcode, with `0x6FA`) | 58C,595,596,59F,5A9,5AA,5B3,5B4,5BD,5DA,5DB,5DC,5DD,5DE,5E3,5E4,5E5,5E6,5E7,5E8,5E9,5EA + events 38 | High Mage Atenza beaten |
| `0x3A` | (unlock opcode, with `0x6FB`) | 5AA | Desert Mage beaten |
| `0x3B` | (unlock opcode, with `0x6FC`) | 58C,595,596,59F,5A0,5A9,5AA,5B3,5B4,5BD,5DA,5DB,5DC,5DD,5DE,5E3,5E4,5E5,5E6,5E7,5E8,5E9,5EA + events 34 | High Mage Martis beaten |
| `0x3C` | (unlock opcode, with `0x6FD`) | 5B4 | Meadow Mage beaten |
| `0x3D` | (unlock opcode, with `0x6FE`) | 58C,595,596,59F,5A0,5A9,5AA,5B3,5BD,5DA,5DB,5DC,5DD,5DE,5E3,5E4,5E5,5E6,5E7,5E8,5E9,5EA + events 40 | High Mage Kepura beaten |
| `0x47` | 56A | — + events 44,45,46 | the tournament is over and the prince is back in Egypt (set by Simon in 56A) |
| `0x48` | 505 | — + events 46 | heard Simon's tale of the cards (505) |
| `0x49` | 50C | 50B | Villager 1 has told you about the festival (50C) |
| `0x4A` | 510 | 50F | talked to Villager 2 (510) |
| `0x4B` | 514 | 513 | talked to Villager 3 (514) |
| `0x4D` | 53D | — + events 51 | saw the mages waiting for Seto at the shrine (53D) |
| `0x4E` | 537 | 52E | Villager 1 has lost to you and changed his line (537) |
| `0x4F` | 53A | 530 | Villager 2 has lost to you and gone home (53A) |
| `0x50` | 586 | — | met Sadin at King's Valley (585/586) |
| `0x51` | 581 | 585 | found the map to the Forbidden Ruins in the palace (581) |
| `0x52` | 575,585 | 585 | handed the map to Sadin (585) |
| `0x53` | 58A | 585 | entered the Forbidden Ruins (58A) |
| `0x54` | 58A | 58A | looked at the map in the ruins (58A) |
| `0x5A` | 583 | — + events 79 | found the hidden Dueling Grounds (583) |
| `0x5B` | 5DA | 5DA | set and re-tested inside Jono 2nd's hub dialogue (5DA); purpose read as a once-only line |
| `0x5C` | 5DA | 595,59F,5A9,5B3,5BD,5DA,5DB | the kidnapping scene has played (5DA; High Mage defeats test it) |
| `0x5D` | 5BF | 5D9,5DA,5DB,5DC,5DD,5DE | all five High Mages beaten: Seto's "you defeated the High Mages" (5BF) |
| `0x5E` | 5D8 | 5D8 | visited the hiding card shop (5D8) |
| `0x5F` | 5DA | 5DA | set and re-tested inside dialogue 5DA; purpose read as a once-only line |
| `0x60` | 58A | 58A | looked at the drawing in the ruins (58A) |
| `0x61` | 5DB | 5DB | set and re-tested inside Teana 2nd's dialogue (5DB); purpose read as a once-only line |
| `0x62` | 5DB | 5DB | set and re-tested inside dialogue 5DB; purpose read as a once-only line |
| `0x63` | 5DC | 5DC | set and re-tested inside dialogue 5DC; purpose read as a once-only line |
| `0x64` | 5DC | 5DC | set and re-tested inside dialogue 5DC; purpose read as a once-only line |
| `0x65` | 5DD | 5DD | set and re-tested inside dialogue 5DD; purpose read as a once-only line |
| `0x66` | 5DD | 5DD | set and re-tested inside dialogue 5DD; purpose read as a once-only line |
| `0x67` | 5DE | 5DE | set and re-tested inside dialogue 5DE; purpose read as a once-only line |
| `0x68` | 5DE | 5DE | set and re-tested inside dialogue 5DE; purpose read as a once-only line |
| `0x69` | 5F2 | 5F1,5F2 | Labyrinth Mage beaten once (5F2 sets the next unset bit of 0x69-0x6C on each win; they only vary Jono's line at the next fork) |
| `0x6A` | 5F2 | 5F1,5F2 | Labyrinth Mage beaten twice |
| `0x6B` | 5F2 | 5F1,5F2 | Labyrinth Mage beaten three times |
| `0x6C` | 5F2 | 5F1,5F2 | Labyrinth Mage beaten four times |
| `0x6D` | 595,59F,5A9,5B3,5BD | 5EE | set with 0x5D after the fifth High Mage; tested by Seto at the labyrinth door (5EE) |
| `0x6E` | 501 | 542,5EE | Simon's evening lecture has happened (501/502) |
| `0x6F` | 521,522 | 507,51F + events 43 | Seto has challenged you at the festival (521/522) |

Events in the event script that test flags: 0x20→46, 0x26→42,44,46, 0x35→36, 0x37→33, 0x39→38, 0x3B→34, 0x3D→40, 0x47→44,45,46, 0x48→46, 0x4D→51, 0x5A→79, 0x6F→43

Three things the table shows on its own. Every duelist's unlock sits in
their "you won" dialogue — ids 1–38, one each, which is the independent
confirmation of the id order in §6.4. The five shrines are gated on the
**High Mage's** `0x1F + id` flag and skip the gate mage on the **Low
Mage's** (`0x34`, `0x36`, `0x38`, `0x3A`, `0x3C` tested by the shrine
dialogues), so "shrine cleared" is not a flag of its own. And the labyrinth
does **not** save your position: its four bits `0x69`–`0x6C` count Labyrinth
Mage wins — the mage's "you won" text (5F2) sets the next unset one and then
always presents the first fork again, with a different line from Jono each
time ("Let's move on", "Teana's waiting for us", "déjà vu", "these guys are
everywhere"). The route itself is in the menus' jump tables [after a menu's
options comes `FB 80` and one `u16` target per option, indexed by the
choice — `func_80038BF0`]: at forks 1, 2 and 4 "Go right" leads on and "Go
left" to the mage, at fork 3 it is the reverse — right, right, left, right,
as every guide says, now read off the bytes.

Not read: Nitemare's win text tests flag `0x5F7` in a jump-only branch, and
the small-id menu texts `0x40`–`0x45` do not parse with the control-code
widths used here. The ending text (5D7) sets and tests nothing.

### 7.12 Losing

A lost campaign duel goes to **game over** [`gameOverLoop` `0x8002D730`],
which offers a retry of the same duel or a return to the title (the save is
untouched, so the real cost is everything since the last card shop). The one
exception is Heishin's first duel, which must be lost. The Data Crystal scene
list (UNVERIFIED as ids) carries a named entry for every campaign event —
`500 Introduction` through `5D7 Ending`, with separate win/lose/rematch
scenes per duelist — and is the natural index for anyone tracing the story
code; it is reproduced in §12.4.

---

## 8. Free Duel

`SELECT OPPONENT!` — a list of every duelist you have **beaten in the
campaign** (plus Heishin, unlocked by the scripted loss, and Duel Master K,
always there), each with its record `WIN n LOSS n`. Pick one, and the duel
starts with your current deck [`freeDuelMenuLoop` `0x8002D3F8`, 32 functions,
the smallest subsystem in the game]. The rules, scoring, starchips and drop
are exactly the single-player path (§6); a loss records a loss and returns
you here — nothing else is lost. This is where the game is actually played
after the story: every guide's "farm X for Y" is a Free Duel loop.

**Duel Master K** is the exception in every way: not in the campaign, always
unlocked, plays a **copy of your own deck** [the patch that makes his deck
editable flips one byte, `0x8585` in the executable, from "copy the player's
deck" to "use a deck"], and his drop pools are a copy of Villager 3's (§6.4).

The unlock is one flag per duelist, `0x6E0 + id`, in the save's flag array
[bytes `0x801D06F4`–`0x801D06F8`]. The screen's own code, which lives in an
**overlay** loaded to `0x80168000` with the Free Duel blob (§12.2), marks all
40 grid entries available and then, for ids 1–38, clears the entry whose flag
is not set [the loop at `0x801683C0`–`0x801683EC` calls `func_8002CCA8(0x6E0
+ id)`]; entry 39 is never cleared — which fits Duel Master K being always
there, if that entry is his (a reading). Two consequences: the flags for ids 32–38 sit in the fifth
byte, `0x801D06F8`, so by this arithmetic the published "all opponents"
cheat, which writes four bytes, covers ids 1–31 — the community reports it
as unlocking everyone, and the two were not reconciled here (nothing was run);
and the "all opponents" *patch* code turns the clearing branch at
`0x801683D4` into a jump past it, which unlocks everyone.

The list is presented in campaign order: Simon Muran first,
Duel Master K last. Only two campaign duelists can be permanently missing
from it: Villager 3 (never dueled before the festival) and Seto 2nd (all
five shrines cleared before the labyrinth).

> **Entered from:** loaded menu. **Exits to:** duel; loaded menu. **Reads:**
> unlock mask, records, deck (must be 40). **Writes:** through the post-duel
> path — starchips, trunk, records. **Uses:** duel engine, disc loader (the
> opponent's block and portrait).

---

## 9. Two players and trading

### 9.1 2P Duel

Two saves, one on each memory card, one controller each. The screen loads
both saves (`Red` / `Blue`), checks that both decks are ready (`1P'S DECK IS
NOT READY`) and that the two saves are **different people** — every save
carries a **duelist code** (shown as `SECRET NO. 00000000` on these
screens), and `YOU CANNOT COMPETE WITH THE SAME DUELIST CODES!` refuses a
save dueling a copy of itself. The duel is the normal
engine with the AI replaced by the second controller; there is no scoring,
no drop and no record. [`tradeLoop` `0x8002D7CC` hosts both this setup and
Trade; scene texts `2PDUEL`, `PvP Duel Screen`.]

### 9.2 Trade

Both memory cards are read (× to load), each save's trunk is shown on its
side, each player marks the cards to give with □, and `Execute Trade` moves
them. The counts need not be equal, and a save may be left with fewer than
40 cards. The same duelist-code rule applies (`YOU CANNOT TRADE WITH THE SAME
DUELIST CODES!`), which is meant to stop copying a save and trading with
itself — and is defeated by a third memory card as an intermediary, which is
how the community duplicates cards and buys passwords "for free" (copy the
save, spend on the copy, trade the purchase through a fresh save to the
original). The starter deck of any new save can likewise be traded away,
forty cards at a time.

> **Entered from:** initial menu. **Exits to:** initial menu; duel (2P).
> **Reads/writes:** two save blocks' trunks and decks; nothing else.
> **Uses:** memory-card I/O on both slots, the duel engine (2P).

---

## 10. Saving and the memory card

One save per memory card (one block); `Save` exists on the loaded menu, in
every campaign card shop, and after the ending. Saving writes the whole save
block (§1): name and duelist code, deck, trunk with seen flags, starchips,
records, unlock mask, campaign progress, password-use record. Loading
restores it and shows the loaded menu; the campaign resumes at the last
scene. The dialogue messages are listed in §2.3. Nothing is auto-saved: a
Free Duel win that is not saved is lost on power-off, and so is a campaign
loss you did not save after.

---

## 11. Numbers you will meet in the code

The constants an agent will see as bare immediates, and what each one is:

| number | means |
|---|---|
| **722** | the card count; any loop to 722 or table of 722 entries is per-card (trunk bytes, weight tables, password table) |
| **723** | 722 + the unused id 0 — the fusion table's offset array is `u16[723]` |
| **40** / **0x50** | the deck size in cards / in bytes (40 × u16) |
| **8000** / **0x1F40** | starting life points |
| **5** | the hand size; also the zones per row, the pairs per rank row, the starchips for an S |
| **10** | the zones per side; rows in the rank table; the guardian stars; the traps; the ranks |
| **20** | the monster types (0–19); also **0x20**, the per-side duel record stride |
| **24** | rituals; **34** equips; **33** pure magic; **10** traps; **621** monsters |
| **28** / **0x1C** | the cards-in-play record stride; slots 0–9 player, 20–29 opponent |
| **500** | the guardian-star bonus, the terrain bonus, one equip level |
| **2048** / **0x7FF** | the drop roll: `(rand & 0x7FF) + 1`; every weight table sums to 2048 |
| **1460** / **0x5B4** | one weight table: 722 × u16 + 16 bytes of padding; the three drop pools are 0x5B4 apart |
| **50** | the rank score's starting value; **99** the clamp; `/ 10` the letter |
| **3** / **1** | max copies of a card in the deck / of each Exodia piece |
| **39** | duelists (0–38 in the block/id order; the record array has 39 slots) |
| **17** | modes in the mode table; **67** AI opcode handlers; **14** magic effect groups |
| **7** | terrain types including normal (0–6), and therefore seven copies of the duel data on disc |
| **235** / **0xEB** | sectors per duel-data blob; **0x16C6** its first sector; **0x1D33** the first per-duelist block, 3 sectors each |
| **0x800** | one CD sector, the ritual table's size, the unit of every disc offset |
| **999,999** | the password cost of a card the game does not mean you to buy |
| **0x8000F800** | file offset → RAM address delta for `SLUS_014.11` |

---

## 12. Where the data lives

### 12.1 In the executable

The card database (stats, levels, names), the terrain table, the effect-group
table and handler tables, the mode table, the AI opcode table, and the
in-game text — every dialogue line of the campaign is here, 160 KB from
`0x801B11D6`, with its pointer table at `0x801C0000` (§7.10). The rule tables of the duel are **not** here: their addresses
are zero in the file because the duel loader fills them from disc.

### 12.2 On the disc

The game opens seven files by name at boot [table at `0x8009078C`,
`setFilePosTable` `func_800136E4`]: `WA_MRG.MRG` (36 MB, everything that is
data), `SU.MRG`, `MODEL.MRG` (3-D models), `MOVIE.STR`, `SD_SE.DAT`,
`SD_BGM.DAT`, `MASTER.XA`. Everything else is a sector range inside one of
them, requested through one function with a per-screen callback
[`func_80014E1C(mode, table, sector, count, callback, …)`]; each menu has a
fixed sector constant (`0x1690`, `0x1E88`, `0x1EDF`, `0x1F2F`, `0x1F85`,
`0x1FA7`, `0x2115`, `0x2147`, `0x2157`, `0x2189`, one indexed at `0x1FD9`).

**The duel blob.** Starting a duel issues one read of **235 sectors at sector
`0x16C6 + 235 × terrain`** [`func_8001798C`, callback `func_800171A8`, a
thirteen-case state machine whose chunk sizes sum to exactly 235 × 2048]:

| offset | size | goes to | what |
|---|---|---|---|
| `+0x00000` | 0x20000 | VRAM (768, 256) | pictures |
| `+0x20000` | 0x2000 | staging → `LoadImage2` rect (256, 240) 256×16 | pictures |
| `+0x22000` | 0x2800 | `0x8017A1D8` | **equip table** |
| `+0x24800` | 0x10000 | `0x8017C2D8` | **fusion table** |
| `+0x34800` | 0x800 | `0x801799D8` | **ritual table** |
| `+0x35000` | 0x1000 | staging → `LoadImage2` rect (0, 240) 256×8 | pictures |
| `+0x36000` | 0x10000 | VRAM (x = 512) | pictures |
| `+0x46000` | 0x16000 | `0x80146000` | the 90 KB **code overlay** |
| `+0x5C000` | 0x1800 | `0x801A8000` | the AI script area (reading) |
| `+0x5D800` | 0x1800 | `0x801A9800` | not read |
| `+0x5F000` | 0x4000 | VRAM (832, 0) | pictures |
| `+0x63000` | 0x2800 | `0x80100000` | not read |
| `+0x65800` | 0x10000 | VRAM (640, 256) | the field picture — the only chunk that differs between the seven terrains |

Twelve of the thirteen chunks are byte-identical across the seven terrain
copies; the tables decode with every id in range (fusion 25,131 rows, equip
4,041, ritual 24) and the overlay lands on the sector an independent
extractor gives. The VRAM x-coordinates 640–832 are past the 640-pixel
framebuffers, i.e. the texture area.

**The per-duelist block.** Before a duel the opponent's block is read:
**3 sectors at `0x1D33 + 3 × id`** into `0x801781D8` [`func_800179F4`] —
deck weights at +0, the POW / BCD / TEC drop pools at +0x5B4 / +0xB68 /
+0x111C (1,460 bytes each), the rank table at +0x16D0 (200 bytes), 104
unread bytes at +0x1798. All 156 weight tables sum to 2048.

**Overlays.** `0x80146000` receives the duel's code overlay above; a second
slot at `0x80168000` receives per-screen code from the menu blobs. Two are
located: the **password shop's**, a 0x7800-byte chunk at `+0x20800` of the
blob at sector `0x1EDF` (and again at `+0x23800` of the one at `0x1F2F`),
where the three shop GameShark patches were verified; and the **Free Duel
screen's**, the last 0x2800 bytes (`+0x29000`) of its 87-sector blob at
`0x1E88` [loader `func_8003B9BC`, callback `func_8003B808`], 8 KB of code
whose entry `0x80168FB4` is one of the executable's own call targets and
where the Free Duel unlock patch was verified. The executable's other call
targets in that range belong to whichever overlay is resident at the time,
so they do not all resolve in one image.

**The scan the tables were found by** is reproducible: `tools_src/
extract_mrg_tables.py` in `MaChInEgUn3/ygofm-decomp` reads all of the
above out of a raw copy of `WA_MRG.MRG`; `tools_src/decode_tables.py` holds
the decoders, each written from the function that indexes the table.

### 12.3 Cheat codes as documentation

The published GameShark codes for this build are a second map of the same
state — LP, trunk, starchips, records, cards in play — and three of them
patch instructions in the executable and three more in the shop overlay,
which is how several functions above got their names. They are compiled and
verified in `gameshark_codes_list.md`.

### 12.4 The scene index (UNVERIFIED — Data Crystal)

The community's list of dialogue-scene ids, kept because it is the only
event-level index of the campaign that exists; nothing here is measured.
Ranges: `002` name entry; `008`–`029` menu and deck-check messages; `03D`–
`045` post-duel messages (`YOU`/`COM`, `TOTAL ANNIHILATION`, `VICTORY BY
ATTRITION`, `SUMMON Exodia`); `0BA`–`0DF` memory card; `0E1`–`0E3` password
screen; then the story: `500` introduction, `501`–`506` Simon Muran (rant,
pre-duel, win, lose, the cards speech), `507`–`50B` Teana (duel, re-duel,
before the festival, dismissed), `50C`–`510` villagers, `543` Heishin
rematch, `551`–`553` Mai, `554` Bandit Keith, `560` Pegasus, `566`–`568`
Kaiba, `569` all Items gathered, `56A` return to Egypt, `577` map to Sadin,
`581` map to the ruins found, `583` hidden dueling grounds, `58E`–`590`
Water Mage, `593` Secmeton, `5AE` Desert Mage, `5B1` Martis, `5C8`–`5D1`
Heishin's chamber and threats, `5D3` DarkNite lose, `5D4`–`5D6` Nitemare,
`5D7` ending, `5D8` Egypt card shop after the tournament, `5D9` Vast Temple
guard, `5DA`–`5E5` Jono 2nd and Teana 2nd, `5EC` enter the labyrinth, `5F0`
Teana rescued, `5F1`–`5F3` Labyrinth guard, `5F4`–`5F5` Seto 2nd, `5F6`
prompt before the Yami temple, `5F8` festival ended, `5FD` post-duel, `D00`
`T-Duel? NO YES`, `E00` Jono's first duel prompt. The same source lists 57
music tracks (ids 0x00–0x38) and the terrain and type ids used above.

---

## 13. What is not verified, and where the earlier version was wrong

Not verified in code:

* what flag `0x5F7`, tested by Nitemare's win text, means;
* the control-code widths of the text engine were read from the handlers
  and hold for 1,528 of the 1,536 texts — six menu texts do not parse;
* the per-screen button maps outside the duel and Build Deck;
* whether a monster played this turn may attack this turn (stated from play);
* the three victory-condition score adjustments (+2 / −40 / +40) and the
  names of the ten score categories (matched to the community's table);
* the initial-deck generator's group tables (Data Crystal names them);
* the whole duelist-id order rests on 92–100 % matches against one
  independent list, and on every unlock opcode sitting in the right win
  dialogue (§7.11);
* the win/loss record order (the archives' claim; only the drop-block order
  is measured);
* what Simon Muran's loss in the opening does (the guides disagree), and
  when his duel is offered (before or after the festival);
* what quitting a duel through `QUIT DUEL?` counts as;
* what the two "enable" GameShark codes target — their guards match neither
  located overlay;
* the home terrains of the five shrines and the finale (only Sebek/Neku's
  Yami is sourced);
* three chunks of the duel blob and the 104-byte tail of the duelist block;
* the Free Duel overlay has since been located (§12.2), so only the two
  "enable" codes remain unplaced.

Corrected from the earlier version of this document: the rank-table
category labels (rows 4, 5, 8, 9); the seven-rank list (ten); the duelist
names attached to drop blocks (off by one from Teana on, and the
"Nitemare/DarkNite swap" verdict reversed — the blocks are right, the cheat
labels are probably swapped); the "work buffer / LoadImage" reading of the
duel loader; the 7,056-byte duelist block (3 sectors); "no equip candidate on
disc" (the scan's filter was narrower than the table); the initial menu's
contents; and "unlocked by meeting" (it is by defeating).

---

## 14. Sources

Measured here: everything in brackets, against `SLUS_014.11` NTSC-U and the
retail disc's `WA_MRG.MRG`. Names of functions and modes: the GMS IDA
database of this binary. Rules and screen behaviour: the game, checked
against the Yugipedia article on the game (rules, spoils, deck construction,
initial deck, trading), the Neoseeker campaign guide (unlock conditions,
per-duelist cards won), a Portuguese walkthrough (dialogue options and
location structure), a 2022 campaign guide, the speedrunning community's
guide (rank farming and the 2048 pools), the card texts as printed in the
game, and the Data Crystal wiki (scene, music, terrain and type ids; RAM and
ROM maps — all UNVERIFIED here). The hacking tutorials circulated by the
Brazilian modding community supplied the deck-limit, Duel Master K and Exodia
patch offsets.
