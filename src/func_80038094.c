#include "common.h"

void func_80038094(u8 *arg0) {
    u8 **pp = (u8 **)(arg0 + *(s8 *)(arg0 + 0x58) * 4);
    u8 *p = *pp;
    s32 v = *p;

    *pp = p + 1;
    func_80038024(arg0, v);
}
