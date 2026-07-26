#define D_8009B398_IS_AGGREGATE
#include "common.h"

s32 func_80017034(u8 *arg0) {
    s32 ok = 1;
    s32 f;

    if (D_800907D8[*(s8 *)(D_8009B1B4 + 0x10) * 5 +
                   *(s8 *)(D_8009B1B4 + 0xF)] >= 0x14) {
        f = *(u16 *)(arg0 + 0x16) & 0x1000;
        ok = f < 1;
    }

    if ((D_8009B398[0] & 0x10) && (*(u16 *)(arg0 + 0x16) & 0x8000) && ok) {
        return *(s16 *)(arg0 + 0xC);
    }

    return 0;
}
