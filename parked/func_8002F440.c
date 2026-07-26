#include "common.h"

void func_8002F440(void) {
    if (func_8002E3B4() == 0) {
        u8 *p = D_8009B290;
        s32 c = *p;

        D_8009B290 = p + 1;
        func_800158B8();

        if ((c & 0x3F) != 0) {
            D_800E9ECF[0] = c & 0x3F;
        }
        if (c & 0x80) {
            return;
        }
    } else if (D_800E9ECE[0] & 0x80) {
        return;
    }

    D_8009B27C = 0;
}
