#include "common.h"

void func_8003BC40(u8 *arg0, u8 *arg1, s32 arg2) {
    s32 i;

    for (i = arg2 - 1; i >= 0; i--) {
        if (*(u16 *)(arg1 + i * 2) != 0) {
            arg2 = i + 1;
            break;
        }
    }
    for (i = 0; i < arg2; i++, arg1 += 2) {
        s32 w = *(u16 *)arg1;
        s32 idx = (w != 0);
        u32 *e = &D_801D9000[idx];
        u32 v = *e;

        goto test;
    big:
        arg0[0] = (idx >> 8) | -0x10;
        arg0[1] = idx;
        arg0 += 2;
        goto next;
    body:
        if (*(u16 *)e == w) {
            if (idx < 0xF0) {
                *arg0 = idx;
                goto bump;
            }
            goto big;
        }
        e++;
        v = *e;
        idx++;
    test:
        if (v != 0) {
            goto body;
        }
        *arg0 = 0;
    bump:
        arg0++;
    next:
        ;
    }
    *arg0 = 0xFF;
}
