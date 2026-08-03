#include "common.h"

void func_80014B30(u8 *p, s32 mode) {
    u8 *e;
    s32 v;

    switch (mode) {
    case 0:
        e = D_801D4200;
        if (*(s32 *)(e + 0x14) != 0) {
            p[0x46] = 3;
            v = D_8009B118;
            *(s32 *)(p + 8) = v;
            *(s32 *)(p + 0xC) = v + 0x800;
            *(s32 *)(p + 0x30) = *(s32 *)(e + 0xC);
            v = *(s32 *)(e + 0x14);
            *(s32 *)(p + 0x1C) = v;
            goto clamp;
        }
        *(s32 *)(p + 0x40) = 2;
        /* fall through */
    case 1:
        e = D_801D4200;
        v = *(s32 *)(e + 0x18);
        if (v == 0) {
            goto tail;
        }
        D_8009B0F4 = D_8009B0F4 & 0xFFDCFFFF;
        v = *(s32 *)(e + 0x10);
        *(s32 *)(p + 0xC) = v;
        *(s32 *)(p + 8) = v;
        p[0x46] = 1;
        v = *(s32 *)(e + 0x18);
        *(s32 *)(p + 0x1C) = v;
    clamp:
        if (v < 0) {
            *(s32 *)(p + 0x1C) = -(v << 11);
        }
        break;

    case 2:
    tail:
        if (D_8009B128 != (void (*)(void))0) {
            D_8009B128();
        }
        break;
    }
}
