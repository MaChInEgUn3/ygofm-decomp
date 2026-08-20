#include "common.h"

void func_800773C4(u8 *arg0);
void func_8004A43C(u8 *arg0, s32 arg1);
void func_8004A7C0(s32 arg0, s32 arg1);
void func_80076ED0(s32 arg0, s32 arg1);
s32 func_80077090(s32 arg0);

void func_8004AAFC(void) {
    u8 sp10[0x18];
    u8 *p;
    u8 *e;
    u8 *q;
    u8 *r;
    s32 *t;
    s32 *u;
    s32 i;
    s32 m;
    s32 o;
    s32 two;
    s32 a;
    s32 b;
    u32 c;
    s32 v;

    func_800773C4(sp10);
    p = D_8009B458;
    i = 0;
    m = i;

    if (*(s16 *)(p + 0x510) > 0) {
        two = 2;
        t = D_80011434;
        q = sp10;
        o = 0x180;
        do {
            e = p + o;
            if (e[3] < 0x10) {
                func_8004A43C(e, 0);
            }
            if (*q == 0) {
                if (e[0xD] == 0) {
                    goto next;
                }
                r = D_8009B458 + e[3] * 0x18;
                a = r[6];
                if ((a & 0xF) != 0) {
                    r[6] = a - 1;
                }
                e[0xD] = 0;
                *(s16 *)(e + 0x1E) = 0;
                e[3] = 0x63;
            }

            b = e[0xD];
            c = b & 0xFF;
            if (c != 0 && *q == 3) {
                if (c >= 2) {
                    m = m | *t;
                    func_8004A7C0(i, b);
                } else {
                    e[0xD] = b + 1;
                }
            }

next:
            if (e[0xF] == 0 && (u32)(*q - 1) < 2) {
                u = t;
                while (1) {
                    func_80076ED0(0, *u);
                    v = func_80077090(*u);
                    if (v == two) {
                        break;
                    }
                    if (v == 0) {
                        break;
                    }
                }
                m = m | *u;
            }

            t++;
            q++;
            p = D_8009B458;
            o += 0x28;
            i++;
        } while (i < *(s16 *)(p + 0x510));
    }

    if (m != 0) {
        func_80076ED0(0, m);
    }
}
