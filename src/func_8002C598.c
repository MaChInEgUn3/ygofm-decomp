#include "common.h"

void func_8002C598(void) {
    u8 *p = D_800EAD88;
    s32 i;

    D_8009B260 = 0;

    for (i = 8; i != 0; i--) {
        p[0x1C] = 0;
        *(s16 *)(p + 0x18) = -1;
        p += 0x20;
    }
}
