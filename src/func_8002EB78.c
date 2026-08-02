#include "common.h"
void func_80039FD4(u8 *arg0);
void func_80039F44(u8 *arg0);

void func_8002EB78(void) {
    if (func_8002E3B4() == 0) {
        u8 *p = D_8009B290;
        s32 a;
        s32 b;
        s32 flag;
        s32 n;
        u8 *e;

        a = *p;
        p++;
        D_8009B290 = p;
        b = *p;
        p++;
        D_8009B290 = p;
        flag = b & 0x80;
        n = flag >> 7;
        e = (u8 *)&D_800EB010[n];
        D_8009B274 = e;
        if (*(s8 *)(e + 0x30) >= 0) {
            func_80039FD4(e);
        }
        func_80039E9C();
        func_80039F44(e);
        e[0x31] = b & 0xF;
        e[0x30] = a;
        e[0x3C] = n;
        e[0x33] = 2;
        if (flag != 0) {
            *(s16 *)(e + 0x34) = 0xD8;
        }
    }
    func_8003B50C(0);
    if (D_8009B274[0x33] == 0) {
        D_8009B27C = 0;
    }
}
