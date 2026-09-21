/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/duel_phase_entry.c (DuelScene_UpdateStartup), profile gcc_2_8_1_g8_split.
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
extern s32 D_801D4244[];
typedef struct {
    s16 id;
     

    s8 deck_index;
    u8 data_block_index;
    u8 flags_04;
    u8 unk_05;
} DuelDeckCardRecord;
extern DuelDeckCardRecord D_801A7E20[];
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
extern DuelSideState D_800E9FF0[2 ];
extern u16 D_8009B36A __attribute__((section(".data")));
extern u16 D_8009B23A;
void func_80018608(void);
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
typedef struct {
    u8 *object;
    u8 *child;
    u8 pad_08;
    u8 active_09;
    u8 pad_0A[2];
} DuelHandSlot;
extern DuelHandSlot D_800EA030[5 ];
extern u8 D_8009B1EC;
void func_800176D0(void);
void func_800157DC(void);
extern volatile u32 D_8009B0F4_abs __attribute__((section(".data")));
extern u32 D_8009B134_abs __attribute__((section(".data")));
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
extern u8 D_800E9F10[];
extern DuelCardPickCursor *D_8009B1B4;
void func_8003FF08(u32);
extern u16 D_8009B162;
extern u16 D_8009B23A;
extern u8 D_8009B174;
void func_80024734(void);
void func_80024824(void);
void func_80018608(void)
{
    u16 *w;
    DuelDeckCardRecord *rec;
    s32 i;
    s32 atk;
    s32 def;
    s32 stat;
    s32 stat2;

    w = (u16 *)&D_800F2848;
    if ((D_8009B23A & 0x8000 ) == 0) {
        D_8009B23A |= 0x8000 ;
        func_80024734();
        D_800F2848.field_00 = 0x4B0;
        w[2] = 0x358;
        w[1] = 0x16C0;
        func_8001352C();
        D_8009B174 = 2;
        func_800157DC();
        return;
    }

    switch (D_8009B174 & 0x1F) {
    case 2:
        D_800F2848.field_00 -= 2;
        w[2] -= 2;
        w[1] -= 0x10;
        if ((s16)w[1] <= 0x400) {
            D_800F2848.field_00 = 0x258;
            w[2] = 0x100;
            w[1] = 0x400;
            D_8009B174 = 3;
        }
        func_8001352C();
        break;
    case 3:
        if ((D_8009B174 & 0x80) == 0) {
            D_8009B174 |= 0x80;
            D_8009B162 = 2;
            D_8009B1B4 = (DuelCardPickCursor *)(D_800E9F10 +
                D_8009B1D5 * (4  * 0x1C ) );
            *(u16 *)&D_8009B1B4->field_0C = 0xAE;
        }
        if (D_8009B162 == 0) {
            D_8009B174 = 4;
        }
        break;
    case 4: {
        u32 mask = 0x02000030 ;

        if (((D_8009B0F4_abs & mask) |
             D_8009B134_abs) != 0) {
            break;
        }
        func_8003FF08(D_8009B36A);
        func_80024824();
        atk = 0;
        def = 0;
        rec = D_801A7E20;
        for (i = 0; i < 40 ; i++, rec++) {
            stat = D_801D4244[rec->id - 1];
            atk += (stat & 0x1FF ) * 10 ;
            def += ((stat >> 9 ) & 0x1FF ) *
                   10 ;
        }
        D_800E9FF0[0].field_0E = atk / 40 ;
        D_800E9FF0[0].field_10 = def / 40 ;
        atk = 0;
        def = 0;
        rec = &D_801A7E20[40 ];
        for (i = 0; i < 40 ; i++, rec++) {
            stat2 = D_801D4244[rec->id - 1];
            atk += (stat2 & 0x1FF ) * 10 ;
            def += ((stat2 >> 9 ) & 0x1FF ) *
                   10 ;
        }
        D_800E9FF0[1].field_0E = atk / 40 ;
        D_800E9FF0[1].field_10 = def / 40 ;
        D_8009B174 = 5;
        break;
    }
    case 5:
        func_800176D0();
        D_8009B1EC = 5 ;
        D_8009B23A = 3;
        ((DuelSelectionSideView *)(D_800E9F10 +
            D_8009B1D5 * (4  * 0x1C ) ))->hand = D_800EA030;
        break;
    }
}
