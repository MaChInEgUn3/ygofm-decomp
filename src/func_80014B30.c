/* PORTED from Unchiga's decompilation of SLUS_014.11, shared 2026-08-30.
 * His C, his comments; the identifiers are rewritten to this repo's address
 * form and nothing else was touched. Verified the only way that counts here:
 * tools_src/build.py rebuilds the retail image byte-for-byte with this in it.
 *
 * Self-contained by design -- it keeps his declarations rather than ours,
 * because a declaration is a codegen input and his are what this C matched
 * under. See docs/MERGE_UNCHIGA.md and tools_src/install_ported.py.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

/* Applies one of three display-mode setups to an object from the shared
   D_801D4200 record, then optionally fires the D_8009B128 callback.
   mode 0 does the full setup (unless the record's f14 is clear, which only
   marks f40 and falls into the mode-1 path); mode 1 does the reduced setup
   and clears two bits of D_8009B0F4; mode 2 goes straight to the callback.
   Anything else returns.  Either setup ends by mirroring its source field
   into f1C, and a negative value is rescaled to -(v << 11).

   Written with explicit gotos because three blocks have MORE THAN ONE
   predecessor, which if/else cannot express:
     `shared` is entered by mode==1 from the dispatch AND by fall-through
        from the f14==0 arm of mode 0;
     `fixup`  is entered by a jump from the mode-0 arm AND by fall-through
        from `shared`;
     `tail`   is entered by mode==2 from the dispatch AND by the f18==0
        test inside `shared`.
   The dispatch arms are also ordered deliberately: testing `mode >= 2`
   first and jumping AWAY to the mode-2 check keeps the mode-0 body inline,
   which is target's layout; the natural if/else nesting func_8008FAF0 the arms the
   other way round.  `t` is one local because both paths into `fixup` load
   their own value into the same register and store it to f1C first. */

struct D {
    u8 pad0[0xC];
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
};

struct Obj {
    u8 pad0[8];
    s32 f8;
    s32 fC;
    u8 pad10[0x1C - 0x10];
    s32 f1C;
    u8 pad20[0x30 - 0x20];
    s32 f30;
    u8 pad34[0x40 - 0x34];
    s32 f40;
    u8 pad44[0x46 - 0x44];
    u8 f46;
};

extern struct D D_801D4200;
extern s32 D_8009B118;
extern u32 D_8009B0F4;
extern void (*D_8009B128)(void);

void func_80014B30(struct Obj *obj, s32 mode) {
    struct D *d;
    s32 t;
    s32 g;
    s32 v;
    void (*fp)(void);

    d = &D_801D4200;

    if (mode == 1) {
        goto shared;
    }
    if (mode >= 2) {
        goto hi;
    }
    if (mode == 0) {
        goto work;
    }
    return;

hi:
    if (mode == 2) {
        goto tail;
    }
    return;

work:
    if (d->f14 == 0) {
        obj->f40 = 2;
        goto shared;
    }
    obj->f46 = 3;
    g = D_8009B118;
    obj->f8 = g;
    obj->fC = g + 0x800;
    obj->f30 = d->fC;
    t = d->f14;
    obj->f1C = t;
    goto fixup;

shared:
    if (d->f18 == 0) {
        goto tail;
    }
    v = d->f10;
    D_8009B0F4 = D_8009B0F4 & 0xFFDCFFFF;
    obj->fC = v;
    obj->f8 = v;
    obj->f46 = 1;
    t = d->f18;
    obj->f1C = t;

fixup:
    if (t < 0) {
        obj->f1C = -(t << 11);
    }
    return;

tail:
    fp = D_8009B128;
    if (fp != 0) {
        fp();
    }
}
