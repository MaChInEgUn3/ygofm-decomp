#include "common.h"

void func_8002348C(u8 *arg0) {
    s32 row = *(s8 *)(arg0 + 0x10);
    s32 col = *(s8 *)(arg0 + 0xF);
    s32 i = D_8009B1D5;

    func_80023144(arg0, D_800907D8[row * 5 + col + i * 20]);
}
