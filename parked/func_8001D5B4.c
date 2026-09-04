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
