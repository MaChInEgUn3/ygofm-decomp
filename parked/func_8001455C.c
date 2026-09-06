/* -1 at 319/320 and 17 truly-different instructions (2026-09-06, first
 * pass). gp=69, at=0, default flags; a jump table for the seven-case switch
 * on D_8009B100, so this one cannot be offered upstream.
 * What it needed:
 *   - a per-file guard, LIBCD_CALLS_RETURN_S32: this unit tests the result
 *     of every func_8007B1F4 / func_8007B468 call, where functions.h declares
 *     both `void` for the callers that already match;
 *   - D_8009B0EC and D_8009B11D declared (both new);
 *   - each `D_8009B0F4 |= 0x400;` written as its own read-modify-write with
 *     a plain `return`, NOT as `v = D_8009B0F4 | 0x400; goto store;`. The
 *     shared-store spelling lets cross-jumping merge two of the three arms
 *     back into one and is -6; retail shares only the final `sw` plus the
 *     epilogue, which is what gcc leaves when each arm writes the global
 *     itself (314 -> 321);
 *   - the D_8009B120 callback pointer read into a local in BOTH predecessors
 *     of the shared `if (f) f();` block -- case 1's arm and the case 6 tail --
 *     which is retail's duplicated-argument-setup shape (321 -> 319 and 168
 *     differences to 139).
 * Residue, three faults that nearly cancel: (1) +2, the two-byte CD location
 * argument: retail forms `addiu $t1,$gp,%gp_rel(D_8009B11D)` once and reaches
 * the first byte as `-1($t1)` with `$a1 = $t1 - 1`, while every spelling here
 * folds the -1 into %lo(D_8009B11D+-1) and emits a %hi/%lo pair per access --
 * six tried (a base local, the store through the local or through the symbol,
 * `&D_8009B11D - 1` hoisted, a `[1]` array arm, an unsized-array arm, and
 * naming D_8009B11C instead, which is -2 and much worse); (2) -2, the
 * e[0x47] dispatch: retail branches to BOTH arms and reaches the return with
 * its own `j`, where ours falls through into arm 1. Laying both arms out as
 * `goto` targets in retail's order is +2 rather than -2, and so is a
 * `switch`; (3) -1, the completion callback: retail copies the counter into
 * $a1 and leaves the load's delay slot empty where we reload the function
 * pointer into it. A second name for the counter (three placements), a named
 * function pointer, and moving the increment after the call are all 319 or
 * much worse. */
#define LIBCD_CALLS_RETURN_S32
#include "common.h"

void func_800144B8(void);
void func_80014390(u8 arg0);
s32 func_80077240(s32 arg0);
void func_8007E600(s32 arg0, s32 *arg1);

void func_8001455C(void) {
    u8 *e;
    s32 n;
    u16 t;
    u8 *q;
    void (*f)(void);

    e = D_800E9E60;
    if (D_8009B0F4 & 0x1000) {
        if ((D_8009B0F4 & 0x800) == 0) {
            if (func_8007B1F4(0x10, (void *)0, func_80014390, 0) > 0) {
                D_8009B0F4 |= 0x800;
            }
        }
    }
    if (D_8009B0F4 & 0x400) {
        return;
    }
    if (D_8009B0F4 & 0x80000) {
        if ((D_8009B112 & 0x8000) == 0) {
            D_8009B112 |= 0x8000;
            if ((D_8009B112 & 3) == 0) {
                goto stop;
            }
            if ((D_8009B112 & 0x2000) == 0) {
                D_8009B100 = 0;
            }
            if (D_8009B112 & 2) {
                D_8009B112 &= 0xFFFE;
            } else {
                *(s32 *)(e + 0x30) = 0;
            }
        }
        t = D_8009B100;
        switch (t) {
        case 0:
            D_8009B112 |= 0x2000;
            D_8009B100 = 1;
        case 1:
            if (func_8007B1F4(9, (void *)0, func_80014220, -1) > 0) {
                D_8009B0F4 |= 0x400;
                f = (void (*)(void))D_8009B120;
                goto docb;
            }
            break;
        case 2:
            D_8009B112 &= 0xDFFF;
            if ((D_8009B112 & 1) == 0) {
stop:
                D_8009B112 = 0;
done:
                func_800144B8();
                return;
            }
            D_8009B100 = 3;
        case 3:
            D_8009B112 |= 0x1000;
            q = &D_8009B11D;
            *q = e[0x38];
            q[-1] = e[0x39];
            if (func_8007B1F4(0xD, q - 1, func_80014294, -1) > 0) {
                D_8009B0F4 |= 0x400;
                return;
            }
            break;
        case 4:
            func_8007E600(*(s32 *)(e + 0x24), &D_8009B104);
            if (func_8007B468(0x4A, &D_8009B104, 0x1B, func_80014308, -1) > 0) {
                D_8009B0F4 |= 0x400;
                return;
            }
            break;
        case 5:
            D_8009B100 = 6;
            D_8009B0EC = 0x258;
            D_8009B112 &= 0xEFFF;
            D_8009B112 |= 0x4000;
            if (D_8009B0F0 != 0) {
                (*(void (**)(void))&D_8009B0F0)();
            }
        case 6:
            t = D_8009B0EC - 1;
            D_8009B0EC = t;
            if ((s16)t > 0) {
                if (*(s32 *)(e + 0x30) < *(s32 *)(e + 0x34)) {
                    return;
                }
            }
            D_8009B112 &= 0x3FFC;
            D_8009B112 |= 2;
            f = (void (*)(void))D_8009B120;
docb:
            if (f != 0) {
                f();
            }
            break;
        }
        return;
    }
    if (e[0x46] == 5) {
        if (e[0x47] == 0) {
            func_8007DDD4();
            func_8007E860((void (*)(void))0);
            if (func_8007B1F4(9, (void *)0, func_800141A8, -1) > 0) {
                D_8009B0F4 |= 0x400;
                return;
            }
            return;
        }
        if (e[0x47] == 1) {
            func_8007DDD4();
            func_8007E860((void (*)(void))0);
            goto done;
        }
        return;
    }
    if (D_8009B0F4 & 0x80) {
        if (D_8009B0F4 & 0x100) {
            return;
        }
        goto done;
    }
    func_8007E600(*(s32 *)(e + 0x24), &D_8009B104);
    if (D_8009B0F4 & 0x100000) {
        if (D_8009B0F4 < 0) {
            goto done;
        }
        if (func_8007B468(0xA0, &D_8009B104, 0x15, func_80014134, -1) > 0) {
            D_8009B0F4 |= 0x480;
            return;
        }
        return;
    }
    if ((D_8009B0F4 & 0x800000) == 0) {
        D_8009B0F4 |= 0x800000;
        if (*(s32 *)(e + 0x20) != 0) {
            n = *(s32 *)(e + 0x40);
            *(s32 *)(e + 0x40) = n + 1;
            (*(void (**)(u8 *, s32))(e + 0x20))(e, n);
        }
        *(s32 *)(e + 0x28) = *(s32 *)(e + 0x1C);
        return;
    }
    if (D_8009B0F4 & 0x400000) {
        if (func_80077240(0) == 0) {
            return;
        }
        D_8009B0F4 &= 0xFFBFFFFF;
    }
    if (D_8009B0F4 >= 0) {
        if (func_8007B468(0xA0, &D_8009B104, 6, func_800140A0, -1) == 0) {
            return;
        }
        D_8009B0F4 |= 0x400;
    }
    D_8009B0F4 |= 0x180;
}
