/* PORTED from Unchiga's decompilation of SLUS_014.11, shared 2026-08-30.
 * His C, his comments; the identifiers are rewritten to this repo's address
 * form and nothing else was touched. Verified the only way that counts here:
 * tools_src/build.py rebuilds the retail image byte-for-byte with this in it.
 *
 * Self-contained by design -- it keeps his declarations rather than ours,
 * because a declaration is a codegen input and his are what this C matched
 * under. See docs/MERGE_UNCHIGA.md and tools_src/install_ported.py.
 */
//@ target 7FC4 F8
//@ sym func_800878D0=0x800878D0 func_800878B0=0x800878B0 func_800855D0=0x800855D0
//@ sym D_800F2856=0x800F2856 D_800FE148=0x800FE148
//@ sym D_800908A0=0x800908A0 D_800EA070=0x800EA070
//@ sym D_8009B1D5=0x8009B1D5
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

/* Blacklist reclamation (config/blacklist.txt:512, "same GTE inline-asm
   blocker as 0x80015DFC"). Loops D_800F2856/D_800FE148-driven RTPS
   projection (same technique as func_8001B0CC.c and
   func_80015D18/func_80015DFC) over 30 D_800908A0 ground points, writing
   each projected {x,y} pair into D_800EA070[i]. The scratch pointer
   ($t0=0x1F8003E0) and the RTPS result buffer pointer ($t1=sp+0x10) are
   computed ONCE before the loop, not per iteration, and both the input
   (D_800908A0) and output (D_800EA070) arrays are walked with plain
   pointer increments (a3/a1), never index arithmetic.

   Three levers beyond the earlier per-iteration attempt:
   1. `register T *x asm(reg) = expr;` (initializer ON the declaration)
      silently drops the materializing lui/ori/addiu entirely under -O2 --
      a real gcc 2.8.1 local-register-variable bug (confirmed via raw .s:
      the register has no prior def anywhere in the function). An asm
      barrier referencing the variable does NOT fix it; only declaring the
      register with no initializer and assigning it in a separate
      statement does.
   2. D_8009B1D5 is func_800738F0 via $gp in the target, which needs -G8 (not -G0);
      D_800F2856's declared size is bumped from [4] to [8] so it still
      forces absolute addressing under G8's 8-byte small-data threshold
      (array-size-controls-G8-threshold) while D_8009B1D5 (1 byte) falls
      under the threshold and gets gp-relative for free.
   3. The target materializes D_800EA070/D_800908A0's address through $v0
      as a throwaway hi-part scratch register before addiu into the
      pinned a1/a3 (`lui v0,hi; addiu a1,v0,lo`); plain C assignment
      always collapses this to the direct 2-insn form into the pinned
      register instead. Only raw inline asm hardcoding the exact
      `lui $2,%hi(sym)` / `addiu %0,$2,%lo(sym)` sequence (clobbering $2)
      reproduces it.

   Final 1-word residual: a plain `s16 y = result.y;` typed struct func_800738F0
   compiles to lhu (gcc determined the sign extension was unobservable
   since y only ever feeds a 16-bit subtract+store); forcing it through
   raw asm `lh %0,%1` with an "m" memory operand restores the target's
   true lh. */

typedef struct {
    s16 x;
    s16 z;
} GroundPoint;

typedef struct {
    s16 x;
    s16 y;
} ScreenPoint;

typedef struct {
    u16 x;
    s16 y;
} RtpsResult;

extern s16 D_800F2856[8];
#define D_800F2856 (D_800F2856[0])
extern u8 D_800FE148[16];
#define D_800FE148 D_800FE148
extern GroundPoint D_800908A0[];
#define D_800908A0 D_800908A0
extern ScreenPoint D_800EA070[30];
#define D_800EA070 D_800EA070
extern u8 D_8009B1D5;

extern void func_800878D0(s32 dist);
extern void func_800878B0(s32 x, s32 y);
extern void func_800855D0(void *m);

void func_800177C4(void) {
    s32 i;
    RtpsResult result;
    register s16 *scratch asm("t0");
    register RtpsResult *presult asm("t1");
    register ScreenPoint *dst asm("a1");
    register GroundPoint *src asm("a3");

    func_800878D0(D_800F2856);
    func_800878B0(0xA0, 0x6C);
    func_800855D0(D_800FE148);

    scratch = (s16 *) 0x1F8003E0;
    i = 0;
    presult = &result;
    __asm__ volatile(
        "lui $2, %%hi(D_800EA070)\n"
        "addiu %0, $2, %%lo(D_800EA070)\n"
        : "=r" (dst) :: "$2"
    );
    __asm__ volatile(
        "lui $2, %%hi(D_800908A0)\n"
        "addiu %0, $2, %%lo(D_800908A0)\n"
        : "=r" (src) :: "$2"
    );

    do {
        u16 x;
        s16 y;

        x = src->x;
        scratch[1] = 0;
        scratch[0] = x;
        scratch[2] = src->z;

        __asm__ volatile(
            "lwc2 $0, 0(%0)\n"
            "lwc2 $1, 4(%0)\n"
            "nop\n"
            "nop\n"
            ".word 0x4a180001\n"   /* rtps */
            :: "r" (scratch)
            : "memory"
        );

        __asm__ volatile(
            "swc2 $14, 0(%0)\n"
            :: "r" (presult)
            : "memory"
        );

        x = result.x;
        dst->x = x - 0x1A;
        __asm__ volatile("lh %0, %1" : "=r" (y) : "m" (result.y));
        dst->y = y - 0x1E;

        if (D_8009B1D5 != 0) {
            if (i < 15) {
                dst->y = y - 0x1D;
            }
        } else {
            if (i >= 15) {
                dst->y = y - 0x1D;
            }
        }

        dst++;
        src++;
    } while (++i < 30);

    func_800878B0(0, 0);
}
