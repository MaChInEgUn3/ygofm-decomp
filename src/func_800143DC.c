#include "common.h"

typedef struct {
    s32 w[18];
} Blk72;

typedef struct {
    s32 w[8];
} Blk32;

void func_800143DC(void) {
    *(Blk72 *)D_800E9E60 = *(Blk72 *)D_800E9E18;
    *(Blk32 *)D_801D4200 = *(Blk32 *)(D_801D4200 + 0x20);
    if (D_800E9E60[0x46] == 4) {
        D_8009B112 |= 1;
    }
    D_8009B0F4 = *(s32 *)(D_800E9E60 + 0x2C) | 0x10;
}
