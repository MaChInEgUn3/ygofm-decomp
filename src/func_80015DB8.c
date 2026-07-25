#include "common.h"

void func_80015DB8(u8 *arg0) {
    u8 i = arg0[0x6A];
    Slot70 *p = &D_800EFE48[i];

    *(s32 *)(arg0 + 0x28) = p->unk28;
    func_80015D18(arg0);
}
