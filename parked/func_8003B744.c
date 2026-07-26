/* 18 differing instructions.
 *
 * Two things already found and worth keeping: duplicating the return in each
 * branch (gcc cross-jumps them into retail's shared tail, and the first branch
 * then falls into it as retail does), and computing the index offset *before*
 * naming the table, which is the order retail materialises them in.
 *
 * What is left: retail copies arg1 into $a2 and does the subtraction last, after
 * both the table address and the 0xFFFF0000 mask are formed; we subtract as soon
 * as the constant exists. Inlining the subtraction into the index expression
 * moves it the wrong way (33).
 */
#include "common.h"

s32 func_8003B744(s32 arg0, s32 arg1) {
    u8 *t;
    s32 i;

    if (arg1 > 0xCFFF) {
        i = arg1 - 0xD000;
        t = D_801C0000;

        return ((s32)t & 0xFFFF0000) | *(u16 *)(t + i * 2);
    }

    if (arg1 > 0x7FFF) {
        i = arg1 - 0x8000;
        t = D_801D5800;

        return ((s32)t & 0xFFFF0000) | *(u16 *)(t + i * 2);
    }

    if (arg1 >= 0x500) {
        arg1 -= 0x100;
    }

    return ((s32)D_801B0000 & 0xFFFF0000) | *(u16 *)(D_801C0000 + arg1 * 2);
}
