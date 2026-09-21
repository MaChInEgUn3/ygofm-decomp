/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/text_box_build_step.c (TextBox_BuildStep), profile gcc_2_8_1_g8_split_comm.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef void (*ScriptCommandHandler)(void);
typedef struct {
    u16 code_00;
    u16 pad_02;
    s32 field_04;
    s32 field_08;
    s16 x_0C;
    s16 y_0E;
    u8 field_10;
    u8 flags_11;
    u8 field_12;
    u8 field_13;
    u8 pad_14;
    u8 field_15;
     
    u8 field_16;
    u8 field_17;
    u8 field_18;
    u8 pad_19[3];
} DuelEffectEntry;
typedef struct {
    u8 *streams[22 ];
    s8 stream_index;
} TextStreamOwner;
struct DuelEffectChannel;
typedef void (*TextBoxStateCallback)(struct DuelEffectChannel *);
struct DisplayObject;
typedef struct DuelEffectChannel {
    u8 *text_00;
     










    u8 field_04;
    u8 field_05;
    u8 field_06;
    u8 field_07;
    u8 field_08;
    u8 field_09;
    u8 field_0A;
    u8 pad_0B;
    u16 field_0C;
    u16 field_0E;
     



    u8 field_10;
    u8 field_11;
    u8 pad_12;
    u8 field_13;
    u8 field_14;
    u8 field_15;
    u8 pad_16[10];
    DuelEffectEntry *entry_end_20;
    DuelEffectEntry *entry_head_24;
     



    struct DisplayObject *field_28;
     



    struct DisplayObject *field_2C;
    struct DisplayObject *field_30;
    u16 flags_34;
    u16 field_36;
    u16 field_38;
    u16 field_3A;
    s16 field_3C;
    s16 field_3E;
    s16 field_40;
    s16 field_42;
     

    u8 text_44[0x0D];
     

    u8 state_51;
     

    u8 delay_52;
    u8 field_53;
    u8 field_54;
    u8 pad_55;
    u8 field_56;
    u8 index_57;
     

    s8 stream_58;
    u8 field_59;
    u8 field_5A;
    u8 field_5B;
    u16 range_start_5C;
    u16 range_count_5E;
    u8 field_60;
    u8 field_61;
     


    u8 field_62;
    u8 pad_63;
} DuelEffectChannel;
extern DuelEffectEntry D_800EB288[620 ];
extern volatile s32 D_8009B350;
s32 func_80037C74(DuelEffectChannel *object);
extern u16 D_8009B398 __attribute__((section(".data")));
extern u16 D_8009B3A4 __attribute__((section(".data")));
extern u8 D_8009B357;
void func_800373C8(DuelEffectChannel *channel, u8 a1, u8 a2);
void func_80035CA8(s32 value);
void func_80035DB8(s32 value);
extern u16 D_801B0000[];
extern u16 D_801C0000[];
extern u16 D_801D5800[];
extern u32 D_801D9000[];
struct DisplayObject;
void func_8004036C(void *object);
struct DuelEffectChannel;
void func_800393B0(struct DuelEffectChannel *object);
extern s16 D_8009B35A;
void func_800391E4(struct DuelEffectChannel *record);
void func_80036C14(DuelEffectChannel *channel, s32 tagged_value);
extern 
s8 *func_80039E9C(void);
extern ScriptCommandHandler D_80090C50[];
extern u16 D_8009B27C __attribute__((section(".data")));
struct DisplayObject;
extern TextBoxStateCallback D_80090E64[];
extern void (*D_8009B340)(volatile DuelEffectChannel *object);
extern void (*D_80090F18[])(u8 *);
extern volatile u16 D_8009B33A;
void func_800393B0(DuelEffectChannel *object)
{
    u16 flags;
    s32 id;
    u8 *text;
    u8 **slot;
    u8 *script;
    DuelEffectEntry *entry;
    s32 op;
    void (**handlers)(u8 *);

    flags = object->flags_34;
    if ((flags & 0x4000 ) == 0) {
        flags |= 0x4000 ;
        object->flags_34 = flags;
        if ((flags & 2) == 0) {
            func_80039E9C();
        }
        if ((object->flags_34 & 0x100) != 0) {
            object->field_5B = 8;
            object->field_5A = 8;
        }
        id = object->field_36;
        D_8009B357 = 0;
        D_8009B340 = 0;
        object->delay_52 = 1;
        object->field_60 = 0;
        object->stream_58 = 0;
        if (id > 0xCFFF) {
            text = (u8 *)(((u32)D_801C0000 & 0xFFFF0000 ) +
                D_801C0000[id - 0xD000]);
        } else if (id > (0x8000  - 1)) {
            text = (u8 *)(((u32)D_801D5800 & 0xFFFF0000 ) +
                D_801D5800[id - 0x8000 ]);
        } else {
            if (id >= 0x500) {
                id -= 0x100;
            }
            text = (u8 *)(((u32)D_801B0000 & 0xFFFF0000 ) +
                D_801C0000[id]);
        }
        object->text_00 = text;
        object->field_56 = 0;
        object->state_51 = 0;
        func_8004036C(object->field_30);
        func_8004036C(object->field_2C);
        object->field_30 = (void *)0;
        object->field_2C = 0;
        func_800391E4(object);
        if ((object->flags_34 & 0x40) == 0) {
            entry = &D_800EB288[object->range_start_5C];
            object->entry_head_24 = entry;
            object->entry_end_20 = entry;
            func_80035CA8(object->index_57);
            func_80035DB8(object->index_57);
        }
        return;
    }

    if (D_8009B357 != 0) {
        D_80090C50[*(u8 *)&D_8009B27C]();
        if (D_8009B27C == 0) {
            D_8009B357 = 0;
        }
    }
    if (object->state_51 != 0) {
        D_80090E64[object->state_51 & 0x1F ](object);
        object->flags_34 = object->flags_34 & 0xFBFF;
        return;
    }
    if ((object->flags_34 & 0x1C00) == 0) {
        if ((D_8009B3A4 & 0x80 ) ||
            (D_8009B398 & (0x40  | 0x80 ) )) {
            func_800373C8(object, 0, 0);
            object->delay_52 = 1;
            object->flags_34 = object->flags_34 | 0x400;
        }
        object->delay_52 = object->delay_52 - 1;
        if (object->delay_52 != 0) {
            return;
        }
    }
    handlers = D_80090F18;
    object->delay_52 = object->field_53;
next_opcode:
    slot = &((TextStreamOwner *)object)->streams[object->stream_58];
    script = *slot;
    D_8009B33A = script[0];
    op = (s16)D_8009B33A;
    *slot = script + 1;
    if (op >= 0xF0) {
        D_8009B350 = 0;
        handlers[(s16)D_8009B33A - 0xF0]((u8 *)object);
        if (D_8009B350 >= 0) {
            if (D_8009B350 == 1) {
                return;
            }
            goto next_opcode;
        }
    }
    if (func_80037C74(object) != 0) {
        object->state_51 = 4;
        return;
    }
    D_8009B35A = D_8009B33A;
    func_80036C14(object, D_801D9000[(s16)D_8009B33A] & 0x8FF0FFFF);
    object->field_60 = object->field_60 + 1;
    if (object->field_61 != 0 && object->field_60 >= object->field_61) {
        object->flags_34 = object->flags_34 | 0x2000 ;
    }
    object->field_38 = object->field_38 + object->field_5A;
}
