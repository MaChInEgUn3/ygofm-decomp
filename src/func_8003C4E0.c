#include "common.h"

void func_8003C4E0(s32 arg0) {
    u8 *t = D_801D5708;

    t[0] = 4;
    t[1] = 4;
    t[2] = 4;
    t[3] = 4;
    t[4] = 4;
    t[arg0] = 0;

    if (arg0 != 0) {
        t[3] = 2;
    } else {
        t[4] = 2;
    }

    func_80035BE4(1, 0xEF, 0x18, 0x38, 0x120, 0x100);
    func_80039A14(D_800EB15C);
}
