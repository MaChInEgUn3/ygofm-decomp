#include "common.h"

void func_8005B620(s32 *dst, s32 *src, s32 n) {
    s32 i;

    for (i = n - 1; i != -1; i--) {
        *dst++ = *src++;
    }
}
