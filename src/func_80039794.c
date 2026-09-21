/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_80039794.c, profile gcc_2_8_1_g8_split_no_strength_reduce.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern u8 D_8009B0C1 __attribute__((section(".data")));
extern u16 D_8009B398 __attribute__((section(".data")));
void func_8003B50C(s32 value);
void func_80039D64(DuelEffectChannel *);
extern u8 D_8009B356;
void func_800393B0(struct DuelEffectChannel *object);
extern s16 D_8009B35A;
struct DisplayObject *func_800374F4(DuelEffectChannel *record);
extern u32 D_801D9000[];
void func_80039794(void)
{
    DuelEffectChannel *p;
    ChoiceChannelCursor *q;
    s32 reset_value;
    TblEnt *table;
    s32 n;
    s32 cnt;
    s32 idx;
    s32 kind;
    s32 arg;
    u16 f;

    p = D_800EB0F8;
    n = 4;
    reset_value = -1;
    table = (TblEnt *)D_801D9000;
    q = (ChoiceChannelCursor *)&p->field_30;
    do {
        if (q->choice.flags & 0x8000) {
            D_8009B35A = 0;
            if ((q->choice.flags & 0x2000) == 0) {
                D_8009B35A = reset_value;
                cnt = -1;
                for (;;) {
                    func_800393B0(p);
                    cnt++;
                    f = q->choice.flags;
                    if (f & 0x2000) {
                        if (f & 8) {
                            q->choice.obj = func_800374F4(p);
                        }
                        break;
                    }
                    if (f & 0x1C00) {
                        goto reset;
                    }
                    if (cnt >= D_8009B0C1) {
                        break;
                    }
                    continue;
reset:
                    D_8009B35A = reset_value;
                }
            } else {
                if (q->choice.flags & 8) {
                    if (D_8009B398 & (0x40  | 0x80 ) ) {
                        q->choice.flags &= 0xFFF7;
                        func_8004036C(q->choice.obj);
                        q->choice.obj = 0;
                        func_8003FEE0(0xB);
                    }
                }
            }
            arg = -1;
            idx = D_8009B35A;
            if (idx >= 0) {
                kind = table[idx].hi & 7;
                if (kind == 4) {
                    arg = D_8009B356;
                } else {
                    D_8009B356 = kind;
                    arg = kind;
                }
            }
            func_8003B50C(arg);
            func_80039D64(p);
        }
        q++;
        n--;
        p++;
    } while (n != 0);
}
