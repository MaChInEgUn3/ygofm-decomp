/* 3 differing at 47/47. First REAL C written for this function 2026-09-04
 * (src/ holds Unchiga's transcription). Flags -O2 -G0 -mno-split-addresses,
 * and the -mno-split-addresses is LOAD-BEARING: with -msplit-addresses (full
 * flag set, not the try_func trailing-arg trap below) it is -2 and 34.
 *
 * The three are the ones the park entry has always named: retail sets up
 * `addiu $a2,$zero,0x1000` BEFORE `lui $a3,%hi(func_8004B734)` and fills the
 * jal's delay slot with `addiu $a3,$a3,%lo(func_8004B734)` -- aspsx splitting
 * the `la` macro INTO the slot. gcc emits the la first (one indivisible macro
 * to it under -mno-split-addresses) and sinks the 0x1000 into the slot, so
 * there is no nop for build.py's split_address_across_call post-pass to
 * rewrite. Measured 2026-09-04, all 3 unless noted:
 *   the 0x1000 and the callback both named as locals           3
 *   the 0x1000 pinned with `do { } while (0);`                  3
 *   the pin plus func_8004B854 in LA_CALL_FUNCS (temp)          3  (no nop, so nothing fires)
 *   one name `n` for the 0x1000 shared by both calls            3
 *   any of the above with -msplit-addresses (full flags)        -2, 34
 * So nothing at source level keeps the constant out of the slot, and the
 * post-pass cannot fire without a nop. The remaining lever is a post-pass
 * that recognises `la / call / <movable insn>` and swaps the movable insn
 * ahead of the la -- a change to build.py's emulation, not to this file.
 *
 * INSTRUMENT NOTE: try_func's trailing arguments REPLACE the compiler flags,
 * they do not append. `try_func f cand.c -msplit-addresses` compiles with
 * ONLY that flag (no -O2, no -G0) and read as +31 here before the mistake
 * was noticed. Always pass the full set.
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
