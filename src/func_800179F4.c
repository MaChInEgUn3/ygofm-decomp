/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/duel_init_scene.c (Duel_InitScene), profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern u8 D_800907D8[];
extern u8 D_8009B1D5;
extern u16 D_8009B16C;
extern DisplayObject *D_8009B214;
extern DisplayObject *D_8009B21C;
extern u8 *D_8009B1D8;
extern u16 D_8009B204;
void func_800179F4(void)
{
    DisplayObject *obj;
    u8 *p;
    u8 *q;
    s32 value;
    s32 side;
    DuelEffectResourceRecord *pane;
    u8 *prev;
    s8 *pid;

    pid = &D_8009B361;
    func_8004763C();
    func_80047AD0(1);
    func_80012D84(4);
    func_800137E4();
    value = D_8009B364;
    func_80014E1C(
        0, 0,
        (((value * 15) * 4 - value) * 4 - value) +
            0x16C6 ,
        0xEB , func_800171A8, 0, 0);
    func_800137E4();
    D_8009B238 = -1;
    D_8009B23A = 11;
    D_8009B164 = 0;
    D_8009B162 = 0;
    D_8009B1D4 = 0;
    D_8009B204 = 0;
    D_8009B220 = 0;
    D_8009B16C = 0;
    D_8009B174 = 0;
    if (D_8009B369 != 1) {
        if (D_8009B361 >= 0) {
            func_80014E1C(
                0, 0,
                D_8009B361 * (3  - 1) +
                    D_8009B361 + 0x1D33 ,
                3 , 0, 0,
                (s32)D_801781D8
            );
        }
        D_8009B1D5 = 0;
        D_8009B23A = 1;
        func_8001778C();
        func_80017708();
        func_800175A0();
        D_8009B16C |= 0x1000;
    }
    D_8009B1C8 = &D_800E9FF0[D_8009B1D5];
    func_800178BC();
    D_800F2848.angle =
        D_8009B1D5 * (0x1000  / 2)  + (0x1000  / 4) ;
    func_8001352C();
    func_800176D0();
    pane = &D_800EA0E8[0];
    func_8002C598();
    func_80029574(0);
    pane->src_x = 0;
    pane->src_y = 256;
    pane->field_2C = 0;
    pane->field_2E = 255;
    func_80029574(1);
    pane[1].src_x = 64;
    pane[1].src_y = 256;
    pane[1].field_2C = 0;
    pane[1].field_2E = 254;
    func_80035668(0);
    func_8001755C();
    func_800137E4();
    D_8009B22C =
        &D_800907D8[D_8009B1D5 * 20 ];
    obj = func_800400AC(func_8004002C(), 2);
    func_800404CC(obj, 12, 24, 4, 2, D_8009B364, 11, 732);
    func_80042918(obj);
     











    *(s16 *)&obj->flags |= 0x08 ;
    side = (u32)D_8009B361 >> 31;
    D_8009B214 = obj;
    obj = func_800400AC(func_8004002C(), 2);
    func_800404CC(
        obj, 280, 32, 4, side, 0, 11, 748
    );
    func_80042918(obj);
    *(s16 *)&obj->flags |= 0x08 ;
    if (D_8009B1D5 != 0) {
        *(u16 *)&obj->field_40.h.field_40 += 16;
    }
    D_8009B21C = obj;
    obj = func_800400AC(func_8004002C(), 6);
    func_80042918(obj);
    func_800428EC(obj, 1);
    obj->field_4C = (s32)func_80016E70;
    prev = (u8 *)D_8009B21C;
    obj->field_50.word = (s32)prev;
    D_800E9DB0[3] = func_800164FC;
    if (D_8009B369 != 1) {
        p = 0;
        D_8009B1DC = 0;
        D_8009B1D8 = 0;
        if (pid[-1] < 0) {
            if (D_8009B361 < 0) {
                D_8009B1D8 = D_801D1200;
                D_8009B1DC = D_801D1200 + 0x1000 ;
                func_800245A0(
                    D_801D1200, D_801D1200 + 0x1000 
                );
                return;
            }
            p = (u8 *)D_801D0200;
            D_8009B1D8 = p;
            if (D_8009B361 < 39 ) {
                q = 0;
                goto shuffle;
            }
        }
        q = p;
    shuffle:
        func_800245A0(p, q);
    }
}
