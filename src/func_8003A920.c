#include "common.h"

void func_8003A920(u8 *arg0, s16 arg1, s16 arg2) {
    s32 i = 2;
    u8 **q = (u8 **)(arg0 + 8);

    do {
        if (*q != 0) {
            *(s16 *)(*q + 0x30) = arg1;
            *(s16 *)(*q + 0x32) = arg2;
        }
        i--;
        q--;
    } while (i >= 0);
}
