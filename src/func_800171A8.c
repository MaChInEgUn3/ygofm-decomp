/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/duel_load_package_stage.c (Duel_LoadPackageStage), profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern u16 D_801799D8[];
typedef struct {
	short x, y;		 
	short w, h;		 
} RECT;
extern int func_80081DE8(RECT *rect, u32 *p);
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
extern RECT D_800E9D70[2];
extern u8 *D_8009B118 __attribute__((section(".data")));
extern u16 D_8017A1D8[];
extern u16 D_8017C2D8[];
void func_800171A8(FileTransferDescriptor *d, s32 stage);
extern u8 D_801A8000[];
extern u8 D_801A9800[];
extern u8 *D_80010000 __attribute__((section(".data")));
extern u8 *D_800101DC __attribute__((section(".data")));
void func_800171A8(FileTransferDescriptor *d, s32 stage)
{
    u32 flags;
    u32 mask;

    switch (stage) {
    case 0:
        d->field_30.h.counter = 0x300;
        d->field_30.h.field_32 = 0x100;
        d->w = 0x40;
        d->h = 0x10;
        D_8009B0F4_abs &= 0xFFDDFFFF;
        D_8009B0F4_abs |= 0x10000;
        d->done = 2;
        d->phase_size = 64 * (1 << 11 ) ;
        d->value_08 = (u32)D_8009B118;
        d->value_0C = (u32)(D_8009B118 + (1 << 11 ) );
        break;
    case 1:
        d->phase_size = 4 * (1 << 11 ) ;
        D_8009B0F4_abs &= 0xFFDCFFFF;
        d->value_08 = d->value_0C = (u32)D_8009B118;
        d->done = 1;
        break;
    case 2:
        D_800E9D70[0].x = 0x100;
        D_800E9D70[0].y = 0xF0;
        D_800E9D70[0].w = 0x100;
        D_800E9D70[0].h = 0x10;
        func_80081DE8(&D_800E9D70[0], (u32 *)D_8009B118);
        d->value_08 = d->value_0C = (u32)D_8017A1D8;
        d->phase_size = 5 * (1 << 11 ) ;
        D_8009B0F4_abs &= 0xFFDCFFFF;
        d->done = 1;
        break;
    case 3:
        d->value_08 = d->value_0C = (u32)D_8017C2D8;
        d->phase_size = 32 * (1 << 11 ) ;
        D_8009B0F4_abs &= 0xFFDCFFFF;
        d->done = 1;
        break;
    case 4:
        d->value_08 = d->value_0C = (u32)D_801799D8;
        d->phase_size = (1 << 11 ) ;
        D_8009B0F4_abs &= 0xFFDCFFFF;
        d->done = 1;
        break;
    case 5:
        d->phase_size = 2 * (1 << 11 ) ;
        D_8009B0F4_abs &= 0xFFDCFFFF;
        d->value_08 = d->value_0C = (u32)D_8009B118;
        d->done = 1;
        break;
    case 6: {
        u32 flags;
        D_800E9D70[0].x = 0;
        D_800E9D70[0].y = 0xF0;
        D_800E9D70[0].w = 0x100;
        D_800E9D70[0].h = 8;
        func_80081DE8(&D_800E9D70[0], (u32 *)D_8009B118);
        d->field_30.h.counter = 0x200;
        d->field_30.h.field_32 = 0x100;
        d->w = 0x40;
        mask = 0xFFDDFFFF;
        flags = D_8009B0F4_abs & mask;
        {
             
            u8 *image_ptr;

            D_8009B0F4_abs = flags;
            mask = 0x10000;
            d->phase_size = mask;
            D_8009B0F4_abs |= mask;
            d->done = 2;
            d->h = 0x10;
            image_ptr = D_8009B118;
            d->value_08 = (u32)image_ptr;
            d->value_0C = (u32)(image_ptr + (1 << 11 ) );
            break;
        }
    }
    case 7:
        mask = 0xFFDCFFFF;
        d->phase_size = 44 * (1 << 11 ) ;
        D_8009B0F4_abs &= mask;
        d->value_08 = d->value_0C = (u32)D_800101DC;
        d->done = 1;
        break;
    case 8:
        d->value_08 = d->value_0C = (u32)D_801A8000;
        d->phase_size = 3 * (1 << 11 ) ;
        D_8009B0F4_abs &= 0xFFDCFFFF;
        d->done = 1;
        break;
    case 9:
        d->value_08 = d->value_0C = (u32)D_801A9800;
        d->phase_size = 3 * (1 << 11 ) ;
        D_8009B0F4_abs &= 0xFFDCFFFF;
        d->done = 1;
        break;
    case 10: {
        u32 cleared;
        u32 loaded;
        u32 enabled;
        d->field_30.h.counter = 0x340;
        d->w = 0x40;
        d->h = 0x10;
        cleared = D_8009B0F4_abs & 0xFFDDFFFF;
        D_8009B0F4_abs = cleared;
        do { loaded = D_8009B0F4_abs; } while (0);
        do { enabled = 0x10000; } while (0);
        d->field_30.h.field_32 = 0;
        D_8009B0F4_abs = loaded | enabled;
        d->done = 2;
        d->phase_size = 8 * (1 << 11 ) ;
        d->value_08 = (u32)D_8009B118;
        d->value_0C = (u32)(D_8009B118 + (1 << 11 ) );
        break;
    }
    case 11:
        d->phase_size = 5 * (1 << 11 ) ;
        D_8009B0F4_abs &= 0xFFDCFFFF;
        d->value_08 = d->value_0C = (u32)D_80010000;
        d->done = 1;
        break;
    case 12: {
        u32 flags;
        d->field_30.h.counter = 0x280;
        d->field_30.h.field_32 = 0x100;
        d->w = 0x40;
        mask = 0xFFDDFFFF;
        flags = D_8009B0F4_abs & mask;
        {
             
            u8 *image_ptr;

            D_8009B0F4_abs = flags;
            mask = 0x10000;
            d->phase_size = mask;
            D_8009B0F4_abs |= mask;
            d->done = 2;
            d->h = 0x10;
            image_ptr = D_8009B118;
            d->value_08 = (u32)image_ptr;
            d->value_0C = (u32)(image_ptr + (1 << 11 ) );
            break;
        }
    }
    }
}
