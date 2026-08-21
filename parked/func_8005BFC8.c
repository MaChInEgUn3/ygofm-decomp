#include "common.h"

s32 func_8005BFC8(s32 arg0) {
    s32 sp10;
    u8 *sp14;
    s32 one;
    s32 t;
    s32 t2;
    s32 cnt;
    u32 lim;
    u32 cap;
    u8 *e;
    s32 f;
    s32 a;
    s32 h;
    s32 w;
    s32 sz;

    if (D_8009B063 != 0) {
        return 1;
    }
    one = 1;
    if (arg0 != 0) {
        D_8009B068 = func_800783DC(&D_8009B49C);
    }

retry:
    t = func_80074170(-1);
    cnt = 0;

    while (1) {
        if (func_800785C0(&sp10, &sp14) == 0) {
            break;
        }
        t2 = func_80074170(-1);
        if (t2 - t < 0x3C) {
            continue;
        }
        if (D_8009B063 != 0) {
            return 1;
        }
        cnt++;
        if (arg0 == 0) {
            if (cnt < 0xA) {
                t = t2;
                continue;
            }
        }
        cnt = 0;
        func_8005C62C(&D_8009B49C);
        t = t2;
    }

    if (func_800781F0(sp14 + 0x1C) + *(u16 *)(sp14 + 6) * 2 >= D_8009B070) {
        D_8009B063 = one;
    }
    lim = D_8009B068;
    cap = D_8009B06C;
    if (lim >= cap) {
        D_8009B064 = one;
    }
    if (*(u32 *)(sp14 + 8) >= cap) {
        D_8009B064 = one;
    }
    if (D_8009B063 == 0) {
        if (*(u32 *)(sp14 + 8) < lim) {
            func_800784D0(sp10, sp14);
            goto retry;
        }
    }

    D_8009B066 = (D_8009B066 + 1) & 1;
    func_800902A0(sp10, D_8009B498 + (D_8009B066 * 0xE000 + 0x1B000));

    e = D_8009B498 + 0x40000;
    h = *(u16 *)(sp14 + 0x10);
    if (D_8009B060 != 0) {
        w = (u32)(h * 3) >> 1;
    } else {
        w = h;
    }
    sz = 0x10;
    *(s16 *)(e + 0x2424) = w;
    e = D_8009B498 + 0x40000;
    f = D_8009B060;
    *(u16 *)(e + 0x2426) = *(u16 *)(sp14 + 0x12);
    if (f != 0) {
        sz = 0x18;
    }
    a = sp10;
    *(s16 *)(e + 0x242C) = sz;
    *(u16 *)(e + 0x242E) = *(u16 *)(sp14 + 0x12);
    func_800784D0(a, e, sp14, sz);
    return 0;
}
