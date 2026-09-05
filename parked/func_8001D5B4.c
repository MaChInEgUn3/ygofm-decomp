/* -2 at 45/47, 35 differing. RECOVERED from git 2026-09-04 (the Unchiga merge
 * deleted it and put a transcription in src/). The -2 is STRUCTURAL and no
 * source spelling tried reaches it:
 *   retail   beq $v0,$zero,L3 / addiu $v0,-1 / j L4 / addiu $v0,1
 *   ours     bne $v0,$zero,L3 / addiu $v0,1  ...
 * i.e. after the call retail keeps BOTH exits materialised -- the -1 into the
 * shared `sb d_8009b160` block and a `j` to the shared `return 1` epilogue --
 * where gcc folds the return-1 path. Retail also reads D_8009B1D7 ABOVE the -1
 * store and falls through into the `!=` arm.
 * Measured 2026-09-04, every one still -2:
 *   early `if (call != 0) return 1;` with the body unnested       -2, 35
 *   `c = D_8009B1D7;` named before the -1 store                    -2, 35
 *   the two arms swapped so `!=` is the fall-through               -2, 36
 *   both of the above together                                     -2, 36
 *   a local per arm with ONE store at the end (WRONG: changes the
 *     semantics, the -1 is inside the ==0 branch)                  -9
 * The polarity rows scoring identically is the wrong-axis tell -- gcc
 * canonicalises the test either way. What is left to try is the func_8003C328
 * lesson: lay the arms out as `goto` targets in retail's own address order,
 * with an explicit `goto` to the shared store block.
 * Done 2026-09-05, still -2 in every case (35 or 36): the `!=` arm laid out
 * first with `goto eq;`, an early `ret1: return 1;` block right after the
 * call with `goto ret1;` from both slt-fail paths, the =3/=2 arms with and
 * without their own `return 1;`, the slt tests inverted to `goto`s, and
 * -fno-thread-jumps / -fno-cse-follow-jumps / -fno-cse-skip-blocks on two
 * of those. The mechanism, read off the listing: retail's return-1 block
 * (`j epilogue / addiu $v0,1`) sits right after the call's beq and is the
 * target of both later beqz's; gcc instead inverts the call's branch to jump
 * straight to the epilogue with the 1 in its slot, and the block is gone.
 * No source layout or flag tried keeps it. Also visible: retail duplicates
 * the =3 store (`sb / j epilogue / addiu 1`) where we cross-jump it into the
 * first block's store.
 * Later the same day: an accumulator return (`ret = 1;` once at the top,
 * every exit a `goto done; done: return ret;`) is +3; assigned at each exit
 * instead it is the same -2/35. The return-1 block does not come back that
 * way either.
 * 2026-09-05, second pass: read off the listing, both `j L4 / addiu $v0,1`
 * are `j ret1` with ret1's first instruction copied into the slot by reorg,
 * so the label is the `addiu $v0,1` block that FALLS INTO the epilogue --
 * i.e. `ret1: return 1;` at the END of the function, reached by `goto ret1`
 * from the call test, from the slt-fail path and after the =3 store, with
 * the =2 arm falling through. Written that way (three layouts: the call
 * test as `!= 0 goto ret1`, as `== 0 { body }` with ret1 after, and with the
 * =3 arm's own `return 1`) it is still -2/36: gcc inverts the call's branch
 * and jumps to the epilogue with the 1 in its slot every time. Retail
 * therefore has THREE copies of the return-1 tail that our jump pass
 * cross-jumps into one; which source shape stops cross-jumping here is
 * not established (an accumulator was +3, see above).
 */
#include "common.h"

s32 func_8001D5B4(u8 *arg0) {
    if (D_8009B162 != 0) {
        D_8009B160 = -1;

        return 1;
    }

    if (func_80024088(arg0, D_8009B160) == 0) {
        D_8009B160 = -1;

        if (D_8009B1D7 == *(s8 *)(arg0 + 0x10)) {
            if (D_8009B1D6 == *(s8 *)(arg0 + 0xF)) {
                return 0;
            }

            D_8009B160 = 0;

            if (D_8009B1D6 < *(s8 *)(arg0 + 0xF)) {
                D_8009B160 = 2;
            }
        } else {
            D_8009B160 = 1;

            if (D_8009B1D7 < *(s8 *)(arg0 + 0x10)) {
                D_8009B160 = 3;
            }
        }
    }

    return 1;
}
