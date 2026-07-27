#include "common.h"

void func_8005922C(u8 *arg0, s32 arg1) {
    u8 *p = arg0 + 4;

    func_80089060(arg0 + 0x44, p);

    if (arg1 != 0) {
        func_80087670(p, arg1);
    }

    *(s32 *)arg0 = 0;
}
