#include "common.h"

u8 *func_80014EEC(s32 arg0, u8 *arg1, s32 arg2, s32 arg3, void *arg4, s32 arg5,
                  s32 arg6) {
    if (D_8009B10C != 0) {
        return (*(u8 *(**)(void))&D_8009B10C)();
    }

    {
        s32 t = D_8009B0F4;

        t &= 0x2000030;
        t |= D_8009B134;

        if (t != 0) {
            return 0;
        }
    }

    func_80013998(D_800E9E60, arg0, arg1, arg2, arg3, arg4, arg5, arg6);

    return D_800E9E60;
}
