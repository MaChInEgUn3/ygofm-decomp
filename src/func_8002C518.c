#include "common.h"

s32 func_8002C518(s32 arg0) {
    s32 v;
    u8 *b;

    b = D_801D0000;
    v = -1;
    if ((arg0 + b)[0x24F] != 0) {
        v = 1;
    }
    if (v < 0) {
        return func_8002C4DC(arg0);
    }
    return 1;
}
