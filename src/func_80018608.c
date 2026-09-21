/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/duel_phase_entry.c (DuelScene_UpdateStartup), profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern s32 D_801D4244[];
extern DuelDeckCardRecord D_801A7E20[];
extern u8 D_8009B1D5;
extern u16 D_8009B36A __attribute__((section(".data")));
void func_80018608(void);
extern ViewState D_800F2848;
void func_8001352C(void);
void func_8001352C(void);
extern DuelHandSlot D_800EA030[5 ];
extern u8 D_8009B1EC;
void func_800176D0(void);
void func_800157DC(void);
extern u32 D_8009B134_abs __attribute__((section(".data")));
extern u8 D_800E9F10[];
extern DuelCardPickCursor *D_8009B1B4;
void func_8003FF08(u32);
extern u16 D_8009B162;
extern u8 D_8009B174;
void func_80024734(void);
void func_80024824(void);
void func_80018608(void)
{
    u16 *w;
    DuelDeckCardRecord *rec;
    s32 i;
    s32 atk;
    s32 def;
    s32 stat;
    s32 stat2;

    w = (u16 *)&D_800F2848;
    if ((D_8009B23A & 0x8000 ) == 0) {
        D_8009B23A |= 0x8000 ;
        func_80024734();
        D_800F2848.field_00 = 0x4B0;
        w[2] = 0x358;
        w[1] = 0x16C0;
        func_8001352C();
        D_8009B174 = 2;
        func_800157DC();
        return;
    }

    switch (D_8009B174 & 0x1F) {
    case 2:
        D_800F2848.field_00 -= 2;
        w[2] -= 2;
        w[1] -= 0x10;
        if ((s16)w[1] <= 0x400) {
            D_800F2848.field_00 = 0x258;
            w[2] = 0x100;
            w[1] = 0x400;
            D_8009B174 = 3;
        }
        func_8001352C();
        break;
    case 3:
        if ((D_8009B174 & 0x80) == 0) {
            D_8009B174 |= 0x80;
            D_8009B162 = 2;
            D_8009B1B4 = (DuelCardPickCursor *)(D_800E9F10 +
                D_8009B1D5 * (4  * 0x1C ) );
            *(u16 *)&D_8009B1B4->field_0C = 0xAE;
        }
        if (D_8009B162 == 0) {
            D_8009B174 = 4;
        }
        break;
    case 4: {
        u32 mask = 0x02000030 ;

        if (((D_8009B0F4_abs & mask) |
             D_8009B134_abs) != 0) {
            break;
        }
        func_8003FF08(D_8009B36A);
        func_80024824();
        atk = 0;
        def = 0;
        rec = D_801A7E20;
        for (i = 0; i < 40 ; i++, rec++) {
            stat = D_801D4244[rec->id - 1];
            atk += (stat & 0x1FF ) * 10 ;
            def += ((stat >> 9 ) & 0x1FF ) *
                   10 ;
        }
        D_800E9FF0[0].field_0E = atk / 40 ;
        D_800E9FF0[0].field_10 = def / 40 ;
        atk = 0;
        def = 0;
        rec = &D_801A7E20[40 ];
        for (i = 0; i < 40 ; i++, rec++) {
            stat2 = D_801D4244[rec->id - 1];
            atk += (stat2 & 0x1FF ) * 10 ;
            def += ((stat2 >> 9 ) & 0x1FF ) *
                   10 ;
        }
        D_800E9FF0[1].field_0E = atk / 40 ;
        D_800E9FF0[1].field_10 = def / 40 ;
        D_8009B174 = 5;
        break;
    }
    case 5:
        func_800176D0();
        D_8009B1EC = 5 ;
        D_8009B23A = 3;
        ((DuelSelectionSideView *)(D_800E9F10 +
            D_8009B1D5 * (4  * 0x1C ) ))->hand = D_800EA030;
        break;
    }
}
