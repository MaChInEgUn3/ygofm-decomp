#include "common.h"

/* Clears two bytes in each of 0x26C records. */
void func_80035DF4(void) {
    Rec1C *p = D_800EB288;
    s32 i;

    for (i = 0x26C; i != 0; i--) {
        p->unk11 = 0;
        p->unk18 = 0;
        p++;
    }
}
