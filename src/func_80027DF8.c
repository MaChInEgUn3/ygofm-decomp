/* PORTED from Unchiga's decompilation of SLUS_014.11, shared 2026-08-30.
 * His C, his comments; the identifiers are rewritten to this repo's address
 * form and nothing else was touched. Verified the only way that counts here:
 * tools_src/build.py rebuilds the retail image byte-for-byte with this in it.
 *
 * Self-contained by design -- it keeps his declarations rather than ours,
 * because a declaration is a codegen input and his are what this C matched
 * under. See docs/MERGE_UNCHIGA.md and tools_src/install_ported.py.
 */
//@ target 185F8 428
//@ sym func_800170C8=0x800170C8
//@ sym D_801A7AD8=0x801A7AD8
//@ sym D_801D4244=0x801D4244
//@ sym D_800E9FF0=0x800E9FF0
//@ sym D_8015C424=0x8015C424
//@ sym D_801A7E20=0x801A7E20
//@ flags G0:split
/* func_80027DF8 -- MATCHED 0/266, "-G0 -msplit-addresses".  Builds a card
   display list for duelist `who` into `out`: a run of 12-byte entries drawn
   from four sources, terminated by a zero id.

   Sections 1 and 2 walk five 0x1C records each (at base+0x8C and base+0x118,
   base = &D_801A7AD8[who * 0x1A4]); section 3 walks the five slot indices in
   D_800E9FF0[who].slots[]; section 4 runs D_800E9FF0[who].count..0x27 over
   D_801A7E20.

   FIVE THINGS THAT GOT THIS TO ZERO, for whoever meets the same shapes:

   1. ONE record pointer, not two.  gcc splits `struct Rec *` into two
      induction variables on its own -- one at +0 (obj), one at +0xC
      (id/flags) -- which is exactly the s4/s0 pair the target uses.  Handing
      it two pointers instead makes it split one of them AGAIN into three and
      costs a whole saved register (245 diffs).

   2. ONE counter shared by all four loops, including section 4's count.
      Per-loop counters have short live ranges and land at s4; the shared one
      outranks `out` and `rec` and lands at s2, like the target (226 -> 217).

   3. `tbl[(s16) x - 1]` FOLDS the -1 into a -4(...) load displacement; the
      target materialises `addiu v0,v0,-1`.  Writing the byte offset with an
      explicit shift -- `*(s32 *)((((s16) x - 1) << 2) + (u32) tbl)` -- defeats
      the fold (217 -> 123).  The `(u32)` cast rather than `(u8 *)` also fixes
      the addu operand order (123 -> 119).

   4. A local that is BOTH stored to a u16 field and used as an index gets
      loaded `lhu` and then sign-extended with sll/sra.  Declaring it `s32`
      makes gcc emit a single `lh` (81 -> 29) -- but ONLY in section 4;
      section 3 wants `s16` there, so the two loops genuinely differ.

   5. The big one, and the reason this took so long: reaching 0x801A7E20 as
      `D_8015C424 + 0x4B9FC`.  Every pointer/integer form of that constant
      offset gets folded into the symbol, giving `lui 0x801a; addiu 0x7e20`.
      The target instead keeps the symbol and splits the offset the way
      gcc's MIPS address legitimiser does -- `lui 0x4; ori 0x8000` plus a
      0x39FC load displacement (0x4B9FC & ~0x7FFF, 0x4B9FC & 0x7FFF).  That
      only happens when the offset is a STRUCT MEMBER offset on a symbol
      declared as the struct itself:

          struct Blob { u8 pad0[0x4B9FC]; struct R6 cards[1]; };
          extern struct Blob D_8015C424;
          ... D_8015C424.cards[n].id

      An `__asm__ ("" : "=r"(p) : "0"(p))` launder of a `struct Blob *` gets
      to 7 diffs but pins the base's materialisation too early; the plain
      struct symbol above is both simpler and exact.

   NOTE: D_8015C424 and D_801A7E20 are NOT yet in config/symbol_addrs.txt.
   struct Blob is a matching device for the offset split, not a claim about
   the real object's layout. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

struct Obj {
    u8  pad0[0x68];
    u8  f68;    /* +0x68 */
};

/* 12-byte output entry.  Sections 1/2 fill through +9; section 3 also fills
   +A; section 4 also fills +B. */
struct Ent {
    u16 id;      /* +0 */
    s16 x;       /* +2 */
    s16 y;       /* +4 */
    u16 flags;   /* +6 */
    u8  b8;      /* +8 */
    s8  b9;      /* +9 */
    s8  bA;      /* +A */
    u8  bB;      /* +B */
};

/* base+0x8C and base+0x98 are two views 0xC apart into one 0x1C-stride
   record array; the target walks them as two separate pointers. */
