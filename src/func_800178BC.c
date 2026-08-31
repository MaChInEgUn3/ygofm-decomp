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

/* Projects a fixed reference point (1000,0,1000) through the GTE with a
   temporary geometry setup, then reads back the resulting screen XY (SXY2)
   to derive the offset between the expected screen center (0xA0,0x6C) and
   where the point actually landed, storing the delta in D_8009B200/202. */

struct Rec {
    s16 f0;
    s16 f2;
    s16 f4;
    char pad[0xE - 0x6];
    s16 fE;
};

struct Vec3 {
    s16 x, y, z;
};

extern struct Rec D_800F2848[4];
#define D_800F2848 (D_800F2848[0])
extern u16 D_8009AF20;
extern s16 D_8009B200;
extern s16 D_8009B202;
extern u8 D_800FE148[16];
#define D_800FE148 D_800FE148

extern void func_800878D0(s32 dist);
extern void func_800878B0(s32 x, s32 y);
extern void func_800855D0(void *m);
extern void func_8001352C(void);
extern void func_80017130(void);

void func_800178BC(void) {
    s32 sxy_raw;
    u16 g18;
    s16 sx, sy;

    func_80017130();

    func_800878D0(D_800F2848.fE);
    func_800878B0(0xA0, 0x6C);
    g18 = D_8009AF20;

    D_800F2848.f0 = 0x14E;
    D_800F2848.f4 = 0x3FE;
    D_800F2848.f2 = g18;
    func_8001352C();

    func_800855D0(D_800FE148);

    {
        register struct Vec3 *v asm("v0") = (struct Vec3 *)0x1F8003E0;
        register s16 c asm("v1") = 0x3E8;
        v->x = c;
        v->y = 0;
        v->z = c;

        __asm__ volatile(
            "lwc2 $0, 0(%0)\n"
            "lwc2 $1, 4(%0)\n"
            "nop\n"
            "nop\n"
            ".word 0x4a180001\n" /* rtps */
            : : "r"(v) : "memory"
        );
    }
    {
        register void *out asm("v0") = &sxy_raw;
        __asm__ volatile(
            "swc2 $14, 0(%0)\n"
            : : "r"(out) : "memory"
        );
    }

    sx = (u16)(sxy_raw & 0xFFFF) - 0xA0;
    D_8009B200 = sx;
    sy = (s16)(sxy_raw >> 16) - 0x6C;
    D_8009B202 = sy;

    func_800878B0(0, 0);
    func_80017130();
}
