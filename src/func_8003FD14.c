#define D_8009B3EA_IS_SCALAR
#include "common.h"
s32 func_8003FCD8(void);

s32 func_8003FD14(void) {
    s32 r;
    s32 i;
    u8 *a;
    u8 *b;
    s32 *st;

    if ((D_8009B3ED & 0x80) == 0) {
        D_8009B3ED |= 0x80;
        D_8009B3C0 = 0x28;
    }
    r = func_8003FCD8();
    if (r == 1) {
        a = D_801D1200;
        b = D_801D1200 + 0x1000;
        i = 0;
        st = D_801D5608;
        D_8009B3EA = 0xA;
        D_8009B3C0 = 0x24;
        for (; i < 0x28; i++, a += 2, b += 2) {
            if (*(u16 *)a == 0) {
                st[0x10] = 1;
                return 0;
            }
            if (*(u16 *)b == 0) {
                st[0x10] = 2;
                return 0;
            }
        }
        func_8003BC40(D_801B122B, D_801D160C, 6);
        func_8003BC40(D_801B1238, D_801D160C + 0x1000, 6);
    }
    return r;
}
