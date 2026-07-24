#include "common.h"

void func_80015BD8(u8 arg0, u8 arg1) {
    D_800E9EC8[5] = arg0;
    D_800E9EC8[6] = arg1 | 0x80;
}
