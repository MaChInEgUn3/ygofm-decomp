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

struct Entry {
    u8 f0;      /* 0x11 marks this slot as the current CD-track notification */
    u8 pad[0x30 - 1];
};

struct S8009B45C {
    char pad0[0x4A];
    u8 f4A;     /* 0x80 bit gates the whole function */
    char pad1[0x4C - 0x4B];
    s16 f4C;    /* current track/entry index */
    char pad2[0x80 - 0x4E];
    struct Entry arr[16];
};

extern struct S8009B45C *D_8009B45C;
extern void func_8004503C(s16 a0, s32 a1, s32 a2);
extern void func_80045BE8(u8 *a0);

/* If D_8009B45C's 0x80 status bit is set and none of the current entry or its
   (up to) two predecessors are already tagged 0x11, marks the CD state via
   func_8004503C(-0x20, 0, 1) and notifies func_80045BE8 with a fresh
   0x11-tagged packet. */
void func_80045114(void) {
    struct S8009B45C *p = D_8009B45C;
    s32 count;

    if ((p->f4A & 0x80) == 0) {
        return;
    }
    count = p->f4C;
    if (p->arr[count].f0 == 0x11) {
        return;
    }
    if (count > 0) {
        if (p->arr[count - 1].f0 == 0x11) {
            return;
        }
        if (count >= 2) {
            if (p->arr[count - 2].f0 == 0x11) {
                return;
            }
        }
    }
    func_8004503C(-0x20, 0, 1);
    {
        u8 local[0x30];
        local[0] = 0x11;
        func_80045BE8(local);
    }
}
