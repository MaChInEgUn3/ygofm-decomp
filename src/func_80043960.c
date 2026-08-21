/* `e = p;` is a second name for the first sprite, and it is load-bearing:
 * retail holds that pointer in $s0 until $s0 is needed for the second one and
 * then copies it to $s1, with the copy filling func_8007E350's delay slot.
 * One name puts it in $s1 from the start and leaves the slot a `nop` -- same
 * instruction count, six registers wrong. D_8009B098 is a `u16` and
 * D_8009B428 beside it a `u8`, so `as -G1` gives the `lui $at` store while the
 * byte keeps %gp_rel. */
#include "common.h"

void func_80043960(s32 mode) {
    u8 *p;
    u8 *q;
    u8 *e;

    D_8009B428 = 0;

    if (mode == 0) {
        func_80014E1C(0, (u8 *)0, 0x1F85, 0x22, func_800434F4, 0, 0);
        func_800137E4();
    }

    func_80014E1C(0, (u8 *)0, 0x1690, 0x36, func_80043328, 0, 0);

    if (mode != 0) {
        func_800137E4();
        func_8007E910(0x2C0, 0);
        func_8007E8D0(func_8007E9B0(0x10, 0x10, 0x140, 0xF0, 0, 0x3E8));
        D_8009B098 = 0;
        func_80047AD0(2);
        func_80012D84(4);
        func_800137E4();
        return;
    }

    func_80015780();

    p = func_800400AC(func_8004002C(), 2);
    func_800428A8(p, 0, 0, 0, 0, 0, 0x10, 0x100, D_801AF000);
    *(u16 *)(p + 8) = *(u16 *)(p + 8) | 0x28;
    func_8004365C((u8 *)0, p);

    func_800438B8(4);
    func_8007E910(0x2C0, 0);
    func_8007E8D0(func_8007E9B0(0x10, 0x10, 0x140, 0xF0, 0, 0x3E8));
    D_8009B098 = 0;
    e = p;
    func_8007E350();
    func_801680F4();

    while (func_80168160(1) != 0) {
    }

    func_8007AFA4();

    q = func_800400AC(func_8004002C(), 2);
    func_800428A8(q, 0, 0, 0, 0, 1, 0x10, 0x100, D_801AF000);
    *(u16 *)(q + 8) = *(u16 *)(q + 8) | 0x28;
    func_8004365C(e, q);

    func_80047AD0(2);
    func_80012D84(4);
    func_8005B85C();
    func_800438B8(0xB4);
    func_80015AD8();
    func_8002CD8C();
}
