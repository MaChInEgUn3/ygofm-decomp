/* Volatile, and that is the whole of the last two differences: retail
 * materialises the 0x2000 it compares D_8009B3A4 against inside the test's
 * own block, and a plain read lets gcc hoist the constant into the preceding
 * branch's delay slot. Found by sweep_guards.py, whose comment on this
 * symbol -- "func_80023FBC reads it five times in a row and retail reloads
 * each time" -- is the same observation. */
#define D_8009B3A4_IS_VOLATILE
#define D_8009B254_IS_SCALAR
#define D_8009B398_IS_VOLATILE
#include "common.h"

void func_800320BC(u8 *arg0, s32 arg1);
void func_80031F7C(u8 *arg0, s32 arg1);
void func_80031574(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

void func_800336F0(u8 *p) {
    u8 *e;
    u8 *q;
    s32 r;
    u32 c;

    e = p + (p[0x6342] * 0x2D4C + 4);
    func_80032B38(p);
    if (func_800330BC(e) != 0) {
        return;
    }

    if ((D_8009B398 & 0x10) != 0) {
        r = func_80033500(e);
        if (r != 0) {
            D_8009B24B = 0x14;
            D_8009B246 = r;
            D_8009B254 = 2;
        }
        return;
    }

    if (D_8009B3A4 == 0x2000) {
        *(s32 *)(p + 0x5AA4) = 0x140;
        *(s16 *)(p + 0x633E) = 1;
        *(s16 *)(p + 0x6340) = 3;
        return;
    }

    if ((D_8009B398 & 0x20) != 0) {
        *(s16 *)(p + 0x633E) = 4;
        *(s16 *)(p + 0x6340) = 2;
        return;
    }

    if ((D_8009B394 & 0xC0) == 0) {
        return;
    }

    r = func_80033500(e);
    c = 1;
    if ((u32)(r - 0x11) < 5) {
        c = (p + r)[0x5AC4] < c;
    }

    if (r != 0 && c != 0) {
        q = p + r;
        if (*(s32 *)(p + 0x5AA0) < 0x28 && q[0x5D97] != 0 && q[0x5AC4] < 3) {
            func_8003FEE0(7);
            func_800320BC(p, r);
            func_80031F7C(p, r);
            func_80031E5C(p);
            func_80031574(r, 3, 0x18, 0x11C, 0xC);
            return;
        }
    }

    func_8003FEE0(9);
}
