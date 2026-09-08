/* -1 at 224/225 (2026-09-08). THE FIRST REAL C THIS FUNCTION HAS EVER HAD.
 * src/func_80018608.c is an ASSEMBLY-DEBT transcription whose instructions
 * are written as `.word`, and `git log --all -- parked/func_80018608.c` is
 * empty, so nothing was thrown away here -- it had simply never been
 * attempted. Written from the m2c draft plus the listing in one pass.
 * gp=15, at=0, so default flags; three symbols are read `%hi`/`%lo` while
 * fifteen gp-relative accesses remain, which rules out `as -G0` and makes
 * the `.data` arms the only route: D_8009B0F4, D_8009B134 and D_8009B36A.
 *
 * Shape: an init guard on D_8009B23A's 0x8000 bit, then a comparison TREE
 * (not a jump table -- four cases, range 4, below gcc 2.8's threshold) on
 * `D_8009B174 & 0x1F` with cases 2, 3, 4 and 5 in address order. Case 4 runs
 * two identical 40-iteration loops over the 6-byte records of D_801A7E20,
 * the second starting at +0xF0, each summing two 9-bit fields of
 * D_801D4244[rec - 1] times ten and storing the sums divided by 40 (the
 * 0x66666667 reciprocal with `sra 4`).
 *
 * THE CENSUS IS THE WHOLE DIAGNOSIS and the difference count is useless
 * here: `lw` and `sw` are both -2 and everything else is within one. Retail
 * saves FOUR callee-saved registers -- $s0 for the mode, $s1 for
 * D_800F2848's full address, $s2 for its `%hi` half, $s3 for the constant 3
 * -- and we save two. Every remaining difference is downstream of that.
 *
 * The named constant 3 (`three = 3;` before the guard, used for both
 * `D_8009B174 = 3` in case 2 and `D_8009B23A = 3` in case 5) buys one of the
 * two: -2 to -1. Retail materialises 3 once, in the dispatch tree's own
 * `beq`, and keeps it to the end.
 *
 * Measured and DEAD, all worse: a `u8 *f = D_800F2848;` base local hoisted
 * above the guard and used everywhere (+2/108), the same with the named 3
 * (+3/220), the local scoped to case 2 only (+3/224), and scoped to the
 * entry branch only (+3/224). The base local is ONE register and retail
 * wants TWO -- the `%hi` half in $s2 and the full address in $s1, with the
 * `[0]` store going through `%lo(D_800F2848)($s2)` and the others through
 * `N($s1)`. No source spelling tried produces that pair, and the local
 * overshoots by three where the gap is one.
 * That is the open question: what makes gcc keep BOTH halves of one
 * address in callee-saved registers across a function.
 */
#define D_8009B0F4_IN_DATA
#define D_8009B134_IN_DATA
#define D_8009B36A_IN_DATA
#include "common.h"

void func_80018608(void) {
    s32 mode;
    s32 three;
    u8 *e;
    u8 *g;
    s32 i;
    s32 j;
    s32 sa;
    s32 sb;
    s32 w;
    s32 h;

    three = 3;
    if ((D_8009B23A & 0x8000) == 0) {
        D_8009B23A |= 0x8000;
        func_80024734();
        *(s16 *)D_800F2848 = 0x4B0;
        *(s16 *)(D_800F2848 + 4) = 0x358;
        *(s16 *)(D_800F2848 + 2) = 0x16C0;
        func_8001352C();
        D_8009B174 = 2;
        func_800157DC();
        return;
    }

    mode = D_8009B174 & 0x1F;
    switch (mode) {
    case 2:
        *(s16 *)D_800F2848 = *(s16 *)D_800F2848 - 2;
        h = *(u16 *)(D_800F2848 + 2) - 0x10;
        *(s16 *)(D_800F2848 + 2) = h;
        *(s16 *)(D_800F2848 + 4) = *(s16 *)(D_800F2848 + 4) - 2;
        if ((s16)h < 0x401) {
            *(s16 *)D_800F2848 = 0x258;
            *(s16 *)(D_800F2848 + 4) = 0x100;
            *(s16 *)(D_800F2848 + 2) = 0x400;
            D_8009B174 = three;
        }
        func_8001352C();
        return;

    case 3:
        if ((D_8009B174 & 0x80) == 0) {
            D_8009B174 |= 0x80;
            D_8009B162 = 2;
            e = &D_800E9F10[D_8009B1D5 * 0x70];
            D_8009B1B4 = e;
            *(s16 *)(e + 0xC) = 0xAE;
        }
        if (D_8009B162 == 0) {
            D_8009B174 = 4;
        }
        return;

    case 4:
        if (((D_8009B0F4 & 0x2000030) | D_8009B134) == 0) {
            func_8003FF08(D_8009B36A);
            func_80024824();
            sa = 0;
            sb = 0;
            g = D_801A7E20;
            i = 0;
            do {
                i += 1;
                j = *(s16 *)g;
                j = j - 1;
                w = D_801D4244[j];
                sa += (w & 0x1FF) * 10;
                sb += ((w >> 9) & 0x1FF) * 10;
                g += 6;
            } while (i < 0x28);

            sa = sa / 40;
            sb = sb / 40;
            *(s16 *)((u8 *)D_800E9FF0 + 0xE) = sa;
            *(s16 *)((u8 *)D_800E9FF0 + 0x10) = sb;

            sa = 0;
            sb = 0;
            g = D_801A7E20 + 0xF0;
            i = 0;
            do {
                i += 1;
                j = *(s16 *)g;
                j = j - 1;
                w = D_801D4244[j];
                sa += (w & 0x1FF) * 10;
                sb += ((w >> 9) & 0x1FF) * 10;
                g += 6;
            } while (i < 0x28);

            D_8009B174 = 5;
            *(s16 *)((u8 *)D_800E9FF0 + 0x2E) = sa / 40;
            *(s16 *)((u8 *)D_800E9FF0 + 0x30) = sb / 40;
        }
        return;

    case 5:
        func_800176D0();
        D_8009B1EC = mode;
        D_8009B23A = three;
        *(s32 *)(&D_800E9F10[D_8009B1D5 * 0x70] + 8) = (s32)D_800EA030;
        return;
    }
}
