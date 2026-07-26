#include "common.h"

void func_800140A0(u8 arg0) {
    s32 v = arg0;

    if (v == 5) {
        D_8009B130++;
        func_8007B468(0xA0, &D_8009B104, 6, func_800140A0, -1);
    } else if (v == 2) {
        func_8007DE38(1);
        func_8007DD50(func_80013C28, -1);
        D_8009B114 = 0;
        D_8009B138 = 0;
        D_8009B0F4 &= ~0x400;
    }
}
