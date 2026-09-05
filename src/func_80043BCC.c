#define D_8009B142_IN_DATA
#define D_8009B143_IN_DATA
#define D_8009B144_IN_DATA
#define D_8009B318_IN_DATA
#define D_8009B398_IS_VOLATILE
#include "common.h"

s32 func_80043BCC(void) {
    s32 r;
    u32 f;
    s32 g;

    func_800159D8();

    for (;;) {
        D_8009B428 = 0;
        for (;;) {
            func_8008E590();
            func_80012D4C();
            f = D_8009B428;
            if ((f & 1) == 0) {
                if ((f & 0x80) == 0) {
                    D_8009B428 = f | 0x80;
                    func_8002CD8C();
                    func_8003594C(0);
                    D_8009B142 = 0xFF;
                    D_8009B143 = 0xFF;
                    D_8009B144 = 0xFF;
                    continue;
                }
                if (f & 0x40) {
                    if (D_8009B398 & 0x8C0) {
                        func_80035B7C((u8 *)D_800EB0F8);
                        D_8009B428 = 1;
                    }
                    continue;
                }
                g = D_8009B318;
                if (g & 0x80) {
                    continue;
                }
                D_8009B428 = 1;
                if ((g & 0x40) == 0) {
                    func_800156DC();
                }
                func_80015AD8();
                continue;
            }
            if ((f & 0x80) == 0) {
                D_8009B428 = f | 0x80;
                func_8002CD8C();
                func_8018001C(0, 0);
                func_800157DC();
            }
            r = func_80180390();
            if (r != -1) {
                break;
            }
        }
        func_8003FF34();
        func_80015B00();
        func_80180DD0();
        func_8002CD8C();
        if (r != -2) {
            return r;
        }
    }
}
