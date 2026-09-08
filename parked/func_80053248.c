/* 100/100 and 46 differing (2026-09-08). THE FUNCTION IS VARIADIC, which no
 * amount of reading the listing was going to say: retail's prologue is a
 * varargs register save area -- `sw $a1,4($sp)` / `lw $a1,4($sp)` /
 * `sw $a0,0($sp)` / `sw $a2,8($sp)` / `sw $a3,12($sp)`, with the `sw $a0`
 * duplicated into the following branch's delay slot -- and the six-fixed-
 * parameter spelling reads arguments five and six from 16($sp)/20($sp) in the
 * prologue, which retail never touches. Signature is
 * `void func_80053248(s32 a, ...)`, the fifth argument list being read with
 * the PsyQ stdarg.h macros (inlined here); `b` is read always and `c`..`f`
 * only inside the `a < 2` arm, which is what "consumes five properties for
 * slots 0 and 1 but only one for slot 2" means.
 *
 * THE DIFFERENCE COUNT WENT UP, 45 -> 46, AND THE CENSUS IS WHY THIS IS THE
 * RIGHT CANDIDATE: the six-parameter version's opcode census is
 * `lw +3, sw -3` -- exactly the three saves it fails to emit and the three
 * reloads it emits instead -- and this one's census is EMPTY. Every opcode
 * count matches and the whole prologue is instruction-for-instruction right,
 * where before all five instructions of it were wrong. WORKFLOW's rule about
 * ranking on the census rather than the count, in its cleanest instance yet.
 *
 * The lever is krystalgamer's one-line description of his own matched copy
 * ("Variadic model-slot property setter. void Model_SetSlotProperties(s32
 * idx, ...) consumes five s32 properties for slots 0 and 1 but only one for
 * slot 2"). Third function in one day closed or unblocked by his prose
 * rather than by his C.
 *
 * Residue is allocation: `b` lands in $v1 where retail reloads it into $a1,
 * the register it was spilled from, and the D_800F2C40 base pair follows.
 * Measured and dead: dropping the `p` base local and indexing the symbol
 * inline at all five sites is +1 and 87.
 */
#include "common.h"

/* PsyQ stdarg.h, verbatim -- the retail prologue is a varargs save area
 * (sw $a1,4($sp) / lw $a1,4($sp) / sw $a0,0($sp) / sw $a2,8($sp) /
 * sw $a3,12($sp)) and no fixed-parameter spelling produces it. */
#define __va_rounded_size(TYPE)  \
  (((sizeof (TYPE) + sizeof (int) - 1) / sizeof (int)) * sizeof (int))
#define va_start(AP, LASTARG) \
 (AP = ((char *)&(LASTARG) + __va_rounded_size(LASTARG)))
#define va_arg(AP, TYPE) \
 (AP = ((char *) (AP)) += __va_rounded_size (TYPE), \
  *((TYPE *) ((char *) (AP) - __va_rounded_size (TYPE))))
typedef void *va_list;

void func_80053248(s32 a, ...) {
    va_list ap;
    u8 *p;
    s32 b, c, d, e, f;

    va_start(ap, a);
    b = va_arg(ap, s32);
    if (b >= 0) {
        p = D_800F2C40;
        *(s16 *)(p + a * 3616 + 0xDF8) = b;
        D_8009B488[a] = b;
    }

    if (a < 2) {
        c = va_arg(ap, s32);
        d = va_arg(ap, s32);
        e = va_arg(ap, s32);
        f = va_arg(ap, s32);
        if (c >= 0) {
            p = D_800F2C40;
            *(s16 *)(p + a * 3616 + 0xDFA) = c;
        }
        if (d >= 0) {
            p = D_800F2C40;
            *(s16 *)(p + a * 3616 + 0xDFC) = d;
        }
        if (e >= 0) {
            p = D_800F2C40;
            (p + a * 3616)[0xDFE] = e != 0;
            D_8009B48E[a] = e != 0;
        }
        if (f >= 0) {
            p = D_800F2C40;
            (p + a * 3616)[0xDFF] = f != 0;
            D_8009B490[a] = f != 0;
        }
    } else {
        D_8009AF88 = D_80091008 + D_800F5678[0] * 178;
    }

    D_8009AF94 = 0xF;
}
