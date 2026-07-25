#include "common.h"

void func_80031E04(u8 *arg0, s32 arg1) {
    s32 i = 0;

    if (arg1 > 0) {
        do {
            func_80031CD4(arg0, i);
            i++;
        } while (i < arg1);
    }
}
