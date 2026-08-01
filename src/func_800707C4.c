#include "common.h"

void func_800707C4(s32 arg0, s32 *arg1, s32 *arg2) {
    s32 v;

    switch (arg0) {
    case 0:
    case 1:
        *arg1 = 1;
        v = 5;
        break;
    case 2:
    case 3:
        *arg1 = 6;
        v = 0xA;
        break;
    case 4:
        *arg1 = 0xB;
        v = func_80070710() + 0xA;
        break;
    case 5:
    case 6:
        *arg1 = 0x38;
        v = 0x3C;
        break;
    case 7:
    case 8:
        *arg1 = 0x3D;
        v = 0x41;
        break;
    case 9:
        *arg1 = 0x42;
        v = 0x46;
        break;
    default:
        return;
    }
    *arg2 = v;
}
