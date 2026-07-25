#include "common.h"

void func_8005A468(s32 arg0, s32 arg1) {
    u8 *rec = &D_800F2C40[arg0 * 3616];
    u8 **p;
    s32 i;

    p = (u8 **)(rec + 0x1E0);
    i = 0;
    if (rec[0xE1B] != 0) {
        do {
            (*p)[0xD] = arg1;
            p++;
            i++;
        } while (i < rec[0xE1B]);
    }
}
