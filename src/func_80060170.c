#include "common.h"

/* Inserts (arg0, arg1) into the first free slot of a table of 8-byte pairs. */
void func_80060170(s32 arg0, s32 arg1) {
    s32 *v = (s32 *)D_800F5918;
    s32 i = 0;
    s32 *k;

    k = v + 1;
    do {
        if (*k == arg0) {
            return;
        }
        if (*k == 0 && *v == 0) {
            *k = arg0;
            *v = arg1;

            return;
        }
        i++;
        k += 2;
        v += 2;
    } while (i < 0x50);
}
