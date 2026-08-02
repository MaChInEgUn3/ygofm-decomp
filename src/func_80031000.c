#define D_8009B3ED_IS_AGGREGATE
#include "common.h"

void func_80031000(void) {
    s32 v = D_8009B2EB;
    s32 r;

    if ((v & 0x80) == 0) {
        D_8009B2EB = v | 0x80;
        D_8009B3ED[0] = 0;
        D_8009B3EA[0] = 0;
    }

    r = func_8003FD14();
    if (r != 0) {
        if (r == 1) {
            func_8005B85C();
            func_800137E4();
            D_8009B26C[0] = 0x10;
        }
        D_8009B2EB = 0;
    }
}
