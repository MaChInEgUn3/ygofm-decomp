#include "common.h"

void func_800402A0(Slot70 *arg0, s32 arg1) {
    u16 saved = arg0->flags;
    s32 v;

    func_8004020C((s32)arg0);
    v = *(s16 *)(D_800EFE38 + arg1 * 2);
    if (v < 0) {
        *(u16 *)(D_800F2878 + arg1 * 2) = arg0->unkA[0];
        arg0->unk2 = -1;
        arg0->unk0 = -1;
    } else {
        D_800EFE48[v].unk0 = arg0->unkA[0];
        arg0->unk2 = *(u16 *)(D_800EFE38 + arg1 * 2);
    }
    arg0->unk0 = -1;
    *(u16 *)(D_800EFE38 + arg1 * 2) = arg0->unkA[0];
    arg0->flags = saved;
}
