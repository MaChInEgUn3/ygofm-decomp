/* 63/63 and 15 differing (2026-09-08). RECONSTRUCTED: src/ holds an
 * ASSEMBLY-DEBT transcription (Unchiga's port) with three register pins and
 * two asm blocks, and the 15-difference C this tree had reached on its own in
 * August was never saved -- only its story survived, in the PARKED.txt entry
 * `func_80048F14_WAS`. This is that C rebuilt from the listing and from that
 * entry, and it lands on the same 15.
 *
 * The transcription is not needed. Its `move %0,%1` block reproduces retail's
 * `addu $a0,$a1,$zero` -- a copy of the 0x801EA800 it has just stored at
 * +0x1564 -- and the legal spelling is WORKFLOW's read-back rule: write the
 * 0xFFFF store as `*(u16 *)(*(s32 *)(q + 0x1564))`. The literal, one local
 * and two locals holding the same address all give no copy; only the
 * read-back does.
 *
 * Three things had to be right at once, and each is worth its own line:
 *   - the reverb attribute struct is 24 BYTES, not the twelve its four
 *     written fields need. At 12 the frame is -40 with $ra at 32 and retail
 *     has -48 with $ra at 40; 20 and 24 both give the right frame, 28 does
 *     not. gcc lays stack locals out in declaration order, so the frame is
 *     the cheapest thing in this function to get right and it dominated the
 *     count until it was (33 -> 29).
 *   - the 0xFFFF store must be `*(u16 *)` and not `*(s16 *)`: through s16 gcc
 *     reuses the -1 already in a register from the four stores above, which
 *     is an instruction short.
 *   - the base is read THREE times and the three reads want THREE NAMES.
 *     One name reassigned is 29; three names is 15, and two (the third group
 *     with its own) is also 15. Writing the symbol inline in the third group
 *     is +3 and 47.
 *
 * Residue, per the old entry and unchanged: retail puts the base reads in
 * $v0,$v0,$v1 with the constant 255 in $v1, we get the rotation, and the
 * 0x1582 store schedules before the third read instead of after it. All six
 * orderings of the second group were measured in August -- three give 15 and
 * three are an instruction worse. The debt is NOT retired until this matches.
 */
#define D_8009B45C_IS_SCALAR
#include "common.h"

typedef struct {
    s32 mask;
    s32 mode;
    s16 depthL;
    s16 depthR;
    u8 rest[12];
} RevAttr;

void func_80076790(s32 arg0);
void func_80075BE0(s32 arg0);
void func_80075DE0(RevAttr *arg0);
void func_80049594(s32 arg0);
void func_80049600(s32 arg0);
void func_80049544(void);

void func_80048F14(void) {
    RevAttr fr;
    u8 *q;
    u8 *r;
    u8 *t;

    func_80076790(1);
    func_80075BE0(1);
    fr.mask = 7;
    fr.mode = 2;
    fr.depthL = 0x7FFF;
    fr.depthR = 0x7FFF;
    func_80075DE0(&fr);

    q = D_8009B45C;
    *(s16 *)(q + 0x1586) = 0;
    *(s16 *)(q + 0x1588) = 0;
    q[0x158A] = 0;

    r = D_8009B45C;
    *(s16 *)(r + 0x1580) = 0xFF;
    r[0x1584] = 0xFF;
    *(s16 *)(r + 0x1582) = 0;

    t = D_8009B45C;
    *(s32 *)(t + 0x1564) = 0x801EA800;
    *(s32 *)(t + 0x1560) = 0x801E2000;
    *(s16 *)(t + 0x1578) = -1;
    *(s16 *)(t + 0x157A) = -1;
    *(s16 *)(t + 0x157C) = -1;
    *(s16 *)(t + 0x157E) = -1;
    *(u16 *)(*(s32 *)(t + 0x1564)) = 0xFFFF;
    *(s16 *)(*(s32 *)(t + 0x1564) + 2) = 0;
    *(s32 *)(*(s32 *)(t + 0x1564) + 4) = 0;
    *(s32 *)(*(s32 *)(t + 0x1564) + 8) = 0;
    *(s32 *)(*(s32 *)(t + 0x1564) + 0xC) = 0x40000;
    func_80049594(2);

    func_80049600(0x14);
    func_80049544();
}
