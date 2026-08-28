#include "common.h"

void func_8004803C(s16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 arg5,
                   u8 arg6) {
    u8 *b;
    s16 idx;
    s32 one;
    s32 v;
    s32 n;

    b = D_8009B45C;
    idx = *(u16 *)((arg0 & 0xFFFF) * 2 + *(s32 *)(b + 0x43C));
    if ((idx & 0xFFFF) != 0xFFFF) {
        n = (idx & 0xFFFF) * 8;
        v = arg3 & 0xFF;
        *(s16 *)(b + 0x38C) =
            (*(u8 *)(n + *(s32 *)(b + 0x444)) * v >> 1) | 0xFF;
        *(s16 *)(b + 0x38E) =
            (*(u8 *)(n + *(s32 *)(b + 0x444)) * v >> 1) | 0xFF;

        if ((s16)arg4 != 0) {
            if ((u32)((arg4 - 1) & 0xFFFF) < 0x80) {
                *(s16 *)(b + 0x38C) =
                    *(s16 *)(b + 0x38C) * (0x80 - (s16)arg4) / 128;
            }
            if ((u32)((arg4 + 0x80) & 0xFFFF) < 0x80) {
                *(s16 *)(D_8009B45C + 0x38E) =
                    *(s16 *)(D_8009B45C + 0x38E) * ((s16)arg4 + 0x80) / 128;
            }
        }

        n = (idx & 0xFFFF) * 8;
        arg1 = arg1 & 0xFF;
        b = D_8009B45C;
        one = 1;
        *(s32 *)(b + 0x384) = one << (arg1 + 0x14);
        *(s16 *)(b + 0x39A) = *(u16 *)(n + *(s32 *)(b + 0x444) + 4) + arg2;
        *(s32 *)(b + 0x3A0) = *(u16 *)(n + *(s32 *)(b + 0x444) + 6) * 0x10;
        func_80076ED0(0, *(s32 *)(b + 0x384), b);

        one = one << arg1;
        D_8009B45C[0x434] = D_8009B45C[0x434] | one;
        (D_8009B45C + arg1)[0x40C] = arg6;
        (D_8009B45C + arg1)[0x410] = arg5;

        b = D_8009B45C;
        *(s16 *)(b + arg1 * 2 + 0x404) = arg0;
        *(u16 *)(b + arg1 * 2 + 0x414) = *(u16 *)(b + 0x38C);
        *(u16 *)(b + arg1 * 2 + 0x41C) = *(u16 *)(b + 0x38E);
        (b + arg1)[0x424] = 0xFF;
        (D_8009B45C + arg1)[0x428] = 0;

        b = D_8009B45C;
        *(s16 *)(b + arg1 * 2 + 0x42C) =
            *(u8 *)(n + *(s32 *)(b + 0x444) + 1) * 4;
        func_80077120(b + 0x384, 0);
    }
}
