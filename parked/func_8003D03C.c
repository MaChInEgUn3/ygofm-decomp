#define D_8009B0C4_IS_AGGREGATE
#define D_8009B408_IS_AGGREGATE
#include "common.h"

void func_8003D03C(u8 *arg0) {
    u8 *p;
    s32 v;
    u32 i;

    func_800356A0(arg0, D_801D4000, 0x200);

    *(s32 *)(arg0 + 0x600) = 0;
    *(s32 *)(arg0 + 0x608) = D_8009B0C4[0];

    if (D_8009B408[0] < 0) {
        D_8009B408[0] = 0;
    }

    arg0[0x7DE] = D_8009B408[0];
    p = arg0 + 0x200;
    v = D_8009B3B8 + 1;
    *(s32 *)(arg0 + 0x604) = v;
    *(s32 *)(arg0 + 0xC84) = v;

    func_8003CF14(p);
    func_8003CFC8(p);

    i = 0;

    do {
        *(arg0 + i + 0x828) = 0;
        i++;
    } while (i < 0x58);

    func_800356A0(arg0 + 0x880, arg0 + 0x200, 0x680);
}
