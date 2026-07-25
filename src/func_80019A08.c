#include "common.h"

/* Table of groups: key, member count, then that many members. */
s32 func_80019A08(s32 arg0, s32 arg1) {
    u16 *p = (u16 *)D_8017A1D8;

    while (1) {
        s32 key = p[0];
        s32 n;

        if (key == 0) {
            return 0;
        }
        n = p[1];
        p += 2;
        if (key == arg0) {
            do {
                if (arg1 == *p) {
                    return arg1;
                }
                n--;
                p++;
            } while (n != 0);

            return 0;
        }
        p += n;
    }
}
