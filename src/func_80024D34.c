#include "common.h"

void func_80024D34(s32 arg0) {
    s32 **slot = (s32 **)func_800249E0();
    s32 i = arg0;
    u8 *p;
    u8 *b;
    u8 *g;
    s16 *q;
    s16 *t;

    if (arg0 & 0x80) {
        i = (arg0 & 0x7F) + 0xF;
    }

    b = D_8015C424;
    g = b + i * 28 + 0x48000;
    p = *(u8 **)(g + 0x36B8);
    t = D_800908A0;
    q = &t[i * 2];
    *slot = (s32 *)func_80024C1C(*(s16 *)p, q[0], q[1]);
    ((u8 *)*slot)[0x6A] = i;
}
