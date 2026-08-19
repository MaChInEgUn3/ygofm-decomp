#include "common.h"

/* The bias-and-shift triples are signed divisions, not shifts. A
 * `bgez / addiu 0xFFF / sra 12` around a value is exactly what gcc emits
 * for `/ 4096`, and writing it that way is the whole tail -- hand-expanding
 * it into an if and a shift is ten differences and puts the shifts in the
 * wrong delay slots. Same reading as the `/ 4` (bgez, +3, sra 2) in the
 * first block.
 *
 * The other shape is the 0x400 store written BEFORE the division that also
 * uses 0x400: written after, gcc keeps the dividend alive and stores it
 * instead of materialising the constant a second time, which is what retail
 * does. */

void func_8003A990(u8 *p) {
    s32 d;
    s32 t;
    s32 c;
    s32 dx;
    s32 dy;

    if (func_80039F1C(p) == 0) {
        *(s16 *)(p + 0x48) = 0x400;
        d = 0x400 / *(s16 *)(p + 0x44);
        *(s16 *)(p + 0x4A) = d;
        if (d >= 0) {
            *(s16 *)(p + 0x48) = 0;
        }
        *(s16 *)(p + 0x44) = *(u16 *)(p + 0x40) - *(u16 *)(p + 0x34);
        *(s16 *)(p + 0x46) = *(u16 *)(p + 0x42) - *(u16 *)(p + 0x36);
    }

    t = *(u16 *)(p + 0x48) + *(u16 *)(p + 0x4A);
    *(s16 *)(p + 0x48) = t;

    if ((u16)(t - 1) >= 0x3FF) {
        func_8003A95C(p, *(s16 *)(p + 0x40), *(s16 *)(p + 0x42));
        p[0x33] = 0;
    } else {
        c = func_80086770((s16)t);
        dx = c * *(s16 *)(p + 0x44) / 4096;
        dy = c * *(s16 *)(p + 0x46) / 4096;
        if (*(s16 *)(p + 0x4A) < 0) {
            dx = *(s16 *)(p + 0x44) - dx;
            dy = *(s16 *)(p + 0x46) - dy;
        }
        func_8003A95C(p, (s16)(*(u16 *)(p + 0x40) - dx), (s16)(*(u16 *)(p + 0x42) - dy));
    }
}
