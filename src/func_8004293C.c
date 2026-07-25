#include "common.h"

void func_8004293C(u8 *arg0) {
    arg0[0x17] = 3;
    *(s16 *)(arg0 + 0x14) = D_8009AF7A - (s8)arg0[0x16];
}
