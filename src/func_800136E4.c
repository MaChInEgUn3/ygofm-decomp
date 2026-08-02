#include "common.h"

void func_800136E4(void) {
    s32 *e;
    u8 **f;
    u8 *g;
    s32 i;
    u8 *p;

    func_80013898((s32)D_801DC000);

    D_8009B10C = (s32)func_800137E4;
    p = D_800E9DF0;
    *(s16 *)(p + 4) = 0x120;
    *(s16 *)(p + 6) = 0xD0;
    *(s16 *)(p + 0xC) = 0xB;
    *(s32 *)D_800E9DF0 = 0x8000000;
    D_8009B0E0 = 0;
    *(s32 *)(p + 0x14) = 0x808080;
    *(u16 *)(p + 0xE) = 0xA000;
    *(s32 *)(p + 8) = 0x180018;
    *(s32 *)(p + 0x10) = 0xFC0230;

    for (i = 0, e = D_800E9EA8, f = D_8009078C; ; ) {
        g = *f;
        if (g == (u8 *)0) {
            break;
        }
        func_800138F4(e, (s32)g);
        func_8008E870(D_80010038, g, *e);
        e++;
        f++;
        i++;
        if (i >= 7) {
            break;
        }
    }
}
