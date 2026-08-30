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

/* Blacklist reclamation (blacklist.txt:682). Rebuilt from scratch (old
   sketch lost); the sole m2c-misdecoded ".word" line is a real `j` to the
   shared epilogue (not a fake call), confirmed by hand-decoding.

   Assignment-style matcher: copies the 5-value multiset
   D_8009B1C8->arr1A[0..4] (sign-extended bytes) into a local s16[5]
   buffer, then for each a3 in [0x11,0x16) greedily scans the buffer for
   the FIRST not-yet-consumed (>=0) entry whose table lookup
   (D_8015C424 byte-indexed by entry*6, offset +0x48000+0x39FC, func_800738F0 as
   s16) equals a3; marks that slot consumed (-1) and moves to the next
   a3. If any a3 finds no match before the buffer is exhausted, returns 0
   early; if all 5 a3 values match, returns 1. The +0x48000+0x39FC
   constant is reproduced as-is (unexplained semantically, confirmed
   correct by byte match).

   LANDED 0/47. Old best was 7/47 (44w, 3 words short), documented as two
   stacked residuals (a register-role swap in loop 1, and a "-1 marker
   materialization" scheduling issue matching
   project_cse_reuses_equal_zero_register). Neither turned out to be the
   real blocker once the table lookup's addressing was fixed:

   THE REAL FIX: `D_8015C424 + entry*6 + 0x48000 + 0x39FC` (any pointer-
   arithmetic phrasing of it) gets constant-folded by gcc into a single
   absolute address (`D_8015C424 + 0x4B9FC` = `0x801A7E20`, folded to a
   plain `lui 0x801a; addiu 0x7e20`) -- target instead keeps D_8015C424 as
   the symbol and splits the 0x4B9FC offset the way gcc's own MIPS address
   legitimiser does (`lui 0x4; ori 0x8000` for the aligned part, 0x39FC as
   the load's immediate displacement), which only happens when the offset
   is a STRUCT MEMBER offset on a symbol declared as the struct itself --
   exactly project_struct_member_offset_defeats_symbol_fold, already
   solved once on the sibling src/func_80027DF8.c (SAME D_8015C424/
   0x4B9FC/0x801A7E20 constants, reused verbatim below):
       struct Blob { u8 pad0[0x4B9FC]; struct R6 cards[1]; };
       extern struct Blob D_8015C424;
       ... D_8015C424.cards[n].id
   Applying that alone took the old 7/47-with-two-func_800738D0-questions state
   to 4/47 -- and with the addressing fixed, the previously-documented
   "-1 marker" issue disappeared on its own: a PLAIN `buf[i] = -1;`
   (no register pin, no asm, nothing from the cse_reuses_equal_zero_
   register family) landed the last 4 words cleanly. That family's fix
   was tried FIRST here too (non-volatile raw-asm `li`, plain and
   register-pinned) and made things WORSE (11/48) -- a reminder that a
   documented residual diagnosed against the WRONG root cause (here, the
   real blocker was the address fold, not the -1 materialization) can
   send the next attempt chasing the wrong lever entirely; re-derive from
   the actual first divergence rather than trusting an old note's framing
   once a bigger structural fix changes the surrounding code. */

struct SomeState {
    char pad[0x1A];
    s8 arr1A[5];
};

extern struct SomeState *D_8009B1C8;

struct R6 {
    s16 id;
    u8 b2;
    u8 pad3[3];
};

struct Blob {        /* the `cards` member sits 0x4B9FC into the object,
                         matching src/func_80027DF8.c's own D_8015C424
                         struct -- see that file for the offset-fold
                         func_80073900-up (project_struct_member_offset_defeats_
                         symbol_fold) */
    u8 pad0[0x4B9FC];
    struct R6 cards[1];
};

extern struct Blob D_8015C424;

s32 func_80018CF8(void) {
    s16 buf[5];
    s32 i;
    s32 a3;

    for (i = 0; i < 5; i++) {
        buf[i] = D_8009B1C8->arr1A[i];
    }

    for (a3 = 0x11; a3 < 0x16; a3++) {
        for (i = 0; i < 5; i++) {
            s16 v1 = buf[i];
            if (v1 >= 0) {
                s16 v0 = D_8015C424.cards[v1].id;
                if (v0 == a3) {
                    buf[i] = -1;
                    goto found;
                }
            }
        }
        return 0;
    found:;
    }

    return 1;
}
