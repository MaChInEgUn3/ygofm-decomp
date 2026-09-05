#define D_8009B0C0_IS_VOLATILE
#define D_8009B0CC_IS_VOLATILE
#define D_8009B0D1_IS_SCALAR
#define D_8009B230_IN_DATA
#define D_8009B269_IN_DATA
#define D_8009B0D8_IS_SCALAR
#include "common.h"

s32 func_80012B50(void) {
    s32 r;
    s32 v;
    u8 *q;

    func_80012A78();
    func_800738B0();
    func_80074390();
    func_800854C0();
    func_800738C0();
    func_80074484();
    func_80073850(2);
    func_8007F634(0);
    func_80015D0C();

    q = D_8009B4A8;
    D_8009B0CC = 0;
    D_8009B0C8 = 0;
    D_8009B0C0 = 0;
    D_8009B09C = 0;
    v = D_8009B09C;
    D_8009B0C3 = 0;
    D_8009B0C1 = 0;
    D_8009B0D8 = 1;
    D_8009B098 = 0x5000;
    D_8009B0D1 = 0;
    *(u8 *)&D_8009B230 = 1;
    D_8009B0B4 = (s32)q;
    D_8009B0C4 = v;

    func_80013154();
    func_800403F0();
    func_800151B0();
    func_800134B4();
    func_80035A58();
    func_80035A64();
    func_8003B5C8();
    func_80046768(D_800E9EC0[0]);
    func_80074420(func_80012CD4);
    func_8003FE80();
    func_8008E5C0(0x55555555);
    func_8007F634(1);
    func_8002CD8C();
    func_8002CD8C();
    func_80043960(0);
    r = func_8008FB50(D_800E9DC0);
    func_8002CD8C();
    if (r != 0) {
        func_8005B85C();
        func_800137E4();
    }
    func_8002D458(func_80043BCC());
    D_8009B269 = 8;
    func_8002DD74();
    return 0;
}
