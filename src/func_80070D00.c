#include "common.h"

void func_80070D00(void) {
    s32 off = func_800705AC();

    if (D_800F5BE8[0].depth < 8) {
        D_800F5BE8[0].stack[D_800F5BE8[0].depth] = D_800F5BE8[0].cursor;
        D_800F5BE8[0].depth = D_800F5BE8[0].depth + 1;
    } else {
        func_8008E870(D_800118AC);
        func_8008E870(D_8009B084, D_800118CC, 0x17B);
        while (1) {}
    }

    off += (s32)D_800F5BE8[0].base;
    D_800F5BE8[0].cursor = (u8 *)off;
}
