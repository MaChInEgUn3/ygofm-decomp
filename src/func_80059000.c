#include "common.h"

typedef struct {
    u8 b[8];
} Rec8;

void func_80059000(s32 arg0, u8 *arg1) {
    u8 *p = &D_800F2C40[arg0 * 3616];
    u8 *q = p + 0xCF8;
    s32 t;

    *(Rec8 *)arg1 = *(Rec8 *)(p + 0xDC8);
    t = q[7];
    if (t != 0) {
        *(u16 *)(arg1 + 0) = t << 4;
    }
    t = q[8];
    if (t != 0) {
        *(u16 *)(arg1 + 2) = t << 4;
    }
    t = q[9];
    if (t != 0) {
        *(u16 *)(arg1 + 4) = t << 4;
    }
    *(s16 *)(arg1 + 6) = 0;
    if (*(s16 *)(arg1 + 0) > 0) {
        *(u16 *)(arg1 + 6) = *(u16 *)(arg1 + 0);
    }
    if (*(s16 *)(arg1 + 6) < *(s16 *)(arg1 + 2)) {
        *(u16 *)(arg1 + 6) = *(u16 *)(arg1 + 2);
    }
    if (*(s16 *)(arg1 + 6) < *(s16 *)(arg1 + 4)) {
        *(u16 *)(arg1 + 6) = *(u16 *)(arg1 + 4);
    }
}
