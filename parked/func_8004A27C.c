/* 9 differing at 31/31 (2026-09-06; was 11). The listing has no %gp_rel and no
 * lui $at, so D_8009B458 takes its real POINTER-SCALAR declaration with the
 * assembler at -G0 (WORKFLOW step 0, branch 1): retail loads it bare through
 * the destination register, and the _IS_AGGREGATE arm had been giving
 * cc1psx's own pair with a temp. The 9 left: retail loads the second
 * halfword into $a1 (arg1's register, dead after the first mult) and keeps
 * the first product in $a3, and stores +0x4C0 straight after +0x4C4 where we
 * let the first sra/sh into the mult latency first. Flat at 9: both
 * halfwords named, both products named before the stores, the products
 * interleaved with the zero stores, and +0x4C0 written before +0x4C4. */
#include "common.h"

void func_8004A27C(s32 arg0, s32 arg1, s32 arg2) {
    u8 *p = D_8009B458;
    s32 t;

    *(u16 *)(p + 0x4CC) = 0;
    *(u16 *)(p + 0x4CE) = 0;
    t = D_80011434[arg0];
    *(s32 *)(p + 0x4C4) = 0xF;
    *(s32 *)(p + 0x4C0) = t;
    *(u16 *)(p + 0x4C8) = (arg1 * *(u16 *)(p + 0x514)) >> 7;
    *(u16 *)(p + 0x4CA) = (arg2 * *(u16 *)(p + 0x516)) >> 7;

    func_80077450(p + 0x4C0);
}
