#include "common.h"

void func_800478EC(void) {
    s32 mask;
    s32 bit;
    s32 acc;
    s32 i;
    s32 o;
    u8 v;
    u8 w;
    s32 t;

    mask = 0x100000;
    bit = 1;
    acc = 0;

    for (i = 0; i < 4; i++, bit <<= 1, mask <<= 1) {
        v = (D_8009B45C + i)[0x428];
        if (v != 0) {
            w = (D_8009B45C + i)[0x424];
            if (v >= w) {
                (D_8009B45C + i)[0x424] = 0;
            } else {
                (D_8009B45C + i)[0x424] = w - v;
            }
            if ((D_8009B45C + i)[0x424] != 0) {
                func_80047864(i);
            } else {
                D_8009B45C[0x434] = D_8009B45C[0x434] & ~bit;
                acc |= mask;
                (D_8009B45C + i)[0x428] = 0;
                func_80076ED0(0, mask);
            }
        }

        o = i * 2;
        t = *(u16 *)(D_8009B45C + o + 0x42C);
        if (t != 0) {
            t = t - 1;
            *(s16 *)(D_8009B45C + o + 0x42C) = t;
            if ((u16)t == 0) {
                if (func_80077090(mask) != 0) {
                    func_80076ED0(0, mask);
                    acc |= mask;
                }
            }
        }

        if (func_80077090(mask) == 3 && (acc & mask) == 0) {
            func_80076ED0(0, mask);
            acc |= mask;
        }
    }

    if (acc != 0) {
        func_80076ED0(0, acc);
    }
}
