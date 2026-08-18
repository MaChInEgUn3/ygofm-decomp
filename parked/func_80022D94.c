#include "common.h"

void func_80022D94(s32 n, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 da;
    s32 db;
    s32 dc;
    s32 dd;

    a = *(s16 *)D_800F2848;
    da = ((arg1 - a) << 16) / n;
    b = *(s16 *)(D_800F2848 + 4);
    db = ((arg2 - b) << 16) / n;
    c = *(s16 *)(D_800F2848 + 2);
    dc = ((arg3 - c) << 16) / n;
    d = *(s32 *)(D_800F2848 + 0x24);
    dd = ((arg4 - d) << 16) / n;

    D_8009B204 = n;
    D_8009B1EE = arg1;
    D_8009B192 = arg2;
    D_8009B190 = arg3;
    D_8009B166 = arg4;
    D_8009B1C4 = (a << 16) | 0x8000;
    D_8009B15C = (b << 16) | 0x8000;
    D_8009B158 = (c << 16) | 0x8000;
    D_8009B224 = (d << 16) | 0x8000;
    D_8009B1FC = da;
    D_8009B198 = db;
    D_8009B194 = dc;
    D_8009B168 = dd;
}
