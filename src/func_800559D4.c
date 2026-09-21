/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/model_control.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
extern int func_8007EF84();
extern int  func_8008E590(void);
extern ModelSlot D_800F2C40[3 ];
extern ModelSlotCF8TailView D_800F3938;
extern u8 D_8009AF94;
extern u8 D_8009AFA0;
extern char D_8009AFF4[];
extern char D_8009B030[];
extern char D_8009B038[];
extern char D_8009B040[];
extern char D_8009B048[];
extern char D_8009B050[];
extern char D_80011574[];
void func_800559D4(s32 index);
void func_8005F198(s32 value);
extern u8 *D_8001000C __attribute__((section(".data")));
extern u8 *D_80010010 __attribute__((section(".data")));
extern s32 D_80010014 __attribute__((section(".data")));
extern s32 D_80010018 __attribute__((section(".data")));
void func_80057AF4(s32 index, s32 anim, s32 flag);
s32 func_80058E1C(void);
void func_8004DC38(ModelSlot *slot, s32 i, s32 n, u32 pos);
extern s32 D_801D4244[];
void func_80048658(s32 id, s32 volume, s32 pan);
void func_800559D4(s32 index)
{
    ModelSlot *slot = &D_800F2C40[index];
    ModelSlot *other;
    ModelControlHandler handler;
    ModelControlHandler primary_handler;
    u8 *primary = (u8 *)slot->field_DE8;
    u8 *secondary = (u8 *)slot->field_DEC;
    u16 *own_stats;
    u16 *other_stats;
    u8 *stats_base;
    s32 command;
    s32 action;
    s32 state;
    s32 changed;
    s32 amount;
    s32 frame;
    s32 part;
    s32 primary_state;

    if (slot->field_E1F == 0) {
        return;
    }
    primary_state = ((ModelControlCommandView *)slot)->commands[2];
    D_8009AFA0 = index;
    if (primary_state >= 0) {
        if (index != 0) {
            primary_handler = (ModelControlHandler)(D_80010010 + 4);
        } else {
            primary_handler = (ModelControlHandler)(D_8001000C + 4);
        }
        func_8005F198(1);
        primary_handler(primary, -1);
        func_8005F198(0);
    }
    if (slot->field_E0E == 6) {
        if (slot->field_BF5 == slot->field_DFE + 3
            || slot->field_DF8 == 0x309 ) {
            slot->field_E0E = 7;
        } else {
            slot->field_E0E = 2;
        }
    }
    state = slot->field_E0E;
    if (state == 2) {
        return;
    }
    if (((ModelControlCommandView *)slot)->commands[slot->field_DFE] < 0) {
        goto no_handler;
    }
    if (index != 0) {
        handler = (ModelControlHandler)((u8 *)D_80010018 + 4);
    } else {
        handler = (ModelControlHandler)((u8 *)D_80010014 + 4);
    }
    if (slot->field_E0E == 7) {
        func_8005F198(1);
        {
            s32 request = ((ModelControlCommandView *)slot)->commands[slot->field_DFE];
            handler(secondary, request % 1000);
        }
        func_8005F198(0);
        slot->field_E0E = 8;
        slot->field_E08 = 0;
    }
    if (slot->field_BF5 != slot->field_DFE + 3
        && slot->field_DF8 != 0x309 ) {
        s32 eligible = slot->field_E0E;
        if (eligible != 0 && eligible != 3 && eligible != 1 && eligible != 4 && eligible != 5) {
            return;
        }
    }
    {
        s32 selected;
        s32 base;
        s32 stat_base;
        s32 own_offset;
        s32 other_offset;
        s32 own_record;
        s32 other_record;
        other_offset = (index ^ 1) * 0xE20 ;
        do { base = (s32)D_800F2C40; } while (0);
        other = (ModelSlot *)(other_offset + base);
        own_offset = index * 0xE20 ;
        stat_base = base + (u32)&((ModelSlot *)0)->field_CF8;
        own_record = own_offset + stat_base;
        other_record = other_offset + stat_base;
        if (other->field_DFF != 0) {
            {
                u16 own_value =
                    ((ModelSlotCF8TailView *)( own_record )) ->prefix.values.field_00;
                u16 other_value =
                    ((ModelSlotCF8TailView *)( other_record )) ->prefix.values.field_02;
                selected = own_value > other_value ? 6 : 8;
            }
        } else {
            u16 own_value =
                ((ModelSlotCF8TailView *)( own_record )) ->prefix.values.field_00;
            u16 other_value =
                ((ModelSlotCF8TailView *)( other_record )) ->prefix.values.field_00;
            selected = own_value > other_value ? 6 : 5;
            if (own_value == other_value) {
                selected |= 0x80;
                if (index != 0) {
                    selected = 6;
                }
            }
        }
        action = selected;
    }
    func_8005F198(1);
    slot->field_E0E = handler(secondary, -1);
    func_8005F198(0);
    switch (slot->field_E0E) {
    case 0:
        func_8007EF84(D_80011574);
        return;
    case 5:
        func_8007EF84(D_8009B030);
        if (other->field_E0F == 5 && other->field_E06 >= 0x60) {
            func_80057AF4(index ^ 1, 1, 1);
        }
        return;
    case 3:
        func_8007EF84(D_8009B038);
        if (action == 6) {
            other->field_E13 = 0x80;
            func_80057AF4(index ^ 1, 6, 1);
            return;
        }
        if (action & 0x80) {
            other->field_E13 = 0xFF;
            func_80057AF4(index ^ 1, 5, 1);
            return;
        }
    case 1:
    case 4: {
        s32 reaction;
        s32 offset;
        s32 own_record;
        s32 other_record;
        amount = func_80058E1C();
        offset = index * 0xE20 ;
        do { own_record = offset + (s32)&D_800F3938; } while (0);
        offset = (index ^ 1) * 0xE20 ;
        other_record = offset + (s32)&D_800F3938;
        amount = slot->field_E0D * (amount + 1);
        if ((((u8 *)&D_800F3938) + offset)[0x107 ] != 0) {
            {
                u32 own_value =
                    ((ModelSlotCF8TailView *)( own_record )) ->prefix.values.field_00;
                u32 other_value =
                    ((ModelSlotCF8TailView *)( other_record )) ->prefix.values.field_02;
                reaction = other_value < own_value ? 6 : 8;
            }
        } else {
            u32 own_value =
                ((ModelSlotCF8TailView *)( own_record )) ->prefix.values.field_00;
            u32 other_value =
                ((ModelSlotCF8TailView *)( other_record )) ->prefix.values.field_00;
            reaction = other_value < own_value ? 6 : 5;
            if (own_value == other_value) {
                reaction |= 0x80;
                if (index != 0) {
                    reaction = 6;
                }
            }
        }
        command = reaction & 0x7F;
        changed = 0;
        if (slot->field_E0E == 1) {
            func_8007EF84(D_8009B040);
        }
        if (slot->field_E0E == 4) {
            func_8007EF84(D_8009B048);
            if (slot->field_E0E == 4 && command == 6 && other->field_E0F != 6) {
                command = 5;
            }
        }
        if (other->field_E0F == command) {
            if (other->field_E16 != 0x23 && other->field_E06 >= 0xA0 &&
                ((func_8008E590() >> 8) & 3) != 0) {
                other->field_E06 -= amount;
                frame = other->field_E06;
                for (part = 0; part < other->field_E1B; part++) {
                    func_8004DC38(other, part, other->field_BF5, frame);
                }
                if ((func_8008E590() >> 8) & 1) {
                    changed++;
                }
            }
        } else {
            func_80057AF4(index ^ 1, command, 1);
            changed++;
        }
        if (D_8009AF94 == 0xF && changed != 0 && command == 8) {
            u32 card_id;
            s32 sound_id;
            do { card_id = other->field_DF8; } while (0);
            sound_id = ((D_801D4244[card_id] >> 26) & 0x1F) == 1 ? 3 : 4;
            func_80048658(sound_id, 0xFF, 0);
        }
        return;
    }
    case 2:
        func_8007EF84(D_8009B050);
        return;
    default:
        func_8007EF84(D_8009AFF4);
        slot->field_E0E = 2;
        return;
    }

no_handler:
    {
        s32 fallback_action;
        s32 offset;
        s32 own_record;
        s32 other_record;
        if (slot->field_BF5 == slot->field_DFE + 3) {
            s32 current_frame = slot->field_E06 >> 4;
            s32 midpoint = slot->field_750[slot->field_BF5].max >> 1;
            if (current_frame >= midpoint) {
                offset = index * 0xE20 ;
                own_record = offset + (s32)&D_800F3938;
                offset = (index ^ 1) * 0xE20 ;
                other_record = offset + (s32)&D_800F3938;
                if ((((u8 *)&D_800F3938) +
                     offset)[0x107 ] != 0) {
                    {
                        u32 own_value =
                            ((ModelSlotCF8TailView *)( own_record )) ->
                                prefix.values.field_00;
                        u32 other_value =
                            ((ModelSlotCF8TailView *)( other_record )) ->
                                prefix.values.field_02;
                        fallback_action = other_value < own_value ? 6 : 8;
                    }
                } else {
                    u32 own_value =
                        ((ModelSlotCF8TailView *)( own_record )) ->
                            prefix.values.field_00;
                    u32 other_value =
                        ((ModelSlotCF8TailView *)( other_record )) ->
                            prefix.values.field_00;
                    fallback_action = other_value < own_value ? 6 : 5;
                    if (own_value == other_value) {
                        fallback_action |= 0x80;
                        if (index != 0) {
                            fallback_action = 6;
                        }
                    }
                }
                func_80057AF4(index ^ 1, fallback_action & 0x7F, 1);
                slot->field_E0E = 2;
            }
        } else if (state == 8) {
            slot->field_E0E = 2;
        }
        if (slot->field_E0E == 7) {
            slot->field_E0E = 8;
        }
    }
}
