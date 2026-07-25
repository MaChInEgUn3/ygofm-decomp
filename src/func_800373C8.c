#include "common.h"

void func_800373C8(u8 *arg0, s32 arg1, s32 arg2) {
    s32 idx = *(u16 *)(arg0 + 0x5C);
    s32 n = *(u16 *)(arg0 + 0x5E);
    Rec1C *p = &D_800EB288[idx];

    if (n == 0) {
        return;
    }
    do {
        if (!(p->unk11 & 0x80)) {
            return;
        }
        p->unk13 = arg1;
        p->unk15 = arg2;
        n--;
        p++;
    } while (n != 0);
}
