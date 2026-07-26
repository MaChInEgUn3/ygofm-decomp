#define D_8009B26C_IS_SCALAR
#include "common.h"

void func_8002CE64(void) {
    u8 v = D_8009B26C;

    if ((v & 0x40) == 0) {
        s32 a = D_8009B27A[0];

        D_8009B26C = v | 0x40;
        func_8002FD10(a);
        D_8009B254[0] = 0;

        return;
    }

    func_8002FFD4(D_800EAE98);
    func_8002FA54();
    if (D_8009B26C & 0x40) {
        return;
    }

    func_8003FF34();
    func_80015B00();
}
