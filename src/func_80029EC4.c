/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_80029EC4.c (Library_DrawCardGrid), profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern u8 D_800EA1E8[];
void func_80029EC4(void)
{
    GsSPRITE *p;
    GsGLINE *q;
    u8 *pj;
    u8 *pk;
    GsOT *ot;
    s32 n;
    s32 idx;
    s32 i;
    s32 c;
    s32 j;
    s32 k;
    s32 r;
    s32 white;
    s32 grey;
    s32 a;
    s32 b;
    s32 y;
    s32 v;
    u8 *list;
    u8 *tb;
    s32 e;
    s32 f;
    s32 first;
    s32 attribute;

    p = (GsSPRITE *)0x1F800320;
    n = (D_8009B148 - 8) / 178;
    ot = D_800E9D90[3];
    if (n < 0) {
        return;
    }
    e = 0xE000C;
    f = 0xF70130;
    white = 0x808080;
    grey = 0x404040;
    a = n * 178 + 8;
    b = n * 25;
    p->x = 8;
    first = b * 8;
    p->y = first * 178 + 8;
    *(u32 *)&p->w = e;
    *(u32 *)&p->cx = f;
    attribute = 0x8000000;
    do {
        p->cy = 0xF7;
        *(u16 *)&p->u = 0xF060;
        p->attribute = attribute;
        p->tpage = 0x1B;
    } while (0);
    do {
        idx = b * 8;
        p->y = a;
        p->y = a - D_8009B148;
        for (i = 0; i < 10; idx += 10, i++) {
            y = p->y;
            j = idx + 1;
            tb = D_800EA1E8;
            if (y + p->w > 0) {
                if (y >= 0xF0) {
                    goto done;
                }
                k = idx + 0x65;
                c = 0;
                pk = &D_800EA1E8[k * 4];
                pj = &D_800EA1E8[j * 4];
                do {
                    r = func_80029EB0(tb, j);
                    if (r & 0x80) {
                        (*(u32 *)&( p )->r)  = white;
                        if (r & 1) {
                            (*(u32 *)&( p )->r)  = grey;
                        }
                        p->x = c + 8;
                        p->cx = *(u16 *)(pj + 0x54);
                        func_800849F0(p, ot, 2);
                    }
                    if (k < (722  + 1) ) {
                        r = func_80029EB0(tb, k);
                        if (r & 0x80) {
                            (*(u32 *)&( p )->r)  = white;
                            if (r & 1) {
                                (*(u32 *)&( p )->r)  = grey;
                            }
                            p->x = c + 0xA8;
                            p->cx = *(u16 *)(pk + 0x54);
                            func_800849F0(p, ot, 2);
                        }
                    }
                    pj += 4;
                    j++;
                    pk += 4;
                    c += 0xE;
                    k++;
                } while (c < 0x8A);
            }
            p->y = p->y + 0x10;
        }
        a += 178;
        n++;
        b += 25;
    } while (n < 4);

done:
    q = (GsGLINE *)0x1F800000;
    v = D_8009B09C & 0x7F;
    q->attribute = 0x50000000;
    q->b0 = 0;
    q->g0 = 0;
    q->r0 = 0;
    q->b1 = 0;
    q->g1 = 0;
    q->r1 = 0;
    list = D_800EA1E8;
    switch (v / 32) {
    case 0:
        q->g0 = v * 8;
        break;
    case 1:
        q->g0 = 0xFF;
        q->g1 = (v - 0x20) * 8;
        break;
    case 2:
        q->g0 = (0x5F - v) * 8;
        q->g1 = 0xFF;
        break;
    case 3:
        q->g1 = (0x7F - v) * 8;
        break;
    }
    q->x1 = 0;
    q->x0 = *(u16 *)(list + 8) - D_8009B146;
    q->y0 = q->y1 = *(u16 *)(list + 0xA) - D_8009B148;
    func_80084130(q, ot, 1);
    q->x1 = 0x140;
    func_80084130(q, ot, 1);
    q->y1 = 0;
    q->x1 = q->x0;
    func_80084130(q, ot, 1);
    q->y1 = 0xF0;
    func_80084130(q, ot, 1);
}
