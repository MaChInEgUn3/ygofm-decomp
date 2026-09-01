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

— and when a monster attacks or is attacked, if its chosen star beats the
other monster's, it gets **+500** to attack and defence for that battle
[`gsBonus` `func_8002CB80`, `monGsBonus` `func_8001EE44`]. Choosing the right
star is the moment-to-moment skill of the game.

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
`func_8002497C`, table at `0x800909D4`]. Terrain persists until another field
card replaces it.

### Magic, traps, equips

A magic card played from the hand takes effect immediately and is discarded.
The effects are few and fixed: destroy all monsters, destroy monsters of a
type, raise or lower attack, change terrain, and so on.

An **equip** card is played onto one of your monsters and raises its stats —
but only if that equip is valid for that monster, which is another hidden
table [`equipTable` `0x8017A1D8`, checked by `checkEquip` `func_80019A08`].
An invalid equip is wasted.

A **trap** is placed face down in a magic/trap zone and triggers on the
opponent's action — an attack of a certain strength, a magic card. Traps in
this game are automatic; there is no choosing when to spring them.

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

### Rituals

Three specific monsters on your field plus the matching ritual magic card
summon a ritual monster [`ritualData` `0x801799D8`, `checkRitual`
`func_8002C7E8`]. Rare in practice.

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
[each event feeds `rankScoreChange` `func_80021558`, values from a table at
`0x801798A8`; the running score at `0x80179A04`]. At the end those become a
single score [`calcRankScore` `func_80021598`] and a **rank**:

    S-POW   A-POW   B   C   D   A-TEC   S-TEC

**POW** ranks come from winning fast and hard — few turns, few tricks. **TEC**
ranks come from winning with technique — many fusions, equips, traps, and no
wasted cards. The middle ranks are everything else.

The rank decides two rewards. You receive **starchips** [`0x801D07E0`, 4
bytes], more for a better rank. And you receive **one card**, drawn at random
from the beaten duelist's drop pool *for that rank* [`cardDrop`
`func_80021810`; pools at `0x8017878C` POW, `0x80178D40` BCD, `0x801792F4`
TEC]. Each duelist has three pools, and the good cards are usually in S-TEC or
S-POW — which is why players learn to win *in a particular way* against a
particular opponent. A community cheat that forces S-TEC every time patches
the very function that computes the rank.

---

## Cards, the trunk and the Library

You own cards in the **trunk**: one byte per card, 722 of them
[`0x801D0250`], holding how many copies you have. The Library's "seen" flag
lives in that same byte. Your **deck** is a separate list of 40 [`0x801D0200`]
drawn from the trunk.

Cards have a **type** (Dragon, Spellcaster, Zombie, Warrior, Beast-Warrior,
Beast, Winged Beast, Fiend, Fairy, Insect, Dinosaur, Reptile, Fish, Sea
Serpent, Machine, Thunder, Aqua, Pyro, Rock, Plant, plus Magic, Trap, Equip,
Ritual, Field), an **attack** and **defence**, two **Guardian Stars**, a
**level**, a **password**, and a **starchip cost**. The static per-card data is
loaded into a runtime table [`0x801D4244`].

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

## What is unverified

* The exact scoring weights that produce each rank, and the exact starchip
  award per rank. The functions and tables are located; their contents have
  not been read.
* The full set of magic-card effects and trap triggers.
* Whether monsters in Free Duel two-player use the same AI interpreter (they
  should not; that mode has two human players).
* The story beats are summarised from memory of the game and may compress or
  reorder minor scenes. The *duelist order* is measured; the narrative around
  it is not.
