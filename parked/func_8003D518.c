#define D_8009AF76_IS_AGGREGATE
#include "common.h"
void func_80042C08(u8 *arg0);

void func_8003D518(u8 *arg0) {
    u8 *p;
    s32 f;

    if ((D_8009B3C1 & 0x80) == 0) {
        D_8009B3C1 |= 0x80;
        p = func_800400AC(func_8004002C(), 6);
        *(s16 *)(p + 0x30) = 0xA0;
        *(s16 *)(p + 0x32) = 0x78;
        *(s16 *)(p + 0x48) = 0x80;
        *(s16 *)(p + 0x4A) = 0xE0;
        func_80042918(p);
        func_800428EC(p, (s8)(D_8009AF76[0] - 3));
        *(void **)(p + 0x4C) = func_80042C08;
        *(u8 **)(arg0 + 4) = p;
    }
    f = D_8009B3C1;
    p = *(u8 **)(arg0 + 4);
    if (f & 0x40) {
        D_8009B3C1 = 0;
    } else {
        s32 x = *(u16 *)(p + 0x48) - 8;
        s32 y = *(u16 *)(p + 0x4A) - 8;

        *(u16 *)(p + 0x48) = x;
        *(u16 *)(p + 0x4A) = y;
        if ((s16)x <= 0) {
            D_8009B3C1 = f | 0x40;
            *(s16 *)(p + 0x48) = 0;
            *(s16 *)(p + 0x4A) = 0x40;
        }
    }
}
