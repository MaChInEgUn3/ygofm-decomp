/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_8003DC1C.c, profile gcc_2_8_1_g8_split.
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
extern int func_8007EF84();
extern int func_8008E870(const char *fmt, ...);
struct DIRENTRY {
	char name[20];
	long attr;
	long size;
	struct DIRENTRY *next;
	long head;
	char system[4];
};
typedef void (*DisplayObjectCallback)(u8 *);
typedef struct DisplayObject {
    s16 previous;                   
    s16 next;                       
    u32 attribute;                  
    u16 flags;                      
    u8 field_0A;                    
    u8 field_0B;                    
    u32 field_0C;                   
    u32 field_10;                   
     









    u16 field_14;                   
    s8 field_16;                    
     









    u8 ot_index;                    
    u16 field_18;                   
    u16 field_1A;                   
    u16 field_1C;                   
    s16 field_1E;                   
     



     




    union {
        u32 word;
        struct {
            u16 field_20;
            u8 field_22;
            u8 field_23;
        } h;
        struct {
            u8 field_20;
            u8 field_21;
            u8 field_22;
            u8 field_23;
        } b;
    } field_20;                     
    DisplayObjectCallback update;   
     



    union {
        struct {
            u16 field_28;
            u16 field_2A;
        } h;
        s32 word;
    } position;                     
     













    union {
        u32 word;
        struct {
            u16 field_2C;
            s16 field_2E;
        } h;
    } field_2C;                     
    union {
        struct {
            u16 field_30;
            u16 field_32;
        } h;
        s32 word;
    } field_30;                     
     











    union {
        u32 word;
        struct {
            s16 field_34;
            s16 field_36;
        } h;
    } field_34;                     
     






























    union {
        u32 word;
        struct {
            s16 field_38;
            s16 field_3A;
        } h;
    } field_38;                     
     

    union {
        s32 word;
        struct {
            u16 field_3C;
            u16 field_3E;
        } h;
    } field_3C;                     
     






    union {
        u32 word;
        struct {
            s16 field_40;
            s16 field_42;
        } h;
    } field_40;                     
     


























    union {
        u32 word;
        struct {
            s16 field_44;
            s16 field_46;
        } h;
    } field_44;                     
    union {
        u32 word;
        struct {
            s16 field_48;
            s16 field_4A;
        } h;
    } field_48;                     
     



















    s32 field_4C;                   
     

















     







    union {
        s32 word;
        struct {
            s16 field_50;
            s16 field_52;
        } h;
    } field_50;                     
    void *field_54;                 
     






    s16 field_58;                   
    s16 field_5A;                   
    u16 field_5C;                   
    u16 field_5E;                   
     







    s16 field_60;                   
    u8 pad_62[2];                   
     




    u8 field_64;                    
    u8 field_65;                    
    u8 field_66;                    
     


    u8 field_67;                    
     








    u8 field_68;                    
     


    u8 field_69;                    
     


    u8 field_6A;                    
     



    u8 field_6B;                    
    u8 field_6C;                    
    u8 pad_6D[0x70  - 0x6D];
} DisplayObject;
s32 func_8004413C(s32 channel);
s32 func_800441DC(s32 channel, s32 name, s32 buffer, s32 offset, s32 size);
s32 func_800442E4(s32 channel, s32 name, s32 buffer, s32 offset, s32 size);
s32 func_80044278(s32 channel, s32 buffer, s32 sector);
s32 func_80044380(s32 channel, s32 buffer, s32 sector);
s32 func_800443EC(s32 channel, s32 name, s32 blocks);
s32 func_80044838(s32 mode, s32 *request, s32 *result);
extern u8 D_80010384[];
s32 func_80044CD4(u8 *name);
extern struct DIRENTRY *D_8009B444 __attribute__((section(".data")));
extern s32 D_8009B440 __attribute__((section(".data")));
extern s32 D_8009B438 __attribute__((section(".data")));
typedef struct {
    u8 *cursor;
    u8 pad_04[8];
    u8 free_blocks;
    u8 entry_index;
    u8 pad_0E[0x25A];
} MemCardWorkSlot;
typedef struct {
    u8 pad_00[0x10];
    u8 blocks;
    u8 pad_11;
    s16 remaining;
    u16 offset;
    s16 chunk;
    u16 field_18;
    u8 text_index;
    u8 pad_1B;
} MemCardWorkRoot;
typedef struct {
    MemCardWorkRoot root;
    MemCardWorkSlot slots[2 ];
} MemCardWorkArea;
extern MemCardWorkArea D_800EF6D0;
extern u16 D_8009B3CC;
extern u8 D_8009B3CF;
extern u8 D_8009B3DD;
extern u8 D_8009B3D5;
extern s32 D_8009B3C8;
extern s32 D_8009B3E4;
extern void (*D_80090F88[5 ])(
    MemCardWorkRoot *root, MemCardWorkSlot *slot
);
extern u8 D_8021007A __attribute__((section(".data")));
extern u8 D_8021007B __attribute__((section(".data")));
extern u8 D_8021007C __attribute__((section(".data")));
extern u8 D_8021007D __attribute__((section(".data")));
extern u8 D_8021007E __attribute__((section(".data")));
extern u8 D_8021007F __attribute__((section(".data")));
extern char D_8009AF6C[];
extern char D_80010378[];
extern char D_80010398[];
extern char D_800103A4[];
void func_8003DC1C(void);
void func_80043E30(long val);
void func_80043EBC(void);
typedef struct {
    u16 code_00;
    u16 pad_02;
    s32 field_04;
    s32 field_08;
    s16 x_0C;
    s16 y_0E;
    u8 field_10;
    u8 flags_11;
    u8 field_12;
    u8 field_13;
    u8 pad_14;
    u8 field_15;
     
    u8 field_16;
    u8 field_17;
    u8 field_18;
    u8 pad_19[3];
} DuelEffectEntry;
struct DuelEffectChannel;
struct DisplayObject;
typedef struct DuelEffectChannel {
    u8 *text_00;
     










    u8 field_04;
    u8 field_05;
    u8 field_06;
    u8 field_07;
    u8 field_08;
    u8 field_09;
    u8 field_0A;
    u8 pad_0B;
    u16 field_0C;
    u16 field_0E;
     



    u8 field_10;
    u8 field_11;
    u8 pad_12;
    u8 field_13;
    u8 field_14;
    u8 field_15;
    u8 pad_16[10];
    DuelEffectEntry *entry_end_20;
    DuelEffectEntry *entry_head_24;
     



    struct DisplayObject *field_28;
     



    struct DisplayObject *field_2C;
    struct DisplayObject *field_30;
    u16 flags_34;
    u16 field_36;
    u16 field_38;
    u16 field_3A;
    s16 field_3C;
    s16 field_3E;
    s16 field_40;
    s16 field_42;
     

    u8 text_44[0x0D];
     

    u8 state_51;
     

    u8 delay_52;
    u8 field_53;
    u8 field_54;
    u8 pad_55;
    u8 field_56;
    u8 index_57;
     

    s8 stream_58;
    u8 field_59;
    u8 field_5A;
    u8 field_5B;
    u16 range_start_5C;
    u16 range_count_5E;
    u8 field_60;
    u8 field_61;
     


    u8 field_62;
    u8 pad_63;
} DuelEffectChannel;
extern DuelEffectChannel D_800EB0F8[4 ];
extern u8 D_8009B3C1;
extern u8 D_8009B3C7;
DuelEffectChannel *func_8003D46C(s32 value, s32 set_flags);
extern s8 D_8009B34D __attribute__((section(".data")));
void func_80039794(void);
void func_800356A0(u8 *destination, u8 *source, u32 length);
void func_80035748(u8 *destination, s32 value, u32 length);
extern u8 D_801D4000[];
void func_8003DC1C(void)
{
    MemCardWorkRoot *root = &D_800EF6D0.root;
    MemCardWorkSlot *slot = &D_800EF6D0.slots[D_8009B3DD];
    s32 zero = 0;
    s32 status;
    s32 index;
    s32 offset;
    s32 remaining;
    u8 *cursor;
    s32 message;
    s32 checksum;
    u8 *name;

    if (D_8009B3CC & 0x2000) {
        index = zero;
        if (index < D_8009B440) {
            do {
                func_8007EF84(D_8009AF6C, &D_8009B444[index]);
                index++;
            } while (index < D_8009B440);
        }
        func_8007EF84(D_80010378, slot->free_blocks);
    }
    status = -1;
    if (D_8009B3CC & 0x4000)
        status = func_80044838(1, &D_8009B3E4, &D_8009B3C8);
    if ((D_8009B3CC & 0x1000) && status != 0 && status == 1) {
        switch (D_8009B3E4) {
        case 2:
            D_8009B3CC |= 0x2000;
            switch (D_8009B3C8) {
            case 3:
                D_8009B3CC |= 0x800;
            case 0:
                slot->free_blocks = (u8)D_8009B438;
                goto success;
            case 4:
                D_8009B3CC |= 2;
                D_8009B3D5 = 1;
                break;
            case 1:
            default:
                D_8009B3D5 = 2;
                break;
            }
            break;
        case 3:
            if (D_8009B3C8 == 0) {
                index = root->chunk;
                remaining = (u16)root->remaining - index;
                root->remaining = remaining;
                if ((s32)((u32)remaining << 16) > 0) {
                    slot->cursor += index;
                    root->offset += index;
                    if (root->remaining < root->chunk)
                        root->chunk = (u16)root->remaining;
                } else {
                    D_8009B3D5 = 0;
                }
            } else {
                D_8009B3D5 = 1;
            }
            break;
        case 4:
            if (D_8009B3C8 == 0) {
                index = root->chunk;
                remaining = (u16)root->remaining - index;
                root->remaining = remaining;
                if ((s32)((u32)remaining << 16) > 0) {
                    slot->cursor += index;
                    root->offset += index;
                    if (root->remaining < root->chunk)
                        root->chunk = (u16)root->remaining;
                } else {
                    D_8009B3D5 = 0;
                }
            } else {
                D_8009B3D5 = 1;
            }
            break;
        case 8:
        case 11:
        case 12:
            D_8009B3D5 = 1;
            if (D_8009B3C8)
                break;
success:
            D_8009B3D5 = 0;
            break;
        }
    }
    if (D_8009B3C1 & 0xF) {
        status = 1;
        D_80090F88[D_8009B3C1 & 0xF](root, slot);
    }
    if (status >= 0)
        return;
    if (D_8009B3CC & 0x400) {
        DuelEffectChannel *text = &D_800EB0F8[root->text_index];
        func_80039794();
        if ((*(u32 *)&text->flags_34 & 0x2008) == 0x2000)
            D_8009B3CC &= ~0x400;
        return;
    }
    switch (D_8009B3CF & 0xF) {
    case 0:
        if (!(D_8009B3CF & 0x80)) {
            D_8009B3CF |= 0x80;
            D_8009B3C1 = 1;
            break;
        }
        if (D_8009B34D) {
            D_8009B3C1 = 2;
            break;
        }
        func_80043E30(1);
        func_80043EBC();
        D_8009B3CF = 1;
        D_8009B3CC |= 0x4000;
    case 1:
        if (!(D_8009B3CF & 0x80)) {
            D_8009B3CF |= 0x80;
            D_8009B3CC |= 0x1000;
            func_8004413C(zero);
            break;
        }
        D_8009B3CF = 4;
    case 4:
        if (!(D_8009B3CC & 0x2000))
            break;
        D_8009B3CC &= ~0x1000;
        if (D_8009B3D5 == 2) {
            message = 0xD2;
            goto show_message;
        }
        if (!(D_8009B3C7 & 1))
            D_8009B3CF = 5;
        else
            D_8009B3CF = 7;
        break;
    case 5:
        if (!(D_8009B3CF & 0x80)) {
            D_8009B3CF |= 0x80;
            index = func_80044CD4(D_80010384);
            if (index < 0 || (D_8009B3CC & 2)) {
                message = 0xD3;
                goto show_message;
            }
            func_80044278(zero, 0x80210000 ,
                D_8009B444[index].head / 64);
            break;
        }
        if (D_8009B3D5) {
            message = 0xD8;
            goto show_message;
        }
        D_8009B3CF = 6;
    case 6:
        if (!(D_8009B3CF & 0x80)) {
            D_8009B3CF |= 0x80;
            name = D_80010384;
            index = func_80044CD4(name);
            message = 0xD3;
            if (index < 0 || (D_8009B3CC & 2))
                goto show_message;
            func_8003D46C(0x80D5, 0);
            slot->entry_index = index;
            D_8009B3CC |= 0x1000;
            func_800441DC(
                zero,
                (s32)name,
                0x80200000 ,
                0x200 ,
                8192  - 0x200 
            );
            break;
        }
        message = 0xD7;
        if (D_8009B3D5 == 1)
            message = 0xD8;
        goto show_message;
    case 7: {
        s32 wait;
        s32 result;
        if (!(D_8009B3CF & 0x80)) {
            D_8009B3CF |= 0x80;
            if (D_8009B3CC & 2) {
                D_8009B3CF = 9;
                break;
            }
            name = D_80010384;
            if (func_80044CD4(name) < 0) {
                D_8009B3CF = 10;
                break;
            }
            func_8003D46C(0x80D6, 0);
            func_800356A0(
                (u8 *)0x80300000 ,
                D_801D4000,
                0x200 
            );
            func_80035748(
                (u8 *)0x80300200 ,
                0x86,
                (1 << 11 ) 
            );
            func_800442E4(
                zero,
                (s32)name,
                0x80300000 ,
                0,
                0x200  + (1 << 11 ) 
            );
            D_8009B3CC |= 0x1000;
            break;
        }
        result = D_8009B3D5;
        if (result == 1) {
            message = 0xD9;
            wait = result;
        } else {
            message = 0xD7;
            wait = 1;
            D_8009B3CF = 8;
        }
        func_8003D46C(message, wait);
        remaining = D_8009B3CC | 0x400;
        D_8009B3CC = remaining;
        remaining = 8;
        D_8009B3CF = remaining;
    }
    case 8:
        if (!(D_8009B3CF & 0x80)) {
            s32 i;
            s32 sector;
            D_8009B3CF |= 0x80;
            index = func_80044CD4(D_80010384);
            checksum = 0;
            i = 0;
            D_8021007E = 1;
            D_8021007D = 255;
            D_8021007C = 255;
            D_8021007B = 255;
            D_8021007A = 255;
            do {
                checksum ^= (*(u8 (*)[128 ])0x80210000 ) [i];
                i++;
            } while (i < 0x7F);
            sector = D_8009B444[index].head;
            D_8021007F = checksum;
            if (sector < 0)
                sector += 63;
            func_80044380(zero, 0x80210000 , sector >> 6);
            break;
        }
        if (!D_8009B3D5)
            break;
        message = 0xD9;
show_message:
        func_8003D46C(message, 1);
        D_8009B3CC |= 0x400;
        break;
    case 9:
    case 10:
        if (!(D_8009B3CF & 0x80)) {
            D_8009B3CF |= 0x80;
            if (slot->free_blocks >= root->blocks)
                func_800443EC(zero, (s32)D_80010384, root->blocks);
            break;
        }
        if (!D_8009B3D5)
            func_8008E870(D_80010398);
        func_8008E870(D_800103A4);
        break;
    }
}
