/* 21 differing at 74/74, PURE C -- no pins, no launder, no instruction
 * template. First real C for this function that reaches exact length
 * (2026-09-05); src/ holds a transcription-class candidate whose four asm
 * levers this replaces. The old park's "76 against 74, an eighth saved
 * register" is gone: the register count is right without any of them.
 *
 * Measures the same 21 under the file's flags (-O2 -G0 -mno-split-addresses)
 * and under default -O2 -G8 with the assembler at -G0 (the scalar +
 * smaller-as form); the aggregate arm at -G8 is +1 (LICM hoists the shared
 * %hi into a saved register), and as -G4 is -3.
 *
 * THE RESIDUE, read off the columns. Retail copies arg1 UNMASKED into $s5
 * in the prologue (right after arg0 into $s6) and masks it EVERY ITERATION
 * into $v0, in the first compare's branch delay slot; arg0's mask is hoisted
 * once into $s4. gcc hoists BOTH masks as loop invariants -- arg1's into $s4,
 * arg0's into $s5 -- and the unmasked arg1 then dies at the mask, so it is
 * never copied. Everything else in the 21 follows from that one choice.
 * `u8 a1 = arg1;` before the loop or inside it does not stop the hoist (21
 * both), because a narrow local is still invariant.
 * The transcription stopped the hoist with an empty asm launder on the copy.
 * The pure-C question is what makes gcc 2.8.1 decline to hoist an invariant
 * mask: the working hypothesis is register pressure -- hoisting arg1's mask
 * needs a callee-saved register of its own, and if the unmasked arg1 is
 * live past the loop in the original (see the $s5 uses recorded below) the
 * count reaches eight and loop.c gives up. Not yet measured.
 */
#include "common.h"

void func_8004B374(s32 arg0, s32 arg1) {
    u8 *base;
    s32 mask;
    s32 i;
    s32 off;
    s32 *tbl;
    s32 v0;
    s32 t1;

    base = D_8009B458;
    i = 0;
    mask = 0;
    if (*(s16 *)(base + 0x510) > 0) {
        t1 = arg0 & 0xFF;
        tbl = D_80011434;
        off = 0;
        do {
            u8 *p = base + off;
            if (p[0x183] == t1 && p[0x185] == (u8)arg1) {
                func_8004A7C0(i);
                mask |= *tbl;
            }
            tbl++;
            off += 0x28;
            base = D_8009B458;
        } while (++i < *(s16 *)(base + 0x510));
    }

    if (mask != 0) {
        do {
            func_80076ED0(0, mask);
            v0 = func_80077090(mask);
        } while (v0 != 2 && v0 != 0);
    }

    {
        u8 *q = D_8009B458 + ((u8)arg0) * 0x18;
        q[4] = 0;
    }
}
