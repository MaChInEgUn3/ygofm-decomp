#define D_8009B45C_IS_AGGREGATE
#include "common.h"

void func_800464F0(void);
void func_80044DA0(void);

s32 func_80045208(s32 a, s16 arg1) {
    u8 buf[0x30];
    u8 *q;
    u8 *p8;
    u32 v;
    s32 w;
    s32 k;
    s32 m;
    u8 *e;

    q = D_8009B45C[0];
    w = a;
    if (q[0x4A] & 0x80) {
        if ((q[0x4A] & 0x40) == 0) {
            if ((u16)a > 0x9FFF) {
                return 0;
            }
        }
        if (a & 0x8000) {
            *(u16 *)(q + 0x534) = a;
            m = a & 0xF000;
            switch (m) {
            case 0x8000:
                w = a + m;
                e = *(u8 **)(q + 0x51C);
                k = 0x50;
                break;
            case 0x9000:
                w = a + 0x7000;
                e = *(u8 **)(q + 0x518);
                k = 0x60;
                break;
            default:
                if (e) {
                    w += 0x6000;
                    e = *(u8 **)(D_8009B45C[0] + 0x520);
                    k = 0x70;
                    break;
                } else {
                    w += 0x6000;
                    e = *(u8 **)(D_8009B45C[0] + 0x520);
                    k = 0x70;
                    break;
                }
            }
            v = *(u32 *)e;
            p8 = e + 8;
            func_800464F0();
            buf[0] = 0x24;
            *(u16 *)(buf + 2) = w;
            *(u32 *)(buf + 4) = v;
            *(u32 *)(buf + 8) = k;
            *(u32 *)(buf + 0xC) = (u32)p8;
            func_80045BE8(buf);
            func_80044DA0();
            *(u16 *)(D_8009B45C[0] + 0x40) = (*(u16 *)(D_8009B45C[0] + 0x40) | 1) & 0xFFFB;
            return 1;
        }
    }
    return 0;
}
