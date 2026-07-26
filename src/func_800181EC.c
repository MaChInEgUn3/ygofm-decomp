#include "common.h"

s32 func_800181EC(u8 *arg0) {
    s32 v = 1;

    switch (arg0[0x68]) {
    case 0x14:
    case 0x17:
        v = 2;
        break;
    case 0x15:
        v = 3;
        break;
    case 0x16:
        v = 4;
        break;
    }

    if (arg0[0x22] != 0) {
        v |= 0x80;
    }

    return v;
}
