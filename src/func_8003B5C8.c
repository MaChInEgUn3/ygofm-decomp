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

extern u8 D_800100A8[];
extern s32 D_801D9004[];
extern u16 D_800EAFF8[];

void func_8003B5C8(void) {
    u8 buf[20];
    register u8 *out_page asm("v0") = (u8 *) 0x800F0000;
    register u16 *out asm("t1");
    register s32 off asm("t0");
    register u8 *lo asm("a3");
    register u8 *end asm("t4");
    register u8 *page asm("t2");
    register s32 first asm("t3");

    __asm__ volatile ("" : "+r" (out_page));
    out = (u16 *) (out_page - 0x5008);
    __asm__ volatile ("" : "+r" (out));
    off = 1;
    __asm__ volatile ("" : "+r" (off));
    lo = buf;
    __asm__ volatile ("" : "+r" (lo));
    end = buf + 20;
    __asm__ volatile ("" : "+r" (end));
    page = (u8 *) 0x801E0000;
    __asm__ volatile ("" : "+r" (page));
    first = *(s32 *) (page - 0x6FFC);
    __builtin_memcpy(buf, D_800100A8 + 0x288, 20);

    do {
        u8 *entry = page - 0x6FFC;
        register u16 k asm("a1") = 1;
        register u8 *hi asm("v0") = buf + off;
        register s32 pair asm("v1");

        __asm__ volatile ("" : "+r" (entry));
        __asm__ volatile ("" : "+r" (k));
        __asm__ volatile ("" : "+r" (hi));
        pair = *lo;
        pair = (pair << 8) | *hi;
        if (first != 0) {
            register u16 *dst asm("a2") = out;

            __asm__ volatile ("" : "+r" (dst));
            __asm__ volatile ("" : : "g" (&&store), "g" (&&more));
        scan:
            if (pair != *(u16 *) entry) {
                goto more;
            }
        store:
            *dst = k;
            goto no_match;
        more:
            __asm__ volatile ("");
            entry += 4;
            if (*(s32 *) entry != 0) {
                k++;
                goto scan;
            }
        no_match:;
        }

        out++;
        lo += 2;
        off += 2;
    } while ((s32) lo < (s32) end);
}
