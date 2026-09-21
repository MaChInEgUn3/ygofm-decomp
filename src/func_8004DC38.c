/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_8004DC38.c, profile gcc_2_8_1_g8.
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
typedef char ModelSlot_field_750_max_offset_must_be_0x7C4[
    ((u32)&((( ModelSlot  *)0)->  field_750[0].max ))  == 0x7C4 ? 1 : -1
];
void func_8004DC38(ModelSlot *slot, s32 i, s32 n, u32 pos);
void func_8004DC38(ModelSlot *p, s32 i, s32 n, u32 pos) {
    s32 *tbl;
    ModelSlotPart *e;
    s32 *q;
    s32 *cp;
    s32 *v;
    s32 k;
    s32 step;
    s32 rem;
    s32 len;
    s32 idx;
    s32 x;
    s32 y;
    s32 z;
    s32 d;
    s32 off4;
    s32 off2;

     



    off4 = i * 4;
    off2 = i * 2;
    k = p->field_2C8[n][i];
    tbl = p->field_DD8;
    e = p->field_1E0[i];
    q = tbl + k;
    if (e == 0) {
        return;
    }
    if (k == 0xFFFF) {
        return;
    }
     

    if (p->field_750[n].values[i] == 0) {
        return;
    }
    step = p->field_750[n].values[i] * 16;
    rem = pos % step;
    cp = q - 1;
    if (rem == 0) {
        if (pos != 0 && p->field_E16 != 0x3C) {
            rem = step;
        }
    }
     




    idx = 0;
    if (idx >= *(u16 *)cp) {
        return;
    }
    for (; idx < *(u16 *)cp; idx++) {
        if (p->field_E16 != 0x3C) {
            d = rem - (((u8 *)q)[2] << 4);
            if (d <= 0) {
                break;
            }
        } else {
            d = rem - (((u8 *)q)[2] << 4);
            if (d < 0) {
                break;
            }
        }
        rem = rem - (((u8 *)q)[2] << 4);
        if (q[1] < 0) {
            break;
        }
        q++;
    }

    len = *(u16 *)cp;
    if (idx >= len) {
        return;
    }
     


    v = q;
scan:
    if (v[1] >= 0) {
        idx++;
        v++;
        if (idx < len) {
            goto scan;
        }
    }
    x = q - p->field_DD8;
    e->ti = x;
    if (x != 0) {
        x = x - 1;
    } else {
        x = v - p->field_DD8;
    }
    e->ci = x;
    y = ((u8 *)q)[2] << 4;
    z = y - rem;
    e->tframe = y;
    e->rframe = z;
    if (p->field_E16 != 0x3C) {
        return;
    }
    if ((s16)z < e->tframe) {
        return;
    }
    e->rframe = 0x6000;
}
