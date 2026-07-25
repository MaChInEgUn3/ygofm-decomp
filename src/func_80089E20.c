#include "common.h"

u8 *func_80089E20(u8 **arg0) {
    u8 *p = *arg0;

    return p + *(u16 *)p * 4;
}
