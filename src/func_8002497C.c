#include "common.h"

s32 func_8002497C(s32 arg0) {
    u8 *n = Base2_8009B364;

    if (D_8009B364[0] == 0 || arg0 >= 0x14) {
        return 0;
    }

    return D_800909D4[arg0][n[0] - 1] * 10;
}
