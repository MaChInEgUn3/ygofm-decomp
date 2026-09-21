/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/campaign_load_scene_package.c (Campaign_LoadScenePackage), profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
extern SceneScriptSlot D_800EAE98[];
FileTransferDescriptor *func_80014E1C(
    s32, u8 *, s32, s32, FileTransferCallback, s32, s32
);
void func_800137E4(void);
extern int func_80082324(int max_count);
extern int func_80081DE8(RECT *rect, u32 *p);
extern RECT D_800E9D70[2];
extern s16 D_8009B146 __attribute__((section(".data")));
extern s16 D_8009B148 __attribute__((section(".data")));
s8 *func_80039E9C(void);
extern u16 D_8009B2A4;
void func_8002FD10(s16 arg0);
void func_8002FB78(
    FileTransferDescriptor *descriptor, s32 stage
);
extern DisplayObject *D_8009B2A0;
DisplayObject *func_8002E3FC(void);
extern u8 *D_80010000 __attribute__((section(".data")));
void func_8002FD10(s16 arg0)
{
    SceneScriptSlot *slot;
    u32 *src;
    RECT *second;
    s32 i;

    slot = D_800EAE98;
    D_8009B2A4 = arg0;
    D_8009B148 = 0;
    D_8009B146 = 0;
    D_8009B2A0 = 0;
    func_80014E1C(
        0, 0,
        0x1E57 ,
        0x31 ,
        func_8002FB78, 0, 0
    );
    func_80039E9C();

    (*(s16 *)( &slot[3] ))  = -1;
    for (i = 0; i < 3; i++) {
        slot[i].unk00 = 0;
        slot[i].unk04 = 0;
    }
    func_800137E4();

    while (func_80082324(10)) {
        ;
    }

    src = ((u32 *)( D_80010000 )) ;
    D_800E9D70[0].x = 0x380;
    D_800E9D70[0].y = 0;
    D_800E9D70[0].w = (48  / 2) ;
    D_800E9D70[0].h = 48 ;
    second = &D_800E9D70[1];
    D_800E9D70[1].x = 0x380;
    second->y = 0xF0;
    second->w = 0x40 ;
    second->h = 1;

    i = 0;
    do {
        func_80081DE8(&D_800E9D70[0], src);
        func_80081DE8(
            &D_800E9D70[1],
            src + 0x900  / sizeof(u32)
        );
        i++;
        D_800E9D70[1].y = D_800E9D70[1].y + 1;
        D_800E9D70[0].x =
            (i % 5 ) *
                (48  / 2)  + 0x380;
        D_800E9D70[0].y =
            (i / 5 ) *
                48 ;
        if (D_800E9D70[1].y >=
            0xF0 + 16 ) {
            D_800E9D70[1].x =
                D_800E9D70[1].x +
                0x40 ;
            D_800E9D70[1].y = 0xF0;
        }
        src += (0x900  + 0x80 )  / sizeof(u32);
    } while (i < 25 );

    D_8009B2A0 = func_8002E3FC();
}
