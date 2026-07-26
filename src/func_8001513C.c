#include "common.h"

void func_8001513C(u8 *arg0) {
    s32 t = *(s32 *)(arg0 + 0x28) - 0x800;

    *(s32 *)(arg0 + 0x28) = t;
    if (t > 0) {
        return;
    }

    *(s32 *)(arg0 + 0x1C) = 0;
    if (*(TickFn *)(arg0 + 0x20) != 0) {
        (*(TickFn *)(arg0 + 0x20))(arg0, (*(s32 *)(arg0 + 0x40))++);
    }

    *(s32 *)(arg0 + 0x28) = *(s32 *)(arg0 + 0x1C);
}
