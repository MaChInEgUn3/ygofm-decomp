/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/model_debug_controller.c (ModelDebug_UpdateController), profile gcc_2_8_1_g8_split.
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
extern ModelDebugState D_8009B004;
typedef union {
    u32 word;
    u8 display_enabled;
} ModelDebugDisplayState;
extern ModelDebugDisplayState D_8009B008;
extern char D_8009B00C[];
extern char D_8009B014[];
extern char D_8009B01C[];
extern char D_8009B024[];
extern char D_8009B02C[];
s32 func_800534B8(void);
extern char D_80011518[];
extern char D_8001152C[];
extern char D_80011540[];
extern char D_80011554[];
extern char D_80011564[];
extern volatile u16 D_8009B398 __attribute__((section(".data")));
extern u16 D_8009B3A4 __attribute__((section(".data")));
extern volatile u16 D_8009B394 __attribute__((section(".data")));
extern u16 D_8009B39A __attribute__((section(".data")));
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
s32 func_80056504(
    s32 slot, s32 model, s32 p2, s32 p3, s32 p4, s32 p5, s32 arg6
);
void func_80056828(s32 index);
extern u8 *D_8009AF88;
extern s8 D_8009AF9A;
extern u8 D_8009AFA1;
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
    u8 pad_00[0xA4];
    u16 stage_height;
    u16 texture_width;
     
    u16 field_A8;
     
    u16 field_AA;
    u8 pad_AC[0x06];
} ModelBackgroundRecord;
extern int func_8007EF84();
typedef struct _GsCOORDUNIT {
	unsigned long		flg;
	MATRIX			matrix;
	MATRIX			workm;
	SVECTOR			rot;
	struct _GsCOORDUNIT	*super;
}	GsCOORDUNIT;
extern s16 D_8009B488[3 ];
extern u8 D_8009B48E[2];
extern u8 D_8009B490[2];
void func_80053248(s32 idx, ...);
void func_800533D8(void);
void func_80059AEC(s32 value);
s32 func_80059AA8(s32 index, s32 value);
struct _GsCOORDUNIT;
void func_8005922C(struct _GsCOORDUNIT *unit, VECTOR *scale);
void func_800137E4(void);
extern volatile u32 D_8009B0F4_abs __attribute__((section(".data")));
extern u32 D_8009B134_abs __attribute__((section(".data")));
extern int  func_8008E590(void);
extern ModelDebugState D_8009B004;
s32 func_800534B8(void)
{
    s32 reload = 0;
    char *normal = D_8009B00C;
    char *selected = D_8009B014;
    ModelSlot *slots;

    if (D_8009AF9A == -2)
        return 1;
    if (D_8009AF9A >= 40)
        return 0;
    if ((D_8009B398 & 0x20) || (D_8009B39A & 0x20)) {
        D_8009AF9A = 40;
        return 0;
    }
    slots = D_800F2C40;
    if (!slots[2].field_E1F) {
        func_80059AEC(1);
        func_8007EF84(D_80011518, slots[2].field_DF8, slots[2].field_E14);
        if (slots[2].field_E14 == 255) {
            if (!((D_8009B0F4_abs & 0x2000030) | D_8009B134_abs))
                func_80056504(2, -1, -1, -1, -1, -1, 0);
        } else {
            func_80056828(2);
        }
        if (D_800F2C40[2].field_E1F) {
            ModelSlot *stage = D_800F2C40;
            s32 height;

            stage += 2;
             

            *(u16 *)&D_8009B004.fields.height =
                ((ModelBackgroundRecord *)D_8009AF88)->stage_height;
            height = D_8009B004.fields.height;
            if (stage->field_D18) {
                stage->field_D18->rot.vx = 0;
                stage->field_D18->rot.vy = 0;
                stage->field_D18->rot.vz = 0;
                stage->field_D18->matrix.t[0] = 0;
                stage->field_D18->matrix.t[1] = height;
                stage->field_D18->matrix.t[2] = 0;
            }
            func_8005922C(stage->field_D18, 0);
            D_8009AF9A = 0;
        }
    } else if (!slots[0].field_E1F) {
        func_80059AEC(1);
        func_8007EF84(D_8001152C, slots[0].field_DF8, slots[0].field_E14);
        if (slots[0].field_E14 == 255) {
            if (!((D_8009B0F4_abs & 0x2000030) | D_8009B134_abs))
                func_80056504(0, -1, -1, -1, -1, -1, 0);
        } else {
            func_80056828(0);
        }
        if (D_800F2C40[0].field_E1F)
            func_80059AA8(0, ((D_8009AF88[0xA1] >> 1) ^ 1) & 1);
    } else if (!slots[1].field_E1F) {
        func_80059AEC(1);
        func_8007EF84(D_80011540, slots[1].field_DF8, slots[1].field_E14);
        if (slots[1].field_E14 == 255) {
            if (!((D_8009B0F4_abs & 0x2000030) | D_8009B134_abs))
                func_80056504(1, -1, -1, -1, -1, -1, 0);
        } else {
            func_80056828(1);
        }
        if (D_800F2C40[1].field_E1F)
            func_80059AA8(1, ((D_8009AF88[0xA1] >> 1) ^ 1) & 1);
    }
    if ((D_8009B3A4 & 0x100) && (D_8009B39A & 0x100))
        D_8009B008.display_enabled ^= 1;
    if (!D_8009B008.display_enabled)
        return 0;
    if (D_8009AF9A == -2) {
        s32 i = 0;
        s32 excluded;
        s32 value;

        while (1) {
            do {
                value = (func_8008E590() >> 8) % 722;
                excluded = 720;
            } while ((u32)value >= 722);
            if ((u32)(value - 300) >= 50 && (u32)(value - 650) >= 50 && value != excluded) {
                D_8009B488[i] = value;
                if ((u16)value != D_800F2C40[i].field_DF8) {
                    i++;
                    if (i >= 2)
                        break;
                }
            }
        }
        reload++;
        D_8009B488[2] = (func_8008E590() >> 8) % 7;
    }
    if (D_8009B398 & 0x10)
        reload++;
    if (D_8009B394 & 0x900) {
        if (D_8009B394 & 0x100)
            D_8009B488[2] = ((u16)D_8009B488[2] + 6) % 7;
        else
            D_8009B488[2] = ((u16)D_8009B488[2] + 8) % 7;
    }
    if (D_8009B394 & 0xA000) {
        if (D_8009B394 & 0x8000)
            D_8009AFA1 = (D_8009AFA1 + 5) % 6;
        else
            D_8009AFA1 = (D_8009AFA1 + 7) % 6;
    }
    if (D_8009B3A4 & 0x80) {
        if (D_8009B394 & 0x5000) {
            if (D_8009B394 & 0x1000)
                D_8009B004.halfwords[1] -= 10;
            else
                D_8009B004.halfwords[1] += 10;
            if (D_800F2C40[2].field_E1F) {
                ModelSlot *stage = D_800F2C40;
                s32 height;

                stage += 2;
                height = D_8009B004.fields.height;
                if (stage->field_D18) {
                    stage->field_D18->rot.vx = 0;
                    stage->field_D18->rot.vy = 0;
                    stage->field_D18->rot.vz = 0;
                    stage->field_D18->matrix.t[0] = 0;
                    stage->field_D18->matrix.t[1] = height;
                    stage->field_D18->matrix.t[2] = 0;
                }
                func_8005922C(stage->field_D18, 0);
            }
        }
    } else if (D_8009B394 & 0x5000) {
        s32 side = D_8009AFA1 >= 3u;
        u16 *number = (u16 *)&D_8009B488[side];
        s32 digits[3] = {
            (u16)((u16)(*number / 100u) % 10u),
            (u16)((u16)(*number / 10u) % 10u),
            (u16)(*number % 10u)
        };

        if (D_8009B394 & 0x1000) {
            digits[(u8)(D_8009AFA1 % 3u)] =
                (digits[(u8)(D_8009AFA1 % 3u)] + 11) % 10;
        } else {
            digits[(u8)(D_8009AFA1 % 3u)] =
                (digits[(u8)(D_8009AFA1 % 3u)] + 9) % 10;
        }
        D_8009B488[side] = 100 * digits[0] + 10 * digits[1] + digits[2];
    }
    if (D_8009B398 & 4)
        D_8009B48E[0] ^= 1;
    if (D_8009B398 & 1)
        D_8009B490[0] ^= 1;
    if (D_8009B398 & 8)
        D_8009B48E[1] ^= 1;
    if (D_8009B398 & 2)
        D_8009B490[1] ^= 1;
    func_8007EF84(D_8009B01C, D_8009AFA1 == 0 ?
        selected : normal, (u16)((u16)((u16)D_8009B488[0] / 100u) % 10u));
    func_8007EF84(D_8009B01C, D_8009AFA1 == 1 ?
        selected : normal, (u16)((u16)((u16)D_8009B488[0] / 10u) % 10u));
    func_8007EF84(D_8009B01C, D_8009AFA1 == 2 ?
        selected : normal, (u16)((u16)D_8009B488[0] % 10u));
    func_8007EF84(normal);
    func_8007EF84(D_80011554, D_8009B48E[0], D_8009B490[0]);
    func_8007EF84(D_8009B024);
    func_8007EF84(D_8009B01C, D_8009AFA1 == 3 ?
        selected : normal, (u16)((u16)((u16)D_8009B488[1] / 100u) % 10u));
    func_8007EF84(D_8009B01C, D_8009AFA1 == 4 ?
        selected : normal, (u16)((u16)((u16)D_8009B488[1] / 10u) % 10u));
    func_8007EF84(D_8009B01C, D_8009AFA1 == 5 ?
        selected : normal, (u16)((u16)D_8009B488[1] % 10u));
    func_8007EF84(normal);
    func_8007EF84(D_80011554, D_8009B48E[1], D_8009B490[1]);
    func_8007EF84(D_8009B02C);
    func_8007EF84(D_80011564, (u16)D_8009B488[2], D_8009B004.fields.height);
    if (reload) {
        func_800137E4();
        func_800533D8();
        func_80053248(0, (u16)D_8009B488[0], -1, -1,
            D_8009B48E[0], D_8009B490[0]);
        func_80053248(1, (u16)D_8009B488[1], -1, -1,
            D_8009B48E[1], D_8009B490[1]);
        func_80053248(2, (u16)D_8009B488[2]);
    }
    return 0;
}
