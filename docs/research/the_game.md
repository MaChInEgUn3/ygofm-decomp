# Yu-Gi-Oh! Forbidden Memories — the whole game, in prose

Written so that someone — or an agent — who has never played it can read this
first and then open the code knowing what each part is *for*. It describes the
game as the player experiences it: every screen, how you get between them, the
rules of a duel, and what happens after one.

**Where this comes from.** The rules and the flow are how the game plays;
anyone who has played it will recognise them, and they are stated here from
knowledge of the game rather than from the code. Wherever a screen, a table or
a number has been *located in the binary*, the address or function is given in
brackets — those are measured against `SLUS_014.11` and are the parts an agent
can grep for. A few things are explicitly marked as unverified.

---

## What the game is

Forbidden Memories is a card-battling game built on the Yu-Gi-Oh! trading
card game, but with its own simplified rules — no tribute summons, no chains,
no card text to speak of. Two duelists face each other across a five-by-two
grid, each with 8000 life points, a deck of 40 cards and a hand of five, and
the first to run the other's life points to zero wins. What makes it its own
thing is **fusion**: any two cards in your hand can be laid on top of each
other, and if the game's hidden table has a recipe for that pair, they become
a new card. Learning what fuses with what is most of the game.

There are 722 cards. You start with a weak deck and earn better cards by
winning duels — each win drops one card, chosen from a pool that depends on
*how well* you duelled — and by spending starchips on passwords.

The story frame is ancient Egypt: you are Prince Atem, the pharaoh's heir, and
the high priest Heishin seizes power using the Millennium Items. You duel your
way through his mages to recover the items and unseat him. Wrapped around that
is a modern-day section where you play as Yugi, who has inherited Atem's
memories through the Millennium Puzzle.

---

## The screens, and how you move between them

The whole game is one loop, `mainLoop` [`0x8002DD74`], that runs whichever
**mode** is current. There are seventeen modes [table at `0x80090B64`] and
every screen you ever see is one of them. Their names are the ones the
original developers used, recovered from an IDA database of the game.

**Title and main menu** [`mainMenuLoop`, `func_8002D588`]. After the intro
video the title screen offers Campaign, Free Duel, Build Deck, Library,
Password, Trade and Options. Choosing Campaign with no save takes you to name
entry.

**Name entry** [`nameEntryLoop`, `func_8002D62C`]. You type a name for the
save file and it takes you into the campaign's opening.

**Campaign** [`campaignLoop` `func_8002CE64`, and `campaignOverworldLoop`
`func_8002D2D8`]. The story mode. It alternates between dialogue scenes and
duels, with a map screen between them once the Egyptian section opens up. A
lost campaign duel goes to **game over** [`gameOverLoop`, `func_8002D730`],
from which you retry that duel.

**The duel itself** [`duelLoop`, `func_8002CEE8`]. Described in full below.
Every duel, campaign or free, runs here. When two monsters fight, the game
cuts to a 3D **battle animation** [`animatedBattleLoop`, `func_8002D180`] and
returns to the duel afterwards.

**Free Duel** [`freeDuelMenuLoop`, `func_8002D3F8`]. A list of every duelist
you have met in the campaign; pick one and duel them with your current deck,
outside the story. Wins and losses against each are tracked and shown.
Unlocked duelists are a bitmask in the save [`0x801D06F4`].

**Build Deck** [`buildDeckMenuLoop`, `func_8002D370`]. Move cards between your
trunk (everything you own) and your deck (exactly 40). Cards can be sorted and
filtered here.

**Library** [`libraryMenuLoop`, `func_8002D0E0`]. A catalogue of every card
you have *seen*, with its picture, stats and password. Cards you have not seen
are shown as unknown. Whether a card counts as seen is a per-card flag kept
alongside its trunk count [`0x801D0250`].

**Password** [`passwordMenuLoop`, `func_8002D684`]. Enter a card's eight-digit
password and pay its starchip cost to receive it. Every card has one; the
expensive ones cost hundreds of thousands. This is the shop.

**Trade** [`tradeLoop`, `func_8002D7CC`]. Two-player card trading between two
memory cards, and the two-player duel option.

**Options** [`optionsMenuLoop`, `func_8002D6C8`]. Sound and display settings.

**Credits** [`creditsLoop`, `func_8002DA1C`]. Rolls after the final campaign
duel. This is the largest single piece of code in the game — a 3D sequence
[`func_8006CD78`, 2319 instructions] that calls the random-number generator
more than any other function in the binary.

