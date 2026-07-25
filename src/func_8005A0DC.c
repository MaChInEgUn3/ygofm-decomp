#include "common.h"

void func_8005A0DC(s32 arg0) {
    s32 v = func_8005F174();

    if (v == 1) {
        if (func_8005F18C() == v) {
            return;
        }
    }
    D_800F2B22[0] = arg0 * 2;
}
