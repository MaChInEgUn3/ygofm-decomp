#include "common.h"

s32 func_80059908(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 fd;
    s32 total;
    s32 left;
    s32 n;

    if (arg0 == 0) {
        return 0;
    }
    fd = func_80073704(arg0, 0, 0);
    if (fd < 0) {
        return 0;
    }

    if (arg3 == 0) {
        arg3 = func_80073734(fd, 0, 2) - arg2;
    }
    total = arg3;
    left = total;
    func_80073734(fd, arg2, 0);

    if (total > 0) {
        do {
            n = 0x1000;
            if (left < 0x1001) {
                n = left;
            }
            if (func_80073758(fd, arg1, n) != n) {
                total = 0;
                break;
            }
            left -= n;
            arg1 += n;
        } while (left > 0);
    }

    func_80073724(fd);
    return total;
}
