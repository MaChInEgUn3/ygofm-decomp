#include "common.h"

void func_8003E80C(void) {
    u8 v = D_8009B3C1;

    if (!(v & 0x80)) {
        D_8009B3C1 = v | 0x80;
        D_8009B3EB = 1;
        D_8009B3FA |= 0x200;
    }
    func_8003E490();
}
