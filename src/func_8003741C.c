#include "common.h"

void func_8003741C(u8 *arg0) {
    u8 v = arg0[0x51];
    Rec1C *r;

    if ((v & 0x80) == 0) {
        arg0[0x51] = v | 0x80;
        func_800373C8(arg0, 2, 0);

        return;
    }

    r = &D_800EB288[*(u16 *)(arg0 + 0x5C)];
    if (r->unk11 & 0x80) {
        return;
    }

    arg0[0x56] = 0;
    *(u16 *)(arg0 + 0x38) = 0;
    *(u16 *)(arg0 + 0x3A) = 0;
    arg0[0x51] = 0;
    arg0[0x62] = 0;
}
