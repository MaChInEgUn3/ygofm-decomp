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

/* Same D_801A7AD8[] table as func_8002C9B4.c (f0/f16) and
   table801a7ad8_row_search.c (idxVal at 0xC). D_801799D8[] is a small table
   of 5-u16 records: a key followed by 3 idxVal requirements and a trailing
   field. */
struct Rec {
    void *f0;
    u8 pad0[0xC - 4];
    s16 idxVal;
    u8 pad1[0x16 - 0xE];
    u16 f16;
    u8 pad2[0x1C - 0x18];
};

struct Out {
    void *f0;
    void *f4;
    void *f8;
    s32 fC;
};

extern u8 D_8009B1D5[];
extern struct Rec D_801A7AD8[];
extern u16 D_801799D8[];

/* Finds the D_801799D8[] record whose key matches `key` (0 if none), then
   scans the current side's 5-row slice of D_801A7AD8 (row 0x14, or row 5
   when D_8009B1D5 is set) for up to 3 active rows whose idxVal matches the
   record's next 3 u16 fields in turn, consuming each matched row so it
   cannot be reused. Returns 0 if any of the 3 requirements has no active
   row. On success, if `out` is non-NULL, copies the 3 matched rows' f0
   pointers into out->f0/f4/f8 and clears out->fC; either way returns the
   record's 3rd requirement value. */
u16 func_8002C7E8(struct Out *out, s32 key) {
    struct Rec *found[4];
    struct Rec *cand[5];
    register u16 *e asm("t4");
    u16 *pk;
    struct Rec *slot;
    struct Rec *obj;
    struct Rec **p;
    struct Rec **q;
    struct Rec **cbase;
    struct Rec **o;
    void **d;
    s32 base;
    s32 i;
    s32 k;

    {
        register u16 *rtmp asm("v0");
        __asm__ volatile (
            "lui %0, %%hi(D_801799D8)\n\t"
            "addiu %1, %0, %%lo(D_801799D8)"
            : "=r"(rtmp), "=r"(e)
        );
    }
    while (1) {
        if (e[0] == 0) {
            return 0;
        }
        if (e[0] == key) {
            break;
        }
        e += 5;
    }

    {
        register s32 rbase asm("a3");
        register s32 roff asm("v1");
        rbase = D_8009B1D5[0] ? 0x14 : 5;
        roff = rbase * 28;
        base = rbase;
        slot = (struct Rec *)((char *)D_801A7AD8 + roff);
    }

    {
        register struct Rec **qq asm("v1");
        register struct Rec *sslot asm("a1");
        register s32 ri asm("a3");
        asm volatile("" ::: "memory");
        ri = 0;
        qq = cand;
        sslot = slot;
        for (; ri < 5; ri++) {
            *qq = 0;
            if (sslot->f16 & 0x8000) {
                *qq = sslot;
            }
            qq++;
            sslot++;
        }
        slot = sslot;
    }

    e++;
    pk = e;
    {
        register struct Rec **rcbase asm("t5");
        register struct Rec **ro asm("t2");
        register s32 rk asm("t3");
        register struct Rec **rp asm("t0");
        register s32 ri asm("a3");
        register u16 *rpk asm("t1");
        rk = 0;
        rcbase = cand;
        ro = (struct Rec **) &found[0];
        rpk = pk;
        do {
            ri = 0;
            rp = rcbase;
            do {
                q = rp;
                obj = *q;
                if ((obj != 0) && (obj->idxVal == rpk[0])) {
                    goto hit;
                }
                rp = q + 1;
                ri++;
            } while (ri < 5);
            return 0;
        hit:
            *ro = obj;
            ro++;
            rpk++;
            rk++;
            *rp = 0;
        } while (rk < 3);
    }

    if (out != 0) {
        register s32 ri asm("a3");
        ri = 0;
        d = (void **) out;
        o = (struct Rec **) &found[0];
        for (; ri < 3; ri++) {
            *d = (*o)->f0;
            o++;
            d++;
        }
        out->fC = 0;
    }
    return e[3];
}
