/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/ai_fusion.c (AiScript_FindBestCombo), profile gcc_2_8_1_g0_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
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
typedef struct {
    u8 enabled;
    u8 pad01[3];
    u8 *script_base;
    u8 *script_cursor;
    u8 *previous_cursor;
    u8 pad10[4];
    u8 return_depth;
    u8 pad15[3];
     


    u8 *return_stack[8 ];
    u8 combo_cards[6 ];
    u16 card_set[32 ];
    u8 type_set[25 ];
     



    u8 field_97;
     



    u16 attack_best_stat;
    s8 attack_best_slot;
    s8 attack_best_target;
    u8 fusion_count;
    u8 fusion_limit;
    u8 fusion_set;
    u8 pad9F;
    u16 fusion_best_stat;
    u8 fusion_depth;
    u8 fusion_best_depth;
    u8 fusion_path[6];
    u8 fusion_used[0x2A];
} AiScriptState;
extern AiScriptState D_800F5BE8;
extern s32 D_800F5B98[20 ];
extern AiActiveCard D_801AB000[];
s32 func_80070920(s32 mode, s32 index);
s8 func_80070710(void);
void func_800727C0(s32 card_id);
s32 func_8007058C(void);
void func_80072A48(void);
void func_800727C0(s32 arg0);
void func_80072A48(void)
{
    s32 depth;
    s32 sets;
    s32 dest;
    s32 n;
    s32 i;
    s32 slot;
    s32 card;
    u8 *e;
    s32 *table;

    table = D_800F5B98;
    depth = table[func_8007058C()];
    sets = table[func_8007058C()];
    depth = depth + 1;
    dest = func_8007058C();
    n = func_80070710();

    D_800F5BE8.fusion_count = n;
    D_800F5BE8.fusion_best_stat = 0;
    D_800F5BE8.fusion_depth = 0;
    D_800F5BE8.fusion_limit = depth;
    D_800F5BE8.fusion_set = sets;

    for (i = 0; i < D_800F5BE8.fusion_count; i++) {
        D_800F5BE8.fusion_used[i] = 0;
    }

    for (i = 0; i < 5 ; i++) {
        card = D_801AB000[i + 1 ].card_id;
        slot = i + 1;
        if (card == 0) {
            continue;
        }
        if (func_80070920(sets, slot) != 0) {
            continue;
        }
        D_800F5BE8.fusion_path[D_800F5BE8.fusion_depth] = slot;
        if (D_801AB000[i + 1 ].attack >
            D_800F5BE8.fusion_best_stat) {
            D_800F5BE8.fusion_best_stat =
                D_801AB000[i + 1 ].attack;
            D_800F5BE8.combo_cards[0] = slot;
            D_800F5BE8.combo_cards[1] = 0;
            D_800F5BE8.fusion_best_depth =
                D_800F5BE8.fusion_depth;
        }
        if (D_801AB000[i + 1 ].defense >
            D_800F5BE8.fusion_best_stat) {
            D_800F5BE8.fusion_best_stat =
                D_801AB000[i + 1 ].defense;
            D_800F5BE8.combo_cards[0] = slot;
            D_800F5BE8.combo_cards[1] = 0;
            D_800F5BE8.fusion_best_depth =
                D_800F5BE8.fusion_depth;
        }
        if (D_800F5BE8.fusion_limit >= 2) {
             



            e = (u8 *)&D_800F5BE8 + i;
            e[0xAA ] = 1;
            D_800F5BE8.fusion_depth =
                D_800F5BE8.fusion_depth + 1;
            func_800727C0(card);
            e[0xAA ] = 0;
            D_800F5BE8.fusion_depth =
                D_800F5BE8.fusion_depth - 1;
        }
    }

    for (i = 0; i < D_800F5BE8.fusion_count; i++) {
        card = D_801AB000[i + ((1  + 5 )  + 5 ) ].card_id;
        slot = i + ((1  + 5 )  + 5 ) ;
        if (card == 0) {
            continue;
        }
        if (func_80070920(sets, slot) != 0) {
            continue;
        }
        D_800F5BE8.fusion_path[D_800F5BE8.fusion_depth] = slot;
        if (D_801AB000[i + ((1  + 5 )  + 5 ) ].attack >
            D_800F5BE8.fusion_best_stat) {
            D_800F5BE8.fusion_best_stat =
                D_801AB000[i + ((1  + 5 )  + 5 ) ].attack;
            D_800F5BE8.combo_cards[0] = slot;
            D_800F5BE8.combo_cards[1] = 0;
            D_800F5BE8.fusion_best_depth =
                D_800F5BE8.fusion_depth;
        }
        if (D_801AB000[i + ((1  + 5 )  + 5 ) ].defense >
            D_800F5BE8.fusion_best_stat) {
            D_800F5BE8.fusion_best_stat =
                D_801AB000[i + ((1  + 5 )  + 5 ) ].defense;
            D_800F5BE8.combo_cards[0] = slot;
            D_800F5BE8.combo_cards[1] = 0;
            D_800F5BE8.fusion_best_depth =
                D_800F5BE8.fusion_depth;
        }
        if (D_800F5BE8.fusion_limit >= 3) {
             



            e = (u8 *)&D_800F5BE8 + i;
            e[0xAA ] = 1;
            D_800F5BE8.fusion_depth =
                D_800F5BE8.fusion_depth + 1;
            func_800727C0(card);
            e[0xAA ] = 0;
            D_800F5BE8.fusion_depth =
                D_800F5BE8.fusion_depth - 1;
        }
    }

    if (D_800F5BE8.combo_cards[0] != 0) {
        if (D_800F5BE8.combo_cards[0] >= 5  + 1) {
            D_800F5B98[dest] = 0;
        } else if (D_800F5BE8.combo_cards[1] != 0) {
            D_800F5B98[dest] = 1;
        } else {
            D_800F5B98[dest] = 2;
        }
    } else {
        D_800F5B98[dest] = 3;
    }
}
