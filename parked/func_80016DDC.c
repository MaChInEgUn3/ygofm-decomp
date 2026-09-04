/* Natural form: 11 differing instructions.
 *
 * Replacing the guard with `a = d == 0; if (a) return;` reaches 1 -- using the
 * variable for the early test makes it live before the abs and fixes the whole
 * register assignment of the band selection. That is not plausible source and
 * it is not this candidate; it is recorded here so the next attempt knows the
 * register assignment is reachable and the remaining instruction is
 * `subu $a1,$zero,$a1`, retail negating the copy where gcc negates the
 * original. Do not start from the artificial guard: it is one instruction out
 * and structurally wrong, which is a worse place to start than eleven out and
 * right.
 */
#include "common.h"

void func_80016DDC(u8 *arg0) {
    s32 d = *(s16 *)(arg0 + 0x12) - *(s16 *)(arg0 + 0x14);
    s32 a;
    s32 step;

    if (d == 0) {
        return;
    }

    a = d;
    if (a < 0) {
        a = -a;
    }

    step = 9;
    if (a >= 0x12C) {
        step = 0x13;
    }
    if (a >= 0x3E8) {
        step = 0x2F;
    }
    if (a >= 0xBB8) {
        step = 0x61;
    }

    if (d > 0) {
        d -= step;
        if (d < 0) {
            d = 0;
        }
    } else {
        d += step;
        if (d > 0) {
            d = 0;
        }
    }

    *(u16 *)(arg0 + 0x12) = *(u16 *)(arg0 + 0x14) + d;
}
