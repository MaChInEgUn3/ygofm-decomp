/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_80049FB4.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
s32 func_80049FB4(s32 note_high, s32 note_low, s32 base, s32 offset);
extern u16 D_80010834[12][128];
s32 func_80049FB4(s32 note_high, s32 note_low, s32 base, s32 offset)
{
    s16 fine;
    s16 col;
    s16 diff;
    s16 down;
    s32 note;

    fine = note_low + offset;
    note = note_high + fine / 128;
    col = fine % 128;
    diff = note - base;
    if (diff >= 0) {
        return (u16)(D_80010834[diff % 12][col] << (diff / 12));
    }
    down = -diff;
    return (u16)(D_80010834[(12 - (s16)(down % 12)) % 12][col] >>
                 ((down + 11) / 12));
}
