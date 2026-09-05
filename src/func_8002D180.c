#define D_8009B26C_IS_SCALAR
#define D_8009B269_IS_SCALAR
#define D_8009B0C0_IN_DATA
#define D_8009B364_IN_DATA
#include "common.h"

void func_8002D180(void) {
    u8 *e;
    s32 v;
    s32 n;
    s32 r;

    func_800878B0(0xA0, 0x78);
    func_800878D0(0x12C);

    v = D_8009B26C;
    if ((v & 0x40) == 0) {
        D_8009B26C = v | 0x40;
        D_8009B0C0 = 1;
        func_800530C4();
        func_800533D8();

        e = D_800EF658;
        n = *(s16 *)D_800EF658;
        if (n == 0x309) {
            D_8009B26C = D_8009B26C | 0x20;
            func_80059C24();
        } else {
            func_80053248(0, n - 1, *(s16 *)(e + 2), *(s16 *)(e + 4),
                          e[7], e[6]);
            e += 8;
            func_80053248(1, *(s16 *)e - 1, *(s16 *)(e + 2), *(s16 *)(e + 4),
                          e[7], e[6]);
            func_80053248(2, D_8009B364);
        }
        func_800159D8();
    } else {
        if (v & 0x20) {
            r = func_80059C88();
        } else {
            r = func_800534B8();
        }
        if (r != 0) {
            func_80047EC4();
            func_8003FF34();
            D_8009B26C = D_8009B269;
        }
        func_80059CE4();
    }
}
