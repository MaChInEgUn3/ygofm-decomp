#include "common.h"

void func_800732A0(void) {
    u8 *p = (u8 *)D_800F5BE8;
    s32 n = 0;
    s32 i = n;

    while (i <= p[0xA3]) {
        s32 c = p[i + 0x38];

        if (c >= 0xB) {
            D_800EAE88[n] = c;
            n++;
        }
        i++;
    }
}
