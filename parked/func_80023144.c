#define D_8009B344_SIZED8_VOLATILE
#define D_8009B34E_SIZED8
#define D_8009B355_SIZED8
#define D_8009B320_SIZED8
#define D_8009B338_SIZED8
#include "common.h"

void func_80023144(u8 *arg0, s32 arg1) {
    u8 *e;
    u8 *o;
    s32 f;
    s32 v;
    s32 mode;
    s32 id;
    s8 c;
    s32 k;
    s32 fl;
    u8 side;

    e = D_801A7AD8 + arg1 * 0x1C;
    fl = *(u16 *)(e + 0x16);
    D_8009B34E[0] = 0;
    D_8009B355[0] = 0;
    mode = 0x50;
    if ((fl & 0x8000) != 0) {
        id = *(s16 *)(e + 0xC);
        f = D_801D4244[id - 1];
        D_8009B34E[0] = 1;
        D_8009B338[0] = id;
        if (((f >> 0x1A) & 0x1F) < 0x14) {
            v = f >> 0x12;
            if ((*(u16 *)(e + 0x16) & 0x200) == 0) {
                v = f >> 0x16;
            }
            D_8009B344[0] = v & 0xF;
            D_8009B344[0] = D_8009B344[0] + 0x17;
            v = func_800170C8(e);
            D_801D5608[0] = (s16)v;
            D_801D5608[1] = (s16)(v >> 0x10);
        } else {
            mode = 0x51;
        }
        if (arg1 % 15 >= 5) {
            fl = *(u16 *)(e + 0x16);
            D_8009B34E[0] = 2;
            if ((fl & 0x1000) != 0) {
                D_8009B34E[0] = 3;
            }
            if (((arg1 < 0xF) ^ 1) == D_8009B1D5 && *(s8 *)(D_8009B1C8 + 0x1F) == 0) {
                D_8009B34E[0] = 2;
            }
        } else if ((*(u16 *)(e + 0x16) & 0x2000) != 0) {
            D_8009B34E[0] = 0;
        }
    }
    k = arg0[0x17];
    if (k == 3) {
        mode += 4;
        c = D_800E9FF0[D_8009B1D5 ^ 1].unk19;
        D_801D5608[2] = c;
        if (c != 0) {
            if ((u32)c >= 4U) {
                D_801D5608[2] = k;
            }
            D_8009B355[0] = 1;
        }
        if (D_8009B34E[0] != 0) {
            D_8009B355[0] = D_8009B355[0] | 2;
            D_8009B320[0] = func_80023090(arg0, D_800E9F48 + D_8009B1D5 * 0x70);
        }
    }
    v = mode;
    if (arg0[0x17] == 2 && arg0[0x18] != 0) {
        side = D_8009B1D5;
        if (*(s8 *)(arg0 + 0x10) < 2) {
            side ^= 1;
        }
        c = D_800E9FF0[side].unk19;
        D_801D5608[2] = c;
        if (c != 0) {
            if ((u32)c >= 4U) {
                D_801D5608[2] = 3;
            }
            D_8009B355[0] = 1;
        }
        v = mode + 2;
    }
    o = *(u8 **)arg0;
    o = func_80035BE4(arg0[0x14], v, *(s16 *)(o + 0x30) + 0x10,
                      *(s16 *)(o + 0x32) + *(s8 *)(arg0 + 0x16), 0x120, 0x40);
    *(s8 *)(o + 0x59) = *(*(u8 **)arg0 + 0x16) + 1;
    func_80039A14(o);
}
