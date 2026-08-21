#define D_8009B142_SIZED
#define D_8009B143_SIZED
#define D_8009B144_SIZED
#define D_8009B14A_SIZED
#define D_8009B14B_SIZED
#define D_8009B14C_SIZED
#define D_8009B0A3_IS_SCALAR
#include "common.h"

typedef struct {
    u8 b[20];
} Blk20;

void func_80013154(u8 *arg0) {
    u8 *p;
    u8 *t;
    s32 six;
    s32 i;
    s32 o;

    func_8007F350(0);
    func_80084DD0(0x140, 0xF0, 4, 1, 0);
    func_800856A0(0, 0, 0x140, 0);

    six = 6;
    p = arg0;
    t = D_800FE048;

    D_8009B0AD = 1;
    D_8009B0D0 = 1;
    D_8009B0A8 = 0;
    D_8009B14C[0] = 1;
    D_8009B144[0] = 1;
    D_8009B14B[0] = 1;
    D_8009B143[0] = 1;
    D_8009B14A[0] = 1;
    D_8009B142[0] = 1;
    t[0x18] = 1;
    t[0x16] = 1;
    t[0x19] = 1;
    t[0x1A] = 1;
    t[0x1B] = 1;
    D_8009B0A0 = 2;
    D_8009B0A1 = six;
    D_8009B0A2 = 0xC;
    D_8009B0A3 = six;

    i = 3;
    do {
        o = 0x514C;
        *(s32 *)(p + 0x5110) = 2;
        *(s32 *)(p + 0x5128) = (s32)(p + 0x10);
        *(s32 *)(p + 0x5138) = 0xC;
        *(s32 *)(p + 0x513C) = (s32)(p + 0x110);
        *(s32 *)(p + 0x5114) = (s32)p;
        *(s32 *)(p + 0x5124) = six;
        *(s32 *)(p + 0x514C) = six;
        *(s32 *)(p + 0x5150) = (s32)(p + 0x4110);
        do {
            func_80085DB0(0, i & 0xFFFF, p + o);
            i--;
            o -= 0x14;
        } while (i >= 0);
        p += 0x5160;
        i = 3;
    } while (p < arg0 + 0xA2C0);

    *(Blk20 *)D_800E9D28 = *(Blk20 *)D_800FE0A8;

    func_80086DC8();
    func_80085740();
    func_800855B0(0, 0);
    func_800878D0(0x12C);
    func_8003CBE8();
    func_8008B7B0(1);
    func_800136E4();
    func_8008E5C0(0x56);
}
