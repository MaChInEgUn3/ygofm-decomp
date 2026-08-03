#include "common.h"

s32 func_800497E0(u8 *dst, u32 n, s32 key) {
    u8 *p;
    u8 *r;
    s32 h;
    u32 len;
    u32 avail;
    u32 pos;
    s32 ret;

    p = D_8009B458;
    h = *(s16 *)(p + 0x4A4);
    len = n;
    if (h != (s16)key) {
        return -1;
    }
    r = p + 0x4A4;
    func_800771B0(*(s32 *)(r + 0x14) + *(s32 *)(p + 0x818));
    avail = *(s32 *)(r + 0x10) - *(s32 *)(D_8009B458 + 0x818);
    if (avail < len) {
        len = avail;
    }
    if (func_80077150(dst, len) != len) {
        return -1;
    }
    p = D_8009B458;
    pos = *(s32 *)(p + 0x818) + len;
    *(s32 *)(p + 0x818) = pos;
    ret = h;
    if (pos < *(u32 *)(r + 0x10)) {
        ret = -2;
    }
    return ret;
}
