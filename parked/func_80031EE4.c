/* 18 differing instructions.
 *
 * The search loop is right -- do/while with a break, which is what produces
 * retail's single tight `bne` back-edge; a plain `while` makes gcc emit a
 * guard as well, and the natural form costs six more.
 *
 * What is left: retail undoes the delay-slot overshoot with its own
 * `addiu $v1,$v1,-16` and then stores at 13($v1); gcc folds the two into
 * `sb $v0,-3($v1)`. A 0x10-byte record type with `q--` folds the same way.
 * The permuter reaches zero by holding 0x10 in a variable so the subtraction
 * cannot be folded -- that is not source, but it does say the remaining
 * difference is only the fold, and that anything preventing it finishes the
 * function.
 */
#include "common.h"

void func_80031EE4(u8 *arg0, s32 arg1) {
    u8 *p = arg0 + arg1;
    s32 raw = p[0x5D97];
    s32 c = raw & 0xFF;

    if (c == 0) {
        u8 *q = arg0 + 4;

        *(s32 *)(arg0 + 0x5A9C) += 1;
        p[0x5D97] = p[0x5D97] + 1;

        do {
            s32 e = *(s16 *)(q + 4);

            q += 0x10;
            if (e == arg1) {
                break;
            }
        } while (1);

        q -= 0x10;
        q[0xD] = 1;
        func_80032C48(arg0 + 4);
    } else if (c != 0xFA) {
        p[0x5D97] = raw + 1;
        *(s32 *)(arg0 + 0x5A9C) += 1;
    }
}