**Two you never see.** Slot 0 is a **debug menu** [`debugMenuLoop`,
`func_8002CE08`], still reachable by a cheat that writes `0x0B` to the menu
selection variable [`0x80184594`]. And slot 13, **hirataLoop**
[`func_8002D7C4`], is an eight-byte stub — a two-Blue-Eyes test duel that a
developer named Hirata left behind; the function was emptied for release but
its slot was kept.

---

## The story, briefly

The campaign has three acts, and the order in which you meet duelists is the
order they are stored in the save file [39 records from `0x801D0720`] — which
is the one piece of the story the binary states outright.

**Egypt, first visit.** Prince Atem, in the palace, duels his tutor Simon
Muran, his friends Teana and Jono, and three villagers as practice. Then
Heishin, the high priest, uses the Millennium Rod to seize the throne. You
duel him and lose; Simon seals your soul into the Millennium Puzzle to save
it.

**The present day.** Yugi Muto, who solved the Puzzle, carries Atem's spirit.
He duels his school friends and then, at Duelist Kingdom, the cast of the
anime — Rex Raptor, Weevil Underwood, Mai Valentine, Bandit Keith, Shadi, Yami
Bakura and finally Pegasus, whose Millennium Eye sends Yugi's spirit back to
Egypt. Isis and Kaiba appear here too.

**Egypt, return.** Now with the Puzzle's power, you work through Heishin's
forces to recover the Millennium Items: the Mage Soldier, then the mages of
the Ocean, Forest, Mountain, Desert and Meadow (each guarding a high mage —
Secmeton, Anubisus, Atenza, Martis, Kepura), the Labyrinth Mage, the
guardians Sebek and Neku, then Heishin again, Seto — the priest who
becomes Kaiba's ancestor — and finally Nitemare and its true form DarkNite.
Beat DarkNite and the credits roll.

A thirty-ninth record, **Duel Master K**, sits after DarkNite. He is not part
of the story.

---

## A duel, from start to finish

This is the heart of the game and where most of the code lives.

### Setup

Both players start with **8000 life points** [player `0x800EA004`, opponent
`0x800EA024`; each side's record is 32 bytes, and the number shown on screen
counting down is kept separately two bytes below the true value]. Each has a
40-card deck, shuffled [`shuffleDeck`, `shuffleBothDecks`], and draws five.
The field is empty and the terrain is *normal*.

The field is a grid. Each player has five **monster zones** in a row nearest
the centre and five **magic/trap zones** behind them. Cards in play are kept
in one array of 28-byte records [`0x801A7AD8`], ten slots per side, with a
monster's attack at offset `+0xE` and defence at `+0x10`.

### A turn

The player whose turn it is:

1. **Draws** until they hold five cards.
2. **Plays one card** from the hand to the field, or fuses cards first and
   plays the result. This is the only card that goes to the field this turn.
3. **Attacks** with any monsters that were already on the field at the start
   of the turn. A monster placed this turn cannot attack.
4. Ends the turn.

There is no tribute cost — a Blue-Eyes White Dragon is played exactly like a
Kuriboh. There are no hand-size limits beyond the five you draw to, no graveyard
interactions, and no reading of card text: what a magic or trap card does is
fixed and simple.

### Playing a monster

When you play a monster you choose **attack or defence position**, **face up
or face down** (face-down cards are always in defence), and one of the
monster's two **Guardian Stars**.

**Guardian Stars** are the game's elemental system. Every monster has two,
one primary and one secondary, drawn from ten: Sun, Moon, Mercury, Venus,
Mars, Jupiter, Saturn, Uranus, Pluto, Neptune. They form two cycles of
advantage —

    Sun → Moon → Venus → Mercury → Sun
    Mars → Jupiter → Saturn → Uranus → Pluto → Neptune → Mars

— and the rule, read from the code [`gsBonus` `func_8002CB80`, decompiled],
is stricter than "beats": only **adjacent** stars in a cycle interact. If your
star is the one immediately *before* the opponent's in its cycle you get
**+500**; if it is the one immediately *after*, **−500**; any other distance,
or a star from the other cycle, is 0. The code treats stars 1–6 as the
six-cycle and 7–10 as the four-cycle. Choosing the right star is the
moment-to-moment skill of the game.

### Battle

