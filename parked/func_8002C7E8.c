/* 12 differing at 84/84 (2026-09-05: the default compiler, cc1psx's own
 * pairs, with the assembler at -G0 -- the file's -mno-split-addresses row is
 * measured with `-quiet -O2 -G8` as try_func's trailing flags; the file's
 * -mno-split-addresses row in build.py STAYS while src/ holds the
 * transcription -- deleting it made that asm block one instruction short and
 * the build red, commit 04c466a, restored the next commit. Drop the row when
 * this C replaces it. That recipe took the D_801799D8 pair through $v0 and
 * 14 -> 12). Was 14, from 18. RECOVERED from git 2026-09-04 (the Unchiga
 * merge deleted it and put a transcription in src/).
 *
 * One lever, worth two: the record cursor's `r += 0x1C` moved from the end
 * of the first loop's body into the for clause AFTER `i++`
 * (`for (i = 0; i < 5; i++, r += 0x1C)`), so it is what fills the loop-back
 * delay slot while the stack cursor's own `addiu 4` comes first, which is
 * retail's order. The other order in the for clause is 18 (no change).
 *
 * The residue is register naming and nothing else: retail carries `k` and
 * both loops' `i` in $a3 and forms the k*28 temporary in $v1 with the table
 * base in $v0; we carry k in $v1, i in $a2, and swap the temp and the base.
 * Two of the sixteen are the t = D_801799D8 pair going through $v0 in retail
 * and self-referencing through $t4 here.
 *
 * Measured and dead on 2026-09-04:
 *   k merged into i (retail reuses $a3 for both, which READS as one name):
 *     28, much worse, and byte-identical across four variants -- the
 *     register-reuse-is-not-name-reuse rule, confirmed again
 *   four declaration orders of i/j/n/k on top of the lever            16
 *   `i = 0;` as a statement before the first for                       16
 *   t assigned through a second name (`e = D_801799D8; t = e;`)       18
 * Permuter started from this base.
 *
 * 16 -> 14, permuter-found and decomposed: the scaled index written through
 * the INNER loop counter, which is dead at that point --
 * `j = k * 28; r = D_801A7AD8 + j;`. The same statement through a fresh name
 * `m` is 16, so it is the borrow of a name whose live range resumes later
 * that does the work (the func_8002A4A8 rule), not the naming of the product.
 *
 * 2026-09-05, at 12: the residue is k and both loop counters in $a3 (retail)
 * against $v1/$a2 (ours). `i = 0;` above the search loop (12), `z = 0;
 * i = z;` there (12), `i = 0;` after k (14), and k merged into i (24) -- the
 * merge is 24 under this recipe where it was 28 under the old one.
 *
 * 12 -> 11 (2026-09-05, second pass): the record base as a SUBTRACTION OF A
 * NEGATION, `r = D_801A7AD8 - -(k * 28);`, replacing the borrowed
 * `j = k * 28; r = D_801A7AD8 + j;`. The product then lands in $v1 as
 * retail has it (the borrow had put it in $a3, j's register), and the
 * `(s32)` cast sum is the same 11. Dead on this base: the plain `+` (17),
 * a fresh `m` (17), borrowing `e` (17), `r = sym; r += k*28` (14), `j =
 * -(k*28); r = sym - j` (11, same), sharing the outer counter with the
 * first loop's `i` (20), and `i = 0;` above the search loop (87: it moves
 * the whole prologue). What is left: k in $a1 where retail has $a3, the
 * addu's operands (base first here, index first in retail), and both loop
 * counters in $a2 against $a3 -- allocation only, no instruction moved.
 *
 * 11 -> 9 (2026-09-05, permuter iteration 65, decomposed): the first loop's
 * halfword read borrowed into the dead `k` -- `k = *(u16 *)(r + 0x16);
 * if ((k & 0x8000) != 0)` -- puts BOTH loop counters in retail's $a3. The
 * embedded `(k = ...) & 0x8000` form is the same 9. Borrowing `j` instead
 * is 13 and `n` is 22; on this base the plain `+` and the `(s32)` cast sum
 * for the record base are both 12, so the negation stays. What is left:
 * k in $a1 where retail has $a3 (and r therefore in $a2 against $a1), and
 * the addu's operand order -- allocation only.
 */


#include "common.h"

s32 func_8002C7E8(s32 arg0, s32 arg1) {
    u8 *out[3];
    u8 *sl[5];
    u8 *t;
    u8 *r;
    u8 *e;
    s32 i;
    s32 j;
    s32 n;
    s32 k;

    t = D_801799D8;

    while (1) {
        if (*(u16 *)t == 0) {
            return 0;
        }
        if (*(u16 *)t == arg1) {
            break;
        }
        t += 0xA;
    }

    k = 5;
    if (D_8009B1D5 != 0) {
        k = 0x14;
    }

    r = D_801A7AD8 - -(k * 28);

    for (i = 0; i < 5; i++, r += 0x1C) {
        sl[i] = (u8 *)0;
        k = *(u16 *)(r + 0x16);
        if ((k & 0x8000) != 0) {
            sl[i] = r;
        }
    }

    t += 2;

    for (n = 0; n < 3; n++) {
        for (j = 0; j < 5; j++) {
            e = sl[j];
            if (e != 0) {
                if (*(s16 *)(e + 0xC) == *(u16 *)(t + n * 2)) {
                    goto found;
                }
            }
        }
        return 0;
    found:
        out[n] = e;
        sl[j] = (u8 *)0;
    }

    if (arg0 != 0) {
        for (i = 0; i < 3; i++) {
            *(s32 *)(arg0 + i * 4) = *(s32 *)out[i];
        }
        *(s32 *)(arg0 + 0xC) = 0;
    }

    return *(u16 *)(t + 6);
}
