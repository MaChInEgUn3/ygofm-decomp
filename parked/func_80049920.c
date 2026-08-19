#include "common.h"

void func_80049920(void) {
    s32 *t;
    s32 *s;
    s32 acc;
    s32 i;
    s32 o;
    s32 r;
    u8 v;

    acc = 0;
    o = 0;
    t = D_80011434;

    for (i = 0; i < *(s16 *)(D_8009B458 + 0x510); o += 0x28, i++, t++) {
        if ((D_8009B458 + o)[0x18D] != 0) {
            if (func_80077090(*t) == 3) {
                v = (D_8009B458 + o)[0x18D];
                if (v >= 2) {
                    acc |= *t;
                    s = t;
                    do {
                        func_80076ED0(0, *s);
                        r = func_80077090(*s);
                    } while (r != 2 && r != 0);
                    (D_8009B458 + o)[0x18D] = 0;
                } else {
                    (D_8009B458 + o)[0x18D] = v + 1;
                }
            }
        }
    }

    if (acc != 0) {
        func_80076ED0(0, acc);
    }
}
