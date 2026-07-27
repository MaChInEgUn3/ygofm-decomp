#include "common.h"

void func_8004671C(void) {
    u8 buf[0x28];

    *(s32 *)(buf + 0x00) = 0x2C3;
    *(u16 *)(buf + 0x04) = 0x3FFF;
    *(u16 *)(buf + 0x06) = 0x3FFF;
    *(u16 *)(buf + 0x10) = 0x7FFF;
    *(u16 *)(buf + 0x12) = 0x7FFF;
    *(s32 *)(buf + 0x14) = 0;
    *(s32 *)(buf + 0x18) = 1;

    func_80077C70(buf);
}
