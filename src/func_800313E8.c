#include "common.h"

/* Three-way state step on the +0x6C flags. The `* 512` uses the value
 * still in the register with an (s16) cast, not a re-read of +0x60: gcc
 * folds `((t << 16) >> 16) << 9` into retail's `sll 16 / sra 7`, where a
 * fresh `lh` costs a reload, a nop and a copy in each of the two arms. */

void func_800313E8(u8 *p) {
    s32 v;
    s32 t;

    if (func_80042B98(p) == 0) {
        *(s32 *)(p + 0x44) = 0;
        *(s16 *)(p + 0x60) = 0;
        *(s32 *)(p + 4) = *(s32 *)(p + 4) & 0xF7FFFFFF;
        p[0x6C] = p[0x6C] | 0x40;
        func_8003FEE0(0xA);
    }

    v = p[0x6C];

    if ((v & 0x40) != 0) {
        t = *(u16 *)(p + 0x60) + 1;
        *(s16 *)(p + 0x60) = t;
        *(s16 *)(p + 0x46) = (s16)t * 512;
        *(s16 *)(p + 0x44) = (s16)t * 512;
        if (*(s16 *)(p + 0x60) >= 8) {
            func_800429D8(p);
            *(s16 *)(p + 0x36) = ((*(s16 *)(p + 0x18) - *(s16 *)(p + 0x30)) << 8) / 12;
            p[0x6C] = p[0x6C] & 0xBF;
            *(s16 *)(p + 0x60) = 0xC;
            *(s16 *)(p + 0x38) = ((*(s16 *)(p + 0x1A) - *(s16 *)(p + 0x32)) << 8) / 12;
        }
    } else if ((v & 0x20) != 0) {
        t = *(u16 *)(p + 0x60) - 1;
        *(s16 *)(p + 0x60) = t;
        *(s16 *)(p + 0x46) = (s16)t * 512;
        *(s16 *)(p + 0x44) = (s16)t * 512;
        if (*(s16 *)(p + 0x60) == 0) {
            func_8004036C((s32)p);
        }
    } else {
        func_80042A78(p);
        t = *(u16 *)(p + 0x60) - 1;
        *(s16 *)(p + 0x60) = t;
        if (*(s16 *)(p + 0x60) <= 0) {
            *(s32 *)(p + 0x30) = *(s32 *)(p + 0x18);
            *(s16 *)(p + 0x60) = 8;
            p[0x6C] = p[0x6C] | 0x20;
        }
    }
}
