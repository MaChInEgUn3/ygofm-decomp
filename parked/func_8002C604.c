/* 3 differing at 34/34, from 24. RECOVERED from git 2026-09-04 (the Unchiga
 * merge deleted it and put a transcription in src/).
 *
 * Three levers, in the order they were found, each read off the residue:
 *
 *   1. D_80010000 is a POINTER VARIABLE, not an array. Retail does
 *      `lui $v1,%hi / lw $v1,%lo($v1)` -- a load -- and the old candidate wrote
 *      `u8 *q = D_80010000;` against the _IS_AGGREGATE arm, which takes the
 *      ARRAY'S ADDRESS (lui/addiu) rather than its first element. That is a
 *      semantic error that happened to keep the length. `D_80010000[0]` gives
 *      the load. Length right again, 24.
 *   2. The two reads from D_800E9D90 want the second one NAMED and issued
 *      right after the first store: retail does `lw 8(t)`, `sw 8(p)`,
 *      `lw 4(t)` and then holds that value across five halfword stores before
 *      storing it at +0xC; written inline the second load sinks to just
 *      before its own store. `b = *(s32 *)(t + 4);` after the first store is
 *      24 -> 10 -- and as a side effect it puts the call result in $a0 where
 *      it belongs, which had read as a separate fault.
 *   3. WHERE the two bases are materialised: retail loads q BEFORE the first
 *      store and forms t right AFTER it, holding both across the stores.
 *      `q = D_80010000[0];` above `p[0x1C] = 0x80;` and `t = D_800E9D90;`
 *      below it is 10 -> 3. Both above is also 3.
 *
 * What is left is the 0x80 constant and the load's %hi sharing a register:
 * retail materialises `addiu $v0,$zero,128` FIRST and then does the load
 * self-referencing through $v1; we do the load through $v0 first and the
 * constant after. Measured and dead, all worse: `do { c = 0x80; } while (0);`
 * ahead of the load (11), the load wrapped in `do { } while (0);` after the
 * store (13) or before it (10). A plain `c = 0x80;` local ahead of the load is
 * 3, i.e. constant-propagated straight back. Permuter started from this base.
 */
#define D_80010000_IS_AGGREGATE
#include "common.h"

u8 *func_8002C604(s32 arg0) {
    u8 *p = func_8002C5CC();

    if (p != 0) {
        u8 *q;
        u8 *t;
        s32 b;

        q = D_80010000[0];
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
