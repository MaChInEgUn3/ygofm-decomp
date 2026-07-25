#include "common.h"

void func_8005F588(s32 arg0) {
    if (D_8009B07B == 1 && D_8009B07C == 1) {
        return;
    }
    if (arg0 == 0) {
        D_8009B07A = -1;
    } else {
        D_8009B07A = 0;
    }
}
