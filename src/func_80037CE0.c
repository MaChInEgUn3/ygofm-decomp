#include "common.h"

void func_80037CE0(u8 *arg0) {
    u16 f;
    u8 m;

    if (arg0[0x56] >= D_8009B345) {
        arg0[0x51] = 1;
        f = *(u16 *)(arg0 + 0x34);
        arg0[0x56] = 0;
        m = D_8009B34C;
        D_8009B340 = 0;
        *(u16 *)(arg0 + 0x34) = f & 0xEFFF;
        if ((m & 0x30) != 0) {
            D_8009B345 = 2;
        }
    }
}
