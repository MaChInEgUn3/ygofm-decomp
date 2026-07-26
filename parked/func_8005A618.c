/* Retail keeps the record pointer in $v0 -- a caller-saved register -- across
 * the call to func_8005F1A4, and reads 2($v0) after it returns. No C produces
 * that: gcc must assume a call clobbers $v0, so it allocates $s1 and the frame
 * grows by 8. Either retail relies on that callee not touching $v0, or this
 * compiler had a way of knowing it. Worth a separate look at whether any other
 * function does the same -- if several do, it is a compiler behaviour and not
 * a one-off.
 */
#include "common.h"

s32 func_8005A618(s32 arg0) {
    s32 o = arg0 * 3616;
    u8 *p = D_800F3938 + o + D_800F3938[o + 0x106];
    s32 t;

    func_8005F1A4(p[0xA] & 0x1F);

    if (arg0 > 0) {
        t = *(s16 *)(p + 2) + 0x1400;
    } else {
        t = *(s16 *)(p + 2) + 0x1C00;
    }

    return t % 4096;
}
