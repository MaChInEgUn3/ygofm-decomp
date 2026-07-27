#define D_8009B26C_IS_SCALAR
#define D_8009B268_IS_SCALAR
#define D_8009B26D_IS_SCALAR
#define D_8009B269_IS_SCALAR
#include "common.h"

void func_8002D588(void) {
    u8 v = D_8009B26C;
    s32 r;

    if (!(v & 0x40)) {
        D_8009B26C = v | 0x40;
        func_8005B85C();
        func_800137E4();
        func_80039E9C();
        func_8018001C(D_8009B268, D_8009B26D);
        func_80015A00();
    }

    func_8008E590();

    r = func_80180390();

    if (r >= 0) {
        func_8003FF34();
        func_80015B00();
        func_80180DD0();
        func_8002D458(r);
        D_8009B269 = 8;
    }
}
