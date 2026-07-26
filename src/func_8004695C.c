#include "common.h"

void func_8004695C(s32 arg0) {
    D_8009B458[0x509] = arg0;

    if (D_8009B458[0x509] != 0) {
        D_8009B458[0x500] = 1;
    } else {
        D_8009B458[0x500] = 0;
    }
}
