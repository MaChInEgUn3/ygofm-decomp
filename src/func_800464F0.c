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

typedef struct {
    u8 pad0[0x4C];
    s16 count;
    u8 pad1[0x7C - 0x4E];
    u8 f7C;
    u8 f7D;
    u8 pad2[0x80 - 0x7E];
    u8 entries[1];
} S45C;

typedef struct {
    u32 words[12];
} Entry30;

extern S45C *D_8009B45C[16];
extern S45C *D_8009B45C[16];
extern S45C *D_8009B45C[16];
extern S45C *D_8009B45C[16];
extern S45C *D_8009B45C[16];
extern S45C *D_8009B45C[16];
extern S45C *D_8009B45C[16];
#define D_8009B45C (D_8009B45C[0])
#define D_8009B45C (D_8009B45C[0])
#define D_8009B45C (D_8009B45C[0])
#define D_8009B45C (D_8009B45C[0])
#define D_8009B45C (D_8009B45C[0])
#define D_8009B45C (D_8009B45C[0])
#define D_8009B45C (D_8009B45C[0])

void func_800464F0(void) {
    S45C *p;
    register s32 i asm("a2");
    register s32 j asm("a1");
    register s32 k asm("a3");
    s32 tag;
    register Entry30 *dst asm("v0");
    register u8 *src_base asm("v1");
    register Entry30 *src asm("a0");
    register s32 c29 asm("t2");
    register s32 c24 asm("t1");
    register s32 c2b asm("t0");

    p = D_8009B45C;
    i = 0;
    if (p->count <= 0) {
        goto tail_dispatch;
    }
    c29 = 0x29;
    c24 = 0x24;
    c2b = 0x2B;
    k = 0x30;
    j = i;

loop:
    if (p->count == 0) {
        goto tail_dispatch;
    }
    tag = p->entries[j];
    if (tag == c29) {
        goto match;
    }
    if (tag >= 0x2A) {
        goto high_range;
    }
    if (tag == c24) {
        goto match;
    }
    k += 0x30;
    goto advance;

high_range:
    if (tag != c2b) {
        goto no_match;
    }

match:
    p = D_8009B45C;
    dst = (Entry30 *)((u8 *)p + j);
    dst = (Entry30 *)((u8 *)dst + 0x80);
    src_base = (u8 *)p + k;
    src = (Entry30 *)(src_base + 0x80);
    *dst = *src;
    p = D_8009B45C;
    p->count = (u16)p->count - 1;
    goto tail_test;

no_match:
    k += 0x30;
advance:
    j += 0x30;
    i += 1;

tail_test:
    p = D_8009B45C;
    if (i >= p->count) {
        goto tail_dispatch;
    }
    if (i >= 0) {
        goto loop;
    }

tail_dispatch:
    {
        register S45C *tail_p asm("v0") = D_8009B45C;
        tag = tail_p->f7C;
    }
    if (tag == 0x29) {
        goto clear;
    }
    if (tag >= 0x2A) {
        goto check_2B;
    }
    if (tag == 0x24) {
        goto clear;
    }
    return;

check_2B:
    if (tag != 0x2B) {
        return;
    }

clear:
    D_8009B45C->f7C = 0;
    D_8009B45C->f7D = 0;
}
