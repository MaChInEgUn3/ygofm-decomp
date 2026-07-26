#include "common.h"

void func_80049230(s16 arg0, s32 arg1) {
    Cmd2C c;

    if (arg0 < 0) {
        func_80049010();

        return;
    }

    if (*(u16 *)*(u8 **)(D_8009B45C + 0x1564) != (arg0 >> 4)) {
        func_80049138(arg0, 1);
    }

    c.unk0 = 0x48;
    c.unk2 = arg0;
    c.unk8 = (s16)arg1;
    func_80045BE8(&c);
    *(u16 *)(D_8009B45C + 0x1582) = arg1;
    D_8009B45C[0x1584] = 0xFF;
}
