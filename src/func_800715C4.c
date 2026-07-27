#include "common.h"

void func_800715C4(void) {
    s32 n = func_8007058C();
    s32 i = 0;
    u8 *b = (u8 *)D_800F5BE8;

    do {
        s32 v = b[i + 0x38];

        if (v >= 1 && v <= 0xA) {
            D_800F5B98[n] = v;

            return;
        }
        i++;
    } while (i < 5);

    D_800F5B98[n] = 0;
}
