#include "common.h"

void func_80039FF8(u8 *arg0) {
    u8 v = arg0[0x32];

    if ((v & 3) == 0) {
        arg0[0x32] = v | 0x10;
        arg0[0x33] = 0;
    }
}
