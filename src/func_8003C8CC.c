#include "common.h"

s32 func_8003C8CC(void) {
    switch (D_8009B37C & 0xF) {
    case 0:
        func_80015B00();
        break;
    case 1:
        func_8003C7A0();
        break;
    case 2:
        break;
    case 3:
        D_8009B37C = 1;
        break;
    }

    return D_8009B37C;
}
