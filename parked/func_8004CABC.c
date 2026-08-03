#include "common.h"

s32 func_8004CABC(void) {
    u8 *p;
    s32 i;
    s32 n;
    s32 c;

    p = D_8009B458;
    i = 0;
    c = *(u16 *)(p + 0x7FA);
    if (c == 0) {
        return 3;
    }
    n = c;
    do {
        if (p[0x53C] != 1) {
            return 1;
        }
        i++;
        i--;
        i++;
        p += 0x2C;
    } while (i < n);
    return 3;
}
