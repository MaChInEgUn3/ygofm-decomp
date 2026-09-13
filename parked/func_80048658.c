#include "common.h"

void func_80048658(s32 arg0, s32 arg1, s32 arg2)
{
    s32 id;
    s32 idc;
    s32 vol;
    s32 pan;
    u16 stop_arg;
    u8 last_arg;
    u16 stop_value;
    s32 lo;
    s32 hi;
    s32 n;
    u8 *e;
    s32 t2;

    if (arg0 & 0x8000) {
        t2 = arg0;
        id = t2;
        pan = arg2;
        stop_arg = id;
        idc = id;
        vol = arg1;
        stop_value = stop_arg;
    } else {
        t2 = arg0;
        id = t2;
        pan = arg2;
        stop_arg = id;
        idc = id;
        vol = arg1;
        stop_value = stop_arg;
    }
    if (id & 0x8000) {
        func_800451E0(stop_value & 0xFFFF, 0);
        return;
    }
    if ((id & 0xF000) == 0x4000) {
        u8 *a = D_8009B45C;
        u16 v;
        s32 n;

        lo = (id & 0x1F) << 1;
        t2 = id & 0x100;
        hi = t2;
        hi = (hi != 0) << 6;
        v = *(u16 *)(a + (lo + hi) + 0x44C);
        if (v == 0xFFFF) {
            return;
        }
        n = (*(u16 **)(a + 0x43C))[v];
        if (n == 0xFFFF) {
            return;
        }
        e = (u8 *)(n * 8 + (u32)*(u8 **)(a + 0x444));
        t2 = e[2];
        last_arg = t2;
        vol &= 0xFF;
        func_800482B0(v, 0, vol, (s16)pan, e[3], last_arg & 0xFF);
    } else {
        u8 *b = D_8009B45C;

        n = (*(u16 **)(b + 0x43C))[idc & 0xFFFF];
        if (n == 0xFFFF) {
            return;
        }
        e = (u8 *)(n * 8 + (u32)*(u8 **)(b + 0x444));
        t2 = e[2];
        last_arg = t2;
        vol &= 0xFF;
        func_800482B0(idc & 0xFFFF, 0, vol, (s16)pan, e[3], last_arg & 0xFF);
    }
}
