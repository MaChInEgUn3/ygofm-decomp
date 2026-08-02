#define D_8009B146_SIZED
#define D_8009B0F4_SIZED
#define D_8009B134_SIZED
#include "common.h"

void func_8002E470(void) {
    u8 *e;
    u8 *q;
    u8 *r;
    u8 *t;
    s32 x;
    s32 f;
    s32 a;
    s32 b;

    if (func_8002E3B4() == 0) {
        e = D_800EAE98;
        D_8009B148[0] = 0;
        D_8009B146[0] = 0;
        func_8002E00C(e);

        q = D_8009B290;
        r = q + 2;
        D_8009B290 = r;
        x = q[0] | (q[1] << 8);
        D_8009B270 = x;
        if (x & 0x8000) {
            D_8009B270 = x & 0xFFF;
            t = q + 4;
            D_8009B290 = t;
            a = q[2];
            b = r[1];
            D_8009B290 = q + 6;
            D_8009B146[0] = a | (b << 8);
            D_8009B148[0] = q[4] | (t[1] << 8);
        }
        func_8002DF2C(e, D_8009B270);
    }

    f = D_8009B27C;
    if ((f & 0x800) == 0) {
        if (((D_8009B0F4[0] & 0x2000030) | D_8009B134[0]) == 0) {
            D_8009B27C = f | 0x800;
            func_8002E128(D_800EAE98, -1);
            func_800157DC();
        }
    } else if ((D_800E9ECE[0] & 0x80) == 0) {
        D_8009B27C = 0;
    }
}
