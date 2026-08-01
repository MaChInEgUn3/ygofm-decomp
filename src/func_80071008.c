#include "common.h"
s32 func_8002CBF4(s32 arg0, s32 arg1);

void func_80071008(void) {
    s32 a;
    s32 b;
    s32 idx;
    s32 r;
    s32 x;
    s32 y;

    a = D_800F5B98[func_8007058C()];
    b = D_800F5B98[func_8007058C()];
    idx = func_8007058C();

    if (((D_801D4244[a - 1] >> 26) & 0x1F) < 0x14) {
        switch (b) {
        case 0:
            r = func_8002CBF4(a, 0);
            break;
        case 1:
            r = func_8002CBF4(a, 1);
            break;
        case 2:
            x = func_8002CBF4(a, 0);
            y = func_8002CBF4(a, 1);
            if (y < x) {
                r = func_8002CBF4(a, 0);
            } else {
                r = func_8002CBF4(a, 1);
            }
            break;
        }
    } else {
        r = 0;
        if (b == 0) {
            switch (a) {
            case 0x157:
                r = 0x32;
                break;
            case 0x158:
                r = 0x64;
                break;
            case 0x159:
                r = 0xC8;
                break;
            case 0x15A:
                r = 0x1F4;
                break;
            case 0x15B:
                r = 0x3E8;
                break;
            }
        }
    }
    D_800F5B98[idx] = r;
}
