/* 17 differing at 34/34, from 18. RECOVERED from git 2026-09-04 (the Unchiga
 * merge deleted it and put a transcription in src/).
 *
 * EVERY instruction is correct and in the right order. The residue is a pure
 * CYCLIC ROTATION of three argument registers by one position:
 *
 *              t (the s16 table)   m (the byte map)   i (the counter)
 *   retail          $a2                 $a0                $a1
 *   ours            $a0                 $a1                $a2
 *
 * Declaring `m` before `t` is worth exactly one difference (18 -> 17) and
 * nothing else moves it. Measured and dead, all 17 or 18:
 *   `m` declared first                                          17
 *   declaration order m, i, t with all three assigned as
 *     statements in that order                                  18
 *   `i = 15;` hoisted out of the for-init                       18
 *   `do { i = 15; } while (0);` before the loop                 17
 *   `do { m = ...; } while (0);` with t assigned after it       17
 *   `r = t;` written before `w = t;`                            17
 * The three do/while rows matter because that idiom is WORKFLOW's documented
 * lever for exactly this symptom ("when a whole register class is rotated");
 * here it reaches nothing, so the entry is a counterexample to that rule as
 * much as it is a park.
 * Permuter started on it 2026-09-04.
 */
#include "common.h"

void func_80032370(void) {
    u8 *m = (u8 *)D_801D07BC - 0x56C;
    s16 *t = (s16 *)D_801D07BC;
    s16 *r;
    s16 *w;
    s32 i;

    for (i = 15; i >= 0; i--) {
        s32 v = t[i];

        if (v != 0 && m[v - 1] == 0) {
            t[i] = 0;
        }
    }

    w = t;
    r = t;

    for (i = 0; i < 0x10; i++) {
        if (*r != 0) {
            if (r != w) {
                *w = *(u16 *)r;
                *r = 0;
            }
            w++;
        }
        r++;
    }
}
