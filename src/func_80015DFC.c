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
//@ target 65FC F8
//@ sym func_800855D0=0x800855D0 func_800878B0=0x800878B0 func_80016784=0x80016784
//@ sym D_800FE148=0x800FE148 D_800E9D98=0x800E9D98 D_8009B1D5=0x8009B1D5
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

/* MATCHED 0/62. Blacklist reclamation (config/blacklist.txt:511, "no
   src/*.c in this codebase has solved a GTE inline-asm pattern yet").
   Same RTPS/scratchpad technique as func_8001B0CC.c and the
   just-landed sibling func_80015D18 -- register-pinned scratch pointer,
   raw RTPS opcode (gcc 2.8.1 has no mnemonic for it), native lwc2/swc2
   for the COP2 register moves. Reads its 3D input through a pointer
   field instead of a struct's own fields, and picks between two
   field8/fieldA offset constants (-0x1A/-0x1D or -0x1A/-0x1E) based on a
   player-index/field18 nested check before calling func_80016784.

   Also needed the oversized-array trick on D_800E9D98 (genuinely far
   from $gp, target uses absolute lui+lw for it, not gp-relative).

   NEW technique beyond the sibling: this function's RTPS result packs
   BOTH X and Y into one swc2 word and needs TWO separate field reads
   back out (the sibling only needed one). Plain C pointer-cast reads
   (`*(u16*)&result`, `*((s16*)&result+1)`) let gcc CSE the two accesses
   onto one shared base register, producing a lhu+sll+sra manual sign-
   extend for Y instead of a plain `lh` -- defeated by forcing each func_800738F0
   through its own raw-asm `lhu`/`lh` with an `"m"` memory operand (fixes
   the exact instruction regardless of addressing choice), THEN pinning
   the swc2 address pointer and the first field's destination to the
   SAME physical register (`asm("v0")`, sequential non-overlapping
   logical values) to match target's exact register reuse. Each fix
   alone got partway (scratch pointer alone: 39->5/62 exact word count;
   pin alone: 5->3/62); needed both together for 0/62. */

typedef struct {
    char pad0[0x30];
    s16 innerX;
    char pad1[2];
    s16 innerZ;
} Inner;

typedef struct {
    Inner *inner;
    char pad0[8 - 4];
    s16 field8;
    s16 fieldA;
    char pad1[0x18 - 0xC];
    s8 field18;
} Obj;

extern u8 D_800FE148[16];
#define D_800FE148 D_800FE148
extern s32 D_800E9D98[4];
#define D_800E9D98 (D_800E9D98[0])
extern u8 D_8009B1D5;

extern void func_800855D0(void *m);
extern void func_80016784(Inner *a0, s32 a1, s32 a2, s32 a3);
extern void func_800878B0(s32 x, s32 y);

void func_80015DFC(Obj *a0) {
    Obj *s0 = a0;
    s32 result;
    s32 resultY;

    func_800855D0(D_800FE148);

    {
        s16 x = s0->inner->innerX;
        register s16 *scratch asm("v1") = (s16 *) 0x1F8003E0;

        scratch[1] = 0;
        scratch[0] = x;
        scratch[2] = s0->inner->innerZ;

        __asm__ volatile(
            "lwc2 $0, 0(%0)\n"
            "lwc2 $1, 4(%0)\n"
            "nop\n"
            "nop\n"
            ".word 0x4a180001\n"   /* rtps */
            :: "r" (scratch)
            : "memory"
        );
    }

    {
        register s32 *presult asm("v0") = &result;
        register u32 resultX asm("v0");
        __asm__ volatile(
            "swc2 $14, 0(%0)\n"
            :: "r" (presult)
            : "memory"
        );
        __asm__ volatile("lhu %0, %1" : "=r" (resultX) : "m" (*(u16 *) &result));
        s0->field8 = resultX - 0x1A;
        __asm__ volatile("lh %0, %1" : "=r" (resultY) : "m" (*((s16 *) &result + 1)));
    }

    s0->fieldA = resultY - 0x1E;

    if (D_8009B1D5 != 0) {
        if (s0->field18 < 15) {
            s0->fieldA = resultY - 0x1D;
        }
    } else {
        if (s0->field18 >= 15) {
            s0->fieldA = resultY - 0x1D;
        }
    }

    func_80016784(s0->inner, D_800E9D98, s0->field8, s0->fieldA);
    func_800878B0(0xA0, 0x6C);
}
