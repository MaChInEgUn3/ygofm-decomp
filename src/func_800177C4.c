#include "common.h"
#include "gte.h"

void func_800177C4(void) {
    struct { u16 x; s16 y; } r;
    s16 *scratch;
    u8 *dst;
    u8 *src;
    s32 i;
    s16 x;
    s32 y;
    s32 f;
    void *pr;

    func_800878D0(D_800F2856[0]);
    func_800878B0(0xA0, 0x6C);
    func_800855D0(D_800FE148);

    scratch = (s16 *)0x1F8003E0;
    i = 0;
    pr = &r;
    dst = (u8 *)D_800EA070;
    src = (u8 *)D_800908A0;
    do {
        x = *(u16 *)src;
        scratch[1] = 0;
        scratch[0] = x;
        scratch[2] = *(u16 *)(src + 2);
        gte_ldv0(scratch);
        gte_rtps();
        gte_stsxy(pr);

        *(s16 *)dst = r.x - 0x1A;
        y = r.y;
        f = D_8009B1D5;
        *(s16 *)(dst + 2) = y - 0x1E;
        if (f != 0) {
            if (i < 15) {
                *(s16 *)(dst + 2) = y - 0x1D;
            }
        } else {
            if (i >= 15) {
                *(s16 *)(dst + 2) = y - 0x1D;
            }
        }
        dst += 4;
        i++;
        src += 4;
    } while (i < 30);

    func_800878B0(0, 0);
}
