#include "common.h"

void func_80021894(s32 arg0) {
    u8 *base = D_801D0200;
    s32 idx = arg0 + 0x4F;
    u8 *p = base + idx;
    u8 *hist;
    u16 *q;
    s32 i;
    u32 v;

    v = *p + 1;
    *p = v;
    hist = base + 0x5BC;
    if ((v & 0xFF) >= 0xFB) {
        *p = 0xFA;
    }
    i = 0xE;
    q = (u16 *)(base + 0x5D8);
    do {
        q[1] = q[0];
        i--;
        q--;
    } while (i >= 0);
    *(s16 *)hist = arg0;
}
