#include "common.h"

void func_8005B36C(u8 *src, u8 *ctx, s32 idx, s32 a3, s32 a4, s32 a5, s32 a6) {
    u8 *p;
    u8 *dst;
    u8 *q;
    s32 n;
    s32 i;
    s32 off;
    s32 v;
    s32 k;
    s32 c;
    u8 *b;

    n = src[3];
    *(s32 *)D_800FE240 = *(s32 *)src;
    src += 4;
    *(s32 *)(D_800FE240 + 4) =
        ((((-a5 & 0xFF) / 8) & 0x1F))
        | (((-a6 & 0xFF) / 8) & 0x1F) << 5
        | 0xE2000000
        | (((a3 & 0xFF) / 8) & 0x1F) << 10
        | (((a4 & 0xFF) / 8) & 0x1F) << 15;
    dst = (u8 *)D_800FE240 + 8;

    q = src;
    for (i = n - 1; i != -1; i--) {
        *(s32 *)dst = *(s32 *)q;
        q += 4;
        dst += 4;
    }

    k = n * 4;
    b = (u8 *)D_800FE240;
    *(s32 *)(k + (s32)b + 8) = 0xE2000000;
    b[3] = n + 2;

    off = (idx & 0xFFFF) * 4;
    k += 0xC;
    c = *(s32 *)(ctx + 4);
    p = (u8 *)D_800FE240;
    v = *(s32 *)(off + c);
    *(s32 *)p = (*(s32 *)p & 0xFF000000) | (v & 0xFFFFFF);
    c = *(s32 *)(ctx + 4);
    D_800FE240 = (s32)(p + k);
    off += c;
    v = *(s32 *)off;
    *(s32 *)off = (v & 0xFF000000) | ((s32)p & 0xFFFFFF);
}
