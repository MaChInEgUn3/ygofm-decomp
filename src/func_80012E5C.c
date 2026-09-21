/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/graphics_frame.c (Graphics_BeginFrame), profile gcc_2_8_1_g8_split_comm.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern DRAWENV D_800FE048[];
extern u8 D_8009B142 __attribute__((section(".data")));
extern u8 D_8009B143 __attribute__((section(".data")));
extern u8 D_8009B144 __attribute__((section(".data")));
extern u8 D_8009B0A0[4];
extern u8 D_8009B0A0[4];
void func_80012E5C(void)
{
    s32 i;
    GsOT **slot;
    s32 idx;
    GsOT *ptr;
    u8 *arg;
    GsOT **base;

    if (D_8009B0A8 == 0) {
        D_800FE048[0].isbg = D_8009B0D0;
        D_800FE048[0].dtd = D_8009B0AD;
        D_800FE048[0].r0 = D_8009B144;
        D_800FE048[0].g0 = D_8009B143;
        D_800FE048[0].b0 = D_8009B142;
        func_80085500();
        if ((D_8009B098 & 0x2000) != 0) {
            func_8007FEFC(&D_800E9D28);
        }
    }
    func_8007F350(1);
    if ((D_8009B318 & 0x80) != 0) {
        func_800359B0();
    }
    if ((D_8009B318 & 0x80) == 0) {
        if (D_8009B141 != 0) {
            func_80085E10(&D_8009B0B4->ordering_tables[1],
                     &D_8009B0B4->ordering_tables[0]);
            if ((D_8009B141 & 0x80 ) == 0) {
                func_80085E10(&D_8009B0B4->ordering_tables[2],
                         &D_8009B0B4->ordering_tables[0]);
                func_80085E10(&D_8009B0B4->ordering_tables[3],
                         &D_8009B0B4->ordering_tables[0]);
            }
            func_80085D80(&D_8009B0B4->ordering_tables[0]);
        }
    }
    idx = func_80085320();
    i = 3;
    D_8009B0AC = idx;
    arg = &D_800A5768[
        D_8009B0AC * 140000 
    ];
    D_8009AFA2 = idx;
    D_8009B0B4 =
        &D_8009B4A8[D_8009B0AC];
    func_800862C0((PACKET *)arg);
    base = D_800E9D90;
    slot = base + 3;
    do {
        ptr = &D_8009B0B4->ordering_tables[i];
        *slot = ptr;
        slot--;
        ptr->length = D_8009B0A0[i];
        func_80085DB0(0, 0, ptr);
        i--;
    } while (i >= 0);
}
