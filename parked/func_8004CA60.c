/* Reproduce with:  echo '{"func_8004CA60": {"as": "-G0"}}' > config/flag_overrides.json
 * Both the -G0 assembler and the outer do{}while(0) are load-bearing.
 * See the PARKED.txt entry. */
#include "common.h"

void func_8004CA60(void) {
    u8 *p;
    s32 i;
    s32 off;
    s32 one;

    do {
        p = D_8009B458;
        if (*(u16 *)(p + 0x7FA) != 0) {
            i = 0;
            one = 1;
            off = 0;
            do {
                p[off + 0x53C] = one;
                p = D_8009B458;
                i++;
                *(s32 *)((p + off) + 0x518) = 0;
                off += 0x2C;
            } while (i < *(u16 *)(p + 0x7FA));
        }
    } while (0);
}
