/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/display_object_render_spotlight_mask.c (DisplayObject_RenderSpotlightMask), profile gcc_2_8_1_g8_split.
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
extern int func_80086770(int a);
extern int func_800866A0(int a);
typedef struct {
	unsigned	addr: 24;
	unsigned 	len:   8;
	u8		r0, g0, b0, code;
} P_TAG;
typedef struct {
	u32	tag;
	u8	r0, g0, b0, code;
	short	x0, 	y0;
	u8	r1, g1, b1, pad1;
	short	x1,	y1;
	u8	r2, g2, b2, pad2;
	short	x2,	y2;
	u8	r3, g3, b3, pad3;
	short	x3,	y3;
} POLY_G4;
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
void func_8005B260(u32 *src, GsOT *ot, s32 idx, s32 flags);
void func_80042C08(DisplayObject *object, GsOT *ot);
void func_80042C08(DisplayObject *object, GsOT *ot)
{
    s32 depth;
    s32 inner;
    s32 outer;
    s32 *radius = (s32 *)0x1F800000;
    s32 *scale = (s32 *)0x1F800010;
    POLY_G4 *poly = (POLY_G4 *)0x1F800020;
    s32 i;
    s32 j;
    s32 cx;
    s32 cy;

    scale[0] = object->field_44.h.field_44;
    scale[1] = object->field_44.h.field_46;
    depth = (s16)object->field_14;
    cx = (s16)object->field_30.h.field_30;
    cy = (s16)object->field_30.h.field_32;
    inner = object->field_48.h.field_48;
    outer = object->field_48.h.field_4A;

    for (i = 0; i < 4; i++) {
        *(u32 *)&poly[i].r0 = 0;
        *(u32 *)&poly[i].r2 = 0;
    }
    for (i = 4; i < 8; i++) {
        *(u32 *)&poly[i].r0 = 0xFFFFFF;
        *(u32 *)&poly[i].r2 = 0xFFFFFF;
    }
    for (i = 0; i < 8; i++) {
        poly[i].y1 = cy;
        poly[i].y0 = cy;
        *(u32 *)&poly[i].r1 = 0xFFFFFF;
        *(u32 *)&poly[i].r3 = 0xFFFFFF;
        (((P_TAG *)(  &poly[i]  ))->len  = (u8)(  8 )) ,  (((P_TAG *)(  &poly[i]  ))->code = (u8)(  0x38 ))  ;
    }

    radius[0] = inner * scale[0] / 4096;
    radius[1] = outer * scale[0] / 4096;
    radius[2] = scale[0] * 240 / 4096;

    poly[3].x0 = poly[1].x0 = radius[0] + cx;
    poly[3].x1 = poly[1].x1 = poly[7].x0 = poly[5].x0 = radius[1] + cx;
    poly[7].x1 = poly[5].x1 = radius[2] + cx;
    poly[2].x0 = poly[0].x0 = cx - radius[0];
    poly[2].x1 = poly[0].x1 = poly[6].x0 = poly[4].x0 = cx - radius[1];
    poly[6].x1 = poly[4].x1 = cx - radius[2];

    for (i = 0x100; i < 0x401; i += 0x100) {
        radius[0] = inner * func_80086770(i) / 4096;
        radius[0] = radius[0] * scale[0] / 4096;
        radius[1] = outer * func_80086770(i) / 4096;
        radius[1] = radius[1] * scale[0] / 4096;
        radius[2] = func_80086770(i) * 240 / 4096;
        radius[2] = radius[2] * scale[0] / 4096;

        poly[3].x2 = poly[1].x2 = radius[0] + cx;
        poly[3].x3 = poly[1].x3 = poly[7].x2 = poly[5].x2 = radius[1] + cx;
        poly[7].x3 = poly[5].x3 = radius[2] + cx;
        poly[2].x2 = poly[0].x2 = cx - radius[0];
        poly[2].x3 = poly[0].x3 = poly[6].x2 = poly[4].x2 = cx - radius[1];
        poly[6].x3 = poly[4].x3 = cx - radius[2];

        radius[0] = inner * func_800866A0(i) / 4096;
        radius[0] = radius[0] * scale[1] / 4096;
        radius[1] = outer * func_800866A0(i) / 4096;
        radius[1] = radius[1] * scale[1] / 4096;
        radius[2] = func_800866A0(i) * 240 / 4096;
        radius[2] = radius[2] * scale[1] / 4096;

        poly[2].y2 = poly[3].y2 = radius[0] + cy;
        poly[2].y3 = poly[3].y3 = poly[6].y2 = poly[7].y2 = radius[1] + cy;
        poly[6].y3 = poly[7].y3 = radius[2] + cy;
        poly[0].y2 = poly[1].y2 = cy - radius[0];
        poly[0].y3 = poly[1].y3 = poly[4].y2 = poly[5].y2 = cy - radius[1];
        poly[4].y3 = poly[5].y3 = cy - radius[2];

        for (j = 0; j < 8; j++) {
            func_8005B260((u32 *)&poly[j], ot, (u16)depth, 2);
            *(s32 *)&poly[j].x0 = *(s32 *)&poly[j].x2;
            *(s32 *)&poly[j].x1 = *(s32 *)&poly[j].x3;
        }
    }
}
