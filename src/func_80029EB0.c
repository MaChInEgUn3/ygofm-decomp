#include "common.h"

u8 func_80029EB0(u8 *arg0, s32 arg1) {
    arg0 += arg1 * 4;
    return arg0[0x56];
}
