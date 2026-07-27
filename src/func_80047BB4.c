#define D_8009B45C_IS_AGGREGATE
#include "common.h"

void func_80047BB4(u16 *arg0, s32 arg1) {
    u8 *p;
    s32 i = 0;

    func_80076ED0(0, 0xF00000);
    func_8004763C();

    p = D_8009B45C[0];
    *(u16 *)(p + 0x40) |= 2;

    if (arg1 > 0) {
        do {
            if (arg0[0] != 0xFFFF) {
                func_80047788(arg0[0]);
            }

            i++;
            arg0++;
        } while (i < arg1);
    }
}
