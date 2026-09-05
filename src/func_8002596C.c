#define D_8009B260_IN_DATA
#define D_8009B20C_HALF
#include "common.h"

void func_8002596C(void) {
    u8 *p;
    u8 *e;
    u8 *r;
    u8 *q;
    s32 a;
    u8 *t;
    s32 v;
    s32 w;
    s32 n;

    if (func_80024E24() == 0) {
        D_8009B20C[1] = 0;
        /* `q` is the other arm's allocation. Borrowing its name here is what
         * produces retail's `addu $s0,$v0,$zero`: a fresh local coalesces
         * away and the copy never appears (measured, both placements). */
        q = func_8002C604(0x10);
        t = D_80090800;
        e = ((D_8009B20C[1] + 5) * 4 + D_8009B1D5 * 80) + t;
        w = *(u16 *)(e + 0);
        p = q;
        D_8009B17C = p;
        *(s16 *)(p + 2) = 0;
        *(s16 *)(p + 0) = w;
        a = 0x15;
        *(s16 *)(p + 4) = *(u16 *)(e + 2);
        goto call;
    }

    if ((D_8009B260 & 1) == 0) {
        D_8009B220 = 0;
        return;
    }

    if (D_8009B17C[0x1D] == D_8009B20C[1] + 1) {
        func_8003FEE0(0x15);
        n = D_8009B1D5 * 20 + 5;
        r = D_801A7AD8 + D_800907D8[D_8009B20C[1] + n] * 28;
        v = *(u16 *)(r + 0x16) & 0x8000;
        D_8009B20C[1] = *(u16 *)&D_8009B20C[1] + 1;
        if (v != 0) {
            q = func_8002C604(0xB);
            *(s32 *)(q + 0x14) = *(s32 *)(q + 0x14) + D_8009B20C[1] * 0x3000;
            *(s16 *)(q + 0) = *(u16 *)(*(u8 **)r + 0x30);
            *(s16 *)(q + 2) = *(u16 *)(*(u8 **)r + 0x32);
            *(s16 *)(q + 4) = *(u16 *)(*(u8 **)r + 0x34);
            *(s16 *)(q + 0x1A) = func_800181EC(*(u8 **)r);
            func_80024954(r);
            a = 0x1F;
call:
            func_8003FEE0(a);
        }
    }
}
