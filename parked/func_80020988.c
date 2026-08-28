#define D_8009B394_SIZED_VOLATILE
#define D_8009B398_SIZED_VOLATILE
#include "common.h"

s32 func_80020988(void) {
    u8 *q;
    s32 one;
    s32 b;
    s32 c;
    s32 v;

    if ((D_8009B152 & 0x80) == 0) {
        D_8009B152 = D_8009B152 | 0x80;
        one = 1;
        q = func_800400AC(func_8004002C(), 2);
        b = 0xB;
        c = 0x20C;
        func_800404CC(q, *(s16 *)(D_8009B1CC + 0x30) - 8,
                      *(s16 *)(D_8009B1CC + 0x32) + 0x1E, 3, one, 2, b, c);
        func_80042918(q);
        func_800428EC(q, 0xA);
        *(u16 *)(q + 8) = *(u16 *)(q + 8) | 0x28;
        D_8009B188 = q;

        q = func_800400AC(func_8004002C(), 2);
        func_800404CC(q, *(s16 *)(D_8009B1CC + 0x30) + 0x3C,
                      *(s16 *)(D_8009B1CC + 0x32) + 0x1E, 3, one, 0, b, c);
        func_80042918(q);
        func_800428EC(q, 0xA);
        *(u16 *)(q + 8) = *(u16 *)(q + 8) | 0x28;
        D_8009B18C = q;
        return 0;
    }

    q = D_8009B1CC;

    if ((D_8009B152 & 0x40) != 0) {
        v = q[0x21] + q[0x60];
        *(u16 *)(q + 8) = *(u16 *)(q + 8) | 4;
        q[0x21] = v;
        if ((v & 0x7F) != 0) {
            return 0;
        }
        if ((v & 0xFF) == 0) {
            *(u16 *)(q + 8) = *(u16 *)(q + 8) & 0xFFFB;
        }
        D_8009B152 = D_8009B152 & 0xBF;
        return 0;
    }

    if ((D_8009B394[0] & 0xA000) != 0) {
        *(s16 *)(q + 0x60) = 0x10;
        if ((D_8009B394[0] & 0x2000) != 0) {
            *(s16 *)(q + 0x60) = -0x10;
        }
        D_8009B152 = D_8009B152 | 0x40;
        return 0;
    }

    if ((D_8009B398[0] & 0xE0) == 0) {
        return 0;
    }
    func_8004036C((s32)D_8009B188);
    func_8004036C((s32)D_8009B18C);
    if ((D_8009B398[0] & 0x20) != 0) {
        return -1;
    }
    if (q[0x21] == 0) {
        return 1;
    }
    return 2;
}
