/* 2 differing at 169/169 (2026-09-05 re-measured; parked 2026-08-29 at 9).
 * Residue: the second scaling's `+ 1` -- retail `addiu $v0,$v0,1` in place
 * on the loaded halfword, ours `addiu $v1,$v0,1` into a second register,
 * and the mult follows it. Measured 2026-09-05, all worse or equal: the
 * load and the +1 inline in the multiply (3), operands swapped (2), a fresh
 * `h2` (3), `h = load; h = h + 1;` (3), `h += 1` (3), and the first block's
 * `h` renamed to `g` (81, a length change). Allocation tie-break in one
 * block -- permuter run 2026-09-05: 7500 iterations, no output at all.
 * gp=0, at=0, as -G0.
 */
#include "common.h"

void func_80045C98(void) {
    u8 f;
    u16 a;
    s16 b;
    s32 h;

    f = 0;
    if (*(s16 *)(D_8009B45C + 0x1588) != 0) {
        *(u16 *)(D_8009B45C + 0x1586) =
            *(u16 *)(D_8009B45C + 0x1586) + *(u16 *)(D_8009B45C + 0x1588);
        f = 1;
        if (D_8009B45C[0x158A] >= *(s16 *)(D_8009B45C + 0x1586)) {
            if (*(s16 *)(D_8009B45C + 0x1588) < 0) {
                *(s16 *)(D_8009B45C + 0x1588) = 0;
                *(u16 *)(D_8009B45C + 0x1586) = D_8009B45C[0x158A];
            }
        }
        if (*(s16 *)(D_8009B45C + 0x1586) >= D_8009B45C[0x158A]) {
            if (*(s16 *)(D_8009B45C + 0x1588) > 0) {
                *(s16 *)(D_8009B45C + 0x1588) = 0;
                *(u16 *)(D_8009B45C + 0x1586) = D_8009B45C[0x158A];
            }
        }
    }

    if (*(s16 *)(D_8009B45C + 0x1582) != 0) {
        *(u16 *)(D_8009B45C + 0x1580) =
            *(u16 *)(D_8009B45C + 0x1580) + *(u16 *)(D_8009B45C + 0x1582);
        f = 1;
        if (D_8009B45C[0x1584] >= *(s16 *)(D_8009B45C + 0x1580)) {
            if (*(s16 *)(D_8009B45C + 0x1582) < 0) {
                *(s16 *)(D_8009B45C + 0x1582) = 0;
                *(u16 *)(D_8009B45C + 0x1580) = D_8009B45C[0x1584];
            }
        }
        if ((b = *(s16 *)(D_8009B45C + 0x1580)) >= D_8009B45C[0x1584]) {
            if (*(s16 *)(D_8009B45C + 0x1582) > 0) {
                *(s16 *)(D_8009B45C + 0x1582) = 0;
                *(u16 *)(D_8009B45C + 0x1580) = D_8009B45C[0x1584];
            }
        }
    }

    if (f != 0) {
        h = *(u16 *)(D_8009B45C + 0x44);
        if (h != 0) {
            a = (u32)((h * (*(s16 *)(D_8009B45C + 0x1580) + 1)) & 0xFFFF);
            a = a >> 8;
        } else {
            a = 0;
        }
        if (a != 0) {
            h = *(s16 *)(D_8009B45C + 0x1586) + 1;
            a = (u32)((a * h) & 0xFFFF);
            b = a >> 8;
        } else {
            b = 0;
        }
        func_80049F10(b, b);
    }

    if (*(s16 *)(D_8009B45C + 0x512) != 0) {
        *(u16 *)(D_8009B45C + 0x510) =
            *(u16 *)(D_8009B45C + 0x510) + *(u16 *)(D_8009B45C + 0x512);
        if (D_8009B45C[0x49] >= *(s16 *)(D_8009B45C + 0x510)) {
            if (*(s16 *)(D_8009B45C + 0x512) < 0) {
                *(s16 *)(D_8009B45C + 0x512) = 0;
                *(u16 *)(D_8009B45C + 0x510) = D_8009B45C[0x49];
            }
        }
        if (*(s16 *)(D_8009B45C + 0x510) >= D_8009B45C[0x49]) {
            if (*(s16 *)(D_8009B45C + 0x512) > 0) {
                *(s16 *)(D_8009B45C + 0x512) = 0;
                *(u16 *)(D_8009B45C + 0x510) = D_8009B45C[0x49];
            }
        }
        func_80044DC0(*(s16 *)(D_8009B45C + 0x510));
    }
}
