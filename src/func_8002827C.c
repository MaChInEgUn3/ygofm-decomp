#include "common.h"

s32 func_8002827C(u8 *arg0) {
    if (*(u16 *)(arg0 + 0x16) & 0x200) {
        return (D_801D4244[*(s16 *)(arg0 + 0xC) - 1] >> 18) & 0xF;
    }

    return (D_801D4244[*(s16 *)(arg0 + 0xC) - 1] >> 22) & 0xF;
}
