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

/* Clears an object's f34 "waiting" bit, reads the next opcode byte from its
   f58-indexed data stream, advances that stream pointer, and applies a
   speed setting for opcodes 1 and 2. Opcode 1 also re-sets the f34 bit. */

struct Obj {
    char pad0[0x34];
    u16 f34;
    char pad1[0x58 - 0x36];
    s8 f58;
    char pad2[0x5A - 0x59];
    u8 f5A;
    u8 f5B;
};

void func_800382A8(struct Obj *a0) {
    register struct Obj *a1 asm("a1") = a0;
    register s32 idx asm("v1") = a1->f58;
    register u16 flags asm("v0");
    u8 *p;
    s32 byte;

    flags = a1->f34;
    flags &= 0xFEFF;
    a1->f34 = flags;

    {
        register u8 **sp asm("v1") = (u8 **)a1 + idx;
        p = *sp;
        byte = *p;
        *sp = p + 1;
    }

    switch (byte) {
    case 1:
        a1->f5A = 8;
        a1->f5B = 8;
        break;
    case 2:
        a1->f5A = 8;
        a1->f5B = 0xC;
        break;
    }

    if (byte == 1) {
        flags = a1->f34;
        flags |= 0x100;
        a1->f34 = flags;
    }
}
