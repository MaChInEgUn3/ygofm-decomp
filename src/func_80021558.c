#include "common.h"

s16 func_80021558(s32 arg0, s32 arg1) {
    Threshold *p = D_801798A8[arg0];

    while (1) {
        if (arg1 < p->threshold) {
            return p->value;
        }
        p++;
    }
}
