#include "common.h"

void func_80059B90(s32 arg0, u8 *arg1) {
    u8 a[8];
    u8 b[0x50];
    u8 c[0x20];

    func_8008E3D0(a, 0, 8);
    *(u16 *)a = arg0;
    func_800580D4(0, 0xF, a, b);
    func_8008A4A0(b, c);

    *(u16 *)(arg1 + 0) = *(u16 *)(c + 0x14);
    *(u16 *)(arg1 + 2) = *(u16 *)(c + 0x18);
    *(u16 *)(arg1 + 4) = *(u16 *)(c + 0x1C);
    *(u16 *)(arg1 + 6) = 0;
}
