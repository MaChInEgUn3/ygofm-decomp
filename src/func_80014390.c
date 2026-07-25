#include "common.h"

void func_80014390(s32 arg0, s32 arg1) {
    s32 v;

    if ((arg0 & 0xFF) == 2) {
        v = func_8007E710(arg1);
        if (v > 0) {
            D_800E9E90[0] = v;
        }
        D_8009B0F4 &= ~0x800;
    }
}
