#include "common.h"
s32 func_80026D18(u8 **arg0, s32 arg1, s32 arg2);
s32 func_80026C0C(s32 arg0);

s32 func_80027060(void) {
    u8 *sp10[6];
    s32 slot;
    s8 v;

    if (func_80026D18(sp10, 0, 0x15) == 0) {
        return 1;
    }
    slot = func_80026C0C(0xA);
    if (slot < 0) {
        return 1;
    }
    v = sp10[0][0x18];
    D_800EAE88[8] = 1;
    D_800EAE88[1] = 0;
    D_800EAE88[7] = 0;
    D_800EAE88[6] = slot % 5 + 6;
    D_800EAE88[0] = v % 5 + 0xB;
    return 0;
}
