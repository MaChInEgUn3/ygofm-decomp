#include "common.h"

void func_8003FF08(s32 arg0) {
    s32 v = arg0 | 0x7000;

    func_80047314(v & 0xFFFF);
    D_8009B400 = v;
}
