#include "common.h"

void func_8002CB50(s32 *arg0) {
    s32 i = 0;
    s32 *p = (s32 *)D_800E9EF0;

    do {
        *arg0++ = *p++;
        i++;
    } while (i < 5);

    *arg0 = 0;
}
