/* PARKED CANDIDATE PORTED from Unchiga's tree (docs/MERGE_UNCHIGA.md).
 * Installed here because HIS base is closer than the one this tree
 * reached: the counts are in PARKED.txt. Measure it with the flags on
 * the next line -- they are his unit's, and try_func's default flags
 * report a different number.
 * FLAGS: -G0 -mno-split-addresses
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

/* 4-way mode dispatch (0/1/2/3), sibling of func_80032184 (same switch tree,
   same D_8009B0F4 masks, same D_8009B118 pointer).  m2c mis-decodes the
   internal jumps: 0x0800EFA9 is `j .L8003BEA4` (this function's own
   epilogue) and 0x0800EFA4 is `j .L8003BE90` (the case1/case3 shared tail);
   neither is a call.  0x24428000 is `addiu v0,v0,%lo(D_801A8000)`.

   Applying the three findings from func_80032184 (see that sketch): func_80073900
   every shared tail out IN FULL in each arm and let gcc's cross-jump pass
   pick the merge point, keep D_8009B0F4 volatile so each func_800738F0-modify-func_80073900
   reloads, and match case0's field-store order across the arms. */

struct Obj {
    s16 x;
    s16 y;
    s16 w;
    s16 h;
    s32 f8;
    s32 fC;
    char pad1[0x1C - 0x10];
    s32 f1C;
    char pad2[0x30 - 0x20];
    s16 f30;
    s16 f32;
    char pad3[0x46 - 0x34];
    u8 f46;
};

extern volatile u32 D_8009B0F4;
extern s32 D_8009B118;
extern u8 D_800100A8[];
extern u8 D_801A8000[];
extern void func_80081DE8(struct Obj *rect, s32 *data);

void func_8003BD14(struct Obj *obj, s32 mode) {
    switch (mode) {
    case 0:
        obj->f30 = 0x300;
        obj->f32 = 0x100;
        obj->w = 0x40;
        obj->h = 0x10;
        D_8009B0F4 &= 0xFFDDFFFF;
        D_8009B0F4 |= 0x10000;
        obj->f46 = 2;
        obj->f1C = 0x20000;
        obj->f8 = D_8009B118;
        obj->fC = D_8009B118 + 0x800;
        break;

    case 1:
        obj->f1C = 0x2000;
        D_8009B0F4 &= 0xFFDCFFFF;
        obj->fC = D_8009B118;
        obj->f8 = D_8009B118;
        obj->f46 = 1;
        break;

    case 2:
        obj->x = 0x100;
        obj->y = 0xF0;
        obj->w = 0x100;
        obj->h = 0x10;
        func_80081DE8(obj, (s32 *)D_8009B118);
        obj->fC = (s32)D_801A8000;
        obj->f8 = (s32)D_801A8000;
        obj->f1C = 0x1800;
        D_8009B0F4 &= 0xFFDCFFFF;
        obj->f46 = 1;
        break;

    case 3:
        obj->f1C = 0x7800;
        D_8009B0F4 &= 0xFFDCFFFF;
        obj->fC = *(s32 *)(D_800100A8 + 0x130);
        obj->f8 = *(s32 *)(D_800100A8 + 0x130);
        obj->f46 = 1;
        break;
    }
}
