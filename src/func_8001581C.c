#include "common.h"

void func_8001581C(s32 arg0) {
    u8 *p;

    if (arg0 == 0xFFFFFF) {
        D_8009B145 = 1;
    }
    *(s32 *)D_800E9EC8 = arg0;
    p = D_800E9EC8;
    func_80015780();
    p[6] |= 0x30;
    func_8001572C();
}
