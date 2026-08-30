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

/* MATCHED 0/110, G0:nosplit --keep-large-ori (claude-w2, 2026-08-28).
 * Reclaimed from the blacklist at a recorded 84/110 (111w) with two
 * blockers inherited from its sibling; both were wrong about the cause.
 *
 * NEEDS --keep-large-ori: the 0xFFFF sentinel is ori $a0,$zero,0xFFFF at
 * 0x800487E8.  cmp.sh and msearch preserve it, the build rewrites it to a
 * sign-extending addiu without the flag, so the unit would verify 0-diff
 * and BUILD WRONG.
 *
 * THE TWO RECORDED BLOCKERS:
 *  1. "Needs G8, not G0 -- D_8009B45C forces gp-relative here, opposite of
 *     the sibling."  Not so: the target addresses D_8009B45C absolutely at
 *     all three sites.  -G0 -mno-split-addresses with one extern alias per
 *     site is right, and it also removes the extra callee-saved register
 *     the entry blamed on register roles -- the hoisted lui was the whole
 *     of that symptom.
 *  2. "The index combine strength-reduces to `or` because gcc proves the
 *     bit ranges are disjoint, but the target uses a real `addu`."  It does
 *     not, once the two halves are separate named locals summed as
 *     `lo + hi`; the `or` came from folding the whole address expression at
 *     once.  Same construction as func_80047DB0, matched this session.
 *
 * What actually took the search: three register-role details.  `ff` (the
 * 0xFFFF sentinel, live across both early-outs) must be pinned to a0.  The
 * 0x80 constant must be a VARIABLE used twice -- the target reads it from a
 * register for both `0x80 - half` and `half + 0x80`, and only an
 * `asm volatile` launder keeps gcc from folding the second into an addiu;
 * a plain launder is not enough.  And that same variable carries the two
 * mult results, which is what func_8008FAF0 them in v0: pinning it to v0 instead
 * reserves v0 function-wide and pushes the mflo into t0.
 *
 * Sibling of func_80048920 (that sketch supplied the struct): same 0x8000
 * early-out, same two-stage 0x4000 table lookup, but the per-voice loop
 * additionally rewrites the 0x414 volume and 0x41C pan words as fixed-point
 * scalings of the 0x444 scale table. */

struct S8009B45C {
    char pad0[0x404];
    u16 ids[4];
    char pad1[0x414 - 0x40C];
    u16 vol[4];
    u16 pan[4];
    char pad2[0x43C - 0x424];
    u16 *p43C;
    char pad3[0x444 - 0x440];
    u8 *p444;
    char pad4[0x44C - 0x448];
    u16 tbl44C[64];
};

extern struct S8009B45C *D_8009B45C;
extern struct S8009B45C *D_8009B45C;
extern struct S8009B45C *D_8009B45C;
extern void func_80044E90(s16 a0);
extern void func_80077C50(s32 a0, void *a1);
extern void func_80047864(s32 voice);

void func_80048768(s32 arg0, s32 arg1) {
    s32 lo;
    s32 hi;
    register s32 i asm("s0");
    register s32 half asm("s1");
    register s32 id asm("s2");
    register s32 up asm("s3");
    register s32 down asm("s4");
    register s32 near1 asm("s5");
    register s32 a1v asm("s6");
    s32 t;
    s32 c80;
    register s32 ff asm("a0");

    id = arg0;
    a1v = arg1;
    if (arg0 & 0x8000) {
        func_80044E90((s16) arg1);
        return;
    }
    if ((arg0 & 0xF000) == 0x4000) {
        struct S8009B45C *a = D_8009B45C;
        u16 v;

        lo = (arg0 & 0x1F) << 1;
        hi = ((arg0 & 0x100) != 0) << 6;
        v = *(u16 *)((u8 *)a + (lo + hi) + 0x44C);
        ff = 0xFFFF;
        if (v == ff) {
            return;
        }
        id = a->p43C[v];
        if (id == ff) {
            return;
        }
    }
    i = 0;
    t = (arg1 - 1) & 0xFFFF;
    near1 = (u32) t < 0x80;
    t = arg1 << 16;
    half = t >> 16;
    c80 = 0x80;
    __asm__ volatile("" : "+r"(c80));
    down = c80 - half;
    up = half + c80;
    do {
        s16 local;
        struct S8009B45C *b;
        u16 idv;

        func_80077C50(i + 0x14, &local);
        b = D_8009B45C;
        idv = b->ids[i];
        __asm__("" : "+r"(id));
        if (idv == (u16) id && local != 0) {
            if (half != 0) {
                if (near1) {
                    c80 = b->p444[idv * 8] * down;
                    b->vol[i] = c80;
                }
                __asm__("" : "+r"(a1v));
                if ((u16)(a1v + 0x80) < 0x80) {
                    struct S8009B45C *c = D_8009B45C;
                    c80 = c->p444[idv * 8] * up;
                    c->pan[i] = c80;
                }
            }
            func_80047864(i);
        }
    } while (++i < 4);
}
