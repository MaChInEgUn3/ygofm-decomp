#include "common.h"

void func_80039F90(u8 *arg0) {
    s32 i = 2;
    s32 *p = (s32 *)(arg0 + 8);

    do {
        func_8004036C(*p);
        *p = 0;
        p--;
    } while (--i >= 0);
}
