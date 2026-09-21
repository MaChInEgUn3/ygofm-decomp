/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/model_texture_transfer.c, profile gcc_2_8_1_g8_split.
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
extern volatile u32 D_8009B0F4_abs __attribute__((section(".data")));
extern u8 D_801DD000[];
extern u8 D_801DE000[];
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
    u32 value[7];
} ModelSlotCF8BlockWords;
typedef struct {
    ModelSlotSoundEntry sound_entries[64 ];
    ModelSlotCF8BlockWords field_CF8;
} ModelTransferMetadata;
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
void func_80059284(s32 index, s32 value);
void func_8005B620(s32 *destination, const s32 *source, u32 count);
typedef struct {
	short x, y;		 
	short w, h;		 
} RECT;
extern int func_80081DE8(RECT *rect, u32 *p);
extern u8 *D_80010000 __attribute__((section(".data")));
extern u8 *D_80010004 __attribute__((section(".data")));
extern u8 *D_8001000C __attribute__((section(".data")));
extern u8 *D_80010010 __attribute__((section(".data")));
extern s32 D_80010014 __attribute__((section(".data")));
extern s32 D_80010018 __attribute__((section(".data")));
extern u8 *D_8009B118 __attribute__((section(".data")));
void func_80056D7C(FileTransferDescriptor *object, s32 mode);
extern u8 D_801A8000[];
void func_80056D7C(FileTransferDescriptor *d, s32 stage)
{
    RECT rect0;
    RECT rect1;
    s32 index;
    s32 alternate;
    ModelSlot *slot;

    index = (s32)d->callback_data;
    alternate = d->position;
    slot = &D_800F2C40[index];
    switch (stage) {
    case 0: {
        u8 *destination;
        if (index == 0) {
            destination = D_80010000;
        } else {
            destination = D_80010004;
        }
        d->value_08 = d->value_0C = (u32)destination;
        d->phase_size = 96 * (1 << 11 ) ;
        D_8009B0F4_abs &= 0xFFDCFFFF;
        d->done = 1;
        break;
    }
    case 1:
        d->field_30.h.counter = index << 8;
        d->field_30.h.field_32 = 0x100;
        d->w = 0x40;
        d->h = 0x10;
        D_8009B0F4_abs &= 0xFFDDFFFF;
        d->phase_size = 48 * (1 << 11 ) ;
        D_8009B0F4_abs |= 0x10000;
        d->done = 2;
        d->value_08 = (u32)D_8009B118;
        d->value_0C = (u32)(D_8009B118 + (1 << 11 ) );
        break;
    case 2:
        d->value_08 = d->value_0C = (u32)D_801DD000;
        d->phase_size = 2 * (1 << 11 ) ;
        D_8009B0F4_abs &= 0xFFDCFFFF;
        d->done = 1;
        break;
    case 3: {
        u32 mask;
        u8 *source;
        RECT *rect;
        do { rect = &rect0; } while (0);
        rect0.x = index << 8;
        rect0.y = 0xF8;
        rect0.w = 0x100;
        rect0.h = 8;
        func_80081DE8(rect, (u32 *)D_801DD000);
        source = D_801DD000;
        do { mask = 0xFFDCFFFF; } while (0);
        source += 2 * (1 << 11 ) ;
        d->value_08 = d->value_0C = (u32)source;
        d->phase_size = (1 << 11 ) ;
        D_8009B0F4_abs &= mask;
        d->done = 1;
        break;
    }
    case 4:
        if (alternate == 0) {
            rect1.x = 0x200;
            rect1.y = index + 0xF2;
            rect1.w = 0x100;
            rect1.h = 1;
            func_80081DE8(&rect1, (u32 *)D_801DE000);
            d->field_30.h.counter = (index << 8) + 0xC0;
            d->w = 0x40;
            d->h = 0x10;
            {
                u32 cleared, loaded, enabled;
                cleared = D_8009B0F4_abs & 0xFFDDFFFF;
                D_8009B0F4_abs = cleared;
                do { loaded = D_8009B0F4_abs; } while (0);
                do { enabled = 0x10000; } while (0);
                d->field_30.h.field_32 = 0x100;
                D_8009B0F4_abs = loaded | enabled;
            }
            d->done = 2;
            d->phase_size = 16 * (1 << 11 ) ;
            d->value_08 = (u32)D_8009B118;
            d->value_0C = (u32)(D_8009B118 + (1 << 11 ) );
        } else {
            d->phase_size = 16 * (1 << 11 ) ;
            D_8009B0F4_abs &= 0xFFFCFFFF;
            D_8009B0F4_abs |= 0x200000;
            d->done = 1;
        }
        break;
    case 6:
        if (alternate == 1) {
            rect1.x = 0x200;
            rect1.y = index + 0xF2;
            rect1.w = 0x100;
            rect1.h = 1;
            func_80081DE8(&rect1, (u32 *)D_801DD000);
            d->field_30.h.counter = (index << 8) + 0xC0;
            d->w = 0x40;
            d->h = 0x10;
            {
                u32 cleared, loaded, enabled;
                cleared = D_8009B0F4_abs & 0xFFDDFFFF;
                D_8009B0F4_abs = cleared;
                do { loaded = D_8009B0F4_abs; } while (0);
                do { enabled = 0x10000; } while (0);
                d->field_30.h.field_32 = 0x100;
                D_8009B0F4_abs = loaded | enabled;
            }
            d->done = 2;
            d->phase_size = 16 * (1 << 11 ) ;
            d->value_08 = (u32)D_8009B118;
            d->value_0C = (u32)(D_8009B118 + (1 << 11 ) );
        } else {
            d->phase_size = 16 * (1 << 11 ) ;
            D_8009B0F4_abs &= 0xFFFCFFFF;
            D_8009B0F4_abs |= 0x200000;
            d->done = 1;
        }
        break;
    case 7:
        if (alternate == 0 && index == 0) {
            d->phase_size = 10 * (1 << 11 ) ;
            D_8009B0F4_abs &= 0xFFDCFFFF;
            d->value_08 = d->value_0C = D_80010014;
            d->done = 1;
        } else {
            d->phase_size = 10 * (1 << 11 ) ;
            D_8009B0F4_abs &= 0xFFFCFFFF;
            D_8009B0F4_abs |= 0x200000;
            d->done = 1;
        }
        break;
    case 8:
        if (alternate == 0 && index == 1) {
            d->phase_size = 10 * (1 << 11 ) ;
            D_8009B0F4_abs &= 0xFFDCFFFF;
            d->value_08 = d->value_0C = D_80010018;
            d->done = 1;
        } else {
            d->phase_size = 10 * (1 << 11 ) ;
            D_8009B0F4_abs &= 0xFFFCFFFF;
            D_8009B0F4_abs |= 0x200000;
            d->done = 1;
        }
        break;
    case 9:
        if (alternate == 1 && index == 0) {
            d->phase_size = 10 * (1 << 11 ) ;
            D_8009B0F4_abs &= 0xFFDCFFFF;
            d->value_08 = d->value_0C = D_80010014;
            d->done = 1;
        } else {
            d->phase_size = 10 * (1 << 11 ) ;
            D_8009B0F4_abs &= 0xFFFCFFFF;
            D_8009B0F4_abs |= 0x200000;
            d->done = 1;
        }
        break;
    case 10:
        if (alternate == 1 && index == 1) {
            d->phase_size = 10 * (1 << 11 ) ;
            D_8009B0F4_abs &= 0xFFDCFFFF;
            d->value_08 = d->value_0C = D_80010018;
            d->done = 1;
        } else {
            d->phase_size = 10 * (1 << 11 ) ;
            D_8009B0F4_abs &= 0xFFFCFFFF;
            D_8009B0F4_abs |= 0x200000;
            d->done = 1;
        }
        break;
    case 11:
        if (index == 0) {
            d->phase_size = 2 * (1 << 11 ) ;
            D_8009B0F4_abs &= 0xFFDCFFFF;
            d->value_08 = d->value_0C = (u32)D_8001000C;
            d->done = 1;
        } else {
            d->phase_size = 2 * (1 << 11 ) ;
            D_8009B0F4_abs &= 0xFFFCFFFF;
            D_8009B0F4_abs |= 0x200000;
            d->done = 1;
        }
        break;
    case 12:
        if (index == 1) {
            d->phase_size = 2 * (1 << 11 ) ;
            D_8009B0F4_abs &= 0xFFDCFFFF;
            d->value_08 = d->value_0C = (u32)D_80010010;
            d->done = 1;
        } else {
            d->phase_size = 2 * (1 << 11 ) ;
            D_8009B0F4_abs &= 0xFFFCFFFF;
            D_8009B0F4_abs |= 0x200000;
            d->done = 1;
        }
        break;
    case 13:
        if (slot->field_E1D != 0) {
            d->phase_size = (1 << 11 ) ;
            D_8009B0F4_abs &= 0xFFFCFFFF;
            D_8009B0F4_abs |= 0x200000;
            d->done = 1;
        } else {
            d->value_08 = d->value_0C =
                (u32)(D_801A8000 + index * (1 << 11 ) );
            d->phase_size = (1 << 11 ) ;
            D_8009B0F4_abs &= 0xFFDCFFFF;
            d->done = 1;
        }
        break;
    case 14:
        if (slot->field_E1D != 0) {
            u32 mask;
            do { mask = 0xFFFCFFFF; } while (0);
            d->phase_size = 50 * (1 << 11 ) ;
            D_8009B0F4_abs &= mask;
            D_8009B0F4_abs |= 0x200000;
            d->done = 1;
        } else {
            d->done = 3;
            d->field_30.word = index * 0x19000 + 0xD810;
            d->phase_size = 50 * (1 << 11 ) ;
            d->value_08 = (u32)D_8009B118;
            d->value_0C = (u32)(D_8009B118 + (1 << 11 ) );
        }
        break;
    case 5:
    case 15:
        d->value_08 = d->value_0C = (u32)D_801DD000;
        d->phase_size = (1 << 11 ) ;
        D_8009B0F4_abs &= 0xFFDCFFFF;
        d->done = 1;
        break;
    case 16: {
        u8 *source;
        source = D_801DD000;
        func_8005B620(
            (s32 *)slot->sound_entries,
            (const s32 *)source,
            64 
        );
        *(ModelSlotCF8BlockWords *)&slot->field_CF8 =
            ((ModelTransferMetadata *)source)->field_CF8;
        if (slot->field_CF8.prefix.values.field_08 & 0x20200000) {
            func_80059284(index, 4);
        }
        if (slot->field_DFA < 0xFFFF) {
            slot->field_CF8.prefix.values.field_00 = slot->field_DFA;
        }
        if (slot->field_DFC < 0xFFFF) {
            slot->field_CF8.prefix.values.field_02 = slot->field_DFC;
        }
        if (slot->field_E1D != 0) {
            slot->field_CF8.field_10 = -1;
            slot->field_CF8.field_14 = -1;
            slot->field_CF8.field_18 = -1;
        }
        slot->field_E14 = 1;
        break;
    }
    }
}
