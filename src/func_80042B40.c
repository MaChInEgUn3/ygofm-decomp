#include "common.h"

/* Finds the first live 0x70-byte record whose low nibble at +0x6C matches. */
u8 *func_80042B40(s32 arg0) {
    u8 *base = (u8 *)D_800EFE48;
    s32 n = 0x60;
    u8 *q = base + 0x6C;

    do {
        if (*(u16 *)(q - 0x64) & 0x80) {
            if ((*q & 0xF) == arg0) {
                return base;
            }
        }
        q += 0x70;
        n--;
        base += 0x70;
    } while (n != 0);

    return 0;
}
