#include "common.h"

void func_80015944(s32 arg0) {
    u8 *p;

    if (arg0 == 0xFFFFFF) {
        D_8009B145 = 1;
    }
    *(s32 *)D_800E9EC8 = arg0;
    p = D_800E9EC8;
    func_800158B8();
    p[6] |= 0x30;
    func_80015870();
}
