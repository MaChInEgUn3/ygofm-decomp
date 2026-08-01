#include "common.h"

void func_8001EC70(u8 *arg0) {
    if (func_80042B98(arg0) == 0) {
        func_80043178(arg0);
        *(s16 *)(arg0 + 0x60) = 0;
        *(s16 *)(arg0 + 0x2E) = 0;
    }
    func_8004318C(arg0, *(s16 *)(arg0 + 0x28), *(s16 *)(arg0 + 0x2A),
                  *(s16 *)(arg0 + 0x60));
    *(u16 *)(arg0 + 0x60) += 0x800 / *(s16 *)(arg0 + 0x2C);
    if (*(s16 *)(arg0 + 0x60) >= 0x800) {
        arg0[0x6C] = 0;
        *(s32 *)(arg0 + 0x24) = 0;
    }
}
