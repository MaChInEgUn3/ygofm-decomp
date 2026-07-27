#include "common.h"

void func_80040BF8(void) {
    s32 i = D_800EFE3E[0];

    if (i >= 0) {
        Slot70 *base = D_800EFE48;
        s32 *t = (s32 *)D_800E9D90;

        do {
            Slot70 *p = (Slot70 *)(i * 112 + (s32)base);
            ObjFn f = p->unk24;
            u8 *q = (u8 *)p;

            i = p->unk2;

            if (f != 0) {
                f(q);
            }

            if (((p->flags & 0xC0) ^ 0xC0) == 0) {
                func_800408D0(q, t[q[0x17]], *(s16 *)(q + 0x14));
            }
        } while (i >= 0);
    }
}
