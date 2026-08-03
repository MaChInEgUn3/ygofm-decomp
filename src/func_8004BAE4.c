#include "common.h"

s32 func_8004BAE4(u8 *p) {
    u8 *b = D_8009B458;
    s32 i = *(s32 *)p;
    s32 v = *(u8 *)(*(s32 *)(b + 0x7DC) + i);

    i = i + 1;
    *(s32 *)p = i;
    if (*(u32 *)(b + 0x7EC) < (u32)i) {
        p[0x24] = 1;
        return -1;
    }
    return v;
}
