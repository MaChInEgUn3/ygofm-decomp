#include "common.h"

void func_80024388(void) {
    s32 v = 0;

    if (D_8009B361[0] < 0) {
        s32 t = D_8009B238;

        v = D_8009B1D5;
        if (t >= 0) {
            v = t;
        }
    }

    if (v != 0) {
        func_8003CDF8();
        func_80024200();
        func_8003CE48();
    } else {
        func_80024200();
    }
}
