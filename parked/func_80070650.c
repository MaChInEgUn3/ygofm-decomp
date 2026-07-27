#include "common.h"

s32 func_80070650(void) {
    u8 *p = (u8 *)D_800F5BE8;
    ObjFn *t = D_800916E0;
    s32 i;
    ObjFn f;

    do {
        *(s32 *)(p + 0xC) = *(s32 *)(p + 8);

        i = func_8007058C();
        t[i](p);

        f = t[i];

        if (f == (ObjFn)func_80070FF8) {
            return 1;
        }

        if (f == (ObjFn)func_80071000) {
            return 3;
        }

        if (f == (ObjFn)func_80070F1C) {
            return 2;
        }
    } while (func_80074170(1) < 0xF0);

    return 0;
}
