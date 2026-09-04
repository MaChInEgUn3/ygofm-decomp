#include "common.h"

void func_80072A48(void) {
    s32 *t;
    u8 *b;
    u8 *b1;
    u8 *r;
    u8 *e;
    s32 a;
    s32 opp;
    s32 k;
    s32 i;
    s32 off;
    s32 id;
    s32 n;
    s32 v;

    t = D_800F5B98;
    a = t[func_8007058C()];
    i = 0;
    opp = t[func_8007058C()];
    k = func_8007058C();
    v = func_80070710();
    b1 = (u8 *)D_800F5BE8;
    b1[0x9C] = v;
    *(u16 *)(b1 + 0xA0) = 0;
    b1[0xA2] = 0;
    b1[0x9D] = a + 1;
    b1[0x9E] = opp;
    if ((v & 0xFF) != 0) {
        do {
            (b1 + i)[0xAA] = 0;
            i++;
        } while (i < b1[0x9C]);
    }
    i = 0;
    r = (u8 *)D_801AB000;
    b = (u8 *)D_800F5BE8;
    off = 0xC;
    do {
        e = r + off;
        id = *(s16 *)e;
        n = i + 1;
        if (id != 0 && func_80070920(opp, n) == 0) {
            (b + b[0xA2])[0xA4] = n;
            if (*(u16 *)(b + 0xA0) < *(s16 *)(e + 2)) {
                *(u16 *)(b + 0xA0) = *(u16 *)(e + 2);
                b[0x38] = n;
                b[0x39] = 0;
                b[0xA3] = b[0xA2];
            }
            if (*(u16 *)(b + 0xA0) < *(s16 *)(e + 4)) {
                *(u16 *)(b + 0xA0) = *(u16 *)(e + 4);
                b[0x38] = n;
                b[0x39] = 0;
                b[0xA3] = b[0xA2];
            }
            if (b[0x9D] >= 2) {
                (b + i)[0xAA] = 1;
                b[0xA2] = b[0xA2] + 1;
                func_800727C0(id);
                (b + i)[0xAA] = 0;
                b[0xA2] = b[0xA2] - 1;
            }
        }
        i++;
        off += 0xC;
    } while (i < 5);
    i = 0;
    b = (u8 *)D_800F5BE8;
    if (b[0x9C] != 0) {
        r = (u8 *)D_801AB000;
        off = 0x84;
        do {
            e = r + off;
            id = *(s16 *)e;
            n = i + 0xB;
            if (id != 0 && func_80070920(opp, n) == 0) {
                (b + b[0xA2])[0xA4] = n;
                if (*(u16 *)(b + 0xA0) < *(s16 *)(e + 2)) {
                /* PLACEHOLDER: the permuter's shape, 95 -> 81, and semantically a
                   no-op because both arms are identical. do { } while (0)
                   round the same block is worth nothing (95), so the lever is
                   the duplication, not the loop node. The plausible spelling
                   is open -- see docs/PARKED.txt. */
                if (i) {
                        *(u16 *)(b + 0xA0) = *(u16 *)(e + 2);
                        b[0x38] = n;
                        b[0x39] = 0;
                        b[0xA3] = b[0xA2];
                } else {
                        *(u16 *)(b + 0xA0) = *(u16 *)(e + 2);
                        b[0x38] = n;
                        b[0x39] = 0;
                        b[0xA3] = b[0xA2];
                }
                }
                if (*(u16 *)(b + 0xA0) < *(s16 *)(e + 4)) {
                    *(u16 *)(b + 0xA0) = *(u16 *)(e + 4);
                    b[0x38] = n;
                    b[0x39] = 0;
                    b[0xA3] = b[0xA2];
                }
                if (b[0x9D] >= 3) {
                    (b + i)[0xAA] = 1;
                    b[0xA2] = b[0xA2] + 1;
                    func_800727C0(id);
                    (b + i)[0xAA] = 0;
                    b[0xA2] = b[0xA2] - 1;
                }
            }
            i++;
            off += 0xC;
        } while (i < b[0x9C]);
    }
    b = (u8 *)D_800F5BE8;
    if (b[0x38] != 0) {
        if (b[0x38] >= 6) {
            D_800F5B98[k] = 0;
            return;
        }
        if (b[0x39] != 0) {
            D_800F5B98[k] = 1;
            return;
        }
        D_800F5B98[k] = 2;
        return;
    }
    D_800F5B98[k] = 3;
}
