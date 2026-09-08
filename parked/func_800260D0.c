/* +2 at 87/89 and 49 differing (2026-09-08, WORK IN PROGRESS). First real C
 * for a function src/ carries as an ASSEMBLY-DEBT transcription (Unchiga's
 * port, whose only asm is `addu %0,%1,%2` for the table index, with `tbl`
 * pinned to $a0 and the index to $v0). gp=11, at=0, default flags.
 *
 * Two facts already paid:
 *   - the counter is `D_8009B20C[1]`, not `D_8009B20E`: retail writes
 *     `%gp_rel(D_8009B20C+2)` and the interior symbol reads as two
 *     differences per site. krystalgamer's functions.csv description names it
 *     outright ("advances D_8009B20C[1] on a 16-frame D_8009B1D0 countdown").
 *     66 -> 63.
 *   - the table base is a LOCAL assigned before the D_8009B1D5 read: retail
 *     puts `lui`/`addiu %lo(D_800907D8)` in the branch's delay slot and the
 *     load-delay slot, and against the symbol inline both slots take a `nop`.
 *     +4/63 -> +2/49.
 *
 * What is left: two more `nop`s of the same kind, and the index `addu` order
 * (`addu $v0,$a1,$v0` then `addu $v0,$v0,$a0` in retail -- counter first,
 * then base). The `(s32)` cast sum spelling is identical to the plain index
 * here (+2/49 both). The debt is NOT retired until this matches.
 */
#include "common.h"

s32 func_80024E24(void);

u8 *func_8002C604(s32 arg0);


void func_800260D0(void) {
    s16 counter;
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
        *(s16 *)marker = *(s16 *)row;
        *(s16 *)(marker + 2) = 0;
        *(s16 *)(marker + 4) = *(s16 *)(row + 2);
        *(s32 *)(marker + 0x14) += D_8009B20C[1] * 0x3000;
        func_8003FEE0(0x14);
        if ((*(u16 *)(rec + 0x16) & 0x8000) && *(s16 *)(rec + 0x12) < 0) {
            *(s16 *)(rec + 0x12) = 0;
            *(s16 *)(marker + 0x1A) = 5;
        }
    } else {
        D_8009B220 = 0;
    }
}
