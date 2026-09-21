/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_800556E8.c, profile gcc_2_8_1_g8_split.
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
void func_8004DC38(ModelSlot *slot, s32 i, s32 n, u32 pos);
void func_8005106C(s32 index);
s32 func_80058E1C(void);
void func_80059700(s32 index, s32 sign);
void func_800597C8(s32 idx, s32 flag, s32 val);
void func_80057AF4(s32 index, s32 anim, s32 flag);
void func_8005F714(s32 first, s32 second, s32 arg);
void func_800556E8(s32 index);
void func_800556E8(s32 index) {
    ModelSlot *m;
    s32 anim;
    s32 length;
    s32 speed;
    s32 i;
    s32 frame;
    s32 lim;

    m = &D_800F2C40[index];
    if (m->field_E1F == 0) {
        return;
    }
    if (m->field_DD8 != 0) {
        anim = m->field_BF5;
        length = m->field_750[anim].max << 4;
        speed = m->field_E0D * func_80058E1C();
        if (anim == 6) {
            lim = length - speed;
            if ((m->field_E16 == 0x3E && m->field_E06 >= lim) ||
                (m->field_E16 == 0x3C && m->field_E06 < 2)) {
                func_80059700(index, 0);
            }
        }
        if (index < 2) {
            func_8005106C(index);
        }
        if (m->field_E16 != 0x23) {
            if (m->field_E16 == 0x3E) {
                s32 v;

                if (m->field_E06 >= length) {
                    m->field_E06 = 0;
                }
                v = m->field_E06 + speed;
                if (v >= length) {
                    m->field_E06 = length;
                } else {
                    m->field_E06 = v;
                }
            } else {
                s32 w;

                if (m->field_E06 == 0) {
                    m->field_E06 = length;
                }
                w = m->field_E06 - speed;
                if (w <= 0) {
                    m->field_E06 = 0;
                } else {
                    m->field_E06 = w;
                }
            }
        }
        if (m->field_E10 == 0) {
            if (m->field_E16 == 0x3E ? m->field_E06 >= length : m->field_E06 == 0) {
                if (m->field_DC0[7] == 6) {
                    m->field_BF4 = 2;
                }
                if (m->field_BF4 != m->field_BF6) {
                    func_800597C8(index, m->field_BF4, 0);
                    m->field_BF6 = m->field_BF4;
                    if (m->field_E0F != 0) {
                        func_80057AF4(index, 0, 0);
                    }
                    if (m->field_DC0[7] == 6) {
                        func_8005F714(-1, index + 2, m->field_750[2].max);
                        m->field_DC0[7] = 0;
                        m->field_BF4 = 1;
                    }
                }
            }
        }
    }
    if (m->field_E16 != 0x23) {
        if (m->field_E0D == 0x10) {
            if (func_80058E1C() == 2) {
                return;
            }
        }
    }
    frame = m->field_E06;
    if (m->field_E1B != 0) {
        i = 0;
        do {
            func_8004DC38(m, i, m->field_BF5, frame);
            i++;
        } while (i < m->field_E1B);
    }
}
