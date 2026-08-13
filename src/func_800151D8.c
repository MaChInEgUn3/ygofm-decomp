#define D_8009B0D8_IS_SCALAR
#include "common.h"

/* A fade that walks a 30-byte mirror pair from both ends. Three shapes.
 *
 * The two clamp bounds are named AFTER x is assigned, not before and not
 * inline: inline they share x's register class and every register in the
 * body rotates (28 differences), named before x they are 66. The first
 * store's address is named and the second is not -- retail computes both
 * addresses before either store, and the asymmetry is what orders them
 * (8 differences to a match; naming both is 4, naming neither is 8).
 *
 * D_8009B0D8 takes its real scalar declaration and an assembler -G0.
 * There is no %gp_rel in the function, so recipe branch 1 applies and any
 * -G is free -- but the reason to spend it is a delay slot, not the
 * addressing: both forms assemble to lui/lw through the same register, and
 * only the scalar is ONE instruction to gcc's delay-slot filler, so the
 * nop retail leaves in front of it survives.
 */

void func_800151D8(void) {
    u8 *p = D_800E9EC8;
    s32 step = p[7];
    s32 h;
    s32 x;
    s32 i;
    s32 k;
    u8 *a;
    s32 lo;
    s32 hi;

    if (p[4] < p[5]) {
        h = *(s16 *)(p + 8);
        for (i = 0xE; i >= 0; i--) {
            x = h - step;
            h = x;
            lo = p[4];
            if (x < lo) {
                x = lo;
            }
            hi = p[5];
            if (hi < x) {
                x = hi;
            }
            a = p + i;
            k = 0x1D - i;
            a[0xA] = x;
            (p + k)[0xA] = x;
        }
        *(s16 *)(p + 8) = *(u16 *)(p + 8) + step * D_8009B0D8;
    } else {
        h = *(s16 *)(p + 8);
        for (i = 0; i < 0xF; i++) {
            x = h + step;
            h = x;
            lo = p[5];
            if (x < lo) {
                x = lo;
            }
            hi = p[4];
            if (hi < x) {
                x = hi;
            }
            a = p + i;
            k = 0x1D - i;
            a[0xA] = x;
            (p + k)[0xA] = x;
        }
        *(s16 *)(p + 8) = *(u16 *)(p + 8) - step * D_8009B0D8;
    }

    if (x == p[5]) {
        p[4] = x;
    }
}
