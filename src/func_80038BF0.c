#include "common.h"

/* Bytecode-step reader: two *(*cursor)++ fetches on the slot indexed by
 * p[0x58]. Each fetch is two names (the lbu value, then the variable), the
 * slot sum needs the negation spelling for the base-first addu, and the
 * permuter found the last three: a third chained name on the second fetch,
 * D_8009B345 spelled through the global as scratch (one sb in the object),
 * and the d & 0x80 mask named before the zero stores. The +0x34 halfword
 * is read into a name before the function-pointer pair so its lhu fills
 * the pair's latency the way retail schedules it. */

void func_80038BA8(u8 *arg0);
void func_80037CE0(u8 *arg0);

void func_80038BF0(u8 *p) {
    s32 t;
    s32 u;
    s32 w;
    s32 v;
    s32 c;
    s32 d;

    D_8009B350 = 1;
    t = *(*(u8 **)(p - -(*(s8 *)(p + 0x58) * 4)))++;
    c = t;
    d = 0xF;
    if (c & 8) {
        u = *(*(u8 **)(p - -(*(s8 *)(p + 0x58) * 4)))++;
        t = u;
        d = t;
    }
    if (c & 0x80) {
        *(s32 *)(p - -(*(s8 *)(p + 0x58) * 4)) += D_8009B34D * 2;
        func_80038BA8(p);
    } else {
        D_8009B345 = 7;
        D_8009B345 = c & D_8009B345;
        D_8009B34C = c & 0xF0;
        D_8009B336 = d & 0xF;
        w = d & 0x80;
        D_8009B34D = 0;
        D_8009B327 = 0;
        if (w != 0) {
            D_8009B327 = 1;
        }
        func_80035CA8(p[0x57]);
        func_80035DB8(p[0x57]);
        v = *(u16 *)(p + 0x34);
        p[0x56] = 0;
        D_8009B340 = func_80037CE0;
        *(u16 *)(p + 0x34) = v | 0x1000;
    }
}
