#include "common.h"

void func_80048920(s32 arg0, s32 arg1) {
    s32 i;
    s32 n;
    s32 f;
    s32 x;
    s32 y;
    s32 id = arg0;
    s16 sp10;

    if (arg0 & 0x8000) {
        func_80044DC0(arg1 & 0xFF);
        return;
    }

    i = 0;
    if ((arg0 & 0xF000) == 0x4000) {
        x = (arg0 & 0x1F) * 2;
        f = arg0 & 0x100;
        f = f != 0;
        n = *(u16 *)(D_8009B45C + (x + (f << 6)) + 0x44C);
        if (n == 0xFFFF) {
            return;
        }
        id = *(u16 *)(*(u8 **)(D_8009B45C + 0x43C) + n * 2);
        y = id;
        if (y == 0xFFFF) {
            return;
        }
    }

    id &= 0xFFFF;
    do {
        func_80077C50(i + 0x14, &sp10);
        if (*(u16 *)(D_8009B45C + i * 2 + 0x404) == id && sp10 != 0) {
            D_8009B45C[i + 0x424] = arg1;
            func_80047864(i);
        }
        i++;
    } while (i < 4);
}
