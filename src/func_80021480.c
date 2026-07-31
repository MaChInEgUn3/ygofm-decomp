#include "common.h"

void func_80021480(s32 arg0) {
    u8 **p;
    s32 i;

    func_80040410(*(u8 **)D_8009B1E8, arg0);
    if (arg0 == 0) {
        p = (u8 **)D_8009B1E8;
        for (i = 0; i < 10; p++, i++) {
            u8 *q = p[1];

            if (q == (u8 *)0) {
                break;
            }
            *(u16 *)(q + 8) |= 0x40;
        }
    } else {
        p = (u8 **)D_8009B1E8;
        for (i = 0; i < 10; p++, i++) {
            u8 *q = p[1];

            if (q == (u8 *)0) {
                break;
            }
            *(u16 *)(q + 8) &= ~0x40;
        }
    }
    func_80039A14(func_80035BE4(0, (D_8009B1E8 + arg0)[0x34], 0x1A, 0x28, 0x120, 0x120));
}
