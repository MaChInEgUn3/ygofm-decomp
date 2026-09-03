#include "common.h"

s32 func_8001F0D0(u8 *p) {
    s32 i;
    s32 off1;
    u8 *b1;
    s32 n;
    u8 *tbl2;
    u8 *rec2;
    u8 *b2;
    s32 off2;
    s32 h2;
    u8 *e;
    s32 id;
    s32 sx;
    s32 sx2;
    s32 th;
    s32 sel;
    s32 off3;
    u8 *b3;
    u8 *q;
    u8 *tb;
    s32 v;
    u8 *w;
    s32 off4;
    u8 *b4;
    s32 j2;
    u8 *tbl3;
    u8 *rec3;
    s32 h3;
    s32 k;

    i = 0;
    off1 = 0x18000;
    b1 = D_8015C424;
    for (; i < 6; i++) {
        *(u16 *)(b1 + i * 2 + off1 + 0x3C68) = 0;
    }
    n = 0;
    i = n;
    tbl2 = D_800907D8;
    rec2 = D_801A7AD8;
    b2 = D_8015C424;
    off2 = 0x18000;
    h2 = D_8009B1D5 * 20;
    for (; i < 5; i++) {
        e = (u8 *)(*(u8 *)(i + h2 + (s32)tbl2) * 28 + (s32)rec2);
        if ((*(u16 *)(e + 0x16) & 0x8000) != 0) {
            id = *(u16 *)(e + 0xC);
            if ((u32)(id - 0x2A9) < 6) {
                sx = (s16)id;
                th = sx - 0x2A9;
                n++;
                *(u16 *)(b2 + th * 2 + off2 + 0x3C68) = id;
                sx2 = sx - 0x299;
                *(u16 *)(b2 + sx2 * 2 + off2 + 0x3C68) = (*(u8 **)e)[0x6A];
            }
        }
    }
    if (n != 0) {
        do { th = func_800170C8(D_801A7AD8 + p[0x6A] * 28) & 0xFFFF; } while (0);
        sel = -1;
        off3 = 0x18000;
        b3 = D_8015C424;
        q = b3 + 0xA;
        i = 5;
        tb = D_8009AF24;
        do {
            if (*(u16 *)(q + off3 + 0x3C68) != 0) {
                v = *(u8 *)(i + (s32)tb);
                if (v * 100 < th) {
                    break;
                }
                sel = i;
            }
            i--;
            q -= 2;
        } while (i >= 0);
        if (sel >= 0) {
            off4 = 0x18000;
            D_8009B22A = sel + 0x2A9;
            b4 = D_8015C424;
            j2 = sel + 0x10;
            D_8009B1B8 = *(u8 *)(b4 + j2 * 2 + off4 + 0x3C68);
            return 1;
        }
        if (0) {
        hit:
            w = *(u8 **)e;
            D_8009B22A = v;
            D_8009B1B8 = w[0x6A];
            return 1;
        }
    }
    i = 0;
    tbl3 = D_800907D8;
    rec3 = D_801A7AD8;
    h3 = D_8009B1D5 * 20;
    k = 0x2B2;
    for (; i < 5; i++) {
        e = (u8 *)(*(u8 *)(i + h3 + (s32)tbl3) * 28 + (s32)rec3);
        if ((*(u16 *)(e + 0x16) & 0x8000) != 0) {
            v = *(s16 *)(e + 0xC);
            if (v == k) {
                goto hit;
            }
        }
    }
    return 0;
}
