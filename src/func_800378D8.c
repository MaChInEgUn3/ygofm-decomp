#include "common.h"

void func_800378D8(u8 *arg0) {
    u8 v = arg0[0x51];

    if (!(v & 0x80)) {
        arg0[0x51] = v | 0x80;
    }

    if (D_8009B328[0x33] == 0) {
        arg0[0x51] = 0;
    }
}
