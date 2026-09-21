/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_8001B938.c, profile gcc_2_8_1_g8_split.
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
    s16 id;
     

    s8 deck_index;
    u8 data_block_index;
    u8 flags_04;
    u8 unk_05;
} DuelDeckCardRecord;
u8 *func_800249E0(s32, s32);
extern u8 D_800907CC[];
typedef struct {
    void *object;
    void *data;
    u8 pad_08[4];
    s16 card_id;
    s16 attack;
    s16 defense;
    s16 stat_modifier;
    s16 terrain_modifier;
    u16 flags;
    u8 table_index;
    u8 pad_19[3];
} DuelCardRecord;
extern DuelCardRecord D_801A7AD8[];
union DuelSideLifePoints {
    u16 unsigned_value;
    s16 signed_value;
};
typedef struct {
    s8 result_adjustment;
    u8 turns_taken;
    u8 effective_attacks;
    u8 defensive_wins;
    u8 face_down_plays;
    u8 pure_magic_used;
    u8 traps_triggered;
    u8 field_07;
    u8 fusions_initiated;
    u8 equips_used;
    u8 field_0A;
    u8 field_0B;
    u8 field_0C;
} DuelRankStatistics;
typedef struct {
    DuelRankStatistics rank;
    u8 field_0D;
    s16 field_0E;
    s16 field_10;
     



    s16 displayed_life_points;
    union DuelSideLifePoints life_points;
    s16 max_life_points;
     

    s8 deck_draw_cursor;
    s8 swords_turns_remaining;
     


    s8 hand[5 ];
     

    s8 card_view_mode;
} DuelSideState;
extern u8 D_8009B1D5;
extern DuelSideState *D_8009B1C8;
typedef struct {
    s16 card_id;
    s16 attack;
    s16 defense;
    u16 flags;
    s8 card_type;
     

    s8 guardian_star;
    s8 guardian_star_2;
    u8 deck_index;
} AiActiveCard;
extern AiActiveCard D_801AB000[];
typedef struct {
    u8 pad_00[0x04];
    u32 attribute;
    u16 flags;
    u8 pad_0A[0x02];
    u32 color;
    void *field_10;
    u8 pad_14[0x0D];
    u8 field_21;
    u8 field_22;
    u8 pad_23[0x0D];
    s16 out_x;
    s16 out_y;
    s16 field_34;
    u8 pad_36[0x0C];
    u16 icon_variant;
    u8 pad_44[0x08];
    void *field_4C;
    u8 pad_50[0x0C];
    u8 icon_state;
    u8 field_5D;
    u8 pad_5E[0x09];
    u8 field_67;
    u8 field_68;
    u8 field_69;
    u8 card_index;
    u8 field_6B;
} DuelCardDisplayObject;
DuelCardDisplayObject *func_80018004(
    DuelCardRecord *card, s32 x, s32 y
);
typedef struct {
    u8 *object;
    u8 *child;
    u8 pad_08;
    u8 active_09;
    u8 pad_0A[2];
} DuelHandSlot;
extern DuelHandSlot D_800EA030[5 ];
void func_8004036C(void *object);
extern u8 D_800EAE88[];
void func_8001BAF0(void)
{
    s8 sel[5 ];
    DuelDeckCardRecord tmp;
    DuelDeckCardRecord *rec;
    DuelDeckCardRecord *other;
    DuelCardDisplayObject *spawned;
    DuelHandSlot *slot;
    DuelCardRecord *records;
    AiActiveCard *card;
    u8 *order;
    s32 i;
    s32 j;
    s32 v;
    s32 id;
    s32 k;

    for (i = 0; i < 5 ; i++) {
        sel[i] = D_8009B1C8->hand[i];
    }
    for (i = 0; i < 5 ; i++) {
        v = D_800EAE88[i];
        if (v == 0) {
            break;
        }
        if (v < 0x10) {
            sel[v - 0xB] = -1;
        }
    }
    for (i = 0; i < 5 ; i++) {
        v = D_800EAE88[i];
        if (v == 0) {
            return;
        }
        if (v >= 0x10) {
            do {
                j = 0;
                order = D_800907CC;
                records = D_801A7AD8;
                slot = D_800EA030;
            search:
                if (sel[j] >= 0) {
                    card = &D_801AB000[v];
                    rec = ((DuelDeckCardRecord *)((u8 *)D_801AB000 - 0x31E0))  + sel[j];
                    other = ((DuelDeckCardRecord *)((u8 *)D_801AB000 - 0x31E0))  +
                            card->deck_index;
                    v = rec->deck_index;
                    rec->deck_index = other->deck_index;
                    other->deck_index = v;
                    tmp = *rec;
                    *rec = *other;
                    *other = tmp;
                    k = D_8009B1D5 * 5 ;
                    id = *(u8 *)((j + k) + (s32)order);
                    spawned = (DuelCardDisplayObject *)slot->object;
                    func_800249E0(id, rec->deck_index);
                    slot->object = (u8 *)func_80018004(
                        (DuelCardRecord *)(id * 0x1C  +
                                           (s32)records),
                        spawned->out_x, spawned->out_y);
                    func_8004036C(spawned);
                    D_8009B1C8->hand[j] = rec->deck_index;
                    D_800EAE88[i] = j + 0xB;
                    sel[j] = -1;
                    continue;
                }
                j++;
                slot++;
                if (j < 5 ) {
                    goto search;
                }
            } while (0);
        }
    }
}
