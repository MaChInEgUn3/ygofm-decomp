#include "common.h"

void func_80048658(s32 arg0, s32 arg1, s32 arg2) {
    s32 n;
    s32 f;
    s32 v;
    u8 *e;

    if (arg0 & 0x8000) {
        func_800451E0(arg0 & 0xFFFF, 0);
        return;
    }

    if ((arg0 & 0xF000) == 0x4000) {
        f = arg0 & 0x100;
        f = f != 0;
        n = *(u16 *)(D_8009B45C + ((arg0 & 0x1F) * 2 + (f << 6)) + 0x44C);
        if (n == 0xFFFF) {
            return;
        }
        v = *(u16 *)(*(u8 **)(D_8009B45C + 0x43C) + n * 2);
        if (v == 0xFFFF) {
            return;
        }
        e = *(u8 **)(D_8009B45C + 0x444) + v * 8;
    } else {
        v = *(u16 *)(*(u8 **)(D_8009B45C + 0x43C) + (arg0 & 0xFFFF) * 2);
        if (v == 0xFFFF) {
            return;
        }
        e = *(u8 **)(D_8009B45C + 0x444) + v * 8;
    }

    func_800482B0(arg0 & 0xFFFF, 0, arg1 & 0xFF, (s16)arg2, e[3], e[2] & 0xFF);
}
