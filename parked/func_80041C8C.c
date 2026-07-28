#include "common.h"

void func_80041C8C(u8 *arg0) {
    u8 *p;
    s32 op;
    s32 val;

    p = *(u8 **)(arg0 + 0x50) + *(u16 *)(arg0 + 0x58);
    op = *p++;
    while (op >= 0xF0) {
        if (D_80090FEC[op ^ 0xFF](arg0) == -1) {
            return;
        }
        p = *(u8 **)(arg0 + 0x50) + *(u16 *)(arg0 + 0x58);
        op = *p++;
    }
    *(s16 *)(arg0 + 0x5A) = op;
    *(s32 *)(arg0 + 0x4C) =
        *(s32 *)(arg0 + 0x54) + ((p[1] << 8) | p[0]);
    *(u16 *)(arg0 + 0x58) += 3;
}
