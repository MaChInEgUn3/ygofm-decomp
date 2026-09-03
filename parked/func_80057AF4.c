#include "common.h"

void func_80057AF4(s32 idx, s32 sel, s32 flag) {
    u8 *p;
    u8 **q;
    u8 *b;
    u8 *e;
    s32 dst;
    s32 src;
    s32 i;
    s32 n;
    s32 c;
    s32 off;
    s32 old;

    p = D_800F2C40 + idx * 0xE20;
    dst = *(s32 *)(p + 0xDE0);
    src = *(s32 *)(p + 0xDDC);
    q = (u8 **)(p + 0x1E0);
    if (p[0xE1F] == 0) {
        return;
    }
    if (sel == -1) {
        goto m1;
    }
    if (sel == 0) {
        goto m0;
    }
    goto def;
m1:
    {
        i = 0;
        p[0xE10] = 0;
        if (p[0xE1B] != 0) {
            do {
                *(u16 *)(*q + 8) = 0xFFFF;
                q++;
                i++;
            } while (i < p[0xE1B]);
        }
        return;
    }
m0:
    {
        if (p[0xE0F] == 0) {
            return;
        }
        i = 0;
        if (p[0xE1B] != 0) {
            do {
                c = *(u16 *)(p + (i * 2 + p[0xE0F] * 0x74) + 0x2C8);
                b = *(u8 **)(p + 0xDD8);
                e = b + c * 4;
                if (c != 0xFFFF) {
                    n = 3;
                    if (((p + i / 8)[0xBEC] >> (i % 8)) & 1) {
                        n = 5;
                    }
                    func_8005B620(src + *(u16 *)e * 4, dst, n);
                    dst += n * 4;
                }
                i++;
            } while (i < p[0xE1B]);
        }
        p[0xE0F] = 0;
        return;
    }
def:
    old = p[0xE0F];
    if (sel != p[0xDFE] + 3) {
        p[0xE0E] = 2;
    }
    off = sel * 0x76;
    if (*(u16 *)(p + off + 0x7C4) == 0) {
        return;
    }
    if (old != 0) {
        if (flag == 0) {
            return;
        }
        p[0xBF6] = p[0xBF4];
        func_80057AF4(idx, 0, 0);
    }
    if (sel == p[0xDFE] + 3 || *(u16 *)(p + 0xDF8) == 0x309) {
        p[0xE0E] = 7;
    }
    p[0xE0F] = sel;
    if (old == sel) {
        func_800597C8(idx, 0, 0);
        return;
    }
    i = 0;
    p[0xE10] = 1;
    if (p[0xE1B] != 0) {
        do {
            c = *(u16 *)(p + (i * 2 + p[0xE0F] * 0x74) + 0x2C8);
            b = *(u8 **)(p + 0xDD8);
            e = b + c * 4;
            if (c != 0xFFFF) {
                n = 3;
                if (((p + i / 8)[0xBEC] >> (i % 8)) & 1) {
                    n = 5;
                }
                *(s16 *)(*q + 8) = (e - b) >> 2;
                func_8005B620(dst, src + *(u16 *)e * 4, n);
                dst += n * 4;
            }
            q++;
            i++;
        } while (i < p[0xE1B]);
    }
}
