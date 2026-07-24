#include "common.h"

/* Clears the low bits of a state word and re-flags it.
 * `volatile` is load-bearing: without it the compiler folds the two
 * read-modify-writes into a single load/store pair, whereas the retail
 * code stores and reloads between them. */
extern volatile unsigned short D_8009B112;

void func_80015010(void) {
    D_8009B112 &= 0x3FFC;
    D_8009B112 |= 2;
}
