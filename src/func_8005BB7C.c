#define D_8009B142_SIZED
#define D_8009B143_SIZED
#define D_8009B144_SIZED
#include "common.h"

s32 func_8005BB7C(s32 arg0) {
    u16 rect[4];
    u8 buf[0x3C0];
    s32 i;
    s32 m;
    u8 *q;

    func_8007F6CC(0);
    func_80044F58(0);
    /* volatile: retail sets a0 = 0 above this store and leaves the jal's
       delay slot empty, which only a store that cannot enter a slot gives. */
    *(volatile u8 *)&D_8009B063 = 1;
    func_8008FE7C(0);
    func_800782D0();
    while (func_8007E7F0(9, 0, 0) == 0) {
    }
    if (D_8009B061 != 0 || arg0 != 0) {
        func_8005C568(0, 0x100);
    }
    if (D_8009B060 != 0) {
        i = 0;
        m = func_80085320();
        q = buf;
        for (; i < 0x3C0; i += 3) {
            *q++ = D_8009B144[0];
            *q++ = D_8009B143[0];
            *q++ = D_8009B142[0];
        }
        rect[0] = 0;
        i = 0;
        rect[1] = m << 8;
        rect[2] = 0x1E0;
        rect[3] = 1;
        for (; i < D_800FE0D4; i++) {
            func_8007F978(rect, buf);
            func_8007F6CC(0);
            rect[1]++;
        }
        rect[0] = 0x140;
        rect[1] = 0;
        rect[3] = 1;
        rect[2] = D_800FE0D0;
        for (i = 0; i < D_800FE0D4; i++) {
            func_8007F978(rect, buf);
            func_8007F6CC(0);
            rect[1]++;
        }
        func_8007F6CC(0);
        func_80074170(0);
        i = 0;
        func_80085500();
        rect[1] = (m ^ 1) << 8;
        rect[2] = 0x1E0;
        rect[0] = 0;
        rect[3] = 1;
        for (; i < D_800FE0D4; i++) {
            func_8007F978(rect, buf);
            func_8007F6CC(0);
            rect[1]++;
        }
        func_8007F6CC(0);
        func_80074170(0);
        D_800FE0CC = 1;
        func_80085500();
        func_800856A0(0, 0, 0x140, 0);
        func_80084F60(0x140, 0xF0, 4, 1, 0);
        rect[0] = 0;
        rect[1] = 0;
        rect[2] = *(s32 *)&D_800FE0D0 * 2;
        rect[3] = *(u16 *)&D_800FE0D4;
        func_8007F850(rect, D_8009B144[0], D_8009B143[0], D_8009B142[0]);
        D_8009B060 = 0;
    }
    return 0;
}
