#define D_8009B398_IS_AGGREGATE
#define D_8009B144_IS_AGGREGATE
#define D_8009B143_IS_AGGREGATE
#define D_8009B142_IS_AGGREGATE
#define D_8009B0F4_IS_AGGREGATE
#include "common.h"

void func_800359B0(void) {
    if (func_8005C530() == 0) {
        u8 v = D_8009B318;

        if ((v & 0x40) || (D_8009B398[0] & 0x800)) {
            D_8009B318 = v | 0x40;
            D_8009B144[0] = 1;
            D_8009B143[0] = 1;
            D_8009B142[0] = 1;
            func_8005C5C4();
        }
    } else {
        Base2_8009B0F4[0] = D_8009B0F4[0] & 0xFDFFFFFF;
        D_8009B318 &= 0x7F;
    }
}
