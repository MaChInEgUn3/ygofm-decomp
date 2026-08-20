#include "common.h"

typedef struct {
    u8 b[8];
} Blk8u;

void func_8004E7B0(s32 arg0) {
    s32 a;
    s32 b;
    s32 v;
    s32 c;
    s32 d;
    s32 e;
    s32 n;
    s32 z;
    s32 r;

    a = *(s16 *)&D_8009B47A - D_8009B482;
    b = *(s16 *)&D_8009B47C - D_8009B484;

    v = a;
    if (v < 0) {
        v = -v;
    }
    if (v >= 0x801) {
        if (a > 0) {
            a -= 0x1000;
        } else {
            a += 0x1000;
        }
    }

    if (arg0 != 0 || a != 0) {
        n = *(u16 *)(D_8009AF88 + 0xA6);
        D_8009AF8E = (a * 0x500 / 384 + D_8009AF8E + n) % n;
    }

    if (arg0 != 0 || b != 0) {
        c = *(s16 *)&D_8009B47C;
        if (c >= 0x801) {
            d = c - 0x1000;
            if (d >= 0) {
                if (d >= 0x400) {
                    r = -0x139;
                    goto store;
                }
            } else {
                if ((0x1000 - c) >= 0x400) {
                    r = -0x139;
                    goto store;
                }
            }
            e = *(s16 *)&D_8009B47C - 0x1000;
            if (e >= 0) {
                r = -(e * 0x1A) / 85;
            } else {
                r = -((0x1000 - *(s16 *)&D_8009B47C) * 0x1A) / 85;
            }
        } else if (c < 0x400) {
            r = (c * 0x1A) / 85;
        } else {
            r = 0x139;
        }
store:
        D_8009AF90 = r;
    }

    *(Blk8u *)&D_8009B480 = *(Blk8u *)&D_8009B478;
}
