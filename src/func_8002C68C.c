#include "common.h"

s32 func_8002C68C(void) {
    s32 v = func_8002C604();

    if (v != 0) {
        D_8009B260 |= 0x80;
    }
    return v;
}
