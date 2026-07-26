#include "common.h"

void func_800733A8(void) {
    s32 *p = D_800F5B98;
    s32 v = p[func_8007058C()] + 1;
    s32 i;

    for (i = 0; i < 0x19; i++) {
        u8 *q = (u8 *)D_800F5BE8;
        u8 c = q[i + 0x7E];

        if (c == v) {
            return;
        }
        if (c == 0) {
            q[i + 0x7E] = v;

            return;
        }
    }
}
