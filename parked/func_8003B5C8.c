#include "common.h"

typedef struct {
    u8 b[20];
} Bytes20;

void func_8003B5C8(void) {
    u8 b[20];
    s32 k;
    s32 n;
    u8 *e;
    s32 key;
    s32 j;
    s32 m;
    u8 *c;

    *(Bytes20 *)b = *(Bytes20 *)D_80010330;

    j = 0;
    c = b;
    for (k = 0, m = 1; k < 20; k += 2, m += 2, c += 2) {
        e = D_801D9004;
        n = 1;
        key = (c[0] << 8) | b[m];
        while (*(s32 *)e != 0) {
            if (key == *(u16 *)e) {
                D_800EAFF8[j] = n;
                break;
            }
            e += 4;
            n++;
        }
        j++;
    }
}
