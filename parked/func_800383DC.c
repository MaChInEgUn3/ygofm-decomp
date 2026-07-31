#include "common.h"

void func_800383DC(u8 *arg0) {
    s32 v = D_8009B32E;
    u8 *tbl;
    s32 off;
    u32 r;
    s8 n;

    if (v > 0xCFFF) {
        tbl = D_801C0000;
        off = -0xD000;
    } else if (v > 0x7FFF) {
        tbl = D_801D5800;
        off = -0x8000;
    } else {
        goto low;
    }
    r = ((u32)tbl & 0xFFFF0000) + *(u16 *)(tbl + (v + off) * 2);
    goto store;
low:
    if (v >= 0x500) {
        v -= 0x100;
    }
    r = ((u32)D_801B0000 & 0xFFFF0000) + *(u16 *)(D_801C0000 + v * 2);
store:
    n = arg0[0x58] + 1;
    arg0[0x58] = n;
    *(u32 *)(arg0 + n * 4) = r;
}
