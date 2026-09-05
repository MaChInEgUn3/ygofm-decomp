/* MATCH 2026-09-05, pure C at default -O2 -G8 with the assembler at -G0
 * (PER_FUNC_AS_FLAGS). Replaces a transcription. Had sat at 3 under
 * -G0 -mno-split-addresses, where the callback's `la` was one indivisible
 * macro and the 0x1000 sank into the jal's delay slot instead of the
 * `addiu %lo`. Under the default compiler the function address is cc1psx's
 * own %hi/%lo pair and reorg fills the slot with its `%lo` half, exactly as
 * retail has it; D_8009B458 stays the bare scalar form because the listing
 * has no %gp_rel and no `lui $at`, so `as -G0` is free (WORKFLOW step 0,
 * branch 1). -G0 with split addresses is -2 (the %hi gets hoisted into a
 * saved register). Same recipe as func_8002C604 the same hour.
 */
#include "common.h"

void func_8004B854(void) {
    u8 *p;
    s32 h;

    p = D_8009B458;
    if (p[0x503] == 0) {
        p[0x503] = 1;
        func_800738B0();
        func_80073A54(0xF2000002);
        h = func_80073860(0xF2000002, 2, 0x1000, func_8004B734);
        p = D_8009B458;
        *(s32 *)(p + 0x504) = h;
        func_80073890(h);
        func_80073950(0xF2000002, 0xE000, 0x1000);
        func_80073A24(0xF2000002);
        func_800738C0();
        D_8009B458[0x500] = 0;
        D_8009B458[0x503] = 0;
    }
}
