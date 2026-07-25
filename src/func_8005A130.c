#include "common.h"

void func_8005A130(s32 arg0) {
    s32 v = func_8005F174();
    u8 *p;

    if (v == 1) {
        if (func_8005F18C() == v) {
            return;
        }
    }
    p = D_800F2B20;
    *(s16 *)(p + 6) = arg0;
    *(s16 *)(p + 4) = arg0;
}
