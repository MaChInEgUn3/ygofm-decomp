/* PORTED from Unchiga's decompilation of SLUS_014.11, shared 2026-08-30.
 * His C, his comments; the identifiers are rewritten to this repo's address
 * form and nothing else was touched. Verified the only way that counts here:
 * tools_src/build.py rebuilds the retail image byte-for-byte with this in it.
 *
 * Self-contained by design -- it keeps his declarations rather than ours,
 * because a declaration is a codegen input and his are what this C matched
 * under. See docs/MERGE_UNCHIGA.md and tools_src/install_ported.py.
 */
//@ target 6518 A0
//@ sym func_800878D0=0x800878D0 func_800878B0=0x800878B0 func_800855D0=0x800855D0
//@ sym D_800FE148=0x800FE148
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

#include "gte.h"

/* Blacklist reclamation (config/blacklist.txt:584). Same RTPS/scratchpad
   -staging technique as func_8001B0CC.c (func_800015D18's own
   sibling, sim=0.25) and calibrate_screen_offset.c -- register-pinned
   scratch pointer + raw RTPS opcode (gcc 2.8.1 has no mnemonic for it)
   + raw lwc2/swc2 for the COP2 register moves. Differs from the sibling
   in three ways: (1) takes the target struct directly as a0 instead of
   indexing a table by slot; (2) Y is a plain 0, not a per-anchor
   constant; (3) the RTPS result (packed X|Y<<16 via swc2) is stored
   straight into the struct's own fields, then re-func_800738F0 and offset by
   -0x20/-0x1E each, rather than returned as a single value. */

typedef struct {
    char pad0[0x28];
    s16 x;
    s16 z;
    char pad1[4];
    s16 outX;
    s16 outY;
} Obj;

extern u8 D_800FE148[16];
#define D_800FE148 D_800FE148

extern void func_800878D0(s32 dist);
extern void func_800878B0(s32 x, s32 y);
extern void func_800855D0(void *m);

void func_80015D18(Obj *a0) {
    Obj *s0 = a0;

    func_800878D0(0x12C);
    func_800878B0(0xA0, 0x6C);
    func_800855D0(D_800FE148);

    {
        s16 x = s0->x;
        register s16 *scratch asm("v1") = (s16 *) 0x1F8003E0;

        scratch[1] = 0;
        scratch[0] = x;
        __asm__ volatile("" ::: "memory");
        scratch[2] = s0->z;

        gte_ldv0(scratch);
        gte_rtps();
    }

    gte_stsxy(&s0->outX);

    s0->outX -= 0x20;
    s0->outY -= 0x1E;
    func_800878B0(0, 0);
}
