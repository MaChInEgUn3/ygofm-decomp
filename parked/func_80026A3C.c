#include "common.h"
void func_80024954(void);

void func_80026A3C(void) {
    s32 i;

    if (func_80024E24() == 0) {
        u8 *p = (u8 *)func_8002C68C(0x17);
        u8 *tb = D_80090800;
        s32 k = D_8009B1D5 ^ 1;
        s32 v = *(u16 *)(&tb[k * 80] + 2);

        *(s16 *)(p + 4) = v;
        func_8008E870(D_8009AF40, (s16)v);
    } else {
        i = 0;
        {
        u8 *tbl = D_800907D8;
        u8 *rec = D_801A7AD8;

        for (; i < 5; i++) {
            u8 *e = &rec[tbl[i + D_8009B1D5 * 20] * 28];

            if (*(u16 *)(e + 0x16) & 0x8000) {
                func_80024954();
            }
        }
        }
        D_8009B220 = 0;
    }
}
