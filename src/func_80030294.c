/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_80030294.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern volatile u16 D_8009B398[4]
    __attribute__((section(".data")));
extern volatile u16 D_8009B3A4[4]
    __attribute__((section(".data")));
extern volatile u16 D_8009B394[4]
    __attribute__((section(".data")));
extern volatile u16 D_8009B39A[4]
    __attribute__((section(".data")));
s32 func_80030294(void)
{
    s32 a[5] = {1, 10, 100, 1000, 10000};
    s32 b[4] = {0xA, 0x9A, 0x99A, 0x999A};
    s32 c[5] = {1, 0x10, 0x100, 0x1000, 0x10000};
    u8 d[8];
    s32 ret;
    s32 i;
    s32 n;
    s32 e;
    s32 step;
    u8 *db;
    s32 k;
    u8 *z;
    u16 *p;
    FrontendDebugRowPointer row;
    s32 val;
    s32 mask;
    u8 t2;
    u8 f;
    u8 *r;
    s32 sc;
    s32 jj;
    s32 cc;
    s32 qq;

    ret = 0;
    *(Bytes8 *)d = *(Bytes8 *)D_8009AF4C;
    db = d;
    t2 = D_8009B2C0[D_8009B2DC];
    if ((D_8009B2EA & 0x80) == 0) {
        D_8009B2EA = D_8009B2EA | 0x80;
        if ((D_8009B2EA & 0x40) != 0) {
            jj = (s8)t2 - 1;
            row.words = &((u16 *)&D_8009B2C8)[D_8009B2DC];
            val = *row.words;
            *row.words = 0;
            p = row.words;
            do {
                k = a[jj];
                qq = val / k;
                *p = *p | (qq << (jj * 4));
                jj = jj - 1;
                val = val - k * qq;
            } while (jj >= 0);
        }
        goto fill;
    }
    if ((D_8009B2EA & 1) != 0) {
        goto fill;
    }
    if (((D_8009B3A4[0] | D_8009B3A6[0]) & 0x800) != 0) {
        goto fill;
    }
    if (((D_8009B398[0] | D_8009B39A[0]) & 0xC0) != 0) {
        ret = 1;
        goto out;
    }
    if (((D_8009B398[0] | D_8009B39A[0]) & 0x20) != 0) {
        ret = -1;
        goto out;
    }
    if (((D_8009B394[0] | D_8009B396[0]) & 0x5000) != 0) {
        e = D_8009B2E9;
        val = ((u16 *)&D_8009B2C8)[D_8009B2DC];
        step = c[e];
        if (((D_8009B394[0] | D_8009B396[0]) & 0x4000) != 0) {
            step = -step;
        }
        if ((D_8009B2EA & 0x40) != 0) {
            mask = *(u16 *)(db - -(e * 2));
            i = e;
            if (i < (s8)t2) {
                n = (s8)t2;
                do {
                    cc = val & mask;
                    val = val & ~mask;
                    cc = cc + step;
                    if (step >= 0) {
                        if (cc < b[i]) {
                            goto joined;
                        }
                    } else {
                        if (cc >= 0) {
                            goto joined;
                        }
                        val = val | ((b[i] - 1) & mask);
                    }
                    cc = 0;
                    mask = mask * 0x10;
                    step = step * 0x10;
                    i = i + 1;
                } while (i < n);
            }
        joined:
            val = val | cc;
        } else {
            val = val + step;
            val = val & (c[(s8)t2] - 1);
        }
        ((u16 *)&D_8009B2C8)[D_8009B2DC] = val;
    }
    if (((D_8009B394[0] | D_8009B396[0]) & 0xA000) == 0) {
        goto out;
    }
    if (((D_8009B394[0] | D_8009B396[0]) & 0x2000) != 0) {
        D_8009B2E9 = D_8009B2E9 - 1;
        if (D_8009B2E9 < 0) {
            D_8009B2DC = D_8009B2DC + 1;
            if (D_8009B2DC >= (s8)D_8009B2E0) {
                D_8009B2DC = D_8009B2E0 - 1;
                D_8009B2E9 = 0;
                goto fill;
            }
            f = D_8009B2C0[D_8009B2DC] - 1;
            goto setpos;
        }
    } else {
        D_8009B2E9 = D_8009B2E9 + 1;
        if (D_8009B2E9 >= (s8)t2) {
            D_8009B2E9 = 0;
            D_8009B2DC = D_8009B2DC - 1;
            if (D_8009B2DC < 0) {
                f = D_8009B2C0[0] - 1;
                D_8009B2DC = 0;
            setpos:
                D_8009B2E9 = f;
            }
        }
    }
fill:
    r = D_800EAED8;
    sc = 0x20;
    i = 0x27;
    z = r + i;
    do {
        *z = sc;
        i = i - 1;
        z = z - 1;
    } while (i >= 0);
    r = &D_800EAED8[
        D_8009B2B4[D_8009B2DC] - D_8009B2E9];
    r[0] = 0x2A;
    r[1] = 0;
out:
    i = (s8)D_8009B2B8;
    if (i != 0) {
        do {
            func_8007EF84(D_8009AF54);
            i = i - 1;
        } while (i != 0);
    }
    func_8007EF84((char *)D_8009B2EC, D_8009B2C8, D_8009B2CA, D_8009B2CC);
    func_8007EF84(D_8009AF58, D_800EAED8);
    return ret;
}
