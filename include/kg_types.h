/* Types from krystalgamer/memories-decomp, as the ported units in src/
 * declare them (see each file's provenance header). Included ONLY by
 * those units: a non-ported unit never sees this file. Built by
 * tools_src/kg_decls.py fold-types from the units' own inline copies,
 * in first-seen order over the sorted file names, each definition once;
 * the six fixed-width names come from types.h, whose text is identical.
 * The layouts are his tree's and the build is the proof they did not
 * change on the way in. */
#ifndef KG_TYPES_H
#define KG_TYPES_H

#include "types.h"

typedef struct {
	short x, y;		 
	short w, h;		 
} RECT;
typedef struct {
	u32	tag;
	u32	code[15];
} DR_ENV;
typedef struct {
	RECT	clip;		 
	short	ofs[2];		 
	RECT	tw;		 
	u16 tpage;		 
	u8	dtd;		 
	u8	dfe;		 
	u8	isbg;		 
	u8	r0, g0, b0;	 
	DR_ENV	dr_env;		 
} DRAWENV;
typedef struct {
	RECT	disp;		 
	RECT	screen;		 
	u8	isinter;	 
	u8	isrgb24;	 
	u8	pad0, pad1;	 
} DISPENV;
typedef unsigned char PACKET;
typedef struct {
	unsigned p:24;
	unsigned char num:8;
}       GsOT_TAG;
typedef struct {
	unsigned long length;
	GsOT_TAG *org;
	unsigned long offset;
	unsigned long point;
	GsOT_TAG *tag;
}       GsOT;
typedef struct GraphicsFrameBuffer GraphicsFrameBuffer;
struct GraphicsFrameBuffer {
    u8 ordering_table_tags[0x5110];
    GsOT ordering_tables[4];
};
struct GraphicsFrameBuffer;
typedef void (*CdlCB)(u8,u8 *);
typedef struct FileTransferDescriptor FileTransferDescriptor;
typedef void (*FileTransferCallback)();
struct FileTransferDescriptor {
    s16 x;
    s16 y;
    s16 w;
    s16 h;
    u32 value_08;
    u32 value_0C;
     

    s32 total_bytes;
    s32 file_bytes;
    u8 *loader_argument;
     

    u32 phase_size;
    FileTransferCallback phase_callback;
    s32 absolute_lba;
    s32 phase_remaining;
    u32 status_flags;
     












