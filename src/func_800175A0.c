#define D_8009B361_IN_DATA
#include "common.h"

void func_800175A0(void) {
    u16 sp[2];
    Rec20 *e;
    s32 k;
    s32 j;
    u32 m;
    u16 t;
    u8 *q;
    s8 *r;

    e = D_800E9FF0;
    if (D_8009B361 < 0) {
        sp[0] = D_8009B234;
        sp[1] = D_8009B236;
    } else {
        sp[1] = 0x1F40;
        sp[0] = 0x1F40;
    }

    for (k = 0; k < 2; k++, e++) {
        j = 4;
        r = (s8 *)e + j;
        for (; j >= 0; j--, r--) {
            r[0x1A] = -1;
        }
        q = (u8 *)e;
        e->unk16[2] = 0;
        t = sp[k];
        *(s16 *)(e->unk0 + 0x12) = 0;
        e->unk19 = 0;
        e->unk14 = t;
        *(u16 *)e->unk16 = t;
        e->unk1A[5] = 0;
        for (m = 0; m < 13; m++) {
            *q = 0;
            q++;
        }
    }

    if (D_8009B360[0] < 0) {
        if (D_8009B361 < 0) {
            D_800E9FF0[1].unk1A[5] = *(u8 *)&D_8009B230;
            D_800E9FF0[0].unk1A[5] = *(u8 *)&D_8009B230;
        } else {
            D_800EA02F[0] = -1;
        }
    } else {
        if (D_8009B361 >= 0) {
            D_800EA02F[0] = -1;
        }
    }
    D_8009B1C8 = (u8 *)&D_800E9FF0[D_8009B1D5];
}
