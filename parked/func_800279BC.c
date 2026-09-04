#include "common.h"

s32 func_800279BC(void) {
    u8 *a[6];
    u8 *b[6];
    u8 *c[6];
    u8 **pb;
    u8 **pc;
    u8 **pa;
    u8 *e;
    u8 *f;
    u8 *h;
    u8 *g;
    s32 i;
    s32 j;
    s32 n;
    s32 k;
    s32 r;
    s32 u;

    D_800EAE91[0] = 0;
    if ((D_8009B16C & 0x1000) == 0) {
        i = 0xA;
        if ((func_8008E590() & 3) == 0) {
            func_80026D18(c, 0xA, 0x17);
            func_80026D18(b, 5, -1);
            e = c[0];
            if (e != 0) {
                pc = c;
                do {
                    f = b[0];
                    if (f != 0) {
                        pb = b;
                        do {
                            if (func_80019A08(*(s16 *)(e + 0xC), *(s16 *)(f + 0xC)) != 0) {
                                goto hit;
                            }
                            pb++;
                            f = *pb;
                        } while (f != 0);
                    }
                    pc++;
                    e = *pc;
                } while (e != 0);
            }
            k = func_80026D18(c, 0xA, 0x14);
            if (k != 0) {
                k = k - 1;
                if (k != 0) {
                    k = func_800358FC(k + 1);
                }
                D_800EAE88[9] = *(s8 *)(c[k] + 0x18) % 5 + 6;
                D_800EAE88[0xA] = 0;
                D_800EAE88[0xB] = 0;
                return 0;
            }
            goto scan;
        hit:
            D_800EAE88[9] = *(s8 *)(e + 0x18) % 5 + 6;
            D_800EAE88[0xA] = *(s8 *)(f + 0x18) % 5 + 1;
            D_800EAE88[0xB] = 0;
            return 0;
        }
    scan:
        i = 0xA;
        do {
            g = D_801A7AD8 + D_800907D8[i + D_8009B1D5 * 0x14] * 0x1C;
            i++;
            if ((*(s32 *)(g + 0x14) & 0xC0000000) == 0x80000000) {
                r = func_800278A0((u8 **)g);
                if (r < 0) {
                    goto neg;
                }
            check:
                if (*(s8 *)(D_8009B1C8 + 0x19) != 0) {
                    goto plain;
                }
                u = *(s8 *)(g + 0x18);
                D_800EAE88[0xA] = r % 5 + 0x38;
                D_800EAE88[0xB] = 0;
                D_800EAE88[9] = u % 5 + 1;
                return 0;
            neg:
                if ((func_8008E590() & 3) != 0) {
                    goto more;
                }
                r = func_8002778C((u8 **)g);
                if (r >= 0) {
                    goto check;
                }
            plain:
                r = *(s8 *)(g + 0x18) % 15;
                D_800EAE88[0xA] = 0;
                D_800EAE88[0xB] = 1;
                r = (s8)r - 4;
                D_800EAE88[9] = r;
                return 0;
            more:
                if ((func_8008E590() & 1) == 0) {
                    goto plain;
                }
                n = 0;
                j = 0;
                pa = a;
                h = D_801A7AD8 + 0x8C + (D_8009B1D5 ^ 1) * 0x1A4;
                do {
                    if ((*(s32 *)(h + 0x14) & 0x90000000) == 0x90000000) {
                        *pa = h;
                        pa++;
                        n++;
                    }
                    j++;
                    h += 0x1C;
                } while (j < 5);
                if (n == 0) {
                    goto plain;
                }
                r = n - 1;
                if (r != 0) {
                    r = func_800358FC(n);
                }
                r = *(s8 *)(a[r] + 0x18);
                goto check;
            }
        } while (i < 0xF);
    }
    return 0;
}
