/* MATCH 2026-09-05. Parked at 10 as a load-scheduling question and it was the
 * batched-load rule: retail issues all four accumulator loads before the first
 * addu, so the four are named reads in retail's order (10 -> 2). The last two
 * were the order of the second and third loads, which no source order of the
 * four moves; a do/while(0) pin round the D_8009B294 read alone is the MATCH
 * (round D_8009B288 or the last pair it is 17). Same addressing as before: as
 * -G4 with D_8009B146/148 sized so their stores go through $at. */
#define D_8009B146_SIZED
#include "common.h"

void func_8002EA0C(void) {
    s32 sx;
    s32 sy;
    s32 n;
    s32 v;
    s32 a;
    s32 b;
    s32 c;
    s32 d;

    if (func_8002E3B4() == 0) {
        sx = *(s16 *)&D_8009B146[0];
        n = *(s16 *)&D_8009B29C;
        D_8009B294 = ((*(s16 *)&D_8009B2A8 - sx) << 16) / n;
        sy = *(s16 *)&D_8009B148[0];
        D_8009B298 = ((*(s16 *)&D_8009B2AA - sy) << 16) / n;
        D_8009B284 = (sx << 16) | 0x8000;
        D_8009B288 = (sy << 16) | 0x8000;
    }

    a = D_8009B284;
    do { b = D_8009B294; } while (0);
    c = D_8009B288;
    d = D_8009B298;
    a = a + b;
    D_8009B284 = a;
    D_8009B146[0] = a >> 16;
    c = c + d;
    D_8009B288 = c;
    D_8009B148[0] = c >> 16;

    v = D_8009B29C - 1;
    D_8009B29C = v;
    if ((s16)v <= 0) {
        D_8009B27C = 0;
        D_8009B146[0] = D_8009B2A8;
        D_8009B148[0] = D_8009B2AA;
    }
}