A monster attacks another monster, or attacks the opponent directly if they
have no monsters. Effective attack and defence are computed from the card's
base stats plus the Guardian Star bonus plus the terrain bonus [`monBattleEffAtk`
`func_8001EF1C`, `monBattleEffDef` `func_8001EF78`; base stats from
`baseCardStat` `func_8002CBF4`].

* Attack against an **attack-position** monster: the lower-ATK monster is
  destroyed and its owner loses the difference in life points. Equal ATK
  destroys both.
* Attack against a **defence-position** monster: if ATK exceeds DEF the
  defender is destroyed, no life points are lost. If DEF is higher, the
  *attacker* loses the difference. Equal, nothing happens.
* A **face-down** monster is flipped when attacked and then resolved as
  defence.

The 3D battle animation plays for every monster-versus-monster fight, showing
the two models and the winner.

### Terrain

The field has a terrain, set by playing a field magic card: **Forest,
Wasteland, Mountain, Sogen (meadow), Umi (sea), Yami (dark)**, or normal
[`0x8009B364`]. Each monster type is helped or hurt by each terrain — a Fish
gains 500 on Umi, a Dragon gains 500 on Mountain, a Fairy loses 500 on Yami —
and the bonus is looked up per type per terrain [`getTerrainBoost`
`func_8002497C`, reading an `s8[20][6]` at `0x800909D4` and multiplying by
10]. Terrain persists until another field card replaces it. The whole table,
read from the executable:

| type | forest | wasteland | mountain | meadow(sogen) | sea(umi) | dark(yami) |
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

Only the 20 monster types have rows — the function returns 0 for anything
else — and every cell is one of exactly three values. The column-to-terrain
names come from the community cheat list, not from code; the code only says
"column = terrain byte − 1".

### Magic, traps, equips — what each card does, from the code

The game does not read a card's *text*; it reads its **number**. When a card
from one of the three non-monster ranges is played, a placement state machine
[`func_80019608`] hands the id to a guard [`func_80026BA4`] that accepts only
301–350, 651–700 and 721, converts it to a small index, and a per-tick
dispatcher [`func_80026B34`] looks that index up in a 104-byte table
[`0x80090AD4`] to get an **effect group**, 0–13, then calls the group's
handler from a 30-entry function table [`0x80090A5C`] — one entry for the
announce pass and one for the resolve pass. So every spell in the game is one
of fourteen behaviours, and which cards share a behaviour is data:

| group | cards | what the handler does |
|---|---|---|
| 0 | all 34 **equips** and all 10 **traps** | nothing at play time — equips resolve when attached to a monster, traps when triggered |
| 1 | Forest, Wasteland, Mountain, Sogen, Umi, Yami | sets the terrain [`0x8009B364`] and recomputes bonuses |
| 2 | Mooyan Curry, Red Medicine, Goblin's Secret Remedy, Soul of the Pure, Dian Keto the Cure Master | restores life points by a per-card amount |
| 3 | Sparks, Hinotama, Final Flame, Ookazi, Tremendous Fire | deals 50 / 100 / 200 / 500 / 1000 damage to the opponent's life points |
| 4 | Dark Hole, Dragon Capture Jar | acts on every monster on the field (Dragon Capture Jar is special-cased by id) |
| 5 | Warrior Elimination, Eternal Rest, Stain Storm, Crush Card, Eradicating Aerosol, Breath of Light, Eternal Draught | destroys monsters selected by one per-card parameter — by the names, a monster type each |
| 6 | Stop Defense | flips a defending monster to attack |
| 7 | Raigeki | destroys the opponent's monsters |
| 8 | Dark-piercing Light | reveals face-down monsters |
| 9 | Spellbinding Circle, Shadow Spell | lowers an enemy monster's stats by 500 / 1000, on a timer |
| 10 | Swords of Revealing Light | reveals the opponent's field and installs a lasting effect on their side |
| 11 | Cursebreaker | removes an effect |
| 12 | all 24 **rituals** | validates the three tributes [`checkRitual`, `0x801799D8`] and performs the summon |
| 13 | Harpie's Feather Duster | destroys the opponent's magic/trap zone |

The "what" column is the handler's code as read, with the card names filled
in from the effect table; the two rows marked *by the names* are the reading
that the names make obvious but the code was not traced far enough to state
outright. Groups 6, 7, 8, 10, 11 and 13 all use the same animated
slot-by-slot scan, which is why they play out visibly one zone at a time.

