/* 49/49 and 19 differing (2026-09-08). FIRST REAL C for this function: src/
 * holds an ASSEMBLY-DEBT transcription (Unchiga's port) with three register
 * pins -- s2, s0 and a "deadS1" -- and an `asm("addiu %0, %1, 0x5b98")` block
 * materialising D_800F5B98's address through $v0. None of that is needed.
 * The function only became visible as debt on 2026-09-08, when asm_debt.py
 * was taught the three asm spellings it could not see.
 *
 * What the pins were hiding: `$s1` is not dead, it is `lookupB` -- the target
 * loads it, tests it with `bnez` and adds it -- and the address block is
 * cc1psx's OWN split pair, which an unsized `extern s32 D_800F5B98[];` at
 * default flags emits by itself (gp=0, at=0, so no addressing work at all).
 *
 * Two levers found, in order:
 *   - D_800917F0 is read `lb`, and variables.h declares it `u8`. The lvalue
 *     cast `*(s8 *)&D_800917F0[i]` is +2/31 -> -1/15 by itself.
 *   - the `+ 1` folds into `%lo(D_800917F0+1)` against the symbol, where
 *     retail keeps `%lo(D_800917F0)` and puts the 1 in the load's own
 *     displacement. A NAMED index blocks the fold, and the two arms want
 *     DIFFERENT spellings: arm 1 the displacement form
 *     `((s8 *)&D_800917F0[valA * 9])[1]`, arm 2 the named `n = valA * 9 + 1`.
 *     Both arms folded is -1/15; both named is +2; the name only in the else
 *     arm is +2; `n = valA * 9` without the +1 is 49/49 and 24; the split
 *     above is 49/49 and 19.
 * A base local for the byte table is +2/31 -- the opposite of what the
 * base-local rule usually buys, because here the symbol is what retail keeps.
 *
 * Residue: retail computes NOTHING before the branch except the idxC shift
 * (`bne $s1,$zero` with `sll $a0,$v0,2` in the delay slot) and we hoist `n`.
 * Writing `n` inside the arm that needs it is +2 in three spellings, so the
 * hoist is buying two instructions elsewhere and the axis is not closed.
 * Permuter next. The debt is NOT retired until this matches.
 *
 * 2026-09-08, fifteen more, and the +2 in the entry above is MISATTRIBUTED.
 * It is not the cost of naming the index inside the arm. Reading the built
 * listing: with per-arm names gcc STILL hoists `sll $s0,3 / addu $s0`
 * (valA * 9) above the branch -- CSE puts it at the dominator whatever the
 * source says -- and what actually duplicates is the DESTINATION shift,
 * `sll $a0,$a0,2`, which appears in both arms plus a copy where retail has
 * one `sll $a0,$v0,2` in the bnez's own delay slot. Three per-arm spellings
 * (one shared name, two names, the +1 split in two statements) are all
 * +2/32, which is rule 7's tell: one regression wearing three hats.
 * Hoisting only the destination shift as a byte offset -- `off = idxC * 4;`
 * with the arms storing through `*(s32 *)((u8 *)tbl + off)` -- is +2/30
 * with per-arm names, +1/31 with both arms inline, and 49/49 and 22 with
 * the installed hoisted `n`. So it is not the lever either.
 * And the arm-1 fold is not the lever: `%lo(D_800917F0+1)` against retail's
 * `%lo(D_800917F0)` plus `lb 1(...)` survives four spellings that should
 * each break it -- `*(s8 *)((u8 *)D_800917F0 + valA * 9 + 1)`, a `s8 *`
 * pointer local read as `q[1]`, `((s8 *)D_800917F0)[valA * 9 + 1]`, and
 * `*(s8 *)(&D_800917F0[valA * 9] + 1)` -- all 49/49 and 19.
 * The mechanism, stated so the next pass does not re-derive it: retail
 * computes valA * 9 TWICE, once per arm, and hoists nothing but the
 * destination shift. gcc computes it once at the dominator from every
 * source shape tried, so what is needed is something that stops the CSE,
 * not something that moves the statement.
 *
 * 2026-09-08, with the difflib ALIGNMENT: the residue is FOUR blocks, and
 * they say it precisely. We compute `valA * 9` and the destination shift
 * before the branch (`addu $a0,$v0,$zero` / `sll $s0,3` / `addu`) where
 * retail has only `sll $a0,$v0,2` in the bnez's delay slot, and we fold the
 * +1 into `%lo(D_800917F0+1)` where retail computes `sll/addu/addiu 1`
 * inside arm 2. So retail hoists ONE instruction and we hoist four.
 * The combination rule 17 asks for -- the destination offset hoisted as
 * `off = idxC * 4;` AND the index written inside each arm, which had never
 * been measured together -- is +2/30, +2/29 with arm 1 inline, +1/31 with
 * both arms inline, and +2/32 with the index only in arm 2. All worse than
 * the installed 49/49 and 19, so the four-block residue stands.
 */
#include "common.h"

void func_800734DC(void) {
    s32 *tbl;
    s32 valA;
    s32 lookupB;
    s32 idxA;
    s32 idxB;
    s32 idxC;
    s32 n;

    tbl = D_800F5B98;
    idxA = func_8007058C();
    valA = tbl[idxA];
    idxB = func_8007058C();
    lookupB = tbl[idxB];
    idxC = func_8007058C();
    n = valA * 9 + 1;
    if (lookupB == 0) {
        tbl[idxC] = ((s8 *)&D_800917F0[valA * 9])[1] * 100;
    } else {
        tbl[idxC] = *(s8 *)&D_800917F0[lookupB + n];
    }
}
