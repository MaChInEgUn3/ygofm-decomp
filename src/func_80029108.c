#include "common.h"

void func_80029108(u8 *arg0, s32 arg1) {
    s32 v = 2;

    if (arg1 >= 0) {
        v = arg0[0x6A];
    }
    if (v != arg0[0x69]) {
        func_80040410(arg0, v);
        func_80041D60(arg0);
        D_8009B424[0] = 1;
    }
}