An **equip** is played onto one of your monsters and raises its stats — but
only if that equip is valid for that monster, which is a hidden table
[`equipTable` `0x8017A1D8`, checked by `checkEquip` `func_80019A08`]. An
invalid equip is wasted. A **trap** is placed face down in a magic/trap zone
and springs on the opponent's action automatically; there is no choosing
when.

### Fusion

This is the mechanic the game is built around. In your hand, select two or
more cards in order. The game tries to fuse the first two: it looks the pair
up in the **fusion table** [`fusionTable` `0x8017C2D8`, 64 KB; `checkFusion`
`func_80019A60`]. If there is a recipe, they become the result card, and the
next selected card is then fused with *that*. If there is no recipe, the
first card is discarded and the second remains — a failed fusion costs you a
card.

Recipes are not printed anywhere in the game. Some are obvious — two dragons
make a bigger dragon — most are not, and part of the game's culture is the
community's fusion lists. Fusion can also be done with a card already on the
field: play a hand card onto a field monster.

**The table has now been read off the disc** — it is the 64 KB chunk at
`+0x24800` of the duel blob described under *Where the rule tables live*
(`WA_MRG.MRG` @ `0xB87800` in the terrain-0 copy; decoder
`tools_src/decode_tables.py`, extractor `tools_src/extract_mrg_tables.py`).
It holds **25,131 recipes** producing **204 distinct results**, and every id
in it is a valid card. The encoding is what `checkFusion` reads: a
`u16 offset[723]` indexed by the *smaller* of the two card ids (zero means
"no recipe as the smaller partner"), and at each offset a run of 5-byte
records, each packing two `(partner, result)` pairs as 10-bit ids. Two things
in it that anyone who has played the game will recognise: Thunder Dragon +
Thunder Dragon → Twin-headed Thunder Dragon; and the results are wildly
uneven — **Nekogal #2 is the result of 1200 recipes, Mystical Sand of 1174, Cyber
Soldier of 1008**. That is the game's fusion sink: most pairs of a weak monster
with the right type fall into a handful of mid-level results, which is why
random fusing in the early game keeps producing the same few cards.

### Rituals

Three specific monsters on your field plus the matching ritual magic card
summon a ritual monster [`ritualData` `0x801799D8`, `checkRitual`
`func_8002C7E8`]. The table is **not** in the executable; it is the 2 KB
chunk at `+0x34800` of the duel blob (`WA_MRG.MRG` @ `0xB97800` in the
terrain-0 copy), read straight into `0x801799D8` by the duel loader, and it is
byte-identical in all seven terrain copies. 24 five-halfword records; every
tribute and result is a valid card id. Three of the 24, names filled in from
the card table:

* Black Luster Ritual = Beaver Warrior + Gaia the Fierce Knight + Kuriboh → Black Luster Soldier
* Zera Ritual = King of Yamimakai + Wicked Dragon with the Ersatz Head + Ryu-kishin Powered → Zera The Mant
* War-lion Ritual = Frenzied Panda + Leogun + Garvas → Super War-lion

### Where the rule tables live

| table | runtime address | read by | on disc (`WA_MRG.MRG`, terrain-0 copy) | size |
|---|---|---|---|---|
| terrain bonuses | `0x800909D4` | `getTerrainBoost` | in the executable | 120 B |
| equip | `0x8017A1D8` | `checkEquip` | duel blob `+0x22000` = `0xB85000` | 0x2800 |
| fusion | `0x8017C2D8` | `checkFusion` | duel blob `+0x24800` = `0xB87800` | 0x10000 |
| ritual | `0x801799D8` | `checkRitual` | duel blob `+0x34800` = `0xB97800` | 0x800 |
| rank scoring | `0x801798A8` | `rankScoreChange` / `calcRankScore` | duelist block `+0x16D0` (sector `0x1D33 + 3 × opponent`) | 200 B |

All four disc tables decode with every id in range, and the equip one holds
**4,041 (equip, monster) pairs over exactly the 34 equip cards** (Legendary
Sword alone equips 63 monsters; the biggest, Megamorph, equips 621).

**How they get there** was read off a function that is already decompiled
here, `func_8001798C`, and it replaces the "work buffer" explanation this
section used to give. The duel's disc load is one call:

    func_80014E1C(0, 0, terrain * 235 + 0x16C6, 235, func_800171A8, 0, 0);

