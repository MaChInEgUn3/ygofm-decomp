#include "common.h"
u8 *func_8005CEF0(u8 **arg0) {
    u8 *s1;
    u8 *fr;
    u8 *dst;
    u8 *out;
    s32 t;
    s32 dur;
    u32 w;
    u32 n;
    s32 v;
    u16 a0;
    u16 a1;
    u16 a2;
    u16 b0;
    u16 b1;
    u16 b2;
    s1 = ((u8 *)arg0) + (*(s32 *)(((u8 *)arg0) + 0x14) * 4 + 0x14);
    fr = *(u8 **)s1;
    if (*(u16 *)(fr + 0x12) == 0) {
        return (u8 *)1;
    }
    t = *(s16 *)(fr + 0x10);
    dur = *(u16 *)(fr + 0x12);
    w = *(s32 *)fr;
    n = w >> 24;
    w &= 0xFFFFFF;
    dst = *(u8 **)(((u8 *)arg0) + n * 4 + 0x14) + w * 4;
    *(s32 *)(dst + 0x18) = (*(s16 *)((*(u8 **)(s1 + 4)) + 0) * t + *(s16 *)((*(u8 **)(s1 + 8)) + 0) * (dur - t)) / dur;
    *(s32 *)(dst + 0x1C) = (*(s16 *)((*(u8 **)(s1 + 4)) + 2) * t + *(s16 *)((*(u8 **)(s1 + 8)) + 2) * (dur - t)) / dur;
    *(s32 *)(dst + 0x20) = (*(s16 *)((*(u8 **)(s1 + 4)) + 4) * t + *(s16 *)((*(u8 **)(s1 + 8)) + 4) * (dur - t)) / dur;
    b0 = *(u16 *)((*(u8 **)(s1 + 8)) + 6);
    b1 = *(u16 *)((*(u8 **)(s1 + 8)) + 8);
    b2 = *(u16 *)((*(u8 **)(s1 + 8)) + 0xA);
    a0 = *(u16 *)((*(u8 **)(s1 + 4)) + 6);
    a1 = *(u16 *)((*(u8 **)(s1 + 4)) + 8);
    a2 = *(u16 *)((*(u8 **)(s1 + 4)) + 0xA);
    if (dur == 16) {
        if ((s16)a0 - (s16)b0 < 0) {
            goto n0;
        }
        if ((s16)a0 - (s16)b0 >= 0x801) {
            goto w0;
        }
        goto d0;
    n0:
        if ((s16)b0 - (s16)a0 < 0x801) {
            goto d0;
        }
    w0:
        v = (s16)b0;
        if (v > 0) {
            v = v - 0x1000;
        } else {
            v = v + 0x1000;
        }
        b0 = v;
    d0:
        ;
        if ((s16)a1 - (s16)b1 < 0) {
            goto n1;
        }
        if ((s16)a1 - (s16)b1 >= 0x801) {
            goto w1;
        }
        goto d1;
    n1:
        if ((s16)b1 - (s16)a1 < 0x801) {
            goto d1;
        }
    w1:
        v = (s16)b1;
        if (v > 0) {
            v = v - 0x1000;
        } else {
            v = v + 0x1000;
        }
        b1 = v;
    d1:
        ;
        if ((s16)a2 - (s16)b2 < 0) {
            goto n2;
        }
        if ((s16)a2 - (s16)b2 >= 0x801) {
            goto w2;
        }
        goto d2;
    n2:
        if ((s16)b2 - (s16)a2 < 0x801) {
            goto d2;
        }
    w2:
        v = (s16)b2;
        if (v > 0) {
            v = v - 0x1000;
        } else {
            v = v + 0x1000;
        }
        b2 = v;
    d2:
        ;
    }
    *(s16 *)(dst + 0x44) = ((s16)a0 * t + (s16)b0 * (dur - t)) / dur;
    *(s16 *)(dst + 0x46) = ((s16)a1 * t + (s16)b1 * (dur - t)) / dur;
    *(s16 *)(dst + 0x48) = ((s16)a2 * t + (s16)b2 * (dur - t)) / dur;
    func_80089060(dst + 0x44, dst + 4);
    *(s32 *)dst = 0;
    out = *(u8 **)(s1 + 0xC);
    if (out != 0) {
        *(u16 *)(*(u8 **)(s1 + 0xC) + 0x0) = *(u16 *)(dst + 0x18);
        *(u16 *)(*(u8 **)(s1 + 0xC) + 0x2) = *(u16 *)(dst + 0x1C);
        *(u16 *)(*(u8 **)(s1 + 0xC) + 0x4) = *(u16 *)(dst + 0x20);
        *(u16 *)(*(u8 **)(s1 + 0xC) + 0x6) = *(u16 *)(dst + 0x44);
        *(u16 *)(*(u8 **)(s1 + 0xC) + 0x8) = *(u16 *)(dst + 0x46);
        *(u16 *)(*(u8 **)(s1 + 0xC) + 0xA) = *(u16 *)(dst + 0x48);
    }
    return (u8 *)0;
}
