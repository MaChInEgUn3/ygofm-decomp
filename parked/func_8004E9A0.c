#include "common.h"

void func_8004E9A0(void) {
    s32 k;
    s32 u_0;
    s32 u_1;
    s32 r;
    s32 n;

    if (D_800F569F[0] != 0) {
        k = D_8009AF88[0xA0];
        switch (k) {
        case 1:
            u_0 = func_80074170(-1) / 8;
            D_8009B46A = 0x1C0;
            D_8009B46C = 0x10;
            D_8009B46E = 0x40;
            r = u_0 % 3;
            D_8009B468 = r * 16 + 0x2D0;
            func_8007FA38(&D_8009B468, 0x2C0, 0x1C0, r);
            break;
        case 4:
            u_1 = func_80074170(-1) / 10;
            n = 8;
            r = u_1 % n;
            D_8009B468 = 0x260;
            D_8009B46C = 0x20;
            D_8009B46E = 0x18;
            D_8009B46A = D_80091508[r] * 3 * 8 + 0x180;
            func_8007FA38(&D_8009B468, 0x220, 0x168, r);
            break;
        }
    }
}
