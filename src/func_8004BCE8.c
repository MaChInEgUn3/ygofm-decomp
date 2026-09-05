/* MATCH (2026-09-05). Was an ASSEMBLY TRANSCRIPTION (Unchiga's port of
 * 2026-08-30, an inline asm block) counted as debt in docs/ASM_DEBT.md;
 * this is the C. Flags: -O2 -G0 -mno-split-addresses, as -G0 (gp == 0, the
 * scalar D_8009B458 arm). The full history is in docs/PARKED.txt.
 *
 * Track/tempo-stream setup on D_8009B458: resets the record's stream
 * fields, reads a halfword through func_8004BCA8 and a word through
 * func_8004BC2C (its top three bytes are the raw tempo), computes
 * 60000000 / tempo * 100 / 115, clamps it to 0xFF, halves or quarters it by
 * mode (0x1E: >> 2; 0x18 and 0x3C: >> 1) and stores the byte into +0x16 and
 * +0x14 of the record before handing it to func_8004BAE4.
 *
 * The shape is the D_8009B0F4-family idiom: a `do { } while (0);` (a macro
 * in the original) round the eight statements from the +0x7F0 store to the
 * +0x808 store. The last three levers, in order: a base local `b` loaded
 * BEFORE the byte store through the pointee, so the +0x518 store goes
 * through the pre-store base while everything after the `sb` reloads;
 * the dividend named inside the pin (`k = 60000000;`); the call result
 * routed through the later result name (`v = call >> 8; r = v;`), which
 * puts the whole reciprocal block in retail's order; and finally the
 * +0x7F0 store moved INSIDE the pin, which is what forms `p` and copies it
 * into $a0 before the two word stores -- the permuter found that last one
 * at score 0 after 13 -> 7 by hand. Every one of these was measured as
 * worthless or worse while an earlier fault was still open.
 */
#include "common.h"

s32 func_8004BCE8(void) {
    u8 *b;
    u8 *p;
    u32 r;
    u32 v;
    s32 m;
    u32 k;

    b = D_8009B458;
    p = b + 0x518;
    b[0x801] = 0;
    do {
        *(s32 *)(D_8009B458 + 0x7F0) = 0;
        *(s32 *)(D_8009B458 + 0x7F4) = 0;
        *(s32 *)(b + 0x518) = 8;
        *(s16 *)(D_8009B458 + 0x7FC) = func_8004BCA8(p);
        *(s16 *)(D_8009B458 + 0x7FA) = 1;
        *(s16 *)(D_8009B458 + 0x7F8) = 0;
        *(s32 *)(D_8009B458 + 0x7EC) = 0x10000;
        v = (u32)func_8004BC2C(p) >> 8;
        r = v;
        k = 60000000;
        *(s32 *)(D_8009B458 + 0x808) = r;
    } while (0);

    v = k / r;
    v = v * 100 / 115;
    if (v >= 0x100) {
        v = 0xFF;
    }

    m = *(u16 *)(D_8009B458 + 0x7FC);
    if (m == 0x1E) {
        goto sh2;
    }
    if (m < 0x1F) {
        if (m == 0x18) {
            goto sh1;
        }
        goto store;
    }
    if (m != 0x3C) {
        goto mask;
    }
sh1:
    v >>= 1;
    goto mask;
sh2:
    v >>= 2;
mask:
store:
    *(s16 *)(p + 0x16) = v & 0xFF;
    *(s16 *)(p + 0x14) = v & 0xFF;
    func_8004BAE4(p);

    if (*(u16 *)(D_8009B458 + 0x7FC) >= 0x60) {
        *(s32 *)(D_8009B458 + 0x804) = *(u16 *)(D_8009B458 + 0x7FC);
    } else {
        *(s32 *)(D_8009B458 + 0x804) = 0;
    }
    *(s32 *)(D_8009B458 + 0x804) = *(u16 *)(D_8009B458 + 0x7FC);
    return 1;
}
