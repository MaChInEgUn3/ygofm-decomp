#include "common.h"

void func_80041340(void) {
    s32 i;

    func_80087870(0x60, 0x60, 0x60);
    func_80087890(0, 0, 0);
    func_800857E0(0, D_80090FCC);
    func_800857E0(1, D_80090FDC);
    func_800857E0(2, D_80090FDC);

    for (i = 6; i >= 0; i--) {
        if (((s16 *)D_800EFE38)[i] >= 0) {
            func_800878D0(0x96);
            func_800878B0(0, 0);
            D_80090FB0[i]();
        }
    }
}
