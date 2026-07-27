#include "common.h"

u16 func_80047C50(s32 arg0) {
    u16 v = arg0;

    if (arg0 & 0x8000) {
        return v;
    }

    return -1;
}
