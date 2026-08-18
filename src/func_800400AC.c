#include "common.h"

/* Claims slot arg0 and links it at the head of list arg1. Two shapes.
 *
 * The flag word is read into a local BEFORE the D_8009B412 increment, and
 * that one line is the whole function. Written as a test on the memory
 * directly, gcc finishes the increment before the record address even
 * exists and the two independent chains never interleave -- retail issues
 * both loads, then both computations, then the store, and fills the load
 * delay slot with the `addiu`. We got a nop there and 86 differences.
 *
 * The store of -1 at +0 really is written twice on the unlinked path: once
 * in the arm and once in the shared tail, which is two materialisations of
 * -1 in the listing and therefore two writes in the source. */

u8 *func_800400AC(s32 arg0, s32 arg1) {
    u8 *r;
    s32 t;
    s32 f;

    if (arg0 < 0) {
        return (u8 *)0;
    }

    r = (u8 *)&D_800EFE48[arg0];
    f = *(u16 *)(r + 8);
    D_8009B412 = D_8009B412 + 1;

    if ((f & 0x80) == 0) {
        t = *(s16 *)(D_800EFE38 + arg1 * 2);
        if (t < 0) {
            *(s16 *)(D_800F2878 + arg1 * 2) = arg0;
            *(s16 *)(r + 2) = -1;
            *(s16 *)r = -1;
        } else {
            D_800EFE48[t].unk0 = arg0;
            *(s16 *)(r + 2) = *(u16 *)(D_800EFE38 + arg1 * 2);
        }
        *(s16 *)r = -1;
        *(s16 *)(D_800EFE38 + arg1 * 2) = arg0;
        *(s32 *)(r + 4) = 0x8000000;
        *(s16 *)(r + 8) = 0xC0;
        r[0x17] = 2;
        *(s32 *)(r + 0x54) = (s32)D_801AC000;
        r[0x6C] = 0;
        *(s32 *)(r + 0x24) = 0;
        *(s16 *)(r + 0x1E) = arg1;
        r[0xA] = arg0;
        r[0xB] = 0;
        *(s32 *)(r + 0xC) = 0x808080;
        *(s32 *)(r + 0x20) = 0;
        *(s32 *)(r + 0x10) = 0;
        *(s16 *)(r + 0x1C) = 0;
        *(s16 *)(r + 0x1A) = 0;
        *(s16 *)(r + 0x18) = 0;
        r[0x66] = 0;
        *(s32 *)(r + 0x48) = 0;
        *(s32 *)(r + 0x44) = 0x10001000;
        *(s32 *)(r + 0x40) = 0;
        *(s16 *)(r + 0x5E) = 0;
        r[0x65] = 0;
        r[0x16] = 0;
        *(s16 *)(r + 0x14) = D_8009AF74[r[0x17]];
    }

    return r;
}
