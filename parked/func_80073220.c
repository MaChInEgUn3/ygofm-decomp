#include "common.h"

void func_80073220(void) {
    s32 i = 5;
    s32 count = 0;
    u8 *p = &D_800EAE88[i];
    u8 *b;

    do {
        *p = 0;
        i--;
        p--;
    } while (i >= 0);

    i = 0;
    b = (u8 *)D_800F5BE8;

    while (i <= b[0xA3]) {
        s32 v = b[0x38 + i];

        if (v >= 0xB) {
            D_800EAE88[count] = v;
            count++;
        }

        i++;
    }
}
