#include "common.h"

s32 func_8004B734(void) {
    u8 *p;
    s32 i;
    VoidFn f;

    p = D_8009B458;
    if (p[0x814] == 0) {
        return 1;
    }
    if (p[0x500] != 0) {
        return 1;
    }
    if (p[0x509] != 0) {
        return 1;
    }
    if (p[0x501] == 0) {
        func_800739EC(0xF2000002);
        D_8009B458[0x501] = 1;

        for (i = 0; i < 8; i++) {
            func_8004C8C8();
            D_8009B458[0x508]++;
            if (D_8009B458[0x508] >= 0xB) {
                D_8009B458[0x508] = 0;
                func_8004C84C();
                func_8004AAFC();
                f = *(VoidFn *)(D_8009B458 + 0x50C);
                if (f != (VoidFn)0) {
                    f();
                }
            }
        }
        D_8009B458[0x501] = 0;
    }
    return 0;
}
