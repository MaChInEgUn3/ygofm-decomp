#include "common.h"

void func_8005F828(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3) {
    s32 v;
    s32 first;

    if (D_8009B07B == 1 && D_8009B07C == 1) {
        return;
    }
    v = *(s8 *)&D_8009B07A;
    if (v < 0) {
        first = 0;
    } else {
        D_8009B07A = D_8009B07A + 1;
        first = v > 0;
    }
    if (arg0 != 0) {
        do {
            func_8005F91C(first, arg1, arg2, arg3);
            if (arg1 != (u8 *)0) {
                arg1 += 8;
            }
            if (arg2 != (u8 *)0) {
                arg2 += 8;
            }
            if (!((arg1 != (u8 *)0 && *(s16 *)(arg1 + 6) != 0) ||
                  (arg2 != (u8 *)0 && *(s16 *)(arg2 + 6) != 0))) {
                break;
            }
            if (arg0 > 0) {
                arg0--;
            }
            first = 1;
        } while (arg0 != 0);
    }
}
