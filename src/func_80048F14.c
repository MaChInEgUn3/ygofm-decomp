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

/* SPU reverb bring-up plus sound-state reset.
 *
 * Reserves the reverb work area, turns reverb on, and programs reverb
 * mode 2 at full depth, then resets three groups of fields in the sound
 * state block at D_8009B45C, points its two buffer pointers at the fixed
 * addresses 0x801E2000 and 0x801EA800, and hands off to the three
 * D_8009B458/D_8009B45C helpers.
 *
 * `frame` is a PsyQ SpuReverbAttr: mask = 7 selects mode + both depths,
 * mode = 2, depth.left = depth.right = 0x7FFF.  It is spelled as a plain
 * local struct rather than the library typedef because this tree has no
 * libspu headers; the layout is the library's.
 *
 * BOUNDARY BUG: function_ranges.txt splits these 63 instructions into
 * three F entries (0x80048F14 + 0x80048FFC + 0x80049000).  The true span
 * is 0x80048F14..0x80049010; both trailing entries are --exclude'd.
 *
 * Byte-exact only at "-G0 -mno-split-addresses --keep-large-ori
 * -fno-schedule-insns2".  --keep-large-ori is load-bearing: the 0xFFFF
 * store at 0x80048FB4 is a genuine `ori $v0,$zero,0xffff`, which the
 * build rewrites to a sign-extending addiu without that flag.
 * -fno-schedule-insns2 (the post-reload pass) is what stops the three
 * reload+store groups from being interleaved with each other.
 * Full derivation, and every shape that did not work, is in
 * match/sketches/func_80048F14.c.
 */

struct SndBuf {
    u8 pad0[2];
    u16 f2;                 /* 0x2 */
    u32 f4;                 /* 0x4 */
    u32 f8;                 /* 0x8 */
    u32 fC;                 /* 0xC */
};

struct SndState {
    u8 pad0[0x1560];
    void *f1560;            /* 0x1560: -> 0x801E2000 */
    struct SndBuf *f1564;   /* 0x1564: -> 0x801EA800 */
    u8 pad1568[0x1578 - 0x1568];
    s16 f1578;              /* 0x1578..0x157E: four counters, reset to -1 */
    s16 f157A;
    s16 f157C;
    s16 f157E;
    u16 f1580;              /* 0x1580 */
    u16 f1582;              /* 0x1582 */
    u8 f1584;               /* 0x1584 */
    u8 pad1585;
    u16 f1586;              /* 0x1586 */
    u16 f1588;              /* 0x1588 */
    u8 f158A;               /* 0x158A */
};

/* SpuReverbAttr */
struct RevAttr {
    s32 mask;               /* 0x0 */
    s32 mode;               /* 0x4 */
    s16 depthL;             /* 0x8 */
    s16 depthR;             /* 0xA */
    u8 pad[8];              /* 0xC: delay/feedback, untouched here */
};

/* ONE extern is enough, and that is a correction: the sketch this came
 * from used three per-site aliases (D_8009B45C_e1/_e2/_e3) on the theory
 * that each group needs its own reload.  With -fno-schedule-insns2 the
 * single extern is byte-identical, so no alias registration is needed. */
extern struct SndState *D_8009B45C;

extern s32 func_80076790(s32 on);
extern s32 func_80075BE0(s32 on);
extern void func_80075DE0(void *attr);
extern void func_80049594(s32 arg0);
extern void func_80049600(s32 arg0);
extern void func_80049544(void);

void func_80048F14(void) {
    struct RevAttr frame;

    func_80076790(1);
    func_80075BE0(1);

    frame.mask = 7;
    frame.mode = 2;
    frame.depthL = 0x7FFF;
    frame.depthR = 0x7FFF;
    func_80075DE0(&frame);

    D_8009B45C->f1586 = 0;
    D_8009B45C->f1588 = 0;
    D_8009B45C->f158A = 0;

    {
        struct SndState *e2 = D_8009B45C;
        struct SndState *e3;
        register u32 c asm("v1");
        register void *rec asm("a1") = (void *)0x801EA800;
        register void *buf asm("a0") = (void *)0x801E2000;
        s32 m1;

        /* volatile: these three keep their source order, which the
           pre-reload scheduler would otherwise shuffle (it emits the sb
           first).  Same sh/sb encodings, so it costs no word. */
        c = 0xFF;
        *(volatile u16 *)&e2->f1580 = c;
        *(volatile u8 *)&e2->f1584 = c;
        e3 = D_8009B45C;
        *(volatile u16 *)&e2->f1582 = 0;
        m1 = -1;
        __asm__ __volatile__("" : "+r"(m1));  /* anchor `li -1` above the two stores */
        e3->f1560 = buf;
        e3->f1564 = rec;
        /* MICRO-ISLAND (1 insn, allocator/copy-propagation tie class).
           REOPEN CONDITION: "local-alloc/global.c register-role assignment
           rule lands" -- the live allocator family (0x8002C604, 0x8004A27C,
           and w4's 0x8014F864/0x8014F9E4, all matched by
           `unpark --matching "local-alloc"`).  NOT the scheduler-tie family:
           that condition fired and was consumed when w3 closed 0x80049920
           and 0x8004D914 on 2026-08-29, so an island filed under it would
           never be swept up.  The ROM keeps a redundant `move a0,a1` here and
           stores 0xFFFF through the COPY; gcc 2.8.1 copy-propagates every C
           spelling of it away -- a second variable holding the same literal, a
           laundered copy, an a0-pinned copy, and reusing the a0-pinned
           variable were all elided (61-63w, 25-38 diffs).  First re-decomp
           target when w3's allocator/scheduler tie-break rules land: delete
           the island, re-measure, and this should come back as pure C. */
        __asm__ __volatile__("move %0,%1" : "=r"(buf) : "r"(rec));
        e3->f1578 = m1;
        e3->f157A = m1;
        e3->f157C = m1;
        e3->f157E = m1;
        *(u16 *)buf = 0xFFFF;
        e3->f1564->f2 = 0;
        e3->f1564->f4 = 0;
        e3->f1564->f8 = 0;
        e3->f1564->fC = 0x40000;
        func_80049594(2);
    }

    func_80049600(0x14);
    func_80049544();
}
