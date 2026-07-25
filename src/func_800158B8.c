#include "common.h"

void func_800158B8(void) {
    u8 *p = D_800E9EC8;
    s32 a = p[4];

    *(s16 *)(p + 8) = 0xFF;
    p[5] = 0;
    p[6] = 0x80;
    func_800156B8(a);
    p[7] = 0xC;
    func_80015870();
}
