/* -12 at 197/209 (2026-09-08). FIRST C for this function, written from the
 * m2c draft in one pass. NOT a debt -- src/31D8.c still has the INCLUDE_ASM,
 * so a MATCH here is a NEW function and +1 on the honest count.
 *
 * MEASURE IT WITH `as -G0`: there is no build.py row yet, so use
 *   echo '{"func_800577B0": {"as": "-G0"}}' > config/flag_overrides.json
 * and DELETE the file afterwards. At the default assembler this is -30; at
 * -G0 it is -12. gp=0 and six `lui $at` stores of D_8009B0F4, which is the
 * recipe's first branch -- no %gp_rel to lose, so any -G is free -- and
 * because the fix is the ASSEMBLER's -G rather than `-mno-split-addresses`,
 * the function's jump table (jtbl_8001179C) survives. WORKFLOW calls that
 * combination the narrow sweet spot and this is a clean instance of it.
 *
 * Shape: a `switch (mode)` over 0..10 with a real jump table (`sltiu $v0,
 * $a1,0xB` then `lui %hi(jtbl_8001179C)`), and it is the D_8009B0F4
 * dispatcher family -- the most heavily documented shape in WORKFLOW, with
 * `&= 0xFFDCFFFF` / `|= 0x10000` arms, shared tails reached by `goto`, and
 * three arms that fall into two join blocks.
 *
 * CENSUS at -12: `lui -5, lw -3, sw -3, ori -3, addiu -1, sh +1, addu +1,
 * nop +1`. The `lw -3` and `sw -3` agree and are the whole diagnosis: retail
 * saves THREE more callee-saved registers than we do. Its prologue is
 * `addiu $sp,-0x30` with $s2, $ra, $s1, $s0 -- our frame is already 0x30 --
 * and the roles are legible: $s2 holds the `p` parameter copied in the
 * prologue and live across every arm, and $s0 holds D_800F2C40 for case 10's
 * store group. The `lui -5` and `ori -3` follow: retail materialises
 * addresses per use where we CSE them into the parameter's own register.
 *
 * So the first lever to try is the func_8005CEF0 family -- whether `p` wants
 * a name, a copy, or to be written inline at every use -- and after that a
 * base local for D_800F2C40 in case 10.
 * Two globals were declared for this: D_80010014 and D_80010018, pointer
 * entries in the same table as D_80010000.
 */
#define D_8009B0F4_IS_SCALAR
#include "common.h"

void func_8005B620(s32 *dst, s32 *src, s32 n);
void func_80081DE8(s16 *arg0, u8 *arg1);

void func_800577B0(u8 *p, s32 mode) {
    s16 sp[8];
    u8 *b;
    s32 v;
    s32 w;

    switch (mode) {
    case 0:
        *(s32 *)(p + 0x1C) = 0x30000;
        b = D_80010000;
        v = D_8009B0F4 & 0xFFDCFFFF;
    m0:
        D_8009B0F4 = v;
        *(s32 *)(p + 0xC) = (s32)b;
        *(s32 *)(p + 8) = (s32)b;
        p[0x46] = 1;
        return;

    case 1:
        *(s16 *)(p + 0x32) = 0x100;
        *(s16 *)(p + 4) = 0x40;
        *(s16 *)(p + 6) = 0x10;
        D_8009B0F4 &= 0xFFDDFFFF;
        *(s16 *)(p + 0x30) = 0;
        D_8009B0F4 |= 0x10000;
        p[0x46] = 2;
        w = 0x30000;
    m1:
        *(s32 *)(p + 0x1C) = w;
        *(s32 *)(p + 8) = D_8009B118;
        *(s32 *)(p + 0xC) = D_8009B118 + 0x800;
        return;

    case 2:
        *(s32 *)(p + 0xC) = (s32)D_801DD000;
        *(s32 *)(p + 8) = (s32)D_801DD000;
        w = 0x1000;
    m2:
        *(s32 *)(p + 0x1C) = w;
        D_8009B0F4 &= 0xFFDCFFFF;
        p[0x46] = 1;
        return;

    case 3:
        sp[1] = 0xF8;
        sp[2] = 0x100;
        sp[0] = 0;
        sp[3] = 8;
        func_80081DE8(&sp[0], D_801DD000);
        *(s32 *)(p + 0x1C) = 0x5000;
        b = D_80010014;
        v = D_8009B0F4 & 0xFFDCFFFF;
        goto m0;

    case 4:
        *(s32 *)(p + 0x1C) = 0x5000;
        b = D_80010018;
        v = D_8009B0F4 & 0xFFDCFFFF;
        goto m0;

    case 6:
        sp[4] = 0x100;
        sp[5] = 0xF0;
        sp[6] = 0x100;
        sp[7] = 2;
        func_80081DE8(&sp[4], D_801DD000);
        *(s16 *)(p + 0x30) = 0x180;
        *(s16 *)(p + 4) = 0x40;
        *(s16 *)(p + 6) = 0x10;
        D_8009B0F4 &= 0xFFDDFFFF;
        *(s16 *)(p + 0x32) = 0x100;
        D_8009B0F4 |= 0x10000;
        p[0x46] = 2;
        w = 0x4000;
        goto m1;

    case 7:
        b = D_801A8000;
    m3:
        *(s32 *)(p + 0xC) = (s32)b;
        *(s32 *)(p + 8) = (s32)b;
        w = 0x800;
        goto m2;

    case 8:
        p[0x46] = 3;
        *(s16 *)(p + 0x30) = 0xD810;
        *(s32 *)(p + 0x1C) = 0x19000;
        *(s32 *)(p + 8) = D_8009B118;
        *(s32 *)(p + 0xC) = D_8009B118 + 0x800;
        return;

    case 5:
    case 9:
        b = D_801DD000;
        goto m3;

    case 10:
        func_8005B620((s32 *)(D_800F2C40 + 0xBF8), (s32 *)D_801DD000, 0x40);
        *(s32 *)(D_800F2C40 + 0xCF8) = *(s32 *)(D_801DD000 + 0x100);
        *(s32 *)(D_800F2C40 + 0xCFC) = *(s32 *)(D_801DD000 + 0x104);
        *(s32 *)(D_800F2C40 + 0xD00) = *(s32 *)(D_801DD000 + 0x108);
        *(s32 *)(D_800F2C40 + 0xD04) = *(s32 *)(D_801DD000 + 0x10C);
        *(s32 *)(D_800F2C40 + 0xD08) = *(s32 *)(D_801DD000 + 0x110);
        *(s32 *)(D_800F2C40 + 0xD0C) = *(s32 *)(D_801DD000 + 0x114);
        *(s32 *)(D_800F2C40 + 0xD10) = *(s32 *)(D_801DD000 + 0x118);
        *(s32 *)(D_800F2C40 + 0xD08) = -1;
        *(s32 *)(D_800F2C40 + 0xD0C) = -1;
        *(s32 *)(D_800F2C40 + 0xD10) = -1;
        *(s16 *)(D_800F2C40 + 0xCF8) = 0;
        *(s16 *)(D_800F2C40 + 0xCFA) = 0;
        D_800F2C40[0xE14] = 1;
        return;
    }
}