— 235 sectors (481,280 bytes) of `WA_MRG.MRG` starting at sector `0x16C6`,
one such **blob per terrain type** (`D_8009B364`, 0–6), 235 sectors apart,
with `func_800171A8` as the callback. That callback is a thirteen-case state
machine (jump table `jtbl_800100C0`): each case takes the next chunk of the
stream and fills a transfer record — destination at `+0xC`, size at `+0x1C`,
and for VRAM-bound chunks the x/y at `+0x30`/`+0x32`. **The thirteen sizes,
in case order, sum to exactly 235 × 2048**, which is the proof of the layout
below; the three table chunks and the overlay were then decoded or verified in
place.

| blob offset | size | destination | what |
|---|---|---|---|
| `+0x00000` | 0x20000 | VRAM (768, 256) | picture data |
| `+0x20000` | 0x2000 | staging buffer, then `LoadImage2` rect (256, 240) 256×16 | picture data |
| `+0x22000` | 0x2800 | `0x8017A1D8` | **equip table** |
| `+0x24800` | 0x10000 | `0x8017C2D8` | **fusion table** |
| `+0x34800` | 0x800 | `0x801799D8` | **ritual table** |
| `+0x35000` | 0x1000 | staging buffer, then `LoadImage2` rect (0, 240) 256×8 | picture data |
| `+0x36000` | 0x10000 | VRAM (x = 512) | picture data |
| `+0x46000` | 0x16000 | `0x80146000` | the 90 KB **code overlay** (`docs/DISC.txt`) |
| `+0x5C000` | 0x1800 | `0x801A8000` | not read |
| `+0x5D800` | 0x1800 | `0x801A9800` | not read |
| `+0x5F000` | 0x4000 | VRAM (832, 0) | picture data |
| `+0x63000` | 0x2800 | `0x80100000` | not read |
| `+0x65800` | 0x10000 | VRAM (640, 256) | the field picture — the **only** chunk that differs between the seven terrains |

Measured: the case order, the sizes, the table destinations, and the
per-terrain comparison (twelve of the thirteen chunks are byte-identical
across all seven blobs). Readings: that the VRAM coordinates in the record
are where the picture chunks land, and what the three "not read" chunks are
for. The VRAM x-coordinates 640–832 are past the 640-pixel framebuffers, so
those chunks go to the texture area, not the screen. "Seven redundant copies
of the overlay", as the disc notes put it, is therefore seven terrain variants
of one 64 KB picture, each shipped with a duplicate of the other 416 KB.

**Retracted.** The earlier version of this section said `func_800171A8`
passed the table addresses to `LoadImage` as VRAM-upload *sources*, making
the region a work buffer. Wrong: what goes to `LoadImage2` is the staging
buffer `D_8009B118` with a RECT at `D_800E9D70`; the table addresses go into
the record's destination field, and the region is just where the loader puts
the tables. The section also said the equip table was scanned for across both
archives "with that exact validity test: no candidate" — keys in 301–350. The
archive was fine and the test was narrower than the table: seven of the 34
equip keys are above 350 (651–668, the second run of non-monster ids), eight
keys have more than 120 members (Megamorph equips 621), and a chain check
that stops at the first key it does not expect never reaches the fifteenth
row it demands. The rank signature never had a chance either — it was
matching smooth byte runs, as the section said.

**The per-duelist block** is the other loader in the same family,
`func_800179F4`:

    func_80014E1C(0, 0, opponent * 3 + 0x1D33, 3, ..., 0x801781D8);

three sectors per duelist, indexed by the opponent id (`D_8009B361`), into
`0x801781D8`. The 6,144-byte block is: the opponent's **deck weights**
(722 × u16) at `+0`; the **POW, BCD and TEC drop-pool weights** at `+0x5B4`,
`+0xB68`, `+0x111C` — 1,460 bytes each, and the runtime copies `0x8017878C`,
`0x80178D40`, `0x801792F4` are exactly those offsets from `0x801781D8`; the
**rank table** at `+0x16D0`, 200 bytes, identical for all 39 duelists; and
104 bytes at `+0x1798` not read here.

The game opens exactly seven disc files, named in a table the boot code
walks [`0x8009078C`, `setFilePosTable` `func_800136E4` → `CdSearchFile` →
`CdPosToInt`]: `WA_MRG.MRG`, `SU.MRG`, `MODEL.MRG`, `MOVIE.STR`, `SD_SE.DAT`,
`SD_BGM.DAT`, `MASTER.XA`. Everything else is an entry inside one of those,
addressed by sector from the file's start. The other decompiled callers of
`func_80014E1C` load the menus the same way — fixed sector constants in
`WA_MRG.MRG` (`0x1690`, `0x1E88`, `0x1EDF`, `0x1F2F`, `0x1F85`, `0x1FA7`,
`0x2115`, `0x2147`, `0x2157`, `0x2189`, one indexed at `0x1FD9`) each with its
own dispatcher callback; six more callers are still assembly.

