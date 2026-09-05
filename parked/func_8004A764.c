/* 6 differing at 23/23 (2026-09-05). Source is an ASSEMBLY TRANSCRIPTION in
 * src/ (docs/ASM_DEBT.md); this is the C candidate. gp=0, at=0, flags
 * -O2 -G8 -msplit-addresses, as -G0.
 *
 * The residue is ONE scheduling decision: retail computes the table element
 * address (sll / addu) and THEN loads D_8009B458 (lui / lw adjacent), reads
 * the element, and only then saves $ra; gcc's first scheduler hoists the
 * D_8009B458 load above the addu and the `sw $ra` above the element read.
 * Measured and dead (2026-09-05, 13 variants): the table read named before
 * the base local (12), an element pointer `&D_80011434[arg0]` or
 * `D_80011434 + arg0` before the base (9, 9 -- the sll moves down instead),
 * every store through the symbol with no local (6), the _IS_VOLATILE arm
 * (6), do/while pins round the read (12), round the base assignment (23),
 * round both (19), -fno-schedule-insns (22), -fno-schedule-insns2 (16), -O1
 * (22), and -O2 without -msplit-addresses (6). No _IS_SCALAR arm exists for
 * D_8009B458 (only _IS_AGGREGATE / _IS_VOLATILE). Permuter has a base dir
 * with one output (build/permuter/func_8004A764) -- re-score before rerun.
 */

#include "common.h"

void func_8004A764(s32 arg0) {
    u8 *p = D_8009B458;

    *(s32 *)(p + 0x4C0) = D_80011434[arg0];
    *(s32 *)(p + 0x4C4) = 0x60100;
    *(u16 *)(p + 0x4FA) = 0;
    *(u16 *)(p + 0x4FC) = 0;
    *(s32 *)(p + 0x4E4) = 5;

    func_80077450(p + 0x4C0);
}
