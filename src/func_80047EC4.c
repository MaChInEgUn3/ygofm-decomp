#define D_8009B45C_IS_AGGREGATE
#include "common.h"

void func_80047EC4(void) {
    s32 i = 0;

    do {
        u8 *p;
        s32 a;

        func_80076ED0(0, 0xF00000);
        func_800773C4(D_8009B45C[0] + 0x15D8);

        p = Base2_8009B45C[0];
        a = p[0x15EF];

        if (a + p[0x15ED] + p[0x15EE] + a == 0) {
            break;
        }

        i++;
    } while (i < 0x18);
}
