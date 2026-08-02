#include "common.h"

void func_8005B4D8(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3) {
    s32 n;
    s32 i;
    u32 *q;
    u8 *s;
    s32 k;
    u8 *b;
    u32 *e;

    s = arg0;
    n = s[3];
    *(u32 *)D_800FE240 = *(u32 *)s;
    s += 4;
    *(u32 *)(D_800FE240 + 4) = ((arg3 & 3) << 5) | 0xE1000200;
    q = (u32 *)(D_800FE240 + 0xC);
    *(u32 *)(D_800FE240 + 8) = 0xE6000001;

    for (i = n - 1; i != -1; i--) {
        *q++ = *(u32 *)s;
        s += 4;
    }

    *(u32 *)(D_800FE240 + n * 4 + 0xC) = 0xE6000000;
    *(u8 *)(D_800FE240 + 3) = n + 3;
    if (arg3 >= 0) {
        *(u8 *)(D_800FE240 + 0xF) = *(u8 *)(D_800FE240 + 0xF) | 2;
    }

    k = (arg2 & 0xFFFF) << 2;
    e = (u32 *)(*(u8 **)(arg1 + 4) + k);
    *(u32 *)D_800FE240 = (*(u32 *)D_800FE240 & 0xFF000000) | (*e & 0xFFFFFF);

    e = (u32 *)(*(u8 **)(arg1 + 4) + k);
    b = (u8 *)D_800FE240;
    D_800FE240 = (s32)(b + n * 4 + 0x10);
    *e = (*e & 0xFF000000) | ((u32)b & 0xFFFFFF);
}
