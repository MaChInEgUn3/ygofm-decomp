#include "common.h"
void func_8002A9C0(u8 *arg0);

u8 *func_8002ABB4(u8 *arg0, s32 arg1) {
    u8 *p = func_800400AC(func_8004002C(), 6);
    s32 b;
    s32 c;

    *(s32 *)(p + 0x48) = *(s32 *)(arg0 + 0x48);
    b = *(s32 *)(arg0 + 0x18);
    *(u16 *)(p + 0x60) = 0x100;
    *(s32 *)(p + 0x18) = b;
    *(s16 *)(p + 0x3C) = *(s16 *)(p + 0x18) * 2;
    *(s16 *)(p + 0x3E) = *(s16 *)(p + 0x1A) * 2;
    *(s32 *)(p + 0x30) = *(s32 *)(arg0 + 0x30);
    *(s32 *)(p + 0x20) = *(s32 *)(arg0 + 0x20);
    c = *(s32 *)(arg0 + 0x44);
    *(s32 *)(p + 0xC) = 0;
    *(s32 *)(p + 0x44) = c;
    func_80042918(p);
    func_800428EC(p, (s8)(arg0[0x16] + arg1));
    *(s32 *)(p + 0x10) = 1;
    *(void **)(p + 0x4C) = func_8002A9C0;
    *(s32 *)(p + 4) = (*(s32 *)(p + 4) | 0x50000000) & 0xF7FFFFFF;
    return p;
}
