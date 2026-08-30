
#include "common.h"

void func_80044E90(s16 arg0);
void func_80077C50(s32 arg0, s16 *arg1);
void func_80047864(s32 arg0, s32 arg1, s32 arg2);

void func_80048A28(s32 arg0, s32 arg1, s32 arg2) {
    s16 sp10;
    u8 *b;
    s32 i;
    s32 h;
    s32 ix;
    s32 t;
    s32 n;
    s32 f;
    u16 w2;

    if ((arg0 & 0x8000) != 0) {
        b = D_8009B45C;
        *(s16 *)(b + 0x510) = arg1 & 0xFF;
        func_80044E90((s16)arg2);
        return;
    }

    i = 0;
    if ((arg0 & 0xF000) == 0x4000) {
        b = D_8009B45C;
        f = arg0 & 0x100;
        f = f != 0;
        ix = (arg0 & 0x1F) * 2;
        n = *(u16 *)(b + (ix + (f << 6)) + 0x44C);
        if (n == 0xFFFF) {
            return;
        }
        arg0 = *(u16 *)(*(s32 *)(b + 0x43C) + n * 2);
        if (arg0 == 0xFFFF) {
            return;
        }
    }

    t = (s16)arg2;

    do {
        func_80077C50(i + 0x14, &sp10);
        b = D_8009B45C;
        h = *(u16 *)(b + i * 2 + 0x404);
        if (h == (arg0 & 0xFFFF) && sp10 != 0) {
            *(u8 *)(b + i + 0x424) = arg1;
            if (t != 0) {
                w2 = (u16)(arg2 + 0x80);
                if ((u16)(arg2 - 1) < 0x80) {
                    *(s16 *)(D_8009B45C + i * 2 + 0x414) =
                        *(u8 *)(*(s32 *)(D_8009B45C + 0x444) + h * 8) * (0x80 - t);
                }
                if (w2 < 0x80) {
                    b = D_8009B45C;
                    *(s16 *)(b + i * 2 + 0x41C) =
                        *(u8 *)(*(s32 *)(b + 0x444) + h * 8) * (t + 0x80);
                }
            }
            func_80047864(i, h, i * 2);
        }
        i++;
    } while (i < 4);
}
