#include "common.h"

s32 func_80027508(void) {
    u8 *e;
    s32 *t;
    s32 n;
    s32 c;

    if ((func_8008E590() & 1) == 0) {
        if (func_80026DC8() == 0) {
            return 0;
        }
    }
    if ((func_8008E590() & 1) == 0) {
        if (func_80027060() == 0) {
            return 0;
        }
    }
    if ((func_8008E590() & 3) == 0) {
        if (func_8002712C() == 0) {
            return 0;
        }
    }
    if (func_80027228() == 0) {
        return 0;
    }

    e = &D_801A7AD8[(D_8009B1D5 * 15 + func_800358FC(5)) * 0x1C];
    t = D_801D4244;
    if (((t[*(s16 *)(e + 0xC) - 1] >> 26) & 0x1F) < 0x14) {
        n = func_80026C0C(5);
        if (n < 0) {
            n = func_800358FC(5);
        }
        D_800EAE88[1] = 0;
        D_800EAE88[6] = n % 5 + 1;
        D_800EAE88[0] = *(s8 *)(e + 0x18) % 5 + 0xB;
        D_800EAE88[7] = func_8008E590() & 1;
        goto set8;
    }

    n = func_80026C0C(0xA);
    if (n < 0) {
        n = func_800358FC(5);
    }
    D_800EAE88[1] = 0;
    D_800EAE88[7] = 0;
    D_800EAE88[6] = n % 5 + 6;
    D_800EAE88[0] = *(s8 *)(e + 0x18) % 5 + 0xB;
    D_800EAE88[8] = func_8008E590() & 1;
    if (((t[*(s16 *)(e + 0xC) - 1] >> 26) & 0x1F) == 0x17) {
    set8:
        D_800EAE88[8] = 1;
    }
    return 0;
}
