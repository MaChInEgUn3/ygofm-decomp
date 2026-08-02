#include "common.h"

s32 func_8005A2E0(s32 arg0) {
    SVector sp10;
    SVector sp18;
    u8 *p = D_800F3A10 + arg0 * 3616;
    u8 *b;

    func_8008E3D0(&sp18, 0, 8);
    b = D_800F56F0;
    sp18.vx = *(u16 *)(b + 0xC) - *(u16 *)p;
    sp18.vy = *(u16 *)(b + 0x10) - *(u16 *)(p + 2);
    sp18.vz = *(u16 *)(b + 0x14) - *(u16 *)(p + 4);
    sp10 = sp18;
    return func_80086E50(sp10.vx * sp10.vx + sp10.vy * sp10.vy
                         + sp10.vz * sp10.vz);
}
