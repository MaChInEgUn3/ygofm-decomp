/* 278/278, 267 differing (2026-09-05); the previous candidate was +2 at 69.
 * The length closed on ONE borrow: `o2 = (u32)arg0;` before the dispatcher,
 * with both `>= 2` / `< 2` tests on `o2` -- a name whose real assignments
 * are the dispatcher arms. The 267 is a positional count on a candidate
 * whose length only just came right and says nothing yet about how far the
 * registers are; the (length, census, differences) rule ranks this above
 * the +2. From the stored permuter output re-score.
 * Then `(u32)o2 >= 2` on the FIRST test only: the base's census was
 * `slti +1 / sltiu -1`, casting both is the mirror, and one cast is the
 * census retail has for the compares (alignment 274 -> 275/278). Left in
 * the census: `sra +1 / srl -1`, one shift retail does unsigned.
 */
#include "common.h"

s32 func_8004D134(s32 arg0, u16 *arg1, u8 *arg2, s32 *arg3, s32 *arg4) {
    u8 *rec;
    u8 *e;
    u8 *h;
    u8 *u;
    s32 n;
    s32 i;
    s32 o1;
    s32 o2;
    s32 step;
    s32 adv;
    s32 bias;
    s32 big;
    s32 w;
    s32 t;
    s32 b;
    s32 x;
    s32 z;
    s32 v;
    s32 m;

    rec = *(u8 **)arg2;
    n = *(u16 *)(rec + 2);
    e = (u8 *)(*(s32 *)(arg2 + 0x14) + *(s32 *)(rec + 4) * 4);
    o2 = (u32)arg0;
    if ((u32)o2 >= 2) {
        return 0;
    }
    switch ((u32)*arg1) {
    case 9:
        o1 = 6; o2 = 2; step = 0x14; adv = 0x20;
        break;
    case 0x209:
        o1 = 0xA; o2 = 6; step = 0x18; adv = 0x20;
        break;
    case 0xD:
    case 0x11:
        o1 = 6; o2 = 2; step = 0x18; adv = 0x28;
        break;
    case 0x20D:
    case 0x211:
        o1 = 0xA; o2 = 6; step = 0x1C; adv = 0x28;
        break;
    case 0x15:
        o1 = 6; o2 = 2; step = 0x1C; adv = 0x34;
        break;
    case 0x215:
        o1 = 0xA;
        o2 = 6;
        step = 0x20;
        do { adv = 0x34; } while (0);
        break;
    default:
        return 0;
    }
    bias = arg0 * 4 - 0xA;
    big = arg0 * 16 + 0x3BD8;
    h = e + 0x1C;
    for (i = n - 1; i != -1; i--) {
        if (o2 < 2) {
            w = *(u16 *)(e + o1);
            t = w + bias;
            *(u16 *)(e + o1) = t;
            b = (w >> 7) & 3;
            if (b >= 3) {
                *(u16 *)(e + o1) = t & 0xFF7F;
            }
            if (b < 2) {
                u = e + o2;
                x = *(u16 *)u;
                v = x + big;
                z = x;
            z = z >> 6;
                *(u16 *)u = v;
                if (z >= 0x10) {
                    v = (v & 0x3F) + 0x10;
                    *(u16 *)u = v;
                    *(u16 *)u = v | ((z % 16) << 6);
                }
            }
        }
        if (arg3 != 0) {
            switch ((u32)*arg1) {
            case 9:
                m = *arg3;
                if (m < *(u16 *)(h - 0x10)) {
                    m = *(u16 *)(h - 0x10);
                }
                *arg3 = m;
                break;
            case 0x209:
                m = *arg3;
                if (m < *(u16 *)(h - 0xC)) {
                    m = *(u16 *)(h - 0xC);
                }
                *arg3 = m;
                break;
            case 0xD:
                m = *arg3;
                if (m < *(u16 *)(h - 0x10)) {
                    m = *(u16 *)(h - 0x10);
                }
                *arg3 = m;
                if (m < *(u16 *)(h - 0xC)) {
                    m = *(u16 *)(h - 0xC);
                }
                *arg3 = m;
                if (m < *(u16 *)(h - 0x8)) {
                    m = *(u16 *)(h - 0x8);
                }
                *arg3 = m;
                break;
            case 0x20D:
                m = *arg3;
                if (m < *(u16 *)(h - 0xC)) {
                    m = *(u16 *)(h - 0xC);
                }
                *arg3 = m;
                if (m < *(u16 *)(h - 0x8)) {
                    m = *(u16 *)(h - 0x8);
                }
                *arg3 = m;
                if (m < *(u16 *)(h - 0x4)) {
                    m = *(u16 *)(h - 0x4);
                }
                *arg3 = m;
                break;
            case 0x11:
                m = *arg3;
                if (m < *(u16 *)(h - 0xE)) {
                    m = *(u16 *)(h - 0xE);
                }
                *arg3 = m;
                break;
            case 0x211:
                m = *arg3;
                if (m < *(u16 *)(h - 0xA)) {
                    m = *(u16 *)(h - 0xA);
                }
                *arg3 = m;
                break;
            case 0x15:
                m = *arg3;
                if (m < *(u16 *)(h - 0x12)) {
                    m = *(u16 *)(h - 0x12);
                }
                *arg3 = m;
                if (m < *(u16 *)(h - 0xC)) {
                    m = *(u16 *)(h - 0xC);
                }
                *arg3 = m;
                if (m < *(u16 *)(h - 0x8)) {
                    m = *(u16 *)(h - 0x8);
                }
                *arg3 = m;
                if (m < *(u16 *)(h - 0x4)) {
                    m = *(u16 *)(h - 0x4);
                }
                *arg3 = m;
                break;
            case 0x215:
                m = *arg3;
                if (m < *(u16 *)(h - 0xE)) {
                    m = *(u16 *)(h - 0xE);
                }
                *arg3 = m;
                if (m < *(u16 *)(h - 0x8)) {
                    m = *(u16 *)(h - 0x8);
                }
                *arg3 = m;
                if (m < *(u16 *)(h - 0x4)) {
                    m = *(u16 *)(h - 0x4);
                }
                *arg3 = m;
                if (m < *(u16 *)h) {
                    m = *(u16 *)h;
                }
                *arg3 = m;
                break;
            }
        }
        h += step;
        *arg4 = *arg4 + adv;
        e += step;
    }
    return n;
}
