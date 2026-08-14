#include "common.h"

/* A checkerboard of primitives built in the scratchpad at 0x1F800000 and
 * handed to a library call 40 times. The loops came out right on the first
 * draft; all 20 differences were in the setup block and all three fixes
 * were about where a value is born, not what it is:
 *   - the 0x200020 is a named local assigned FIRST, before the counters.
 *     It is materialised before the scratchpad address exists, so it
 *     cannot be the store's literal.
 *   - `f = 0; y = f;` are plain statements above the setup, where the
 *     for-init form lands after it.
 *   - the +0xC field is read into a local near the top and stored last,
 *     which is what puts its `lw` next to the +4 one.
 * The two stores at +0 and +8 are then written in ascending offset order
 * and the scheduler emits them the other way round; naming the +4 read
 * instead of swapping them also matches, and swapping is the smaller
 * claim. */

void func_8003D334(u8 *arg0, s32 arg1) {
    u8 *q;
    s32 x;
    s32 y;
    s32 t;
    s32 f;
    s32 u;
    s32 c;

    c = 0x200020;
    f = 0;
    y = f;
    q = (u8 *)0x1F800000;
    *(s32 *)q = *(s32 *)(arg0 + 4);
    *(s32 *)(q + 8) = c;
    u = *(s32 *)(arg0 + 0xC);
    *(s16 *)(q + 0xC) = 0xB;
    *(s16 *)(q + 0x10) = 0x2C0;
    *(s16 *)(q + 0x12) = 0xFC;
    t = *(s16 *)(arg0 + 0x14);
    *(s16 *)(q + 0xE) = 0x3030;
    *(s32 *)(q + 0x14) = u;

    for (; y < 0xF0; y += 0x20, f ^= 1) {
        *(s16 *)(q + 4) = f << 5;
        q[0xE] = 0x30;
        *(s16 *)(q + 6) = y;
        *(s16 *)(q + 0x10) = 0x2C0;
        for (x = 0; x < 0x140; x += 0x40) {
            func_800849F0(q, arg1, (u16)t);
            *(u16 *)(q + 4) = *(u16 *)(q + 4) + 0x40;
        }
        *(s16 *)(q + 4) = (f ^ 1) << 5;
        q[0xE] = 0x50;
        *(s16 *)(q + 0x10) = 0x2D0;
        for (x = 0; x < 0x140; x += 0x40) {
            func_800849F0(q, arg1, (u16)t);
            *(u16 *)(q + 4) = *(u16 *)(q + 4) + 0x40;
        }
    }
}
