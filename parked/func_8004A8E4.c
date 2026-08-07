#define D_8009B458_IS_AGGREGATE
#include "common.h"

s32 func_8004A8E4(s32 arg0) {
    u8 *e;
    s32 off;
    s32 v;

    off = arg0 * 40 + 0x180;
    e = D_8009B458[0] + off;
    v = e[3];
    if (v != 0x63) {
        off = v * 24;
        e = D_8009B458[0] + off;
        v = e[6];
        if ((v & 0xF) != 0) {
            e[6] = v - 1;
        }
    }
    return arg0;
}
