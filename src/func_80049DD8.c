#include "common.h"

void func_80049DD8(void) {
    u8 c[0x40];
    u8 *p;
    u8 *e;
    s32 i;

    D_8009B458[0x500] = 1;

    for (i = 0; i < *(s16 *)(D_8009B458 + 0x510); i++) {
        e = D_8009B458 + i * 0x28;
        if ((e[0x183] >> 4) == 0 && e[0x18D] != 0) {
            *(s32 *)(c + 4) = 3;
            /* NOT D_80011434[i]. The byte-address form is load-bearing: the
             * indexed form lets gcc hoist this load above the store above it
             * to cover its latency, and retail keeps the store first. See
             * WORKFLOW, "a load the target does not hoist". */
            *(s32 *)c = *(s32 *)((u8 *)D_80011434 + i * 4);
            *(s16 *)(c + 8) = *(u16 *)(e + 0x194);
            *(s16 *)(c + 0xA) = *(u16 *)(e + 0x196);
            func_80077450(c);
        }
    }
    p = D_8009B458;
    *(s16 *)(p + 0x7E2) = 1;
    p[0x500] = 0;
}
