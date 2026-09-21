/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_80052D2C.c (Model_SetSlotProperties), profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
extern ModelSlot D_800F2C40[3 ];
extern u8 D_80091008[];
extern s16 D_8009B488[3 ];
extern u8 D_8009B48E[2];
extern u8 D_8009B490[2];
void func_80053248(s32 idx, ...);
extern u8 *D_8009AF88;
extern u8 D_8009AF94;
extern u16 D_800F5678[];
void func_80053248(s32 idx, ...)
{
    va_list ap;
    s32 p1;
    s32 p2;
    s32 p3;
    s32 p4;
    s32 p5;

    ( ap  = ((char *)&(  idx ) + (((sizeof (   idx  ) + sizeof (int) - 1) / sizeof (int)) * sizeof (int)) )) ;
    p1 = ( ap  = ((char *) ( ap )) += (((sizeof (   s32  ) + sizeof (int) - 1) / sizeof (int)) * sizeof (int)) ,	*((  s32  *) ((char *) ( ap ) - (((sizeof (   s32  ) + sizeof (int) - 1) / sizeof (int)) * sizeof (int)) ))) ;
    if (p1 >= 0) {
        D_800F2C40[idx].field_DF8 = p1;
        D_8009B488[idx] = p1;
    }
    if (idx < 2) {
        p2 = ( ap  = ((char *) ( ap )) += (((sizeof (   s32  ) + sizeof (int) - 1) / sizeof (int)) * sizeof (int)) ,	*((  s32  *) ((char *) ( ap ) - (((sizeof (   s32  ) + sizeof (int) - 1) / sizeof (int)) * sizeof (int)) ))) ;
        p3 = ( ap  = ((char *) ( ap )) += (((sizeof (   s32  ) + sizeof (int) - 1) / sizeof (int)) * sizeof (int)) ,	*((  s32  *) ((char *) ( ap ) - (((sizeof (   s32  ) + sizeof (int) - 1) / sizeof (int)) * sizeof (int)) ))) ;
        p4 = ( ap  = ((char *) ( ap )) += (((sizeof (   s32  ) + sizeof (int) - 1) / sizeof (int)) * sizeof (int)) ,	*((  s32  *) ((char *) ( ap ) - (((sizeof (   s32  ) + sizeof (int) - 1) / sizeof (int)) * sizeof (int)) ))) ;
        p5 = ( ap  = ((char *) ( ap )) += (((sizeof (   s32  ) + sizeof (int) - 1) / sizeof (int)) * sizeof (int)) ,	*((  s32  *) ((char *) ( ap ) - (((sizeof (   s32  ) + sizeof (int) - 1) / sizeof (int)) * sizeof (int)) ))) ;
        if (p2 >= 0) {
            D_800F2C40[idx].field_DFA = p2;
        }
        if (p3 >= 0) {
            D_800F2C40[idx].field_DFC = p3;
        }
        if (p4 >= 0) {
            D_800F2C40[idx].field_DFE = (p4 != 0);
            D_8009B48E[idx] = (p4 != 0);
        }
        if (p5 >= 0) {
            D_800F2C40[idx].field_DFF = (p5 != 0);
            D_8009B490[idx] = (p5 != 0);
        }
    } else {
        D_8009AF88 = &D_80091008[D_800F5678[0] * 0xB2];
    }
    D_8009AF94 = 15;
}
