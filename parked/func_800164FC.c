#include "common.h"

void func_800164FC(void) {
    u8 *e;
    u8 *a;
    u8 *p1;
    u8 *p3;
    s32 *p4;
    s32 n;
    s32 h;
    s32 c;
    s32 f;
    u8 *q;

    q = D_800F2848;
    func_800878D0(*(s16 *)(q + 0xE));
    func_800878B0(0xA0, 0x6C);
    func_80087890(0, 0, 0);
    func_80086810(0x28A, 0x320, *(s16 *)(q + 0xE));
    func_800540B4(2);

    if ((D_8009B30C & 2) != 0) {
        D_8009B314 = D_8009B314 + 1;
        if ((u32)D_8009B314 >= (u32)D_8009B308) {
            D_8009B30C = D_8009B30C & ~3;
        }
        D_8009B310 = D_8009B304;
    }

    p4 = (s32 *)0x1F8000C0;
    p1 = (u8 *)0x1F800140;
    p3 = (u8 *)0x1F800180;
    c = 0x808080;
    e = D_801A7B64;
    n = 0;

    p1[3] = 9;
    p1[7] = 0x2C;
    p1[4] = 0xFF;
    p1[5] = 0xFF;
    p1[6] = 0xFF;
    *(s16 *)(p1 + 0x16) = 0x5F;
    *(s16 *)(p1 + 0xE) = 0x3C11;
    f = 0x80;
    p1[0x24] = 0xAF;
    p1[0x14] = 0xAF;
    p1[0x25] = 0x37;
    p1[0x1D] = 0x37;
    p1[7] = 0x2E;
    p1[0x1C] = f;
    p1[0xC] = f;
    p1[0x15] = 0;
    p1[0xD] = 0;
    *(s16 *)(p3 + 0x1A) = 0x9E;
    *(s16 *)(p3 + 0xE) = 0x3C50;
    p3[0x19] = f;
    p3[0xD] = f;
    p3[0x31] = 0xBC;
    p3[0x25] = 0xBC;
    *p4 = c;

    do {
        h = *(u16 *)(e + 0x16);
        if ((h & 0x8000) != 0) {
            a = *(u8 **)e;
            if (a != (u8 *)0) {
                if ((h & 0x400) != 0) {
                    func_80015DFC(e);
                    n++;
                    goto next;
                }
                *p4 = *(s32 *)(a + 0xC);
                func_80015EF4(e, p3, p1, p4);
            }
        }
        n++;
    next:
        e += 0x1C;
    } while (n < 0xA);

    e = D_801A7B64;
    e = e + 0x1A4;
    n = 0;
    do {
        h = *(u16 *)(e + 0x16);
        if ((h & 0x8000) != 0) {
            a = *(u8 **)e;
            if (a != (u8 *)0) {
                if ((h & 0x400) != 0) {
                    func_80015DFC(e);
                    n++;
                    goto next2;
                }
                *p4 = *(s32 *)(a + 0xC);
                func_80015EF4(e, p3, p1, p4);
            }
        }
        n++;
    next2:
        e += 0x1C;
    } while (n < 0xA);

    func_800878B0(0, 0);
}
