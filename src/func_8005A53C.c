#include "common.h"

void func_8005A53C(s32 (*fn)(s32), u8 *e, s32 arg2, s32 n) {
    s32 i;
    s32 t;
    s32 v;
    s32 kind;
    s32 step;
    s32 r;

    for (i = n - 1; i != -1; i--) {
        t = func_800601D0(*(s32 *)e);
        v = *(s32 *)(e + 4);
        kind = t >> 24;
        step = (v & 0xFFFF) + 1;
        v &= 0xFFFF0000;
        if (((u32)kind < 2 && (t & 0xFFFF) != 0 && v != 0)
            || (kind == 1 && (t & 0xFFFF) == 0)) {
            r = fn(*(s32 *)e);
            if (r != -1) {
                *(s32 *)e = r;
            }
        }
        e += step * 4;
    }
}
