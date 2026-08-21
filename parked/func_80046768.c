#define D_8009B0F0_SIZED
#define D_8009B120_SIZED
#include "common.h"

typedef struct {
    u8 c[11];
} Name11;

typedef struct {
    u8 c[10];
} Name10;

void func_80046768(s32 arg0) {
    u32 *q;
    u8 *e;
    u8 *f;
    s32 c;
    s32 d;

    D_8009B45C = (u8 *)0x801E0000;
    D_8009B460 = 0x801E1650;

    q = (u32 *)0x801E0000;
    do {
        *q = 0;
        q++;
    } while ((u32)q <= 0x801EA7FF);

    D_8009B0F0[0] = (s32)func_8004666C;
    D_8009B120[0] = (s32)func_800466C8;

    *(Name11 *)(D_8009B45C + 0x1619) = *(Name11 *)D_80010784;
    *(Name10 *)(D_8009B45C + 0x1629) = *(Name10 *)D_80010790;
    *(Name10 *)(D_8009B45C + 0x1639) = *(Name10 *)D_8001079C;

    D_8009B45C[0x4A] = 3;
    if ((arg0 & 0xFF) != 0) {
        D_8009B45C[0x4A] |= 0xF0;
    }
    D_8009B45C[0x1649] = 0xFF;
    D_8009B45C[0x164A] = 0xD2;
    D_8009B45C[0x164B] = 0xFF;
    c = D_8009B45C[0x1649];
    d = D_8009B45C[0x164A];
    D_8009B45C[0x49] = 0xFF;
    *(s16 *)(D_8009B45C + 0x42) = c;
    *(s16 *)(D_8009B45C + 0x44) = d;
    D_8009B45C[0x1584] = 0xFF;
    func_800494F4((s32 *)0x801E1670);
    func_8004671C();
    func_80044D48();
    func_80048F14();
    func_80046FA0(0);
    D_8009B458[0x509] = 0;
    f = D_8009B458;
    e = D_8009B45C;
    *(s32 *)(f + 0x50C) = (s32)func_800478EC;
    *(s16 *)(e + 0x40) = 0;
}
