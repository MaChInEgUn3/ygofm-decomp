/* PARKED at 235/235, 55 differences.  REQUIRES -fno-strength-reduce:
 * config/flag_overrides.json
 *   {"func_8001825C": {"cc": ["-quiet", "-O2", "-G8", "-fno-strength-reduce"]}}
 * Without it the two record loops each grow a second cursor at base+4 and the
 * function saves a fifth callee-saved register -- 194 differences against 234.
 * The flag is per FILE, so loop 3's givs have to be written out by hand. */
#define D_8009B0F4_IS_AGGREGATE
#define D_8009B134_IS_AGGREGATE
#include "common.h"

void func_80024D34(s32 arg0, s32 arg1);
s32 func_800181EC(u8 *arg0);

void func_8001825C(void) {
    u8 *r;
    u8 *q;
    u8 *u;
    u8 *e;
    u8 *e4;
    u8 *g;
    u8 *b;
    s32 i;
    s32 m;
    s32 k;
    s32 h;
    u16 f;
    s32 w;

    f = D_8009B23A;
    if ((f & 0x8000) != 0) {
        goto arm2;
    }
    D_8009B23A = f | 0x8000;
    r = D_801A7B64;
    i = 5;
    q = r + 0x12;
    for (; i < 0xF; i++, q += 0x1C, r += 0x1C) {
        w = *(u16 *)(q + 4);
        m = w & 0x7A00;
        if ((w & 0x8000) != 0) {
            h = *(s16 *)q;
            func_80024D34(i, *(s8 *)(*(u8 **)(q - 0xE) + 2));
            *(s16 *)q = h;
            *(u16 *)(q + 4) = *(u16 *)(q + 4) | m;
            func_80018080(*(u8 **)r);
        }
    }
    b = D_801A7B64;
    r = b + 0x1A4;
    i = 0x14;
    q = b + 0x1B6;
    for (; i < 0x1E; i++, q += 0x1C, r += 0x1C) {
        w = *(u16 *)(q + 4);
        m = w & 0x7A00;
        if ((w & 0x8000) != 0) {
            h = *(s16 *)q;
            func_80024D34(i, *(s8 *)(*(u8 **)(q - 0xE) + 2));
            *(s16 *)q = h;
            *(u16 *)(q + 4) = *(u16 *)(q + 4) | m;
            func_80018080(*(u8 **)r);
        }
    }
    i = 0;
    func_8001352C();
    r = (u8 *)D_8009B1F0;
    q = (u8 *)D_800E9FF0;
    for (; i < 2; r += 4, i++, q += 0x20) {
        if (*(s8 *)(q + 0x19) != 0) {
            u = func_8002C604(0x15);
            *(u16 *)(u + 0x1A) = i + 2;
            *(u8 *)(u + 0x1C) = *(u8 *)(u + 0x1C) | 0x20;
            *(u8 **)r = u;
        }
    }
    if (*(s8 *)D_8009B1C8 == 0x28) {
        i = 0;
        D_8009B23A = D_8009B23A | 0x2000;
        while (1) {
            e4 = D_801A7AD8 + D_800907D8[i + D_8009B1D5 * 20] * 28;
            if ((*(u16 *)(e4 + 0x16) & 0x8000) != 0) {
                func_80024954(e4);
            }
            i++;
            if (i >= 0xA) {
                break;
            }
        }
    } else if (D_800E9FF0[0].unk14 != 0 && D_800E9FF0[1].unk14 != 0) {
        func_8003FF08(D_8009B36A[0]);
    }
    func_800157DC();
    return;
arm2:
    if ((f & 0x4000) != 0) {
        goto arm3;
    }
    if (((D_8009B0F4[0] & 0x2000030) | D_8009B134[0]) != 0) {
        return;
    }
    if ((D_800E9ECE[0] & 0x80) != 0) {
        return;
    }
    w = f | 0x4000;
    D_8009B23A = w;
    D_8009B1B9 = 2;
    if ((w & 0x2000) == 0) {
        return;
    }
    D_8009B23A = 0xC;
    return;
arm3:
    while (1) {
        k = D_8009B1B9 - 1;
        D_8009B1B9 = k;
        k = (s8)k;
        if (k < 0) {
            D_8009B23A = 5;
            return;
        }
        if (D_8009B208[k] >= 0) {
            break;
        }
    }
    b = D_8015C424;
    g = b + D_8009B208[k] * 28 + 0x48000;
    e = *(u8 **)(g + 0x36B4);
    func_8001352C();
    u = func_8002C68C(0xB);
    *(u16 *)(u + 0) = *(u16 *)(e + 0x30);
    *(u16 *)(u + 2) = *(u16 *)(e + 0x32);
    *(u16 *)(u + 4) = *(u16 *)(e + 0x34);
    *(u16 *)(u + 0x1A) = func_800181EC(e);
    func_80024954(D_801A7AD8 + e[0x6A] * 28);
    func_8003FEE0(0x1F);
}
