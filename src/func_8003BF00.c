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

/* REPLACED THE HAND-TRANSCRIPTION WITH REAL C, 2026-08-28 (claude-w2).
   Verified 0/112 with msearch and again with verify_match.py over the full
   0x1C0 span.  The previous body was 113 raw instruction words; the header below is
   condensed from it, because two of its findings did the work here.

   BUILD FLAGS ARE NOT OPTIONAL FOR THIS UNIT.  It has no entry in
   config/unit_flags.txt, which was harmless while the body was raw machine words
   (flag-insensitive) and is NOT harmless now: this needs
       -G0 -mno-split-addresses --keep-large-ori
   G0:split measures 90/112, and without --keep-large-ori ccpsx rewrites the
   `ori v1,zero,0x8000` at 0x8003C02C to a sign-extending addiu.  A unit_flags
   line must land WITH this file or the build goes red for a reason that
   looks like a source defect (project_src_without_unit_flags_compiles_default).

   What the prior transcription's own notes got right, and I reused:
     - the computed-goto dispatch is expressible in pure C (the
       asm-volatile-label-barrier pattern from src/func_8001455C.c); its
       "gcc cannot express this" verdict had already been retracted there;
     - the func_80081DE8 block is its OWN case body reached only through the
       table, not a fall-through after the shared tail;
     - it writes directly into the passed-in struct and calls
       func_80081DE8(obj, D_8009B118), not func_80081DE8(rect, obj).
   What was still func_800738D0 there was "case-to-table-slot order is a positional
   guess" and an AND-mask register-colour residual that had eaten a $a2 pin.
   Neither survives: the table is ordinary ROM data and can simply be READ
   (0x80010224+0x13C = 0x80010360, file offset 0xB60), and it is ASCENDING,
   so case order IS source order; and the register residual was the
   -msplit-addresses flag, not colouring -- the ROM stores D_8009B0F4 through
   the gas macro `lui at,%hi` / `sw rN,%lo(at)` and gcc can never allocate
   $at.  No pin of any kind is used below. */

/* Preset selector, 6-entry jump table at D_80010224+0x13C (= 0x80010360,
   file offset 0xB60), verified against the ROM as
   {0x8003BF34, 0x8003BF5C, 0x8003BF88, 0x8003BFC8, 0x8003C044, 0x8003C084}
   -- ASCENDING, so case order is source order and the long-standing
   "case-to-table-slot order is a positional guess" caveat is resolved by
   reading the table rather than guessing it.

   Case bodies are the obj-mode-dispatch family; cases 0, 1 and 4 share the
   tail at .L8003C068 and each writes it out in full.  Object lives in
   caller-saved $a2 and the frame holds only $ra, because no arm needs the
   object after the func_80081DE8 call (same as func_8002DDFC). */

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

void func_8003BF00(struct Obj *obj, s32 sel) {
    switch (sel) {
    case 0:
        goto L8003BF34;
    case 1:
        goto L8003BF5C;
    case 2:
        goto L8003BF88;
    case 3:
        goto L8003BFC8;
    case 4:
        goto L8003C044;
    case 5:
        goto L8003C084;
    }
    return;

L8003BF34:
    obj->f1C = 0x3000;
    D_8009B0F4 &= 0xFFDCFFFF;
    obj->fC = (s32)D_800101D8;
    obj->f8 = (s32)D_800101D8;
    obj->f46 = 1;
    return;

L8003BF5C:
    D_8009B0F4 &= 0xFFDCFFFF;
    obj->f1C = 0x43000;
    obj->fC = D_80010000;
    obj->f8 = D_80010000;
    obj->f46 = 1;
    return;

L8003BF88:
    obj->fC = (s32)D_801AF000;
    obj->f8 = (s32)D_801AF000;
    obj->f1C = 0x800;
    D_8009B0F4 &= 0xFFDCFFFF;
    obj->f46 = 1;
    return;

L8003BFC8:
    obj->f30 = 0x1C0;
    obj->f32 = 0x100;
    obj->w = 0x40;
    obj->h = 0x10;
    D_8009B0F4 &= 0xFFDDFFFF;
    D_8009B0F4 |= 0x10000;
    obj->f46 = 2;
    obj->f1C = 0x8000;
    obj->f8 = D_8009B118;
    obj->fC = D_8009B118 + 0x800;
    return;

L8003C044:
    obj->f1C = 0x800;
    D_8009B0F4 &= 0xFFDCFFFF;
    obj->fC = D_8009B118;
    obj->f8 = D_8009B118;
    obj->f46 = 1;
    return;

L8003C084:
    obj->x = 0x100;
    obj->y = 0xF0;
    obj->w = 0x100;
    obj->h = 4;
    func_80081DE8(obj, (s32 *)D_8009B118);
}
