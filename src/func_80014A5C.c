#include "common.h"
void func_8001455C(void);

void func_80014A5C(s32 arg0) {
    if (D_8009B124 != 0) {
        D_8009B124 = 0;
        return;
    }
    D_8009B124 = 1;
    if (D_8009B0E8 != 0) {
        return;
    }
    D_8009B0E8 = 1;
    if (!(D_8009B0F4 & 0x10) && (D_8009B0F4 & 0x20)) {
        func_800143DC();
    }
    if (D_8009B0F4 & 0x10) {
        if (D_8009B134 != 0 && !(D_8009B134 & 0x40)) {
            D_8009B134 |= 0x40;
            D_800E9E60[0x46] = 5;
            D_800E9E60[0x47] = 0;
        }
        func_8001455C();
    } else {
        D_8009B134 = 0;
    }
    D_8009B0E8 = 0;
}
