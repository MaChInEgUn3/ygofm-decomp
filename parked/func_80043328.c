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

/* Sixth member of the 4-way mode-dispatch family (func_80032184,
   func_8003BD14, func_8002FB78, func_8003C120, func_8003BA14, this).
   cases 1/2/3 all reach the shared tail at .L800434CC (D_8009B0F4 store +
   fC/f8 + f46=1); written out in full per arm, cross-jump picks the merge. */

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
extern void func_80081DE8(struct Obj *rect, s32 *data);

void func_80043328(struct Obj *obj, s32 mode) {
    switch (mode) {
    case 0:
        obj->f30 = 0x280;
        obj->f32 = 0;
        obj->w = 0x40;
        obj->h = 0x10;
        D_8009B0F4 &= 0xFFDDFFFF;
        obj->f1C = 0x18000;
        D_8009B0F4 |= 0x10000;
        obj->f46 = 2;
        obj->f8 = D_8009B118;
        obj->fC = D_8009B118 + 0x800;
        break;

    case 1:
        obj->f1C = 0x1000;
        D_8009B0F4 &= 0xFFDCFFFF;
        obj->fC = D_8009B118;
        obj->f8 = D_8009B118;
        obj->f46 = 1;
        break;

    case 2:
        obj->x = 0x200;
        obj->y = 0xF8;
        obj->w = 0x100;
        obj->h = 8;
        func_80081DE8(obj, (s32 *)D_8009B118);
        obj->f1C = 0x800;
        D_8009B0F4 &= 0xFFDCFFFF;
        obj->fC = D_8009B118 + 0x1000;
        obj->f8 = D_8009B118 + 0x1000;
        obj->f46 = 1;
        break;

    case 3:
        obj->x = 0x280;
        obj->y = 0xE8;
        obj->w = 0x10;
        obj->h = 8;
        func_80081DE8(obj, (s32 *)(D_8009B118 + 0x1000));
        obj->f1C = 0x1800;
        D_8009B0F4 &= 0xFFDCFFFF;
        obj->fC = *(s32 *)(D_800100A8 + 0x130);
        obj->f8 = *(s32 *)(D_800100A8 + 0x130);
        obj->f46 = 1;
        break;
    }
}
