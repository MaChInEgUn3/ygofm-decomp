#define D_8009B458_IS_AGGREGATE
#include "common.h"

void func_8004A7C0(s32 arg0) {
    s32 off = arg0 * 40 + 0x180;
    u8 *p = D_8009B458[0] + off;

    if (p[3] < 0x10) {
        s32 *t = &D_80011434[arg0];
        s32 v;

        do {
            func_80076ED0(0, *t);
            v = func_80077090(*t);
        } while (v != 2 && v != 0);

        p[0xF] = 0;
    }
}
