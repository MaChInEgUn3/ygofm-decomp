#include "common.h"

/* Resets the camera matrix and the two shadow blocks. Two struct copies
 * with different alignments: the 32-byte one is four aligned lw/sw pairs,
 * the 8-byte gp-relative one is lwl/lwr because that group is bytes and
 * halfwords with no word alignment to claim. D_8009B478 is stored as a
 * HALFWORD here though it is declared u8, hence the lvalue cast. */

typedef struct {
    s32 w[8];
} Mtx32;

typedef struct {
    u8 b[8];
} Blk8;

void func_800530C4(void) {
    u8 *n;
    s32 r;

    D_8009AF90 = 0;
    D_8009AF8E = 0;
    D_8009B47C = 0;
    *(s16 *)&D_8009B478 = 0;
    D_8009B47A = 0xC00;
    func_800857C0(D_8009AF8C);

    *(s32 *)D_800F56F0 = 0;
    *(s32 *)(D_800F56F0 + 4) = -0x15E;
    *(s32 *)(D_800F56F0 + 8) = -0x4B0;
    *(s32 *)(D_800F56F0 + 0xC) = 0;
    *(s32 *)(D_800F56F0 + 0x10) = -0x15E;
    *(s32 *)(D_800F56F0 + 0x14) = 0;
    *(s32 *)(D_800F56F0 + 0x18) = 0;
    *(s32 *)(D_800F56F0 + 0x1C) = 0;

    func_80058434(1, 0x80, -0x55, 0x4B0, 0);
    func_8008AD50(D_800F56F0);

    n = D_800F56A0;
    *(s16 *)(n + 0x48) = 0;
    *(s16 *)(n + 0x46) = 0;
    *(s16 *)(n + 0x44) = 0;
    *(s32 *)(n + 0x20) = 0;
    *(s32 *)(n + 0x1C) = 0;
    *(s32 *)(n + 0x18) = 0;
    *(s32 *)(n + 0x4C) = 0;
    func_80088E50(n + 0x44, n + 4);
    *(s32 *)n = 0;

    *(Mtx32 *)D_800F5710 = *(Mtx32 *)D_800F56F0;
    *(Blk8 *)&D_8009B480 = *(Blk8 *)&D_8009B478;

    func_8004E7B0(1);
    r = func_8005F174();
    if (r != 1 || func_8005F18C() != r) {
        func_80052D2C(0, 0, 0, 0);
    }
    func_8005FAE4();
}
