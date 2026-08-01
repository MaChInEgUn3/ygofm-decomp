#define D_8009B268_IS_SCALAR
#define D_8009B26C_IS_SCALAR
#define D_8009B26D_IS_SCALAR
#include "common.h"
void func_8003BBF8(void);
void func_8016AA6C(void);

void func_8002D458(s32 arg0) {
    D_8009B268 = 1;
    D_8009B26D = arg0;
    switch (arg0) {
    case 0:
        func_8003BBF8();
        func_8016AA6C();
        *(s16 *)D_801D07DC = 0x30;
        D_8009B27A[0] = 0x30;
        D_8009B3D4[0] = 1;
        D_8009B0D1[0] = 0;
        D_8009B26C = 2;
        break;
    case 2:
        D_8009B26C = 0x10;
        break;
    case 3:
        D_8009B26C = 0xE;
        break;
    case 8:
        D_8009B26C = 4;
        break;
    case 5:
        D_8009B26C = 2;
        D_8009B27A[0] = D_801D07DC[0];
        break;
    case 6:
        D_8009B365[0] = 0;
        D_8009B26C = 6;
        break;
    case 7:
        func_80033C90();
        D_8009B268 = 0;
        break;
    case 4:
        D_8009B26C = 0xB;
        D_8009B268 = 0;
        break;
    case 9:
        D_8009B26C = 0xA;
        D_8009B268 = 0;
        break;
    case 1:
    case 10:
    default:
        D_8009B26C = 0;
        break;
    }
}
