#include "common.h"

s32 func_800443EC(s32 arg0, s32 arg1, s32 arg2) {
    if (func_800440B4(arg0, 8) == 0) {
        return 0;
    }

    func_8008F200(D_800F2B00, D_80010538, arg0, arg1);
    D_8009B434 = arg2;
    func_80043D48(D_800F2AE0);
    func_8008B330(arg0);

    return 1;
}
