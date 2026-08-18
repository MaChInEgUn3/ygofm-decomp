#include "common.h"

/* Both divisions are real `div`s wrapped in break 7 / break 6 because the
 * divisor is a field rather than a literal -- the dividends (0x80, 0x800)
 * are the constants. The `u8 c` at the end is not decoration either: the
 * listing masks the lbu with andi 0xFF before testing it, which is the
 * QImode normalisation a byte-typed local gives and an s32 does not. */

void func_8001D3C4(u8 *p) {
    s32 a;
    s32 d;
    u8 c;

    if (func_80042B98(p) == 0) {
        if (*(s16 *)(p + 0x2C) != p[0x21]) {
            *(u16 *)(p + 8) |= 4;
        }
        *(s16 *)(p + 0x2E) = *(u16 *)(p + 0x60);
        func_80043178(p);
        *(s16 *)(p + 0x60) = 0;
    }

    a = p[0x21];
    if (a != *(s16 *)(p + 0x2C)) {
        p[0x21] = a + 0x80 / *(s16 *)(p + 0x2E);
    }

    func_8004318C(p, *(s16 *)(p + 0x28), *(s16 *)(p + 0x2A), *(s16 *)(p + 0x60));

    d = 0x800 / *(s16 *)(p + 0x2E);
    *(s16 *)(p + 0x60) = *(u16 *)(p + 0x60) + d;

    if (*(s16 *)(p + 0x60) >= 0x800) {
        c = p[0x2C];
        p[0x21] = c;
        *(s32 *)(p + 0x30) = *(s32 *)(p + 0x28);
        if (c == 0) {
            *(u16 *)(p + 8) &= 0xFFFB;
        }
        p[0x6C] = 0;
        *(s32 *)(p + 0x24) = 0;
    }
}
