#include "common.h"

void func_8004C0AC(u8 *arg0) {
    u32 i = 0;
    u32 n = func_8004BB34(arg0);

    do {
        i++;
        if ((func_8004BAE4(arg0) & 0xFF) == 0xF7) {
            break;
        }
    } while (i < n);
}
