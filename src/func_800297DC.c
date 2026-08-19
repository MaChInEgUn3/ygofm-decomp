#include "common.h"

/* Two eight-argument calls with the same list, the second only when the
 * rectangle at r+4 has gone negative. The n * 3 / 4 is a signed divide --
 * the bgez/+3 correction in the listing -- not a shift. */

void func_800297DC(u8 *arg0, s32 arg1, u8 *p, u8 *r, s32 base, s32 n) {
    s32 h;

    *(s16 *)(p + 4) = base + n;
    *(s16 *)(p + 0xC) = base + n * 3 / 4;
    *(s16 *)(p + 0x14) = base;
    func_80087A50(p, p + 8, p + 0x10, arg0 + 8, arg0 + 0x10, arg0 + 0x18, r, r + 4);

    if (*(s32 *)(r + 4) < 0) {
        h = n / 2;
        *(s16 *)(p + 4) = base + h;
        *(s16 *)(p + 0xC) = base + h * 3 / 4;
        func_80087A50(p, p + 8, p + 0x10, arg0 + 8, arg0 + 0x10, arg0 + 0x18, r, r + 4);
    }

    func_8005B260(arg0, arg1, 1, 1);
}
