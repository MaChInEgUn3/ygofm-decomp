#include "common.h"

void func_80040D14(void) {
    s32 i = D_800EFE44[0];

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
                void (*g)(u8 *, s32) = *(void (**)(u8 *, s32))(q + 0x4C);

                if (g != 0) {
                    g(q, t[q[0x17]]);
                }
            }
        } while (i >= 0);
    }
}
