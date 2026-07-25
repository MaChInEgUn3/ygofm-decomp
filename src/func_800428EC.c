#include "common.h"

void func_800428EC(u8 *arg0, s32 arg1) {
    arg0[0x16] = arg1;
    *(s16 *)(arg0 + 0x14) = D_8009AF74[arg0[0x17]] - (s8)arg1;
}
