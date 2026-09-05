/* 5 differing at 81/81 under default -O2 -G8 with the assembler at -G0
 * (flag_overrides {"as": "-G0"}); 7 under the file's current
 * -O2 -G0 -mno-split-addresses. PURE C, first written 2026-09-05; src/ holds
 * a transcription with four extern aliases and three register pins.
 *
 * Six levers, in the order the residue gave them up (all under -G8/as -G0):
 *   34 -> 19  the bump/retry `if` INVERTED (`if (b >= 2) {retry} else {bump}`)
 *             so the retry is the fall-through and the one-store bump is the
 *             out-of-line arm at the end, falling into the loop increment
 *   19 -> 18  `while (++i < ...)` so the increment lands after the lh
 *   18 -> 16  default -G8 with as -G0 instead of -G0 -mno-split-addresses:
 *             D_8009B458 bare and reloaded per site, D_80011434 as cc1psx's
 *             own pair through $v0 (retail has `lui $v0 / addiu $s1,$v0`)
 *   16 -> 11  a DEAD `mask = 0;` as the first statement
 *   11 ->  5  a name per D_8009B458 reload site inside the loop (b1, b2)
 *
 * The five are ONE fault: i and mask have exchanged $s3 and $s4. Retail zeroes
 * i into $s4 and copies it into mask ($s3) in the blez delay slot; ours zeroes
 * mask into $s4 and copies it into i -- byte-identical in the prologue with
 * the roles swapped, visible only in the loop. Measured and dead:
 *   i declared before mask                                       no change
 *   `do { i = 0; } while (0);` after the dead mask = 0           10, WORSE:
 *     CSE still turns i = 0 into a copy of mask and deletes mask = i; the
 *     pin stops constant propagation, not equality knowledge
 *   `off = i;` for `off = 0;`                                    5, no change
 * gcc 2.8's global allocator orders by priority (references over live
 * length) with pseudo number as the tie-break, and no spelling tried moves
 * which of the two wins $s3. Permuter started from this base.
 */
#include "common.h"

void func_80049920(void) {
    u8 *base;
    s32 i;
    s32 mask;
    s32 off;
    s32 *tbl;
    s32 *q;
    s32 v;
    s32 two;
    u8 b;
    u8 *p;
    u8 *b1;
    u8 *b2;

    mask = 0;
    base = D_8009B458;
    i = 0;
    mask = i;
    if (*(s16 *)(base + 0x510) > 0) {
        two = 2;
        off = 0;
        tbl = D_80011434;
        do {
            if (*(base + off + 0x18D) != 0) {
                if (func_80077090(*tbl) == 3) {
                    b1 = D_8009B458;
                    p = b1 + off;
                    b = p[0x18D];
                    if (b >= 2) {
                        mask |= *tbl;
                        q = tbl;
                        do {
                            func_80076ED0(0, *q);
                            v = func_80077090(*q);
                        } while (v != two && v != 0);
                        b2 = D_8009B458;
                        *(b2 + off + 0x18D) = 0;
                    } else {
                        p[0x18D] = b + 1;
                    }
                }
            }
            off += 0x28;
            base = D_8009B458;
            tbl++;
        } while (++i < *(s16 *)(base + 0x510));
    }
    if (mask != 0) {
        func_80076ED0(0, mask);
    }
}
