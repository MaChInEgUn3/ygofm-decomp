#include "common.h"

void func_8002C9B4(u8 *out, s32 sel) {
    u8 *e;
    u8 *f;
    s32 i;

    if (sel < 0) {
        e = D_801A7B64;
        f = e + 0x1A4;
        for (i = 0; i < 0xA; i++, e += 0x1C, f += 0x1C) {
            if ((*(u16 *)(e + 0x16) & 0x8000) != 0) {
                *(s32 *)out = *(s32 *)e;
                out += 4;
            }
            if ((*(u16 *)(f + 0x16) & 0x8000) != 0) {
                *(s32 *)out = *(s32 *)f;
                out += 4;
            }
        }
        *(s32 *)out = 0;
        return;
    }

    if (D_8009B1D5 != 0) {
        i = 5;
    } else {
        i = 0x14;
    }
    e = D_801A7AD8 + i * 28;

    if (sel >= 0x15) {
        for (i = 0; i < 5; i++, e += 0x1C) {
            if ((*(u16 *)(e + 0x16) & 0x8000) != 0) {
                if ((func_800170C8(e) & 0xFFFF) >= sel) {
                    *(s32 *)out = *(s32 *)e;
                    out += 4;
                }
            }
        }
        *(s32 *)out = 0;
        return;
    }

    for (i = 0; i < 5; i++, e += 0x1C) {
        if ((*(u16 *)(e + 0x16) & 0x8000) != 0) {
            if (sel < 0 || *(u8 *)(*(s32 *)e + 0x68) == sel) {
                *(s32 *)out = *(s32 *)e;
                out += 4;
            }
        }
    }
    *(s32 *)out = 0;
}
