/* Reproduce with:  echo '{"func_8004CA60": {"as": "-G0"}}' > config/flag_overrides.json
 * The -G0 assembler is load-bearing, not cosmetic -- see the PARKED.txt entry. */
#include "common.h"

void func_8004CA60(void) {
    u8 *p;
    s32 i;
    s32 off;
    s32 one;

    p = D_8009B458;
    if (*(u16 *)(p + 0x7FA) != 0) {
        i = 0;
        one = 1;
        off = 0;
        do {
            p[off + 0x53C] = one;
            p = D_8009B458;
            i++;
            *(s32 *)(p + off + 0x518) = 0;
            off += 0x2C;
        } while (i < *(u16 *)(p + 0x7FA));
    }
}
