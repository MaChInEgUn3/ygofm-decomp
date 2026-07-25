#include "common.h"

void func_800156DC(void) {
    u8 *p;

    D_8009B145 = 1;
    func_800158B8();
    p = D_800E9EC8;
    p[6] = 0;
    p[4] = 0;
    D_8009B142 = 0xFF;
    D_8009B143 = 0xFF;
    D_8009B144 = 0xFF;
    func_80015D0C();
}
