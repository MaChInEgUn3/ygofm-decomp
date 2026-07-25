#include "common.h"

s32 func_8005988C(s32 arg0) {
    s32 h = func_80073704(arg0, 0, 0);
    s32 r;

    if (h < 0) {
        return -1;
    }
    r = func_80073734(h, 0, 2);
    func_80073724(h);

    return r;
}
