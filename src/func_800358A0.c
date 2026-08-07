#include "common.h"

void func_800358A0(s32 arg0, s32 arg1, u8 *arg2) {
    s32 i;

    func_800357E8(arg0, arg1, arg2);
    i = arg1;
    while (1) {
        i--;
        if (i <= 0) {
            break;
        }
        if (arg2[i] >= 0xA) {
            arg2[i] = 0;
        }
    }
}
