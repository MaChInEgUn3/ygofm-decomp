#include "common.h"
void func_80043230(u8 *arg0, s32 arg1, s32 arg2);
void func_80039934(Rec64 *arg0, s32 arg1, s32 arg2);

s32 func_8003F2B0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 t;

    if (func_80042B98(arg0) == 0) {
        func_80043178(arg0);
    }
    t = *(s16 *)(arg0 + 0x60);
    if (t < 0) {
        t += 0x40;
        if (t >= 0) {
            arg0[0x6C] = 0;
            t = 0;
        }
    } else {
        t -= 0x40;
        if (t <= 0) {
            arg0[0x6C] = 0;
            t = 0;
        }
    }
    *(s16 *)(arg0 + 0x60) = t;
    func_80043230(arg0, arg1, arg2);
    if (arg3 >= 0) {
        func_80039934(&D_800EB0F8[arg3], *(s16 *)(arg0 + 0x30),
                      *(s16 *)(arg0 + 0x32));
    }
    return arg0[0x6C];
}
