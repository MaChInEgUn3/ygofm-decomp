/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_80051A48.c, profile gcc_2_8_1_g8_split.
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
typedef char ModelSlot_field_750_max_offset_must_be_0x7C4[
    ((u32)&((( ModelSlot  *)0)->  field_750[0].max ))  == 0x7C4 ? 1 : -1
];
extern ModelSlot D_800F2C40[3 ];
extern ModelCameraMove D_800F2B20;
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
typedef struct _GsCOORDUNIT {
	unsigned long		flg;
	MATRIX			matrix;
	MATRIX			workm;
	SVECTOR			rot;
	struct _GsCOORDUNIT	*super;
}	GsCOORDUNIT;
extern GsRVIEW2 D_800F56F0;
void func_80051A48(void);
extern s8 D_8009AF99;
typedef struct {
    s16 x;
    s16 y;
    s16 z;
    s16 kind;
} __attribute__((packed)) ModelEffectEndpoint;
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
s32 func_8005FB08(void);
s32 func_8005FB14(void);
void func_80052694(s32 arg0);
void func_80059EBC(s32 value);
struct _GsCOORDUNIT;
void func_80057F38(u8 *view);
void func_80058434(s32 direction, s32 yaw, s32 pitch, s32 distance, s32 unused);
s32 func_80058E1C(void);
void func_80051A48(void)
{
    s32 eye_slots[2] = {D_800F2B20.eye.pair_slot, D_800F2B20.eye.slot};
    s32 target_slots[2] = {D_800F2B20.target.pair_slot, D_800F2B20.target.slot};
    s32 rate;
    s32 progress;
    Key *key;

    if (func_8005FB08() && D_800F2B20.flags) {
        if (D_800F2B20.duration <= 0xFFFE) {
            s32 next_elapsed;

            rate = func_80058E1C();
            if (D_800F2B20.elapsed < (u16)(D_800F2B20.duration / 5u) ||
                D_800F2B20.elapsed > 4 * D_800F2B20.duration / 5) {
                rate /= 2;
                if (rate < 2)
                    rate = 2;
            }
            next_elapsed = D_800F2B20.elapsed + rate;
            D_800F2B20.elapsed = next_elapsed < D_800F2B20.duration ?
                next_elapsed : D_800F2B20.duration;
        }
        if (eye_slots[0] >= 0) {
            ModelSlot *base = D_800F2C40;
            ModelSlot *slot;
            s32 dx;
            s32 dy;

            slot = base + eye_slots[0];
            dx = (s16)slot->field_DD0[0] - D_800F2B20.eye.start_x;
            dy = (s16)slot->field_DD0[1] - D_800F2B20.eye.start_y;
            D_800F2B20.eye.start_x = D_800F2B20.eye.start_x +
                (dx > 0 ? (dx < 31 ? dx : 30) :
                (dx >= -30 ? dx : -30));
            D_800F2B20.eye.start_y = D_800F2B20.eye.start_y +
                (dy > 0 ? (dy < 31 ? dy : 30) :
                (dy >= -30 ? dy : -30));
        }
        if (eye_slots[1] >= 0) {
            ModelSlot *base = D_800F2C40;
            ModelSlot *slot;
            s32 dx;
            s32 dy;
            s32 dz;

            slot = base + eye_slots[1];
            dx = (s16)slot->field_DD0[0] - D_800F2B20.eye.end_x;
            dy = (s16)slot->field_DD0[1] - D_800F2B20.eye.end_y;
            dz = (s16)slot->field_DD0[2] - D_800F2B20.eye.end_z;
            D_800F2B20.eye.end_x = D_800F2B20.eye.end_x +
                (dx > 0 ? (dx < 31 ? dx : 30) :
                (dx >= -30 ? dx : -30));
            D_800F2B20.eye.end_y = D_800F2B20.eye.end_y +
                (dy > 0 ? (dy < 31 ? dy : 30) :
                (dy >= -30 ? dy : -30));
            D_800F2B20.eye.end_z = D_800F2B20.eye.end_z +
                (dz > 0 ? (dz < 31 ? dz : 30) :
                (dz >= -30 ? dz : -30));
        }
        if (target_slots[0] >= 0) {
            ModelSlot *base = D_800F2C40;
            ModelSlot *slot;
            s32 dx;
            s32 dy;

            slot = base + target_slots[0];
            dx = (s16)slot->field_DD0[0] - D_800F2B20.target.start_x;
            dy = (s16)slot->field_DD0[1] - D_800F2B20.target.start_y;
            D_800F2B20.target.start_x = D_800F2B20.target.start_x +
                (dx > 0 ? (dx < 31 ? dx : 30) :
                (dx >= -30 ? dx : -30));
            D_800F2B20.target.start_y = D_800F2B20.target.start_y +
                (dy > 0 ? (dy < 31 ? dy : 30) :
                (dy >= -30 ? dy : -30));
        }
        if (target_slots[1] >= 0) {
            ModelSlot *base = D_800F2C40;
            ModelSlot *slot;
            s32 dx;
            s32 dy;
            s32 dz;

            slot = base + target_slots[1];
            dx = (s16)slot->field_DD0[0] - D_800F2B20.target.end_x;
            dy = (s16)slot->field_DD0[1] - D_800F2B20.target.end_y;
            dz = (s16)slot->field_DD0[2] - D_800F2B20.target.end_z;
            D_800F2B20.target.end_x = D_800F2B20.target.end_x +
                (dx > 0 ? (dx < 31 ? dx : 30) :
                (dx >= -30 ? dx : -30));
            D_800F2B20.target.end_y = D_800F2B20.target.end_y +
                (dy > 0 ? (dy < 31 ? dy : 30) :
                (dy >= -30 ? dy : -30));
            D_800F2B20.target.end_z = D_800F2B20.target.end_z +
                (dz > 0 ? (dz < 31 ? dz : 30) :
                (dz >= -30 ? dz : -30));
        }
        if (D_800F2B20.flags & 1) {
            D_800F56F0.vpx = (D_800F2B20.eye.end_x - D_800F2B20.eye.start_x) *
                D_800F2B20.elapsed / D_800F2B20.duration + D_800F2B20.eye.start_x;
            D_800F56F0.vpy = (D_800F2B20.eye.end_y - D_800F2B20.eye.start_y) *
                D_800F2B20.elapsed / D_800F2B20.duration + D_800F2B20.eye.start_y;
            D_800F56F0.vpz = (D_800F2B20.eye.end_z - D_800F2B20.eye.start_z) *
                D_800F2B20.elapsed / D_800F2B20.duration + D_800F2B20.eye.start_z;
            if (D_800F56F0.vpy >= -100)
                D_800F56F0.vpy = -100;
        } else if (D_800F2B20.mode) {
            rate = func_80058E1C();
            func_80058434(1, D_800F2B20.field_04 * rate * D_8009AF99, 0, 0, 0);
        }
        if (D_800F2B20.flags & 2) {
            D_800F56F0.vrx = (D_800F2B20.target.end_x - D_800F2B20.target.start_x) *
                D_800F2B20.elapsed / D_800F2B20.duration + D_800F2B20.target.start_x;
            D_800F56F0.vry = (D_800F2B20.target.end_y - D_800F2B20.target.start_y) *
                D_800F2B20.elapsed / D_800F2B20.duration + D_800F2B20.target.start_y;
            D_800F56F0.vrz = (D_800F2B20.target.end_z - D_800F2B20.target.start_z) *
                D_800F2B20.elapsed / D_800F2B20.duration + D_800F2B20.target.start_z;
            if (D_800F56F0.vry >= -100)
                D_800F56F0.vry = -100;
        }
        func_80057F38(0);
        func_80052694(1);
        if (D_800F2B20.elapsed >= D_800F2B20.duration)
            func_80059EBC(1);
        return;
    }
    if (!D_800F2B20.mode)
        return;
    key = (Key *)func_8005FB14();
    if (eye_slots[1] >= 0) {
        ModelSlot *base = D_800F2C40;
        ModelSlot *slot;
        s32 dx;
        s32 dy;
        s32 dz;

        slot = base + eye_slots[1];
        dx = (s16)slot->field_DD0[0] - D_800F56F0.vpx;
        dy = (s16)slot->field_DD0[1] - D_800F56F0.vpy;
        dz = (s16)slot->field_DD0[2] - D_800F56F0.vpz;
        D_800F56F0.vpx = D_800F56F0.vpx +
            (dx > 0 ? (dx < 31 ? dx : 30) :
            (dx >= -30 ? dx : -30));
        D_800F56F0.vpy = D_800F56F0.vpy +
            (dy > 0 ? (dy < 31 ? dy : 30) :
            (dy >= -30 ? dy : -30));
        D_800F56F0.vpz = D_800F56F0.vpz +
            (dz > 0 ? (dz < 31 ? dz : 30) :
            (dz >= -30 ? dz : -30));
        if (D_800F56F0.vpy >= -100)
            D_800F56F0.vpy = -100;
    }
    if (target_slots[1] >= 0) {
        ModelSlot *base = D_800F2C40;
        ModelSlot *slot;
        s32 dx;
        s32 dy;
        s32 dz;

        slot = base + target_slots[1];
        dx = (s16)slot->field_DD0[0] - D_800F56F0.vrx;
        dy = (s16)slot->field_DD0[1] - D_800F56F0.vry;
        dz = (s16)slot->field_DD0[2] - D_800F56F0.vrz;
        D_800F56F0.vrx = D_800F56F0.vrx +
            (dx > 0 ? (dx < 31 ? dx : 30) :
            (dx >= -30 ? dx : -30));
        D_800F56F0.vry = D_800F56F0.vry +
            (dy > 0 ? (dy < 31 ? dy : 30) :
            (dy >= -30 ? dy : -30));
        D_800F56F0.vrz = D_800F56F0.vrz +
            (dz > 0 ? (dz < 31 ? dz : 30) :
            (dz >= -30 ? dz : -30));
        if (D_800F56F0.vry >= -100)
            D_800F56F0.vry = -100;
    }
    if (!key || (key->requested[0].kind != 4 && key->requested[1].kind != 4)) {
        rate = func_80058E1C();
        func_80058434(1, D_800F2B20.field_04 * rate * D_8009AF99, 0, 0, 0);
        func_80052694(1);
    }
    if (D_800F2B20.field_02) {
        ModelCameraMove *move = &D_800F2B20;
        s32 step;

        step = func_80058E1C();
        if (move->field_02 - step > 0) {
            step = func_80058E1C();
            progress = move->field_02 - step;
        } else {
            progress = 0;
        }
        move->field_02 = progress;
    }
}
