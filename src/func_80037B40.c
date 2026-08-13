#define D_8009B112_IS_AGGREGATE
#define D_8009B0F4_IS_AGGREGATE
#include "common.h"

void func_80037B40(u8 *p) {
    if ((p[0x51] & 0x80) == 0) {
        p[0x51] |= 0x80;
        p[0x52] = 0xFF;
        D_8009B335 = 0;
        if (D_8009B33C != 0) {
            p[0x51] |= 0x40;
        }
    }

    p[0x52]--;

    if (p[0x52] != 0) {
        switch (D_8009B335) {
        case 0:
            if ((D_8009B0F4[0] & 0x80000) == 0) {
                return;
            }
            p[0x52] = 0xFF;
            D_8009B335 = 1;
        case 1:
            if ((D_8009B112[0] & 0x4000) == 0) {
                return;
            }
            p[0x52] = 0xFF;
            D_8009B335 = 2;
        case 2:
            if ((D_8009B112[0] & 0x4000) == 0) {
                break;
            }
            if ((p[0x51] & 0x40) == 0) {
                return;
            }
            D_8009B33C--;
            if (D_8009B33C > 0) {
                return;
            }
            break;
        }
    }

    p[0x51] = 0;
    p[0x52] = 1;
}
