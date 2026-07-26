#include "common.h"

s32 func_80070920(s32 arg0, s32 arg1) {
    if (arg0 == 1) {
        if (func_80070870(arg1) != 0) {
            return 1;
        }
    }

    if (arg0 == 2) {
        if (func_800708C4(arg1) != 0) {
            return 1;
        }
    }

    return 0;
}
