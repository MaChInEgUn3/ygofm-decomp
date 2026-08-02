#define FUNC_80046FA0_S32
#define D_8009B398_IS_VOLATILE
#define D_8009B408_SIZED
#include "common.h"

void func_8003C7A0(void) {
    s32 v;

    if (D_8009B384 == 0 && (D_8009B398 & 0xA000)) {
        if (D_8009B398 & 0x2000) {
            if (D_8009B37D != 0) {
                return;
            }
            v = 1;
            D_8009B408[0] = v;
            D_8009B37D = 1;
        } else {
            if (D_8009B37D == 0) {
                return;
            }
            v = 0;
            D_8009B408[0] = v;
            D_8009B37D = 0;
        }
        func_80046FA0(v);
        func_8003FEE0(0x2F);
        func_8003C568(D_8009B384);
        return;
    }

    if (D_8009B384 != 0 && (D_8009B398 & 0xC0)) {
        func_8003FEE0(7);
        D_8009B37C = *(u8 *)&D_8009B384 + 1;
        return;
    }

    if (D_8009B398 & 0x20) {
        D_8009B37C = 0;
        func_8003FEE0(8);
    }
}
