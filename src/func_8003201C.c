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

// Builds a per-id active-record histogram: for each id 0..0x2D2, counts how
// many of the 40 records at a0+0x2D54 (id s16 @+0, active flag @+9, stride
// 0x10) are active and have that id, storing the count into the byte table
// at a0+0x5AC4. Then separately counts the number of leading active records
// in the 40-entry array at a0+0x2D50 (active flag @+0xD, stride 0x10),
// stopping at the first inactive one, and stores that count at a0+0x5AA0.
void func_8003201C(u8 *a0) {
    a0[0x5AC4] = 0;

    {
        register s32 a2 asm("a2") = 1;
        u8 *t0 = a0 + a2;

        for (; a2 < 0x2D3; a2++, t0++) {
            s32 a1;
            u8 *v1;
            register u8 *a3 asm("a3");

            t0[0x5AC4] = 0;
            a1 = 0;
            a3 = t0;
            v1 = a0 + 0x2D54;

            for (; a1 < 0x28; a1++) {
                if (v1[9] != 0) {
                    if (*(s16 *)v1 == a2) {
                        a3[0x5AC4] = a3[0x5AC4] + 1;
                    }
                }
                v1 += 0x10;
            }
        }
    }

    {
        register u8 *v1 asm("v1") = a0 + 0x2D50;
        register s32 a1 asm("a1") = 0;
        register s32 a2 asm("a2");

        for (a2 = 0; a2 < 0x28; a2++) {
            if (v1[0xD] == 0) {
                break;
            }
            a1++;
            v1 += 0x10;
        }

        *(s32 *)(a0 + 0x5AA0) = a1;
    }
}
