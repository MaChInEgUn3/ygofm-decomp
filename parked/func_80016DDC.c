/* ONE differing instruction at 37/37: retail has `subu $a1,$zero,$a1`,
 * negating the COPY, and gcc emits `subu $a1,$zero,$v1`, negating the
 * original, because it knows the copy still equals `d` and propagates it.
 * Every register is now correct.
 *
 * 2026-09-04, 11 -> 1 on ONE line: `do { a = -a; } while (0);`.
 * The permuter found it as an identical-arm `if (arg0) { a = -a; } else
 * { a = -a; }` paired with `d -= step` rewritten as `d = d - step`.
 * Decomposed: the rewrite is worth NOTHING (11), the identical-arm `if` alone
 * is 1, and the `do { } while (0);` alone is also 1 -- so the plausible
 * spelling reaches the whole gain and the implausible one is not needed. Read
 * it as a macro in the original, which is what that idiom is for.
 *
 * The header this file used to carry explained the earlier 1-difference
 * variant as "making the variable live before the abs". That was WRONG and is
 * retracted: eight spellings of it were measured (initialiser above the guard,
 * guard on `a`, declaration order, ternary abs, the difference computed into
 * `a` first, `step = 9` hoisted two ways) and every one is 12 or worse.
 *
 * The last instruction is copy propagation and four attempts do not move it,
 * all still 1: wrapping the copy in its own `do { } while (0);`, testing
 * `d < 0` instead of `a < 0`, both together, and writing the negation as
 * `a = 0 - a;`.
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
        do { a = -a; } while (0);
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
