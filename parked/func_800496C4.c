/* 16 differing instructions under -O1 -G0 -fno-delayed-branch
 * -mno-split-addresses (found by sweep_try.py, not confirmed by a build).
 *
 * Open question, and it is not a codegen one: retail reserves an eight-byte
 * frame -- `addiu $sp,$sp,-8` ... `addiu $sp,$sp,8` -- and never stores
 * anything in it. No saves, no locals, no calls; it is a leaf. gcc only emits
 * a frame when frame_size > 0, which means one four-byte local lived in memory,
 * which means its address was taken. Nothing in this function needs that.
 * Whatever that local was, it is why the function is two instructions longer
 * than the C wants to be, and guessing at the body will not find it. Retail
 * also materialises the zero it stores at +0x4A4 into $t0 rather than using
 * $zero, which is the same story: a variable that exists in the source and not
 * in mine.
 *
 * Return value: this was written as void, and func_80049308 stores the
 * result -- retail zeroes $v0 on the path modelled here and there are exits
 * above it that do not, so the reconstruction is missing at least one. The
 * difference count below predates knowing that.
 */
#include "common.h"

s32 func_800496C4(u8 *arg0, s16 arg1, s32 arg2) {
    u8 *b = D_8009B458;
    u8 *q;
    s32 v;

    *(s32 *)(b + 0x818) = 0;

    if (arg1 == -1) {
        if (*(s16 *)(b + 0x4A4) != arg1) {
            return;
        }
    }

    b = D_8009B458;
    *(s16 *)(b + 0x4A4) = 0;
    q = b + 0x4A4;
    *(u8 **)(q + 4) = arg0;
    v = (*(u16 *)(arg0 + 0x12) << 9) + 0xA20;
    *(s32 *)(q + 8) = v;
    *(s32 *)(q + 0x10) = *(s32 *)(arg0 + 0xC) - v;
    q[0x18] = arg0[0x18];
    *(s32 *)(q + 0x14) = arg2;
    q[0x1B] = arg0[0x19];

    return 0;
}
