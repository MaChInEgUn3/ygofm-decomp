#include "common.h"

s32 func_8003A198(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *p;
    s32 off;
    u16 v;

    off = arg1 * 2;
    v = *(u16 *)(arg0 + off);
    if (v == 0) {
        return 0;
    }
    p = arg0 + v;
    off = arg2 * 2;
    v = *(u16 *)(p + off);
    if (v == 0) {
        return 0;
    }
    p = arg0 + v;
    off = arg3 * 2;
    v = *(u16 *)(p + off);
    if (v != 0) {
        return 1;
    }
    return 0;
}
