#include "common.h"

typedef struct {
    u16 h[3];
} Blk6;

void func_8003C568(s32 arg0) {
    u8 sp0[12];
    u8 *a;
    u8 *b;
    s32 k;

    *(Blk6 *)sp0 = *(Blk6 *)D_8009AF5C;
    *(s16 *)(sp0 + 8) = 0x68;
    k = D_8009B37D;
    a = D_8009B380;
    b = D_8009B388;
    *(s16 *)(sp0 + 0xA) = 0xC8;
    *(s16 *)(a + 0x32) = 0x48;
    *(u16 *)(a + 0x30) = *(u16 *)(sp0 + 8 + k * 2);
    *(s16 *)(b + 0x30) = 0x20;
    *(u16 *)(b + 0x32) = *(u16 *)(sp0 + arg0 * 2) + 8;
    if (arg0 == 0) {
        *(u16 *)(a + 8) &= 0xFFBF;
        *(u16 *)(b + 0x30) = *(u16 *)(a + 0x30) + 8;
        *(u16 *)(b + 0x32) = *(u16 *)(a + 0x32) + 8;
    } else {
        *(u16 *)(a + 8) |= 0x40;
    }
}
