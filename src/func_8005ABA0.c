/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/color_transform.c (Color_HslToRgb), profile gcc_2_8_1_g8.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
Color *func_8005ABA0(Color *out, s32 h, u16 s, u16 v, u8 lim);
Color *func_8005ABA0(Color *out, s32 h, u16 s, u16 v, u8 lim)
{
    u32 ch[3];
    Color t;
    s32 m;
    s32 i0;
    s32 ja;
    s32 jb;
    s32 w;
    s32 x;

    m = (h / (1 << 12 )  + 1) % 6 ;
    i0 = m / 2;
    if (m & 1) {
        jb = (i0 + 1) % 3;
        ja = (i0 + 2) % 3;
    } else {
        ja = (i0 + 1) % 3;
        jb = (i0 + 2) % 3;
    }

    if (s < ((1 << 12 )  / 2)  + 1) {
        ch[ja] = (s * ((1 << 12 )  - v) / (1 << 12 ) ) * lim;
        ch[i0] = (s << 1) * lim - ch[ja];
    } else {
        ch[i0] = (s * ((1 << 12 )  - v) / (1 << 12 )  + v) * lim;
        ch[ja] = (s << 1) * lim - ch[i0];
    }

    x = (h + (1 << 12 ) ) % (6  * (1 << 12 ) )  -
        i0 * (2 * (1 << 12 ) );
    w = x - (1 << 12 ) ;
    if (w < 0) {
        w = (1 << 12 )  - x;
    }
    ch[jb] = (ch[i0] - ch[ja]) * w / (1 << 12 )  + ch[ja];

    ch[0] = (ch[0] + ((1 << 12 )  / 2) ) / (1 << 12 ) ;
    ch[1] = (ch[1] + ((1 << 12 )  / 2) ) / (1 << 12 ) ;
    ch[2] = (ch[2] + ((1 << 12 )  / 2) ) / (1 << 12 ) ;
    t.r = ch[0] < 0x100 ? ch[0] : 0xFF;
    t.g = ch[1] < 0x100 ? ch[1] : 0xFF;
    t.b = ch[2] < 0x100 ? ch[2] : 0xFF;
    *out = t;
    return out;
}
