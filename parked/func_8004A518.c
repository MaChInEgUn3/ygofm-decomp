/* +2 at 114/112, 99 differing. First PURE C written for this function
 * (2026-09-05); src/ holds a transcription with asm reloads, register pins
 * and scheduling fences. Three loops of constant stores over D_8009B458
 * records at +0x518 (16 x 0x2C), +0x180 (count x 0x28, with two calls per
 * record) and +0 (16 x 0x18), then one batch key-on of the OR-ed keys.
 *
 * The prologue matches through the constant materialisation once loop 1's
 * cursor is its OWN name (o1): shared with loop 2's cursor it was promoted
 * to $s2 across the calls. Retail keeps it in $a0 -- no call in loop 1.
 *
 * THE +2 IS ONE EXTRA CALLEE-SAVED REGISTER: ours saves $s6 (and the frame
 * layout shifts by one slot); retail uses s0..s5 only. The $s6 uses in our
 * output are recorded below so the next attempt starts from the value that
 * took it rather than from a guess:
 *     row  13  sw $s6,40($sp)
 *     row  52  addiu $s6,$zero,99
 *     row  57  sb $s6,3($v1)
 *     row 105  lw $s6,40($sp)
 *
 * Measured and dead on 2026-09-05, all still +2 unless noted:
 *   loop-1 constants as literals instead of named locals     +2, 103
 *   `i = 0;` instead of `i = mask;` for loop 1                +2, 99
 *   loop 2's record base reloaded explicitly at the top so
 *     `base` does not span the calls                          +4 (an extra
 *     lui/lw pair per iteration; the bottom reload feeds both the test and
 *     the next top)
 *   the same with -fno-schedule-insns                         +4
 *   the same with -fno-schedule-insns2                        +4, worse
 *   the 0x63 as a u8 local assigned INSIDE the loop               +2, 99
 *   the same as an s32 local inside the loop                       +2, 99
 *   both loop-2 literals (0x63, second 0x40) as u8 locals inside    +2, 99
 * So the $s6 is gcc hoisting the invariant literal 0x63 out of a loop that
 * contains calls, into a callee-saved register; retail materialises it per
 * iteration as a temp. The same unsolved mechanism as func_8004B374's
 * per-iteration `andi` (see WORKFLOW, "an invariant retail leaves inside a
 * call-bearing loop").
 * Also visible: loop 1's `slti` and cursor increment are scheduled early
 * where retail keeps the increment in the loop-back delay slot; that is
 * downstream of the register question and was not attacked separately.
 * Flags: the file's -O2 -G0 -mno-split-addresses and default -G8 with
 * as -G0 measure identically here.
 */
#include "common.h"

void func_8004A518(void) {
    u8 *base;
    u8 *r;
    s32 mask;
    s32 i;
    s32 o1;
    s32 off;
    s32 *tbl;
    s32 key;
    s32 k40;
    s32 c72;
    s32 cff;
    s32 one;
    s32 o18;
    s32 b40;
    s32 b7f;
    s32 w7f;

    mask = 0;
    i = mask;
    c72 = 0x72;
    one = 1;
    cff = 0xFF;
    o1 = 0x518;
    base = D_8009B458;
    *(s16 *)(base + 0x512) = 0x7F;
    do {
        r = D_8009B458 + o1;
        i++;
        *(s32 *)(r + 0) = 0;
        *(s32 *)(r + 4) = 0;
        r[0x26] = 0;
        *(s32 *)(r + 0x1C) = 0;
        *(s32 *)(r + 8) = 0;
        *(s32 *)(r + 0xC) = 0;
        *(s16 *)(r + 0x14) = c72;
        *(s16 *)(r + 0x16) = c72;
        r[0x24] = one;
        *(s32 *)(r + 0x10) = 0;
        *(s16 *)(r + 0x18) = 0;
        r[0x27] = 0;
        r[0x28] = cff;
        r[0x29] = 0;
        r[0x2B] = 0;
        o1 += 0x2C;
    } while (i < 16);

    base = D_8009B458;
    if (*(s16 *)(base + 0x510) > 0) {
        i = 0;
        k40 = 0x40;
        tbl = D_80011434;
        off = 0x180;
        do {
            r = base + off;
            key = *tbl;
            r[3] = 0x63;
            r[0] = i;
            r[0xD] = 0;
            r[0xF] = 0;
            r[0xC] = 0x40;
            *(s16 *)(r + 0x1A) = k40;
            *(s16 *)(r + 0x1C) = k40;
            *(s16 *)(r + 0x1E) = 0;
            func_8004A764(i);
            tbl++;
            off += 0x28;
            func_80076ED0(0, key);
            base = D_8009B458;
            i++;
            mask |= key;
        } while (i < *(s16 *)(base + 0x510));
    }

    i = 0;
    b40 = 0x40;
    b7f = 0x7F;
    w7f = 0x7F;
    o18 = i;
    do {
        r = D_8009B458 + o18;
        i++;
        r[1] = b40;
        r[3] = b7f;
        r[4] = 0;
        r[5] = b7f;
        r[7] = b40;
        *(s32 *)(r + 8) = w7f;
        *(s32 *)(r + 0xC) = w7f;
        r[0x10] = 0;
        *(s16 *)(r + 0x14) = 0;
        r[6] = 0;
        o18 += 0x18;
    } while (i < 16);

    func_80076ED0(0, mask);
}
