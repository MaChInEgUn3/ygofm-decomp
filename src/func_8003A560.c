/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/display_effect_resource_setup.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
extern int func_8007F978(RECT *rect, u32 *p);
extern int func_8007F9D8(RECT *rect, u32 *p);
extern int func_80082324(int max_count);
s32 func_80039F1C(DisplayEffectState *object);
extern u8 D_801AF000[];
FileTransferDescriptor *func_80014EEC(
    s32, u8 *, s32, s32, FileTransferCallback, s32, s32
);
extern volatile u32 D_8009B0F4_abs __attribute__((section(".data")));
extern u32 D_8009B134_abs __attribute__((section(".data")));
void func_800356A0(u8 *destination, u8 *source, u32 length);
void func_8003A01C(
    FileTransferDescriptor *descriptor, s32 mode);
s32 func_8003A1EC(
    MenuRecord *record, DisplayObject **out, s32 resource_index);
extern s8 D_8009B326;
extern s8 D_8015C410[];
void func_8003A560(DisplayEffectVramState *state);
extern u8 D_801AF800[];
extern u8 *D_80010000 __attribute__((section(".data")));
void func_8003A560(DisplayEffectVramState *a)
{
    DisplayEffectVramSlot *slots;
    DisplayEffectVramSlot *slot;
    FileTransferDescriptor *req;
    s32 i;

    if (func_80039F1C((DisplayEffectState *)a) == 0) {
        slots = (DisplayEffectVramSlot *)D_80010000;
        D_8009B326 = 0;
         



        slot = &slots[5  - 1];
        for (i = 5  - 1; i >= 0; i--) {
            if (D_8015C410[i] < 0) {
                D_8009B326 = i;
            }
            if (D_8015C410[i] == a->field_30) {
                while (func_80082324(10) != 0) {
                    ;
                }
                slot->image_rect.x = 832 - a->field_3C * 192;
                slot->image_rect.y = 256;
                slot->image_rect.w = 192;
                slot->image_rect.h = 256;
                func_8007F978(&slot->image_rect, (u32 *)slot->image);
                slot->clut_rect.x = 512;
                slot->clut_rect.y = a->field_3C * 2 + 240;
                slot->clut_rect.w = 256;
                slot->clut_rect.h = 2;
                func_8007F978(&slot->clut_rect, (u32 *)slot->clut);
                if (a->field_3C != 0) {
                    func_800356A0(D_801AF800, slot->extra, 0x800);
                } else {
                    func_800356A0(D_801AF000, slot->extra, 0x800);
                }
                a->state |= 0x40;
                return;
            }
            slot--;
        }
        if (((D_8009B0F4_abs & 0x02000030 ) |
             D_8009B134_abs) != 0) {
            a->state &= 0x7F;
            return;
        }
        req = func_80014EEC(
            0, 0, a->field_30 * 50 + 15182, 50, func_8003A01C, 0, 0
        );
        req->callback_data = D_801AF000;
        req->position = a->field_3C;
        if (a->field_3C != 0) {
            req->callback_data = D_801AF800;
        }
        D_8009B0F4_abs = req->status_flags | 0x10 ;
    } else if ((a->state & 0x40) == 0) {
        if (((D_8009B0F4_abs & 0x02000030 ) |
             D_8009B134_abs) != 0) {
            return;
        }
        a->state |= 0x40;
        D_8015C410[D_8009B326] = a->field_30;
        while (func_80082324(10) != 0) {
            ;
        }
        slot = &((DisplayEffectVramSlot *)D_80010000)[D_8009B326];
        slot->image_rect.x = 832 - a->field_3C * 192;
        slot->image_rect.y = 256;
        slot->image_rect.w = 192;
        slot->image_rect.h = 256;
        func_8007F9D8(&slot->image_rect, (u32 *)slot->image);
        slot->clut_rect.x = 512;
        slot->clut_rect.y = a->field_3C * 2 + 240;
        slot->clut_rect.w = 256;
        slot->clut_rect.h = 2;
        func_8007F9D8(&slot->clut_rect, (u32 *)slot->clut);
        if (a->field_3C != 0) {
            func_800356A0(slot->extra, D_801AF800, 0x800);
        } else {
            func_800356A0(slot->extra, D_801AF000, 0x800);
        }
    } else {
        func_8003A1EC(
            (MenuRecord *)a, (DisplayObject **)a, a->field_31);
        a->state = 0;
        a->field_32 |= 0x40;
    }
}
