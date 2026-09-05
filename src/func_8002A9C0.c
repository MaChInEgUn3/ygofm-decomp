/* MATCH (2026-09-05), from a park at 6. The last six differences were the
 * materialisation ORDER of five constants: retail forms 0x1F800300, then
 * the /3 reciprocal 0x55555555, then 0x1F800310, 0x1F800318, 0x1F800308.
 * The park had measured all 24 orders of the four base locals with the
 * constant's name assigned AFTER them, and every one was 6 or worse; with
 * `m = 0x55555555;` written between b0 and b2 -- retail's own order,
 * `b0; m; b2; b3; b1;` -- it is a MATCH first try, and the other five
 * placements of m are 4 to 9. A rejected spelling measured while another
 * fault was open had not been measured at all. Flags: default, as default.
 */
#include "common.h"

void func_80041F90(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3);
void func_80087AB0(u8 *a, u8 *b, u8 *c, u8 *d, u8 *e, u8 *f, u8 *g, u8 *h, s32 *i, s32 *j);
void func_8005B260(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);

void func_8002A9C0(u8 *p, s32 arg1) {
    s32 sp28;
    s32 sp2C;
    u8 *q;
    u8 *r;
    u8 *b0;
    u8 *b1;
    u8 *b2;
    u8 *b3;
    s32 n;
    s32 e;
    s32 m;
    s32 z;
    s32 y;
    s32 k;
    s32 v;
    s32 w;

    n = *(u16 *)(p + 0x60) - 0x10;
    *(s16 *)(p + 0x60) = n;
    if ((s16)n <= 0) {
        func_8004036C((s32)p);
        return;
    }

    r = (u8 *)0x1F800398;

    p[0xE] = p[0x60];
    func_80041F90(p, *(s16 *)(p + 0x30) + *(s16 *)(p + 0x18),
                  *(s16 *)(p + 0x32) + *(s16 *)(p + 0x1A), (u8 *)0x1F800398);

    q = (u8 *)0x1F8002A0;
    b0 = (u8 *)0x1F800300;
    m = 0x55555555;
    b2 = (u8 *)0x1F800310;
    b3 = (u8 *)0x1F800318;
    b1 = (u8 *)0x1F800308;

    z = *(s32 *)(p + 0xC);
    q[3] = 6;
    *(s32 *)(q + 0x18) = m;
    *(s32 *)(q + 4) = z;
    q[7] = 0x4C;

    v = *(u16 *)(p + 0x30) - *(u16 *)r;
    *(s16 *)b2 = v;
    *(s16 *)b0 = v;
    v = v + *(u16 *)(p + 0x3C);
    *(s16 *)b3 = v;
    *(s16 *)(b0 + 8) = v;

    w = *(u16 *)(p + 0x32) - *(u16 *)(r + 2);
    *(s16 *)(b1 + 2) = w;
    *(s16 *)(b0 + 2) = w;

    e = *(u16 *)(p + 0x3E);

    *(s16 *)(b3 + 4) = 0;
    *(s16 *)(b2 + 4) = 0;
    *(s16 *)(b1 + 4) = 0;
    *(s16 *)(b0 + 4) = 0;

    w = w + e;
    *(s16 *)(b3 + 2) = w;
    *(s16 *)(b0 + 0x12) = w;

    func_80087AB0((u8 *)0x1F800300, (u8 *)0x1F800308, (u8 *)0x1F800310,
                  (u8 *)0x1F800318, (u8 *)0x1F8002A8, (u8 *)0x1F8002AC,
                  (u8 *)0x1F8002B4, (u8 *)0x1F8002B0, &sp28, &sp2C);

    func_8005B260((u8 *)0x1F8002A0, arg1, *(u16 *)(p + 0x14), 1);

    q[3] = 3;
    q[7] = 0x40;
    k = *(u16 *)(p + 0x14);
    *(s32 *)(q + 0xC) = *(s32 *)(q + 0x14);
    func_8005B260((u8 *)0x1F8002A0, arg1, k, 1);
}
