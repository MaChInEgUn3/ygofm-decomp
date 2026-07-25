#include "common.h"

void func_80042918(u8 *arg0) {
    arg0[0x17] = 1;
    *(s16 *)(arg0 + 0x14) = D_8009AF76 - (s8)arg0[0x16];
}
