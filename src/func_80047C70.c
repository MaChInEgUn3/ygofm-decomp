#include "common.h"

void func_80047C70(u8 *arg0) {
    s32 i = 0;

    do {
        func_80076ED0(0, arg0);

        if (func_80077090(arg0) == 0) {
            break;
        }

        i++;
    } while (i < 0x100);
}
