#include "common.h"

void func_8003CB7C(void) {
    s32 i = 1;
    volatile u16 *c = &D_8009B3A6;
    volatile u16 *b = &D_8009B39A;
    volatile u16 *a = &D_8009B396;

    do {
        *a = 0;
        *b = *a;
        *c = *b;
        a--;
        b--;
        c--;
        i--;
    } while (i >= 0);

    for (i = 0x1F; i >= 0; i--) {
        D_800EF6B0[i] = 0;
    }

    D_8009B390 = 0;
    D_8009B3B0 = 0;
    D_8009B3B4 = 0;
    D_8009B3A8 = 0;
}
