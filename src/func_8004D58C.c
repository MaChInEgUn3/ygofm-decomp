/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/model_slot_row_tables.c, profile gcc_2_8_1_g0.
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
extern ModelSlot D_800F2C40[3 ];
void func_8004D58C(s32 slot, u8 *commands);
void func_8004D58C(s32 arg0, u8 *arg1)
{
    ModelSlot *ch;
    u8 *t;
    u8 *c;
    u8 *q;
    u8 *e;
    u8 *p3;
    u8 *p2;
    u8 *g;
    u8 *k;
    u8 *s;
    u8 *u;
    u8 *v;
    s32 ff;
    s32 one;
    s32 i;
    s32 j;
    s32 n;
    s32 m;
    s32 a;
    s32 b;
    s32 w;
    s32 d;
    s32 x;
    s32 y;
    s32 flag;
    s32 qd;

    do {
        do {
            p3 = (u8 *)0;
        } while (0);
    } while (0);
    p2 = (u8 *)0;
    i = 0;
    ff = 0xFFFF;
    n = 0;
    m = 0;
    ch = &D_800F2C40[arg0];
    t = (u8 *)ch;
    c = t;
    ch->field_E06 = 0;
    ch->field_E08 = 0;
    ch->field_DD8 = 0;
    *(s32 *)&ch->field_DDC = 0;
    *(s32 *)&ch->field_DE0 = 0;
    *(s32 *)&ch->field_DE4 = 0;
    ch->field_DF0 = 0;
     











    do {
        ((ModelSlotRow *)(c + (u32)&((ModelSlot *)0)->field_750))->max = 0;
        j = 0;
        a = n;
        b = m;
        do {
            u = t + a;
            a += 2;
            v = t + b;
            b += 2;
            j++;
            *(u16 *)(v + (u32)&((ModelSlot *)0)->field_2C8) = ff;
            *(s16 *)(u + (u32)&((ModelSlot *)0)->field_750) = 0;
        } while (j < 0x3A);
        n += sizeof(ModelSlotRow);
        m += 0x74;
        i++;
        c += sizeof(ModelSlotRow);
    } while (i < 0xA);
    i = 7;
    q = t + i;
    do {
        q[(u32)&((ModelSlot *)0)->field_BEC] = 0;
        i--;
        q--;
    } while (i >= 0);
    e = *(u8 **)(arg1 + 0x10);
    if (e == (u8 *)0) {
        return;
    }
    do {
        if (*(s32 *)(e + 8) != 0) {
            w = e[0xF];
            if (w == 3) {
                p3 = *(u8 **)(e + 4);
            }
            if (w == 2) {
                p2 = *(u8 **)(e + 4);
            }
        }
        e = *(u8 **)e;
    } while (e != (u8 *)-1);
    if (p3 != (u8 *)0) {
        p3 += 8;
        k = *(u8 **)p3;
        p3 += 4;
        i = 0;
        if (*(u16 *)k != 0) {
            one = 1;
            g = k;
            do {
                do {
                    do {
                        qd = i / 8;
                    } while (0);
                } while (0);
                s = t + qd;
                d = qd << 3;
                y = s[(u32)&((ModelSlot *)0)->field_BEC];
                flag = *(volatile s32 *)(g + 4) & 0x100;
                if (flag != 0) {
                    x = y | (one << (i - d));
                } else {
                    x = y;
                }
                s[(u32)&((ModelSlot *)0)->field_BEC] = x;
                g += 4;
                i++;
            } while ((u32)i < *(u16 *)k);
        }
        *(s32 *)(t + (u32)&((ModelSlot *)0)->field_DD8) = *(s32 *)p3;
        *(s32 *)(t + (u32)&((ModelSlot *)0)->field_DDC) = *(s32 *)(p3 + 4);
    }
    if (p2 != (u8 *)0) {
        p2 += 4;
        *(s32 *)(t + (u32)&((ModelSlot *)0)->field_DE0) = *(s32 *)p2;
        *(s32 *)(t + (u32)&((ModelSlot *)0)->field_DE4) = *(s32 *)(p2 + 4);
    }
}
