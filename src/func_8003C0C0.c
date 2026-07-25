#include "common.h"

void func_8003C0C0(void) {
    s32 off = 0;

    if (func_8002CCA8(0x47) != 0) {
        off = 0x9E;
    }
    func_80014E1C(0, 0, off + 0x1FD9, 0x9E, func_8003BF00, 0, 0);
    func_800137E4();
}
