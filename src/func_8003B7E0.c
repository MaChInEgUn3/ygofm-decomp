#include "common.h"

u8 func_8003B7E0(u8 *arg0) {
    u8 **pp = (u8 **)(arg0 + *(s8 *)(arg0 + 0x58) * 4);
    u8 *p = *pp;
    u8 v = *p;

    *pp = p + 1;
    return v;
}
