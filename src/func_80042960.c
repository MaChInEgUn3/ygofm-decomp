#include "common.h"

s32 func_80042960(u8 *arg0) {
    VoidFn fn = *(VoidFn *)(arg0 + 0x24);

    if (fn != 0) {
        fn();
    }

    return (*(u16 *)(arg0 + 8) & 0xC0) == 0xC0;
}
