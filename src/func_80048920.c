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

/* MATCHED 0/66, G0:nosplit --keep-large-ori (claude-w2, 2026-08-28).
 * Was a carved STUB at a recorded best of 29/66; promoted in place.
 * Reclaimed straight after its sibling func_80048768 -- same recipe, and
 * once that one was solved this took one search: -G0 -mno-split-addresses
 * with one extern alias per absolute reload site, plus pins fixing the
 * four register roles (i->s0, the arg1 copy->s1, the masked id->s2, and
 * the id copy->a2).  The a2 pin is the load-bearing one: without it gcc
 * proves id == arg0 on the non-lookup path and folds the copy away, which
 * costs the word and shifts everything after it.
 *
 * NEEDS --keep-large-ori: the 0xFFFF sentinel is ori $a1,$zero,0xFFFF at
 * 0x8004898C.
 *
 * Input router: 0x8000 forwards the low byte to func_80044DC0; a 0x4000
 * class id goes through the same two-stage D_8009B45C table lookup as the
 * sibling func_80048768; the surviving id is matched against the four live
 * ids and each hit records arg1 in arr424 and notifies func_80047864. */

struct S8009B45C {
    char pad0[0x404];
    u16 ids[4];
    char pad1[0x424 - 0x40C];
    u8 arr424[4];
    char pad2[0x43C - 0x428];
    u16 *p43C;
    char pad3[0x44C - 0x440];
    u16 tbl44C[64];
};

extern struct S8009B45C *D_8009B45C;
extern struct S8009B45C *D_8009B45C;
extern void func_80044DC0(u8 a0);
extern void func_80077C50(s32 a0, void *a1);
extern void func_80047864(s32 voice);

void func_80048920(s32 arg0, s32 arg1) {
    s32 lo;
    s32 hi;
    register s32 i asm("s0");
    register s32 a1v asm("s1") = arg1;
    register s32 idm asm("s2");
    register s32 id asm("a2");
    s32 ff;

    id = arg0;
    if (arg0 & 0x8000) {
        func_80044DC0((u8) a1v);
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
    idm = id & 0xFFFF;
    do {
        s16 local;
        struct S8009B45C *b;

        func_80077C50(i + 0x14, &local);
        b = D_8009B45C;
        if (b->ids[i] == idm && local != 0) {
            b->arr424[i] = a1v;
            func_80047864(i);
        }
    } while (++i < 4);
}
