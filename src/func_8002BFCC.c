#define D_8009B146_IN_DATA
#define D_8009B148_IN_DATA
#include "common.h"

void func_80029574(s32 arg0);
void func_80029590(void);
void func_8002BF3C(void);
void func_80035668(s32 arg0);
void func_8004293C(u8 *arg0);
void func_80029EC4(void);
void func_8002BD0C(void);

void func_8002BFCC(void) {
    s16 *q;
    u8 *b;
    u8 *r;
    u8 *o;
    u8 *e;
    u8 *m;
    s32 n;
    s32 x;
    s32 y;
    s32 v;
    s32 c;
    s32 d;
    s32 k;
    s32 off;
    s32 rb;

    D_8009B148 = 0;
    D_8009B146 = 0;
    func_80035668(0);
    func_80029574(0);
    n = 0x2D1;
    q = (s16 *)0x801805A2;
    b = D_800EA0E8;
    *(s16 *)(b + 0x28) = 0x100;
    *(s16 *)(b + 0x2A) = 0x100;
    *(s16 *)(b + 0x2C) = 0x200;
    *(s16 *)(b + 0x2E) = 0xF0;
    do {
        *q = n + 1;
        n--;
        q--;
    } while (n >= 0);
    func_80014E1C(0, (u8 *)0, 0x1DCD, 0x8A, func_8002BD0C, 0, 0);
    func_800137E4();
    func_8002BF3C();
    D_800E9DBC[0] = func_80029EC4;
    func_80029590();
    r = D_800EA1E8;
    D_800EA1E8[0] = 0;
    c = (s8)D_8009B258;
    d = c;
    if (c >= 0xA) {
        x = (c % 10) * 0xE + 0xAE;
    } else {
        x = (d % 10) * 0xE + 0xE;
    }
    *(s16 *)(r + 0x12) = x;
    *(s16 *)(r + 8) = x;
    k = (s8)D_8009B259;
    y = (k / 10) * 0xB2 + (k % 10) * 0x10 + 0xE;
    *(s16 *)(r + 0x14) = y;
    *(s16 *)(r + 0xA) = y;
    func_8002A660(r);
    o = func_800400AC(func_8004002C(), 2);
    func_800404CC(o, 0x10, 0xD8, 0, 2, 1, 0x1B, 0x127);
    o[0x5F] = 0x80;
    func_80042918(o);
    n = 1;
    *(u16 *)(o + 8) = *(u16 *)(o + 8) | 8;
    *(u8 **)(r + 0x48) = o;
    o = func_800400AC(func_8004002C(), 2);
    func_800404CC(o, *(s16 *)(r + 8), *(s16 *)(r + 0xA), 0, 2, 2, 0x1B, 0x147);
    rb = (s32)r;
    o[0x5F] = 0x80;
    *(u8 **)(r + 0x44) = o;
    r[0x56] = 0;
    *(s16 *)(r + 0x54) = 0;
    do {
        *(u8 *)(rb + n * 4 + 0x56) = 0;
        *(s16 *)(r + 0x54) = 0;
        off = n * 4 - 4;
        v = (*(s32 *)((u8 *)D_801D4244 + off) >> 0x1A) & 0x1F;
        switch (v) {
        case 0x14:
        case 0x17:
            *(s16 *)(rb + n * 4 + 0x54) = 0x170;
            break;
        case 0x15:
            *(s16 *)(rb + n * 4 + 0x54) = 0x180;
            break;
        case 0x16:
            *(s16 *)(rb + n * 4 + 0x54) = 0x190;
            break;
        default:
            *(s16 *)(rb + n * 4 + 0x54) = 0x160;
            break;
        }
        n++;
    } while (n < 0x2D3);
    D_801D5608[0] = 0;
    n = 1;
    do {
        if (func_8002CCA8(n + 0x120) != 0) {
            D_801D5608[0] += 1;
            *(u8 *)(r + n * 4 + 0x56) = 0x80;
            if (func_8002C518(n) < 0) {
                *(u8 *)(r + n * 4 + 0x56) |= 1;
            }
        }
        n++;
    } while (n < 0x2D3);
    func_8003B6AC(3, 1);
    m = func_80035BE4(3, 0xF8, 0x58, -0x18, 0x90, 0x10);
    m[0x5A] = 0x10;
    m[0x5B] = 0x10;
    func_80039A14(m);
    func_8004293C(*(u8 **)(m + 0x28));
    *(u16 *)(*(u8 **)(m + 0x28) + 8) &= 0xFFF7;
    func_8002A2F4(r);
    func_8003FF08(0x72D0);
}
