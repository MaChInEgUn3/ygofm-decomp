#include "common.h"

s32 func_8002C570(s32 arg0) {
    if (D_801D0000[arg0 + 0x24F] != 0) {
        return 1;
    }
    return -1;
}
