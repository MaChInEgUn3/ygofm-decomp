/* 18 differing instructions. Retail computes base+offset twice with opposite
 * operand orders -- "addu $a0,$v1,$v0" for the first read and
 * "addu $v0,$v0,$v1" for the second -- so the two array accesses want
 * different source spellings in the same function, and I could not find the
 * pair. Six combinations of the named-array and byte-offset levers tried.
 */
#include "common.h"

s32 func_8005A618(s32 arg0) {
    s32 o = arg0 * 3616;
    u8 *r = D_800F3938 + o;
    u8 *p;
    s32 t;

    p = func_8005F1A4(r[r[0x106] + 0xA] & 0x1F);

    if (arg0 > 0) {
        t = *(s16 *)(p + 2) + 0x1400;
    } else {
        t = *(s16 *)(p + 2) + 0x1C00;
    }

    return t % 4096;
}
