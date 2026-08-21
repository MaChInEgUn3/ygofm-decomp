#define D_8009B141_SIZED8
#define D_8009B142_IS_AGGREGATE
#define D_8009B143_IS_AGGREGATE
#define D_8009B144_IS_AGGREGATE
#define D_8009B318_SIZED8
#define D_8009AFA2_SIZED8
#include "common.h"

void func_80012E5C(void) {
    u8 *b;
    u8 *q;
    u8 *e;
    s32 i;
    s32 n;
    s32 v;
    s32 c1;
    s32 c2;
    s32 c3;
    s32 c4;
    u8 *bp;
    u8 *qb;
    u8 *ab;

    if (D_8009B0A8 == 0) {
        c1 = D_8009B0AD;
        c2 = D_8009B144[0];
        c3 = D_8009B143[0];
        c4 = D_8009B142[0];
        b = D_800FE048;
        b[0x18] = D_8009B0D0;
        b[0x16] = c1;
        b[0x19] = c2;
        b[0x1A] = c3;
        b[0x1B] = c4;
        func_80085500(c1, c2, c3, c4);
        if ((D_8009B098 & 0x2000) != 0) {
            func_8007FEFC(D_800E9D28);
        }
    }

    func_8007F350(1);

    if ((D_8009B318[0] & 0x80) != 0) {
        func_800359B0();
        if ((D_8009B318[0] & 0x80) != 0) {
            goto out;
        }
    }
    if (D_8009B141[0] == 0) {
        goto out;
    }
    func_80085E10(D_8009B0B4 + 0x5124, D_8009B0B4 + 0x5110);
    if ((D_8009B141[0] & 0x80) == 0) {
        func_80085E10(D_8009B0B4 + 0x5138, D_8009B0B4 + 0x5110);
        func_80085E10(D_8009B0B4 + 0x514C, D_8009B0B4 + 0x5110);
    }
    func_80085D80(D_8009B0B4 + 0x5110);

out:
    i = 3;
    v = func_80085320();
    bp = &D_8009B0A0;
    D_8009B0AC = v;
    D_8009AFA2[0] = v;
    ab = D_800A5768;
    e = ab + (v & 0xFF) * 0x222E0;
    D_8009B0B4 = (s32)(D_8009B4A8 + (v & 0xFF) * 0x5160);
    n = 0x514C;
    func_800862C0(e);
    qb = D_800E9D90;
    q = qb + 0xC;

    do {
        e = (u8 *)(D_8009B0B4 + n);
        *(s32 *)q = (s32)e;
        q -= 4;
        *(s32 *)e = *(u8 *)(i + (s32)bp);
        n -= 0x14;
        func_80085DB0(0, 0, e);
        i--;
    } while (i >= 0);
}
