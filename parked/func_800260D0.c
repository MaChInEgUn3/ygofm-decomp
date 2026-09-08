/* +1 at 87/88 and 49 differing (2026-09-08, WORK IN PROGRESS; was +4/66).
 * First real C for a function src/ carries as an ASSEMBLY-DEBT transcription
 * (Unchiga's port, whose only asm is `addu %0,%1,%2` for the table index,
 * with `tbl` pinned to $a0 and the index to $v0). gp=11, at=0, default flags.
 *
 * Three facts paid, in order:
 *   - the counter is `D_8009B20C[1]`, not `D_8009B20E`: retail writes
 *     `%gp_rel(D_8009B20C+2)` and the interior symbol reads as two
 *     differences per site. krystalgamer's functions.csv description names it
 *     outright ("advances D_8009B20C[1] on a 16-frame D_8009B1D0 countdown").
 *     66 -> 63.
 *   - the D_800907D8 base is a LOCAL assigned before the D_8009B1D5 read:
 *     retail puts its `lui`/`addiu %lo` in the branch's delay slot and the
 *     load-delay slot, and against the symbol inline both take a `nop`.
 *     +4/63 -> +2/49.
 *   - the row's `+2` halfword is READ INTO A NAME before the +0x14
 *     accumulate, and its store to +4 written last: retail hoists that load
 *     above the `lw`/`addu`/`sw` and sinks the store into the jal's delay
 *     slot. +2 -> +1.
 *
 * Measured and DEAD:
 *   - `counter * 0x3000` instead of `D_8009B20C[1] * 0x3000` is +2 and 88.
 *     Retail reads the global once into $a2 and uses it twice; the local
 *     holding the same value is a different pseudo and costs the whole block.
 *   - a base local for D_80090800, which is the same lever that paid for
 *     D_800907D8: three placements (before the +0x1A store, after it, and
 *     right after the func_8002C604 call) are all +1 and 50, i.e. one worse.
 *     Three identical scores is the wrong-axis tell.
 *
 * What is left is one extra instruction of ours, in the row-address block
 * where retail materialises `%hi/%lo(D_80090800)` straddling the counter and
 * D_8009B1D5 loads. The debt is NOT retired until this matches.
 */
#include "common.h"

s32 func_80024E24(void);

u8 *func_8002C604(s32 arg0);


void func_800260D0(void) {
    s16 counter;
    s32 v;
    s32 n;
    u8 *tbl;
    u8 *rec;
    u8 *marker;
    u8 *row;

    if (func_80024E24() == 0) {
        D_8009B20C[1] = -1;
        D_8009B1D0 = 0;
    }
    D_8009B1D0 -= 1;
    if ((s16)D_8009B1D0 > 0) {
        return;
    }
    D_8009B1D0 = 0x10;
    counter = D_8009B20C[1] + 1;
    D_8009B20C[1] = counter;
    if (counter < 5) {
        tbl = D_800907D8;
        n = D_8009B1D5 * 20 + 10;
        rec = &D_801A7AD8[tbl[counter + n] * 28];
        marker = func_8002C604(8);
        *(s16 *)(marker + 0x1A) = 3;
        row = D_80090800 + ((D_8009B20C[1] + 10) * 4 + D_8009B1D5 * 80);
        *(s16 *)(marker + 2) = 0;
        *(s16 *)marker = *(s16 *)row;
        v = *(u16 *)(row + 2);
        *(s32 *)(marker + 0x14) += D_8009B20C[1] * 0x3000;
        *(s16 *)(marker + 4) = v;
        func_8003FEE0(0x14);
        if ((*(u16 *)(rec + 0x16) & 0x8000) && *(s16 *)(rec + 0x12) < 0) {
            *(s16 *)(rec + 0x12) = 0;
            *(s16 *)(marker + 0x1A) = 5;
        }
    } else {
        D_8009B220 = 0;
    }
}
