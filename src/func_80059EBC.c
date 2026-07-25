#include "common.h"

void func_80059EBC(s32 arg0) {
    s32 v = func_8005F174();

    if (v == 1) {
        if (func_8005F18C() == v) {
            return;
        }
    }
    func_80052D2C(arg0, 0, 0, 0);
}
