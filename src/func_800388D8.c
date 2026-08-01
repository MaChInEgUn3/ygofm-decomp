#include "common.h"

void func_800388D8(u8 *arg0) {
    u8 **pp = (u8 **)(arg0 + *(s8 *)(arg0 + 0x58) * 4);
    u8 *p = *pp;
    s32 c = *p;
    s32 op;

    *pp = p + 1;
    op = c;
    if (op & 0x40) {
        D_8009B140 = D_8009AF76 + 9;
    }
    if (op & 0x20) {
        D_8009B140 = 4;
    }
    if (op & 0x10) {
        if (op & 1) {
            func_80015944(0xFFFFFF);
        } else {
            func_8001581C(0xFFFFFF);
        }
        D_800E9ECF[0] = 4;
    } else if (op & 1) {
        func_80015C84();
    } else {
        func_80015C0C();
    }
    if (op & 0x80) {
        func_80015998();
    }
}
