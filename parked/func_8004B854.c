#define D_8009B458_IS_AGGREGATE
#include "common.h"

void func_8004B854(void) {
    u8 *p = D_8009B458[0];

    if (p[0x503] == 0) {
        s32 h;

        p[0x503] = 1;
        func_800738B0();
        func_80073A54(0xF2000002);
        h = func_80073860(0xF2000002, 2, 0x1000, func_8004B734);
        *(s32 *)(D_8009B458[0] + 0x504) = h;
        func_80073890(h);
        func_80073950(0xF2000002, 0xE000, 0x1000);
        func_80073A24(0xF2000002);
        func_800738C0();
        D_8009B458[0][0x500] = 0;
        D_8009B458[0][0x503] = 0;
    }
}
