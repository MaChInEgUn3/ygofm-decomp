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

/* Sets D_800F2C40[idx]'s field_e06 to val<<4, then for each of its
   field_e1b pointer-array entries calls func_8004DC38 with the (possibly
   flag-overridden) field_bf5 byte and the new field_e06 value, re-reading
   field_e1b each iteration since the callee can grow it. Finally latches
   field_bf5 to flag if set and clears field_dce. */

typedef struct {
    u8 pad[0x1E0];
    void *ptrs[1]; /* 0x1E0, 4-byte-stride array of pointers */
    u8 pad2[0xBF5 - 0x1E0 - 4];
    u8 field_bf5; /* 0xBF5 */
    u8 pad3[0xDCE - 0xBF5 - 1];
    u16 field_dce; /* 0xDCE */
    u8 pad4[0xE06 - 0xDCE - 2];
    u16 field_e06; /* 0xE06 */
    u8 pad5[0xE1B - 0xE06 - 2];
    u8 field_e1b; /* 0xE1B */
    u8 pad6[0xE20 - 0xE1B - 1];
} RecD800F2C40;

extern RecD800F2C40 D_800F2C40[];
extern s32 func_8004DC38(void *a0, s32 a1, s32 a2, s32 a3);

void func_800597C8(s32 idx, s32 flag, s32 val) {
    s32 i = 0;
    RecD800F2C40 *rec = &D_800F2C40[idx];
    s32 count;

    count = rec->field_e1b;
    rec->field_e06 = val << 4;
    __asm__ volatile("");

    if (count != 0) {
        s32 arg3 = rec->field_e06;

        do {
            s32 arg2 = rec->field_bf5;

            if (flag != 0) {
                u8 *entry = rec->ptrs[i];
                arg2 = flag;
                entry[0xC] = flag;
            }

            func_8004DC38(rec, i, arg2, arg3);
            count = rec->field_e1b;
            i++;
        } while (i < count);
    }

    if (flag != 0) {
        rec->field_bf5 = flag;
    }
    rec->field_dce = 0;
}
