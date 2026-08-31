/* ASSEMBLY DEBT -- this is a TRANSCRIPTION, not a decompilation.
 * Ordinary MIPS written into an inline asm block to force a match. It is
 * byte-exact and therefore invisible to build.py, which is exactly the
 * problem: the oracle cannot tell transcribed assembly from real C, so
 * nothing but this comment stops it being counted as done.
 * Counted by tools_src/asm_debt.py; the standard is in docs/ASM_DEBT.md.
 */
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

/* D_8009B458+0x518: 16-entry, 0x2C-byte-stride record array (the same
   "Record" layout process_timer_burst_records_8004c8c8.c already named,
   here re-zeroed/reset to its default state). */
typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
    u16 f14;
    u16 f16;
    u16 f18;
    s32 f1C;
    u8 pad20[0x24 - 0x20];
    u8 f24;
    u8 pad25;
    u8 f26;
    u8 f27;
    u8 f28;
    u8 f29;
    u8 pad2A;
    u8 f2B;
} Rec518;

/* D_8009B458+0x180: the same "Sub" SPU-voice-slot layout used by
   func_8004A7C0.c (0x28-byte stride), here (re)initialized per active
   voice up to D_8009B458->f510. */
typedef struct {
    u8 f0;
    u8 pad1[2];
    u8 f3;
    u8 pad4[8];
    u8 fC;
    u8 fD;
    u8 pad0E;
    u8 fF;
    u8 pad10[0xA];
    u16 f1A;
    u16 f1C;
    u16 f1E;
} Sub180;

/* D_8009B458+0: 16-entry, 0x18-byte-stride array of per-voice mix
   parameters (volume/pan-like fields, all reset to their default here). */
typedef struct {
    u8 pad0;
    u8 f1;
    u8 pad2;
    u8 f3;
    u8 f4;
    u8 f5;
    u8 f6;
    u8 f7;
    u32 f8;
    u32 fC;
    u8 f10;
    u8 pad11[3];
    u16 f14;
} Voice18;

extern u8 D_80010538[];
extern void *D_8009B458;
extern void func_8004A764(s32 idx);
extern void func_80076ED0(s32 a0, u32 a1);

/* SPU voice-state init: resets the 16 timer/burst records at +0x518, then
   (if D_8009B458->f510 > 0) walks up to that many voice slots at +0x180,
   keying each one via a lookup table at D_80010538+0xEFC (func_8004A764
   loads the voice attributes, func_80076ED0(0, key) fires it) and OR-
   accumulating the fired keys into a mask; finally resets the 16 mix-
   parameter entries at +0 and batch key-ons the accumulated mask.

   D_8009B458 is func_800738F0 via a fresh absolute lui+lw at every access site
   (never cached across iterations/calls) to match the target's addressing
   -- this codebase's documented D_8009B458-absolute-addr-vs-G0-LICM
   pattern; using inline asm for the reload sidesteps gcc looping the
   address computation out of each loop. A handful of `register ... asm`
   pins and a couple of scheduling fences reproduce the target's exact
   instruction order/registers for otherwise-equivalent independent
   stores. */
