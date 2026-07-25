/* Reaches D_8009B26C gp-relatively; see the note in include/variables.h. */
#define D_8009B26C_IS_SCALAR
#include "common.h"

void func_8002D3F8(void) {
    u8 v = D_8009B26C;

    if (!(v & 0x40)) {
        D_8009B26C = v | 0x40;
        func_8003B9BC();
        func_80015A00();
    }
    func_80168FB4();
    if (!(D_8009B26C & 0x40)) {
        func_8003FF34();
    }
}
