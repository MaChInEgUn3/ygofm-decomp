#include "common.h"

void func_80038E1C(u8 *arg0) {
    s32 n = arg0[0x56] + 1;
    ObjFn fn;

    *(s16 *)(arg0 + 0x38) = 0x1000;
    arg0[0x56] = n;
    if (func_80037C74(arg0) != 0) {
        arg0[0x51] = 4;
    }
    fn = D_8009B340;
    D_8009B350 = 1;
    if (fn != 0) {
        fn(arg0);
    }
}
