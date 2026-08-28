#include "common.h"

void func_8004803C(s16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 arg5,
                   u8 arg6) {
    u8 *b;
    s32 idx;
    s32 ch;
    s32 one;
    s32 v;
    s32 n;

    b = D_8009B45C;
    idx = *(u16 *)(*(s32 *)(b + 0x43C) + (arg0 & 0xFFFF) * 2);
    if ((idx & 0xFFFF) != 0xFFFF) {
        n = (idx & 0xFFFF) * 8;
        v = arg3 & 0xFF;
        *(s16 *)(b + 0x38C) =
            (*(u8 *)(*(s32 *)(b + 0x444) + n) * v >> 1) | 0xFF;
        *(s16 *)(b + 0x38E) =
            (*(u8 *)(*(s32 *)(b + 0x444) + n) * v >> 1) | 0xFF;

        if ((s16)arg4 != 0) {
            if ((u32)((arg4 - 1) & 0xFFFF) < 0x80) {
                v = *(s16 *)(b + 0x38C) * (0x80 - (s16)arg4);
                *(s16 *)(b + 0x38C) = v / 128;
            }
            if ((u32)((arg4 + 0x80) & 0xFFFF) < 0x80) {
                v = *(s16 *)(D_8009B45C + 0x38E) * ((s16)arg4 + 0x80);
                *(s16 *)(D_8009B45C + 0x38E) = v / 128;
            }
        }

        n = (idx & 0xFFFF) * 8;
        ch = arg1 & 0xFF;
        one = 1;
        *(s32 *)(D_8009B45C + 0x384) = one << (ch + 0x14);
        *(s16 *)(D_8009B45C + 0x39A) =
            *(u16 *)(*(s32 *)(D_8009B45C + 0x444) + n + 4) + arg2;
        *(s32 *)(D_8009B45C + 0x3A0) =
            *(u16 *)(*(s32 *)(D_8009B45C + 0x444) + n + 6) * 0x10;
        func_80076ED0(0, *(s32 *)(D_8009B45C + 0x384), D_8009B45C);

        D_8009B45C[0x434] = D_8009B45C[0x434] | (one << ch);
        (D_8009B45C + ch)[0x40C] = arg6;
        (D_8009B45C + ch)[0x410] = arg5;

        *(s16 *)(D_8009B45C + ch * 2 + 0x404) = arg0;
        *(u16 *)(D_8009B45C + ch * 2 + 0x414) = *(u16 *)(D_8009B45C + 0x38C);
        *(u16 *)(D_8009B45C + ch * 2 + 0x41C) = *(u16 *)(D_8009B45C + 0x38E);
        (D_8009B45C + ch)[0x424] = 0xFF;
        (D_8009B45C + ch)[0x428] = 0;
        *(s16 *)(D_8009B45C + ch * 2 + 0x42C) =
            *(u8 *)(*(s32 *)(D_8009B45C + 0x444) + n + 1) * 4;
        func_80077120(D_8009B45C + 0x384, 0);
    }
}
