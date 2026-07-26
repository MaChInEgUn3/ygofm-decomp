#include "common.h"

/* The prototype is s32 because seven callers pass one; the parameter is an
   object pointer and is cast here rather than retyping the chain. */
void func_8004020C(s32 arg0) {
    u8 *p = (u8 *)arg0;
    s32 c = D_8009B410;
    s32 a = *(s16 *)p;
    s32 b = *(s16 *)(p + 2);

    D_8009B410 = c + 1;

    if (a < 0) {
        *(s16 *)(D_800EFE38 + *(s16 *)(p + 0x1E) * 2) = b;
        if (b >= 0) {
            D_800EFE48[b].unk0 = -1;
        }
    } else {
        D_800EFE48[a].unk2 = b;
        if (b >= 0) {
            D_800EFE48[b].unk0 = a;
        }
    }

    *(u16 *)(p + 8) = 0;
}
