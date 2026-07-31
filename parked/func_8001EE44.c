#include "common.h"

s32 func_8001EE44(u8 *arg0, u8 *arg1) {
    s32 a;
    s32 b;

    if (arg1 == (u8 *)0) {
        return 0;
    }
    if (*(u16 *)(arg0 + 0x16) & 0x200) {
        a = D_801D4244[*(s16 *)(arg0 + 0xC) - 1] >> 18;
    } else {
        a = D_801D4244[*(s16 *)(arg0 + 0xC) - 1] >> 22;
    }
    a &= 0xF;
    if (*(u16 *)(arg1 + 0x16) & 0x200) {
        b = D_801D4244[*(s16 *)(arg1 + 0xC) - 1] >> 18;
    } else {
        b = D_801D4244[*(s16 *)(arg1 + 0xC) - 1] >> 22;
    }
    b &= 0xF;
    return func_8002CB80(a, b);
}
