/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/duel_card_data_transfer.c (Duel_StepCardDataTransfer), profile gcc_2_8_1_g0_no_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
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
extern volatile u32 D_8009B0F4;
void func_800245EC(FileTransferDescriptor *, s32);
void func_800245EC(FileTransferDescriptor *o, int mode) {
    s16 *p = o->callback_data;

    if (mode == 0) {
        o->field_30.h.counter = *p;
        o->phase_size = (1 << 11 ) ;
        D_8009B0F4 &= ~0x230000;
        o->value_08 = o->value_0C = o->position;
        o->done = 1;
        return;
    }
    if (mode == 1) {
        p++;
        o->callback_data = p;
        o->position += 0x580 ;
    }
    o->field_30.h.counter++;
    if (o->field_30.h.counter == *p) {
        o->phase_size = (1 << 11 ) ;
        o->result = 1;
        D_8009B0F4 &= ~0x230000;
        o->value_08 = o->value_0C = o->position;
        o->done = 1;
    } else {
        o->phase_size = (1 << 11 ) ;
        o->result = 2;
        D_8009B0F4 &= ~0x30000;
        D_8009B0F4 |= 0x200000;
        o->done = 1;
    }
}