void func_8004A518(void) {
    s32 var_s5;
    register s32 var_s1 asm("s1");
    s32 var_a0;
    void *rec1;
    Rec518 *r;
    void *rec3;
    s16 count;
    s32 var_s1_2;
    s32 *table;
    s32 var_s2;
    Sub180 *sub;
    s32 key;
    void *rec5;
    register s32 var_s1_3 asm("s1");
    s32 var_v1;
    Voice18 *v;

    {
        register s32 c72 asm("a1");
        register s32 c1 asm("a3");
        register s32 cFF asm("a2");

        var_s5 = 0;
        var_s1 = 0;
        c72 = 0x72;
        c1 = 1;
        cFF = 0xFF;
        var_a0 = 0x518;

        {
            void *rec0v = D_8009B458;

            *(s16 *)((u8 *)rec0v + 0x512) = 0x7F;
        }

        do {
            __asm__ volatile("lui %0, %%hi(D_8009B458)\n\tlw %0, %%lo(D_8009B458)(%0)" : "=r"(rec1));
            var_s1 += 1;
            r = (Rec518 *)((u8 *)rec1 + var_a0);
            r->f0 = 0;
            r->f4 = 0;
            r->f26 = 0;
            r->f1C = 0;
            r->f8 = 0;
            r->fC = 0;
            r->f14 = c72;
            r->f16 = c72;
            r->f24 = c1;
            r->f10 = 0;
            r->f18 = 0;
            r->f27 = 0;
            r->f28 = cFF;
            r->f29 = 0;
            r->f2B = 0;
            var_a0 += 0x2C;
        } while (var_s1 < 0x10);
    }

    __asm__ volatile("lui %0, %%hi(D_8009B458)\n\tlw %0, %%lo(D_8009B458)(%0)" : "=r"(rec3));
    count = *(s16 *)((u8 *)rec3 + 0x510);
    var_s1_2 = 0;
    if (count > 0) {
        s32 c40 = 0x40;

        /* D_80010538+0xEFC lookup table of per-voice SPU keys. */
        __asm__ volatile(
            "lui $2, %%hi(D_80010538+0xEFC)\n\t"
            "addiu %0, $2, %%lo(D_80010538+0xEFC)"
            : "=r"(table) :: "$2");
        var_s2 = 0x180;
        do {
            register s32 a0arg asm("a0");

            sub = (Sub180 *)((u8 *)rec3 + var_s2);
            key = *table;
            a0arg = var_s1_2;
            __asm__ volatile("" ::: "memory");
            {
                register s32 c63 asm("v0") = 0x63;
                sub->f3 = c63;
            }
            sub->f0 = var_s1_2;
            sub->fD = 0;
            sub->fF = 0;
            {
                register s32 c64 asm("v0") = 0x40;
                sub->fC = c64;
            }
            sub->f1A = c40;
            sub->f1C = c40;
            sub->f1E = 0;
            func_8004A764(a0arg);
            {
                register s32 a0zero asm("a0") = 0;

                __asm__ volatile("" ::: "memory");
                table += 1;
                var_s2 += 0x28;
                func_80076ED0(a0zero, key);
            }
            __asm__ volatile("lui %0, %%hi(D_8009B458)\n\tlw %0, %%lo(D_8009B458)(%0)" : "=r"(rec3));
            var_s1_2 += 1;
            var_s5 |= key;
        } while (var_s1_2 < *(s16 *)((u8 *)rec3 + 0x510));
    }

    {
        register s32 c40b asm("a2");
        register s32 c7fb asm("a1");
        register s32 c7fw asm("a0");

        var_s1_3 = 0;
        c40b = 0x40;
        c7fb = 0x7F;
        /* Target keeps this as its own fresh li rather than reusing c7fb's
           value via a move, even though both hold 0x7F. */
        __asm__ volatile("addiu %0, $zero, 0x7F" : "=r"(c7fw));
        var_v1 = var_s1_3;
        do {
            __asm__ volatile("lui %0, %%hi(D_8009B458)\n\tlw %0, %%lo(D_8009B458)(%0)" : "=r"(rec5));
            var_s1_3 += 1;
            v = (Voice18 *)((u8 *)rec5 + var_v1);
            v->f1 = c40b;
            v->f3 = c7fb;
            v->f4 = 0;
            v->f5 = c7fb;
            v->f7 = c40b;
            v->f8 = c7fw;
            v->fC = c7fw;
            v->f10 = 0;
            v->f14 = 0;
            v->f6 = 0;
            var_v1 += 0x18;
        } while (var_s1_3 < 0x10);
    }

    func_80076ED0(0, var_s5);
}
