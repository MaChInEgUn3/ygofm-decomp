#include "common.h"

s32 func_8005C5D4(void) {
    s32 t = 0x7FFFFFFF;

    if (D_8009B062 == 0) {
    loop:
        if (t > 0) {
            goto body;
        }

        func_8008FBE0(1);
        goto done;

    body:
        if (D_8009B062 != 0) {
            goto done;
        }

        t--;
        goto loop;
    }

done:
    D_8009B062 = 0;

    return 0;
}
