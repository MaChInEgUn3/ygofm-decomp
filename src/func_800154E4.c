#include "common.h"

void func_800154E4(void) {
    u8 *p;
    u8 *q;
    s32 i;
    s32 n;
    s32 v;
    s32 w;
    s32 x;
    s32 c;
    s32 f;

    q = D_800E9EC8;
    func_80015310(q);

    f = q[6];
    if ((f & 0x80) == 0) {
        if (D_8009B141 == 0) {
            return;
        }
        if (q[4] == 0xFF) {
            return;
        }
    }

    p = (u8 *)0x1F8003C0;
    *(s32 *)(p + 0) = 0x60000000;
    *(s32 *)(p + 8) = 0xF00140;
    *(s32 *)(p + 4) = 0;
    n = D_800E9D94[0];

    if ((f & 1) != 0) {
        *(s16 *)(p + 0xA) = 8;
        i = 0;
        do {
            v = 0xFF - (q + i)[0xA];
            p[0xE] = v;
            p[0xD] = v;
            p[0xC] = v;
            func_80084240(p, n, 4);
            i++;
            *(s16 *)(p + 6) = *(u16 *)(p + 6) + 8;
        } while (i < 0x1E);

        if ((D_800E9ECE[0] & 2) == 0) {
            return;
        }
    }

    c = 4;
    if ((D_800E9ECE[0] & 2) != 0) {
        c = D_8009B140;
        if (c == 0) {
            c = 0x3F;
        }
    }

    w = 0xFF - D_800E9EC8[4];
    p[0xE] = w;
    p[0xD] = w;
    p[0xC] = w;

    if ((D_800E9EC8[6] & 0x10) != 0) {
        x = q[0] - q[4];
        *(s32 *)(p + 0) = 0x50000000;
        if (x < 0) {
            x = 0;
        }
        p[0xC] = x;
        x = q[1] - q[4];
        if (x < 0) {
            x = 0;
        }
        p[0xD] = x;
        x = q[2] - q[4];
        if (x < 0) {
            x = 0;
        }
        p[0xE] = x;
    }

    func_80084240(p, n, c);
}
