#include "common.h"

void func_800429D8(u8 *arg0) {
    if (arg0 == 0) {
        return;
    }
    *(u16 *)(arg0 + 0x36) = 0;
    *(u16 *)(arg0 + 0x38) = 0;
    *(u16 *)(arg0 + 0x3A) = 0;
    arg0[0x62] = 0x80;
    arg0[0x63] = 0x80;
    arg0[0x64] = 0x80;
}
