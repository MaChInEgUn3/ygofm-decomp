#include "common.h"

void func_80060AEC(u8 *arg0) {
    s32 v = func_800608B8(*(s32 *)arg0);

    **(s32 **)(arg0 + 4) = v;
    func_80060170(*(s32 *)arg0, **(s32 **)(arg0 + 4));
}
