#include "common.h"

void func_80038B08(u8 *arg0) {
    func_8004036C(*(s32 *)(arg0 + 0x30));
    *(s32 *)(arg0 + 0x30) = 0;
    arg0[0x51] = 2;
    arg0[0x62] = 0;
    D_8009B350 = 1;
}
