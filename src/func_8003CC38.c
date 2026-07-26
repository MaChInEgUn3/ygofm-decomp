#include "common.h"

void func_8003CC38(void) {
    u8 *p = D_800EF668;

    if (p[0] == 0) {
        if ((p[1] & 0xF) != 0) {
            D_8009B3A8 |= ((p[2] << 8) | p[3]) ^ 0xFFFF;
        }
    }

    {
        u8 *q = D_800EF668;

        if (q[0x22] == 0) {
            if ((q[0x23] & 0xF) != 0) {
                D_8009B3A8 |= (((q[0x24] << 8) | q[0x25]) ^ 0xFFFF) << 16;
            }
        }
    }
}
