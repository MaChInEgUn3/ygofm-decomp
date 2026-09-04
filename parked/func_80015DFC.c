/* -1 at 61/62, 18 differing. First REAL C written for this function
 * 2026-09-04 (src/ holds Unchiga's transcription: raw lwc2/rtps/swc2 plus
 * register-pinned lhu/lh). The GTE is reached through include/gte.h, the way
 * the matched sibling func_80015D18 does it.
 *
 * Four levers, in the order the residue gave them up:
 *   +4 -> +2  the GTE result as `struct { u16 x; s16 y; } r` read through
 *             gte_stsxy(&r); an s32 with casts reads y as lhu+sll+sra.
 *   +2 -> +1  `s16 x = *(u16 *)(in + 0x30);` NAMED before `scratch[1] = 0;`
 *             (the sibling's shape; retail issues that load before the zero
 *             store, and inline it costs a load-delay nop).
 *   +1 -> -2  `f = D_8009B1D5;` named right after `y = r.y;` -- retail reads
 *             the flag immediately after the lh of y so its delay is covered
 *             and the fieldA store lands in the beq's slot. Without this name
 *             everything else is +2 (h4).
 *   -2 -> -1  D_800E9D98 declared into .data (new D_800E9D98_IN_DATA arm in
 *             variables.h): retail has cc1psx's own %hi/%lo pair, and the
 *             function's one gp-relative flag has to stay gp-relative, so the
 *             per-symbol form is the only one that fits.
 *
 * The residue is the JOIN BLOCK before the func_80016784 call. Retail's block
 * begins with `lui $v0,%hi(D_800E9D98)`, and the else-arm's skip branch jumps
 * to that label+4 with the lui copied into its delay slot -- so retail has two
 * luis and we have one, and the first 46 instructions are byte-identical.
 * Ours begins the block with the inner-pointer reload and fills that slot
 * with the fall-through's `addiu -29` instead. Measured 2026-09-04, all -1
 * and 18 unless noted:
 *   D_800E9D98 named just before the call (g1)                     -1, 18
 *   the same named at the top of the function (g2)                +1, 54
 *   the inner pointer named just before the call (g3)              -1, 18
 *   both named, global first (g4)                                  -1, 18
 *   both calls written in both arms (h1)                           -1, 18
 *   only func_80016784 written in both arms (h2)                   -1, 18
 *   the then-arm ending in an explicit `goto call;` (h3)           -1, 18
 * The five identical scores are the wrong-axis tell: gcc merges every one of
 * those back to the same join and makes the same delay-slot choice. What
 * decides which insn the filler copies -- the target block's lui or the
 * fall-through's addiu -- has not been found at source level.
 */
#define D_800E9D98_IN_DATA
#include "common.h"
#include "gte.h"

void func_80015DFC(u8 *arg0) {
    struct { u16 x; s16 y; } r;
    s16 *scratch;
    u8 *in;
    s32 y;
    s16 x;
    s32 f;

    func_800855D0(D_800FE148);

    scratch = (s16 *)0x1F8003E0;
    in = *(u8 **)arg0;
    x = *(u16 *)(in + 0x30);
    scratch[1] = 0;
    scratch[0] = x;
    scratch[2] = *(u16 *)(*(u8 **)arg0 + 0x34);
    gte_ldv0(scratch);
    gte_rtps();
    gte_stsxy(&r);

    *(s16 *)(arg0 + 8) = r.x - 0x1A;
    y = r.y;
    f = D_8009B1D5;
    *(s16 *)(arg0 + 0xA) = y - 0x1E;

    if (f != 0) {
        if (*(s8 *)(arg0 + 0x18) < 15) {
            *(s16 *)(arg0 + 0xA) = y - 0x1D;
        }
    } else {
        if (*(s8 *)(arg0 + 0x18) >= 15) {
            *(s16 *)(arg0 + 0xA) = y - 0x1D;
        }
    }

    func_80016784(*(u8 **)arg0, D_800E9D98, *(s16 *)(arg0 + 8), *(s16 *)(arg0 + 0xA));
    func_800878B0(0xA0, 0x6C);
}
