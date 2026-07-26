#include "common.h"

void func_8002EE20(void) {
    u8 *p = D_8009B290;
    s32 off;

    D_8009B290 = p + 2;
    off = p[0] | (p[1] << 8);
    D_8009B27C = 0;
    off += (s32)D_801A8000;
    D_8009B290 = (u8 *)off;
}
