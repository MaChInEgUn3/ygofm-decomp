#define D_8009B36A_IN_DATA
#define D_8009B368_IN_DATA
#include "common.h"

void func_80030F40(void) {
    D_8009B36A = 0x71D0;
    D_8009B368 = 0;
    func_80024DC8(-1, 1, 0x8000, 0x8000);
}
