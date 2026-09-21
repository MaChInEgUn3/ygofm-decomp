/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/gpu_packets.c (Graphics_SubmitTextureWindowPacket), profile gcc_2_8_1_g8.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern u32 *D_800FE240 __attribute__((section(".data")));
void func_8005B36C(
    u32 *src,
    GsOT *ot,
    s32 idx,
    s32 offx,
    s32 offy,
    s32 maskx,
    s32 masky
);
void func_8005B36C(
    u32 *src,
    GsOT *ot,
    s32 idx,
    s32 offx,
    s32 offy,
    s32 maskx,
    s32 masky
)
{
    u32 *from;
    s32 len;
    s32 i;
    u32 *dst;
    s32 index;
    u32 first;

    len = ((P_TAG *)( src )) ->len;
    index = idx;
    first = src[0];
    D_800FE240[0] = first;
    src++;
    D_800FE240[1] = 0xE2000000
                  | ((((-maskx) & 0xFF) / 8) & 0x1F)
                  | (((((-masky) & 0xFF) / 8) & 0x1F) << 5)
                  | ((((offx & 0xFF) / 8) & 0x1F) << 10)
                  | ((((offy & 0xFF) / 8) & 0x1F) << 15);
    dst = D_800FE240 + 2;
    from = src;
    for (i = len - 1; i != -1; i--) {
        *dst++ = *from++;
    }
    D_800FE240[len + 2] = 0xE2000000;
    (((P_TAG *)( D_800FE240 ))->len  = (u8)(  len + 2 )) ;
    (((P_TAG *)(   D_800FE240  ))->addr = (u32)(  (u32)(((P_TAG *)(  &ot->org[index & 0xFFFF]  ))->addr)  )) , (((P_TAG *)(  &ot->org[index & 0xFFFF]  ))->addr = (u32)(    D_800FE240  ))  ;
    D_800FE240 = D_800FE240 + (len + 3);
}
