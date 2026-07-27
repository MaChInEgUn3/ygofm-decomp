#define D_8009B450_IS_VOLATILE
#include "common.h"

void func_80044038(s32 arg0) {
    s32 n = 10;

    do {
        func_80043D48(D_800F2AF0);
        func_8008B3A0(arg0);

        while (D_8009B450 < 0) {
        }

        n--;
    } while (D_8009B450 == 1 && n > 0);
}
