/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/card_list_render_deck_box_stats.c (CardList_RenderDeckBoxStats), profile gcc_2_8_1_g0_split.
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
extern u8 D_80090DD8[];
void func_800357E8(s32 arg0, s32 arg1, u8 *arg2);
typedef struct {
	unsigned p:24;
	unsigned char num:8;
}       GsOT_TAG;
typedef struct {
	unsigned long length;
	GsOT_TAG *org;
	unsigned long offset;
	unsigned long point;
	GsOT_TAG *tag;
}       GsOT;
typedef struct {
	unsigned long attribute;
	short   x, y;
	unsigned short w, h;
	unsigned short tpage;
	unsigned char u, v;
	short   cx, cy;
	unsigned char r, g, b;
	short   mx, my;
	short   scalex, scaley;
	long    rotate;
}       GsSPRITE;
void    func_800849F0(GsSPRITE * sp, GsOT * ot, unsigned short pri);
extern s32 D_801D4244[];
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
void func_80060B38(DisplayObject *obj, GsOT *ot);
typedef struct {
    u8 pad_00[0x04];
    u32 attribute;
    u16 flags;
    u8 pad_0A[0x02];
    u32 color;
    void *field_10;
    u8 pad_14[0x0D];
    u8 field_21;
    u8 field_22;
    u8 pad_23[0x0D];
    s16 out_x;
    s16 out_y;
    s16 field_34;
    u8 pad_36[0x0C];
    u16 icon_variant;
    u8 pad_44[0x08];
    void *field_4C;
    u8 pad_50[0x0C];
    u8 icon_state;
    u8 field_5D;
    u8 pad_5E[0x09];
    u8 field_67;
    u8 field_68;
    u8 field_69;
    u8 card_index;
    u8 field_6B;
} DuelCardDisplayObject;
typedef struct {
    DuelCardDisplayObject *object;
    s16 x;
    s16 y;
    u16 enabled;
    u16 card_entries[7];
} CardListRowSet;
extern CardListRowSet D_801A8000[];
void func_80060B38(DisplayObject *obj, GsOT *ot) {
    u8 atk[8];
    u8 def[8];
    GsSPRITE *sp;
    u8 *tbl;
    CardListRowSet *rec;
    u16 *entries;
    s32 pri;
    s32 i;
    s32 j;
    s32 id;
    u8 d;

    tbl = D_80090DD8;
    sp = (GsSPRITE *)0x1F800320;
    rec = &D_801A8000[obj->field_6A];
    pri = *(s16 *)&obj->field_14;
    sp->attribute = obj->attribute;
    sp->tpage = 0xB;
    (*(u32 *)&( sp )->r)  = 0x808080 ;
    *(u32 *)&sp->w = 0x100010;
    sp->x = obj->field_30.h.field_30 + 0x22;
    sp->y = obj->field_30.h.field_32 - 0x18;
    sp->cy = 0xFB;
    i = 0;
    do {
        (*(u32 *)&( sp )->r)  = 0x202020;
        if (i == obj->field_69) {
            (*(u32 *)&( sp )->r)  = 0x808080 ;
        }
        sp->u = (tbl[0] & 0xF) * 8 - 0x80;
        sp->v = tbl[0] & 0xF0;
        sp->cx = (tbl[1] & 0xF0) | 0x200;
        func_800849F0(sp, ot, pri);
        sp->x += 0x14;
        i++;
        tbl += 2;
    } while (i < 6);

    if (rec->enabled != 0) {
        sp->attribute = obj->attribute;
        sp->x = obj->field_30.h.field_30 + 0x24;
        *(u32 *)&sp->w = 0x80008;
        entries = rec->card_entries;
        sp->y = obj->field_30.h.field_32;
        sp->tpage = 0xB;
        sp->cx = 0x290;
        sp->cy = 0xFA;
        sp->u = 0x80;
        sp->v = 0x70;
        i = 0;
        do {
            id = *entries & 0xFFF;
            if (id != 0) {
                if (((D_801D4244[id - 1] >> 26 ) &
                     0x1F ) < 20 ) {
                    sp->x = obj->field_30.h.field_30 + 0x24;
                    (*(u32 *)&( sp )->r)  = 0x808080 ;
                    if (*entries & 0x8000) {
                        (*(u32 *)&( sp )->r)  = 0x404040 ;
                    }
                    func_800357E8(
                        (D_801D4244[id - 1] & 0x1FF ) *
                            10 ,
                        4, atk);
                    func_800357E8(
                        ((D_801D4244[id - 1] >> 9 ) &
                         0x1FF ) * 10 ,
                        4, def);
                    for (j = 3; j >= 0; j--) {
                        d = atk[j];
                        if (d < 10 ) {
                            sp->u = d * 8 - 0x80;
                            func_800849F0(sp, ot, pri);
                        }
                        if (def[j] < 10 ) {
                            sp->y += 8;
                            sp->u = def[j] * 8 - 0x80;
                            func_800849F0(sp, ot, pri);
                            sp->y -= 8;
                        }
                        sp->x += 8;
                    }
                }
            }
            i++;
            sp->y += 0x16;
            entries++;
        } while (i < 7);
    }
}
