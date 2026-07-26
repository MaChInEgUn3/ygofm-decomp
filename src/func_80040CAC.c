#include "common.h"

void func_80040CAC(void) {
    s32 i = *(s16 *)D_800EFE38;

    while (i >= 0) {
        Slot70 *p = &D_800EFE48[i];
        ObjFn f = p->unk24;

        i = p->unk2;

        if (f != 0) {
            f((u8 *)p);
        }
    }
}
