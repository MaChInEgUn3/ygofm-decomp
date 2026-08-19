#include "common.h"

void func_80025F3C(void) {
    u8 *p;
    u8 *r;
    u8 *e;
    s32 f;
    s32 i;
    s32 n;

    if (func_80024E24() == 0) {
        p = func_8002C604(0x15);
        D_8009B17C = p;
        D_8009B1F0[D_8009B1D5 ^ 1] = p;
        *(s16 *)(p + 0) = 0xA0;
        p[0x1C] |= 0x20;
        *(s16 *)(p + 2) = 0x78;
        *(s16 *)(p + 0x1A) = D_8009B1D5 ^ 1;
        func_8003FEE0(0x23);
        return;
    }

    f = D_8009B220;

    if ((f & 0x40) == 0) {
        if (D_8009B17C[0x1D] != 0) {
            D_8009B220 = f | 0x40;

            for (i = 5; i < 0xA; i++) {
                n = D_800907D8[i + D_8009B1D5 * 20];
                r = D_801A7AD8 + n * 28;
                if ((*(s32 *)(r + 0x14) & 0x90000000) == 0x90000000) {
                    e = *(u8 **)r;
                    *(s32 *)(e + 0x24) = (s32)func_80025B28;
                    e[0x6C] = 1;
                }
            }
        }
        return;
    }

    if (func_80042B40(1) == 0) {
        if (D_8009B17C[0x1D] >= 2) {
            D_800E9FF0[D_8009B1D5 ^ 1].unk19 = 4;
            D_8009B220 = 0;
        }
    }
}
