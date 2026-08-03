#include "common.h"

void func_80071EB8(void) {
    s32 sp10;
    s32 sp14;
    s32 k;
    s32 cnt;
    s32 idx;
    s32 lo;
    s32 hi;
    u8 *e;

    k = D_800F5B98[func_8007058C()];
    cnt = 0;
    idx = func_8007058C();
    func_800707C4(k, &sp10, &sp14);

    lo = sp10;
    hi = sp14;
    if (lo <= hi) {
        e = (u8 *)D_801AB000 + lo * 12;
        do {
            if (*(s16 *)e != 0) {
                if (k == 1 || k == 3 || k == 6 || k == 8) {
                    if (*(u16 *)(e + 6) & 0x4000) {
                        goto next;
                    }
                }
                cnt++;
            }
        next:
            lo++;
            e += 0xC;
        } while (lo <= hi);
    }

    D_800F5B98[idx] = cnt;
}
