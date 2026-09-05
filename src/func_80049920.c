/* MATCH 2026-09-05, pure C under default -O2 -G8 with the assembler at -G0
 * (PER_FUNC_AS_FLAGS): D_8009B458 bare and reloaded per site, D_80011434 as
 * cc1psx's own pair. Replaces a transcription (four aliases, three pins).
 *
 * Seven levers, in the order the residue gave them up:
 *   34 -> 19  the bump/retry `if` INVERTED so the retry is the fall-through
 *             and the one-store bump is the out-of-line arm at the end
 *   19 -> 18  `while (++i < ...)` so the increment lands after the lh
 *   18 -> 16  default -G8 / as -G0 instead of -G0 -mno-split-addresses
 *   16 -> 11  a DEAD `mask = 0;` as the first statement
 *   11 ->  5  a name per D_8009B458 reload site inside the loop (b1, b2)
 *    5 ->  0  `z = 0;` and the entry guard compared against z instead of the
 *             literal. The five were i and mask with $s3/$s4 exchanged -- a
 *             pure allocation tie-break that no declaration order, pin or
 *             borrow moved. A third zero pseudo numbered before the guard
 *             shifts which of the two wins $s3. The permuter found it as an
 *             uninitialised `new_var`; the initialised spelling scores the
 *             same and is the one installed.
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
    s32 z;
    u8 *b1;
    u8 *b2;

    mask = 0;
    base = D_8009B458;
    i = 0;
    mask = i;
    z = 0;
    if (*(s16 *)(base + 0x510) > z) {
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
