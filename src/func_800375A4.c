#define D_8009B398_IS_AGGREGATE
#define D_8009B3A4_IS_AGGREGATE
#include "common.h"

void func_800375A4(u8 *arg0) {
    u8 f = arg0[0x51];
    s8 c;

    if ((f & 0x80) == 0) {
        arg0[0x51] = f | 0x80;
        D_8009B32C = 0xA;
        *(u8 **)(arg0 + 0x30) = func_800374F4(arg0);
        return;
    }
    if (D_8009B3A4[0] & 0x80) {
        c = D_8009B32C - 1;
        D_8009B32C = c;
        if (c < 0) {
            D_8009B32C = 0;
        }
    } else {
        D_8009B32C = 0xA;
    }
    /* Read signed here and unsigned in the decrement above: retail has `lb`
     * at this test and `lbu` at that one, so one of them has to be cast. */
    if (*(s8 *)&D_8009B32C == 0 || (D_8009B398[0] & 0xC0) != 0) {
        func_8003FEE0(0xB);
        arg0[0x51] = 2;
        func_8004036C(*(s32 *)(arg0 + 0x30));
        *(s32 *)(arg0 + 0x30) = 0;
    }
}
