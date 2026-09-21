/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/movie_frame_pipeline.c, profile gcc_2_8_1_g8.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
extern int func_8007F978(RECT *rect, u32 *p);
void	func_800786A0(void);
void func_8005C1F4(void);
extern u8 D_8009B060;
extern u8 D_8009B062;
extern u8 D_8009B067;
extern s32 D_800F5D44 __attribute__((section(".data")));
extern u8 *D_8009B498;
extern void func_8008FDB4(u32 *buf, int size);
void func_8005C1F4(void) {
    u8 *src;
    u8 *dst;
    s32 idx;
    MovieWorkArea *out;

    if (D_8009B060 != 0) {
        if (D_800F5D44 != 0) {
            func_800786A0();
            D_800F5D44 = 0;
        }
    }
    dst = D_8009B498 + (u32)&((RECT *)0)[D_8009B067] + 0x40000;
    src = D_8009B498 + 0x40000;
    ((MovieWorkArea *)dst)->slots[0] = ((MovieWorkArea *)src)->strip;
    idx = D_8009B067;
    func_8007F978((RECT *)(D_8009B498 + 0x42400 + (u32)&((RECT *)0)[idx]),
              (u32 *)(
                  D_8009B498 + 0x37000 + (u32)&((u8 (*)[0x2D00])0)[idx]));
    D_8009B067 = (D_8009B067 + 1) % 4;
    out = (MovieWorkArea *)(D_8009B498 + 0x40000);
    out->strip.x += out->strip.w;
    if (out->strip.x < out->frame.x + out->frame.w) {
        func_8008FDB4((u32 *)(
                      D_8009B498 + 0x37000 +
                      (u32)&((u8 (*)[0x2D00])0)[D_8009B067]),
                  out->strip.w * out->strip.h / 2);
    } else {
        D_8009B062 = 1;
    }
}
