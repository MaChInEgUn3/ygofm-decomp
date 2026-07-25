#include "common.h"

void func_80038024(u8 *arg0, s32 arg1) {
    *(u16 *)(arg0 + 0x34) |= 0x80;
    func_80036C14(arg0, arg1);
    *(u16 *)(arg0 + 0x34) &= 0xFF7F;
    *(u16 *)(arg0 + 0x38) += 0x10;
}
