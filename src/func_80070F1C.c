#include "common.h"

void func_80070F1C(void) {
    s32 *t = D_800F5B98;
    s32 a = t[func_8007058C()];
    s32 b = t[func_8007058C()];
    s32 c = t[func_8007058C()];
    s32 d = t[func_8007058C()];

    D_800EAE88[9] = a;
    D_800EAE88[0xB] = c;

    if (d == 0) {
        if (a >= 6 && b == 1) {
            D_800EAE88[0xA] = a;
        } else {
            D_800EAE92[0] = 0;
        }
    } else if (d < 0xFF) {
        D_800EAE88[0xA] = d;
    } else {
        D_800EAE88[0xA] = 0x3A;
    }
}
