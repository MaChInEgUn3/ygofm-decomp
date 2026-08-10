/* 34 differing instructions (25 under -O1 -G0, from sweep_try -- not built).
 *
 * The control flow is right: guard skipping the whole loop rather than an
 * early return, offset initialised from the counter, inner search with a
 * break, and the outer break sharing the single exit. What is left is
 * allocation -- retail holds the slot count in $v1 and copies it to $t1 for
 * the inner bound, we keep it in $t0 and use it directly -- and the order in
 * which the sought pointer and the walker are formed. Naming the bound in its
 * own local makes it worse, and so does splitting the && into nested ifs.
 */
#include "common.h"

s32 func_8005A3D0(u8 *arg0, s32 arg1) {
    s32 i = 0;
    s32 n = arg0[0xE17];

    if (n != 0) {
        s32 o = i;
        u8 *p = *(u8 **)(arg0 + 0xD14);

        do {
            s32 j = 0;

            if (*(s32 *)(p + 0x4C) == arg1 && n != 0) {
                u8 *b = *(u8 **)(arg0 + 0xD14);
                u8 *t = b + o;
                u8 *q = b;

                do {
                    if (*(s32 *)(q + 0x4C) == (s32)t) {
                        if (n || o) {
                            break;
                        } else {
                            break;
                        }
                    }
                    j++;
                    q += 0x50;
                } while (j < n);

                if (j < arg0[0xE17]) {
                    break;
                }
            }
            o += 0x50;
            n = arg0[0xE17];
            i++;
            p += 0x50;
        } while (i < n);
    }

    return i;
}
