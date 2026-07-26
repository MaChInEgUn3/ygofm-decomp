#define D_8009B450_IS_SCALAR
#include "common.h"

s32 func_800440B4(s32 arg0, s32 arg1) {
    if (D_8009B43E >= 0) {
        return 0;
    }

    D_8009B43C = 10;
    D_8009B437 = arg0;
    D_8009B43E = arg1;
    D_8009B44F = 0;
    D_8009B43D = 0;
    D_8009B450 = -1;

    return 1;
}
