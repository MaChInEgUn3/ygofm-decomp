#include "common.h"

/* The game's own out-of-line copy of PsyQ's GetTPage() macro:
 * packs a texture page attribute word from (tp, abr, x, y). */
int func_80082780(int tp, int abr, int x, int y) {
    return ((tp & 0x3) << 7) | ((abr & 0x3) << 5) | ((y & 0x100) >> 4) |
           ((x & 0x3ff) >> 6) | ((y & 0x200) << 2);
}
