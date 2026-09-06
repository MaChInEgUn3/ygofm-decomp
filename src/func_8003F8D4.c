/* MATCH 2026-09-06, first-day function from the m2c draft (257 instructions,
 * the memory-card save state machine: format, load, verify, retry). Jump
 * table on the mode nibble, so only the full build proves it. Levers, in
 * order: the scalar arm for D_8009B3EA; D_8009B398 on its .data VOLATILE arm
 * (retail reloads it for the second bit test and reads it bare); the call
 * arguments D_8009B3EE and D_8009B3C0 hoisted into locals BEFORE the +0x60
 * store that precedes the sprite call (-6 -> -1); ONE name for the sprite
 * pointer in cases 0 and 0xA, which is what puts it in $s0 (its live range
 * crosses the wait loop's calls in 0xA); the record passed to func_80035B7C
 * as its ADDRESS, index-first through the (s32) cast sum (m2c had read it as
 * a load); case 3's `v = 0` before the D_8009B3F9 store reaching a SHARED
 * `return v` through a goto, so the zero stays a variable; and the +0x34 flag
 * read through a block-local base `q = D_800EB0F8` so the 0x34 is a load
 * displacement rather than folded into %lo.
 */
#define D_8009B3EA_IS_SCALAR
#define D_8009B398_IN_DATA_VOLATILE
#include "common.h"

void func_80039794(void);
s32 func_8003F2B0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_8003F70C(void);

s32 func_8003F8D4(void) {
    u8 *o;
    s32 v;
    s32 m;
    u8 *q;
    s32 a;
    s32 b;

    m = D_8009B3EA & 0xF;
    switch (m) {
    case 0:
        if ((D_8009B3EA & 0x80) == 0) {
            D_8009B3EA |= 0x80;
            func_8003F388();
            a = D_8009B3EE;
            *(s16 *)(D_8009B3D8 + 0x60) = -0x400;
            o = func_80035BE4(a, 0xC2, 0x20, 0x50, 0x100, 0x30);
            o[0x59] = 0x10;
            func_80039A14(o);
        }
        if (func_8003F2B0(D_8009B3D8, 0x20, 0x50, D_8009B3EE) == 0) {
            D_8009B3EA = 1;
        }
        return 0;
    case 1:
        if (D_8009B398 & 0x20) {
            func_8003FEE0(8);
            D_8009B3EA = 0x82;
            *(s16 *)(D_8009B3D8 + 0x60) = 0x400;
        } else if (D_8009B398 & 0x40) {
            func_8003FEE0(7);
            D_8009B3EA = 2;
            *(s16 *)(D_8009B3D8 + 0x60) = 0x400;
        }
        return 0;
    case 2:
        if (func_8003F2B0(D_8009B3D8, 0x20, 0x100, D_8009B3EE) == 0) {
            func_80035B7C((u8 *)(D_8009B3EE * 100 + (s32)D_800EB0F8));
            func_8004036C((s32)D_8009B3D8);
            D_8009B3D8 = (u8 *)0;
            if ((D_8009B3EA & 0x80) == 0) {
                D_8009B3EA = 3;
                func_8003F758(D_801D1200, 0x680, D_80010384, 1);
                return 0;
            }
            return 2;
        }
        return 0;
    case 3:
        v = func_8003F70C();
        if (v != 0) {
            if (v == 1) {
                if (D_8009B3EA & 0x40) {
                    if (func_8003D288(D_801D1200, D_801D1200 + 0x1000) == 0) {
                        return 1;
                    }
                    D_8009B3EA = 0xA;
                    return 0;
                }
                D_8009B3EA |= 0x40;
                func_8003F758(D_801D2200, 0x680, D_80010384, 1);
                v = 0;
                D_8009B3F9 = 0x10;
                goto done;
            }
            return v;
        }
    done:
        return v;
    case 0xA:
        if ((D_8009B3EA & 0x80) == 0) {
            D_8009B3EA |= 0xC0;
            func_8003F388();
            a = D_8009B3EE;
            b = D_8009B3C0;
            *(s16 *)(D_8009B3D8 + 0x60) = -0x400;
            o = func_80035C38(a, b, 0x20, 0x50, 0x100, 0x30, 0x1008);
            o[0x59] = 0x10;
            do {
                func_80039794();
            } while ((*(u16 *)(o + 0x34) & 0x2000) == 0);
        }
        if (D_8009B3EA & 0x40) {
            if (func_8003F2B0(D_8009B3D8, 0x20, 0x50, D_8009B3EE) == 0) {
                D_8009B3EA &= 0xBF;
            }
            return 0;
        }
        func_80039794();
        q = (u8 *)D_800EB0F8;
        if ((*(u16 *)(q + D_8009B3EE * 100 + 0x34) & 8) == 0) {
            D_8009B3EA = 0xB;
        }
        return 0;
    case 0xB:
        if ((D_8009B3EA & 0x80) == 0) {
            D_8009B3EA |= 0x80;
            *(s16 *)(D_8009B3D8 + 0x60) = 0x400;
        }
        if (func_8003F2B0(D_8009B3D8, 0x20, 0x100, D_8009B3EE) == 0) {
            func_80035B7C((u8 *)(D_8009B3EE * 100 + (s32)D_800EB0F8));
            func_8004036C((s32)D_8009B3D8);
            D_8009B3D8 = (u8 *)0;
            return 2;
        }
        return 0;
    }
    return 0;
}
