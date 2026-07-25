#include "common.h"

void func_8006086C(u8 *arg0) {
    s32 v = func_8006041C(*(s32 *)arg0);

    **(s32 **)(arg0 + 4) = v;
    func_80060170(*(s32 *)arg0, **(s32 **)(arg0 + 4));
}
