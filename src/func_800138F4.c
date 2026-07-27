#include "common.h"

void func_800138F4(s32 *out, s32 arg1) {
    u8 buf[0x18];

    while (func_8007D3F0(buf, arg1) == 0) {
    }

    *out = func_8007E710(buf);
}
