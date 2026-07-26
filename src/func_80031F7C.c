#include "common.h"

void func_80031F7C(u8 *arg0, s32 arg1) {
    s32 n = (arg0 + arg1)[0x5D97];

    if (n != 0) {
        n--;
        if (n == 0) {
            u8 *p = arg0 + 4;

            while (1) {
                if (*(s16 *)(p + 4) == arg1) {
                    break;
                }
                p += 0x10;
            }

            p[0xD] = 0;
            if ((arg0 + arg1)[0x5D97] != 0) {
                p[0xD] = 0x80;
            }
            func_80032C48(arg0 + 4);
        }
        (arg0 + arg1)[0x5D97] = n;
        *(s32 *)(arg0 + 0x5A9C) -= 1;
    }
}
