#include "common.h"

/* Builds an 8-byte packet on the stack and hands three library calls the
 * derived rectangles. Two shapes carry it: the halfword stores go through
 * a HalfView struct member -- spelled as cast arithmetic they lose the
 * in-struct marking and gcc 2.8's scheduler hoists the whole-struct copy's
 * lwl/lwr above stores to the same bytes (volatile does not pin it, no
 * flag reaches it) -- and the 0x1000 - D_8009B47A store is written before
 * the D_8009B47C one, which is what issues both gp loads back to back the
 * way retail covers their latency. */

typedef struct {
    u8 b[8];
} Blk8;

typedef struct {
    s16 h0;
    s16 h1;
    s16 h2;
    s16 h3;
} HalfView;

void func_800592AC(s32 p, s32 x, u8 *o) {
    Blk8 dst;
    Blk8 src;
    u8 buf[0x20];
    u8 *t;

    func_8008E3D0(&src, 0, 8);
    ((HalfView *)&src)->h1 = 0x1000 - D_8009B47A;
    ((HalfView *)&src)->h2 = D_8009B47C;
    t = D_800F2C40 + p * 3616;
    dst = src;
    *(s32 *)o = 0;
    *(u16 *)(o + 0x44) = 0x1000 - *(u16 *)(*(u8 **)(t + 0xD18) + 0x44);
    *(u16 *)(o + 0x46) = 0x1000 - *(u16 *)(*(u8 **)(t + 0xD18) + 0x46);
    *(u16 *)(o + 0x48) = 0x1000 - *(u16 *)(*(u8 **)(t + 0xD18) + 0x48);
    func_800889C0(o + 0x44, o + 4);
    func_80088E50(&dst, buf);
    func_80087370(o + 4, buf);
    *(s32 *)(o + 0x20) = 0;
    *(s32 *)(o + 0x1C) = 0;
    *(s32 *)(o + 0x18) = 0;
    *(s32 *)(o + 0x4C) = x;
}
