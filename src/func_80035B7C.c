#include "common.h"

void func_80035B7C(u8 *arg0) {
    func_80035CA8(arg0[0x57]);
    func_80035DB8(arg0[0x57]);
    *(s16 *)(arg0 + 0x34) = 0;
    func_8004036C(*(s32 *)(arg0 + 0x30));
    func_8004036C(*(s32 *)(arg0 + 0x2C));
    func_8004036C(*(s32 *)(arg0 + 0x28));
    *(s32 *)(arg0 + 0x30) = 0;
    *(s32 *)(arg0 + 0x2C) = 0;
    *(s32 *)(arg0 + 0x28) = 0;
}
