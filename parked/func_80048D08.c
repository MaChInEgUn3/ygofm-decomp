#include "common.h"

/* Eight raw bytes moved whole between two parallel tables; retail's
 * lwl/lwr + swl/swr pair rather than aligned lw/sw says the alignment is one.
 * Local to this file -- src/func_80059000.c has its own Rec8 of a different
 * shape, so this must not go in types.h. */
typedef struct {
    u8 b[8];
} Rec8;

void func_80048D08(s32 a, s32 *arg1) {
    u8 *base;
    u8 *pa;
    u8 *pb;
    u8 *q;
    u8 *d;
    u8 *d2;
    u8 *p;
    s32 o;
    s32 j;
    s32 k;
    u32 ta;
    u32 tb;
    u16 id;
    u16 h;
    u16 v;

    if ((u32)a < 2) {
        base = (u8 *)0x801E7800;
        o = 1 - a;
        ta = (a % 2) * 0x19000 + 0xD810;
        tb = (o % 2) * 0x19000 + 0xD810;
        pa = base + (a << 11);
        pb = base + (o << 11);
        func_80048C70(pa, arg1);
        func_8004763C();

        for (k = 0; k < 2; k++) {
            q = pb;
            if (k != 0) {
                q = pa;
            }
            for (j = 0; j < *(s32 *)q; j++) {
                id = *(u16 *)(q + j * 2 + 8);
                if (id != 0xFFFF) {
                    p = D_8009B45C;
                    h = *(u16 *)(p + 0x440);
                    *(u16 *)(*(u8 **)(p + 0x43C) + id * 2) = h;
                    d = (u8 *)(h * 8 + (s32)*(u8 **)(p + 0x444));
                    *(Rec8 *)d = *(Rec8 *)(q + j * 8 + 0x1A0);
                    d2 = (u8 *)(h * 8 + (s32)*(u8 **)(p + 0x444));
                    v = *(u16 *)(d2 + 6);
                    if (k != 0) {
                        v += ta >> 4;
                    } else {
                        v += tb >> 4;
                    }
                    *(u16 *)(d2 + 6) = v;
                    *(u16 *)(D_8009B45C + 0x440) =
                        *(u16 *)(D_8009B45C + 0x440) + 1;
                }
                if (k != 0) {
                    *(u16 *)(D_8009B45C + ((a << 6) + j * 2) + 0x44C) = id;
                }
            }
        }
    }
}
