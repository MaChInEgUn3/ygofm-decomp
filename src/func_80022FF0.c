#include "common.h"

void func_80022FF0(u8 *arg0, s32 arg1) {
    u8 *a;
    u8 *b;
    s32 i;

    a = *(u8 **)(arg0 + 8);
    if (a == 0) {
        return;
    }

    i = 0;
    func_80022F98(arg0, *(u8 **)(arg0 + 4));
    *(u8 **)(arg0 + 4) = 0;
    b = a + 4;

    do {
        func_80022F98(arg0, *(u8 **)a);
        func_80022F98(arg0, *(u8 **)b);
        if (arg1) {
            *(u8 **)a = 0;
            *(u8 **)b = 0;
        }
        b += 12;
        i++;
        a += 12;
    } while (i < 5);
}
