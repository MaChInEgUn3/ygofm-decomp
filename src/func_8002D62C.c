/* Reaches D_8009B26C gp-relatively; see the note in include/variables.h. */
#define D_8009B26C_IS_SCALAR
#define D_8009B269_IS_SCALAR
#include "common.h"

void func_8002D62C(void) {
    u8 v = D_8009B26C;

    if (!(v & 0x40)) {
        D_8009B26C = v | 0x40;
        func_8003BBF8();
        func_801683EC();
    }
    if (func_80169C08() != 0) {
        D_8009B26C = D_8009B269;
    }
}
