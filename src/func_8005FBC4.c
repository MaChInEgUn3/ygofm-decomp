#include "common.h"

void func_8005FBC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u16 *arg4, s32 arg5) {
    arg4[3] = arg0;
    arg4[0] = (arg1 - arg2) * arg5 - arg0 + arg3;
    arg4[1] = (arg0 + arg2 - arg1 * 2) * arg5;
    arg4[2] = (arg1 - arg0) * arg5;
}
