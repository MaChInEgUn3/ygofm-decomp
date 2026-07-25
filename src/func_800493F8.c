#include "common.h"

void func_800493F8(void) {
    u16 *p;

    func_80049010();
    p = (u16 *)0x801EA800;
    *(u16 **)(D_8009B45C + 0x1564) = p;
    *p = 0xFFFF;
}
