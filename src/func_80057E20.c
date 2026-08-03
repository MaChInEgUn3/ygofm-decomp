#include "common.h"

void func_80057E20(s32 idx, u8 *out) {
    u8 *p;
    u8 *e;
    s32 v;

    p = D_800F2C40 + idx * 3616;
    e = p + 0xCF8;
    *(SVector *)out = *(SVector *)(p + 0xDC8);

    if (e[7] != 0) {
        v = e[7] << 4;
        if (*(s16 *)(out) < v) {
            *(s16 *)(out) = v;
        }
    }

    if (e[8] != 0) {
        v = e[8] << 4;
        if (*(s16 *)(out + 2) < v) {
            *(s16 *)(out + 2) = v;
        }
    }

    if (e[9] != 0) {
        v = e[9] << 4;
        if (*(s16 *)(out + 4) < v) {
            *(s16 *)(out + 4) = v;
        }
    }


    *(s16 *)(out + 6) = 0;
    if (*(s16 *)out > 0) {
        *(u16 *)(out + 6) = *(u16 *)out;
    }
    if (*(s16 *)(out + 6) < *(s16 *)(out + 2)) {
        *(u16 *)(out + 6) = *(u16 *)(out + 2);
    }
    if (*(s16 *)(out + 6) < *(s16 *)(out + 4)) {
        *(u16 *)(out + 6) = *(u16 *)(out + 4);
    }
}
