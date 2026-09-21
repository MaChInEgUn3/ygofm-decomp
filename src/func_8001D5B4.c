/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_8001D5B4.c, profile gcc_2_8_1_g8.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
extern s8 D_8009B160;
extern s8 D_8009B1D6;
extern s8 D_8009B1D7;
s32 func_80024088(DuelFieldCursor *cursor, s8 dir);
extern u16 D_8009B162;
s32 func_8001D5B4(DuelFieldCursor *cursor)
{
    if (D_8009B162 != 0) { D_8009B160 = -1; return 1; }
    if (func_80024088(cursor, D_8009B160) != 0) { return 1; }
    D_8009B160 = -1;
    if (D_8009B1D7 != cursor->row) {
        D_8009B160 = 1;
        if (D_8009B1D7 < cursor->row) { D_8009B160 = 3; }
        return 1;
    } else if (D_8009B1D6 != cursor->col) {
        D_8009B160 = 0;
        if (D_8009B1D6 < cursor->col) { D_8009B160 = 2; }
        return 1;
    } else {
        return 0;
    }
    return 1;
}
