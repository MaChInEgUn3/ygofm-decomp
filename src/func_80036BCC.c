#include "common.h"

/* Scans big-endian halfword keys, returning the parallel 0x1E-byte record.
 * The two tables start at the same address and the retail code forms that
 * address twice, so they are two symbols here -- see config/symbol_aliases.txt. */
u8 *func_80036BCC(s32 arg0) {
    u8 *rec = D_801D9174;
    u8 *key = KeyTable_801D9174;
    s32 v;

    while (1) {
        v = (key[0] << 8) | key[1];
        if (v == 0) {
            return 0;
        }
        if (v == arg0) {
            return rec;
        }
        key += 2;
        rec += 0x1E;
    }
}