### The opponent's turn

The computer plays by running a **script**. Each duelist has one, a short
bytecode program [loaded at `0x801A8000`], and a small interpreter
[`aiMain` `0x80070650`] steps through it: read an opcode, dispatch to one of
67 handlers [`aiFunctionTable` `0x800916E0`] — jump, jump-if-greater, call,
return, "find strongest monster", "find best combination", "play to field",
"end hand phase" — until the script says the turn is done. The scripts differ
per duelist, which is why some opponents fuse aggressively and some never do.
The AI knows the fusion table [`aiCompleteFusion` `func_800727C0`].

### The end

A duel ends when a player's life points reach zero, or when a player must draw
and has no cards left. In the campaign, losing means game over and a retry.
Winning goes to the results screen.

---

## After a duel: rank, starchips, and the dropped card

Every won duel is **scored**. During the duel the game counts how many turns
it took, how many effective attacks you made, how many defensive wins, how
many face-down plays, how many pure magic cards, traps, fusions and equips
in a per-duel statistics record. At the end `calcRankScore` [`func_80021598`]
runs each counter through `rankScoreChange` [`func_80021558`], which walks one
row of the table at `0x801798A8` — five `(threshold, value)` pairs, the first
threshold above the counter supplies the value — and sums them into a single
score. The table is on the disc, in every duelist's block, and it is the same
for all 39. Read out:

| row | counter (record field) | score by counter value | what it counts (reading) |
|---|---|---|---|
| 0 | `+0x00` | <5: +12 · <9: +8 · <29: 0 · <33: −8 · else −12 | turns |
| 1 | `+0x01` | <2: +4 · <4: +2 · <10: 0 · <20: −2 · else −4 | effective attacks |
| 2 | `+0x02` | <2: 0 · <6: −10 · <10: −20 · <15: −30 · else −40 | defensive wins |
| 3 | `+0x03` | <1: 0 · <11: −2 · <21: −4 · <31: −6 · else −8 | face-down plays |
| 4 | `+0x04` | <1: +2 · <4: −4 · <7: −8 · <10: −12 · else −16 | fusions |
| 5 | `+0x05` | <1: +2 · <3: −8 · <5: −16 · <7: −24 · else −32 | equips |
| 6 | `+0x17` (s8) | <9: +15 · <13: +12 · <33: 0 · <37: −5 · else −7 | cards used |
| 7 | `+0x13` (s16) | <100: −7 · <1000: −5 · <7000: 0 · <8000: +4 · else +6 | remaining LP |
| 8 | `+0x07` | <1: +4 · <5: 0 · <10: −4 · <15: −8 · else −12 | magic cards |
| 9 | `+0x08` | same as row 8 | traps |

The thresholds and values are measured; the row-to-counter pairing is read
off the call sites in `calcRankScore`. The *category* names are a reading —
they are the rows of the rank guide the community has published for twenty
years, matched threshold for threshold, and the LP row (100 / 1000 / 7000 /
8000) is unmistakable — but the record's fields are not named in any source
here. The score then becomes a **rank**:

    S-POW   A-POW   B   C   D   A-TEC   S-TEC

**POW** ranks come from winning fast and hard — few turns, few tricks. **TEC**
ranks come from winning with technique — many fusions, equips, traps, and no
wasted cards. The middle ranks are everything else.

The rank decides two rewards. You receive **starchips** [`0x801D07E0`, 4
bytes], more for a better rank. And you receive **one card**, drawn at random
from the beaten duelist's drop pool *for that rank* [`cardDrop`
`func_80021810`, a weighted draw over a table of 722 halfword weights].

