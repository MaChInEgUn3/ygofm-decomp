#include "common.h"

s32 func_8004BBBC(s32 arg0) {
    do {
        if (func_8004BAA0(D_8009AF80, *(s32 *)(D_8009B458 + 0x7DC) + arg0, 4) == 0) {
            return arg0 + 4;
        }

        arg0++;
    } while (*(u32 *)(D_8009B458 + 0x7EC) >= arg0);

    return -1;
}
