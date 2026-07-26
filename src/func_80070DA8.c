#include "common.h"

void func_80070DA8(void) {
    u8 n = D_800F5BE8[0].depth;

    if (n != 0) {
        n--;
        D_800F5BE8[0].depth = n;
        D_800F5BE8[0].cursor = D_800F5BE8[0].stack[n];
    } else {
        func_8008E870(D_800118E4);
        func_8008E870(D_8009B084, D_800118CC, 0x193);
        while (1) {}
    }
}
