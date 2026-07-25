#include "common.h"

void func_8003FE80(void) {
    s32 *p = D_800E9EA8;

    D_8009B408 = -1;
    func_80046990(p[4], p[5], p[6]);
    while (func_8004703C() & 8) {
        func_80012D4C();
    }
}
