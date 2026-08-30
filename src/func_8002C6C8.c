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

/* RENAMED func_8002C6C8 (was func_8002C6C8) -- live func_80073900-trace
   2026-08-28, user RE notes (relayed via dev-80/overseer): reads the phase
   s16 at 0x800EADA0 (this file's rec->f18, offset 0x18 into D_800EAD88[]'s
   0x20-byte stride, matching 0x800EADA0-0x800EAD88=0x18) and jal's the
   disc-streamed overlay dispatcher at 0x801462B0 (func_801462B0 below).

   SEAM DOCUMENTATION (base-EXE<->overlay boundary, USER PRIORITY DIRECTIVE
   #1, 2026-08-29): this is the READER/DISPATCHER half of the seam, paired
   with the PHASE WRITER half in src/alloc_init_pool_entry_800ead88.c
   (func_8002C604) -- that function's instruction at 0x8002C638
   (`sh s0,24(a0)`) is what originally stamps a freshly-allocated
   D_800EAD88[] record's f18 with its phase value, using the a0 parameter
   passed in by func_8002C604's own caller. This function then walks every
   in-use record and, per-record, hands f18 (the phase), the record's
   PRE-reset f1A, f14, and the record pointer itself across the seam via
   `func_801462B0(rec->f18, savedF1A, rec->f14, rec)` -- func_801462B0 is
   the disc-streamed overlay dispatcher (0x8014xxxx-0x8015xxxx region,
   currently nops in asm_803E0.s; see w5's overlay-split lane), so
   rec->f18 (the phase) is literally the value the base EXE hands into
   overlay code to say which duel phase is active. Live capture evidence
   (opponent-turn-2026-08-20_134333/opponent_turn.pst, func_800738F0 directly via
   `tools/scout.py peek 0x800EADA0 4 --ram ...`): pool slot 0's f18 reads
   0x0002 during an opponent-turn snapshot -- direct confirmation that
   phase value 2 is live while it is the opponent's turn. Per the user's
   relayed RE notes, phases 2 AND 3 both denote "opponent turn" (the two
   halves of the opponent's turn sequence, e.g. draw/setup then
   action -- not independently re-derived from the capture, which only
   caught phase 2 live; phase 3 is the directive's own evidence). Phases
   0/1 are presumed the player's own turn by the same pairing, unconfirmed
   here. See src/alloc_init_pool_entry_800ead88.c's header for the writer
   side's own notes, including the caller-of-func_8002C604 lead (whichever
   caller passes phase 2/3 is an entry point into "opponent turn begins"
   from the base-EXE side, worth chasing next). */

/* Clears D_8009B260's bit 0x1, then walks all 8 D_800EAD88[] records. For
   each record whose f1C flags byte has 0x80 set: raises D_8009B260's bit 0
   unless f1C also has 0x20 set; clears D_8009B261; if f1C's 0x40 bit isn't
   set yet, sets it and resets f1A to -1; copies D_800E9D90.f4/f8 into
   f18record's fC/f8, stashes the record pointer at D_8009B264, and calls
   func_801462B0(f18, the ORIGINAL f1A func_800738F0 before the possible reset,
   f14, record) followed by func_800878B0(0,0) and func_800878D0 using
   D_800F2848's projection field; if D_8009B261 ends up 1, clears f1C back
   to 0. Returns D_8009B260's bit 0.

   savedF1A must be s32, not the field's true s16 type -- declaring it s16
   makes gcc emit an unsigned reload + manual sign-extend at the call site
   instead of the target's plain signed halfword load. */
struct Rec {
    char pad0[0x8];
    s32 f8;
    s32 fC;
    char pad1[0x14 - 0x10];
    s32 f14;
    s16 f18;
    s16 f1A;
    u8 f1C;
    char pad2[0x20 - 0x1D];
};

struct D800E9D90Type {
    char pad[0x4];
    s32 f4;
    s32 f8;
};

struct D800F2848Type {
    char pad[0xE];
    s16 fE;
};

extern struct Rec D_800EAD88[8];
extern struct D800E9D90Type D_800E9D90;
extern struct D800F2848Type D_800F2848;
extern u8 D_8009B260;
extern u8 D_8009B261;
extern struct Rec *D_8009B264;
extern void func_801462B0(s16 a0, s16 a1, s32 a2, struct Rec *a3);
extern void func_800878B0(s32 a0, s32 a1);
extern void func_800878D0(s32 a0);

s32 func_8002C6C8(void) {
    struct Rec *rec;
    s32 i;

    D_8009B260 = D_8009B260 & 0xFE;

    rec = &D_800EAD88[0];
    for (i = 8; i != 0; i--) {
        u8 flags1 = rec->f1C;
        if (flags1 & 0x80) {
            u8 flags2;
            s32 savedF1A;

            if (!(flags1 & 0x20)) {
                D_8009B260 = D_8009B260 | 1;
            }
            D_8009B261 = 0;
            flags2 = rec->f1C;
            savedF1A = rec->f1A;
            if (!(flags2 & 0x40)) {
                rec->f1C = flags2 | 0x40;
                rec->f1A = -1;
            }
            rec->fC = D_800E9D90.f4;
            D_8009B264 = rec;
            rec->f8 = D_800E9D90.f8;
            func_801462B0(rec->f18, savedF1A, rec->f14, rec);
            func_800878B0(0, 0);
            func_800878D0(D_800F2848.fE);
            if (D_8009B261 == 1) {
                rec->f1C = 0;
            }
        }
        rec++;
    }

    return D_8009B260 & 1;
}
