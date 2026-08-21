#include "common.h"

void func_80058434(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *b;
    u8 *t;
    s32 c;
    s32 sn;
    s32 r;
    s32 u;
    s32 w;
    s32 z;
    s32 v;

    if (arg0 > 0) {
        b = D_800F56FC;
        t = b - 0xC;
    } else {
        b = D_800F56F0;
        t = b + 0xC;
    }

    if (*(s16 *)&D_8009B478 + arg3 >= 0xB) {
        *(u16 *)&D_8009B478 = *(u16 *)&D_8009B478 + arg3;
    }

    if ((arg1 & 0xFFF) != 0) {
        v = *(s16 *)&D_8009B47A + arg1 + 0x1000;
        D_8009B47A = v - v / 0x1000 * 0x1000;
    }

    if ((arg2 & 0xFFF) != 0) {
        v = *(s16 *)&D_8009B47C + arg2 + 0x1000;
        D_8009B47C = v - v / 0x1000 * 0x1000;
    }

    if (arg1 != 0 || arg2 != 0 || arg3 != 0) {
        c = func_80086770(*(s16 *)&D_8009B47C);
        sn = func_800866A0(*(s16 *)&D_8009B47C);
        r = *(s16 *)&D_8009B478;
        u = r * c / 0x1000;
        w = r * sn / 0x1000;
        c = func_80086770(*(s16 *)&D_8009B47A);
        sn = func_800866A0(*(s16 *)&D_8009B47A);
        z = u * sn / 0x1000;
        u = u * c / 0x1000;
        *(s32 *)(t + 0) = *(s32 *)(b + 0) + u * arg0;
        *(s32 *)(t + 4) = *(s32 *)(b + 4) + w * arg0;
        *(s32 *)(t + 8) = *(s32 *)(b + 8) + z * arg0;
    }
}
