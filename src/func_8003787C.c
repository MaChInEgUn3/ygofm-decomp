#include "common.h"

void func_8003787C(u8 *arg0) {
    u8 v = arg0[0x51];
    u8 *p;

    if (!(v & 0x80)) {
        arg0[0x51] = v | 0x80;
    }
    p = D_8009B328;
    if (p[0x33] == 0) {
        func_80039FD4(p);
        arg0[0x51] = 0;
    }
}
