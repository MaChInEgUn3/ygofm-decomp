#include "common.h"

void func_8005B260(u8 *src, u8 *ctx, s32 idx, s32 flags) {
    u8 *p;
    u8 *dst;
    s32 n;
    s32 i;
    s32 off;
    s32 *e;
    s32 v;

    n = src[3];
    *(s32 *)D_800FE240 = *(s32 *)src;
    src += 4;
    *(s32 *)(D_800FE240 + 4) = ((flags & 3) << 5) | 0xE1000200;
    dst = (u8 *)D_800FE240 + 8;

    for (i = n - 1; i != -1; i--) {
        *(s32 *)dst = *(s32 *)src;
        src += 4;
        dst += 4;
    }

    ((u8 *)D_800FE240)[3] = n + 1;
    if (flags >= 0) {
        ((u8 *)D_800FE240)[0xB] |= 2;
    }

    off = (idx & 0xFFFF) * 4;
    p = (u8 *)D_800FE240;
    e = (s32 *)(off + *(s32 *)(ctx + 4));
    *(s32 *)p = (*(s32 *)p & 0xFF000000) | (*e & 0xFFFFFF);
    off += *(s32 *)(ctx + 4);
    v = *(s32 *)off;
    D_800FE240 = (s32)(p + n * 4 + 8);
    *(s32 *)off = (v & 0xFF000000) | ((s32)p & 0xFFFFFF);
}
