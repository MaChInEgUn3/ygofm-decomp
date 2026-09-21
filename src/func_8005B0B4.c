/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/color_transform.c, profile gcc_2_8_1_g8.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
Color *func_8005B0B4(
    Color *out, u8 r, u8 g, u8 b, s32 flags, u16 scale, u8 lim
)
{
    HsvT hsv;
    Color c;
    s32 idx;
    s32 inv;
    s32 flat;
    u8 k;

    inv = flags & 0x8 ;
    idx = flags & 0x7 ;
    flat = ((u8)idx == 6 );

    Color_RgbToHsl_void(&hsv, r, g, b, lim);

    if ((u8)idx < 7 ) {
        k = idx;
        if (inv) {
            k = (k + 6  / 2) %
                6 ;
        }
        hsv.h = k << 12 ;
    }

    if (flat) {
        hsv.v = 0;
    } else {
        hsv.v = hsv.v * scale / (1 << 12 ) ;
    }

    Color_HslToRgb_wide(&c, hsv.h, hsv.s, hsv.v, lim);

    if (inv) {
        c.r = lim - c.r;
        c.g = lim - c.g;
        c.b = lim - c.b;
    }

    c.r = c.r ? c.r : 1;
    c.g = c.g ? c.g : 1;
    c.b = c.b ? c.b : 1;

    *out = c;
    return out;
}
