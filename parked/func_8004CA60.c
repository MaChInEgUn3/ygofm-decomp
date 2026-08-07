#include "common.h"

void func_8004CA60(void) {
    s32 i;
    s32 off;

    if (*(u16 *)(D_8009B458 + 0x7FA) != 0) {
        i = 0;
        off = 0;
        do {
            D_8009B458[off + 0x53C] = 1;
            i++;
            *(s32 *)(D_8009B458 + off + 0x518) = 0;
            off += 0x2C;
        } while (i < *(u16 *)(D_8009B458 + 0x7FA));
    }
}
