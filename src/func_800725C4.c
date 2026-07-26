#include "common.h"

void func_800725C4(void) {
    s32 *p = D_800F5B98;
    s32 v = p[func_8007058C()];
    s32 k = func_8007058C();

    if (func_8002C7E8(0, v) != 0) {
        p[k] = 1;
    } else {
        p[k] = 0;
    }
}
