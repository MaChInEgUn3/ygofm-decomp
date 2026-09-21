/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/duel_effect_command.c, profile gcc_2_8_1_g8_split.
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
extern u8 D_8009B320;
extern s16 D_8009B338;
void func_80036C14(DuelEffectChannel *channel, s32 tagged_value);
void func_80036C14(DuelEffectChannel *channel, s32 tagged_value);
extern s32 D_801D4244[];
extern u16 D_801B0000[];
extern u16 D_801C0000[];
extern u16 D_801D5800[];
void func_80037DA4(DuelEffectChannel *object);
struct DuelEffectChannel;
void func_80037DA4(DuelEffectChannel *object)
{
    s32 op;
    s32 id;
    s32 n;
    s32 kind;
    s32 stats;
    s32 type;
    u8 *text;
    u8 *current;
    u8 **slot;

    text = (u8 *)(s32)object->stream_58;
    object->field_62 = 0;
    text = (u8 *)((u32)text * 4);
    {
        u8 *stream = (u8 *)object;

        stream += (u32)text;
        text = stream;
        current = *(u8 **)text;
        op = *current++;
        *(u8 **)text = current;
    }
    n = 0;
    if (op & 0x10) {
        object->field_54 = D_8009B320;
        return;
    }
    if (op & 0x20) {
        id = D_8009B338 + 0x8000;
    } else if (op & 0x40) {
        id = D_8009B338 + 0xD100;
    } else {
        kind = op & 0xF;
        id = 0;
        switch (kind) {
        case 0:
            id = (D_801D4244[D_8009B338 - 1] >>
                  26 ) & 0x1F ;
            break;
        case 1:
            stats = D_801D4244[D_8009B338 - 1];
            id = (stats >> 22 ) &
                 0xF ;
            type = (stats >> 26 ) & 0x1F ;
            id += 0x17;
            if ((u32)(type - 20 ) < (23  - 20  + 1) ) {
                object->field_62 = type;
            }
            break;
        case 2:
            id = (D_801D4244[D_8009B338 - 1] >>
                  18 ) &
                 0xF ;
            id += 0x17;
            if (id == 0x17) {
                n = 1;
            }
            break;
        }
        if (!(op & 0x80)) {
            goto plain;
        }
        id += 0x8300;
    }
    object->stream_58++;
    n = id;
    if (id > 0xCFFF) {
        text = (u8 *)((u32)D_801C0000 & 0xFFFF0000) +
               D_801C0000[id - 0xD000];
    } else if (id > 0x7FFF) {
        text = (u8 *)((u32)D_801D5800 & 0xFFFF0000) +
               D_801D5800[id - 0x8000];
    } else {
        if (id >= 0x500) {
            n = id - 0x100;
        }
        text = (u8 *)((u32)D_801B0000 & 0xFFFF0000) + D_801C0000[n];
    }
store:
    slot = & ((TextStreamOwner *)( object )) ->streams[object->stream_58];
    *slot = text;
    return;
plain:
    object->flags_34 |= 0x80;
    if ((u8)n == 0) {
        func_80036C14(object, id);
    }
    object->flags_34 &= 0xFF7F;
    object->field_38 += 0x10;
}
