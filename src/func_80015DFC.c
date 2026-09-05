/* MATCH 2026-09-05, pure C at -O2 -G1 -msplit-addresses with the assembler
 * at -G1 (PER_FUNC_FLAGS / PER_FUNC_AS_FLAGS). Replaces a transcription
 * (raw lwc2/rtps/swc2 and register-pinned loads); the GTE goes through
 * include/gte.h like the matched sibling func_80015D18.
 *
 * The last instruction was the join block before the func_80016784 call:
 * retail opens it with `lui $v0,%hi(D_800E9D98)`, copies that lui into the
 * skip branch's delay slot, and completes the pair with `lw $a1,%lo($v0)`
 * two instructions later -- cc1psx's OWN pair, scheduled apart. The .data
 * attribute arm that had been used for this symbol gave the assembler's
 * expansion instead (adjacent, self-referencing through $a1), one short.
 * The listing has one %gp_rel, the one-byte D_8009B1D5, and D_800E9D98 is
 * four bytes: WORKFLOW's second recipe branch, real declarations and a -G
 * between the widths. -G1 and -G2 both match; -G4 is -2.
 * Earlier levers, kept: the GTE result read through a two-halfword struct,
 * the +0x30 halfword named before the scratch zero store, and the flag
 * named right after y.
 */
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
