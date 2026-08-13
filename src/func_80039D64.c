#include "common.h"

void func_80039D64(u8 *arg0) {
    Rec1C *p;
    Rec1C *q;
    Rec1C *s;
    Rec1C *e;

    p = *(Rec1C **)(arg0 + 0x24);
    D_8009B330 = 0;

    while (p->unk11 & 0x80) {
        if (p->unk13 != 0) {
            D_80090F58[p->unk13 & 0x1F](p, arg0);
        }
        p++;
    }

    if (D_8009B330 != 0) {
        q = &D_800EB288[*(u16 *)(arg0 + 0x5C)];
        e = *(Rec1C **)(arg0 + 0x20);
        s = q;
        while (s != e) {
            if (s->unk11 & 0x80) {
                *q = *s;
                q++;
            }
            s++;
        }
        *(Rec1C **)(arg0 + 0x20) = q;
        q->unk11 = 0;
    }
}
