/* Two shapes carry this one.
 *
 * The 0x2000001 the loop compares against is materialised in the *prologue*,
 * before anything else -- gcc's loop pass will not hoist a constant load out
 * of this loop on its own (it did not, at any statement position inside the
 * `if`), and a local assigned at the very top of the function is what puts the
 * lui/ori where retail has them, ahead of even `i = 0`.
 *
 * And `- 0x280 + sh` must not be allowed to fold: written as one expression
 * gcc reassociates it to `x + (sh - 0x280)` and hoists that sum out of the
 * loop as an invariant, which retail does not have. Naming the loaded value
 * first and grouping the subtraction with it keeps retail's
 * addiu -0x280 / addu $a0 pair at both sites. The two sites want *different*
 * names -- one `v` for both is the last two differences, the same
 * two-unrelated-values-two-names rule as everywhere else. */
#include "common.h"

typedef void (*Slot)(u8 *);

Slot func_800603DC(s32 arg0);

void func_80060220(s32 arg0, u8 *arg1, u8 *arg2) {
    u8 *p;
    u8 *q;
    u8 *b;
    u16 *e;
    u8 *r;
    u8 *rec;
    s32 n;
    s32 i;
    s32 j;
    s32 k;
    s32 f;
    s32 sh;
    s32 v;
    s32 w;
    s32 m;

    m = 0x2000001;
    i = 0;
    q = *(u8 **)arg2;
    r = arg2;
    n = *(u16 *)(q + 2);
    q += 4;

    if (n != 0) {
        f = arg0 < 2;
        sh = arg0 << 8;
        p = q;


        do {
            q = p + 0xC;
            if (*(s32 *)arg1 == m) {
                b = *(u8 **)(r + 0x18);
                if (b != (u8 *)0) {
                    j = 0;
                    e = (u16 *)(b + *(s32 *)(q + 8) * 4);
                    rec = q;
                    if (*(s16 *)(q + 6) > 0) {
                        do {
                            if (f) {
                                *e = 0;
                            }
                            e++;
                            for (k = 1; k < *(s16 *)(rec + 4); k++) {
                                *e |= 0x8000;
                                e++;
                            }
                            j++;
                        } while (j < *(s16 *)(rec + 6));
                    }
                    if (f) {
                        v = *(u16 *)rec;
                        if (*(s16 *)rec >= 0x280) {
                            *(u16 *)rec = (v - 0x280) + sh;
                        } else {
                            *(u16 *)rec = sh;
                        }
                        v = *(s16 *)(rec + 2);
                        if (v >= 8) {
                            *(s16 *)(rec + 2) = v % 8;
                        }
                        *(u16 *)(rec + 2) = *(u16 *)(rec + 2) + 0xF8;
                    }
                    q += 0xC;
                }
            }
            if (f) {
                w = *(u16 *)p;
                *(u16 *)p = (w - 0x280) + sh;
            }
            i++;
            p = q;

        } while (i < n);
    }

    func_800603DC(*(s32 *)arg1)(arg2);
    func_8007F6CC(0);
    *(u8 *(**)(u8 **))(*(s32 *)(arg1 + 4)) = func_80089E20;
}
