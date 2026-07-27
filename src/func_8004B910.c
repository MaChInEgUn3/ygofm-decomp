#define D_8009B458_IS_AGGREGATE
#include "common.h"

void func_8004B910(void) {
    D_8009B458[0][0x503] = 1;
    func_800738B0();
    func_80073A54(0xF2000002);
    func_800738A0(*(s32 *)(D_8009B458[0] + 0x504));
    func_80073870(*(s32 *)(D_8009B458[0] + 0x504));
    func_800738C0();
    D_8009B458[0][0x500] = 0;
}
