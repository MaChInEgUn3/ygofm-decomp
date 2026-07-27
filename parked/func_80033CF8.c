#include "common.h"

void func_80033CF8(s32 arg0, s32 arg1, s32 arg2) {
    u8 *p;
    s32 a;
    u16 n;

    *(u16 *)((u8 *)D_8009B310 + 2) = func_80086E50(arg0 * arg0 + arg2 * arg2);

    a = func_800899A0(arg0, arg2) / 16;

    if (a >= 0x100) {
        a = 0xFF;
    }

    p = (u8 *)D_8009B310;
    n = D_8009B314;
    *(u16 *)(p + 0) = (a << 8) | (arg1 >> 4);
    *(u16 *)(p + 4) = n;
    *(u16 *)(p + 6) = 0;

    D_8009B310 = (s32)(p + 8);
    D_8009B314 = D_8009B314 + 1;
}
