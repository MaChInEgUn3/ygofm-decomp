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

struct Obj {
    u8 pad[4];
    u8 field4;
    u8 field5;
    u8 field6;
    u8 field7;
    u16 field8;
};

extern struct Obj D_800E9EC8[];
extern u8 D_8009B141;
extern void func_800156B8(int a0);
extern void func_8001572C(void);

/* Resets field5/field6/field8, masks the top bit off D_8009B141, then calls
   func_800156B8(field4) and func_8001572C() before setting field7. */
void func_80015780(void) {
    u8 v0;
    int a0;

    D_800E9EC8[0].field5 = 0xFF;
    D_800E9EC8[0].field6 = 0x80;
    v0 = D_8009B141;
    a0 = D_800E9EC8[0].field4;
    D_800E9EC8[0].field8 = 0;
    v0 &= 0x7F;
    D_8009B141 = v0;
    func_800156B8(a0);
    D_800E9EC8[0].field7 = 0xC;
    func_8001572C();
}
