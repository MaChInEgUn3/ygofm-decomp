#include "common.h"

s32 func_80044380(s32 arg0, s32 arg1, s32 arg2) {
    if (func_800440B4(arg0, 0xC) == 0) {
        return 0;
    }

    D_8009B44C = arg2;
    D_8009B430 = arg1;
    func_80043D48(D_800F2AE0);
    func_8008B330(arg0);

    return 1;
}
