/* MATCH 2026-09-05. Parked at 7 as two requirements pulling against each
 * other: the parameters take $s1-$s4 in declaration order only when USED in
 * that order, and retail stores the three bytes before the three words. Both
 * at once: the stores as STRUCT MEMBERS. gcc 2.8 lets a scalar global (the
 * D_8009B0F4 read-modify-write) move across a store to a struct member
 * through a pointer, where a cast store `*(s32 *)(p + 0x24)` pins it; with
 * the flag free to move, the scheduler hoists its load between the byte and
 * word stores and sinks the ori/sw into the epilogue, which is retail. Source
 * order stays words-first, so the parameters keep their registers.
 */
#include "common.h"

typedef struct {
    u8 pad0[0x24];
    s32 f24;
    u8 pad1[4];
    s32 f2C;
    u8 pad2[4];
    s32 f34;
    u8 f38;
    u8 f39;
    u8 pad3[0xC];
    u8 f46;
} Rec;

u8 *func_80013B68(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Rec *p;

    D_8009B0F4 &= ~0x20;
    p = (Rec *)D_800E9E18;

    if ((D_8009B0F4 & 0x10) && (D_8009B0F4 & 0x80000)) {
        func_80015010();
    }

    p->f24 = arg0;
    p->f34 = arg1;
    p->f38 = arg2;
    p->f39 = arg3;
    p->f46 = 4;
    p->f2C = 0x80000;
    D_8009B0F4 |= 0x20;

    return (u8 *)p;
}
