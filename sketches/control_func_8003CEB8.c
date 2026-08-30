//@ func func_8003CEB8
//@ flags G8

#include "common.h"

s32 func_8003CEB8(u8 *arg0, s32 arg1) {
/*@ALT crctype
---
    s32 crc;
---
    s16 crc;
---
    u16 crc;
@*/
    s32 i;
    s32 j;

    crc = 0;
    for (i = 0; i < arg1; i++) {
        crc = crc ^ (arg0[i] << 8);
        for (j = 7; j >= 0; j--) {
            if ((crc & 0x8000) != 0) {
                crc = (crc << 1) ^ 0x1021;
            } else {
                crc = crc << 1;
            }
        }
    }
    i = crc & 0xFFFF;
    return i;
}
