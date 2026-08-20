#define D_8009B0D8_IS_SCALAR
#include "common.h"

void func_80015CFC(void);
void func_800151D8(void);

void func_80015310(u8 *p) {
    u8 *q;
    u8 *r;
    s32 a;
    s32 b;
    s32 n;
    s32 f;
    s32 g;
    s32 v;
    s32 c;

    q = D_800E9EC8;

    if ((q[6] & 0x80) == 0) {
        return;
    }

    if ((D_8009B141 & 0x80) == 0) {
        func_80015CFC();
    }

    n = p[7] * D_8009B0D8;
    a = p[4];
    b = p[5];

    if (a == b) {
        f = q[6];
        q[6] = f & 0x7F;
        if (a == 0xFF) {
            q[6] = f & 0x79;
            func_80015CFC();
            D_8009B140 = 0;
            D_8009B145 = 0;
            D_8009B144 = D_8009B14C;
            D_8009B143 = D_8009B14B;
            D_8009B142 = D_8009B14A;
        }
        if (a != 0) {
            return;
        }
        g = q[6];
        if ((g & 2) != 0) {
            if ((g & 4) == 0) {
                return;
            }
            D_8009B141 = 0x80;
        } else {
            func_80015D0C();
        }
        r = D_800E9EC8;
        D_8009B144 = D_8009B14C;
        D_8009B143 = D_8009B14B;
        D_8009B142 = D_8009B14A;
        v = r[6];
        if ((v & 0x10) != 0) {
            if ((v & 0x20) != 0) {
                r[6] = v & 0xDF;
                D_8009B144 = p[0];
                D_8009B143 = p[1];
                D_8009B142 = p[2];
                func_80015CFC();
                r[6] = r[6] | 0x80;
            }
        }
    } else {
        if ((q[6] & 1) != 0) {
            func_800151D8();
            return;
        }
        if (a < b) {
            a = a + n;
            c = a < b;
        } else {
            a = a - n;
            c = b < a;
        }
        if (c == 0) {
            a = b;
        }
        D_800E9ECC[0] = a;
    }
}
