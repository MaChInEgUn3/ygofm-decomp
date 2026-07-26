#include "common.h"

s32 func_8004BC2C(u8 *arg0) {
    s32 a = func_8004BAE4(arg0);
    s32 b = func_8004BAE4(arg0);
    s32 c = func_8004BAE4(arg0);
    s32 d = func_8004BAE4(arg0);

    return (d & 0xFF) + ((c & 0xFF) << 8) + ((b & 0xFF) << 16) + (a << 24);
}
