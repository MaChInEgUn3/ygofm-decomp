#include "common.h"

void func_80070738(s32 arg0, s32 *arg1, s32 *arg2) {
    s32 v;

    switch (arg0) {
    case 0:
    case 1:
        *arg1 = 1;
        v = 5;
        break;
    case 2:
        *arg1 = 0xB;
        v = func_80070710() + 0xA;
        break;
    case 3:
    case 4:
    case 5:
        *arg1 = 0x38;
        v = 0x3C;
        break;
    case 6:
        *arg1 = 0x42;
        v = 0x46;
        break;
    default:
        return;
    }
    *arg2 = v;
}