The pools live on the disc, in the per-duelist block the duel loader reads
(three sectors at `0x1D33 + 3 × opponent` of `WA_MRG.MRG`, laid out under
*Where the rule tables live*): three tables of 722 × u16 weights, one per
pool, at `+0x5B4`, `+0xB68` and `+0x111C` of the block, which are the runtime
copies' own offsets from `0x801781D8` [`0x8017878C`, `0x80178D40`,
`0x801792F4` — POW, BCD, TEC in that order]. **Every one of the 39 × 3 tables
decodes, and every one sums to exactly 2048**, so the draw is a random number
in 0–2047 walked against cumulative weights. Concrete: Rex Raptor's POW pool
leans on Pumpking the King of Ghosts, Stone D. and Barrel Rock, his TEC pool
on Wasteland, Dark Hole and Barrel Rock; Pegasus's POW pool on Umi, Mystical
Elf and Rogue Doll; Simon Muran's three pools are the same list headed by
Shadow Specter and Time Wizard. Duel Master K drops Roaring Ocean Snake and
B. Dragon Jungle King for POW and BCD, Electro-whip and Cyber Shield for TEC.

**Retracted, from the earlier version of this section.** The block is 6,144
bytes at a 3-sector stride, not 7,056 at a 7,056-byte stride; with the wrong
stride a third of the slots read as garbage, the four final bosses appeared to
have no drops, and Nitemare and DarkNite appeared swapped against the
GameShark record order. All three were artefacts of the stride. With the
game's own arithmetic there are no invalid slots and every one of the 39
blocks has full pools. What the data does show is **duplication**: blocks 0
and 1 (Simon Muran and Teana, by the cheat archives' order) are byte-identical
from deck to rank table, and Seto 3rd's three pools are byte-identical to
Rex Raptor's — so "Seto 3rd drops Pumpking" is true and is a copy. On the
order: the block is indexed by the opponent id `D_8009B361` (measured); the
win/loss records are in the order the cheat archives publish (their claim —
the function that writes a record was not traced here). No swap is *visible*
between the two, and nothing here proves one impossible. Which *name*
belongs to which id is likewise the archives' claim (index 36 Nitemare, 37
DarkNite); the decks do not settle it. The "1216-byte trailer" was the rank
table plus 104 unread bytes.

Also in that block, at `+0`, is what the community calls the opponent's
*deck* — and it is a **fourth weight table**, 722 × u16 summing to 2048, not
a fixed list of 40 cards. The opponent's deck is drawn from a weighted pool,
the same way your drop is. Nitemare's heaviest deck weights are Harpie's
Feather Duster, Blue-eyes White Dragon and Raigeki; Duel Master K's are
Twin-headed Thunder Dragon, Aqua Dragon and Meteor Dragon.

## Cards, the trunk and the Library

You own cards in the **trunk**: one byte per card, 722 of them
[`0x801D0250`], holding how many copies you have. The Library's "seen" flag
lives in that same byte. Your **deck** is a separate list of 40 [`0x801D0200`]
drawn from the trunk.

