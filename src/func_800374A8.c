#include "common.h"

void func_800374A8(u8 *arg0) {
    u8 v = arg0[0x51];

    if (!(v & 0x80)) {
        arg0[0x51] = v | 0x80;
        func_800373C8(arg0, 3, 0);
        arg0[0x51] = 0x82;
    }
}
