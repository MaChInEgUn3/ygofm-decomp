#include "common.h"

void func_80026BA4(s32 arg0, s32 arg1) {
    s32 v;

    if (!((arg0 >= 0x12D && arg0 <= 0x15E) ||
          (arg0 >= 0x28B && arg0 <= 0x2BC) ||
          arg0 == 0x2D1)) {
        return;
    }

    if (arg0 < 0x28B) {
        v = arg0 - 0x12D;
    } else {
        v = arg0 - 0x259;
        if (arg0 == 0x2D1) {
            v = 0x64;
        }
    }

    D_8009B1A8 = v;
    D_8009B1D2 = arg0;
    D_8009B220 = 0x8000;

    if (arg1 != 0) {
        D_8009B220 = 0xC000;
    }
}
