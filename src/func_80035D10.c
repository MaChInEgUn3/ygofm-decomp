#include "common.h"

s32 func_80035D10(void) {
    s32 col = D_8009B324;
    s32 row = D_8009B325;
    s32 n = 0x100;

    do {
        s32 idx = row * 16 + col;

        if (D_800EAF08[idx] == 0) {
            return idx;
        }

        col++;

        if ((col & 3) == 0) {
            row++;

            if (row >= 0xF) {
                row = 0x10;
            }

            if ((row & 3) == 0) {
                row -= 4;
            } else {
                col -= 4;
            }

            if (col >= 0x10) {
                row += 4;
                col = 0;

                if (row >= 0x10) {
                    row = 0;
                }
            }
        }
        n--;
    } while (n != 0);

    return -1;
}
