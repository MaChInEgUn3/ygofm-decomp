#include "common.h"

void func_800234E4(u8 *arg0) {
    s32 n = *(s8 *)(arg0 + 0x10) * 5 + *(s8 *)(arg0 + 0xF);
    u8 *p = func_800400AC(func_8004002C(), 2);
    u8 *e;
    u8 *tbl;

    func_80040468(p, 4, 3, arg0[0x17] + D_8009B1D5 * 4, 0x1F, 0x100);
    tbl = D_80090800;
    e = &tbl[n * 4 + D_8009B1D5 * 80];
    *(u16 *)(p + 0x28) = *(u16 *)e;
    *(u16 *)(p + 0x2A) = *(u16 *)(e + 2);
    *(u16 *)(p + 8) |= 0x28;
    *(void **)(p + 0x24) = func_80015D18;
    *(u8 **)(arg0 + 4) = p;
}
