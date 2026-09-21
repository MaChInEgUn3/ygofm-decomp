/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/library_runtime.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
int func_80058DD8(int index);
void *func_800591FC(void);
extern u8 D_800EA1E8[];
extern s16 D_80181002 __attribute__((section(".data")));
extern s16 D_80181012 __attribute__((section(".data")));
void func_8002ACA4(u8 *state);
void func_8002BAA0(u8 *state);
void func_8002BAAC(u8 *state);
void func_8002BAB4(void);
void func_80058FB0(s32 idx, u16 *out);
void func_80057F38(u8 *view);
extern ViewState D_800F2848;
void func_8001352C(void);
void func_8001352C(void);
extern int  func_8008E590(void);
s32 func_80058E68(s32 index);
void func_80057AF4(s32 index, s32 anim, s32 flag);
void func_8002A788(u8 *state);
void func_8002ACA4(u8 *state);
void func_8002BAA0(u8 *value);
void func_8002BAAC(u8 *value);
void func_8002BAB4(void)
{
    u8 *state;
    ViewState *model;
    s32 one;
    s32 r;
    s32 a;
    s32 step;
    s32 cur;
    s32 target;
    s32 count;
    s32 mode;
    u8 *dst;
    ViewState *p;

    state = D_800EA1E8;
    one = 1;
    mode = D_800EA1E8[0];
    mode &= 0xF;
    switch (mode) {
    case 0:
        func_8002BAA0(state);
        break;
    case 1:
        func_8002A788(state);
        break;
    case 2:
        func_8002ACA4(state);
        model = &D_800F2848;
        r = func_80058DD8(0);
        if (r == one) {
            if (func_80058E68(0) != r) {
                func_80058FB0(0, (u16 *)0x80181010);
                r = D_80181012 - D_80181002;
                a = r >= 0 ? r : -r;
                step = a / 24;
                step += 1;
                cur = model->view.vry;
                if (D_80181012 < cur) {
                    model->view.vry = cur - step;
                    cur = *(volatile long *)&model->view.vry;
                }
                if (cur < D_80181012) {
                    model->view.vry = cur + step;
                }
            } else {
                r = model->view.vry;
                target = D_80181002;
                if (r != target) {
                    if (target < r) {
                        r -= 8;
                        if (r < target) {
                            r = target;
                        }
                    } else {
                        r += 8;
                        if (target < r) {
                            r = target;
                        }
                    }
                    model->view.vry = r;
                }
                count = *(s32 *)(state + 0x20) - 1;
                *(s32 *)(state + 0x20) = count;
                if (count <= 0) {
                    *(s32 *)(state + 0x20) = 0x12C;
                    r = 2;
                    if (func_8008E590() & 1) {
                        r = 7;
                    }
                    func_80057AF4(0, r, 1);
                }
            }
        }
        p = &D_800F2848;
        p->angle += 0xC;
        func_8001352C();
        dst = func_800591FC();
        ((LibraryViewQuad *)dst)[0] = *(LibraryViewQuad *)&model->view.vpx;
        ((LibraryViewQuad *)dst)[1] = *(LibraryViewQuad *)&model->view.vry;
        func_80057F38(0);
        break;
    case 3:
        func_8002BAAC(state);
        break;
    }
}
