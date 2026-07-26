#include "common.h"

void func_80046FA0(s16 arg0) {
    u8 *p = D_8009B45C;

    if (p[0x48] != arg0) {
        p[0x48] = arg0;

        if (arg0 == 0) {
            func_800495DC();
        } else {
            func_800495EC();
        }

        func_80044DC0(*(s16 *)(D_8009B45C + 0x510));
    }
}
