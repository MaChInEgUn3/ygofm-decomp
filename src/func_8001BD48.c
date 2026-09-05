#define D_8009B361_IN_DATA
#define D_8009B398_IN_DATA_VOLATILE
#include "common.h"

s32 func_8001BD48(void) {
    if (D_8009B361 < 0) {
        if (D_8009B398 & 0x100) {
            D_8009B164 = 1;
            return 1;
        }
    }
    return 0;
}
