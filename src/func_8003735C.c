#include "common.h"

s32 func_8003735C(u8 *arg0) {
    s32 i = *(u16 *)(arg0 + 0x5C);
    s32 n = *(u16 *)(arg0 + 0x5E);
    Rec1C *p = &D_800EB288[i];

    while (n != 0) {
        if (!(p->unk11 & 0x80)) {
            return 0;
        }
        if (p->unk13 != 0) {
            return 1;
        }
        n--;
        p++;
    }

    return 0;
}
