#include "common.h"

void func_80015780(void) {
    D_800E9EC8[5] = 0xFF;
    D_800E9EC8[6] = 0x80;
    *(u16 *)(D_800E9EC8 + 8) = 0;
    D_8009B141 &= 0x7F;
    func_800156B8(D_800E9EC8[4]);
    D_800E9EC8[7] = 0xC;
    func_8001572C();
}
