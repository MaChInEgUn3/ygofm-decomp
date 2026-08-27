#include "common.h"

typedef struct {
    s32 unk0;
    Matrix m0;
    Matrix m1;
    SVector rot;
    s32 unk4C;
} LightPkt;

void func_800580D4(s32 arg0, s32 arg1, s32 arg2, u8 *arg3) {
    LightPkt pkt;
    SVector sv60;
    Matrix m68;
    SVector sv88;
    SVector sv90;
    Matrix m98;
    SVector svB8;
    u8 *p;
    s32 n;
    s32 v;
    s32 y;

    p = D_800F2C40 + arg0 * 0xE20;
    n = arg1;
    if (p[0xE17] < n) {
        n = p[0xE18];
    }
    func_8008A4A0(*(s32 *)(p + 0xD14) + n * 0x50, &m68);
    func_800855D0(&m68);
    func_80089CC0(arg2, &sv60, &svB8);

    pkt.rot.vz = 0;
    pkt.rot.vy = 0;
    pkt.rot.vx = 0;
    func_80088E50(&pkt.rot, &pkt.m0);

    pkt.unk0 = 1;
    pkt.m0.t[0] = sv60.vx;
    y = sv60.vy;
    pkt.m0.t[1] = y;
    pkt.m0.t[2] = sv60.vz;
    pkt.m1 = pkt.m0;
    pkt.unk4C = 0;
    func_8008E3D0(&sv90, 0, 8, y);

    sv90.vy = 0x1000 - D_8009B47A;
    sv90.vz = D_8009B47C;
    sv88 = sv90;

    *(s32 *)arg3 = 0;
    *(s16 *)(arg3 + 0x44) = 0x1000 - *(u16 *)(*(s32 *)(D_800F2C40 + 0xD18) + 0x44);
    *(s16 *)(arg3 + 0x46) = 0x1000 - *(u16 *)(*(s32 *)(D_800F2C40 + 0xD18) + 0x46);
    v = 0x1000 - *(u16 *)(*(s32 *)(D_800F2C40 + 0xD18) + 0x48);
    *(s16 *)(arg3 + 0x48) = v;
    func_800889C0(arg3 + 0x44, arg3 + 4, v);

    func_80088E50(&sv88, &m98);
    func_80087370(arg3 + 4, &m98);

    *(s32 *)(arg3 + 0x20) = 0;
    *(s32 *)(arg3 + 0x1C) = 0;
    *(s32 *)(arg3 + 0x18) = 0;
    *(s32 *)(arg3 + 0x4C) = (s32)&pkt;
}
