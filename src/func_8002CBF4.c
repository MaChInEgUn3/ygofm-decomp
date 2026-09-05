/* MATCH (2026-09-05). Was an ASSEMBLY TRANSCRIPTION (Unchiga's port of
 * 2026-08-30, an inline asm block) counted as debt in docs/ASM_DEBT.md;
 * this is the C. Flags: default compiler, as -G0. History in docs/PARKED.txt.
 *
 * Reads a card's 32-bit record from D_801D4244: the low 9 bits (or bits
 * 9..17 when arg1 is set) times ten, plus func_8002497C's bonus for the
 * 5-bit field at bits 26..30, clamped to 0..9999 (negative results return
 * 0, which is why the clamp is a single `return s`).
 *
 * Two shapes carry the match and both are the register allocator's, not
 * the code's. `do { s = v * 10; } while (0);` pins the *10 ahead of the
 * third record read so the load-delay slot after `lw $a0` stays empty as
 * retail has it. And the record base for that read goes through a local
 * `t` -- which alone gives retail's instruction ORDER with the two
 * registers exchanged (6) -- plus a dead conditional assignment to `v`
 * inside the pin, `if (!s) { v = !s; }`, which gcc deletes entirely but
 * which numbers a pseudo that tips the allocation the other way: 3 -> 0.
 * Either half alone is 3 or 6; the permuter found the pair at score 0
 * after seventeen hand spellings of the halves had been measured. Read it
 * as the residue of a macro in the original.
 */
#include "common.h"

s32 func_8002CBF4(s32 arg0, s32 arg1) {
    s32 v;
    s32 s;
    s32 k;
    s32 *t;

    if (arg1 != 0) {
        v = D_801D4244[arg0 - 1];
        v = v >> 9;
    } else {
        v = D_801D4244[arg0 - 1];
    }

    v &= 0x1FF;
    do {
        s = v * 10;
        if (!s) {
            v = !s;
        }
    } while (0);
    t = D_801D4244;
    k = arg0 - 1;
    s += func_8002497C((t[k] >> 26) & 0x1F);

    if (s < 0) {
        return 0;
    }

    if (s >= 0x2710) {
        s = 0x270F;
    }

    return s;
}
