#define D_8009B26C_SIZED
#define D_8009B27A_SIZED
#define D_8009B398_IS_AGGREGATE
#include "common.h"

void func_80030998(void) {
    u8 *a;
    u8 *s;
    s32 r;
    s32 n;
    s32 f;
    u16 h;

    if ((D_8009B2EB & 0x80) == 0) {
        D_8009B2EB = D_8009B2EB | 0x80;
        func_80030090();
        func_8002FD10(0);
        D_8009B2BC = 0;
        goto sel;
    }
    if ((D_8009B398[0] & 0x100) != 0) {
        D_8009B2BC = D_8009B2BC ^ 1;
    sel:
        if (D_8009B2BC == 0) {
            h = D_8009AF44;
            D_8009B2C8 = h;
            func_80030250((s32)D_80090CDC, 0x12, 0, 0, 2, 3, 1);
        } else {
            h = D_8009AF46;
            D_8009B2C8 = h;
            func_80030250((s32)D_80090CF4, 0x12, 0, 0, 2, 2, 1);
        }
    }

    r = func_80030294();
    f = D_8009B2EB;
    if ((f & 0x40) != 0) {
        func_80039794();
        s = (u8 *)D_800EB0F8;
        if ((D_8009B2EB & 0x20) == 0) {
            if ((*(u16 *)(s + 0x34) & 0x2000) != 0) {
                *(s32 *)(s + 0x30) = func_800374F4(s);
                D_8009B2EB = D_8009B2EB | 0x20;
            }
        } else if (func_8003B734() != 0) {
            func_80035B7C(s);
            func_8004036C((s32)D_8009B2A0);
            D_8009B2EB = D_8009B2EB & 0x9F;
            D_8009B2EA = D_8009B2EA & 0xFE;
        }
    } else if (r != 0) {
        if (r < 0) {
            D_8009B2EB = 0;
            func_800300AC();
            return;
        }
        if (D_8009B2BC == 0) {
            D_8009B2EB = f | 0x40;
            D_8009AF44 = D_8009B2C8;
            D_8009B2EA = D_8009B2EA | 1;
            func_8003B6AC(0, 2);
            func_8008E870(D_80010288, D_800EB288[*(u16 *)D_80090E58].unk18);
            func_80035BE4(0, D_8009AF44, 0x10, 0xB0, 0x120, 0x30);
            D_8009B2A0 = (u8 *)func_8002E3FC();
            return;
        }
        h = D_8009B2C8;
        D_8009B26C[0] = 2;
        D_8009AF46 = h;
        D_8009B27A[0] = h;
    }
}
