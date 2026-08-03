#include "common.h"

void func_80047DB0(s32 arg0) {
    s32 mask;
    s32 bit;
    s32 flag;
    s32 i;
    s32 id;
    s32 f;

    if (arg0 & 0x8000) {
        func_800464F0();
        func_80045114();
        return;
    }

    flag = 1;
    if ((arg0 & 0xF000) == 0x4000) {
        f = arg0 & 0x100;
        f = f != 0;
        id = *(u16 *)(D_8009B45C + ((arg0 & 0x1F) * 2 + (f << 6)) + 0x44C);
        if (id == 0xFFFF) {
            return;
        }
    }

    mask = 0;
    bit = 0x100000;
    i = 0;
    id = id & 0xFFFF;

    do {
        if (*(u16 *)(D_8009B45C + i * 2 + 0x404) == id) {
            mask = mask | bit;
            D_8009B45C[0x434] = D_8009B45C[0x434] & ~flag;
            func_80047C70(bit);
        }
        flag = flag << 1;
        i++;
        bit = bit << 1;
    } while (i < 4);

    if (mask != 0) {
        func_80076ED0(0, mask);
    }
}
