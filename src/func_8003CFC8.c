#include "common.h"

void func_8003CFC8(u8 *arg0) {
    s32 v = func_8003CEB8(arg0 + 0x400, 0x204);
    u32 *p = (u32 *)(arg0 + 0x624);
    s32 i = 8;

    *(u16 *)(arg0 + 0x606) = v;
    *(u16 *)(arg0 + 0x604) = v;
    v &= 0xFFFF;
    v |= v << 16;
    D_8009AF68 = v;
    D_8009AF64[0] = v;

    do {
        i--;
        *p = func_8003CE74();
        p--;
    } while (i != 0);
}
