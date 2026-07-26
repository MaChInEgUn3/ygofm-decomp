#include "common.h"

void func_8002BF3C(void) {
    u8 *p = D_801D0250;
    s32 i = 0;
    u16 *q;

    do {
        if (*p != 0) {
            func_8002CCE4(i + 0x121);
        }
        i++;
        p++;
    } while (i < 0x2D2);

    q = (u16 *)D_801D0200;
    i = 0;
    do {
        if (*q != 0) {
            func_8002CCE4(*q + 0x120);
        }
        i++;
        q++;
    } while (i < 0x28);
}
