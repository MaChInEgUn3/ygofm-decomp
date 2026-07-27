#include "common.h"

void func_8004A2F8(void) {
    u8 *b = D_8009B458;

    if (*(s16 *)(b + 0x510) > 0) {
        s32 i = 0;
        s32 o2 = 0x180;
        s32 o = 0;

        do {
            u8 *r = b + o;

            if (r[0x183] < 0x10) {
                func_8004A0FC(b + o2, b + r[0x183] * 24);

                {
                    u8 *c = D_8009B458 + o;

                    func_8004A27C(i, *(u16 *)(c + 0x194), *(u16 *)(c + 0x196));
                }
            }

            o2 += 0x28;
            b = D_8009B458;
            o += 0x28;
            i++;
        } while (i < *(s16 *)(b + 0x510));
    }
}
