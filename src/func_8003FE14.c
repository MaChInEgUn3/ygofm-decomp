#include "common.h"

void func_8003FE14(void) {
    u8 *p = D_801D1880;
    u8 *q;

    func_8003CF14(p);
    q = p + 0x1000;
    func_8003CF14(q);
    D_8009B3E0 = q;
    func_8003F758(p, 0x400, D_80010384, 4);
}
