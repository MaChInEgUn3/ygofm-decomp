#include "common.h"

/* Renders a bytecode operand into the buffer at +0x44 and pushes that back
 * onto the caller's little handle stack. Five shapes:
 *  - the fetch is two names (`t = *(*cursor)++; c = t;`); retail copies the
 *    loaded byte into a callee-saved register and one name gives no copy.
 *  - both loops are written with the test INSIDE, not as a `while` with a
 *    header: retail has no entry guard on either, so a top-tested while
 *    either duplicates the test or jumps forward into it.
 *  - `p - -(idx * 4)` for both stack accesses; the plain `+` comes out
 *    index-first and retail has the base first.
 *  - `e = p + 0x44` is written THREE times, once per path, because the
 *    listing materialises it three times.
 *  - and the buffer base is named before the trim loop's counter, which is
 *    the only thing that orders those two preheader instructions. */

void func_80038148(u8 *p) {
    u8 buf[8];
    u8 *e;
    u8 *bp;
    s32 r;
    s32 c;
    s32 t;
    s32 k;
    s32 i;
    s32 h;
    s32 w;

    r = func_80036D70(p);
    t = *(*(u8 **)(p - -(*(s8 *)(p + 0x58) * 4)))++;
    c = t;
    func_800357E8(*(s32 *)r, c & 0xF, buf);

    h = 0;

    if ((c & 0x80) != 0) {
        if ((c & 0x40) == 0) {
            goto skip;
        }
        h = *(u16 *)&D_800EAFF8[0];
        e = p + 0x44;
        goto write;
    }

    if (c < 2) {
        e = p + 0x44;
        goto write;
    }

    bp = buf;
    k = c - 1;
    while (1) {
        if (bp[k] < 10) {
            break;
        }
        c = k;
        if (k < 2) {
            break;
        }
        k = c - 1;
    }

skip:
    e = p + 0x44;

write:
    i = (c & 0xF) - 1;
    do {
        w = h;
        if (buf[i] < 10) {
            w = *(u16 *)&D_800EAFF8[buf[i]];
        }
        if (w >= 0xF0) {
            *e = (w >> 8) - 0x10;
            e[1] = w;
            e += 2;
        } else {
            *e = w;
            e += 1;
        }
        i--;
    } while (i >= 0);

    *e = 0xFF;
    p[0x58] = p[0x58] + 1;
    *(u8 **)(p - -(*(s8 *)(p + 0x58) * 4)) = p + 0x44;
}
