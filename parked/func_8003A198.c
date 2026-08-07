#include "common.h"

/* 3 differences, 21/21, instruction-for-instruction identical to retail.
 * What is left is register allocation in the second block alone: retail keeps
 * the intermediate base in $v0 and the final address in $a1
 * (addu $v0,$a0,$v0 / sll $v1,$a2,1 / addu $a1,$v0,$v1) where this coalesces
 * both into $a1 (addu $a1,$a0,$v0 / sll $v0,$a2,1 / addu $a1,$a1,$v0).
 *
 * `p = (e = arg0 + v)` is the permuter's find and it is load-bearing: a dead
 * store to a local that is overwritten two lines later, acting as an
 * allocation hint. Same family as the assign-to-a-dead-local rule. Without it
 * this is 11.
 *
 * The nested `if`s are also load-bearing and were the big step (18 -> 11):
 * retail reaches its single `addu $v0,$zero,$zero` from all three paths, and
 * three separate `if (v == 0) return 0;` statements emit the first exit inline
 * instead of cross-jumping, and fold the last pair into `sltu $v0,$zero,$v0`.
 *
 * Measured and no better: the same hint applied to the third block as well
 * (3), `p` declared s32 with casts (3), a second permuter run from this base
 * which saturated at 3 over ~4 minutes.
 */
s32 func_8003A198(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *e;
    u8 *p;
    s32 off;
    u16 v;
    u16 w;

    off = arg1 * 2;
    e = arg0 + off;
    v = *(u16 *)e;
    if (v != 0) {
        p = (e = arg0 + v);
        off = arg2 * 2;
        e = p + off;
        v = *(u16 *)e;
        if (v != 0) {
            p = arg0 + v;
            off = arg3 * 2;
            e = p + off;
            w = *(u16 *)e;
            if (w != 0) {
                return 1;
            }
        }
    }
    return 0;
}
