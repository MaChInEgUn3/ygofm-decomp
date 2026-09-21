/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_80023D08.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern s16 D_800907AC[2 ][2][4];
typedef struct {
    s16 x;
    s16 y;
} DuelFieldPosition;
extern DuelFieldPosition
    D_80090800[2 ][20 ];
extern u8 D_8009B1D5;
void func_8003FEE0(u32);
typedef struct {
    u8 pad_00[0x30];
    s16 x;
    s16 y;
    s16 z;
    s16 velocity_x;
    s16 velocity_y;
    s16 velocity_z;
    u8 pad_3C[0x26];
    u8 fraction_x;
    u8 fraction_y;
    u8 fraction_z;
} DisplayObjectVelocity;
void func_800429D8(DisplayObjectVelocity *object);
extern u16 D_8009AF20[2];
void func_80022D94(s32 frames, s32 x, s32 z, s32 y, s32 value);
extern u16 D_8009B162;
typedef struct {
    u8 pad00[0x28];
    s16 x;
    s16 y;
    s16 target_x;
    s16 target_y;
    u8 pad30[6];
    u16 step_x;
    u8 pad38[2];
    u16 step_y;
    u8 pad3C[0x24];
    u16 steps;
    u8 pad62[0xA];
    u8 moving;
} DuelFieldCursorObject;
typedef struct {
    u8 pad00[4];
    DuelFieldCursorObject *object;
    u8 pad08[7];
    s8 col;
    s8 row;
    s8 min_row;
    s8 max_row;
    u8 pad13[5];
    u8 page;
    u8 flags;
} GridCursor;
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
