/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/model_scene_setup.c, profile gcc_2_8_1_g8_split.
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
s32 func_8005A8C4(s32 index, s32 type);
s32 func_80059AA8(s32 index, s32 value);
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
typedef char ModelSlot_field_750_max_offset_must_be_0x7C4[
    ((u32)&((( ModelSlot  *)0)->  field_750[0].max ))  == 0x7C4 ? 1 : -1
];
extern ModelSlot D_800F2C40[3 ];
extern ModelTintRequest D_800F2B50[10 ];
void func_8004DC38(ModelSlot *slot, s32 i, s32 n, u32 pos);
s32 func_80058E1C(void);
void func_800528AC(void);
struct _GsCOORDUNIT;
extern u8 D_8009AF9B;
extern s32 D_8009AF9C;
typedef struct  {
	short	m[3][3];	 
        long    t[3];		 
} MATRIX;
typedef struct {		 
	short	vx, vy;
	short	vz, pad;
} SVECTOR;
typedef struct _GsCOORDUNIT {
	unsigned long		flg;
	MATRIX			matrix;
	MATRIX			workm;
	SVECTOR			rot;
	struct _GsCOORDUNIT	*super;
}	GsCOORDUNIT;
void func_800540B4(s32 index);
void func_800528AC(void)
{
    ModelTintColor save;
    ModelTintColor col;
    s32 i;
    s32 j;
    s32 k;
    u32 v;
    s32 keep;
    s32 rowbase;
    u32 part;
    u32 sid;
    s32 old;
    u8 side;
    u16 sav06;
    s32 off;
    u16 lo;
    u16 hi;
    u16 a;
    s32 aa;
    s32 sv;
    ModelSlot *slot;
    ModelTintRequest *e;
    ModelTintRequest *table;

    table = (ModelTintRequest *)D_800F2B50;
    for (i = 0, off = 0; i < 10 ; off += 0x18, i++) {
        e = &table[i];
        rowbase = (s32)((u8 *)table + 1);
        if ((*(u8 *)e & 1) == 0) {
            continue;
        }
        if (D_800F2C40[(e->flags >> 1) & 1].field_E1F == 0) {
            continue;
        }
        if (func_8005A8C4((e->flags >> 1) & 1, e->start.b3)) {
            goto tail;
        }
        v = e->flags;
        a = e->field_0A;
        lo = e->elapsed;
        hi = e->duration;
        side = (v >> 1) & 1;
        v = v >> 3;
        slot = &D_800F2C40[side];
        sav06 = slot->field_E06;
        part = v & 0x1F;
        keep = slot->field_BF5;
        old = func_80059AA8(side, 0);
        sid = part;
        save = * ((ModelTintColor *)( slot->field_DC0 )) ;
        col.b3 = e->start.b3;
        col.b0 = e->start.b0 * (hi - lo) / hi + e->end.b0 * lo / hi;
        col.b1 = e->start.b1 * (hi - lo) / hi + e->end.b1 * lo / hi;
        col.b2 = e->start.b2 * (hi - lo) / hi + e->end.b2 * lo / hi;
        * ((ModelTintColor *)( slot->field_DC0 ))  = col;

        aa = a;
        for (j = 0; j < slot->field_E1B; j++) {
            s32 t = slot->field_BF5;
            if (sid != 0) {
                slot->field_1E0[j]->sid = sid;
                t = sid;
            }
            func_8004DC38(slot, j, t, aa);
        }
        if (sid != 0) {
            slot->field_BF5 = sid;
        }

        D_8009AF9C = off + rowbase;
        D_8009AF9B = (e->flags >> 2) & 1;
        func_800540B4(side);
        D_8009AF9C = 0;
        D_8009AF9B = 0;

        sv = sav06;
        for (k = 0; k < slot->field_E1B; k++) {
            s32 t = slot->field_BF5;
            if (keep != 0) {
                slot->field_1E0[k]->sid = keep;
                t = keep;
            }
            func_8004DC38(slot, k, t, sv);
        }
        if (keep != 0) {
            slot->field_BF5 = keep;
        }

        func_80059AA8(side, old);
        * ((ModelTintColor *)( slot->field_DC0 ))  = save;
tail:
        e->elapsed += func_80058E1C();
        if (e->elapsed >= e->duration) {
            e->flags &= 0xFFFE;
        }
    }
}
