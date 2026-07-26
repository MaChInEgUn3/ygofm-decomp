#include "common.h"

void func_8001B8B8(u8 *arg0) {
    s32 i;

    for (i = 0; i < 5; i++) {
        if (D_800EA030[i].unk9 == 0) {
            *(s32 *)(D_800EA030[i].unk0 + 0xC) = 0x404040;
        }
    }

    if (arg0[0x15] == 0) {
        *(s32 *)(D_800EA030[*(s8 *)(arg0 + 0xE)].unk0 + 0xC) = 0x808080;
    }
}
