#define D_8009B458_IS_AGGREGATE
#include "common.h"

void func_800494F4(s32 *arg0) {
    u32 i = 0;

    D_8009B458[0] = (u8 *)arg0;

    do {
        *arg0 = 0;
        i++;
        arg0++;
    } while (i < 0x212);

    func_80074E60();
    func_8004A6D8();
    func_80049434();
}
