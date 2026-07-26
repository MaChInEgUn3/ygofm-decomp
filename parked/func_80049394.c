#define D_8009B45C_IS_AGGREGATE
#include "common.h"

void func_80049394(u16 *arg0) {
    func_80049010();

    if (arg0 != 0) {
        *(u16 **)(D_8009B45C[0] + 0x1564) = arg0;
    } else {
        *(u16 **)(D_8009B45C[0] + 0x1564) = (u16 *)0x801EA800;
    }

    **(u16 **)(D_8009B45C[0] + 0x1564) = 0xFFFF;
}
