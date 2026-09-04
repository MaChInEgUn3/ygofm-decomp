#include "common.h"

void func_80016DDC(u8 *object)
{
    s32 difference = *(s16 *)(object + 18) - *(s16 *)(object + 20);
    /* This order and the builtin preserve the target a1/a2 register roles. */
    s32 step;
    s32 magnitude;

    if (difference == 0) {
        return;
    }
    magnitude = __builtin_abs(difference);
    step = 9;
    if (magnitude >= 300) {
        step = 19;
    }
    if (magnitude >= 1000) {
        step = 47;
    }
    if (magnitude >= 3000) {
        step = 97;
    }
    if (difference > 0) {
        difference -= step;
        if (difference < 0) {
            difference = 0;
        }
    } else {
        difference += step;
        if (difference > 0) {
            difference = 0;
        }
    }
    *(s16 *)(object + 18) = *(u16 *)(object + 20) + difference;
}
