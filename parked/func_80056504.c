#define D_8009B0F4_SIZED
#include "common.h"
extern u8 D_800114F8[];
extern u8 D_80011580[];
extern u8 D_80091008[];
void func_800577B0(void);
void func_80056D7C(void);
void func_80057544(void);

s32 func_80056504(s32 arg0, s32 id, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    u8 *rec;
    u8 *e;
    u8 *h;
    s32 n;
    s32 top;
    s32 r;

    r = 0;
    top = arg0 & 0x80;
    n = arg0 & 0x7F;
    if (id < 0) {
        id = *(u16 *)(D_800F2C40 + n * 0xE20 + 0xDF8);
    } else {
        *(u16 *)(D_800F2C40 + n * 0xE20 + 0xDF8) = id;
    }
    if (top == 0) {
        func_80047EC4();
    }
    func_800137E4();
    func_8004CB0C(n, 0, 0, arg6);
    rec = D_800F2C40 + n * 0xE20;
    rec[0xE1D] = top;
    if (n >= 2) {
        goto big;
    }
    if (id == 0x309) {
        h = func_80014EEC(1, D_800114F8, 0x3B4, 0x113, func_800577B0, 0, 0);
        D_8009B0F4[0] = *(s32 *)(h + 0x2C) | 0x10;
        rec[0xE14] = 0;
        return 0;
    }
    if ((u32)id >= 0x2D2) {
        goto fail;
    }
    if ((u32)(id - 0x12C) < 0x32) {
        goto fail;
    }
    if ((u32)(id - 0x28A) < 0x32) {
        goto fail;
    }
    if (id == 0x2D0) {
        goto fail;
    }
    if (id >= 0x2D1) {
        id -= 1;
    }
    if (id >= 0x2BC) {
        id -= 0x32;
    }
    if (id >= 0x15E) {
        id -= 0x32;
    }
    h = func_80014EEC(2, D_80011580, id * 0x114, 0x114, func_80056D7C, 0, 0);
    if (arg2 >= 0) {
        *(s16 *)(rec + 0xDFA) = arg2;
    }
    if (arg3 >= 0) {
        *(s16 *)(rec + 0xDFC) = arg3;
    }
    if (arg4 >= 0) {
        rec[0xDFE] = arg4 != 0;
    }
    if (arg5 >= 0) {
        rec[0xDFF] = arg5 != 0;
    }
    *(s32 *)(h + 0x38) = n;
    *(s32 *)(h + 0x3C) = (D_800F2C40 + n * 0xE20)[0xDFE];
    D_8009B0F4[0] = *(s32 *)(h + 0x2C) | 0x10;
    (D_800F2C40 + n * 0xE20)[0xE14] = 0;
    goto out;
big:
    if ((u32)id < 7) {
        id = *(u8 *)(D_80091008 + id * 0xB2 + 0xA0);
        if ((u32)id < 7) {
            goto ok;
        }
    }
fail:
    r++;
    goto out;
ok:
    h = func_80014EEC(1, D_800114F8, id * 0x74 + 0x88, 0x74, func_80057544, 0, 0);
    D_8009B0F4[0] = *(s32 *)(h + 0x2C) | 0x10;
    rec[0xE14] = 0;
out:
    return r;
}
