#include "common.h"

/* Two near-identical arms over arg0[2..0]. Three permuter-found names make
 * it match: the arm-1 sign-extend held in an s8 local assigned per
 * iteration (keeps the sll/sra pair inside the loop, where symmetric
 * inline (s8) lets gcc split the sll into the copy-in); the arm-1 mask/or
 * as two read-modify-writes (same one-store emission, different combine);
 * and the arm-2 store address named. Arm 2's preheader sll is gcc hoisting
 * into arg2's dead register, not a source statement. */

void func_8003A440(u8 **arg0, u32 arg1, s32 arg2) {
    u8 *e;
    s8 c;
    u32 *w;
    s32 i;

    if (arg1 == 0) {
        for (i = 2; i >= 0; i--) {
            c = (s8)arg2;
            e = arg0[i];
            if (e != 0) {
                *(u32 *)(e + 4) = *(u32 *)(e + 4) & 0x8FFFFFFF;
                *(u32 *)(e + 4) = *(u32 *)(e + 4) | 0x40000000;
                func_800428EC(e, c);
                *(u32 *)(e + 0xC) = 0x808080;
                *(u16 *)(e + 0x42) -= 1;
            }
        }
    } else {
        for (i = 2; i >= 0; i--) {
            e = arg0[i];
            if (e != 0) {
                w = (u32 *)(e + 4);
                *w = (*(u32 *)(e + 4) & 0x8FFFFFFF) | arg1;
                func_800428EC(e, (s8)arg2);
                if (arg1 == 0x60000000) {
                    *(u16 *)(e + 0x42) = 0xFD;
                } else {
                    *(u16 *)(e + 0x42) += 1;
                }
            }
        }
    }
}
