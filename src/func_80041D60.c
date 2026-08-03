#include "common.h"

void func_80041D60(u8 *p) {
    u8 *t;
    u8 *q1;
    u8 *q2;
    u8 *q3;
    u8 *q4;
    u8 *q5;
    u32 x;
    s32 v;
    u16 f;
    u16 h;

    f = *(u16 *)(p + 8);
    if ((f & 0x10) == 0) {
        *(u16 *)(p + 8) = f | 0x10;
        *(s16 *)(p + 0x58) = 0;
        *(s16 *)(p + 0x5A) = 1;
        t = *(u8 **)(p + 0x54);
        q1 = t + p[0x67] * 2;
        q2 = t + ((q1[1] << 8) | q1[0]);
        q3 = q2 + p[0x68] * 2;
        q4 = t + ((q3[1] << 8) | q3[0]);
        q5 = q4 + p[0x69] * 2;
        *(u8 **)(p + 0x50) = t + ((q5[1] << 8) | q5[0]);
        x = *(u32 *)(p + 4) & 0xFF7FFFFF;
        *(u32 *)(p + 4) = x;
        if (*(u16 *)(p + 8) & 0x100) {
            *(u32 *)(p + 4) = x | 0x800000;
        }
    } else {
        if (f & 3) {
            return;
        }
        h = *(u16 *)(p + 0x5A);
        if (*(s16 *)(p + 0x5A) == 0) {
            return;
        }
        v = h - *(u16 *)&D_8009B0D8[0];
        *(s16 *)(p + 0x5A) = v;
        if ((s16)v > 0) {
            return;
        }
    }
    func_80041C8C(p);
}
