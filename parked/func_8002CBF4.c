/* 3 differing at 45/45 (2026-09-05; was 6), from -2 and 34. RECOVERED from git 2026-09-04 (the
 * Unchiga merge deleted it and put a transcription in src/). Three levers,
 * each read off the residue, and the order they were needed in:
 *
 *   -2 -> -1  the clamp as a single return: `if (s >= 0x2710) s = 0x270F;
 *             return s;` instead of two returns. Retail materialises 9999
 *             INTO s ($s0) and copies to $v0 at the shared epilogue; two
 *             returns let gcc fold the constant straight into $v0.
 *   -1 ->  0  `do { s = v * 10; } while (0);` before the call argument is
 *   (13)      formed. Retail completes the *10 (sll 2, addu, sll 1) before
 *             the third D_801D4244 read and leaves the load-delay slot after
 *             `lw $a0` EMPTY; unpinned, gcc defers the final sll 1 into that
 *             slot and the function is one short. Naming the call argument
 *             instead of pinning s does nothing (-1).
 *   13 ->  6  the `>> 9` arm as two statements against one name,
 *             `v = D_801D4244[arg0 - 1]; v = v >> 9;` -- the func_80048920
 *             one-name-two-statements rule, and it fixed that arm's whole
 *             $v0/$v1 assignment.
 *
 * What is left is the THIRD read, the call argument, with base and index in
 * exchanged registers ($v0/$v1) inside one block. Every attempt to name it is
 * +1 -- reusing the dead `v` in three statements, the same in one expression,
 * and a `do { } while (0);` round the read -- because a name for a call
 * argument gives gcc a copy retail does not have; a fresh name `t` in three statements is +0 and 6.
 * (The first run of that variant printed nothing: a wine-server race with the
 * permuter restarting in the same second, not a compile error -- read the log.) A named index before the `if` is -2 and a
 * base local in the `>> 9` arm is -1. Permuter queued; the box runs one at a
 * time and func_8002C7E8 has it.
 *
 *    6 ->  3  (2026-09-05) the index of the THIRD read named right before it,
 *             `k = arg0 - 1;` then `D_801D4244[k]` -- the base and the index
 *             then take retail's registers. The remaining 3 are ORDER: retail
 *             forms the base pair before `addiu $v1,$a0,-1`, we form the
 *             index first. Dead at 3: a base local as well (6), the index pinned
 *             with `do { } while (0);` (6), the byte-address cast spelling (3).
 */
#include "common.h"

s32 func_8002CBF4(s32 arg0, s32 arg1) {
    s32 v;
    s32 s;
    s32 k;

    if (arg1 != 0) {
        v = D_801D4244[arg0 - 1];
        v = v >> 9;
    } else {
        v = D_801D4244[arg0 - 1];
    }

    v &= 0x1FF;
    do { s = v * 10; } while (0);
    k = arg0 - 1;
    s += func_8002497C((D_801D4244[k] >> 26) & 0x1F);

    if (s < 0) {
        return 0;
    }

    if (s >= 0x2710) {
        s = 0x270F;
    }

    return s;
}
