#include "common.h"

void func_8004ACE4(u8 *p) {
    u8 sp10[0x18];
    s32 one;

    switch (p[0x11]) {
    case 0xF:
        one = 1;
        if (func_80075DC0() == one) {
            func_80075BE0(0);
        }
        if (func_800767E0(-1) != 0) {
            func_80076790(0);
        }
        *(s32 *)sp10 = one;
        *(s32 *)(sp10 + 4) = p[0x13];
        func_80075DE0(sp10);
        if (func_800767E0(-2) != 0) {
            func_80076790(1);
        }
        func_80075BE0(1);
        D_8009B458[0x844] = p[0x13];
        break;

    case 0x10:
        *(s32 *)sp10 = 6;
        *(u16 *)(sp10 + 8) = p[0x13] << 8;
        *(u16 *)(sp10 + 0xA) = p[0x13] << 8;
        func_80075DE0(sp10);
        func_80075BE0(1);
        D_8009B458[0x845] = p[0x13];
        break;
    }
}
