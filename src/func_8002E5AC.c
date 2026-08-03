#include "common.h"

void func_8002E5AC(void) {
    u8 *q;
    u8 *o;
    s32 n;
    s32 a;
    s32 b;

    if (func_8002E3B4() == 0) {
        q = D_8009B290;
        D_8009B290 = q + 2;
        n = q[0] | (q[1] << 8);
        D_8009B2A4 = D_8009B2A4 | 0x4000;
        func_8003B6AC(0, 2);

        o = func_80035BE4(0, n & 0xFFF, 0x10, 0xB0, 0x120, 0x30);
        func_8002E370(o);
        *(u16 *)(o + 0x34) = *(u16 *)(o + 0x34) | 8;
        if (n & 0x8000) {
            a = D_8009B27C;
            b = *(u16 *)(o + 0x34);
            D_8009B27C = a | 0x4000;
            *(u16 *)(o + 0x34) = b & 0xFFF7;
        }
        D_8009B28C = D_8009B27C;
        return;
    }

    if (D_8009B2A4 & 0x4000) {
        return;
    }
    if ((D_8009B27C & 0x4000) == 0) {
        func_80035B7C((u8 *)D_800EB0F8);
    }
    D_8009B28C = 0;
    D_8009B27C = 0;
}
