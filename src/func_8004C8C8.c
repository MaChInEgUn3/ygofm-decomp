/* MATCH (2026-09-05), from a park at 5. The one real difference was where
 * the cursor's initialising copy `p = b` sat: retail emits it AFTER the
 * loop's entry guard, in the preheader, and a rotated `for` puts it before
 * the guard's own load. The form that reproduces it is the explicit guard
 * plus `do { } while` (WORKFLOW's func_80060220 rule) with `i = 0; p = b;`
 * inside the guard -- in that order; `p = b; i = 0;` is 2 -- and the two
 * `continue`s rewritten as `goto next;` onto the increments at the bottom
 * of the body. Flags: -O2 -G8 -fno-strength-reduce, as -G0.
 */
#include "common.h"

s32 func_8004C8C8(void) {
    u8 *b;
    u8 *p;
    u8 *q;
    s32 i;
    s32 v;
    s32 t;
    s32 r;
    s32 d;
    u32 w;

    b = D_8009B458 + 0x518;

    if (*(s16 *)(b + 0x2CA) != 1) {
        return 0;
    }

    if (*(u16 *)(b + 0x2E2) != 0) {
        i = 0;
        p = b;
        do {
        if (p[0x24] != 0) {
            goto next;
        }

        v = *(u16 *)(p + 0x14) + *(u16 *)(p + 0x16);
        *(s16 *)(p + 0x14) = v;
        if ((u16)v < 0x100) {
            goto next;
        }
        *(s16 *)(p + 0x14) = v & 0xFF;

        if (i == *(u16 *)(b + 0x2E0)) {
            *(s32 *)(b + 0x2D8) += 1;
        }

        t = *(s32 *)(p + 0x1C);
        if (t != 0 && *(s32 *)(D_8009B458 + 0x80C) == 0) {
            d = t - 1;
            goto dec;
        }

        while (1) {
            func_8004C420(p);
            if (p[0x24] != 0) {
                break;
            }
            r = func_8004BB34(p);
            *(s32 *)(p + 0x1C) = r;
            if (r != 0) {
                if (*(s32 *)(D_8009B458 + 0x804) != 0) {
                    func_8004C5C8(p);
                }
                if (*(s32 *)(p + 0x1C) != 0) {
                    break;
                }
            }
        }

        d = *(s32 *)(p + 0x1C);
        if (d != 0) {
            d = d - 1;
        dec:
            *(s32 *)(p + 0x1C) = d;
        }

        q = D_8009B458;
        w = *(u32 *)(q + 0x7DC) + *(u32 *)(p + 0);
        *(u32 *)(q + 0x810) = w;
        if (*(u32 *)(q + 0x80C) != 0) {
            if (w >= *(u32 *)(q + 0x80C)) {
                *(u32 *)(q + 0x80C) = 0;
            }
        }
    next:
        p += 0x2C;
        i++;
        } while (i < *(u16 *)(b + 0x2E2));
    }

    return 0;
}
