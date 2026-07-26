#include "common.h"

void func_80059F18(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 b = 0;
    s32 c;
    s32 r;

    if (arg1 >= 0) {
        b = arg1 + 1;
    }

    c = 0;
    if (arg2 >= 0) {
        c = arg2 + 1;
    }

    r = func_8005F174();
    if (r == 1 && func_8005F18C() == r) {
        return;
    }

    func_80052D2C(arg0, b, c, arg3);
}
