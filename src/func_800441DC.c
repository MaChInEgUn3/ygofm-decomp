#include "common.h"

s32 func_800441DC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (func_800440B4(arg0, 3) == 0) {
        return 0;
    }

    func_8008F200(D_800F2B00, D_80010538, arg0, arg1);
    D_8009B44C = arg3;
    D_8009B430 = arg2;
    D_8009B434 = arg4;
    func_80043D48(D_800F2AE0);
    func_8008B330(arg0);

    return 1;
}
