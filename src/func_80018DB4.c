#include "common.h"

void func_80018C34(u8 *arg0);
s32 func_80018CF8(void);
s32 func_80042B40(s32 arg0);

void func_80018DB4(void) {
    u8 *p;
    u8 *c;
    u8 *g;
    u8 *base;
    s32 i;
    s32 k;
    s32 v;
    s32 t;
    s32 b;
    s32 a;
    s32 n;
    s32 off;
    s32 y;

    v = D_8009B23A;
    if ((v & 0x8000) == 0) {
        D_8009B23A = v | 0x8000;
        D_8009B1ED = 1;
    }

    if ((D_8009B23A & 0x4000) == 0) {
        t = D_8009B1ED - 1;
        D_8009B1ED = t;
        if ((s8)t > 0) {
            return;
        }
        D_8009B1ED = 8;
        b = D_8009B1EC - 1;
        c = D_8009B1C8;
        D_8009B1EC = b;
        if (*(s8 *)(c + 0x18) >= 0x28) {
            D_8009B165 = D_8009B1D5 ^ 1;
            *(s8 *)&D_800E9FF0[D_8009B165] = -0x28;
            D_8009B23A = 0xC;
            return;
        }
        i = 4 - (s8)b;
        a = D_800907CC[i + D_8009B1D5 * 5];
        if ((a & 0x80) != 0) {
            k = (a & 0x7F) + 0xF;
        } else {
            k = a;
        }
        func_800249E0(k, *(s8 *)(D_8009B1C8 + 0x18));
        p = func_80018004(&D_801A7AD8[k * 28], i * 60 + 0x14E, 0x92);
        p[0x6C] = 1;
        *(s16 *)(p + 0x60) = 0xC;
        *(s32 *)(p + 0x24) = (s32)func_80018C34;
        D_800EA030[i].unk0 = p;
        base = D_8015C424;
        g = base + p[0x6A] * 28 + 0x48000;
        y = *(s8 *)(*(s32 *)(g + 0x36B8) + 2);
        *(s8 *)(D_8009B1C8 + i + 0x1A) = y;
        n = *(u8 *)(D_8009B1C8 + 0x18);
        *(u8 *)(D_8009B1C8 + 0x18) = n + 1;
        if (*(s8 *)&D_8009B1EC == 0) {
            D_8009B23A = D_8009B23A | 0x4000;
        }
        func_8003FEE0(0xA);
    } else {
        if (func_80042B40(1) == 0) {
            D_8009B23A = 4;
            if (func_80018CF8() != 0) {
                D_8009B23A = 0xE;
            }
        }
    }
}
