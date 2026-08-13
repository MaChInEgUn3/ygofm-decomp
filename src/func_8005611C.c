#include "common.h"

/* Three shapes, all in the preheaders. The 0x1000 stores are written next
 * to the 0x800 ones so the constant stays live in its own register across
 * the 0x80/7/8/0xFF run that follows -- written where the stores are
 * emitted it shares $v0 with them and every register downstream rotates
 * (24 differences). The first loop's cursor is `p + i` with i already
 * named, not `p + 3`, or gcc folds the addiu and never emits retail's
 * addu. And the stored 1 is a local assigned BEFORE the counter: the same
 * three preheader instructions come out in the target's order only that
 * way, with the name after the counter it is two differences. */

void func_8005611C(s32 arg0) {
    u8 *p;
    u8 *q;
    s32 i;
    s32 n;

    p = D_800F2C40 + arg0 * 3616;
    func_8005B5FC(p, 0, 0x388);

    *(s32 *)(p + 0xDA8) = 0x800;
    *(s32 *)(p + 0xDA4) = 0x800;
    *(s32 *)(p + 0xDA0) = 0x800;
    *(s32 *)(p + 0xDB8) = 0x1000;
    *(s32 *)(p + 0xDB4) = 0x1000;
    *(s32 *)(p + 0xDB0) = 0x1000;
    p[0xDC2] = 0x80;
    p[0xDC1] = 0x80;
    p[0xDC0] = 0x80;
    p[0xE0C] = 7;
    p[0xE0D] = 8;
    p[0xE14] = 0xFF;
    p[0xDC3] = 0;
    *(s16 *)(p + 0xE0A) = 0x1000;
    p[0xE1D] = 0;
    p[0xDFE] = arg0;
    p[0xDFF] = 0;
    *(u16 *)(p + 0xDFC) = 0xFFFF;
    *(u16 *)(p + 0xDFA) = 0xFFFF;

    n = 1;
    i = 3;
    q = p + i;
    for (; i >= 0; q--, i--) {
        q[0xBF4] = n;
    }

    for (i = 0; i < 0x40; i++) {
        *(s32 *)(p + i * 4 + 0xBF8) &= 0x8000FFFF;
        p[i * 4 + 0xBF9] = 0;
        p[i * 4 + 0xBF8] = 0;
    }

    *(s32 *)(p + 0xD08) = -1;
    *(s32 *)(p + 0xD0C) = -1;
    *(s32 *)(p + 0xD10) = -1;
    p[0xE16] = 0x3E;
    p[0xE1F] = 0;
    func_80059134(arg0);
}
