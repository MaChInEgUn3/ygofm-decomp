#include "common.h"

void func_80049544(void) {
    s32 v = *(s32 *)(D_8009B458 + 0x81C);

    if (v > 0) {
        if (v < 4) {
            func_8004B854();
        }
    }

    D_8009B458[0x814] = 1;
}
