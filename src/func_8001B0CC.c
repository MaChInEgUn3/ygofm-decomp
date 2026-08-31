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

/* Projects the fixed 3D anchor point for slot index a0 through the GTE and
   returns its projected screen-space X coordinate.

   D_800908A0 is an array of {s16 x; s16 z;} ground-plane coordinates, one
   per slot; the anchor's height is always the constant -0x18. The point is
   staged into the PS1 scratchpad (KSEG1 0x1F800000-0x1F8003FF) at 0x1F8003E0
   as an SVECTOR {vx=x, vy=-0x18, vz=z}, then RTPS'd through the current
   rotation/translation matrix (D_800FE148, installed via func_800855D0) and
   projection plane distance (D_800F2856, installed via func_800878D0). The
   screen offset is temporarily set to the HUD center (0xA0, 0x6C) for the
   projection and restored to (0, 0) afterward. Same RTPS/scratchpad-staging
   technique as calibrate_screen_offset.c (func_800178BC), including its
   register-pinned scratch pointer and raw RTPS opcode -- gcc 2.8.1 has no
   mnemonic for RTPS, and mtc2/lwc2/swc2 need the specific COP2 register
   numbers rather than any C-level abstraction. */

typedef struct {
    s16 x;
    s16 z;
} GroundPoint;

extern s16 D_800F2856[4];
#define D_800F2856 (D_800F2856[0])
extern GroundPoint D_800908A0[];
#define D_800908A0 D_800908A0
extern u8 D_800FE148[16];
#define D_800FE148 D_800FE148

extern void func_800878D0(s32 dist);
extern void func_800878B0(s32 x, s32 y);
extern void func_800855D0(void *m);

s32 func_8001B0CC(s32 slot) {
    s16 x;
    s16 result;

    func_800878D0(D_800F2856);
    func_800878B0(0xA0, 0x6C);
    func_800855D0(D_800FE148);

    {
        register s16 *scratch asm("v1") = (s16 *) 0x1F8003E0;
        GroundPoint *pt = &D_800908A0[slot];

        x = pt->x;
        scratch[1] = -0x18;
        scratch[0] = x;
        __asm__ volatile("" ::: "memory");
        scratch[2] = pt->z;

        __asm__ volatile(
            "lwc2 $0, 0(%0)\n"
            "lwc2 $1, 4(%0)\n"
            "nop\n"
            "nop\n"
            ".word 0x4a180001\n"   /* rtps */
            :: "r"(scratch)
            : "memory"
        );
    }
    {
        s16 *resptr = &result;
        __asm__ volatile(
            "swc2 $14, 0(%0)\n"
            :: "r"(resptr)
            : "memory"
        );
    }

    func_800878B0(0, 0);
    return result;
}
