#include "common.h"

void func_8003E7D4(void) {
    u8 v = D_8009B3C1;

    if (!(v & 0x80)) {
        D_8009B3C1 = v | 0x80;
        D_8009B3EB = 0;
    }
    func_8003E490();
}
