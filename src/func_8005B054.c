#include "common.h"

/* Packs the returned triple into 15-bit RGB. */
s32 func_8005B054(s32 arg0, s32 arg1, s32 arg2) {
    u8 buf[8];

    func_8005ABA0(buf, arg0, arg1 & 0xFFFF, arg2 & 0xFFFF, 0x1F);

    return (buf[0] & 0x1F) | ((buf[1] & 0x1F) << 5) | ((buf[2] & 0x1F) << 10);
}
