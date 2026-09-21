/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/debug_effect_screen.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
u8 *func_800291E0(s32 index, s32 x, s32 y);
void func_80029528(s32 index);
void func_800137E4(void);
FileTransferDescriptor *func_80029164(s32 slot, s32 value);
u8 *func_8002C604(s32 id);
void func_80012D84(s32 count);
void func_8004036C(void *object);
void func_8001944C(DisplayObject *object);
extern ;
extern volatile u16 D_8009B398 __attribute__((section(".data")));
extern volatile u16 D_8009B3A4 __attribute__((section(".data")));
extern volatile u16 D_8009B394 __attribute__((section(".data")));
u8 *func_80017F04(DuelCardRecord *arg0, s32 arg1, s32 arg2);
extern u16 D_800908A0[];
extern u8 D_8009B16C[4];
extern u8 gDebugEffect_abPreviewState[6];
extern u8 *D_8009B180;
extern u8 *D_8009B184;
extern DuelCardRecord D_801A7B80[];
u8 gDebugEffect_abPreviewState[6] __attribute__((section(".sdata"))) = {0};
void func_800220B8(void);
void func_800222F4(void) {
    DisplayObject *obj;
    DuelEffectRequest *p;

    if (D_8009B3A4 & 0x800 ) {
        func_800220B8();
    }
    if ((D_8009B23A & 0x8000 ) == 0) {
        D_8009B23A |= 0xC000;
        D_8009B16C[2] = 0;
        gDebugEffect_abPreviewState[4]  = 0;
        gDebugEffect_abPreviewState[0]  = 0;
        (&gDebugEffect_abPreviewState[2]) [1] = 0;
        D_8009B184 = 0;
        D_8009B180 = 0;
    }
    if (D_8009B23A & 0x4000) {
        D_8009B23A &= 0xBFFF;
        func_80029528(0);
        func_8004036C(D_8009B180);
        func_8004036C(D_8009B184);
        D_8009B184 = 0;
        D_8009B180 = 0;
        switch (gDebugEffect_abPreviewState[4] ) {
        case 0:
            break;
        case 1:
            func_80029164(0, 1);
            func_800137E4();
            obj = (DisplayObject *)func_800291E0(0, -1, -1);
            obj->field_30.h.field_30 = 0x5A;
            obj->field_30.h.field_32 = 0x16;
            func_80012D84(4);
            func_8001944C(obj);
            break;
        case 2:
            D_8009B180 = func_80017F04(D_801A7B80, 0x86, 0x52);
            break;
        case 3:
            D_8009B180 = func_80017F04(D_801A7B80, 0x5C, 0x52);
            D_8009B184 = func_80017F04(&D_801A7B80[1], 0xB0, 0x52);
            break;
        }
    } else if (D_8009B398 & 0x100 ) {
        D_8009B23A |= 0x4000;
        gDebugEffect_abPreviewState[4] ++;
        if (gDebugEffect_abPreviewState[4]  >= 4) {
            gDebugEffect_abPreviewState[4]  = 0;
        }
    } else if (D_8009B398 & (0x8000  | 0x2000 )) {
        gDebugEffect_abPreviewState[0]  ^= 1;
    } else if (D_8009B394 & (0x1000  | 0x4000 )) {
        (&gDebugEffect_abPreviewState[2]) [gDebugEffect_abPreviewState[0] ]++;
        if (D_8009B394 & 0x4000 ) {
            (&gDebugEffect_abPreviewState[2]) [gDebugEffect_abPreviewState[0] ] -= 2;
        }
    } else if (D_8009B398 & 0x40 ) {
        p = (DuelEffectRequest *)func_8002C604(
            (&gDebugEffect_abPreviewState[2]) [0]);
        D_8009B16C[2] = (D_8009B16C[2] + 1) & 7;
        p->field_1A = (&gDebugEffect_abPreviewState[2]) [1];
        switch (gDebugEffect_abPreviewState[4] ) {
        case 0:
            p->field_00 = D_800908A0[0xC];
            p->field_02 = -0x18;
            p->field_04 = D_800908A0[0xD];
            break;
        case 1:
            p->field_00 = 0xA0;
            p->field_02 = 0x78;
            break;
        case 2:
            p->field_00 = 0xA0;
            p->field_02 = 0x70;
            break;
        case 3:
            p->field_00 = 0xA0;
            p->field_02 = 0x70;
            break;
        }
    }
}
