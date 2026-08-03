#include "common.h"

void func_80047CC4(s32 arg0) {
    s32 key;
    s32 i;
    s32 bit;
    s32 hi;
    s32 n;

    key = func_80047C50(arg0 & 0xFFFF);
    i = D_8009B45C[0x435];
    n = 0;
    bit = 1 << (u8)i;
    hi = 1 << ((u8)i + 0x14);

    do {
        /* `- -x` and not `+ x`: retail has `addu $v0,$v1,$v0` with the
         * loaded base first, and every `+` spelling gives index-first
         * because the base here is a pointer *value*, not a symbol. The
         * negation is what fixes the operand order; found by the permuter,
         * see docs/PARKED.txt's former entry for this function. */
        if ((D_8009B45C[0x434] & bit) != 0 &&
            *(u16 *)(D_8009B45C + 0x404 - -((u8)i * 2)) == (u16)key) {
            /* No prototype: src/func_80047C70.c declares its parameter
             * `u8 *`, and what retail leaves in $a0 here is this bitmask.
             * Adding a declaration to functions.h breaks this file. */
            func_80047C70(hi);
            D_8009B45C[0x435] = i;
            D_8009B45C[0x434] &= ~bit;
            return;
        }
        bit <<= 1;
        hi <<= 1;
        if (bit & 0x10) {
            bit = 1;
        }
        i++;
        n++;
        i &= 3;
    } while (n < 4);
}
