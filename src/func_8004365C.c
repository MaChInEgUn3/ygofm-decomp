/* One name `c` carries three values a reader would call separate: the outer
 * colour word, the `0x80 - i` difference, and the colour word built from it.
 * Retail keeps all three in $a1 -- two names for the last two is 12
 * differences, every one of them that register. */
#include "common.h"

void func_8004365C(u8 *a, u8 *b) {
    u8 *x;
    u8 *y;
    s32 i;
    s32 hi;
    s32 c;
    s32 v;

    x = (u8 *)0;

    if (a != (u8 *)0) {
        x = func_800400AC(func_8004002C(), 2);
        func_800428A8(x, 0, 0, 0, 0, a[0x69], a[0x66], 0x20D, D_801AF000);
        *(s32 *)(x + 4) = *(s32 *)(a + 4);
        func_800428EC(x, -1);
        *(u16 *)(x + 8) = *(u16 *)(x + 8) | 8;
        *(s32 *)(x + 4) = *(s32 *)(x + 4) | 0x60000000;
        *(s32 *)(a + 4) = *(s32 *)(a + 4) | 0x50000000;
    }

    *(s16 *)(b + 0x48) = 0xA0;
    *(s16 *)(b + 0x4A) = 0x78;
    *(s32 *)(b + 4) = *(s32 *)(b + 4) & 0xF7FFFFFF;

    y = func_800400AC(func_8004002C(), 2);
    func_800428A8(y, 0, 0, 0, 0, b[0x69], b[0x66], 0x20D, D_801AF000);
    *(s32 *)(y + 4) = *(s32 *)(b + 4);
    func_800428EC(y, -1);
    *(u16 *)(y + 8) = *(u16 *)(y + 8) | 8;
    *(s32 *)(y + 4) = *(s32 *)(y + 4) | 0x60000000;
    *(s32 *)(y + 0x48) = *(s32 *)(b + 0x48);
    *(s32 *)(b + 4) = *(s32 *)(b + 4) | 0x50000000;

    i = 0;
    hi = 0x80;

    do {
        c = ((i << 16) | (i << 8)) | i;
        *(s32 *)(b + 0xC) = c;
        *(s32 *)(y + 0xC) = c;
        if (a != (u8 *)0) {
            c = hi - i;
            v = c * 0x60 + 0x1000;
            c = c | ((c << 16) | (c << 8));
            *(s16 *)(y + 0x46) = v;
            *(s16 *)(y + 0x44) = v;
            *(s16 *)(b + 0x46) = v;
            *(s16 *)(b + 0x44) = v;
            *(s32 *)(a + 0xC) = c;
            *(s32 *)(x + 0xC) = c;
        }
        i += 8;
        func_80012D4C();
    } while (i < 0x81);

    *(s32 *)(b + 0x44) = 0x10001000;
    *(s32 *)(b + 4) = (*(s32 *)(b + 4) | 0x8000000) & 0x8FFFFFFF;
    func_8004036C((s32)a);
    func_8004036C((s32)x);
    func_8004036C((s32)y);
}
