/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/color_transform.c (Color_TintBgr555Pixel), profile gcc_2_8_1_g8.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
HsvT *func_8005A98C(HsvT *out, u8 r, u8 g, u8 b, u8 lim);
Color *func_8005ABA0(Color *out, s32 h, u16 s, u16 v, u8 lim);
s32 func_8005AE68(u16 color, s32 flags, u16 scale);
HsvT *func_8005A98C(HsvT *out, u8 r, u8 g, u8 b, u8 lim);
Color *func_8005ABA0(Color *out, s32 h, u16 s, u16 v, u8 lim);
s32 func_8005AE68(u16 color, s32 flags, u16 scale)
{
    Color packed;
    HsvT hsv;
    Color out;
    u8 lim;
    s32 sector;
    u8 hue;
    s32 inverted;
    s32 gray;

    if (color == 0) {
        return 0;
    }

    inverted = flags & 0x8 ;
    sector = flags & 0x7 ;
    gray = ((u8)sector == 6 );
    func_8005A98C(
        &hsv,
        color & ((1 << 5 ) - 1) ,
        (color >> 5  ) & ((1 << 5 ) - 1) ,
        (color >> (2 * 5 ) ) & ((1 << 5 ) - 1) ,
        ((1 << 5 ) - 1) );

    lim = ((1 << 5 ) - 1) ;
    if ((u8)sector < 7 ) {
        hue = sector;
        if (inverted) {
            hue = (hue + 6  / 2) % 6 ;
        }
        hsv.h = hue << 12 ;
    }

    if (gray) {
        hsv.v = 0;
    } else {
        hsv.v = (hsv.v * scale) / (1 << 12 ) ;
    }

    func_8005ABA0(&out, hsv.h, hsv.s, hsv.v, ((1 << 5 ) - 1) );

    if (inverted) {
        out.r = lim - out.r;
        out.g = lim - out.g;
        out.b = lim - out.b;
    }

    out.r = out.r ? out.r : 1;
    out.g = out.g ? out.g : 1;
    out.b = out.b ? out.b : 1;
    packed = out;
    return (packed.r & ((1 << 5 ) - 1) ) |
           ((packed.g & ((1 << 5 ) - 1) ) << 5  ) |
           ((packed.b & ((1 << 5 ) - 1) ) << (2 * 5 ) ) |
           (color & (1 << (3 * 5 )) );
}
