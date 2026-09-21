/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/campaign_load_scene_package.c (Campaign_LoadScenePackage), profile gcc_2_8_1_g8_split.
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
typedef struct {
    s32 unk00;
    s16 unk04;
    s16 unk06;
    s32 unk08;
    s32 unk0C;
    s32 unk10;
} SceneScriptSlot;
struct DisplayObject;
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
extern SceneScriptSlot D_800EAE98[];
FileTransferDescriptor *func_80014E1C(
    s32, u8 *, s32, s32, FileTransferCallback, s32, s32
);
void func_800137E4(void);
typedef struct {
	short x, y;		 
	short w, h;		 
} RECT;
extern int func_80082324(int max_count);
extern int func_80081DE8(RECT *rect, u32 *p);
extern RECT D_800E9D70[2];
extern s16 D_8009B146 __attribute__((section(".data")));
extern s16 D_8009B148 __attribute__((section(".data")));
s8 *func_80039E9C(void);
struct DisplayObject;
extern u16 D_8009B2A4;
void func_8002FD10(s16 arg0);
void func_8002FB78(
    FileTransferDescriptor *descriptor, s32 stage
);
extern DisplayObject *D_8009B2A0;
DisplayObject *func_8002E3FC(void);
extern u8 *D_80010000 __attribute__((section(".data")));
void func_8002FD10(s16 arg0)
{
    SceneScriptSlot *slot;
    u32 *src;
    RECT *second;
    s32 i;

    slot = D_800EAE98;
    D_8009B2A4 = arg0;
    D_8009B148 = 0;
    D_8009B146 = 0;
    D_8009B2A0 = 0;
    func_80014E1C(
        0, 0,
        0x1E57 ,
        0x31 ,
        func_8002FB78, 0, 0
    );
    func_80039E9C();

    (*(s16 *)( &slot[3] ))  = -1;
    for (i = 0; i < 3; i++) {
        slot[i].unk00 = 0;
        slot[i].unk04 = 0;
    }
    func_800137E4();

    while (func_80082324(10)) {
        ;
    }

    src = ((u32 *)( D_80010000 )) ;
    D_800E9D70[0].x = 0x380;
    D_800E9D70[0].y = 0;
    D_800E9D70[0].w = (48  / 2) ;
    D_800E9D70[0].h = 48 ;
    second = &D_800E9D70[1];
    D_800E9D70[1].x = 0x380;
    second->y = 0xF0;
    second->w = 0x40 ;
    second->h = 1;

    i = 0;
    do {
        func_80081DE8(&D_800E9D70[0], src);
        func_80081DE8(
            &D_800E9D70[1],
            src + 0x900  / sizeof(u32)
        );
        i++;
        D_800E9D70[1].y = D_800E9D70[1].y + 1;
        D_800E9D70[0].x =
            (i % 5 ) *
                (48  / 2)  + 0x380;
        D_800E9D70[0].y =
            (i / 5 ) *
                48 ;
        if (D_800E9D70[1].y >=
            0xF0 + 16 ) {
            D_800E9D70[1].x =
                D_800E9D70[1].x +
                0x40 ;
            D_800E9D70[1].y = 0xF0;
        }
        src += (0x900  + 0x80 )  / sizeof(u32);
    } while (i < 25 );

    D_8009B2A0 = func_8002E3FC();
}
