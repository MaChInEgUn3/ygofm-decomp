/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_80052D2C.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
void func_800533D8(void){s16 table[256];RECT packet;register s16*p=&table[1];register s32 fill=0xffff;register s32 counter=254;s32 i;table[0]=0;do{*p=fill;counter--;p++;}while(counter>=0);packet.x=0x200;packet.y=0xF0;packet.w=0x100;packet.h=1;while(func_80082324(3)){}while(func_80081DE8(&packet,(u32 *)table)){}while(func_80082324(3)){}func_8005611C(0);func_8005611C(1);func_8005611C(2);for(i=0;i< 10 ;i++)D_800F2B50[i].flags&=0xfffe;D_8009AF9B=0;D_8009AF9C=0;func_80059AE0(0x8000);D_8009AF94=0;D_8009AF9A=-1;}
