#include "common.h"

void func_80040390(void) {
    u16 *b = (u16 *)D_800F2878;
    u16 *a = (u16 *)D_800EFE38;
    s32 i = 0;
    s32 v = -1;
    Slot70 *p;
    s32 j;

    D_8009B410 = 0;
    D_8009B412 = 0;
    do {
        *a = v;
        *b = v;
        b++;
        i++;
        a++;
    } while (i < 7);
    p = D_800EFE48;
    j = 0x5F;
    do {
        p->flags = 0;
        j--;
        p++;
    } while (j >= 0);
}
