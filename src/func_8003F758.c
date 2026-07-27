#include "common.h"

void func_8003F758(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3) {
    func_8008E6F0(D_800EFE18, arg2);

    D_8009B3F9 = 0;
    D_8009B3C2 = arg1;
    D_8009B3C4 = 0x200;
    D_8009B3DC = (arg1 + 0x1FFF) / 0x2000;
    D_8009B3D0 = (s32)arg0;

    func_8003F740(arg3);
}
