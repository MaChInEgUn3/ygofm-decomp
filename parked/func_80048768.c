#include "common.h"

void func_80048768(u16 sel, s16 amt) {
    s16 sp10;
    u8 *b;
    u8 *e;
    s32 i;
    s32 id;
    s32 v;
    s32 k;

    if ((sel & 0x8000) != 0) {
        func_80044E90(amt);
        return;
    }

    i = 0;

    if ((sel & 0xF000) == 0x4000) {
        k = (sel & 0x100) != 0;
        v = *(u16 *)(D_8009B45C + (sel & 0x1F) * 2 + k * 64 + 0x44C);
        if (v == 0xFFFF) {
            return;
        }
        sel = *(u16 *)(*(s32 *)(D_8009B45C + 0x43C) + v * 2);
        if (sel == 0xFFFF) {
            return;
        }
    }

    do {
        func_80077C50(i + 0x14, &sp10);
        b = D_8009B45C;
        e = b + i * 2;
        id = *(u16 *)(e + 0x404);
        if (id == (u16)sel && sp10 != 0) {
            if (amt != 0) {
                if ((u16)(amt - 1) < 0x80) {
                    *(s16 *)(e + 0x414) = *(u8 *)(*(s32 *)(b + 0x444) + id * 8) * (0x80 - amt);
                }
                if ((u16)(amt + 0x80) < 0x80) {
                    *(s16 *)(D_8009B45C + i * 2 + 0x41C) =
                        *(u8 *)(*(s32 *)(D_8009B45C + 0x444) + id * 8) * (amt + 0x80);
                }
            }
            func_80047864(i, id, i * 2);
        }
        i++;
    } while (i < 4);
}
