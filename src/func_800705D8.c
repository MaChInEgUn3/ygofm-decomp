#include "common.h"

void func_800705D8(s32 arg0) {
    func_8008E360(D_800F5BE8, 0xD4);
    func_8008E360(D_800EAE88, 0xC);
    func_8008E360(D_800F5B98, 0x50);

    if (arg0 == 0) {
        D_800F5BE8[0].unk0[0] = 1;
    }

    D_800F5BE8[0].base = (u8 *)arg0;
    D_800F5BE8[0].cursor = (u8 *)arg0;
}
