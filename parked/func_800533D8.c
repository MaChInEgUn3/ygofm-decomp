/* 2026-09-05, still 7: the preheader order (retail: cursor, 0xFFFF, counter;
 * ours: cursor, counter, 0xFFFF) does not follow the source. Six spellings all
 * 7: `v = 0xFFFF;` named before the counter with the counter as a plain
 * statement, named before a for-init, the `sp10[0] = 0` store moved below both,
 * a do/while with `--i >= 0`, and `q = sp10 + 1` with the counter first; the
 * `do { v = 0xFFFF; } while (0);` pin is 9. Flag sweep flat. A pure
 * allocation tie-break -- permuter next. */
#include "common.h"

void func_800533D8(void) {
    u16 sp10[256];
    u16 sp210[4];
    u8 *p;
    u16 *q;
    s32 i;

    sp10[0] = 0;
    q = &sp10[1];
    for (i = 0xFE; i >= 0; i--) {
        *q++ = 0xFFFF;
    }

    sp210[0] = 0x200;
    sp210[1] = 0xF0;
    sp210[2] = 0x100;
    sp210[3] = 1;

    while (func_80082324(3) != 0) {
    }
    while (func_80081DE8(sp210, sp10) != 0) {
    }
    while (func_80082324(3) != 0) {
    }

    func_8005611C(0);
    func_8005611C(1);
    func_8005611C(2);

    i = 0;
    p = D_800F2B50;
    while (i < 10) {
        *(u16 *)p &= 0xFFFE;
        i++;
        p += 0x18;
    }

    D_8009AF9B = 0;
    D_8009AF9C = 0;
    func_80059AE0(0x8000);
    D_8009AF94 = 0;
    D_8009AF9A = -1;
}
