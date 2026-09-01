# How Forbidden Memories is put together

Written for the use krystalgamer described: so you can tell an agent
*"decompile everything related to Free Duel"* and it can work out what that
means without being handed a function list.

Every number here is measured against `SLUS_014.11` (NTSC-U). Where something
is a reading rather than a measurement it says so.

---

## The shape of the program

Boot runs `gameInit` (`0x80012B50`), then everything else happens inside one
dispatcher, **`mainLoop` at `0x8002DD74`**. It is the only function in the
binary that reads the mode table at `0x80090B64`, and that table has **17
entries** — one per screen or mode. Whatever the game is doing at any moment,
it is inside one of those seventeen.

That makes the mode the natural unit of work. "Everything related to X" is
"everything reachable from mode X's handler".

## The seventeen modes, and what each costs

Reach is every in-scope function reachable from that handler within six call
levels. Modes share a lot of code, so these do not add up to the whole binary.

| mode | handler | reach | matched | remaining |
|---|---|---:|---:|---:|
| `debugMenuLoop` | `func_8002CE08` | 42 | 38 | 4 |
| `animatedBattleLoop` | `func_8002D180` | 176 | 137 | 39 |
| `campaignLoop` | `func_8002CE64` | 68 | 58 | 10 |
| `duelLoop` | `func_8002CEE8` | 198 | 168 | 30 |
| `libraryMenuLoop` | `func_8002D0E0` | 199 | 168 | 31 |
| `campaignOverworldLoop` | `func_8002D2D8` | 39 | 33 | 6 |
| `freeDuelMenuLoop` | `func_8002D3F8` | **32** | **29** | **3** |
| `buildDeckMenuLoop` | `func_8002D370` | 82 | 75 | 7 |
| `mainMenuLoop` | `func_8002D588` | 46 | 41 | 5 |
| `nameEntryLoop` | `func_8002D62C` | 23 | 20 | 3 |
| `passwordMenuLoop` | `func_8002D684` | 23 | 20 | 3 |
| `optionsMenuLoop` | `func_8002D6C8` | 88 | 80 | 8 |
| `gameOverLoop` | `func_8002D730` | 60 | 56 | 4 |
| `hirataLoop` | `func_8002D7C4` | 1 | 1 | 0 |
| `tradeLoop` | `func_8002D7CC` | 89 | 80 | 9 |
| `creditsLoop` | `func_8002DA1C` | 217 | 176 | 41 |
| slot 16 | `func_8002DC38` | 70 | 64 | 6 |

The mode names come from the GMS IDA database; the addresses are ours, paired
by position in the table, and every one matches.

`hirataLoop` is worth one line: its handler is **eight bytes**, `jr $ra; nop`,
and nothing but the mode table references it. krystalgamer identified it as a
debug menu option — a two Blue-Eyes fight — so the feature was cut for retail
and the slot left behind. "hirata" also shows up as an assert path inside the
binary, `src/hirata/H_mctrl1.c`, which turns out to be the **AI interpreter's**
source file: the idb names the two functions that assert from it `aiInstCall`
and `aiInstRetn`.

## Worked example — "everything related to Free Duel"

This is the smallest complete subsystem in the game, which makes it the good
first example.

**Code.** 32 functions reachable from `func_8002D3F8`, of which 29 are already
matched. Three left.

**Data.** Free Duel state lives in the save block:

* `0x801D06F4`–`0x801D06F6` — the unlock bitmask. The cheat that unlocks every
  duelist writes `FFFF` to both halves.
* `0x801D0720` — **duelist records, 39 of them, 4 bytes each**: wins at the
  base, losses at `+2`. Simon Muran is first, Duel Master K is last, and the
  array ends at `0x801D07BC`.
* `0x8009B36C` and `0x8009B390` — runtime state the "glitched duelist" cheat
  reads and writes; `0x8009B390` is also the guard in the take-control cheat,
  so it is a live duel-state flag rather than save data.

**A warning that belongs with the data.** Unchiga found incorrect Free Duel
record codes while building the rematch mod for the recomp, and the published
cheat list does contain two errors that the stride exposes: Simon Muran's
losses address and Villager 3's wins address are both wrong. If you use those
codes as evidence, use the corrected addresses in `gameshark-codes.md`.

## The data structures worth knowing before reading any duel code

**Cards in play — `0x801A7AD8`, records of 28 (`0x1C`) bytes.**
ATK at `+0xE`, DEF at `+0x10`. Ten slots per side: the player occupies records
0–9 and the opponent records 20–29. **53 functions touch this array**, 31 of
them already matched, which makes it the single most load-bearing structure in
the duel code. Our own decompiled sources already index it as
`D_801A7AD8[n * 28]`, and the cheat addresses land exactly on that stride.

**The save block — `0x801D0200` onward.**

| address | size | what |
|---|---|---|
| `0x801D0200` | 0x50 | the player's deck |
| `0x801D0250` | 722 | the trunk: one byte per card, holding the count *and* the seen-in-Library flag |
| `0x801D0534 + 0x164` | | password-use counter |
| `0x801D0534 + 0x1C0` | | Free Duel unlock bitmask |
| `0x801D0534 + 0x1EC` | 156 | the 39 duelist records |
| `0x801D07BC` | | last cards dropped (per Data Crystal) |
| `0x801D07DC + 4` | 4 | starchips |

722 is the card count, and it is worth stating because cheat sources that
publish only 250 codes give the wrong constant.

