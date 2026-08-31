# Naming: the scheme, the sources, and why nothing is renamed yet

krystalgamer's framing on 2026-08-31, and it is correct: *"fazer decomp e mt
bonito mas quando todas as funcoes se chamam func_* e praticamente inutil.
atribuir significado semantico isso sim e o trabalho foda."* A build that
reproduces the retail sha1 with 1071 functions called `func_%08X` has proved
something about the compiler and almost nothing about the game.

This file is the reference for fixing that. It has three sources of names, one
measured house style, and one open decision.

## The style, measured rather than eyeballed

Taken from `dotr.c`, Ghidra output for **Duelist of the Roses** with real debug
symbols: 2689 named functions against 265 auto-named. Counting the prefixes:

**Functions — `<Prefix><Module>_<Action>`, PascalCase throughout.**

    SzBattle_Init          SzBattle_Entry        SzBattle_DrawStage_Pipe
    SzColor_RGB2HLS        RhBase_FlipBuffer     RhBase_AssignRenderFrame
    lRhBase_InitGsAndVif   lRhFile_CdCallback    SD_BGMFadeOut

  * `Sz` (661), `Ta` (702), `Rh` (110), `Lk`, `Sh`, `Ex`, `RF` — subsystem
    prefixes. `Sz` is the game layer, `Rh` the renderer, `SD` the sound driver.
  * a leading lowercase **`l`** marks a file-local one: `lRhBase_*` sits beside
    `RhBase_*` and is the static half of the same module.
  * `sce*` (292) is Sony's SDK and is not the team's naming at all.

**Variables — scope letter, then type letter, then PascalCase.**

    g_SDValue      g_SDBuffer     g_vec_temp     g_aqwExDitherMatrix
    s_iUsingNow    s_iHowManyTimesCDAreUsed

  * `g_` global, `s_` static or struct member.
  * then a type hint: `i` int, `w` word, `st` struct, `a` array
    (`aqw` = array of quadwords).

**This is confirmed from inside our own binary, which is what makes it usable
rather than borrowed.** The debug trace at `func_80046A08` prints
`g_SDValue->s_stGlobalHdrSE.s_wSD_NUM_SEGROUP` — global, struct member, word
member, exactly the scheme above. The same team wrote both games and reused
the sound driver.

## The three sources, in descending evidentiary weight

**1. `config/names_gms.txt` — 464 names, from the GMS IDA database.** Same
binary, so the addresses are ours. Read `python-idb` out of `SLUS_014.idb`.
Seven of them (the AI VM) are marked VERIFIED: `func_80070650` was found here
independently and read instruction-for-instruction against the idb's
`aiMain()`. Cross-checked once more against an unrelated source —
`checkFusion` reaches `D_8017C2D8`, which Data Crystal documents as the fusion
table. **The idb author's own `myst_sub_XXXX` / `u_myst_sub_XXXX` placeholders
are not names and are commented out**; krystalgamer said to ignore them and
they are ignored.

**2. Data Crystal's RAM map — 11 annotations, already in `include/variables.h`**
as `/* Data Crystal RAM map, UNVERIFIED: ... */`. A wiki, so a hypothesis; it
earns its place by having been right where it overlapped the idb.

**3. `dotr.c` — style, and shared symbols only.** DoTR is **PlayStation 2** and
this is PlayStation 1: `AddDmacHandler`, `audioDecSendToIOP`, EE/IOP/SIF. No
function here can be matched to a function there, and an earlier plan to point
`tools_src/siblings.py` across the two is void — instruction n-grams do not
cross a CPU generation. What transfers is the scheme above and the specific
symbols the team reused, of which the sound driver is the demonstrated case
(48 `SD_*` entry points; `g_SDValue` appears 304 times).

A fourth is worth trying and has not been: **the recomp**. Unchiga's native
port had to reproduce behaviour to run, so its own naming is behavioural
evidence about functions nobody has read.

## The open decision: nothing is renamed, and that is deliberate for now

Every tool here, every `docs/PARKED.txt` entry and every paragraph of
`docs/WORKFLOW.md` is keyed to `func_%08X` / `D_%08X`. The address form is the
one thing that cannot be wrong, and during matching that property is worth
more than readability: a name that is subtly wrong outlives the reading that
produced it, and a wrong name in a comment is worse than no name.

So names live in `config/*.txt` as annotation. That is the right posture while
the build is still the only oracle — and it is **not** a permanent answer,
because krystalgamer's point stands: at the end, a decomp nobody can read has
not finished. The migration is a separate, mechanical step (the mapping is
already a file), and it should happen once matching is done, not during.
