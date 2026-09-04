#include "common.h"

void func_800528AC(void) {
    Word4 save;
    Word4 col;
    s32 i;
    u16 sv;
    s32 off;
    u8 *p;
    u8 *e;
    u8 *q;
    u8 side;
    s32 sd;
    s32 j;
    u32 fl;
    u16 hi;
    u16 lo;
    s32 d;
    s32 bank;
    u16 sh;
    s32 c;

    off = 0;
    p = D_800F2B50 + off;
    i = 0;
    do {
        if (p[0] & 1) {
            sd = (*(u16 *)p >> 1) & 1;
            if (D_800F2C40[sd * 0xE20 + 0xE1F] != 0) {
                if (func_8005A8C4(sd, p[0x13]) == 0) {
                    fl = *(u16 *)p;
                    sh = *(u16 *)(p + 0xA);
                    lo = *(u16 *)(p + 0xC);
                    hi = *(u16 *)(p + 0xE);
                    side = (fl >> 1) & 1;
                    e = D_800F2C40 + side * 0xE20;
                    sv = *(u16 *)(e + 0xE06);
                    bank = e[0xBF5];
                    c = (fl >> 3) & 0x1F;
                    d = func_80059AA8(side & 0xFF, 0);
                    save = *(Word4 *)(e + 0xDC0);
                    col.unk3 = p[0x13];
                    col.unk0 = p[0x10] * (hi - lo) / hi + p[0x14] * lo / hi;
                    col.unk1 = p[0x11] * (hi - lo) / hi + p[0x15] * lo / hi;
                    col.unk2 = p[0x12] * (hi - lo) / hi + p[0x16] * lo / hi;
                    *(Word4 *)(e + 0xDC0) = col;
                    j = 0;
                    if (e[0xE1B] != 0) {
                        q = e;
                        do {
                            s32 v = e[0xBF5];
                            if (c != 0) {
                                v = c;
                                *(u8 *)(*(s32 *)(q + 0x1E0) + 0xC) = c;
                            }
                            func_8004DC38(e, j, v, sh);
                            j++;
                            q += 4;
                        } while (j < (s32)e[0xE1B]);
                    }
                    if (c != 0) {
                        e[0xBF5] = c;
                    }
                    D_8009AF9C = (s32)(D_800F2B50 + off + 1);
                    D_8009AF9B = (*(u16 *)p >> 2) & 1;
                    j = 0;
                    func_800540B4(side);
                    D_8009AF9C = 0;
                    D_8009AF9B = 0;
                    if (e[0xE1B] != 0) {
                        q = e;
                        do {
                            s32 v = e[0xBF5];
                            if (bank != 0) {
                                v = bank;
                                *(u8 *)(*(s32 *)(q + 0x1E0) + 0xC) = bank;
                            }
                            func_8004DC38(e, j, v, sv);
                            j++;
                            q += 4;
                        } while (j < (s32)e[0xE1B]);
                    }
                    if (bank != 0) {
                        e[0xBF5] = bank;
                    }
                    func_80059AA8(side, d);
                    *(Word4 *)(e + 0xDC0) = save;
                }
                *(u16 *)(p + 0xC) = *(u16 *)(p + 0xC) + func_80058E1C();
                if ((u32)*(u16 *)(p + 0xC) >= *(u16 *)(p + 0xE)) {
                    *(s16 *)p = *(u16 *)p & 0xFFFE;
                }
            }
        }
        p += 0x18;
        i++;
        off += 0x18;
    } while (i < 0xA);
}
