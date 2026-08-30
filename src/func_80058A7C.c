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

/* Updates a small per-object timing/phase record and packs several of its
   fields (plus bits from a1) into a return value shaped like a 16.16
   hardware-style register pair. f4 is always advanced by (a0&1)<<8 minus
   0x280. If f12 (a phase counter) is below 0x100, f10 only nudges by -0x80,
   and once f12 reaches exactly 8 it's bumped to 0xF2+(a0&1) (a phase
   transition marker); otherwise f10 advances the same way f4 does. The
   packed result's high half combines a1's low 2 bits, f0's low 2 bits, and
   two flag bits pulled out of f6; the low half combines f12's low bits with
   f10's mid bits. */
struct S80058A7C {
    u16 f0;                    /* 0x0 */
    char pad1[0x4 - 0x2];
    u16 f4;                      /* 0x4 */
    u16 f6;                        /* 0x6 */
    char pad2[0x10 - 0x8];
    u16 f10;                         /* 0x10 */
    s16 f12;                           /* 0x12 */
};

u32 func_80058A7C(s32 a0, s32 a1, struct S80058A7C *a2) {
    u16 shifted = (a0 & 1) << 8;
    u16 f4 = a2->f4;
    s32 f12;
    asm volatile("" ::: "memory");
    f12 = a2->f12;
    asm volatile("" ::: "memory");
    f4 = f4 - 0x280;
    asm volatile("" ::: "memory");
    f4 = f4 + shifted;
    a2->f4 = f4;

    if (f12 < 0x100) {
        a2->f10 = a2->f10 - 0x80;
        if (a2->f12 == 8) {
            a2->f12 = (a0 & 1) + 0xF2;
        }
    } else {
        u16 f10 = a2->f10;
        asm volatile("" ::: "memory");
        f10 = f10 - 0x280;
        asm volatile("" ::: "memory");
        f10 = f10 + shifted;
        a2->f10 = f10;
    }

    {
        u32 part_a1 = (a1 & 3) << 5;
        u32 part_f0 = (a2->f0 & 3) << 7;
        u32 hi = part_f0 | part_a1;
        hi |= ((s32)(a2->f6 & 0x100) << 16) >> 20;
        hi |= (a2->f4 & 0x3FF) >> 6;
        hi |= (a2->f6 & 0x200) << 2;
        hi <<= 16;

        {
            u16 f12u = a2->f12;
            u32 lo = ((f12u << 6) | ((a2->f10 >> 4) & 0x3F)) & 0xFFFF;
            return hi | lo;
        }
    }
}
