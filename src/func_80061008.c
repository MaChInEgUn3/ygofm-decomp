#include "common.h"

void func_80061008(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *p = D_801A8000;
    u8 *e;
    s32 i;

    i = 0;
    *(s16 *)(p + 4) = arg0 + 2;
    *(s16 *)(p + 6) = arg1;
    *(s16 *)(p + 0x1C) = arg2 + 2;
    *(s16 *)(p + 0x1E) = arg3;

    do {
        *(s16 *)(p + 8) = 0;
        e = func_800400AC(func_8004002C(), 6);
        e[0x68] = 0;
        e[0x69] = 0;
        *(u16 *)(e + 0x30) = *(u16 *)(p + 4);
        *(u16 *)(e + 0x32) = *(u16 *)(p + 6);
        e[0x6A] = i++;
        func_80042918(e);
        *(s32 *)(e + 0x4C) = (s32)func_80060B38;
        *(u8 **)p = e;
        p += 0x18;
    } while (i < 2);

    D_8009B148 = 0;
    D_8009B146 = 0;
}
