#define D_8009B458_IS_AGGREGATE
#include "common.h"

void func_8004B9E0(void) {
    u8 *p = D_8009B458[0];

    if (p[0x501] == 0) {
        p[0x501] = 1;

        if (D_8009B458[0][0x502] != 0) {
            func_8004C8C8();
            func_8004C8C8();
            func_8004C8C8();
            func_8004C8C8();
            func_8004C8C8();
            func_8004C8C8();
            func_8004C8C8();
            func_8004C8C8();
            func_8004C8C8();
            func_8004C8C8();
        }

        func_8004C84C();
        func_8004AAFC();

        D_8009B458[0][0x501] = 0;
    }
}
