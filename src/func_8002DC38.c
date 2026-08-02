#define D_8009B26C_IS_SCALAR
#define D_8009B269_IS_SCALAR
#define D_8009B368_SIZED
#include "common.h"

void func_8002DC38(void) {
    s32 v = D_8009B26C;
    s32 r;
    u8 *p;

    if ((v & 0x40) == 0) {
        D_8009B26C = v | 0x40;
        D_8009B236 = 0x1F40;
        D_8009B234 = 0x1F40;
        func_80180FD8(&D_8009B234, &D_8009B236, &D_8009B230);
        func_80035C38(0, 0x25, 0x34, 0xB4, 0xD8, 0x20, 0x20);
        p = (u8 *)D_800EB0F8;
        func_80039A14(p);
        func_80035BE4(1, 0x26, 0xE, 0x66, 0x100, 0x30);
        func_80039A14(p + 0x64);
        func_8003FF08(0x72C0);
        func_80015A00();
    }

    r = func_801812B4();
    if (r != 0) {
        func_8003FF34();
        func_80015B00();
        func_80181E30();
        if (r == 1) {
            func_80024DC8(-1, -1, 0, 0);
            D_8009B368[0] = 8;
        } else {
            D_8009B26C = D_8009B269;
        }
    }
}
