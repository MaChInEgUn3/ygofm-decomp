#define D_80010000_IS_AGGREGATE
#include "common.h"

void func_80012AE8(void) {
    void (**f)(void);
    s32 n;

    if (D_800906E0 != 0) {
        f = (void (**)(void))D_80010000;
        n = (s32)CtorCount_0;
        if (n != 0) {
            do {
                (*f++)();
                n--;
            } while (n != 0);
        }
    }
}