    union {
        struct {
            u16 counter;
            u16 field_32;
        } h;
        u32 word;
    } field_30;
    s32 direct_destination;
    void *callback_data;
    u32 position;
    u32 result;
    u16 buffer_index;
    u8 done;
    u8 substate;
};
typedef struct {
	u8 minute;		 
	u8 second;		 
	u8 sector;		 
	u8 track;		 
} CdlLOC;
typedef void ( *DslCB )( u8, u8* );
typedef struct {
	u8 minute;		 
	u8 second;		 
	u8 sector;		 
	u8 track;		 
} DslLOC;
typedef struct {
    void *model;
    u8 pad_04[0x14];
    s8 field_18;
} DuelCardRenderHolder;
typedef struct {
    u8 b[8];
} Bytes8;
struct DisplayObject;
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
	u8	r, g, b, cd;
} CVECTOR;
typedef struct {
	unsigned	addr: 24;
	unsigned 	len:   8;
	u8		r0, g0, b0, code;
} P_TAG;
typedef struct {
	u32	tag;
	u8	r0, g0, b0, code;
	short	x0, 	y0;
	u8	u0, v0;	u16	clut;
	short	x1,	y1;
	u8	u1, v1;	u16	tpage;
	short	x2,	y2;
	u8	u2, v2;	u16	pad1;
	short	x3,	y3;
	u8	u3, v3;	u16	pad2;
} POLY_FT4;
typedef struct {
	u32	tag;
	u8	r0, g0, b0, code;
	short	x0, 	y0;
	u8	u0, v0;	u16	clut;
	u8	r1, g1, b1, p1;
	short	x1,	y1;
	u8	u1, v1;	u16	tpage;
	u8	r2, g2, b2, p2;
	short	x2,	y2;
	u8	u2, v2;	u16	pad2;
	u8	r3, g3, b3, p3;
	short	x3,	y3;
	u8	u3, v3;	u16	pad3;
} POLY_GT4;
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
typedef struct DuelEffectResourceRecord {
     


    void *object_00;
    void *object_04;
    RECT rects[4];
    u16 src_x;
    u16 src_y;
    u16 field_2C;
    u16 field_2E;
     




    u16 field_30;
     









    s16 field_32;
    s16 field_34;
    s16 field_36;
    s16 field_38;
    u8 field_3A;
    u8 field_3B;
    u8 field_3C;
    u8 pad_3D[3];
} DuelEffectResourceRecord;
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
typedef struct {
    char pad_00[0x22];
    u8 flag;
    char pad_23[0x45];
    u8 type;
} CardObject;
typedef struct {
    s16 field_00;    
    s16 field_02;    
    s16 field_04;    
    u8 pad_06[2];    
    s32 field_08;    
    s32 field_0C;    
    s16 field_10;    
    s16 field_12;    
    void *buffer;    
    s16 id;          
    s16 field_1A;    
    u8 flags;        
    u8 field_1D;     
} DuelEffectRequest;
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
typedef struct {
    u8 pad_0000[0x36B4];
    DuelCardRecord record;
} DuelCardReplayRecordBlock;
typedef struct DuelFieldEffectObject DuelFieldEffectObject;
struct DuelFieldEffectObject {
    s16 x;
    s16 y;
    u8 pad_04[0x16];
    s16 field_1A;
    u8 flags;
    u8 count;
    u8 pad_1E[4];
    u8 timer;
    u8 pad_23;
    void (*callback)(DuelFieldEffectObject *);
    u8 pad_28[0x3F];
    u8 mark;
    u8 pad_68[2];
    u8 index;
    u8 pad_6B;
    u8 active;
};
typedef struct {
    s16 id;
     

    s8 deck_index;
    u8 data_block_index;
    u8 flags_04;
    u8 unk_05;
} DuelDeckCardRecord;
typedef struct {
    u8 *object;
    u8 *child;
    u8 pad_08;
    u8 active_09;
    u8 pad_0A[2];
} DuelHandSlot;
typedef struct {
    u8 pad_00[0x0C];
    s16 field_0C;
    u8 pad_0E;
    s8 col;
    s8 row;
    u8 field_11;
    u8 field_12;
    u8 field_13;
    u8 pad_14[4];
    u8 field_18;
    u8 status;
} DuelCardPickCursor;
typedef struct {
    u8 pad_00[8];
    DuelHandSlot *hand;
} DuelSelectionSideView;
typedef struct {
    u32 field_00;
     


    struct DisplayObject *cursor_object;
    DuelHandSlot *hand;
     
    s16 field_0C;
     



    u8 field_0E;
     

    s8 col;
    s8 row;
    u8 field_11;
    u8 field_12;
    u8 field_13;
    u8 field_14;
     

    u8 field_15;
    u8 pad_16;
    u8 field_17;
    u8 field_18;
     
    u8 status;
    u8 pad_1A[2];
} DuelSelectionRecord;
typedef struct {
    u8 work_slot;
    u8 biased_x;
    u8 biased_y;
} DuelExodiaCardPose;
typedef struct {
    DuelExodiaCardPose poses[5 ];
    u8 padding;
} DuelExodiaCardPoseTable;
typedef struct {
    u16 x;              
    u16 y;              
    u16 field_04;       
    u8 pad_06[0xC];     
    s16 field_12;       
    s32 field_14;       
    u8 pad_18[2];       
    s16 field_1A;       
} DuelEffectObject;
typedef struct {
    u8 pad_00[0x08];
    u16 flags;
    u8 pad_0A[0x0E];
    s16 half_height;
    s16 half_width;
    u8 pad_1C[0x14];
    s16 x;
    s16 y;
    u8 pad_34[0x08];
    s16 height;
    s16 width;
    s16 field_40;
    s16 field_42;
    u8 pad_44[0x04];
    s16 half_height_2;
    s16 half_width_2;
    u8 pad_4C[0x10];
    u8 field_5C;
    u8 field_5D;
    u8 pad_5E[0x08];
    u8 field_66;
} DisplayObjectConfigView;
typedef struct {
    u8 pad_00[0x30];
    s16 x;
    s16 y;
    s16 z;
    s16 velocity_x;
    s16 velocity_y;
    s16 velocity_z;
    u8 pad_3C[0x26];
    u8 fraction_x;
    u8 fraction_y;
    u8 fraction_z;
} DisplayObjectVelocity;
typedef struct {
    u8 pad_00[0x30];
    u16 field_30;
    u16 field_32;
    u8 pad_34[2];
    u16 field_36;
    u16 field_38;
} DisplayObjectSnapshot;
typedef struct {
    u8 pad_00[0x30];
    s16 out_x;
    s16 out_y;
    u8 pad_34[0x02];
    s16 x;
    s16 y;
} DisplayObjectPosition;
typedef struct DisplayLinkEntry {
    DisplayObject *object;
    DisplayObject *field_04;
    u8 pad_08[4];
} DisplayLinkEntry;
typedef struct {
    DisplayObject *field_00;
    DisplayObject *object;
    DisplayLinkEntry *entries;
    s16 field_0C;
    u8 pad_0E[1];
    s8 x;
    s8 y;
    u8 pad_11[2];
    u8 field_13;
    u8 field_14;
    u8 pad_15[1];
    s8 field_16;
    u8 table_index;
    u8 field_18;
} DuelFieldDisplaySource;
typedef struct {
    u8 pad_00000[0x4B6B4];
    DuelCardRecord field_cards[30 ];
    DuelDeckCardRecord cards[(40  * 2) ];
} DuelCardStagingDeckView;
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
struct DuelEffectChannel;
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
typedef struct {
    s16 value;
} DuelPlacementCardIdCell;
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
    u8 pad_00[8];
    u16 flags;                   
    u8 pad_0A[2];
    u32 color;                   
    u8 pad_10[6];
    u8 depth;                    
    u8 pad_17[0xA];
    u8 face;                     
    u8 pad_22[2];
    void (*update)();            
    union { struct { s16 x, y; } xy; s32 word; } target;   
    union { struct { u16 x, y; } xy; s32 word; } saved;    
    union { struct { u16 x, y; } xy; s32 word; } pos;      
    u8 pad_34[2];
    u16 home_x;                  
    u16 home_y;                  
    u8 pad_3A[0x22];
    u8 icon_state;               
    u8 pad_5D[3];
    s16 step;                    
    u8 pad_62[6];
    u8 kind;                     
    u8 pad_69;
    u8 card_index;               
    u8 pad_6B;
    u8 field_6C;                 
} HandCardObject;
typedef struct {
    u8 pad_00[0xF];
    s8 col;
    s8 row;
} DuelFieldCursor;
typedef struct {
    u8 pad_00[4];
    struct DisplayObject *position_object;
    u8 pad_08[6];
    s8 slot_index;
    u8 pad_0F[6];
    u8 count;
    u8 pad_16[2];
} DuelHandStackState;
typedef struct {
    u8 pad_00[2 * 0x1C ];
    DuelCardPickCursor field;
    u8 pad_52[(4  * 0x1C )  - 2 * 0x1C  -
              sizeof(DuelCardPickCursor)];
} DuelSelectionSideCursors;
typedef struct {
    u8 pad_00[0x19];
    u8 status;
} DuelCursorStatus;
typedef struct {
    DuelSelectionRecord records[4 ];
} DuelSelectionSide;
typedef struct {
    s16 model_id;
    s16 field_02;
    s16 field_04;
    u8 field_06;
    u8 field_07;
} AnimatedBattleModelProperties;
typedef struct {
    u8 x;
    u8 y;
    u8 kind;
    u8 tag;
} DuelResultSpriteSpec;
typedef struct {
    DisplayObject *object;
    u8 pad_04[0xC - 4];
} DuelResultSpriteSlot;
typedef struct {
    u32 lo;
    u32 hi;
} Pair;
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
typedef union {
    struct {
        s32 attack;
        s32 defense;
        s32 rank;
    } card_stats;
    struct {
        s32 card_id;
        s32 count;
    } card;
    struct {
        s32 chest;
        s32 deck;
    } build_deck;
    struct {
        s32 used;
        s32 needed;
    } blocks;
    struct {
        s32 field_00[16];
        s32 invalid_side;
    } deck_validation;
    s32 library_count;
     
    s32 starchips;
    s32 rank_rows[16][2 ];
    Pair pair;
} TextStagingValues;
typedef union {
    struct {
        u16 wins;
        u16 losses;
    } result;
    u16 counts[2];
} SaveDataDuelistRecord;
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
typedef struct {
    u8 pad_00[8];
    u16 flags;
    u8 pad_0A[0x5D];
    u8 field_67;
    u8 field_68;
    u8 field_69;
} DisplayObjectConfig;
typedef struct DisplayParent {
    DisplayObject *position_base;
    DisplayObject *base;
    DisplayLinkEntry *entries;
    u8 pad_0C[0xB];
    u8 index;
} DisplayParent;
typedef struct {
    u8 pad_00[0x08];
    u16 flags;
    u8 pad_0A[0x16];
    union {
        s32 packed;
        u8 channel[4];
    } tint;
    s32 field_24;
    u16 angle_step;
    union {
        u16 unsigned_value;
        s16 signed_value;
    } angle;
    u8 pad_2C[0x02];
    s16 mode;
    u8 pad_30[0x30];
    u16 counter;
    u8 pad_62[0x08];
    u8 record_index;
    u8 pad_6B[0x01];
    u8 phase;
} DuelCardTurnObject;
typedef struct {
    s16 x;
    s16 y;
} DuelFieldPosition;
typedef struct {
    u8 pad00[0x28];
    s16 x;
    s16 y;
    s16 target_x;
    s16 target_y;
    u8 pad30[6];
    u16 step_x;
    u8 pad38[2];
    u16 step_y;
    u8 pad3C[0x24];
    u16 steps;
    u8 pad62[0xA];
    u8 moving;
} DuelFieldCursorObject;
typedef struct {
    u8 pad00[4];
    DuelFieldCursorObject *object;
    u8 pad08[7];
    s8 col;
    s8 row;
    s8 min_row;
    s8 max_row;
    u8 pad13[5];
    u8 page;
    u8 flags;
} GridCursor;
typedef struct DuelRitualResult {
    void *tribute_objects[3 ];
    s32 field_0C;
} DuelRitualResult;
typedef union {
    DisplayObject *slots[5 ];
    struct {
        DisplayObject *effects[2];
        DuelRitualResult result;
    } ritual;
} DisplayObjectRitualWorkArea;
struct DuelRitualResult;
typedef struct {
    s8 result;       
    s8 field1;       
     

    s8 field_02;     
    char pad_03[3];  
    s8 value;        
    s8 zero;         
    s8 random;       
    s8 field_09;     
    s8 field_0A;     
    s8 field_0B;     
} AiSelection;
typedef struct {
    char pad[0x6A];
    u8 index;
} DuelSelectionObject;
typedef struct {
    DuelSelectionObject *ptr;
} DuelSelectionSource;
struct ProjectionOut {
    s16 f0;
    s16 f2;
    s32 f4;
};
typedef union {
    s32 word;
    struct {
        u16 x;
        u16 y;
    } h;
} SpritePos;
typedef union {
    u16 word;
    struct {
        u8 lo;
        u8 hi;
    } b;
} SpriteHalf;
typedef struct {
    u32 attribute;
    SpritePos xy;
    union {
        u32 word;
        struct {
            SpriteHalf w;
            u16 h;
        } wh;
    } extent;
    u16 tpage;
    SpriteHalf uv;
    union {
        u32 word;
        struct {
            u16 cx;
            u16 cy;
        } h;
    } cxcy;
    u32 rgb;
    SpritePos mxmy;
    u32 scale;
    s32 rotate;
} SpritePrim;
typedef struct {
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    u8 field_4;
    u8 field_5;
    u8 field_6;
    u8 field_7;
    u16 field_8;
    u8 field_A;
    u8 field_B;
} Func80028B08Ctx;
typedef struct {
    u32 field_0;
    u32 field_4;
} Func80028B08Extra;
typedef struct {
	u32	tag;
	u8	r0, g0, b0, code;
	short	x0, 	y0;
	u8	r1, g1, b1, p1;
	short	x1,	y1;
	u8	r2, g2, b2, p2;
	short	x2,	y2;
	u32	pad;
} LINE_G3;
typedef struct {
    u8 pad_00[8];
    s16 x;
    s16 y;
    u16 x_fraction;
    u16 y_fraction;
    s16 globe_radius;
    u16 rest_x;
    u16 rest_y;
    u8 frames;
    u8 active;
    s32 velocity_x;
    s32 velocity_y;
    u8 pad_20[4];
     



    struct DisplayObject *slots[8];
    struct DisplayObject *render;
} LibraryMotionState;
typedef struct {
	unsigned long attribute;
	short   x, y;
	unsigned short w, h;
	unsigned short tpage;
	unsigned char u, v;
	short   cx, cy;
	unsigned char r, g, b;
	short   mx, my;
	short   scalex, scaley;
	long    rotate;
}       GsSPRITE;
typedef struct {
	unsigned long attribute;
	short   x0, y0;
	short   x1, y1;
	unsigned char r0, g0, b0;
	unsigned char r1, g1, b1;
}       GsGLINE;
typedef struct {
    s32 values[4];
} LibraryViewQuad;
typedef struct {
     


























    s32 grid[4][3];
    s8 field_30;
     


    u8 field_31;
    u8 field_32;
    u8 display_effect_step;
    u16 field_34;
     




    u16 field_36;
    u8 pad_38[2];
    u8 field_3A;
    u8 field_3B;
     



    u8 field_3C;
    u8 pad_3D;
     



    u16 field_3E;
     




















    s16 field_40;
    s16 field_42;
    s16 field_44;
    s16 field_46;
    s16 field_48;
    s16 field_4A;
} MenuRecord;
typedef struct {
    s32 unk00;
    s16 unk04;
    s16 unk06;
    s32 unk08;
    s32 unk0C;
    s32 unk10;
} SceneScriptSlot;
enum { FRONTEND_DEBUG_ROW_COUNT = 3 };
typedef s8 FrontendDebugColumns[FRONTEND_DEBUG_ROW_COUNT];
typedef u8 FrontendDebugDigitCounts[FRONTEND_DEBUG_ROW_COUNT];
typedef union {
    u8 *bytes;
    u16 *words;
} FrontendDebugRowPointer;
typedef struct {
    u8 pad_00[4];
    u16 id;
    u8 pad_06[7];
    u8 flags;
    u8 pad_0E[2];
} CardEntry;
typedef struct CardList {
    CardEntry entries[(722  + 1) ];
    u8 pad_2D30[4];
     





    struct DisplayObject *cursor_box;
    struct DisplayObject *scroll_box;
    s16 first;
     



    s16 first_target;
     














    s16 row_count;
    s16 sort_row_count;
    u8 pad_2D44;
     


    u8 sort_mode;
     

    s8 sort_choice;
    u8 kind;
     




    s8 cursor;
} CardList;
typedef struct BuildDeckTransitionState {
    u16 *deck_cards;
    CardList lists[2];
    s32 chest_total;
    s32 deck_total;
    s32 viewport_target_x;
    s32 viewport_step_x;
    s32 transition_ticks;
    u8 pad_5AB0[0x14];
    u8 deck_card_quantities[(722  + 1) ];
    u8 chest_card_quantities[(722  + 1) ];
    u8 card_sort_rank[(722  + 1)  + 1];
    u16 state;
    u16 next_state;
    u8 pane_index;
    u8 pad_6343;
} BuildDeckTransitionState;
typedef unsigned int size_t;
typedef struct {
    u32 key;
    s16 card_id;
    u8 pad_06[7];
    u8 field_0D;
    u8 pad_0E[2];
} CardListSortItem;
typedef struct {
	u32	tag;
	u8	r0, g0, b0, code;
	short	x0, 	y0;
	u8	u0, v0;	u16	clut;
	u8	r1, g1, b1, p1;
	short	x1,	y1;
	u8	u1, v1;	u16	tpage;
	u8	r2, g2, b2, p2;
	short	x2,	y2;
	u8	u2, v2;	u16	pad2;
} POLY_GT3;
typedef struct {
	u32	tag;
	u8	r0, g0, b0, code;
	short	x0, 	y0;
	u8	r1, g1, b1, p1;
	short	x1,	y1;
	u8	r2, g2, b2, p2;
	short	x2,	y2;
	u8	r3, g3, b3, p3;
	short	x3,	y3;
	u32	pad;
} LINE_G4;
typedef struct {
	unsigned long	*primp;
	GsOT		*tagp;
	int		shift;
	int		offset;
	PACKET		*out_packetp;
	unsigned long	*primtop;
	SVECTOR		*vertop;
	SVECTOR		*nortop;
}	GsARGUNIT_NORMAL;
typedef struct {
     


    s16 packed;
     
    s16 distance;
     

    s16 append_index;
     

    s16 sorted_position;
} SortedEntry;
typedef struct {
	u32	tag;
	u8	r0, g0, b0, code;
	short	x0, 	y0;
	u8	r1, g1, b1, p1;
	short	x1,	y1;
} LINE_G2;
typedef struct {
    u8 *streams[22 ];
    s8 stream_index;
} TextStreamOwner;
typedef struct {
    u8 *streams[20];
    u8 unk50;
    u8 state;
    u8 pad52[6];
    s8 depth;
} EffectObject;
typedef struct {
    u8 pad_00[0x31];
    u8 field_31;
    u8 field_32;
    u8 state;
    u16 field_34;
    u16 field_36;
    u8 pad_38[0x06];
    u16 field_3E;
} DisplayEffectState;
typedef void (*ScriptCommandHandler)(void);
typedef void (*TextBoxStateCallback)(struct DuelEffectChannel *);
typedef struct {
    void *obj;
    u16 flags;
} ChoiceView;
typedef struct {
    ChoiceView choice;
    u8 pad_08[sizeof(DuelEffectChannel) - sizeof(ChoiceView)];
} ChoiceChannelCursor;
typedef struct {
    u16 lo;
    u16 hi;
} TblEnt;
typedef struct {
    u8 pad_00[0x30];
    s8 field_30;
    u8 field_31;
    u8 field_32;
    u8 state;
    u16 field_34;
    u16 field_36;
    u8 pad_38[0x04];
    u8 field_3C;
    u8 pad_3D;
    u16 field_3E;
} DisplayEffectVramState;
typedef struct {
    u8 image[0x18000];
    u8 clut[0x400];
    u8 extra[0x800];
    RECT image_rect;
    RECT clut_rect;
} DisplayEffectVramSlot;
struct DIRENTRY {
	char name[20];
	long attr;
	long size;
	struct DIRENTRY *next;
	long head;
	char system[4];
};
typedef struct {
    u8 *cursor;
    u8 pad_04[8];
    u8 free_blocks;
    u8 entry_index;
    u8 pad_0E[0x25A];
} MemCardWorkSlot;
typedef struct {
    u8 pad_00[0x10];
    u8 blocks;
    u8 pad_11;
    s16 remaining;
    u16 offset;
    s16 chunk;
    u16 field_18;
    u8 text_index;
    u8 pad_1B;
} MemCardWorkRoot;
typedef struct {
    MemCardWorkRoot root;
    MemCardWorkSlot slots[2 ];
} MemCardWorkArea;
typedef struct {
    u32 unk0;
    u32 flag;
    u8 pad8[0x18];
    u8 out[4];
} ClipState;
typedef struct {		 
	short vx, vy;
} DVECTOR;
typedef struct {
	SVECTOR v;
	u8 uv[2]; u16 pad;	 
	CVECTOR c;
	DVECTOR sxy;
	u32  sz;		 
} RVECTOR;
typedef struct {
	RVECTOR r01,r02,r31,r32,rc;
	RVECTOR	*r0,*r1,*r2,*r3;
	u32 *rtn;
} CRVECTOR4;
typedef struct {
	u32 	ndiv;		 
	u32 	pih,piv;	 
	u16 clut,tpage;
	CVECTOR	rgbc;
	u32	*ot;
	RVECTOR r0,r1,r2,r3;
	CRVECTOR4 cr[5];
} DIVPOLYGON4;
typedef struct {
	u32	tag;
	u8	r0, g0, b0, code;
	short	x0, 	y0;
	u8	r1, g1, b1, pad1;
	short	x1,	y1;
	u8	r2, g2, b2, pad2;
	short	x2,	y2;
	u8	r3, g3, b3, pad3;
	short	x3,	y3;
} POLY_G4;
typedef struct {
    s16 x;
    s16 y;
    s32 divisions;
} DisplayObjectPacketOrigin;
typedef struct {
    short left;	        
    short right;        
} SpuVolume;
typedef struct {
    unsigned long	voice;		 



    unsigned long	mask;		 
    SpuVolume		volume;		 
    SpuVolume		volmode;	 
    SpuVolume		volumex;	 
    unsigned short	pitch;		 
    unsigned short	note;		 
    unsigned short	sample_note;	 
    short		envx;		 
    unsigned long	addr;		 
    unsigned long	loop_addr;	 
    long		a_mode;		 
    long		s_mode;		 
    long		r_mode;		 
    unsigned short	ar;		 
    unsigned short	dr;		 
    unsigned short	sr;		 
    unsigned short	rr;		 
    unsigned short	sl;		 
    unsigned short	adsr1;		 
    unsigned short	adsr2;		 
} SpuVoiceAttr;
typedef struct {
    short cd_left  [0x200 ];
    short cd_right [0x200 ];
    short voice1   [0x200 ];
    short voice3   [0x200 ];
} SpuDecodedData;
typedef struct {
    u8 command;
    u8 field_0001;
    s16 field_0002;
    s32 field_0004;
    s32 field_0008;
    s32 field_000C;
    s32 field_0010;
    s32 field_0014;
    s32 field_0018;
    s32 field_001C;
    s32 field_0020;
    s32 field_0024;
    s32 field_0028;
    s32 field_002C;
} SDCommand;
typedef struct {
     
    u16 sector_offset;
    u8 pad_0002[2];
    u32 field_0004;
} SDValueLink;
typedef struct {
    u8 volume;
    u8 timer;
    u8 pad0002[2];
    u16 pitch;
    u16 field_0006;
} SDNote;
typedef union {
    u32 sum;
    s16 halves[2];
} SDLevelWord;
typedef struct {
    u16 field_0000;
    u16 field_0002;
    u16 field_0004;
    u8 pad0006[0x36];
    u32 field_003C;
    u16 flags_0040;
    u16 mix_scale;
    u16 field_0044;
    u8 pad0046[2];
    u8 output_type;
    u8 field_0049;
    u8 flags_004A;
    u8 pad004B;
    s16 command_count;
    u16 field_004E;
    u32 field_0050;
    u32 field_0054;
    u32 field_0058;
    u32 field_005C[8];
    u8 field_007C;
    u8 field_007D;
    u8 field_007E;
    u8 pad007F;
     


















    union {
        SDCommand c[16 ];
        u8 b[16  * 0x30];
    } commands;
    u8 pad0380[4];
     







    SpuVoiceAttr voice_attr;
    s32 field_03C4;
    s32 field_03C8;
    u16 field_03CC;
    u16 field_03CE;
    u8 pad03D0[0x34];
    u16 voice_ids[4 ];
    u8 field_040C[4 ];
    u8 voice_flags[4 ];
    u16 voice_volume_left[4 ];
    u16 voice_volume_right[4 ];
    u8 voice_value[4 ];
    u8 voice_step[4 ];
    u16 voice_timer[4 ];
    u8 voice_active_mask;
    u8 field_0435;
    u8 pad0436[2];
    u32 field_0438;
    u16 *field_043C;
    u16 field_0440;
    u16 field_0442;
    SDNote *field_0444;
    SDValueLink *field_0448;
    u16 field_044C[2 ][32 ];
    s32 field_04CC;
    u8 pad04D0[0x510 - ((0x44C  + 2  * (1 << 6 ) )  + 4)];
    s16 cd_volume;
    s16 field_0512;
    u8 channel_volume[2];
    u8 pad0516[2];
     


    u8 *bank_0518[3];
    u8 pad0524[4];
    u32 field_0528;
    u32 field_052C;
    u8 field_0530;
    u8 field_0531;
    u8 field_0532;
    u8 mix_multiplier;
    u16 field_0534;
    u8 pad0536[2];
    s32 decoded_half;
    u8 buffer_053C[4][0x200];
    u8 pad0D3C[0x800];
    u8 *buffer_ptrs_153C[4];
    SDLevelWord output_level;
    SDLevelWord field_1550;
    u8 pad1554[0xC];
    u8 *field_1560;
    u16 *music_track;
    u8 pad1568[0x10];
    s16 field_1578;
    s16 field_157A;
     
    s16 field_157C;
    s16 field_157E;
    s16 field_1580;
    s16 field_1582;
    u8 field_1584;
    u8 pad1585;
    s16 field_1586;
    s16 field_1588;
    u8 field_158A;
    u8 pad158B[0x4D];
    u8 field_15D8[0x14];
    u8 field_15EC;
    u8 field_15ED;
    u8 field_15EE;
    u8 field_15EF;
    u8 pad15F0[4];
    s16 field_15F4;
    u8 pad15F6[0x22];
    u8 busy;
     



    u8 field_1619[0x10];
    u8 field_1629[0x10];
    u8 field_1639[0x10];
     

    u8 field_1649;
    u8 field_164A;
    u8 field_164B;
} SDValue;
typedef struct {
    u32 a;
    u32 b;
} SoundCommandPair;
typedef struct {
    s32 field_00;
    s32 field_04;
    u8 pad_08[4];
    s32 field_0C;
    s32 field_10;
    s32 field_14;
    s32 field_18;
    s16 field_1C;
    u8 field_1E;
    u8 field_1F;
} FileRequestSlot;
typedef struct {
    s32 form;
    s32 version;
    s32 id;
    u32 file_size;
    u16 reserved_10;
    u16 program_count;
    u16 tone_count;
    u16 vag_count;
    u8 master_volume;
    u8 pan;
    u8 attribute_1;
    u8 attribute_2;
    u32 reserved_1C;
} SDVabHeader;
typedef struct {
    u8 pad_0000[0x0C];
    s32 spu_address;
    u8 pad_0010[0x40];
    u8 vab_header[1];
} SDMusicPackage;
typedef struct {
    s32 count;
    u8 pad0004[4];
    u16 keys[((0x1A0  - 0x08 ) / 2 ) ];
    SDNote data[((0x1A0  - 0x08 ) / 2 ) ];
} SDSeqBlock;
typedef struct {
    u16 field_00;
    u16 count;
    u8 field_04[8];
    s32 payload_size;
    u16 index_records[16][2];
} CommandIndexTable;
typedef struct {
    u32 words[8];
} SDCommandTail;
typedef unsigned long long u64;
typedef union {
    u64 all;
    struct { s32 original; s32 copy; } words;
} SDSEPlayIdPair;
typedef struct {
    unsigned long	mask;	   

    long		mode;	   
    SpuVolume		depth;	   
    long                delay;	   
    long                feedback;  
} SpuReverbAttr;
typedef struct {
    u8 program;
    u8 pan;
    u8 pad0002;
    u8 volume;
    u8 field_0004;
    u8 expression;
    u8 field_0006;
    u8 pitch_bend_msb;
    s32 field_0008;
    s32 field_000C;
    u8 field_0010;
    u8 parameter_selector;
    u8 control_mode;
    u8 control_value;
    s16 field_0014;
    u8 pad0016[2];
} SDSecondaryRecord;
typedef struct {
    u8 voice_index;
    u8 pad0001[2];
    u8 channel_index;
    u8 pad0004;
    u8 field_0005;
    u8 note;
    u8 pad0007;
    u8 field_0008;
    u8 field_0009;
    u8 field_000A;
    u8 field_000B;
     

    u8 pan;
    u8 field_000D;
    u8 field_000E;
    u8 field_000F;
    u8 pitch_bend_positive_scale;
    u8 pitch_bend_negative_scale;
    u8 field_0012;
    u8 field_0013;
     

    u16 level_left;
    u16 level_right;
    u8 pad0018[2];
    s16 cached_pitch_bend;
    s16 field_001C;
    u16 field_001E;
    u8 pad0020[8];
} SDSecondaryObject;
typedef struct {
    s16 field_0000;
    u8 pad0002[2];
    u8 *field_0004;
    s32 field_0008;
    s32 field_000C;
    s32 field_0010;
    u8 *field_0014;
    u8 field_0018;
    u8 field_0019;
    u8 field_001A;
    u8 field_001B;
} SDSecondaryTransfer;
typedef struct {
    s32 pos;
    s32 pos_saved;
    s32 chunk_length;
    s32 chunk_end;
    s32 chunk_start;
    u16 tempo_accumulator;
    u16 tempo_step;
    u16 field_0018;
    u16 field_0018_saved;
    u32 delta_remaining;
    u32 delta_remaining_saved;
    u8 ended;
    u8 ended_saved;
    u8 loop_count;
    u8 field_0027;
    u8 running_status_held;
    u8 running_status;
    u8 running_status_saved;
    u8 field_002B;
} SDSequenceTrack;
typedef struct {
    SDSecondaryRecord channels[16 ];
    SDSecondaryObject objects[20 ];
    u8 pad04A0[4];
    SDSecondaryTransfer transfer;
    SpuVoiceAttr voice_attr;
    u8 flag_0500;
    u8 flag_0501;
    u8 flag_0502;
    u8 event_guard;
    long event_handle;
    u8 field_0508;
    u8 field_0509;
    u8 pad050A[2];
    void (*field_050C)(void);
    s16 object_count;
    s16 field_0512;
    u16 field_0514;
    u16 field_0516;
    SDSequenceTrack tracks[16 ];
    u8 pad07D8[4];
    u8 *field_07DC;
    s16 field_07E0;
    s16 field_07E2;
    s16 field_07E4;
    s16 field_07E6;
    u8 *field_07E8;
    s32 field_07EC;
    s32 field_07F0;
    s32 field_07F4;
    u16 field_07F8;
    u16 track_count;
    u16 timebase;
    u8 pad07FE[2];
    u8 field_0800;
    u8 field_0801;
    u8 pad0802[2];
    s32 field_0804;
    s32 field_0808;
    s32 field_080C;
    s32 field_0810;
    u8 field_0814;
    u8 field_0815;
    u8 pad0816[2];
    u32 bytes_consumed;
    s32 field_081C;
    u8 pad0820[0x24];
    u8 field_0844;
    u8 field_0845;
    u8 pad0846[2];
} SDSecondaryState;
typedef struct {
    u8 pad0000[0x20];
    u16 adsr1;
    u16 adsr2;
    u16 a_mode;
} SDToneEnvelopeView;
typedef struct {
    u32 field_00;
    void *field_04;
} ModelSlotHeadEntry;
typedef struct {
    u16 values[58 ];
    u16 max;
} ModelSlotRow;
typedef struct {
    u32 rewrite_idx;
    u16 size;
    u16 num;
    u16 ii;
    u16 aframe;
    u8 sid;
    s8 speed;
    u16 srcii;
    s16 rframe;
    u16 tframe;
    u16 ci;
    u16 ti;
    u16 start;
    u8 start_sid;
    u8 traveling;
} ModelSlotPart;
typedef struct {
    u8 frame;
    u8 id;
    u16 flags;
} ModelSlotSoundEntry;
typedef struct {
    s32 field_00;
    s32 field_04;
    s32 field_08;
    u8 field_0C[3];
    u8 pad_0F;
} ModelSlotLightEntry;
typedef struct {
    s32 field_00;
    s32 field_04;
    s32 field_08;
    s32 field_0C;
} ModelSlotS32Quad;
typedef union {
    struct {
        u8 field_00[0xA];
        u8 field_0A[2];
    } bytes;
    struct {
        u16 field_00;
        u16 field_02;
        u8 field_04[4];
        u32 field_08;
    } values;
     




    struct {
        u8 pad_00[7];
        u8 min_x;
        u8 min_y;
        u8 min_z;
        u8 pad_0A[2];
    } thresholds;
} ModelSlotCF8Prefix;
typedef struct {
    ModelSlotCF8Prefix prefix;
    u16 field_0C[2];
    s32 field_10;
    s32 field_14;
    s32 field_18;
} ModelSlotCF8Block;
typedef struct {
    ModelSlotHeadEntry field_000[60 ];
    ModelSlotPart *field_1E0[58 ];
     



    u16 field_2C8[10 ][58 ];
    ModelSlotRow field_750[10 ];
     



    u8 field_BEC[8];
    u8 field_BF4;
    u8 field_BF5;
    u8 field_BF6;
    u8 field_BF7;
    ModelSlotSoundEntry sound_entries[64 ];
    ModelSlotCF8Block field_CF8;
    u8 *entries;
     



    struct _GsCOORDUNIT *field_D18;
     

    struct _GsCOORDUNIT *field_D1C;
    u8 pad_D20[0x50];
    ModelSlotLightEntry field_D70[3];
    s32 field_DA0[3];
    u8 pad_DAC[4];
    ModelSlotS32Quad field_DB0;
    u8 field_DC0[8];
    u16 field_DC8[4];
    s16 field_DD0[4];
     



    s32 *field_DD8;
    u8 *field_DDC;
    u8 *field_DE0;
    u8 *field_DE4;
     

    s32 field_DE8;
    s32 field_DEC;
     



    s32 field_DF0;
    s32 field_DF4;
    u16 field_DF8;
    u16 field_DFA;
    u16 field_DFC;
    u8 field_DFE;
    u8 field_DFF;
     


    u16 field_E00;
     
    u16 field_E02;
    u16 field_E04;
    u16 field_E06;
     



    u16 field_E08;
     


    u16 field_E0A;
     


    u8 field_E0C;
    u8 field_E0D;
    u8 field_E0E;
    u8 field_E0F;
    u8 field_E10;
    u8 field_E11;
    u8 field_E12;
    u8 field_E13;
    u8 field_E14;
    u8 field_E15;
    u8 field_E16;
    u8 entry_count;
    u8 field_E18;
    u8 field_E19;
    u8 field_E1A;
    u8 field_E1B;
    u8 field_E1C;
     



    u8 field_E1D;
    u8 field_E1E;
    u8 field_E1F;
} ModelSlot;
typedef char ModelSlot_field_750_max_offset_must_be_0x7C4[
    ((u32)&((( ModelSlot  *)0)->  field_750[0].max ))  == 0x7C4 ? 1 : -1
];
typedef struct _GsCOORDUNIT {
	unsigned long		flg;
	MATRIX			matrix;
	MATRIX			workm;
	SVECTOR			rot;
	struct _GsCOORDUNIT	*super;
}	GsCOORDUNIT;
typedef struct {
	GsCOORDUNIT	*coord;	 
	unsigned long	*primtop;
}       GsUNIT;
typedef struct {
	unsigned long	type;
	unsigned long	*ptr;
}	GsTYPEUNIT;
typedef struct {
	unsigned long	*primp;
	GsOT 		*tagp;
	int		shift;
	int		offset;
	PACKET		*out_packetp;
}	GsARGUNIT;
typedef struct {
    s32 key;
    void **handler;
} ModelHandlerObject;
typedef struct {
    u32 type;
    u32 *ptr;
} ModelTypeUnit;
typedef struct {
	int     vx, vy, vz;
	unsigned char r, g, b;
}       GsF_LIGHT;
typedef struct {
    u8 pad_00[0xA4];
    u16 stage_height;
    u16 texture_width;
     
    u16 field_A8;
     
    u16 field_AA;
    u8 pad_AC[0x06];
} ModelBackgroundRecord;
typedef struct {
    SVECTOR values[2];
} BackgroundNormals;
typedef struct {
    u8 bytes[8];
} ModelBytes8;
typedef struct {
    s16 field_00;
    s16 angle;
    s16 field_04;
    s16 field_06;
} ModelEffectCoefficient;
typedef struct {
    s16 x;
    s16 y;
    s16 z;
    s16 kind;
} __attribute__((packed)) ModelEffectEndpoint;
struct _GsCOORDUNIT;
typedef union {
    u32 word;
    u8 bytes[4];
    u16 halfwords[2];
    struct {
        u8 field_00;
        u8 field_01;
        s16 height;
    } fields;
} ModelDebugState;
typedef struct {
    s32 values[2];
} ModelSeparationPair;
typedef struct {
    s16 start_x;
    s16 start_y;
    s16 start_z;
    s16 pair_slot;
    s16 end_x;
    s16 end_y;
    s16 end_z;
    s16 slot;
} ModelCameraLeg;
typedef struct {
    u8 mode;
    u8 flags;
    u16 field_02;
    u16 field_04;
    u16 field_06;
    u16 elapsed;
    u16 duration;
    ModelCameraLeg eye;
    ModelCameraLeg target;
} ModelCameraMove;
typedef struct {
    u16 field_0;
    u16 field_2;
    u16 field_4;
    u16 field_6;
} ModelEffectResolvedValues;
typedef struct ModelEffectKey {
    ModelEffectEndpoint requested[2];
    ModelEffectResolvedValues resolved[2];
    s16 magnitude;
     



    u16 duration;
    u16 progress;
    u8 ready;
    u8 pad_27;
} Key;
typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
} ModelTintColor;
typedef struct {
    u16 flags;              
    u8 pad_02[8];           
    u16 field_0A;           
    u16 elapsed;            
    u16 duration;           
    ModelTintColor start;   
    ModelTintColor end;     
} ModelTintRequest;
typedef void *va_list;
typedef union {
    u32 word;
    u8 display_enabled;
} ModelDebugDisplayState;
typedef struct {
	u32	tag;
	u8	r0, g0, b0, code;
	short	x0, 	y0;
	u8	r1, g1, b1, pad1;
	short	x1,	y1;
	u8	r2, g2, b2, pad2;
	short	x2,	y2;
} POLY_G3;
typedef struct {
    s16 x;
    s16 y;
    s16 z;
    s16 max;
} ModelEffectAdjustment;
typedef struct {
    s16 x;
    s16 z;
} ModelShadowFanStep;
typedef struct {
    s32 key;
    s32 metadata;
} ModelHandlerRunEntry;
typedef struct {
    ModelSlotCF8Prefix prefix;
    u16 field_0C[2];
    s32 field_10;
    s32 field_14;
    s32 field_18;
    u8 pad_1C[0xEA];
    u8 field_106;
    u8 field_107;
} ModelSlotCF8TailView;
typedef s32 (*ModelControlHandler)(u8 *context, s32 command);
typedef struct {
    u8 prefix[0xD08];
    s32 commands[3];
} ModelControlCommandView;
typedef struct {
    u32 value[7];
} ModelSlotCF8BlockWords;
typedef struct {
    ModelSlotSoundEntry sound_entries[64 ];
    ModelSlotCF8BlockWords field_CF8;
} ModelTransferMetadata;
typedef struct {
    u8 r;
    u8 g;
    u8 b;
} Color;
typedef struct {
    s32 h;
    u16 s;
    u16 v;
} HsvT;
typedef struct {
	u8	r0, g0, b0, code;
} P_CODE;
typedef struct {
    u8 head[0x2400];
    RECT slots[4];
    RECT frame;
    RECT strip;
} MovieWorkArea;
typedef struct {
    u16 id;
    u16 type;
    u16 secCount;
    u16 nSectors;
    u32  frameCount;
    u32  frameSize;

    u16 width;
    u16 height;
    u32  dummy1;
    u32  dummy2;
    CdlLOC  loc;
} StHEADER;
typedef	u16 DECDCTTAB[34816];
typedef struct {
	unsigned long	*primp;
	GsOT		*tagp;
	int		shift;
	int		offset;
	PACKET		*out_packetp;
	long		header_size;
	unsigned long	*htop;
	unsigned long	*ctop;
	unsigned long	*ptop;
} GsARGUNIT_ANIM;
typedef struct {
	short		idx;
	u8		sid;
	u8		pad;
} GsSEH;
typedef struct {
	u32		rewrite_idx;
	u16		size, num;
	u16		ii;
	u16		aframe;
	u8		sid;
	signed char	speed;
	u16		srcii;
	short		rframe;
	u16		tframe;
	u16		ci, ti;
	u16		start;
	u8		start_sid;
	u8		traveling;
} GsSEQ;
typedef struct {
    s16 x;
    s16 y;
    s16 z;
    s16 rx;
    s16 ry;
    s16 rz;
} ModelKeyframe;
typedef struct {
    GsSEQ *seq;
    ModelKeyframe *source;
    ModelKeyframe *target;
    ModelKeyframe *out;
} ModelAnimParams;
typedef struct {
    s16 x;
    s16 y;
    s16 z;
    u16 rotation_x;
    u16 rotation_y;
    u16 rotation_z;
    s16 scale_x;
    s16 scale_y;
    s16 scale_z;
} ModelAnimationSample;
typedef struct {
    GsSEQ *track;
    ModelAnimationSample *sample_1;
    ModelAnimationSample *sample_2;
    u16 *output;
} ModelAnimationInterpolationSlots;
typedef struct {
    s16 x;
    s16 y;
    s16 z;
    u16 w;
} Coeff;
typedef struct {
    DuelCardDisplayObject *object;
    s16 x;
    s16 y;
    u16 enabled;
    u16 card_entries[7];
} CardListRowSet;
typedef struct {
	unsigned long attribute;
	short   x0, y0;
	short   x1, y1;
	unsigned char r, g, b;
}       GsLINE;
typedef u8 Triplet[4];
typedef struct {
    u8 colors[3][6];
    s16 minimum_height;
    s16 minimum_radius;
    s16 growth_duration;
    s16 fade_duration;
    s16 pad;
} ModelSubdividedEffectConfig;
typedef struct {
    ModelSubdividedEffectConfig *config;
    SVECTOR vertices[6];
    SVECTOR *vertex_links[24];
    SVECTOR subdivided_vertices[384];
    Triplet colors[6];
    u8 *color_links[24];
    Triplet subdivided_colors[384];
    u8 field_130C;
    u8 field_130D;
    u8 pad_130E[2];
    s32 elapsed;
    s32 remaining;
} ModelSubdividedEffect;
typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 pad_03;
    s16 min_radius;
    s16 full_level;
    s16 full_scale;
    u16 pad_0A;
} ModelDiscEffectConfig;
typedef struct {
    ModelDiscEffectConfig *table;
    SVECTOR points[67];
    u8 r;
    u8 g;
    u8 b;
    u8 pad21F;
    s32 unk220;
    s32 level;
    s32 scale;
    u8 frame;
} ModelDiscEffectState;
typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 pad;
} ModelBurstColor;
typedef struct {
    u8 r[3];
    u8 g[3];
    u8 b[3];
} ModelBurstPalette;
typedef struct {
    u16 mode;
    u16 unk_02;
    RECT prect;
    u32 *paddr;
    RECT crect;
    u32 *caddr;
} ModelBurstImage;
typedef struct {
    u16 tpage;
    u16 clut;
} ModelBurstTexture;
typedef struct {
    ModelBurstPalette *table;
    s32 frame;
    SVECTOR rings[3];
    SVECTOR ring_speed[3];
    SVECTOR dust[64];
    SVECTOR dust_speed[64];
    SVECTOR sparks[32];
    SVECTOR spark_drift[32];
    SVECTOR spark_rise[32];
    SVECTOR embers[32];
    SVECTOR smoke[64];
    SVECTOR smoke_speed[64];
    SVECTOR origin;
    u16 dust_frame[64];
    u16 spark_frame[32];
    u16 smoke_frame[64];
    u16 radius;
    u16 phase;
    u16 stage;
    u16 spark_count;
    u8 fade;
    u8 pad_d89;
    u16 tpage;
    u16 clut;
    ModelBurstTexture spark_texture[1];
    ModelBurstColor colors[3];
    u8 flash_r;
    u8 flash_g;
    u8 flash_b;
    u8 pad_da1;
    ModelBurstColor spark_colors[32];
    u8 smoke_r;
    u8 smoke_g;
    u8 smoke_b;
} ModelBurstEffect;
typedef struct {
    u16 size;
    u16 grow;
} ModelSparkSize;
typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 pad;
} ModelSparkColor;
typedef struct {
    SVECTOR sparks[32];
    ModelSparkSize sizes[32];
    SVECTOR flashes[32];
    SVECTOR dust[64];
    SVECTOR dust_speed[64];
    u16 dust_frame[64];
    u16 spark_count;
    u16 flash_count;
    u16 frame;
    u16 mode;
    u8 fade;
    u8 pad709;
    u16 tpage;
    u16 clut;
    ModelSparkColor spark_colors[32];
    ModelSparkColor flash_colors[32];
    u8 dust_r;
    u8 dust_g;
    u8 dust_b;
} ModelSparkEffect;
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
typedef struct {
    s8 values[9 ];
} AiOpponentData;

#endif /* KG_TYPES_H */