Of the 722 cards, **621 are monsters, 34 equips, 33 magic, 24 rituals and 10
traps** [counted from the game's own type field]. The 101 non-monsters occupy
three fixed id ranges — 301–350, 651–700 and 721 — which is how the duel code
recognises them.

Every card has a **type**: ids 0–19 are the monster types in the game's own
order — Dragon, Spellcaster, Zombie, Warrior, Beast-Warrior, Beast, Winged
Beast, Fiend, Fairy, Insect, Dinosaur, Reptile, Fish, Sea Serpent, Machine,
Thunder, Aqua, Pyro, Rock, Plant — and 20 Magic, 21 Trap, 22 Ritual, 23 Equip.
**There is no "field" kind**: Forest, Wasteland, Mountain, Sogen, Umi and Yami
are ordinary magic cards (type 20) that happen to set the terrain.

Monsters also carry an **attack**, a **defence**, two **Guardian Stars** and a
**level**; every card has a **password** and a **starchip cost**. The stats
are packed one 32-bit word per card [`0x801D4244`, file `0x1C4A44`: ATK bits
0–8 ×10, DEF bits 9–17 ×10, second star bits 18–21, first star bits 22–25,
type bits 26–30 — read from `baseCardStat` and `monGsBonus`]. Names are a
single 0xFF-delimited text blob in the game's own one-byte encoding
[`0x801D6001`], the level is the low nibble of a byte per card
[`0x801D5332`], and passwords and costs are not in the executable at all —
they are 8-byte records in `WA_MRG.MRG` on the disc (cost, then the password
as reversed BCD).

Guardian Star ids: 1 Mars, 2 Jupiter, 3 Saturn, 4 Uranus, 5 Pluto, 6 Neptune
— the six-cycle — and 7 Mercury, 8 Sun, 9 Moon, 10 Venus — the four-cycle.
Blue-Eyes White Dragon is Sun/Mars, 3000/2500, Dragon, level 8, cost 999999.

**24 cards have no password at all** — a sentinel in place of one — and they
are the fusion-only and story-only cards: Blue-eyes Ultimate Dragon, Gate
Guardian, Black Luster Soldier, Magician of Black Chaos, Cosmo Queen, Dark
Magic Ritual and the like. You cannot buy those; you fuse, ritual or win them.

The **password** system doubles as the shop: every card's eight-digit code is
printed on the real card, and entering it at the Password screen buys the card
for its starchip cost. The strongest cards cost 999,999 starchips, more than a
normal playthrough earns, so passwords are a long-game reward or a cheat.

---

## Free Duel and records

Free Duel lets you replay any duelist you have met. Each duelist has a record
of your wins and losses against them [4 bytes each — wins, then losses —
39 records from `0x801D0720`], displayed on the selection screen. There is no
story reward; you duel for the card drop and the starchips, and Free Duel is
how most players farm the cards they want.

---

## Trade and two-player

With two memory cards, two players can **trade** cards between saves, and can
**duel each other** with their own decks. Both live under the Trade mode.

---

## The save file

One save per memory card slot. It holds the player's name, the campaign
position, the deck [`0x801D0200`], the trunk with Library flags
[`0x801D0250`, 722 bytes], the password-use counter [`0x801D0698`], the Free
Duel unlock bitmask [`0x801D06F4`], the 39 duelist win/loss records
[`0x801D0720`], the last cards dropped [`0x801D07BC`], and the starchips
[`0x801D07E0`]. The game keeps a working copy of this block in memory and
writes it back to the card when you save.

---

## How input reaches the game

Every screen reads the pad the same way, and the chain is fully located. The
PsyQ pad driver fills a buffer [`0x800EF668`, handed to `InitPAD` by
`func_8003CBE8`]. Once per frame `func_8003CC38` [decompiled] folds both pads'
raw button bits into one word [`0x8009B3A8`, pad 1 low, pad 2 high, inverted
from active-low]. Then `func_8003CCD8` derives the words the game actually
reads: **held** [`0x8009B3A4`], **pressed this frame**
[`0x8009B398` = `(now ^ before) & now`], and a repeat word [`0x8009B394`,
inferred]. Thirty-seven functions test buttons against those; the
pressed-this-frame word is the one most of them use.

What is *not* established is a clean button-to-action map per screen: the
mode handlers share input helpers, so static call-reach attributes the same
button set to several modes. That map is a runtime-tracing job — the recomp's
function-entry trace is the right tool — and it is left open here.

## What is unverified

* The score cut-offs that turn the summed rank score into S-POW … S-TEC, and
  the starchip award per rank. The per-event weights are now read (table
  above); the cut-offs and the payout are not.
* The three duel-blob chunks that go to `0x801A8000`, `0x801A9800` and
  `0x80100000`, and the 104-byte tail of the duelist block.
* `0x80168000` is an overlay slot: different menu blobs load different code
  there. The **password-shop overlay** is located — 0x7800 bytes at `+0x20800`
  of the blob at sector `0x1EDF` and again at `+0x23800` of the one at
  `0x1F2F`, byte-identical, placed by `func_8003BA14` — and the three shop
  patch codes verify against it instruction for instruction (see
  `gameshark_codes_list.md`). The overlay the Free Duel unlock patch and the
  two "enable" codes target is a different one, and its guard halfwords
  appear nowhere in `WA_MRG.MRG`, `SU.MRG` or `MODEL.MRG` in raw form (the
  same scanner finds the executable's and the shop overlay's guards), so
  either it is unpacked or generated at run time, or those codes are for
  another build.
* Three duel rules stated above from memory of the game, not from code:
  whether a monster played this turn can attack; whether the game imposes a
  limit on copies of one card in a deck; and whether running out of cards to
  draw loses the duel. Direct attack on an empty field is likewise unread.
* The per-screen button map (see the input section).
* Campaign progression — which duel unlocks which map node — is not mapped
  at all. The AI scripts each duelist runs are not read.
* The full set of magic-card effects and trap triggers.
* Whether monsters in Free Duel two-player use the same AI interpreter (they
  should not; that mode has two human players).
* The story beats are summarised from memory of the game and may compress or
  reorder minor scenes. The *duelist order* is measured; the narrative around
  it is not.
