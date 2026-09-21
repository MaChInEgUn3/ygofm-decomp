/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/gpu_packets.c, profile gcc_2_8_1_g8.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
extern u32 *D_800FE240 __attribute__((section(".data")));
void func_8005B260(u32 *src, GsOT *ot, s32 idx, s32 flags);
void func_8005B260(u32 *src, GsOT *ot, s32 idx, s32 flags)
{
    u32 *s;
    u32 draw;
    s32 len;
    s32 i;
    s32 index;
    u32 *dst;

    draw = 0xE1000200;
    s = src;
    index = idx;
    len = ((P_TAG *)( s )) ->len;
    D_800FE240[0] = *s++;
    D_800FE240[1] = ((flags & 3) << 5) | draw;
    dst = D_800FE240;
    dst = dst + 2;
    for (i = len - 1; i != -1; i--) {
        *dst++ = *s++;
    }
    draw = (u8)(len + 1);
    i = draw;
    ((P_TAG *)( D_800FE240 )) ->len = i;
    if (flags >= 0) {
        ((u8 *)( D_800FE240 )) [((u32)&((u32 *)0)[ 2 ] + (u32)&((P_CODE *)0)->code) ] |= 2;
    }
    (((P_TAG *)(   D_800FE240  ))->addr = (u32)(  (u32)(((P_TAG *)(  &ot->org[index & 0xFFFF]  ))->addr)  )) , (((P_TAG *)(  &ot->org[index & 0xFFFF]  ))->addr = (u32)(    D_800FE240  ))  ;
    D_800FE240 = D_800FE240 + (len + 2);
}
