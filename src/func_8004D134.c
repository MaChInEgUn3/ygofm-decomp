/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/model_slot_row_tables.c, profile gcc_2_8_1_g0.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
s32 func_8004D134(s32 mode, u16 *kind, u8 *ctx, s32 *best, s32 *total);
s32 func_8004D134(s32 mode, u16 *kind, u8 *ctx, s32 *best, s32 *total)
{
    u8 *hdr;
    u8 *rec;
    u8 *base;
    u8 *p;
    u8 *q;
    s32 count;
    s32 n;
    s32 off1;
    s32 off2;
    s32 stride;
    s32 step;
    s32 add1;
    s32 add2;
    s32 f;
    u32 v;
    u32 adjusted;
     

    s32 x;
    s32 y;
    u32 k;

    hdr = *(u8 **)ctx;
    base = *(u8 **)(ctx + 0x14);
    count = *(u16 *)(hdr + 2);
    rec = base + *(s32 *)(hdr + 4) * 4;
    n = count;
    if ((u32)mode >= 2) {
        return 0;
    }
    k = *kind;
    switch (k) {
    case 9:
        off1 = 6;
        off2 = 2;
        stride = 0x14;
        step = 0x20;
        break;
    case 0x209:
        off1 = 0xA;
        off2 = 6;
        stride = 0x18;
        step = 0x20;
        break;
    case 0xD:
        off1 = 6;
        off2 = 2;
        stride = 0x18;
        step = 0x28;
        break;
    case 0x20D:
        off1 = 0xA;
        off2 = 6;
        stride = 0x1C;
        step = 0x28;
        break;
    case 0x11:
        off1 = 6;
        off2 = 2;
        stride = 0x18;
        step = 0x28;
        break;
    case 0x211:
        off1 = 0xA;
        off2 = 6;
        stride = 0x1C;
        step = 0x28;
        break;
    case 0x15:
        off1 = 6;
        off2 = 2;
        stride = 0x1C;
        step = 0x34;
        break;
    case 0x215:
        off1 = 0xA;
        off2 = 6;
        stride = 0x20;
        step = 0x34;
        break;
    default:
        return 0;
    }

    if (--n != -1) {
        add1 = (mode << 2) - 0xA;
        add2 = (mode << 4) + 0x3BD8;
        do {
            if (mode < 2) {
                p = rec + off1;
                v = (*(u16 *)( p )) ;
                adjusted = v + add1;
                (*(u16 *)( p ))  = adjusted;
                f = (v >> 7) & 3;
                if (f >= 3) {
                    (*(u16 *)( p ))  = adjusted & 0xFF7F;
                }
                if (f < 2) {
                    q = rec + off2;
                    v = (*(u16 *)( q )) ;
                    y = v + add2;
                    (*(u16 *)( q ))  = y;
                    x = v >> 6;
                    if (x >= 0x10) {
                        y = (y & 0x3F) + 0x10;
                        (*(u16 *)( q ))  = y;
                        (*(u16 *)( q ))  =
                            y | ((x % 0x10) << 6);
                    }
                }
            }
            if (best != 0) {
                k = *kind;
                switch (k) {
                case 9:
                    x = *best;
                    y = *(u16 *)(rec + 0xC);
                    if (x < y) {
                        x = y;
                    }
                    *best = x;
                    break;
                case 0x209:
                    x = *best;
                    y = *(u16 *)(rec + 0x10);
                    if (x < y) {
                        x = y;
                    }
                    *best = x;
                    break;
                case 0xD:
                    x = *best;
                    y = *(u16 *)(rec + 0xC);
                    if (x < y) {
                        x = y;
                    }
                    *best = x;
                    y = *(u16 *)(rec + 0x10);
                    if (x < y) {
                        x = y;
                        *best = y;
                    }
                    y = *(u16 *)(rec + 0x14);
                    if (x < y) {
                        x = y;
                    }
                    *best = x;
                    break;
                case 0x20D:
                    x = *best;
                    y = *(u16 *)(rec + 0x10);
                    if (x < y) {
                        x = y;
                    }
                    *best = x;
                    y = *(u16 *)(rec + 0x14);
                    if (x < y) {
                        x = y;
                        *best = y;
                    }
                    y = *(u16 *)(rec + 0x18);
                    if (x < y) {
                        x = y;
                    }
                    *best = x;
                    break;
                case 0x11:
                    x = *best;
                    y = *(u16 *)(rec + 0xE);
                    if (x < y) {
                        x = y;
                    }
                    *best = x;
                    break;
                case 0x211:
                    x = *best;
                    y = *(u16 *)(rec + 0x12);
                    if (x < y) {
                        x = y;
                    }
                    *best = x;
                    break;
                case 0x15:
                    x = *best;
                    y = *(u16 *)(rec + 0xA);
                    if (x < y) {
                        x = y;
                    }
                    *best = x;
                    y = *(u16 *)(rec + 0x10);
                    if (x < y) {
                        x = y;
                        *best = y;
                    }
                    y = *(u16 *)(rec + 0x14);
                    if (x < y) {
                        x = y;
                    }
                    *best = x;
                    y = *(u16 *)(rec + 0x18);
                    if (x < y) {
                        x = y;
                    }
                    *best = x;
                    break;
                case 0x215:
                    x = *best;
                    y = *(u16 *)(rec + 0xE);
                    if (x < y) {
                        x = y;
                    }
                    *best = x;
                    y = *(u16 *)(rec + 0x14);
                    if (x < y) {
                        x = y;
                        *best = y;
                    }
                    y = *(u16 *)(rec + 0x18);
                    if (x < y) {
                        x = y;
                    }
                    *best = x;
                    y = *(u16 *)(rec + 0x1C);
                    if (x < y) {
                        x = y;
                    }
                    *best = x;
                    break;
                }
            }
            rec = rec + stride;
            *total = *total + step;
        } while (--n != -1);
    }
    return count;
}
