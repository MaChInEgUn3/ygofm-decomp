#include "common.h"

void func_80049640(void) {
    s32 v;

    func_8004A6D8();
    v = *(s32 *)(D_8009B458 + 0x81C);

    if (v > 0) {
        if (v < 4) {
            func_8004B910();
        }
    }

    func_80049434();
}
