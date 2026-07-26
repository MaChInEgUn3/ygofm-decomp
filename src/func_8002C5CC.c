#include "common.h"

u8 *func_8002C5CC(void) {
    u8 *p = D_800EAD88;
    s32 n;

    for (n = 8; n != 0; n--) {
        if (!(p[0x1C] & 0x80)) {
            return p;
        }
        p += 0x20;
    }

    return 0;
}
