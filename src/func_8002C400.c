#include "common.h"

s32 func_8002C400(s32 arg0) {
    if (arg0 >= 10) {
        return (arg0 % 10) * 14 + 174;
    }

    return (arg0 % 10) * 14 + 14;
}
