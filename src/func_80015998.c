#include "common.h"

void func_80015998(void) {
    u8 *p = D_800E9EC8;

    do {
        func_80012D4C();
    } while (p[6] & 0x80);
}
