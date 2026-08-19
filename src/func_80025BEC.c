#define D_8009B260_SIZED
#include "common.h"

/* Recipe branch 3, and the widths decide it before any C is written: the
 * function keeps three symbols %gp_rel (a four-byte pointer, a halfword and
 * a byte) while D_8009B260 has to be bare. The bare one is the NARROWEST,
 * so no real threshold exists -- its declaration is inflated to eight and
 * the assembler runs at -G4, which is the only window (4 <= G < 8). Read
 * that off the listing and the function came out first try. */

void func_80025BEC(void) {
    u8 *q;
    u8 *r;
    u8 *e;
    s32 f;
    s32 i;
    s32 n;

    if (func_80024E24() == 0) {
        q = func_8002C604(0x13);
        *(s16 *)q = 0xA0;
        D_8009B17C = q;
        *(s16 *)(q + 2) = 0x68;
        func_8003FEE0(0x13);
        return;
    }

    f = D_8009B220;

    if ((f & 0x40) == 0) {
        if (D_8009B17C[0x1D] != 0) {
            D_8009B220 = f | 0x40;
            func_8003FEE0(0x1D);

            for (i = 5; i < 0xF; i++) {
                n = D_800907D8[i + D_8009B1D5 * 20];
                r = D_801A7AD8 + n * 28;
                if ((*(s32 *)(r + 0x14) & 0x90000000) == 0x90000000) {
                    e = *(u8 **)r;
                    *(s32 *)(e + 0x24) = (s32)func_80025B28;
                    e[0x6C] = 1;
                }
            }
        }
    }

    if ((D_8009B260[0] & 1) == 0) {
        if (func_80042B40(1) == 0) {
            D_8009B220 = 0;
        }
    }
}
