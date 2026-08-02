#include "common.h"

void func_8001D240(u8 *arg0) {
    u8 n;

    if (func_80042B98(arg0) == 0) {
        *(u16 *)(arg0 + 8) |= 4;
        if (arg0[0x22] == 0) {
            *(s16 *)(arg0 + 0x28) = -8;
            *(s16 *)(arg0 + 0x2A) = 0xC0;
        } else {
            *(s16 *)(arg0 + 0x28) = 8;
            *(s16 *)(arg0 + 0x2A) = 0;
        }
    }
    n = arg0[0x22] + arg0[0x28];
    arg0[0x22] = n;
    if (n < 0xC0) {
        u8 *e = &D_801A7AD8[arg0[0x6A] * 28];

        *(u16 *)(e + 0x16) |= 0x800;
        n = arg0[0x2A];
        arg0[0x22] = n;
        if (n == 0) {
            *(u16 *)(e + 0x16) &= 0xF7FF;
            if (arg0[0x21] == 0) {
                *(u16 *)(arg0 + 8) &= 0xFFFB;
            }
        }
        arg0[0x6C] = 0;
        *(s32 *)(arg0 + 0x24) = 0;
    }
}
