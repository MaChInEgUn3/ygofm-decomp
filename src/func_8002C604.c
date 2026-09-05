/* MATCH 2026-09-05, pure C at default -O2 -G8 with the assembler at -G0
 * (PER_FUNC_AS_FLAGS). Replaces a transcription. The candidate had sat at 3
 * with D_80010000 on its _IS_AGGREGATE arm: retail materialises the 0x80
 * constant FIRST and then loads the pointer self-referencing through $v1,
 * which is the bare-symbol form -- one instruction to gcc's scheduler, so
 * the constant cannot be slotted between its halves. The listing has no
 * %gp_rel and no `lui $at`, so the scalar arm with `as -G0` is free
 * (WORKFLOW step 0, branch 1), and it is a first-try MATCH.
 * The three earlier levers, kept: D_80010000 is a pointer variable (a load,
 * not an address); the second D_800E9D90 read named right after the first
 * store so it is held across the halfword stores; q loaded above the first
 * store and t formed below it.
 */
#include "common.h"

u8 *func_8002C604(s32 arg0) {
    u8 *p = func_8002C5CC();

    if (p != 0) {
        u8 *q;
        u8 *t;
        s32 b;

        q = D_80010000;
        p[0x1C] = 0x80;
        t = D_800E9D90;
        *(s16 *)(p + 0x18) = arg0;
        *(s16 *)(p + 0x1A) = 0;
        p[0x1D] = 0;
        *(s32 *)(p + 0x14) = (s32)(q + 0x3800);
        *(s32 *)(p + 8) = *(s32 *)(t + 8);
        b = *(s32 *)(t + 4);
        *(s16 *)(p + 0x10) = 8;
        *(s16 *)p = 0;
        *(s16 *)(p + 2) = 0;
        *(s16 *)(p + 4) = 0;
        *(s16 *)(p + 0x12) = 0;
        *(s32 *)(p + 0xC) = b;
    }

    return p;
}
