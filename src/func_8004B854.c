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

struct S8009B458 {
    char pad[0x500];
    u8 field500;   /* 0x500 */
    char pad2[0x503 - 0x500 - 1];
    u8 flag;       /* 0x503 */
    s32 field504;  /* 0x504 */
};

extern struct S8009B458 *D_8009B458;

extern void func_800738B0(void);
extern void func_80073A54(s32 a);
extern s32 func_80073860(s32 a, s32 b, s32 c, void *d);
extern void func_80073890(s32 a);
extern void func_80073950(s32 a, s32 b, s32 c);
extern void func_80073A24(s32 a);
extern void func_800738C0(void);
void func_8004B734(void);

/* Re-entrancy guarded via D_8009B458->flag: opens stream 0xF2000002 with
   func_8004B734 as its callback, stores the returned handle, feeds it
   0xE000/0x1000 bytes, then tears the stream back down and clears both
   the guard flag and field500 before returning. */
void func_8004B854(void) {
    s32 handle;

    if (D_8009B458->flag) {
        return;
    }
    D_8009B458->flag = 1;
    func_800738B0();
    func_80073A54(0xF2000002);

    /* target evaluates a2 before starting a3's lui/addiu pair, and fills
       the jal's delay slot with a3's addiu; every C arg-order/hoisting
       variant tried instead computes a3 fully first and fills the delay
       slot with a2's li, so the call is hand-encoded here. */
    {
        register s32 h asm("v0");
        __asm__ volatile(
            ".word 0x3c04f200\n" /* lui   a0, 0xf200                  */
            ".word 0x34840002\n" /* ori   a0, a0, 2                   */
            ".word 0x24050002\n" /* li    a1, 2                       */
            ".word 0x24061000\n" /* li    a2, 4096                    */
            ".word 0x3c078005\n" /* lui   a3, 0x8005                  */
            ".word 0x0c01ce18\n" /* jal   func_80073860                */
            ".word 0x24e7b734\n" /* addiu a3, a3, -18636 (delay slot) */
            : "=r" (h)
            :
            : "at", "v1", "a0", "a1", "a2", "a3",
              "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7", "t8", "t9",
              "ra", "memory"
        );
        handle = h;
    }

    D_8009B458->field504 = handle;
    func_80073890(handle);
    func_80073950(0xF2000002, 0xE000, 0x1000);
    func_80073A24(0xF2000002);
    func_800738C0();
    D_8009B458->field500 = 0;
    D_8009B458->flag = 0;
}
