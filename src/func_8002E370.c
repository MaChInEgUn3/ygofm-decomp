#include "common.h"

void func_8002E370(u8 *arg0) {
    Rec4C *base = D_800EB010;
    Rec4C *p;
    s32 i = 2;

    p = base + 2;
    do {
        if (p->unk30 >= 0) {
            *(u16 *)(arg0 + 0x34) |= 2;

            return;
        }
        p--;
    } while (--i >= 0);
}
