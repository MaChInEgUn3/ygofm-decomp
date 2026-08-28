#include "common.h"

void func_80046294(void) {
    s32 i;
    s32 off;
    s32 boff;
    s32 cmd;
    u8 *bp;

    bp = D_8009B45C;
    do {
        i = 0;
    } while (0);
    if (*(s16 *)(bp + 0x4C) > 0) {
        boff = 0x30;
        off = i;
        while (1) {
            if (*(s16 *)(bp + 0x4C) == 0) {
                goto after;
            }
            cmd = (bp + off)[0x80];
            switch (cmd) {
            case 0x42:
            case 0x43:
            case 0x45:
            case 0x46:
            case 0x48:
                *(Rec48 *)(D_8009B45C + off + 0x80) =
                    *(Rec48 *)(D_8009B45C + boff + 0x80);
                goto dec;

            case 0x20:
                if (*(s32 *)(D_8009B45C + off + 0x90) != 0x20) {
                    goto test;
                }
                *(Rec48 *)(D_8009B45C + off + 0x80) =
                    *(Rec48 *)(D_8009B45C + boff + 0x80);
            dec:
                *(u16 *)(D_8009B45C + 0x4C) =
                    *(u16 *)(D_8009B45C + 0x4C) - 1;
                goto test;

            default:
                boff += 0x30;
                off += 0x30;
                i++;
            }
        test:
            bp = D_8009B45C;
            if (i >= *(s16 *)(bp + 0x4C)) {
                break;
            }
            if (i < 0) {
                break;
            }
            }
    }
after:
    switch (D_8009B45C[0x7C]) {
    case 0x42:
    case 0x43:
    case 0x45:
    case 0x46:
    case 0x48:
        D_8009B45C[0x7C] = 0;
        D_8009B45C[0x7D] = 0;
        break;
    }

    if ((*(u16 *)(D_8009B45C + 0x40) & 0x80) != 0) {
        if (*(s16 *)(D_8009B45C + 0x157E) != -1) {
            if (func_80049F50() == 1) {
                func_80049C40(*(s16 *)(D_8009B45C + 0x157E));
            }
            *(u16 *)(D_8009B45C + 0x40) = *(u16 *)(D_8009B45C + 0x40) & 0xFF7F;
        }
    }
}
