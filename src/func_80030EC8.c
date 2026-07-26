#define D_8009B3ED_IS_AGGREGATE
#include "common.h"

void func_80030EC8(void) {
    s32 r;

    if ((D_8009B2EB & 0x80) == 0) {
        D_8009B2EB |= 0x80;
        D_8009B3ED[0] = 0;
        D_8009B3EA[0] = 0;
    }

    r = func_8003FCD8();
    if (r == 0) {
        return;
    }
    if (r == 1) {
        func_8005B85C();
        func_800137E4();
        D_8009B26C[0] = 0xE;
    }

    D_8009B2EB = 0;
}
