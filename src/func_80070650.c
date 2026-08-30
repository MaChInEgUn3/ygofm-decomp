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

/* Blacklist reclamation (blacklist.txt:460), LANDED 0/48. Old best was
   37/48 (47w, 1 short) -- register allocation only, from naming the
   FIRST `D_800916E0[idx]` func_800738F0 into the same `h` local as the second.
   That forces gcc to treat both reads as one variable's persistent
   lifetime spanning the call, needing an extra callee-saved register the
   target's compile doesn't use: target lets the first load's value stay
   in the caller-saved v0 scratch register (it's only needed for the
   `jalr`, dead immediately after) and reuses the now-free address
   register for the SECOND, persistent load post-call. Calling
   `D_800916E0[idx]()` directly (no local for the transient first value)
   and keeping the named `h` local only for the second, persistent func_800738F0
   reproduces this split exactly -- 37/48 -> 0/48, no register pins or
   explicit hoisting needed. */

extern s32 func_8007058C(void);
extern s32 func_80074170(s32 mode);

typedef void (*Handler)(void);
extern Handler D_800916E0[];

extern void func_80070FF8(void);
extern void func_80071000(void);
extern void func_80070F1C(void);

struct Big {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC; /* 0xC */
    u8 pad2[0x14 - 0x10];
    u8 count; /* 0x14 */
    u8 pad3[3];
    s32 items[1]; /* 0x18 */
};

extern struct Big D_800F5BE8;

s32 func_80070650(void) {
    for (;;) {
        s32 idx;
        Handler h;

        D_800F5BE8.fC = D_800F5BE8.f8;
        idx = func_8007058C();
        D_800916E0[idx]();
        h = D_800916E0[idx];

        if (h == func_80070FF8) {
            return 1;
        }
        if (h == func_80071000) {
            return 3;
        }
        if (h == func_80070F1C) {
            return 2;
        }

        if (func_80074170(1) >= 0xF0) {
            break;
        }
    }

    return 0;
}
