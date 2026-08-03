#define D_8009B3A4_IS_VOLATILE_SIZED
#define D_8009B398_IS_AGGREGATE
#include "common.h"

void func_80013360(void) {
    s16 *p;
    s32 d;

    D_800E9D28[0] = 0;
    p = D_800E9D28;
    p[1] = 0;
    D_8009B098 |= 0x2000;
    goto test;

loop:
    if (D_8009B3A4[0] & 0xF000) {
        d = 2;
        if (D_8009B3A4[0] & 0x40) {
            d = 4;
        }
        if (D_8009B3A4[0] & 0x2000) {
            p[0] += d;
        }
        if (D_8009B3A4[0] & 0x8000) {
            p[0] -= d;
        }
        if (D_8009B3A4[0] & 0x1000) {
            p[1] -= d;
        }
        if (D_8009B3A4[0] & 0x4000) {
            p[1] += d;
        }
    }
    func_8007EC68(-1);

test:
    func_80012D4C();
    if ((D_8009B398[0] & 0x800) == 0) {
        goto loop;
    }

    D_8009B098 &= 0xDFFF;
    func_8003CB7C();
}
