/* MATCH 2026-09-05. Parked at 7 (and 9 before that) as a scheduling question
 * around the D_8009B408 byte read; it was addressing. Retail reads both globals
 * in the BARE form -- lb through the destination register, sb through $at --
 * beside a four-byte gp-relative D_8009B3B8, so both take the .data arm with
 * their real scalar types at the default assembler threshold. Then the byte
 * read goes BEFORE the two word stores through arg0 (retail loads it first and
 * puts the second store in the branch delay slot), and the local is s32 so the
 * scalar read stays an lb rather than lbu + sll. The dead identical-arm if the
 * permuter had found is no longer load-bearing and is gone.
 */
#define D_8009B0C4_IN_DATA
#define D_8009B408_IN_DATA
#include "common.h"

void func_8003D03C(u8 *arg0) {
    u8 *p;
    s32 b;
    s32 v;
    u32 i;
    s32 n;

    func_800356A0(arg0, D_801D4000, 0x200);

    n = D_8009B0C4;
    b = D_8009B408;
    *(s32 *)(arg0 + 0x600) = 0;
    *(s32 *)(arg0 + 0x608) = n;

    if (b < 0) {
        D_8009B408 = 0;
    }

    arg0[0x7DE] = D_8009B408;
    p = arg0 + 0x200;
    v = D_8009B3B8 + 1;
    *(s32 *)(arg0 + 0x604) = v;
    *(s32 *)(arg0 + 0xC84) = v;

    func_8003CF14(p);
    func_8003CFC8(p);

    i = 0;

    do {
        *(arg0 + i + 0x828) = 0;
        i++;
    } while (i < 0x58);

    func_800356A0(arg0 + 0x880, arg0 + 0x200, 0x680);
}
