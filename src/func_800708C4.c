#include "common.h"

s32 func_800708C4(s32 arg0) {
    u32 v;
    s32 i;
    u8 *q;

    v = D_801AB000[arg0].unk8;
    i = 0;
    q = (u8 *)D_800F5BE8;
    for (; i < 0x19; i++) {
        if (v == q[i + 0x7E] - 1) {
            return 1;
        }
    }
    return 0;
}
