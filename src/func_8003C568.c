#include "common.h"

/* Both stack addus need the negation spelling (sp0 + 8 - -(k * 2)): a frame
 * array does not flip to base-first with the (tbl + i)[K] grouping, only
 * with the negation. The k-indexed load is named into v before the 0x48
 * store -- retail issues it early -- which the permuter found; sp0 never
 * escapes, so the reorder past the store through the global pointer is
 * safe. u16 h[3] for the 6-byte copy and the k local ordering the two
 * pointer loads are the older levers from the park. */
typedef struct {
    u16 h[3];
} Blk6;

void func_8003C568(s32 arg0) {
    u8 sp0[12];
    u8 *a;
    u8 *b;
    s32 k;
    u32 v;

    *(Blk6 *)sp0 = *(Blk6 *)D_8009AF5C;
    *(s16 *)(sp0 + 8) = 0x68;
    k = D_8009B37D;
    a = D_8009B380;
    b = D_8009B388;
    *(s16 *)(sp0 + 0xA) = 0xC8;
    v = *(u16 *)(sp0 + 8 - -(k * 2));
    *(s16 *)(a + 0x32) = 0x48;
    *(u16 *)(a + 0x30) = v;
    *(s16 *)(b + 0x30) = 0x20;
    *(u16 *)(b + 0x32) = *(u16 *)(sp0 - -(arg0 * 2)) + 8;
    if (arg0 == 0) {
        *(u16 *)(a + 8) &= 0xFFBF;
        *(u16 *)(b + 0x30) = *(u16 *)(a + 0x30) + 8;
        *(u16 *)(b + 0x32) = *(u16 *)(a + 0x32) + 8;
    } else {
        *(u16 *)(a + 8) |= 0x40;
    }
}
