#include "common.h"

s32 func_8004BCA8(u8 *arg0) {
    s32 hi = func_8004BAE4(arg0);
    s32 lo = func_8004BAE4(arg0);

    return (lo & 0xFF) | ((hi & 0xFF) << 8);
}
