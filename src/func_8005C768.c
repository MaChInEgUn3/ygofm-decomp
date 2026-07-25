#include "common.h"

ByteFn func_8005C768(s32 arg0) {
    if ((arg0 & 0xFFFF0000) == 0x3000000) {
        switch (arg0 & 0xFFFF) {
        case 0x2019:
            return func_8005CEF0;

        case 0x2119:
            return func_8005D378;
        }
    }

    return func_80089E20;
}
