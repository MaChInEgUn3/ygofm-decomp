#include "common.h"

void func_8002A2F4(u8 *p) {
    s32 *q = D_801D5608;
    s32 r;
    s32 t;
    s32 n;
    s32 mode;
    u8 *o;

    mode = 0;
    r = func_8002A6B8();
    D_8009B338 = r;
    t = (s16)r;
    q[0] = t;
    n = t;

    if (n != 0) {
        r = func_80029EB0(p, n);
        mode = 5;
        if ((r & 0x80) == 0) {
            D_8009B338 = 0;
        }
    }

    o = func_80035BE4(1, mode, 0x10, 0xCA, 0x120, 0x30);
    D_8009B320 = o[0x54];
    if (*(p + (n << 2) + 0x56) & 1) {
        D_8009B320 = 4;
    }
    func_80039A60(D_800EB15C);
}
