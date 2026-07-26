#include "common.h"

void func_80048C70(s32 *arg0, s32 *arg1) {
    u32 i = 0;

    do {
        *arg0++ = *arg1++;
        *arg0++ = *arg1++;
        *arg0++ = *arg1++;
        *arg0++ = *arg1++;
        *arg0++ = *arg1++;
        *arg0++ = *arg1++;
        *arg0++ = *arg1++;
        *arg0++ = *arg1++;
        i++;
    } while (i < 0x40);
}
