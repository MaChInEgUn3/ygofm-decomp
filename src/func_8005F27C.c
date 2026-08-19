#include "common.h"

/* The multiply's shape is the whole of this function and its sibling, and
 * it took both halves at once. `u = d * t;` gives retail's operand order --
 * gcc's expand_binop swaps a commutative operator's operands when the
 * destination IS one of them, so `t = d * t` and `t = t * d` both emit
 * (t, d) -- and the copy back into `t` links the fresh pseudo to t's
 * register, which is where retail keeps the product. The copy itself is
 * coalesced away. Either half alone is three differences.
 *
 * The 750 is a local because retail divides with a real `div`: a literal
 * divisor becomes a reciprocal multiply and the tail is seven instructions
 * longer. */

void func_8005F27C(s32 arg0, s32 arg1, s32 arg2) {
    u8 *r;
    s32 v;
    s32 d;
    s32 t;
    s32 k;
    s32 u;
    u8 sp18[8];

    r = D_80091570 + arg1 * 8;

    if (D_8009B07B == 1) {
        if (D_8009B07C == 1) {
            return;
        }
    }

    v = (s16)*(u16 *)r;

    if (arg0 < 2) {
        func_80059000(arg0, sp18);
        if (*(s16 *)(sp18 + 6) < 0x32) {
            *(s16 *)(sp18 + 6) = 0x32;
        }
        *(s16 *)(sp18 + 6) = *(u16 *)(sp18 + 6) - 0x12C;
        d = *(s16 *)(sp18 + 6);
        if (d != 0) {
            k = 750;
            t = v;
            if (d > 0) {
                t = v / 2;
            }
            u = d * t;
            t = u;
            v += t / k;
        }
    }

    func_8005F3B8(arg0, v, *(s16 *)(r + 2), *(s16 *)(r + 4), arg2);
}
