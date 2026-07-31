#define D_8009B400_IS_AGGREGATE
#include "common.h"
void func_8003FF08(s32 arg0);

void func_800386B8(u8 *arg0) {
    u8 **pp = (u8 **)(arg0 + *(s8 *)(arg0 + 0x58) * 4);
    u8 *p = *pp;
    s32 c = *p;
    s32 op;

    *pp = p + 1;
    op = c;
    if (op & 0x3F) {
        func_8003FF08(func_80036D3C(arg0) & 0xFFFF);
    } else {
        if (op & 1) {
            func_8003FF08(D_8009B404[0]);
        }
        if (op & 2) {
            D_8009B404[0] = func_80036D3C(arg0) & 0xFFFF;
        }
        if (op & 4) {
            D_8009B404[0] = D_8009B400[0];
        }
    }
    if (op & 0x80) {
        arg0[0x51] = 0xC;
        D_8009B350 = 1;
    }
}
