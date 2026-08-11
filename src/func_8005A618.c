#include "common.h"

/* Parked at 15 until the int-cast lever: the two computations of the same
 * base+offset want opposite addu operand orders, so the first is pointer
 * arithmetic ((D_800F3938 + o)[0x106], base first) and the second is named
 * integer arithmetic (r2 = o + (s32)D_800F3938, index first) -- the name
 * also keeps r2 independent of the lbu so it fills the load-delay slot.
 * The modulo is written per arm; gcc cross-jumps the sra/sll/subu tail and
 * keeps each arm's folded bias, which is retail's shape. */

s32 func_8005A618(s32 arg0) {
    s32 o = arg0 * 3616;
    u8 *p;
    s32 x;
    s32 r2;
    s32 t;

    r2 = o + (s32)D_800F3938;
    p = func_8005F1A4(*(u8 *)(r2 + (D_800F3938 + o)[0x106] + 0xA) & 0x1F);

    x = *(s16 *)(p + 2);
    if (arg0 <= 0) {
        t = x + 0x1C00;
        return t % 4096;
    }
    t = x + 0x1400;
    return t % 4096;
}
