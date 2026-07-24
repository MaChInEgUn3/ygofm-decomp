#include "common.h"

s32 func_80028260(s32 arg0) {
    if (arg0 & 0x80) {
        return (arg0 & 0x7F) + 0xF;
    }
    return arg0;
}