/* One 0x1C record.  gcc splits this into two induction variables by itself:
   one at +0 for obj, one at +0xC for id/flags -- which is exactly the s4/s0
   pair the target uses. */
struct Rec {         /* 0x1C */
    struct Obj *obj; /* +0x00 */
    u8  pad4[8];
    u16 id;          /* +0x0C */
    u8  padE[8];
    u16 flags;       /* +0x16 */
    u8  pad18[4];
};

struct E9 {          /* 0x20 */
    u8 pad0[0x18];
    s8 count;        /* +0x18 */
    s8 pad19;
    s8 slots[6];     /* +0x1A */
};

struct R6 {          /* 6 */
    s16 id;
    u8  b2;
    u8  pad3[3];
};

struct Blob {        /* the `cards` member sits 0x4B9FC into the object */
    u8 pad0[0x4B9FC];
    struct R6 cards[1];
};

extern u8 D_801A7AD8[];
extern s32 D_801D4244[];
extern struct E9 D_800E9FF0[];
extern struct Blob D_8015C424;
extern struct R6 D_801A7E20[];

s32 func_800170C8(struct Rec *);

void func_80027DF8(struct Ent *out, s32 who) {
    u8 *base;
    s32 i;

    base = &D_801A7AD8[who * 0x1A4];

    {
        struct Rec *rec;
        s32 *tbl;

        rec = (struct Rec *) (base + 0x8C);
        i = 0;
        tbl = D_801D4244;
        do {
            out->id = 0;
            if (rec->flags & 0x8000) {
                s32 r;
                s32 t;

                out->id = rec->id;
                r = func_800170C8(rec);
                out->x = r;
                out->y = r >> 16;
                out->flags = rec->flags;
                out->b8 = rec->obj->f68;
                if (rec->flags & 0x200) {
                    t = *(s32 *) ((((s16) rec->id - 1) << 2) + (u32) tbl) >> 18;
                } else {
                    t = *(s32 *) ((((s16) rec->id - 1) << 2) + (u32) tbl) >> 22;
                }
                out->b9 = t & 0xF;
            }
            i += 1;
            out += 1;
            rec += 1;
        } while (i < 5);
    }

    {
        struct Rec *rec;
        s32 *tbl;

        rec = (struct Rec *) (base + 0x118);
        i = 0;
        tbl = D_801D4244;
        do {
            out->id = 0;
            if (rec->flags & 0x8000) {
                s32 r;
                s32 t;

                out->id = rec->id;
                r = func_800170C8(rec);
                out->x = r;
                out->y = r >> 16;
                out->flags = rec->flags;
                out->b8 = rec->obj->f68;
                if (rec->flags & 0x200) {
                    t = *(s32 *) ((((s16) rec->id - 1) << 2) + (u32) tbl) >> 18;
                } else {
                    t = *(s32 *) ((((s16) rec->id - 1) << 2) + (u32) tbl) >> 22;
                }
                out->b9 = t & 0xF;
            }
            i += 1;
            out += 1;
            rec += 1;
        } while (i < 5);
    }

    {
        s32 *tbl;

        i = 0;
        do {
            s32 n;

            n = D_800E9FF0[who].slots[i];
            if (n >= 0) {
                s32 *p;
                s32 id;

                id = D_8015C424.cards[n].id;
                out->id = id;
                tbl = D_801D4244;
                p = (s32 *) (((id - 1) << 2) + (u32) tbl);
                out->x = (*p & 0x1FF) * 10;
                out->y = ((*p >> 9) & 0x1FF) * 10;
                out->flags = 0;
                out->b8 = (*p >> 26) & 0x1F;
                out->b9 = (*p >> 22) & 0xF;
                out->bA = (*p >> 18) & 0xF;
                out += 1;
            }
            i += 1;
        } while (i < 5);
    }

    {
        struct R6 *rp;

        i = D_800E9FF0[who].count;
        rp = &D_801A7E20[i + who * 40];
        if (i < 0x28) {
            s32 *tbl;

            tbl = D_801D4244;
            do {
                s32 *p;
                s32 id;

                id = rp->id;
                out->id = id;
                p = (s32 *) (((id - 1) << 2) + (u32) tbl);
                out->x = (*p & 0x1FF) * 10;
                out->y = ((*p >> 9) & 0x1FF) * 10;
                out->flags = 0;
                out->b8 = (*p >> 26) & 0x1F;
                i += 1;
                out->b9 = (*p >> 22) & 0xF;
                out->bA = (*p >> 18) & 0xF;
                out->bB = rp->b2;
                rp += 1;
                out += 1;
            } while (i < 0x28);
        }
    }
    out->id = 0;
}
