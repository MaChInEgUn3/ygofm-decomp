#define D_8009B26C_IS_SCALAR
#include "common.h"

void func_8002D2D8(void) {
    u8 v = D_8009B26C;

    if ((v & 0x40) == 0) {
        D_8009B26C = v | 0x40;
        D_8009B0A3[0] = 0xA;
        func_8003C0C0();
        func_8016866C(D_8009B363[0]);
        func_800157DC();

        return;
    }

    func_80168FCC();
    if (D_8009B26C & 0x40) {
        return;
    }

    func_800134B4();
    D_8009B0A3[0] = 6;
    func_80012D4C();
}
