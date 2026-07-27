#include "common.h"

u8 *func_8002C68C(s32 arg0) {
    u8 *v = func_8002C604(arg0);

    if (v != 0) {
        D_8009B260 |= 0x80;
    }

    return v;
}
