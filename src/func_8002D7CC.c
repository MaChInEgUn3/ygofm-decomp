#define D_8009B26C_IS_SCALAR
#define D_8009B269_IS_SCALAR
#define D_8009B398_IN_DATA_VOLATILE
#define D_8009B39A_IN_DATA
#include "common.h"

void func_80032328(void);
void func_80181F68(void);
s32 func_801821DC(void);
void func_80183FE4(void);
void func_80043230(u8 *arg0, s32 arg1, s32 arg2, s16 arg3);

void func_8002D7CC(void) {
    u8 *q;
    u8 *e;
    s32 v;
    s32 t;
    s32 s;

    v = D_8009B26C;
    if ((v & 0x40) == 0) {
        D_8009B26C = v | 0x40;
        func_80032328();
        func_8003FF08(0x72D0);
        func_80181F68();
        D_8009B26E = 1;
        e = func_80035C38(0, 0xB, 0x18, 0x20, 0x110, 0xA0, 0x20);
        e[0x59] = 0x10;
        func_80039A14(e);
        q = func_800400AC(func_8004002C(), 2);
        func_800404CC(q, 0, 0, 0, 4, 0xB, 0xC, 0x208);
        *(u16 *)(q + 8) = *(u16 *)(q + 8) | 0x20;
        *(s32 *)(q + 4) = *(s32 *)(q + 4) | 0x40000000;
        func_80042918(q);
        func_800428EC(q, 0xF);
        *(u8 **)D_800E9EF0 = q;
        func_80015A00();
    }

    e = (u8 *)D_800EB0F8;
    q = *(u8 **)D_800E9EF0;
    t = D_8009B26E;

    if (t == 1) {
        goto m1;
    }
    if (t == 2) {
        goto m2;
    }
    goto def;

m1:
    if (((D_8009B398 | D_8009B39A) & 0xE0) != 0) {
        func_8003FEE0(0x1E);
        func_80043178(q);
        *(s16 *)(q + 0x60) = 0x400;
        D_8009B26E = 2;
    }
    return;

m2:
    s = *(u16 *)(q + 0x60) - 0x20;
    *(s16 *)(q + 0x60) = s;
    func_80043230(q, 0, 0xF0, (s16)s);
    func_80039934(e, *(s16 *)(q + 0x30) + 0x18,
                  *(s16 *)(q + 0x32) + 0x20);
    if (*(s16 *)(q + 0x60) <= 0) {
        D_8009B26E = 0;
        func_80035B7C(e);
        func_8004036C(*(s32 *)D_800E9EF0);
        *(s32 *)D_800E9EF0 = 0;
    }
    return;

def:
    if (func_8002892C() != 0) {
        return;
    }
    if (func_801821DC() == 0) {
        return;
    }
    func_8003FF34();
    func_80015B00();
    func_80183FE4();
    D_8009B26C = D_8009B269;
}
