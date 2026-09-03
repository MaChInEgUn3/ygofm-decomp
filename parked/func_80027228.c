#include "common.h"

/* Sibling of func_80026DC8 (0.886): the same two nested scans over two
   6-pointer lists into D_800EAE88, keyed on checkFusion instead of
   checkEquip and entered through func_80026C6C. Both hit blocks are
   out-of-line labels in address order -- hit1, hit2, then the tail they
   share (which ends in a rand() call), then the second scan -- so they are
   written as goto targets in that order, as func_8003C328's arms are. */

s32 func_80027228(void) {
    u8 *a[6];
    u8 *b[6];
    u8 **q;
    u8 **r;
    u8 *e;
    u8 *f;
    u8 *d;
    s32 n;
    s32 i;
    s32 m;
    s32 u;
    s32 w;

    n = func_80026C6C(b, 0, 0x14);
    if (n == 0) {
        return 1;
    }
    n--;
    if (n != 0) {
        func_800358FC(n + 1);
    }
    if ((func_8008E590() & 1) == 0) {
        return 1;
    }
    func_80026D18(a, 5, -1);
    e = b[0];
    if (e != (u8 *)0) {
        r = b;
        do {
            f = a[0];
            if (f != (u8 *)0) {
                q = a;
                do {
                    if (func_80019A60(*(s16 *)(e + 0xC),
                                      *(s16 *)(f + 0xC)) != 0) {
                        goto hit1;
                    }
                    q++;
                    f = *q;
                } while (f != (u8 *)0);
            }
            r++;
            e = *r;
        } while (e != (u8 *)0);
    }

    m = func_80026C0C(5);
    if (m >= 0) {
        goto scan2;
    }
    return 1;

hit1:
    u = (s8)e[0x18];
    d = D_800EAE88;
    d[1] = 0;
    D_800EAE88[0] = u % 5 + 0xB;
    d[6] = (s8)f[0x18] % 5 + 1;
    goto tail;

hit2:
    D_800EAE88[0] = (s8)e[0x18] % 5 + 0xB;
    w = (s8)f[0x18];
    d = D_800EAE88;
    d[2] = 0;
    d[6] = m % 5 + 1;
    d[1] = w % 5 + 0xB;

tail:
    d[7] = func_8008E590() & 1;
    d[8] = 0;
    return 0;

scan2:
    func_80026C6C(a, 0, 0x14);
    e = b[0];
    i = 0;
    if (e != (u8 *)0) {
        do {
            f = a[0];
            if (f != (u8 *)0) {
                q = a;
                do {
                    if (*(s8 *)(e + 0x18) != *(s8 *)(f + 0x18) &&
                        func_80019A60(*(s16 *)(e + 0xC),
                                      *(s16 *)(f + 0xC)) != 0) {
                        goto hit2;
                    }
                    q++;
                    f = *q;
                } while (f != (u8 *)0);
            }
            i++;
            e = b[i];
        } while (e != (u8 *)0);
    }
    return 1;
}
