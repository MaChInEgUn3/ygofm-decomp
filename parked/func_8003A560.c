/* 50 differing at 240/240 (2026-09-05, first written from the m2c draft).
 * Sound-bank slot loader: five 0x18C10-byte records at D_80010000, a slot
 * table D_8015C410 indexed from 4 down, the current slot in D_8009B326.
 * Levers that paid, in order: k4 = 0x18400 and the table base named in the
 * preheader (-1 -> 240/240, 116 -> 74); a second name for the 0x100 in the
 * second block (74 -> 68); `b = D_80010000 + 0x63040;` as the preheader's
 * FIRST statement (68 -> 60); `b -= 0x18C10;` before `i--;` (60 -> 57); the
 * copy call written in BOTH arms of the table choice (57 -> 52); and the
 * slot byte compared as `*t == (c = ...)` so *t loads first (52 -> 50).
 * Dead: the second func_8007F978 argument named (60), both args named (62),
 * the .data[8] arm for the two tables (bare `la` lets gcc if-convert the
 * arms, -1), `q = b; q += 0x18000;` and the integer-plus spelling (52), a
 * store pointer copy `y = q` for the three stores before the call (58), a
 * ternary for the table (57).
 * Residue: k4 and q exchanged in $s0/$s1 (retail forms the 0x18000 constant
 * in q's own register, ours in a temp); block 2 has hun2 and q the same way
 * round and its 0x3C byte read early; the call's a1 copy before the last
 * three stores. Addressing: D_8009B0F4, D_8009B134 and D_80010000 on their
 * .data arms (bare), D_8015C410 and the two tables as cc1psx's own pairs,
 * D_8009B326 gp-relative (new s8 declaration), default flags. */
#define D_8009B0F4_IN_DATA
#define D_8009B134_IN_DATA
#define D_80010000_IN_DATA
#include "common.h"

s32 func_80039F1C(void);
void func_8003A1EC(u8 *arg0, u8 *arg1, s32 arg2);
void func_8007F9D8(u8 *arg0, u8 *arg1);
s32 func_80082324(s32 arg0);
void func_8003A01C(u8 *arg0);

void func_8003A560(u8 *p) {
    u8 *b;
    u8 *q;
    s8 *t;
    u8 *r;
    u8 *src;
    s32 i;
    s32 c;
    s32 v;
    s32 hun;
    s32 hun2;
    s32 fl;
    s32 k;
    s32 k4;
    s8 *tb;

    if (func_80039F1C() == 0) {
        b = D_80010000 + 0x63040;
        i = 4;
        tb = D_8015C410;
        hun = 0x100;
        k4 = 0x18400;
        D_8009B326 = 0;
        do {
            t = tb + i;
            if (*t < 0) {
                D_8009B326 = i;
            }
            if (*t == (c = *(s8 *)(p + 0x30))) {
                while (func_80082324(0xA) != 0) {
                }
                q = b + 0x18000;
                v = p[0x3C];
                *(s16 *)(q + 0xC04) = 0xC0;
                *(s16 *)(q + 0xC02) = hun;
                *(s16 *)(q + 0xC06) = hun;
                *(s16 *)(q + 0xC00) = 0x340 - v * 0xC0;
                func_8007F978(b + 0x18C00, b, v);
                *(s16 *)(q + 0xC08) = 0x200;
                *(s16 *)(q + 0xC0C) = hun;
                *(s16 *)(q + 0xC0E) = 2;
                *(s16 *)(q + 0xC0A) = p[0x3C] * 2 + 0xF0;
                func_8007F978(b + 0x18C08, q);
                if (p[0x3C] != 0) {
                    func_800356A0(D_801AF800, b + k4, 0x800);
                } else {
                    func_800356A0(D_801AF000, b + k4, 0x800);
                }
                p[0x33] |= 0x40;
                return;
            }
            b -= 0x18C10;
            i--;
        } while (i >= 0);
        if (((D_8009B0F4 & 0x2000030) | D_8009B134) != 0) {
            p[0x33] &= 0x7F;
            return;
        }
        r = func_80014EEC(0, (u8 *)0, c * 0x32 + 0x3B4E, 0x32, func_8003A01C, 0, 0);
        *(u8 **)(r + 0x38) = D_801AF000;
        *(s32 *)(r + 0x3C) = p[0x3C];
        if (p[0x3C] != 0) {
            *(u8 **)(r + 0x38) = D_801AF800;
        }
        D_8009B0F4 = *(s32 *)(r + 0x2C) | 0x10;
        return;
    }
    fl = p[0x33];
    if ((fl & 0x40) == 0) {
        if (((D_8009B0F4 & 0x2000030) | D_8009B134) == 0) {
            p[0x33] = fl | 0x40;
            D_8015C410[D_8009B326] = p[0x30];
            while (func_80082324(0xA) != 0) {
            }
            k = D_8009B326;
            b = D_80010000 + k * 0x18C10;
            q = b + 0x18000;
            hun2 = 0x100;
            *(s16 *)(q + 0xC02) = hun2;
            *(s16 *)(q + 0xC06) = hun2;
            *(s16 *)(q + 0xC00) = 0x340 - p[0x3C] * 0xC0;
            *(s16 *)(q + 0xC04) = 0xC0;
            func_8007F9D8(b + 0x18C00, b);
            *(s16 *)(q + 0xC08) = 0x200;
            *(s16 *)(q + 0xC0C) = hun2;
            *(s16 *)(q + 0xC0E) = 2;
            *(s16 *)(q + 0xC0A) = p[0x3C] * 2 + 0xF0;
            func_8007F9D8(b + 0x18C08, q);
            if (p[0x3C] != 0) {
                func_800356A0(b + 0x18400, D_801AF800, 0x800);
            } else {
                func_800356A0(b + 0x18400, D_801AF000, 0x800);
            }
        }
    } else {
        func_8003A1EC(p, p, p[0x31]);
        p[0x33] = 0;
        p[0x32] |= 0x40;
    }
}
