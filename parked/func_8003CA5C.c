#define D_8009B398_IS_AGGREGATE
#include "common.h"

/* 4 differences, a $v0/$v1 swap on the second tail test's load chain in one
 * basic block -- retail keeps the delay-slot 1 live in $v0 and loads
 * D_8009B398 through $v1; we reuse $v0. Two permuter runs saturated here
 * and a named return-1 does not move it. The two finds that got 13 -> 4,
 * both permuter's: the +0x5A halfword named into w, and the dead
 * identical-arms if on D_8009B378 around return 0, which is what stops
 * gcc folding the test into sltiu (five hand shapes could not). */

void func_800429D8(u8 *arg0);

s32 func_8003CA5C(void) {
    u8 *p;
    s16 w;

    p = (u8 *)D_8009B378;
    func_80042A00(p);
    w = *(s16 *)(p + 0x5A);
    if (w == 0) {
        switch (p[0x6C]) {
        case 0:
            func_80040410(p, 1);
            p[0x6C] = 1;
            *(s16 *)(p + 0x36) = -0xC0;
            break;
        case 1:
            func_800429D8(p);
            func_80040410(p, 2);
            p[0x6C] = 2;
            break;
        case 2:
            func_80040410(p, 0);
            p[0x6C] = 0;
            if (*(s16 *)(p + 0x30) < -0x2F) {
                *(s16 *)(p + 0x30) = 0x160;
                *(s16 *)(p + 0x32) = func_800358FC(0xB0) + 0x30;
            }
            break;
        }
    }
    if (D_800E9ECE[0] & 0x80) {
        return 1;
    }
    if (D_8009B398[0] & 0xE0) {
        if (D_8009B378 != 0) {
            return 0;
        } else {
            return 0;
        }
    }
    return 1;
}
