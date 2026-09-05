/* PORTED from Unchiga's tree (docs/MERGE_UNCHIGA.md) and finished here:
 * parked at 6 until the D_800101D8 read was written through splat's interior
 * symbol instead of D_800100A8 + 0x130, and the computed goto was rewritten
 * as a switch so build.py can place the compiled jump table in splat's rodata
 * (the raw table symbol does not link). Assembler -G0, default cc flags.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

/* The obj-mode-dispatch family again, but reached through a 5-entry jump
   table at D_80010224+0x124 instead of a compare tree.  Table verified
   against the ROM (file offset 0xB48): {0x8003B840, 0x8003B8B4, 0x8003B8DC,
   0x8003B944, 0x8003B970} -- ascending, so case order is source order.

   The dispatcher is a switch of gotos to the labelled arms.  The internal jumps
   0x0800EE6B / 0x0800EE65 / 0x0800EE6A are `j` to this function's own labels
   (.L8003B9AC epilogue, .L8003B994 shared tail, .L8003B9A8 f46 store), not
   calls; 0x2442F000 is addiu v0,v0,%lo(D_801AF000).  Every shared tail is
   written out in full per arm, as for the rest of the family. */

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
extern s32 D_80010000;
extern u8 D_800100A8[];
extern u8 *D_800101D8;
extern u8 D_801AF000[];
extern void func_80081DE8(struct Obj *rect, s32 *data);

void func_8003B808(struct Obj *obj, s32 sel) {
    switch (sel) {
    case 0:
        goto L8003B840;
    case 1:
        goto L8003B8B4;
    case 2:
        goto L8003B8DC;
    case 3:
        goto L8003B944;
    case 4:
        goto L8003B970;
    }
    return;

L8003B840:
    obj->f32 = 0x100;
    obj->f30 = 0;
    obj->w = 0x40;
    obj->h = 0x10;
    D_8009B0F4 &= 0xFFDDFFFF;
    obj->f1C = 0x10000;
    D_8009B0F4 |= 0x10000;
    obj->f46 = 2;
    obj->f8 = D_8009B118;
    obj->fC = D_8009B118 + 0x800;
    return;

L8003B8B4:
    obj->f1C = 0x800;
    D_8009B0F4 &= 0xFFDCFFFF;
    obj->fC = D_8009B118;
    obj->f8 = D_8009B118;
    obj->f46 = 1;
    return;

L8003B8DC:
    obj->x = 0;
    obj->y = 0xF0;
    obj->w = 0x100;
    obj->h = 4;
    func_80081DE8(obj, (s32 *)D_8009B118);
    obj->fC = (s32)D_801AF000;
    obj->f8 = (s32)D_801AF000;
    obj->f1C = 0x800;
    D_8009B0F4 &= 0xFFDCFFFF;
    obj->f46 = 1;
    return;

L8003B944:
    D_8009B0F4 &= 0xFFDCFFFF;
    obj->f1C = 0x18000;
    obj->fC = D_80010000;
    obj->f8 = D_80010000;
    obj->f46 = 1;
    return;

L8003B970:
    obj->f1C = 0x2800;
    D_8009B0F4 &= 0xFFDCFFFF;
    obj->fC = (s32)D_800101D8;
    obj->f8 = (s32)D_800101D8;
    obj->f46 = 1;
}
