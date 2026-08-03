#include "common.h"

typedef struct {
    s32 w[12];
} Rec30;

void func_800464F0(void) {
    s32 i;
    s32 off;
    s32 nxt;
    s32 tag;
    u8 *p;

    p = D_8009B45C;
    if (*(s16 *)(p + 0x4C) > 0) {
        i = 0;
        nxt = 0x30;
        off = 0;

        do {
            if (*(s16 *)(p + 0x4C) == 0) {
                break;
            }
            tag = (p + off)[0x80];
            switch (tag) {
            case 0x29:
            case 0x24:
            case 0x2B:
                *(Rec30 *)(D_8009B45C + off + 0x80) =
                    *(Rec30 *)(D_8009B45C + nxt + 0x80);
                *(u16 *)(D_8009B45C + 0x4C) = *(u16 *)(D_8009B45C + 0x4C) - 1;
                break;
            default:
                nxt += 0x30;
                off += 0x30;
                i++;
                break;
            }
        } while (i < *(s16 *)(D_8009B45C + 0x4C));
    }

    switch (D_8009B45C[0x7C]) {
    case 0x29:
    case 0x24:
    case 0x2B:
        D_8009B45C[0x7C] = 0;
        D_8009B45C[0x7D] = 0;
        break;
    }
}
