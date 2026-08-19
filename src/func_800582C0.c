#include "common.h"

/* Reads each of two 0x400-halfword bands out of VRAM, recolours it and
 * writes it back, with the library spin loops around every transfer. The
 * large-argument case is reached by a goto and written last: as an early
 * `if (...) { ...; return; }` gcc inlines it and the whole loop shifts
 * (71 differences). The value handed to func_8007FA38 as its second
 * argument is the same `arg0 << 8` the rectangle gets, which is why the
 * listing seems to set only three argument registers. */

void func_800582C0(s32 arg0, s32 arg1, s32 arg2) {
    u16 buf[0x400];
    u16 *q;
    s32 y;
    s32 i;

    if ((u32)arg0 < 2) {
        y = 0;

        if (arg1 >= 7 && (arg1 & 8) == 0 && arg2 >= 0x1000) {
            goto big;
        }

        D_8009B470 = arg0 << 8;
        D_8009B472 = 0xF8;
        D_8009B474 = 0x100;
        D_8009B476 = 4;

        do {
            D_8009B472 = y + 0xF8;
            while (func_80082324(3) != 0) {
            }
            while (func_80081ED4(&D_8009B470, buf) != 0) {
            }
            while (func_80082324(3) != 0) {
            }

            q = buf;
            for (i = 0; i < 0x400; i++, q++) {
                *q = func_8005AE68(*q, (u8)arg1, (u16)arg2);
            }

            D_8009B472 = y + 0xF0;
            while (func_80082324(3) != 0) {
            }
            while (func_80081DE8(&D_8009B470, buf) != 0) {
            }
            while (func_80082324(3) != 0) {
            }
            y += 4;
        } while (y < 8);
    }

    return;

big:
    D_8009B472 = 0xF8;
    D_8009B474 = 0x100;
    D_8009B470 = arg0 << 8;
    D_8009B476 = 8;
    func_8007FA38(&D_8009B470, arg0 << 8, 0xF0);
}
