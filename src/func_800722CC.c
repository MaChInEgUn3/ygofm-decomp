#include "common.h"

void func_800707C4(s32 arg0, s32 *arg1, s32 *arg2);

void func_800722CC(void) {
    s32 sp10;
    s32 sp14;
    Rec12 *e;
    Rec12 *r;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 k;
    s32 i;
    s32 one;

    a = D_800F5B98[func_8007058C()];
    b = D_800F5B98[func_8007058C()];
    c = D_800F5B98[func_8007058C()];
    d = D_800F5B98[func_8007058C()];
    k = func_8007058C();

    func_800707C4(b, &sp10, &sp14);

    i = sp10;
    if (sp14 < i) {
        goto zero;
    }

    one = 1;
    r = D_801AB000;
    e = &r[i];
    while (1) {
        if (e->unk0 == 0) {
            goto next;
        }
        if (e->unk8 != a) {
            goto next;
        }
        if (b == one || b == 3 || b == 6 || b == 8) {
            if ((e->unk6 & 0x4000) != 0) {
                goto next;
            }
        }
        if (c == one && b >= 5) {
            if ((e->unk6 & 0x1000) != 0) {
                goto next;
            }
        }
        if (func_80070920(d, i) == 0) {
            break;
        }
next:
        e++;
        i++;
        if (sp14 < i) {
            break;
        }
    }

    if (sp14 < i) {
zero:
        D_800F5B98[k] = 0;
    } else {
        D_800F5B98[k] = i;
    }
}
