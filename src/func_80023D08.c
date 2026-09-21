/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_80023D08.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern s16 D_800907AC[2 ][2][4];
extern DuelFieldPosition
    D_80090800[2 ][20 ];
extern u8 D_8009B1D5;
void func_8003FEE0(u32);
void func_800429D8(DisplayObjectVelocity *object);
extern u16 D_8009AF20[2];
void func_80022D94(s32 frames, s32 x, s32 z, s32 y, s32 value);
extern u16 D_8009B162;
void func_80023D08(GridCursor *o, s32 dir);
void func_8002348C(void);
void func_80023D08(GridCursor *o, s32 dir) {
    DuelFieldCursorObject *d;
    s32 pos;
    s32 shift;
    s32 index;
    s32 q;

    d = o->object;
    if (o->flags & 0x80) {
        if (D_8009B162 != 0) {
            return;
        }
        func_8002348C();
        o->flags &= 0x3F;
        func_8003FEE0(6);
        return;
    }
    if (dir < 0) {
        return;
    }
    if (dir & 1) {
        pos = o->row + 1;
        if (dir & 2) {
            pos = o->row - 1;
        }
        if (pos >= o->max_row) {
            return;
        }
        if (pos < o->min_row) {
            return;
        }
        shift = 0x10;
        if ((o->row ^ pos) != 3) {
            shift = 8;
        }
        func_80022D94(shift, 0x14E, 0x3FE, D_8009AF20[D_8009B1D5],
                      D_800907AC[D_8009B1D5][o->page][pos]);
        o->row = pos;
        index = pos * 5  + o->col;
        func_800429D8((DisplayObjectVelocity *)d);
        d->moving = 0;
        d->steps = shift;
        d->target_x = d->x;
        d->target_y = D_80090800[D_8009B1D5][index].y;
        q = ((d->target_y - d->y) << 8) / shift;
        D_8009B162 = 0x50;
        d->step_y = q;
        o->flags |= 0xC0;
    } else {
        pos = o->col + 1;
        if (dir & 2) {
            pos = o->col - 1;
        }
        if ((u32)pos >= 5 ) {
            return;
        }
        o->col = pos;
        index = o->row * 5  + (s8)pos;
        func_800429D8((DisplayObjectVelocity *)d);
        shift = 8;
        d->steps = shift;
        d->moving = 0;
        d->target_x = D_80090800[D_8009B1D5][index].x;
        D_8009B162 = 0x40;
        d->target_y = d->y;
        d->step_x = ((d->target_x - d->x) << shift) / shift;
        o->flags |= 0x80;
    }
}
