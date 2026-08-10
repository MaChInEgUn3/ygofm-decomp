#include "common.h"

/* Builds an 8-byte bitmap from a negative-terminated vararg list of bit
 * indices, then forwards to func_80058938 (same tail as func_80059AF8).
 * The clear loop is a real down-walking cursor -- buf[i] does not strength-
 * reduce -- with i assigned before q so i lands in $a0. The vararg walk is
 * PsyQ stdarg.h's expansion written out: advance first, read at ap - 4. */
void func_80058838(s32 arg0, s32 arg1, Word4 arg2, Word4 arg3, s32 arg4, ...) {
    u8 buf[8];
    u8 *ap;
    s32 v;
    s32 idx;
    s32 i;
    u8 *q;

    i = 7;
    q = buf + 7;
    for (; i >= 0; i--) {
        *q-- = 0;
    }

    ap = (u8 *)&arg4 + 4;
    while (1) {
        ap += 4;
        v = *(s32 *)(ap - 4);
        if (v < 0) {
            break;
        }
        idx = v >> 3;
        buf[idx] |= 1 << (v - idx * 8);
    }

    arg2.unk3 = arg1 & 0x7F;
    func_80058938(arg0, arg1 & 0x80, arg2, arg3, arg4, (s32)buf);
}
