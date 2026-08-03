#include "common.h"

void func_80047788(s32 arg0) {
    Cmd2C c;
    u8 *p;
    u8 *e;
    s32 n;
    s32 off;

    p = D_8009B45C;
    n = *(u16 *)(p + 2) * 8;
    n = (n + 0x7FF) / 2048 + 1;
    off = (arg0 & 0xFFFF) * 8;
    e = *(u8 **)(p + 0x448);
    e = off + e;
    func_800471D0(*(s32 *)(p + 0x438), 0x801E6800, n + *(u16 *)e,
                  *(s32 *)(e + 4), 0x800, 0x10);
    c.unk0 = 0x51;
    c.unk4 = *(s32 *)(D_8009B45C + 0x438);
    c.unkC = 0x801E6800;
    func_80045BE8(&c);
    p = D_8009B45C;
    e = off + *(u8 **)(p + 0x448);
    *(s32 *)(p + 0x438) += *(s32 *)(e + 4);
}
