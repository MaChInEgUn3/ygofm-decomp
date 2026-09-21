/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/movie_frame_pipeline.c (Movie_DecodeAndPresentFrame), profile gcc_2_8_1_g8.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern DRAWENV *func_8007FEC8(DRAWENV *env);
s32 func_8005BE3C(void);
s32 func_8005BFC8(s32 resync);
extern u8 D_8009B060;
extern u8 D_8009B062;
extern u8 D_8009B063;
extern u8 D_8009B064;
extern u8 D_8009B065;
extern u8 D_8009B066;
extern u8 D_8009B067;
extern u8 *D_8009B498;
extern void func_8008FD38(u32 *buf, int mode);
extern void func_8008FDB4(u32 *buf, int size);
s32 func_8005C5D4(void);
void func_80044F58(s32 value);
s32 func_8005BFC8(s32 resync);
s32 func_8005BE3C(void) {
    DRAWENV env;
    s32 fade;
    s32 result;
    s32 x;
    s32 y;
    MovieWorkArea *frame;
    MovieWorkArea *display;
    MovieWorkArea *rects;
    MovieWorkArea *out;
    s32 slot;
    s32 side;

    if (D_8009B063 != 0) {
        return 1;
    }
    if (D_8009B064 != 0) {
        if (D_8009B065 == 0) {
            return 1;
        }
        fade = D_8009B065 - 0x40;
        if (fade < 0) {
            fade = 0;
        }
        D_8009B065 = fade;
        func_80044F58(D_8009B065);
    }
     


    *(volatile u8 *)&D_8009B062 = 0;
    func_8007FEC8(&env);

    frame = (MovieWorkArea *)(D_8009B498 + 0x40000);
    display = (MovieWorkArea *)(D_8009B498 + 0x40000);
    x = env.clip.x +
        ((D_8009B060 != 0 ? 0x1E0 : 0x140) - frame->frame.w) / 2;
    side = D_8009B060;
    slot = D_8009B066;
     




    *(s16 *)((u8 *)display +
        (u32)&((MovieWorkArea *)0)->strip.x) = x;
    *(s16 *)((u8 *)frame +
        (u32)&((MovieWorkArea *)0)->frame.x) = x;

    rects = (MovieWorkArea *)(D_8009B498 + 0x40000);
    y = *(u16 *)&env.clip.y + (0xF0 - rects->frame.h) / 2;
    rects->strip.y = y;
    rects->frame.y = y;
    func_8008FD38((u32 *)(D_8009B498 + 0x1B000 + slot * 0xE000), side);

    out = (MovieWorkArea *)(D_8009B498 + 0x40000);
    func_8008FDB4((u32 *)(D_8009B498 + 0x37000 + D_8009B067 * 0x2D00),
              out->strip.w * out->strip.h / 2);

    result = func_8005BFC8(1);
    if (result != 0) {
        return result;
    }
    func_8005C5D4();
    return 0;
}
