#include "common.h"

s32 func_80023090(u8 *arg0, u8 *arg1) {
    u8 *t = D_800907D8;
    u8 *r = D_801A7AD8;
    s32 a = *(s8 *)(arg0 + 0x10);
    s32 b = *(s8 *)(arg1 + 0x10);
    s32 x = a * 5 + *(s8 *)(arg0 + 0xF);
    s32 d = D_8009B1D5 * 20;
    s32 i = t[x + d];
    s32 p = i * 28;
    s32 j = t[b * 5 + *(s8 *)(arg1 + 0xF) + d];
    s32 v = func_8001EE44((s32)(r + p), (s32)(r + j * 28));

    if (v == 0) {
        return 4;
    }

    if (v < 0) {
        return 1;
    }

    return 6;
}
