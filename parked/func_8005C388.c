#include "common.h"

void func_8005C388(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 sp18[8];
    s32 sum;

    {
        u8 *tbl = D_8009151C;
        s32 t = *(u16 *)(tbl + arg0 * 4 + 2);
        u8 *p;
        s32 i;

        if (t != 0) {
            arg2 = t;
        }
        sum = 0;
        p = tbl;
        for (i = 0; i < arg0; i++) {
            sum += *(u16 *)p;
            p += 4;
        }
    }
    func_8007E600(D_800E9EB4[0] + sum, sp18);
    func_8005B8A0(sp18, arg1, arg2,
                  func_8007E710(sp18) + *(u16 *)(D_8009151C + arg0 * 4),
                  arg3, arg4);
}
