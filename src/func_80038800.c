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

/* Script-byte dispatcher (same cursor-array struct pattern as the
   read_stream_byte_multi_to_field81.c family). Reads a raw byte,
   advances+stores the cursor unconditionally, dispatches on the low 7
   bits (opcode 0 vs non-zero), then both paths share one tail testing
   the raw byte's top bit. */

extern void func_8003FF34(void);
extern void func_8003FF58(void);
extern s32 D_8009B350;

struct Obj {
    char pad0[0x51];
    u8 field51;
    char pad52[0x58 - 0x52];
    s8 field88;
};

void func_80038800(struct Obj *obj) {
    s8 idx;
    register u8 **slot asm("v0");
    u8 *ptr;
    u32 raw;
    u32 s0;
    register u32 opcode asm("a0");
    u32 v0;

    idx = obj->field88;
    slot = (u8 **) ((char *) obj + (idx << 2));
    ptr = *slot;
    raw = *ptr;
    ptr = ptr + 1;
    s0 = raw;
    opcode = s0 & 0x7F;
    *slot = ptr;
    if (opcode == 0) {
        func_8003FF34();
        goto shared_test;
    }
    func_8003FF58();
shared_test:
    v0 = s0 & 0x80;
    if (v0 != 0) {
        obj->field51 = 13;
        D_8009B350 = 1;
    }
}
