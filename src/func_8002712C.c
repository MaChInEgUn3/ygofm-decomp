#include "common.h"

s32 func_8002712C(void) {
    u8 *sp10[6];
    s32 slot;
    s8 v;

    if (func_80026D18(sp10, 0, 0x14) != 0) {
        v = sp10[0][0x18];
        D_800EAE88[1] = 0;
        D_800EAE88[7] = 0;
        D_800EAE88[8] = 0;
        D_800EAE88[6] = 6;
        D_800EAE88[0] = v % 5 + 0xB;
        slot = func_80026C0C(0xA);
        if (slot >= 0) {
            D_800EAE88[8] = func_8008E590() & 1;
            D_800EAE88[6] += slot % 5;
        }
        return 0;
    }
    return 1;
}
