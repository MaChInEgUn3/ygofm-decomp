/* MATCH (2026-09-05), from a park at 2 differences. The last two were the
 * `n = v & 0xFF` that gcc sank into the jal's delay slot where retail keeps
 * the andi before the call and puts `n - 1` in the slot. The mask is not a
 * mask: it is the READ-BACK of the byte global just stored, and the
 * decrement belongs to the same expression -- `n = D_8009B364[0] - 1;`
 * before the call. Written as the read-back and the decrement in two
 * statements it is 4, as `v & 0xFF` with the decrement before the call 3.
 * Flags: default compiler, as -G4 (D_8009B364 sized out of small data, the
 * D_8009B0F4 / D_8009B134 sized arms).
 */
#define D_8009B364_SIZED8
#define D_8009B0F4_SIZED
#define D_8009B134_SIZED
#include "common.h"

void func_80024E58(void) {
    u8 *p;
    u8 *r;
    u8 *q;
    u8 *e;
    s32 i;
    s32 n;
    s32 f;
    s32 v;
    s32 b;
    u8 *a;

    if (func_80024E24() == 0) {
        r = D_8009B1C8;
        r[0xA] = r[0xA] + 1;
        v = *(u8 *)&D_8009B1D2 - 0x49;
        D_8009B364[0] = v;
        n = D_8009B364[0] - 1;
        e = func_8002C604(0xA);
        D_8009B17C = e;
        *(s16 *)(e + 0x1A) = n;
        func_8003FEE0(0x13);
        return;
    }

    f = D_8009B220;

    if ((f & 0x40) == 0) {
        if (D_8009B17C[0x1D] != 0) {
            D_8009B220 = f | 0x40;
            func_80014E1C(0, (u8 *)0, D_8009B364[0] * 0xEB + 0x1791, 0x10,
                          (u8 *)0, 0, 0x1000280);
        }
        return;
    }

    if ((f & 0x20) == 0) {
        if (((D_8009B0F4[0] & 0x2000030) | D_8009B134[0]) == 0) {
            a = D_8009B214;
            b = D_8009B364[0];
            *(s16 *)(D_8009B17C + 0x1A) = -2;
            func_80040410(a, b);
            D_8009B220 = D_8009B220 | 0x20;
        }
        return;
    }

    if ((D_8009B17C[0x1C] & 0x80) != 0) {
        return;
    }

    q = D_801A7AD8;
    i = 0;
    p = q + 0x14;
    do {
        if ((*(u16 *)(p + 2) & 0x8000) != 0) {
            *(s16 *)(p + 0) = func_8002497C((*(u8 **)q)[0x68]);
        }
        i++;
        p += 0x1C;
        q += 0x1C;
    } while (i < 0x1E);

    D_8009B220 = 0;
}
