#include "common.h"

s32 func_80070870(s32 arg0) {
    u32 v;
    s32 i;
    u16 *q;

    v = D_801AB000[arg0].unk0;
    q = (u16 *)D_800F5BE8;
    for (i = 0; i < 0x20; i++) {
        if (v == q[i + 0x1F]) {
            return 1;
        }
    }
    return 0;
}
