#include "common.h"

void func_80029528(s32 arg0) {
    s32 *p = (s32 *)&D_800EA0E8[arg0 * 64];

    func_8004036C(p[0]);
    func_8004036C(p[1]);
    p[1] = 0;
    p[0] = 0;
}
