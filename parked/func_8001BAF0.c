#include "common.h"

typedef struct {
    u8 unk0;
    u8 unk1;
    s8 unk2;
    u8 unk3;
    s16 unk4;
} Rec6;

void func_8001BAF0(void) {
    s8 st[5];
    Rec6 tmp;
    Rec6 *b;
    Rec6 *a;
    Rec6 *o;
    u8 *e;
    Rec0C *r;
    u8 *sp;
    u8 *bb;
    s32 i;
    s32 j;
    s32 c;
    s32 t;
    s32 id;

    for (i = 0; i < 5; i++) {
        st[i] = (D_8009B1C8 + i)[0x1A];
    }
    for (i = 0; i < 5; i++) {
        c = D_800EAE88[i];
        if (c == 0) {
            break;
        }
        if (c < 0x10) {
            st[c - 0xB] = -1;
        }
    }
    bb = (u8 *)D_801AB000;
    b = (Rec6 *)(bb - 0x31E0);
    e = D_800EAE88;
    while (1) {
        c = *e;
        if (c == 0) {
            break;
        }
        if (c >= 0x10) {
            r = D_800EA030;
            for (j = 0; j < 5; j++, r++) {
                if (st[j] >= 0) {
                    a = &b[st[j]];
                    t = a->unk2;
                    o = &b[D_801AB000[c].unk9[2]];
                    a->unk2 = o->unk2;
                    o->unk2 = t;
                    tmp = *a;
                    *a = *o;
                    *o = tmp;
                    id = D_800907CC[j + D_8009B1D5 * 5];
                    sp = r->unk0;
                    func_800249E0(id, a->unk2);
                    r->unk0 = (u8 *)func_80018004(&D_801A7AD8[id * 28],
                                                  *(s16 *)(sp + 0x30),
                                                  *(s16 *)(sp + 0x32));
                    func_8004036C((s32)sp);
                    (D_8009B1C8 + j)[0x1A] = a->unk2;
                    *e = j + 0xB;
                    st[j] = -1;
                    break;
                }
            }
        }
        e++;
        if ((s32)e - (s32)D_800EAE88 >= 5) {
            break;
        }
    }
}
