/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_800218F0.c (DuelScene_UpdateResultRewards), profile gcc_2_8_1_g8_split.
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
extern u16 D_8009B23A;
typedef void (*DisplayObjectCallback)(u8 *);
typedef struct DisplayObject {
    s16 previous;                   
    s16 next;                       
    u32 attribute;                  
    u16 flags;                      
    u8 field_0A;                    
    u8 field_0B;                    
    u32 field_0C;                   
    u32 field_10;                   
     









    u16 field_14;                   
    s8 field_16;                    
     









    u8 ot_index;                    
    u16 field_18;                   
    u16 field_1A;                   
    u16 field_1C;                   
    s16 field_1E;                   
     



     




    union {
        u32 word;
        struct {
            u16 field_20;
            u8 field_22;
            u8 field_23;
        } h;
        struct {
            u8 field_20;
            u8 field_21;
            u8 field_22;
            u8 field_23;
        } b;
    } field_20;                     
    DisplayObjectCallback update;   
     



    union {
        struct {
            u16 field_28;
            u16 field_2A;
        } h;
        s32 word;
    } position;                     
     













    union {
        u32 word;
        struct {
            u16 field_2C;
            s16 field_2E;
        } h;
    } field_2C;                     
    union {
        struct {
            u16 field_30;
            u16 field_32;
        } h;
        s32 word;
    } field_30;                     
     











    union {
        u32 word;
        struct {
            s16 field_34;
            s16 field_36;
        } h;
    } field_34;                     
     






























    union {
        u32 word;
        struct {
            s16 field_38;
            s16 field_3A;
        } h;
    } field_38;                     
     

    union {
        s32 word;
        struct {
            u16 field_3C;
            u16 field_3E;
        } h;
    } field_3C;                     
     






    union {
        u32 word;
        struct {
            s16 field_40;
            s16 field_42;
        } h;
    } field_40;                     
     


























    union {
        u32 word;
        struct {
            s16 field_44;
            s16 field_46;
        } h;
    } field_44;                     
    union {
        u32 word;
        struct {
            s16 field_48;
            s16 field_4A;
        } h;
    } field_48;                     
     



















    s32 field_4C;                   
     

















     







    union {
        s32 word;
        struct {
            s16 field_50;
            s16 field_52;
        } h;
    } field_50;                     
    void *field_54;                 
     






    s16 field_58;                   
    s16 field_5A;                   
    u16 field_5C;                   
    u16 field_5E;                   
     







    s16 field_60;                   
    u8 pad_62[2];                   
     




    u8 field_64;                    
    u8 field_65;                    
    u8 field_66;                    
     


    u8 field_67;                    
     








    u8 field_68;                    
     


    u8 field_69;                    
     


    u8 field_6A;                    
     



    u8 field_6B;                    
    u8 field_6C;                    
    u8 pad_6D[0x70  - 0x6D];
} DisplayObject;
struct DisplayObject;
typedef union {
    struct {
        u16 wins;
        u16 losses;
    } result;
    u16 counts[2];
} SaveDataDuelistRecord;
typedef struct {
    u8 tint_r;
    u8 tint_g;
    u8 tint_b;
    u8 pad_03;
    u8 level;
    u8 target_level;
    u8 flags;
    u8 step;
    u16 field_08;
    u8 band_levels[30 ];
} FadeTransitionState;
typedef struct {
    u16 player_deck[40 ];
    u8 card_quantities[722 ];
    u8 pad_322[
        0x334  -
        (40  * sizeof(u16) + 722 )
    ];
    s32 duelist_code;
    u8 pad_338[0x3DE  -
        (0x334  + sizeof(s32))];
     

    u8 field_3DE;
    u8 pad_3DF[
        0x400  -
        (0x3DE  + sizeof(u8))
    ];
     

    s32 field_400;
    u32 save_sequence;
    u32 vblank_counter;
    u8 player_name_sjis[(6  * sizeof(u16)) ];
    u8 campaign_flags[
        (0x7FF  + 1) >> 3 
    ];
    u16 duel_wins;
    u16 duel_losses;
    SaveDataDuelistRecord duelist_records[(5  * 8 ) ];
    u8 pad_5BC[
        0x5DC  -
        (0x51C + sizeof(SaveDataDuelistRecord) * (5  * 8 ) )
    ];
    u8 campaign_scene_index;
    u8 field_5DD;
    u8 output_type;
    u8 pad_5DF;
    u32 starchips;
} SaveDataState;
extern SaveDataState *D_8009B1D8[2];
extern u16 D_8009B32E __attribute__((section(".data")));
extern u8 D_801D5708[];
extern s32 D_801D56A8[];
extern u8 D_801AF000[];
typedef struct  {
	short	m[3][3];	 
        long    t[3];		 
} MATRIX;
typedef struct {		 
	long	vx, vy;
	long	vz, pad;
} VECTOR;
typedef struct {		 
	short	vx, vy;
	short	vz, pad;
} SVECTOR;
typedef struct {
	VECTOR  scale;
	SVECTOR rotate;
	VECTOR  trans;
}       GsCOORD2PARAM;
typedef struct _GsCOORDINATE2 {
	unsigned long flg;
	MATRIX  coord;
	MATRIX  workm;
	GsCOORD2PARAM *param;
	struct _GsCOORDINATE2 *super;
	struct _GsCOORDINATE2 *sub;
}       GsCOORDINATE2;
typedef struct {
	long    vpx, vpy, vpz;
	long    vrx, vry, vrz;
	long    rz;
	GsCOORDINATE2 *super;
}       GsRVIEW2;
typedef struct {
    s16 field_00;
    s16 angle;
    s16 field_04;
    s16 field_06;
    s16 field_08;
    s16 field_0A;
    s16 field_0C;
    s16 projection;
    GsRVIEW2 view;
} ViewState;
extern ViewState D_800F2848;
void func_8001352C(void);
void func_8001352C(void);
extern s16 D_8009B146 __attribute__((section(".data")));
extern s16 D_8009B148 __attribute__((section(".data")));
typedef struct {
    DisplayObject *root;
    DisplayObject *children[10 ];
     


    s32 side_scores[2];
     

    u8 page_text_ids[3];
    u8 page_index;
    u8 rank_tier;
    u8 is_tec_rank;
    u8 starchip_prize;
    u8 pad_3B;
    s16 dropped_card_id;
    u8 pad_3E[2];
} DuelResultDisplayState;
extern DuelResultDisplayState *D_8009B1E8;
void func_800218F0(void);
void func_80021480(s32 page);
void func_80021598(void);
s32 func_80021810(s32 pool_index);
void func_80021894(s32 card_id);
extern DuelResultDisplayState D_801799D8;
extern u16 D_8009B16C;
extern s8 D_8009B360[2 ] __attribute__((section(".data")));
extern u8 D_8009B165;
extern s8 D_8009B361 __attribute__((section(".data")));
extern u8 D_8009B34E __attribute__((section(".data")));
extern u8 D_8009B355 __attribute__((section(".data")));
extern s16 D_8009B338 __attribute__((section(".data")));
extern u8 D_800E9EC8_arr[0x28 ];
void func_800156B8(s32);
void func_80015904(void);
void func_80015BD8(s32, s32);
void func_80015C84();
extern u16 D_8009B398 __attribute__((section(".data")));
extern u16 D_8009B394 __attribute__((section(".data")));
void func_8003FF08(u32);
void func_8003FEE0(u32);
void func_800428A8(
    DisplayObject *object,
    s32 arg1,
    s32 arg2,
    s32 arg3,
    s32 arg4,
    s32 arg5,
    s32 arg6,
    s32 arg7,
    void *resource
);
s32 func_800428EC(DisplayObject *object, s8 value);
void func_80042918(DisplayObject *object);
struct DisplayObject;
s32 func_8004002C(void);
void *func_800400AC(s32 index, s32 key);
void func_800404CC(
    void *object, s32 x, s32 y, s32 field_67, s32 field_68,
    s32 field_69, s32 color, s32 texture
);
struct DisplayObject;
void func_800218F0(void)
{
    DisplayObject *object;
    s32 score;
    s32 sound;
    s32 count;
    s32 offset;
    s32 x;
    s16 dropped_card;
    u16 value;
    s8 page;
    u8 opponent;

    D_800F2848.angle = (u16)D_800F2848.angle + 2;
    func_8001352C();
    if (!(D_8009B23A & 0x8000)) {
        D_8009B23A |= 0x8000;
        func_80015C84();
        func_80015BD8(128, 2);
        D_8009B1E8 = &D_801799D8;
        D_8009B148 = 0;
        D_8009B146 = 0;
        D_8009B34E = 0;
        D_8009B355 = 0;
        D_801D5708[0] = 4;
        D_801D5708[1] = 4;
        D_801D5708[D_8009B165] = 0;
        sound = 0x72E1;
        if (D_8009B165) {
            sound = 0x72F1;
            opponent = (u8)D_8009B361;
            D_8009B355 = 1;
            D_8009B32E = (s8)opponent - 31960;
        }
        func_8003FF08(sound);
        if (D_8009B360[0] < 0 && D_8009B361 < 0) {
            D_8009B34E = 1;
            D_8009B355 += 2;
        }
        D_8009B1E8->is_tec_rank = 0;
        func_80021598();
        score = D_8009B1E8->side_scores[D_8009B165];
        if (score < 50) {
            D_8009B1E8->is_tec_rank = 1;
            if (score < 0)
                score = 0;
            score = 99 - score;
        }
        if (score >= 100)
            score = 99;
        score -= 50;
        D_8009B1E8->rank_tier = score / 10;
        D_8009B1E8->page_index = 0;
        object = func_800400AC(func_8004002C(), 2);
        func_800404CC(object, 32, 16, 3, 1, 2, 11, 524);
        func_80042918(object);
        object->flags |= 0x28;
        object = func_800400AC(func_8004002C(), 2);
        func_800404CC(object, 288, 16, 3, 1, 0, 11, 524);
        func_80042918(object);
        count = 9;
        object->flags |= 0x28;
        object = func_800400AC(func_8004002C(), 2);
        func_800428A8(object, 0, 8, 0, 4, 0, 16, 8, D_801AF000);
        func_80042918(object);
        func_800428EC(object, -1);
        object->flags |= 0x20;
        D_8009B1E8->root = object;
        do {
            D_8009B1E8->children[count] = 0;
            count--;
        } while (count >= 0);
        D_8009B338 = 0;
        if (D_8009B360[0] < 0 && D_8009B361 >= 0) {
            if (D_8009B165)
                goto side_result;
            D_8009B1E8->starchip_prize = D_8009B1E8->rank_tier + 1;
            score = 2 * (D_8009B1E8->is_tec_rank != 0);
            if (D_8009B1E8->rank_tier < 3)
                score = 1;
            dropped_card = func_80021810(score);
            count = 0;
            D_8009B338 = dropped_card;
            D_8009B1E8->dropped_card_id = dropped_card;
            D_801D56A8[0] = dropped_card;
            offset = 8;
            if (D_8009B1E8->starchip_prize) {
                x = 160;
                do {
                    count++;
                    object = func_800400AC(func_8004002C(), 2);
                    func_800404CC(object, x, 192, 3, 4, 0, 11, 524);
                    func_80042918(object);
                    x += 20;
                    object->flags |= 0x20;
                    *(DisplayObject **)((u8 *)D_8009B1E8 + offset + 4) = object;
                    offset += 4;
                } while (count < D_8009B1E8->starchip_prize);
            }
        }
side_result:
        if (D_8009B360[D_8009B165] < 0) {
            object = func_800400AC(func_8004002C(), 2);
            func_800428A8(object, 0, 16, 0, 5, D_8009B1E8->is_tec_rank,
                16, 8, D_801AF000);
            func_80042918(object);
            func_800428EC(object, -2);
            object->flags |= 0x20;
            D_8009B1E8->children[0] = object;
            object = func_800400AC(func_8004002C(), 2);
            func_800428A8(object, 0, 16, 0, 6, D_8009B1E8->rank_tier,
                16, 8, D_801AF000);
            func_80042918(object);
            func_800428EC(object, -1);
            object->flags |= 0x20;
            D_8009B1E8->children[1] = object;
        }
        goto show_page;
    }
    if (D_8009B23A & 0x4000) {
        if (!(((FadeTransitionState *)D_800E9EC8_arr)->flags & 0x80)) {
            if (!(D_8009B23A & 0x2000)) {
                D_8009B23A |= 0x2000;
                func_80015904();
                ((FadeTransitionState *)D_800E9EC8_arr)->level = 255;
                func_800156B8(255);
            } else {
                 


                SaveDataState *save = D_8009B1D8[D_8009B165];
                D_8009B16C |= 0x2000;
                if (save) {
                    if (D_8009B360[0] < 0 && D_8009B361 >= 0) {
                        D_8009B1D8[0]->starchips +=
                            D_8009B1E8->starchip_prize;
                        if (D_8009B1D8[0]->starchips > 999999)
                            D_8009B1D8[0]->starchips = 999999;
                        func_80021894(D_8009B1E8->dropped_card_id);
                    } else {
                        value = D_8009B1D8[D_8009B165]->duel_wins + 1;
                        D_8009B1D8[D_8009B165]->duel_wins = value;
                        if (value >= 10000)
                            D_8009B1D8[D_8009B165]->duel_wins = 9999;
                        value = D_8009B1D8[D_8009B165 ^ 1]
                                    ->duel_losses + 1;
                        D_8009B1D8[D_8009B165 ^ 1]->duel_losses = value;
                        if (value >= 10000)
                            D_8009B1D8[D_8009B165 ^ 1]
                                ->duel_losses = 9999;
                    }
                }
            }
        }
    } else if (D_8009B394 & 0xA000) {
        D_8009B1E8->page_index++;
        if (D_8009B394 & 0x8000) {
            page = D_8009B1E8->page_index - 2;
            D_8009B1E8->page_index = page;
            if (page < 0)
                D_8009B1E8->page_index = 2;
        }
        if ((s8)D_8009B1E8->page_index >= 3)
            D_8009B1E8->page_index = 0;
        func_8003FEE0(6);
show_page:
        func_80021480((s8)D_8009B1E8->page_index);
    } else if (D_8009B398 & 0x40) {
        D_8009B23A |= 0x4000;
        func_80015BD8(0, 6);
        func_8003FEE0(0x30);
    }
}
