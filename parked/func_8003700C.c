#define D_8009B394_IS_VOLATILE
#include "common.h"

s32 func_8003700C(u8 *p) {
    s32 v;
    s32 old;

    if (D_8009B394 & 0x5008) {
        if (D_8009B394 & 8) {
            v = *(u8 *)&D_8009B34D + 1;
            D_8009B34D = v;
            if ((s8)v < D_8009B345) {
                goto act;
            }
            D_8009B34D = 0;
        } else if (D_8009B394 & 0x4000) {
            old = *(u8 *)&D_8009B34D;
            v = old + 1;
            D_8009B34D = v;
            if ((s8)v < D_8009B345) {
                goto act;
            }
            D_8009B34D = old;
            return 1;
        } else {
            old = *(u8 *)&D_8009B34D;
            v = old - 1;
            D_8009B34D = v;
            if ((s8)v >= 0) {
                goto act;
            }
            D_8009B34D = old;
            return 1;
        }
    act:
        func_8003FEE0(6);
        func_80036F80(p);
        return 1;
    }
    return 0;
}
