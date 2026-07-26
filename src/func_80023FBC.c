#define D_8009B3A4_IS_VOLATILE
#include "common.h"

void func_80023FBC(u8 *arg0) {
    s32 v = -1;

    if (D_8009B3A4 & 0xF000) {
        if (D_8009B3A4 & 0x2000) {
            v = 0;
        }
        if (D_8009B3A4 & 0x4000) {
            v = 1;
        }
        if (D_8009B3A4 & 0x8000) {
            v = 2;
        }
        if (D_8009B3A4 & 0x1000) {
            v = 3;
        }
    }

    func_80023D08(arg0, v);
}
