#define D_8009B458_IS_AGGREGATE
#include "common.h"

void func_8004B374(s32 arg0, s32 arg1) {
    u8 *p;
    u8 *e;
    s32 *q;
    s32 mask;
    s32 i;
    s32 off;
    s32 a;
    s32 r;

    i = 0;
    p = D_8009B458[0];
    mask = i;
    if (*(s16 *)(p + 0x510) > 0) {
        a = arg0 & 0xFF;
        q = D_80011434;
        off = i;
        do {
            e = p + off;
            if (e[0x183] == a && e[0x185] == (arg1 & 0xFF)) {
                func_8004A7C0(i);
                mask |= *q;
            }
            q++;
            p = D_8009B458[0];
            i++;
            off += 0x28;
        } while (i < *(s16 *)(p + 0x510));
    }
    if (mask != 0) {
        do {
            func_80076ED0(0, mask);
            r = func_80077090(mask);
        } while (r != 2 && r != 0);
    }
    D_8009B458[0][(arg0 & 0xFF) * 24 + 4] = 0;
}
