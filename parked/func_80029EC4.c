#define D_8009B09C_IS_AGGREGATE
#define D_8009B146_IS_AGGREGATE
#include "common.h"

s32 func_80029EB0(u8 *arg0, s32 arg1);

void func_80029EC4(void) {
    u8 *pkt;
    u8 *pkt2;
    s32 ctx;
    s32 c1;
    s32 c2;
    s32 a;
    s32 b;
    s32 n;
    s32 i;
    s32 j;
    s32 k;
    s32 p;
    s32 q;
    s32 f;
    s32 h;
    s32 t;
    s32 dy;
    u8 *tb;

    pkt = (u8 *)0x1F800320;
    n = (*(s16 *)D_8009B148 - 8) / 178;
    ctx = D_800E9D9C[0];
    if (n < 0) {
        return;
    }
    c1 = 0x808080;
    c2 = 0x404040;
    a = 178 * n + 8;
    b = 25 * n;
    *(s16 *)(pkt + 4) = 8;
    *(s32 *)(pkt + 8) = 0xE000C;
    *(s32 *)(pkt + 0x10) = 0xF70130;
    *(s16 *)(pkt + 6) = 1424 * b + 8;
    *(s16 *)(pkt + 0x12) = 0xF7;
    *(s16 *)(pkt + 0xE) = 0xF060;
    *(s32 *)pkt = 0x8000000;
    *(s16 *)(pkt + 0xC) = 0x1B;
    do {
        k = b * 8;
        *(s16 *)(pkt + 6) = a;
        *(s16 *)(pkt + 6) = a - *(u16 *)D_8009B148;
        j = 0;
        do {
            h = *(s16 *)(pkt + 6);
            if (h + *(u16 *)(pkt + 8) <= 0) {
                goto adv;
            }
            if (h >= 0xF0) {
                goto phase2;
            }
            q = k + 0x65;
            i = 0;
            p = k + 1;
            do {
                f = func_80029EB0(D_800EA1E8, p);
                if (f & 0x80) {
                    *(s32 *)(pkt + 0x14) = c1;
                    if (f & 1) {
                        *(s32 *)(pkt + 0x14) = c2;
                    }
                    *(s16 *)(pkt + 4) = i + 8;
                    *(s16 *)(pkt + 0x10) = *(u16 *)(D_800EA1E8 + p * 4 + 0x54);
                    func_800849F0(pkt, ctx, 2);
                }
                if (q < 0x2D3) {
                    f = func_80029EB0(D_800EA1E8, q);
                    if (f & 0x80) {
                        *(s32 *)(pkt + 0x14) = c1;
                        if (f & 1) {
                            *(s32 *)(pkt + 0x14) = c2;
                        }
                        *(s16 *)(pkt + 4) = i + 0xA8;
                        *(s16 *)(pkt + 0x10) = *(u16 *)(D_800EA1E8 + q * 4 + 0x54);
                        func_800849F0(pkt, ctx, 2);
                    }
                }
                p++;
                q++;
                i += 0xE;
            } while (i < 0x8A);
        adv:
            *(u16 *)(pkt + 6) = *(u16 *)(pkt + 6) + 0x10;
            k += 0xA;
            j++;
        } while (j < 0xA);
        a += 0xB2;
        b += 0x19;
        n++;
    } while (n < 4);
phase2:
    pkt2 = (u8 *)0x1F800000;
    *(s32 *)pkt2 = 0x50000000;
    pkt2[0xE] = 0;
    pkt2[0xD] = 0;
    pkt2[0xC] = 0;
    pkt2[0x11] = 0;
    pkt2[0x10] = 0;
    pkt2[0xF] = 0;
    tb = D_800EA1E8;
    t = D_8009B09C[0] & 0x7F;
    switch (t / 32) {
    case 0:
        pkt2[0xD] = t * 8;
        break;
    case 1:
        pkt2[0xD] = 0xFF;
        pkt2[0x10] = (t - 0x20) * 8;
        break;
    case 2:
        pkt2[0xD] = (0x5F - t) * 8;
        pkt2[0x10] = 0xFF;
        break;
    case 3:
        pkt2[0x10] = (0x7F - t) * 8;
        break;
    }
    *(s16 *)(pkt2 + 8) = 0;
    dy = *(u16 *)(tb + 0xA) - *(u16 *)D_8009B148;
    t = *(u16 *)(tb + 8) - D_8009B146[0];
    *(s16 *)(pkt2 + 4) = t;
    *(s16 *)(pkt2 + 0xA) = dy;
    *(s16 *)(pkt2 + 6) = dy;
    func_80084130(pkt2, ctx, 1);
    *(s16 *)(pkt2 + 8) = 0x140;
    func_80084130(pkt2, ctx, 1);
    *(s16 *)(pkt2 + 0xA) = 0;
    *(s16 *)(pkt2 + 8) = *(u16 *)(pkt2 + 4);
    func_80084130(pkt2, ctx, 1);
    *(s16 *)(pkt2 + 0xA) = 0xF0;
    func_80084130(pkt2, ctx, 1);
}
