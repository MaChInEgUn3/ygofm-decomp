#include "common.h"

s32 func_8003A198(u8 *b, s32 x, s32 y, s32 z) {
    u16 *p;

    p = (u16 *)(b + x * 2);
    if (*p) {
        p = (u16 *)(b + *p + y * 2);
        if (*p) {
            p = (u16 *)(b + *p + z * 2);
            if (*p) {
                return 1;
            }
        }
    }
    return 0;
}
