#include "common.h"

void func_80024914(u8 *arg0) {
    *(u16 *)(arg0 + 0x16) &= 0x7FFF;

    if (*(s32 *)arg0 != 0) {
        func_8004036C(*(s32 *)arg0);
        *(s32 *)arg0 = 0;
    }
}
