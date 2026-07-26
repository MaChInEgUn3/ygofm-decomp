#include "common.h"

u8 *func_80018004(u8 *arg0) {
    u8 *p = func_80017F04(arg0);

    if (*(s8 *)(D_8009B1C8 + 0x1F) != 0) {
        *(u16 *)(arg0 + 0x16) |= 0x2000;
        p[0x67] = *(*(u8 **)(arg0 + 4) + 4) + 1;
        if (*(s8 *)(D_8009B1C8 + 0x1F) < 0) {
            p[0x67] = 0xFF;
        }
    }

    return p;
}
