#include "common.h"

void func_8001306C(void) {
    u8 *p;
    s32 i;

    func_800154E4();
    i = 0;
    func_80041340();
    p = D_800E9DB0;

    do {
        if (*(s32 *)p != 0) {
            (*(void (**)(void))p)();
        }
        i++;
        p += 4;
    } while (i < 4);

    if (D_8009B0B8 != 0) {
        (*(void (**)(void))&D_8009B0B8)();
    }

    if (D_8009B0B0 < D_8009B0A4 || D_8009B0BC < D_8009B0D4
        || --D_8009AF08 < 0) {
        D_8009AF08 = 0x3C;
        D_8009B0B0 = D_8009B0A4;
        D_8009B0BC = D_8009B0D4;
    }

    func_80014A5C(0);
    func_800136D4();
}
