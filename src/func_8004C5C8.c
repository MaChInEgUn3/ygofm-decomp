#include "common.h"

void func_8004C5C8(u8 *p) {
    switch (*(u16 *)(D_8009B458 + 0x7FC)) {
    case 0x30:
        *(s32 *)(p + 0x1C) = *(s32 *)(p + 0x1C) * 10;
        *(s32 *)(p + 0x1C) = *(s32 *)(p + 0x1C) + *(u16 *)(p + 0x18);
        *(s16 *)(p + 0x18) = *(u16 *)(p + 0x1C) & 3;
        *(s32 *)(p + 0x1C) = *(u32 *)(p + 0x1C) >> 2;
        return;
    case 0x60:
        *(s32 *)(p + 0x1C) = *(s32 *)(p + 0x1C) * 5;
        *(s32 *)(p + 0x1C) = *(s32 *)(p + 0x1C) + *(u16 *)(p + 0x18);
        *(s16 *)(p + 0x18) = *(u16 *)(p + 0x1C) & 3;
        *(s32 *)(p + 0x1C) = *(u32 *)(p + 0x1C) >> 2;
        return;
    case 0xC0:
    case 0xF0:
        *(s32 *)(p + 0x1C) = *(s32 *)(p + 0x1C) + *(u16 *)(p + 0x18);
        *(s16 *)(p + 0x18) = *(u16 *)(p + 0x1C) & 1;
        *(s32 *)(p + 0x1C) = *(u32 *)(p + 0x1C) >> 1;
        return;
    case 0x120:
    case 0x168:
        *(u32 *)(p + 0x1C) = *(u32 *)(p + 0x1C) / 3;
        return;
    case 0x180:
    case 0x1E0:
        *(s32 *)(p + 0x1C) = *(s32 *)(p + 0x1C) + *(u16 *)(p + 0x18);
        *(s16 *)(p + 0x18) = *(u16 *)(p + 0x1C) & 3;
        *(s32 *)(p + 0x1C) = *(u32 *)(p + 0x1C) >> 2;
        return;
    case 0x300:
    case 0x3C0:
        *(s32 *)(p + 0x1C) = *(s32 *)(p + 0x1C) + *(u16 *)(p + 0x18);
        *(s16 *)(p + 0x18) = *(u16 *)(p + 0x1C) & 7;
        *(s32 *)(p + 0x1C) = *(u32 *)(p + 0x1C) >> 3;
        return;
    default:
        return;
    }
}
