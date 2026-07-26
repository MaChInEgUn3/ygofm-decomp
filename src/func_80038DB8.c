#include "common.h"

void func_80038DB8(u8 *arg0) {
    s32 c;
    s32 co;
    s32 no;
    s32 v;

    v = func_80036D3C(arg0);
    c = *(s8 *)(arg0 + 0x58);
    no = (c + 1) * 4;
    co = c * 4;
    *(s32 *)(arg0 + no) =
        (*(s32 *)(arg0 + co) & 0xFFFF0000) | (v & 0xFFFF);
    arg0[0x58]++;
}
