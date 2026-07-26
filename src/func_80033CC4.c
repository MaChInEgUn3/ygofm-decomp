#include "common.h"

void func_80033CC4(u8 *arg0) {
    s32 k = arg0[0x2D47] * 16;
    u8 *r = D_80090DD8 + *(s8 *)(arg0 + 0x2D46) * 2;

    arg0[0x2D45] = r[k + 1] & 0xF;
}
