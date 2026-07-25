#include "common.h"

/* Fills a 0x1E-byte span of the table, counting down.
 *
 * The deref form is load-bearing: `p[i + 0xA]` is the same thing to C but
 * gcc emits `addu counter,base` where the retail code has `addu base,counter`,
 * and the operand order is visible in the encoding. */
void func_800156B8(s32 arg0) {
    u8 *p = D_800E9EC8;
    s32 i;

    for (i = 0x1D; i >= 0; i--) {
        *(p + i + 0xA) = arg0;
    }
}
