#include "common.h"

/* Registers the four interrupt callbacks on two roots and then arms all
 * eight handles. The cursor is assigned FIRST, above the three global
 * stores: retail materialises the table base before any callback address,
 * and written after the calls the whole register file rotates by one. */

void func_80043EBC(void) {
    s32 *t;
    s32 i;

    t = D_800F2AE0;
    D_8009B43E = -1;
    D_8009B44E = 0;
    D_8009B444 = 0;
    func_800738B0();

    D_800F2AE0[0] = func_80073860(0xF4000001, 4, 0x1000, func_80044CFC);
    D_800F2AE0[1] = func_80073860(0xF4000001, 0x100, 0x1000, func_80044D0C);
    D_800F2AE0[2] = func_80073860(0xF4000001, 0x8000, 0x1000, func_80044D20);
    D_800F2AE0[3] = func_80073860(0xF4000001, 0x2000, 0x1000, func_80044D34);
    D_800F2AE0[4] = func_80073860(0xF0000011, 4, 0x1000, func_80044CFC);
    D_800F2AE0[5] = func_80073860(0xF0000011, 0x100, 0x1000, func_80044D0C);
    D_800F2AE0[6] = func_80073860(0xF0000011, 0x8000, 0x1000, func_80044D20);
    D_800F2AE0[7] = func_80073860(0xF0000011, 0x2000, 0x1000, func_80044D34);

    for (i = 8; i != 0; i--) {
        func_80073890(*t);
        t++;
    }

    func_800738C0();
}
