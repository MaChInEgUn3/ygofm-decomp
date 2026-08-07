#include "common.h"

s32 func_8001EF78(u8 *arg0, u8 *arg1) {
    s32 h;
    s32 r;

    h = func_800170C8(arg0);
    r = (h >> 16) + func_8001EE44(arg0, arg1);
    if (r >= 0x2710) {
        r = 0x270F;
    }
    return r;
}
