#include "common.h"

s32 func_8005C5D4(void)
{
    s32 timeout = 0x800000;
    if (D_8009B062 == 0) {
        for (;;) {
            if (--timeout <= 0) {
                func_8008FBE0(1);
                break;
            }
            if (D_8009B062 != 0) {
                break;
            }
        }
    }
    D_8009B062 = 0;
    return 0;
}
