#include "common.h"

void func_8003CF14(u8 *arg0) {
    s32 v = func_8003CEB8(arg0, 0x340);
    u32 w = v & 0xFFFF;
    s32 *p = (s32 *)(arg0 + 0x378);
    s32 i = 0xF;

    *(s16 *)(arg0 + 0x37E) = v;
    *(s16 *)(arg0 + 0x37C) = v;
    D_8009AF68 = w | (w << 16);
    D_8009AF64[0] = w | (w << 16);

    do {
        i--;
        *p = func_8003CE74();
        p--;
    } while (i != 0);

    v = func_8003CEB8(arg0 + 0x380, 0x6C);
    w = v & 0xFFFF;
    p = (s32 *)(arg0 + 0x3F8);
    i = 4;

    *(s16 *)(arg0 + 0x3FE) = v;
    *(s16 *)(arg0 + 0x3FC) = v;
    D_8009AF68 = w | (w << 16);
    D_8009AF64[0] = w | (w << 16);

    do {
        i--;
        *p = func_8003CE74();
        p--;
    } while (i != 0);
}
