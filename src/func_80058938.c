/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_80058938.c (Model_QueueTintRequest), profile gcc_2_8_1_g8_split_no_strength_reduce.
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
void func_80058938(
    s32 slot, s32 selection, ModelTintColor start, ModelTintColor end,
    s32 duration, const u8 *part_mask);
void func_80058938(
    s32 slot, s32 selection, ModelTintColor start, ModelTintColor end,
    s32 duration, const u8 *part_mask);
void func_80058938(
    s32 a0, s32 a1, ModelTintColor a2, ModelTintColor a3, s32 a4,
    const u8 *bits)
{
    ModelSlot *slot;
    ModelTintRequest *r;
    ModelTintRequest *end;
    register u8 *base = (u8 *)D_800F2B50;
    s32 off;
    s32 fill;
    s32 f;
    s32 mode;
    s32 f1, f2, f3, f4, f5, f6;
    s32 sel;

    slot = &D_800F2C40[a0];
    mode = (a0 & 1) << 1;
    sel = (a1 & 1) << 2;
    fill = 0xFF;
    off = 0;
    r = D_800F2B50;
    end = r + 10 ;
    do {
        if ((*(u8 *)r & 1) == 0) {
            f = r->flags;
            f1 = f | 1;
            f2 = f1 & 0xFFFD;
            f3 = f2 | mode;
            f4 = f3 & 0xFFFB;
            f5 = f4 | sel;
            do {
                mode = 0;
            } while (0);
            r->flags = f5;
            f6 = f5 & 0xFF07;
            sel = off;
            f = f6 | ((slot->field_BF5 & 0x1F) << 3);
            r->flags = f;
            r->field_0A = slot->field_E06;
            r->elapsed = 0;
            r->duration = (a4 *= 2);
            r->start = a2;
            r->end = a3;
            for (; mode < 8; mode++) {
                base[mode + sel + 1] = bits ? bits[mode] : fill;
            }
            break;
        }
        off += sizeof(ModelTintRequest);
        r++;
    } while ((s32)r < (s32)end);
}
