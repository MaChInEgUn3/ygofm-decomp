#include "common.h"

void func_80030198(void) {
    u8 *p;
    u8 *q;

    D_8009B2B2 = 0x80;
    D_8009B2EB = 0;
    D_8009B2F0 = 0;
    func_8003B6AC(1, 1);
    p = func_80035BE4(1, 0xF, 0x10, 0x10, 0x120, 0xA0);
    p[0x5A] = 0x10;
    p[0x5B] = 0x10;
    func_80039A14(p);
    q = func_800400AC(func_8004002C(), 4);
    D_8009B2E4 = q;
    func_800427DC(q, 0);
    q[0x45] = 0xC0;
    q[0x3D] = 0xC0;
    q[0x35] = 0xC0;
    q[0x2D] = 0xC0;
    func_800300C8();
    func_80015A00();
}
