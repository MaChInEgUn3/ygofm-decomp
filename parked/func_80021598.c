/* 29 differing at 158/158 with an EMPTY opcode census (2026-09-05); the
 * previous 27 carried `addiu +1, addu -1`, so by the (length, census,
 * differences) rule this is the closer candidate even though the count is
 * two higher. One edit: `e = f;` before `t[16] = f[6];` and the read through
 * `e` -- a borrowed name whose live range resumes later. Found by
 * score_permuter_outputs.py in a stored output. Stream alignment 156/158
 * against 157/158, so it is a trade, and it is written down as one.
 */
#include "common.h"

void func_80021598(void) {
    u8 *p;
    u8 *e;
    u8 *f;
    s32 *t;
    s32 k;
    u8 **fp;
    s32 v;

    fp = &f;
    e = (u8 *)D_800E9FF0;
    p = D_8009B1E8;
    p[0x34] = 0x44;
    p[0x35] = 0x40;
    p[0x36] = 0x45;
    t = D_801D5608;

    if (*(s8 *)(e + D_8009B165 * 0x20) == 0x28) {
        p[0x35] = 0x42;
    }
    k = 0;
    if (*(s8 *)(e + D_8009B165 * 0x20) == -0x28) {
        p[0x35] = 0x41;
    }

    f = e + 1;
    *(s32 *)(p + 0x30) = 0x32;
    *(s32 *)(p + 0x2C) = 0x32;

    do {
        *(s32 *)(p + 0x2C) = *(s32 *)(p + 0x2C) + *(s8 *)e;

        v = *(s8 *)(f + 0x17);
        t[0] = v;
        *(s32 *)(p + 0x2C) = *(s32 *)(p + 0x2C) + func_80021558(6, v);

        v = *(s16 *)(f + 0x13);
        t[2] = v;
        *(s32 *)(p + 0x2C) = *(s32 *)(p + 0x2C) + func_80021558(7, v);

        t[4] = *(s16 *)(f + 0xD);
        t[6] = f[0xA];

        v = f[1];
        t[8] = v;
        *(s32 *)(p + 0x2C) = *(s32 *)(p + 0x2C) + func_80021558(1, v);

        t[10] = *(s16 *)(f + 0xF);
        t[12] = f[0xB];

        v = f[2];
        t[14] = v;
        *(s32 *)(p + 0x2C) = *(s32 *)(p + 0x2C) + func_80021558(2, v);

        e = f;
        t[16] = e[6];

        v = f[3];
        t[18] = v;
        *(s32 *)(p + 0x2C) = *(s32 *)(p + 0x2C) + func_80021558(3, v);

        v = f[7];
        t[20] = v;
        *(s32 *)(p + 0x2C) = *(s32 *)(p + 0x2C) + func_80021558(8, v);

        v = f[8];
        t[22] = v;
        k++;
        *(s32 *)(p + 0x2C) = *(s32 *)(p + 0x2C) + func_80021558(9, v);

        e += 0x20;
        t[24] = f[9];

        v = f[4];
        t[26] = v;
        *(s32 *)(p + 0x2C) = *(s32 *)(p + 0x2C) + func_80021558(4, v);

        v = f[5];
        t[28] = v;
        *(s32 *)(p + 0x2C) = *(s32 *)(p + 0x2C) + func_80021558(5, v);

        v = f[0];
        f += 0x20;
        t[30] = v;
        *(s32 *)(p + 0x2C) = *(s32 *)(p + 0x2C) + func_80021558(0, v);

        t++;
        p += 4;
    } while (k < 2);
}
