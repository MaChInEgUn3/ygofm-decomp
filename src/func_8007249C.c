#include "common.h"

/* Draws four indices from func_8007058C -- three resolve through
 * D_800F5B98, the fourth keeps both the raw index and its slot pointer --
 * then scans D_801AB000[1..5] for a target and writes the winner into the
 * slot, or re-materialises the symbol to zero it (the cursor clobbered the
 * base register, so the tail's inline symbol is the natural dup-%hi). Two
 * permuter names close the allocation: the table base named in passing
 * inside the for-init, and the func_80070920 boolean named -- together
 * they stop the b == 1 constant being hoisted into an eighth callee-saved
 * where retail rematerialises it per iteration. */

void func_8007249C(void) {
    s32 a;
    s32 b;
    Rec12 *base;
    s32 r;
    s32 c;
    s32 i4;
    s32 *slot;
    Rec12 *q;
    s32 i;

    a = D_800F5B98[func_8007058C()];
    b = D_800F5B98[func_8007058C()];
    c = D_800F5B98[func_8007058C()];
    i4 = func_8007058C();
    slot = &D_800F5B98[i4];
    for (i = 1, q = (base = D_801AB000) + 1; i < 6; i++, q++) {
        if (q->unk0 == 0) {
            continue;
        }
        if (b == 1) {
            if (q->unk6 & 0x4000) {
                continue;
            }
        }
        r = func_80070920(c, i) != 0;
        if (r) {
            continue;
        }
        if (func_80019A08(a, q->unk0) == 0) {
            continue;
        }
        *slot = i;
        return;
    }
    D_800F5B98[i4] = 0;
}
