#include "common.h"

void func_8007149C(void) {
    s32 k = func_8007058C();
    s32 count = 0;
    s32 i;

    for (i = 0xB; i < 0x38; i++) {
        if (D_801AB000[i].unk0 != 0) {
            count++;
        }
    }

    D_800F5B98[k] = count - 5;
}
