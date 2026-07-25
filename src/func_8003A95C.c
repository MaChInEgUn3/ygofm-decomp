#include "common.h"

void func_8003A95C(u8 *arg0, s32 arg1, s32 arg2) {
    *(s16 *)(arg0 + 0x34) = arg1;
    *(s16 *)(arg0 + 0x36) = arg2;
    func_8003A920(arg0, arg1, arg2);
}
