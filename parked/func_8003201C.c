#include "common.h"

void func_8003201C(u8 *arg0) {
    s32 card;
    s32 j;
    s32 k;
    s32 count;
    u8 *r;

    arg0[0x5AC4] = 0;

    for (card = 1; card < 0x2D3; card++) {
        arg0[card + 0x5AC4] = 0;
        r = arg0 + 0x2D54;

        for (j = 0; j < 0x28; j++) {
            if (r[9] != 0) {
                if (*(s16 *)r == card) {
                    arg0[card + 0x5AC4]++;
                }
            }
            r += 0x10;
        }
    }

    count = 0;
    r = arg0 + 0x2D50;

    for (k = 0; k < 0x28; k++) {
        if (r[0xD] == 0) {
            break;
        }
        count++;
        r += 0x10;
    }

    *(s32 *)(arg0 + 0x5AA0) = count;
}
