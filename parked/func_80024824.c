#include "common.h"

void func_80024824(void) {
    u8 *dst = D_8018C2D8;
    u8 *rec = D_801A7E20;
    u8 *base = D_8015C424;
    u8 *vram = D_8015C424 + 0x18000;
    s32 i;

    for (i = 0; i < 0x50; i++) {
        u8 *tbl = D_80178130;
        u8 *src = base;
        s32 v = *(u16 *)(vram + i * 2 + 0x3BC4);

        *(u16 *)rec = v;
        rec[2] = i;
        rec[3] = i;
        rec[4] = vram[i + 0x3B70];
        while (1) {
            if (*(u16 *)tbl == (s16)v) {
                break;
            }
            tbl += 2;
            src += 0x580;
        }
        func_800356A0(dst, src, 0x580);
        dst += 0x580;
        rec += 6;
    }
}
