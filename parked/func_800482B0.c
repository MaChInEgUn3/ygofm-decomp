#include "common.h"

void func_800482B0(s32 arg0, s16 arg1, u8 arg2, u16 arg3, s32 arg4, u8 arg5) {
    s16 sp20;
    u8 sp22;
    u16 sp28;
    s32 m;
    s32 i;
    s32 n;
    s32 bit;
    s32 c;

    sp22 = arg2;
    sp28 = arg3;
    if (*(u16 *)(*(s32 *)(D_8009B45C + 0x43C) + (arg0 & 0xFFFF) * 2) != 0xFFFF) {
        if ((arg0 & 0x8000) != 0) {
            func_800451E0(arg0 & 0xFFFF, 0);
            return;
        play:
            func_8004803C(arg0 & 0xFFFF, D_8009B45C[0x435], arg1, sp22, (s32)(s16)sp28,
                          arg4 & 0xFF, arg5 & 0xFF);
            return;
        }
        n = 0;
        m = arg4 & 0xF;
        if (m != 0) {
            m = func_80047F38(m, arg4);
            if (m != 0) {
                c = 0;
                while ((m & 1) == 0) {
                    c++;
                    m = m >> 1;
                    if ((u8)c >= 4) {
                        goto scan;
                    }
                }
                D_8009B45C[0x435] = c;
                goto play;
            }
        }
    scan:
        if ((arg4 & 0xF0) != 0) {
            c = 0;
            n = 0;
            i = 0;
            do {
                func_80077C50(i + 0x14, &sp20);
                if (sp20 != 0 &&
                    *(u16 *)(D_8009B45C + ((u8)c) * 2 + 0x404) == (arg0 & 0xFFFF)) {
                    n++;
                    if ((u8)n == ((arg4 & 0xF0) >> 4)) {
                        D_8009B45C[0x435] = c;
                        goto play;
                    }
                }
                i++;
                c++;
            } while (i < 4);
            goto out;
        }
    out:
        bit = 1 << D_8009B45C[0x435];
        i = 0;
        do {
            func_80077C50(D_8009B45C[0x435] + 0x14, &sp20);
            if (sp20 == 0) {
                n = 1;
                func_8004803C(arg0 & 0xFFFF, D_8009B45C[0x435], arg1, sp22,
                              (s32)(s16)sp28, arg4 & 0xFF, arg5 & 0xFF);
            }
            bit = bit * 2;
            if ((bit & 0x10) != 0) {
                bit = 1;
            }
            D_8009B45C[0x435] = D_8009B45C[0x435] + 1;
            i++;
            D_8009B45C[0x435] = D_8009B45C[0x435] & 3;
        } while (i < 4 && (u8)n == 0);
        if ((u8)n == 0) {
            i = 0;
            bit = 1 << D_8009B45C[0x435];
            do {
                c = D_8009B45C[0x435];
                if ((u32)(arg5 & 0xFF) >= (u32)D_8009B45C[c + 0x40C]) {
                    n = 1;
                    func_8004803C(arg0 & 0xFFFF, c, arg1, sp22, (s32)(s16)sp28,
                                  arg4 & 0xFF, arg5 & 0xFF);
                }
                bit = bit * 2;
                if ((bit & 0x10) != 0) {
                    bit = 1;
                }
                D_8009B45C[0x435] = D_8009B45C[0x435] + 1;
                i++;
                D_8009B45C[0x435] = D_8009B45C[0x435] & 3;
            } while (i < 4 && (u8)n == 0);
        }
    }
}
