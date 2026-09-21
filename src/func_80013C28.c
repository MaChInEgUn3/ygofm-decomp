/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/file_transfer_runtime.c (File_TransferReadyCallback), profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef void (*CdlCB)(u8,u8 *);
int func_8007E3D0(void *madr, int size);
CdlCB func_8007E860(CdlCB func);
void func_8007DDD4( void );
typedef struct {
	short x, y;		 
	short w, h;		 
} RECT;
extern int func_80081DE8(RECT *rect, u32 *p);
extern unsigned long func_80077150 (unsigned char *addr, unsigned long size);
extern unsigned long func_800771B0 (unsigned long addr);
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
void func_80013C28(s32);
extern volatile u32 D_8009B0F4;
extern FileTransferDescriptor *D_8009AF18;
extern u32 *D_8009B0F8;
extern u8 D_8009B114;
extern s32 D_8009B138;
void func_80013C28(s32 event);
void func_80013C28(s32 arg)
{
    s32 event;
    s32 remaining;
    FileTransferDescriptor *transfer;
    FileTransferDescriptor *p;
    FileTransferDescriptor *q;
    FileTransferDescriptor *r;
    FileTransferDescriptor *image;
    FileTransferDescriptor *counter;
    FileTransferDescriptor *t;
    u8 *dst;
    u32 *src;
    u32 word;
    s32 i;
    s32 n;
    s32 image_y;

    event = arg & 0xFF;
    D_8009B114++;
    if (event != 1) {
        return;
    }
    D_8009B138 = (s32)((u32)D_8009B138 + 1);
    p = D_8009AF18;
    switch (p->done) {
    case 1:
        if ((D_8009B0F4 & 0x200000) == 0) {
            if ((D_8009B0F4 & 0x40000000) == 0) {
                func_8007E3D0(
                    (void *)p->value_08,
                    (1 << 11 )  / sizeof(u32)
                );
            } else {
                i = 0;
                t = p;
                src = D_8009B0F8;
                do {
                    word = src[i];
                    ((u32 *)t->value_08)[i] = word;
                    i++;
                } while (i < (s32)((1 << 11 )  / sizeof(u32)));
            }
            D_8009AF18->value_08 += (1 << 11 ) ;
        }
        transfer = D_8009AF18;
        remaining = transfer->total_bytes;
        D_8009B0F8 += (1 << 11 )  / sizeof(u32);
        remaining -= (1 << 11 ) ;
        transfer->total_bytes = remaining;
        if (remaining <= 0) {
            func_8007DDD4();
            func_8007E860(0);
        }
        q = D_8009AF18;
        q->phase_remaining -= (1 << 11 ) ;
        if (q->phase_remaining <= 0) {
            q->phase_size = 0;
            if (q->phase_callback != 0) {
                q->phase_callback(q, q->result++);
            }
            q->phase_remaining = q->phase_size;
        }
        if (D_8009AF18->total_bytes <= 0) {
            goto clear;
        }
        return;
    case 2:
         




        dst = (u8 *)*(u32 *)(
            (u32)p + ((p->buffer_index & 1) << 2) +
            (u32)&((FileTransferDescriptor *)0)->value_08
        );
        if ((D_8009B0F4 & 0x40000000) == 0) {
            func_8007E3D0(dst, (1 << 11 )  / sizeof(u32));
        } else {
            src = D_8009B0F8;
            for (i = 0; i < (s32)((1 << 11 )  / sizeof(u32)); ++i) {
                ((u32 *)dst)[i] = src[i];
            }
            D_8009B0F8 += (1 << 11 )  / sizeof(u32);
        }
        D_8009AF18->total_bytes -= (1 << 11 ) ;
        if (D_8009AF18->total_bytes <= 0) {
            func_8007DDD4();
            func_8007E860(0);
        }
        image = D_8009AF18;
        image->x = image->field_30.h.counter;
        image->y = image->field_30.h.field_32;
        while (func_80081DE8((RECT *)D_8009AF18, (u32 *)dst)) {
        }
        if ((D_8009B0F4 & 0x20000) != 0) {
            D_8009AF18->field_30.h.counter += 0x40;
        } else {
            r = D_8009AF18;
            image_y = r->field_30.h.field_32 + 0x10;
            r->field_30.h.field_32 = image_y;
            if ((image_y & 0xFF) == 0) {
                r->field_30.h.field_32 = (image_y ^ 0x100) & 0x100;
                r->field_30.h.counter += 0x40;
            }
        }
        q = D_8009AF18;
        q->phase_remaining -= (1 << 11 ) ;
        if (q->phase_remaining > 0) {
            goto counter;
        }
        goto step;
    case 3:
        n = (1 << 11 ) ;
        dst = (u8 *)p->value_08;
        if (p->phase_remaining < n) {
            n = p->phase_remaining;
        }
        if ((D_8009B0F4 & 0x40000000) == 0) {
            func_8007E3D0(dst, n / 4);
        } else {
            src = D_8009B0F8;
            for (i = 0; i < n / 4; ++i) {
                ((u32 *)dst)[i] = src[i];
            }
            D_8009B0F8 = (u32 *)((u8 *)D_8009B0F8 + n);
        }
        D_8009AF18->total_bytes -= (1 << 11 ) ;
        if (D_8009AF18->total_bytes <= 0) {
            func_8007DDD4();
            func_8007E860(0);
        }
        func_800771B0(D_8009AF18->field_30.word);
        func_80077150(dst, (u32)n);
        q = D_8009AF18;
        q->field_30.word += n;
        q->phase_remaining -= (1 << 11 ) ;
        if (q->phase_remaining > 0) {
            goto counter;
        }
    step:
        q->phase_size = 0;
        if (q->phase_callback != 0) {
            q->phase_callback(q, q->result++);
        }
        q->phase_remaining = q->phase_size;
    counter:
        counter = D_8009AF18;
        counter->buffer_index++;
        if (counter->total_bytes > 0) {
            return;
        }
    clear:
        D_8009B0F4 &= ~0x100;
        return;
    }
}
