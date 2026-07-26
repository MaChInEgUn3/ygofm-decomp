#include "common.h"

void func_80049308(void) {
    u8 *p = D_8009B45C;

    if (*(s16 *)(p + 0x157A) != 0) {
        u8 *q = *(u8 **)(p + 0x1564);
        s32 r = func_800496C4(q + 0x50, 0, *(s32 *)(q + 0xC));

        p = D_8009B45C;
        *(s16 *)(p + 0x157A) = r;

        if ((s16)r != 0) {
            *(s16 *)(p + 0x1578) = -1;
            *(s16 *)(p + 0x157A) = -1;

            return;
        }
    }

    {
        u8 *b = D_8009B45C;

        *(s16 *)(b + 0x1578) = **(u16 **)(b + 0x1564);
    }
}
