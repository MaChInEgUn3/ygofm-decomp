#define D_8009B260_SIZED
#define D_8009B34D_SIZED
#include "common.h"

void func_80024200(void) {
    u8 *o;
    u8 *e;
    s32 f;

    if (D_8009B162 != 0) {
        func_800235C0();
    }
    func_8002C6C8();

    f = D_8009B260[0];
    if (f & 0x80) {
        if (f & 1) {
            return;
        }
        D_8009B260[0] = f & 0x7F;
    }

    if (func_80026B34() != 0) {
        return;
    }
    if (func_8002892C() != 0) {
        return;
    }

    f = D_8009B164;
    if (f != 0) {
        if ((f & 0x80) == 0) {
            D_8009B164 = f | 0x80;
            func_8003FEE0(0x30);
            o = func_80035C38(3, 0x22, 0x78, 0x58, 0x50, 0x24, 0x20);
            do {
                func_80039794();
            } while (*(s32 *)(o + 0x30) == 0);
        } else {
            func_80039794();
            e = D_800EB224;
            if (*(u16 *)(e + 0x34) & 0x2000) {
                func_80035B7C(e);
                D_8009B164 = 0;
                if (D_8009B34D[0] != 0) {
                    D_8009B16C = D_8009B16C | 0x2000;
                }
            }
        }
    } else {
        D_80090998[(D_8009B23A & 0xF)]();
        if ((D_8009B23A & 0x8000) == 0) {
            D_8009B174 = 0;
        }
    }
}
