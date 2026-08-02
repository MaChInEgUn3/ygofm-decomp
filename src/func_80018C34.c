#include "common.h"

void func_80018C34(u8 *arg0) {
    if (func_80042B98(arg0) == 0) {
        *(s16 *)(arg0 + 0x28) = *(u16 *)(arg0 + 0x30) - 0x140;
        *(s16 *)(arg0 + 0x2C) = 0x400 / *(s16 *)(arg0 + 0x60);
        func_80043178(arg0);
        *(s16 *)(arg0 + 0x60) = -0x400;
    }
    func_80043230(arg0, *(s16 *)(arg0 + 0x28), *(s16 *)(arg0 + 0x32),
                  *(s16 *)(arg0 + 0x60));
    *(u16 *)(arg0 + 0x60) += *(u16 *)(arg0 + 0x2C);
    if ((s16)*(u16 *)(arg0 + 0x60) >= 0) {
        *(s32 *)(arg0 + 0x24) = 0;
        arg0[0x6C] = 0;
        *(u16 *)(arg0 + 0x30) = *(u16 *)(arg0 + 0x28);
    }
}
