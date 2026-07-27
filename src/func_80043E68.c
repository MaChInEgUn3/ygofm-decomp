#include "common.h"

void func_80043E68(void) {
    s32 *p = D_800F2AE0;
    s32 i;

    func_800738B0();

    i = 8;

    do {
        func_80073870(*p);
        p++;
        i--;
    } while (i != 0);

    func_800738C0();
}
