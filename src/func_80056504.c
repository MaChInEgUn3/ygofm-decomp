/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/model_load_monster_merge.c (Model_LoadMonsterMerge), profile gcc_2_8_1_g8_split.
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
extern u8 D_80091008[];
void func_80047EC4(void);
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
extern u8 D_800114F8[];
extern u8 D_80011580[];
FileTransferDescriptor *func_80014EEC(
    s32, u8 *, s32, s32, FileTransferCallback, s32, s32
);
void func_800137E4(void);
extern volatile u32 D_8009B0F4_abs __attribute__((section(".data")));
void func_80056D7C(FileTransferDescriptor *object, s32 mode);
void func_80057544(FileTransferDescriptor *object, s32 mode);
void func_800577B0(FileTransferDescriptor *object, s32 mode);
void func_8004CB0C(s32 slot, u8 *hmd, s32 size, s32 flags);
s32 func_80056504(s32 slot, s32 model, s32 p2, s32 p3, s32 p4,
                           s32 p5, s32 arg6)
{
    FileTransferDescriptor *transfer;
    s32 flags;
    s32 result;

    result = 0;
    flags = slot & 0x80;
    slot &= 0x7F;
    if (model < 0) {
        model = D_800F2C40[slot].field_DF8;
    } else {
        D_800F2C40[slot].field_DF8 = model;
    }
    if (flags == 0) {
        func_80047EC4();
    }
    func_800137E4();
    func_8004CB0C(slot, 0, 0, arg6);
    D_800F2C40[slot].field_E1D = flags;
    if (slot < 2) {
        if (model == 0x309 ) {
            transfer = func_80014EEC(
                1, D_800114F8, 0x3B4 ,
                0x113 ,
                func_800577B0, 0, 0
            );
            D_8009B0F4_abs = transfer->status_flags
                | 0x10 ;
            D_800F2C40[slot].field_E14 = 0;
            return 0;
        }
        if (model < 0 || model >= 0x2D2 
            || (model >= 0x12C 
                && model < 0x15E )
            || (model >= 0x28A 
                && model < 0x2BC )
            || model == 0x2D0 ) {
            result++;
        } else {
            if (model >= (0x2D2  - 1) ) {
                model--;
            }
            if (model >= 0x2BC ) {
                model -= (0x15E  - 0x12C ) ;
            }
            if (model >= 0x15E ) {
                model -= (0x15E  - 0x12C ) ;
            }
            transfer = func_80014EEC(
                2, D_80011580, model * 0x114 ,
                0x114 , func_80056D7C,
                0, 0
            );
            if (p2 >= 0) {
                D_800F2C40[slot].field_DFA = p2;
            }
            if (p3 >= 0) {
                D_800F2C40[slot].field_DFC = p3;
            }
            if (p4 >= 0) {
                D_800F2C40[slot].field_DFE = p4 != 0;
            }
            if (p5 >= 0) {
                D_800F2C40[slot].field_DFF = p5 != 0;
            }
            transfer->callback_data = (void *)slot;
            transfer->position = D_800F2C40[slot].field_DFE;
            D_8009B0F4_abs = transfer->status_flags
                | 0x10 ;
            D_800F2C40[slot].field_E14 = 0;
        }
    } else {
        if (model >= 0 && model < 7) {
            model = D_80091008[
                model * 0xB2 
                + 0xA0 ];
            if (model >= 0 && model < 7) {
                goto found;
            }
        }
        result++;
        goto done;
found:
        transfer = func_80014EEC(
            1, D_800114F8,
            model * 0x74  + 0x88 ,
            0x74 , func_80057544, 0, 0
        );
        D_8009B0F4_abs = transfer->status_flags
            | 0x10 ;
        D_800F2C40[slot].field_E14 = 0;
    }
done:
    return result;
}
