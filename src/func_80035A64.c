#include "common.h"

void func_80035A64(void) {
    Rec64 *e;
    s32 i;

    e = D_800EB0F8;
    for (i = 4; i != 0; i--) {
        e->unk34 = 0;
        e->unk30 = 0;
        e->unk2C = 0;
        e->unk28 = 0;
        e++;
    }

    func_80035CE4();
    func_80035DF4();
}
