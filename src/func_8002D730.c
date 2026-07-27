#define D_8009B26C_IS_SCALAR
#define D_8009B269_IS_SCALAR
#define D_8009B268_IS_SCALAR
#define D_8009B26D_IS_SCALAR
#include "common.h"

void func_8002D730(void) {
    u8 v = D_8009B26C;

    if (!(v & 0x40)) {
        D_8009B26C = v | 0x40;
        func_8003C498();
        func_8003C950();
    }

    if (func_8003CA5C() == 0) {
        u8 w;

        func_8003FF34();
        func_80015B00();
        w = D_8009B269;
        D_8009B26C = w;

        if (w != 0) {
            D_8009B268 = 1;
            D_8009B26D = 0;
            D_8009B26C = 8;
            func_8008FB8C(D_800E9DC0, 1);
        }
    }
}
