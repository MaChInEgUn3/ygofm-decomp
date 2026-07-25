#include "common.h"

s32 func_80035598(u32 *arg0, u32 *arg1) {
    if (*arg0 == *arg1) {
        return 0;
    }
    if (*arg0 >= *arg1) {
        return 1;
    }
    return -1;
}
