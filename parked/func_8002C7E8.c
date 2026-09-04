/* 16 differing at 84/84, from 18. RECOVERED from git 2026-09-04 (the Unchiga
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

    r = D_801A7AD8 + k * 28;

    for (i = 0; i < 5; i++, r += 0x1C) {
        sl[i] = (u8 *)0;
        if ((*(u16 *)(r + 0x16) & 0x8000) != 0) {
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
