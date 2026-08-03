#include "common.h"

s32 func_8004C77C(void) {
    u8 *e;
    s32 i;
    s32 v;
    u8 *b;

    *(s32 *)(D_8009B458 + 0x804) = 0;
    D_8009B458[0x800] = 0;
    func_8004BCE8();

    for (i = 0; i < *(u16 *)(D_8009B458 + 0x7FA); i++) {
        e = D_8009B458 + (i * 0x2C + 0x518);
        *(s32 *)(e + 4) = *(s32 *)e;
        v = func_8004BB34(e);
        e[0x24] = 0;
        e[0x27] = 0;
        e[0x29] = 0;
        e[0x28] = 0;
        b = D_8009B458;
        *(s32 *)(e + 0x1C) = v;
        *(s16 *)(e + 0x18) = 0;
        if (*(s32 *)(b + 0x804) != 0) {
            func_8004C5C8(e);
        }
    }
    return 0;
}
