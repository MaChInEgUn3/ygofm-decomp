/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/gpu_packets.c, profile gcc_2_8_1_g8.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
void func_8005B4D8(u32 *src, GsOT *ot, s32 idx, s32 flags)
{
    u32 *s;
    u32 draw_mode;
    u32 mask_on;
    s32 len;
    s32 i;
    s32 index;
    u32 *dst;

    draw_mode = 0xE1000200;
    mask_on = 0xE6000001;
    s = src;
    index = idx;
    len = ((P_TAG *)( s )) ->len;
    D_800FE240[0] = *s++;
    D_800FE240[1] = ((flags & 3) << 5) | draw_mode;
    D_800FE240[2] = mask_on;
    dst = D_800FE240 + 3;
    for (i = len - 1; i != -1; i--) {
        *dst++ = *s++;
    }
    *(D_800FE240 + len + 3) = 0xE6000000;
    (((P_TAG *)( D_800FE240 ))->len  = (u8)(  len + 3 )) ;
    if (flags >= 0) {
        ((u8 *)( D_800FE240 )) [((u32)&((u32 *)0)[ 3 ] + (u32)&((P_CODE *)0)->code) ] |= 2;
    }
    (((P_TAG *)(   D_800FE240  ))->addr = (u32)(  (u32)(((P_TAG *)(  &ot->org[index & 0xFFFF]  ))->addr)  )) , (((P_TAG *)(  &ot->org[index & 0xFFFF]  ))->addr = (u32)(    D_800FE240  ))  ;
    D_800FE240 = D_800FE240 + (len + 4);
}
