#include "common.h"

void func_80038BA8(u8 *arg0) {
    s32 v = func_80036D3C(arg0);
    s32 *p = (s32 *)(arg0 + *(s8 *)(arg0 + 0x58) * 4);

    *p = (*p & 0xFFFF0000) | (v & 0xFFFF);
}
