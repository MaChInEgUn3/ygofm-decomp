#include "common.h"

/* The `beqz` in front of the clear loop is the loop's OWN entry guard, not
 * a separate test. Writing it as `if (n != 0) { for (...) }` emits two
 * branches -- gcc knows r[0x9C] == n after the store but the two
 * conditions are still different expressions, so it tests both -- and the
 * function comes out one instruction long. The retail listing masks the
 * call's return with andi 0xFF and branches once: that is the for's guard
 * comparing 0 against a byte field it has just written. */

void func_80072DC0(void) {
    u8 *r;
    s32 a;
    s32 b;
    s32 c;
    s32 k;
    s32 x;
    s32 y;
    s32 i;
    s32 n;

    a = D_800F5B98[func_8007058C()];
    b = D_800F5B98[func_8007058C()] + 1;
    c = D_800F5B98[func_8007058C()];
    k = func_8007058C();
    n = func_80070710();

    r = (u8 *)D_800F5BE8;
    r[0x9C] = n;
    r[0x9D] = b;
    *(s16 *)(r + 0xA0) = 0;
    r[0xA2] = 0;
    r[0xA3] = 0;
    r[0x9E] = c;

    for (i = 0; i < r[0x9C]; i++) {
        r[i + 0xAA] = 0;
    }

    x = func_8002CBF4(a, 0);
    y = func_8002CBF4(a, 1);

    if (y < x) {
        D_800F5C88[0] = func_8002CBF4(a, 0);
    } else {
        D_800F5C88[0] = func_8002CBF4(a, 1);
    }

    func_800727C0(a);

    if (D_800F5C8B[0] != 0) {
        D_800F5B98[k] = 0;
    } else {
        D_800F5B98[k] = 1;
    }
}
