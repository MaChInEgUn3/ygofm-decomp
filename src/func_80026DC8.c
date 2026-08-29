#include "common.h"

s32 func_80026DC8(void) {
    u8 *a[6];
    u8 *b[6];
    u8 **q;
    u8 **r;
    u8 *e;
    u8 *f;
    s32 n;
    s32 u;
    s32 w;

    if (func_80026D18(b, 0, 0x17) != 0) {
        func_80026D18(a, 5, -1);
        e = b[0];
        if (e != (u8 *)0) {
            r = b;
            do {
                f = a[0];
                if (f != (u8 *)0) {
                    q = a;
                    do {
                        if (func_80019A08(*(s16 *)(e + 0xC),
                                          *(s16 *)(f + 0xC)) != 0) {
                            D_800EAE88[0] = *(s8 *)(e + 0x18) % 5 + 0xB;
                            D_800EAE88[1] = 0;
                            D_800EAE88[6] = *(s8 *)(f + 0x18) % 5 + 1;
                            D_800EAE88[7] = 0;
                            D_800EAE88[8] = 0;
                            return 0;
                        }
                        q++;
                        f = *q;
                    } while (f != (u8 *)0);
                }
                r++;
                e = *r;
            } while (e != (u8 *)0);
        }

        n = func_80026C0C(5);
        if (n < 0) {
            return 1;
        }
        func_80026C6C(a, 0, 0x14);
        e = b[0];
        if (e != (u8 *)0) {
            r = b;
            do {
                f = a[0];
                if (f != (u8 *)0) {
                    q = a;
                    do {
                        if (func_80019A08(*(s16 *)(e + 0xC),
                                          *(s16 *)(f + 0xC)) != 0) {
                            u = *(s8 *)(f + 0x18);
                            D_800EAE88[0] = u % 5 + 0xB;
                            w = *(s8 *)(e + 0x18);
                            D_800EAE88[2] = 0;
                            D_800EAE88[7] = 0;
                            D_800EAE88[8] = 0;
                            D_800EAE88[6] = n % 5 + 1;
                            D_800EAE88[1] = w % 5 + 0xB;
                            return 0;
                        }
                        q++;
                        f = *q;
                    } while (f != (u8 *)0);
                }
                r++;
                e = *r;
            } while (e != (u8 *)0);
        }
    }
    return 1;
}
