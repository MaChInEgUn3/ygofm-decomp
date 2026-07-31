#define D_8009B45C_IS_AGGREGATE
#include "common.h"

typedef struct {
    u8 b[8];
} Rec8;

void func_800476B4(u8 *arg0, u32 arg1) {
    s32 i;

    for (i = 0; i < *(s32 *)arg0; i++) {
        u16 v = *(u16 *)(arg0 + 8 + i * 2);

        if (v != 0xFFFF) {
            u8 *g = D_8009B45C[0];

            *(u16 *)(*(u8 **)(g + 0x43C) + v * 2) = *(u16 *)(g + 0x440);
            *(Rec8 *)(*(u8 **)(g + 0x444) + *(u16 *)(g + 0x440) * 8) =
                *(Rec8 *)(arg0 + 0x1A0 + i * 8);
            *(u16 *)(*(u8 **)(g + 0x444) + *(u16 *)(g + 0x440) * 8 + 6) +=
                arg1 >> 4;
            *(u16 *)(g + 0x440) += 1;
        }
    }
}