**Life points — a per-side record at stride `0x20`.** The player's LP are at
`0x800EA004` and the opponent's at `0x800EA024`. Each side also carries the
ticking on-screen figure two bytes below the true value.

**The game's rule tables — and where they really live.**

| table | runtime address | touched by |
|---|---|---|
| fusion | `0x8017C2D8` | 2 functions (1 matched) |
| equip | `0x8017A1D8` | 2 (1) |
| ritual | `0x801799D8` | 4 (1) |
| rank scoring | `0x801798A8` | `rankScoreChange`, `calcRankScore` |
| terrain bonuses | `0x800909D4` | `getTerrainBoost` — an `s8[20][6]`, in the executable |

Only the terrain table is in the executable. **The other four are zero in
`SLUS_014.11` at those addresses** — verified byte by byte, and not an
addressing slip, because the card-stats table at `0x801D4244` decodes exactly
under the same file+0x8000F800 formula. They are loaded from `WA_MRG.MRG` at
runtime, like the duel overlay at `0x80146000`. Their record formats are
known from the code that reads them (see `the-game.md`), so an agent working
on fusion needs the disc, not just the executable.

Those small reader counts are the useful part: the fusion rules are reached
from essentially one place, so "how does fusion work" is a two-function
question, not a subsystem.

## The AI is a virtual machine

This is the part most worth knowing before touching duel code, because it does
not look like the rest of the game.

Each opponent ships a **bytecode script**, and `aiMain` (`0x80070650`)
interprets it. The loop reads one opcode byte, dispatches through
**`aiFunctionTable` at `0x800916E0`** — **67 handlers** — runs it, and stops
when the handler it just ran was one of three specific ones (end-of-hand,
end-of-field, field-play). Every 16th of a second it yields via `VSync`.

The opcode set is a real instruction set: `aiInstJump`, `aiInstJumpGe`,
`aiInstJumpEq`, `aiInstJumpNeq`, `aiInstJumpRand`, `aiInstCall`, `aiInstRetn`,
`aiInstRand`, `aiInstSub`, `aiInstStrongest`, `aiInstBestCombo`,
`aiInstFindFirst`. **62 of the 67 handlers are already matched**, so this
subsystem is nearly closed.

VM state is at `0x800F5BE8` (26 functions touch it, 25 matched); the loaded
script sits at `0x801A8000`.

`aiMain` was identified independently of the naming sources — it is the only
function in the binary that both touches `0x800F5BE8` and contains a `jalr` —
and then read line by line against the idb's decompilation of it. Table index,
indirect call, all three pointer comparisons and the `VSync(1) >= 240` test
match instruction for instruction.

## Two clusters that look scary and are not

**The 9.1 KB function.** `func_8006CD78`, 2319 instructions, is reached only
through a pointer: mode table slot 15 (`creditsLoop`) → `func_8002DA1C` →
`func_80059CE4` → `func_8004EB00` → a 4-entry table at `0x800114E8` →
`func_8006CD78`. It is not a mis-detected merge of several functions: one
prologue, one epilogue, one 296-byte frame.

It is the **credits sequence**, and the measurements agree with that reading
before you know the name — it and `func_8006F1B4` are the two heaviest callers
of `rand()` in the whole binary, 20 and 28 calls where third place has 5, and
they drive GTE perspective transforms through library wrappers.

Those two are also a genuine structural pair: 3-gram similarity 0.392 against
a median of 0.100 for random large-function pairs. The other two entries of
that table are **not** — 0.155 and 0.190, indistinguishable from unrelated
functions. So it is a pair to attack together, not a block of four.

**The sound driver.** Two functions, found by their own strings:
`func_80046768` loads `SD_bgm.dat` / `SD_se.dat` / `MASTER.XA`, and
`func_80046A08` does device and mixer init. The second prints a debug trace
naming `g_SDValue->s_stGlobalHdrSE.s_wSD_NUM_SEGROUP` — which is the same
symbol that appears in Duelist of the Roses, because the same team reused the
driver. That string is also the only place in this binary where the original
naming convention is visible.

## How to use this to scope a task

To take a subsystem:

1. Pick a mode from the table above. Its handler address is the root.
2. Everything reachable from that handler is the code. The remaining column
   says how much is actually left.
3. Cross it with the data structures section — a duel mode means the 28-byte
   card array; a menu mode means the save block.
4. Check `gameshark-codes.md` for addresses in that area. A cheat naming a
   behaviour tells you what a field means, and two of them patch instructions
   and so name functions outright.

## Where each claim comes from

* **Measured here**: every function count, reach figure, address arithmetic,
  stride and structure size. Re-derivable from the listings.
* **From the GMS IDA database** (2018, same binary): the mode names, the AI
  opcode names, `gameInit`, `calcStats`, `checkFusion`, `checkEquip` and about
  460 others. Addresses are ours; paired by address, not by position in a list.
* **From cheat archives**: the field meanings — which byte is LP, which is the
  terrain, which is a duelist's win count. Published claims, tested by whoever
  used the cheat, not verified here except where a code patches an instruction.
* **From Data Crystal**: a handful of RAM annotations, marked UNVERIFIED where
  they appear.
* **Readings, not measurements**: that slot 15 is the credits, that
  `H_mctrl1.c` is the AI's source file, that `+0x67` of a card record is its
  visibility. Each is consistent with everything else, and none is proven.
