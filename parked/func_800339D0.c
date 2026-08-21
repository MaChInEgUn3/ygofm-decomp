#define D_8009B140_SIZED8
#define D_8009AF76_IS_AGGREGATE
#define D_8009B34D_IS_AGGREGATE
#include "common.h"

void func_800339D0(u8 *p) {
    u8 *q;
    u8 *e;
    u8 *r;
    u16 *w;
    u8 *d;
    s32 i;
    s32 f;

    if (func_80032B38(p) == 0) {
        func_8003FEE0(8);
        if (func_80033998() != 0) {
            f = D_8009B2F8;
            *(u16 *)(p + 0x633E) = *(u16 *)(p + 0x633E) | 0x4000;
            if ((f & 0x80) != 0) {
                func_80035C38(0, 8, 0x28, 0x78, 0xF0, 0x10, 0x1028)[0x59] = 0xA;
            } else {
                e = func_80035C38(0, 9, 0x30, 0x60, 0xE0, 0x30, 0x20);
                e[0x59] = 0xA;
                do {
                    func_80039794();
                } while (*(s32 *)(e + 0x30) == 0);
            }
            func_80015BD8(0xA0, 2);
            D_8009B140[0] = D_8009AF76[0] - 8;
        }
    }

    q = p + 0x5D98;

    if ((*(u16 *)(p + 0x633E) & 0x4000) != 0) {
        func_80039794(q);
        r = (u8 *)D_800EB0F8;
        if ((*(s32 *)(r + 0x34) & 0x2008) == 0x2000) {
            func_80035B7C(r);
            if ((D_8009B2F8 & 0x80) == 0 && D_8009B34D[0] != 0) {
                *(u16 *)(p + 0x633E) = *(u16 *)(p + 0x633E) & 0xBFFF;
            } else {
                *(u16 *)(p + 0x633E) = *(u16 *)(p + 0x6340);
                func_80015BD8(0xFF, 2);
            }
        }
    } else {
        i = 0;
        d = *(u8 **)p + 0x50;
        do {
            *d = *q;
            q++;
            i++;
            d++;
        } while (i < 0x2D2);

        w = *(u16 **)p;
        i = 0;
        d = p + 0x2D54;
        do {
            *w = 0;
            if (d[9] != 0) {
                *w = *(u16 *)d;
            }
            w++;
            i++;
            d += 0x10;
        } while (i < 0x28);

        func_80032370();
        *(u16 *)(p + 0x633E) = 0;
    }
}
