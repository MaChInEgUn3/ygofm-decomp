/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_80029934.c, profile gcc_2_8_1_g8_split_psyq_rtps_no_cse_skip_blocks.
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
typedef struct  {
	short	m[3][3];	 
        long    t[3];		 
} MATRIX;
typedef struct {		 
	short	vx, vy;
	short	vz, pad;
} SVECTOR;
extern void func_800878B0(long ofx,long ofy);
extern void func_800878D0(long h);
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
	u8	r1, g1, b1, p1;
	short	x1,	y1;
	u8	r2, g2, b2, p2;
	short	x2,	y2;
	u32	pad;
} LINE_G3;
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
void    func_800855D0(MATRIX * mp);
void func_800559D4(s32 index);
struct DisplayObject;
typedef struct {
    u8 pad_00[8];
    s16 x;
    s16 y;
    u16 x_fraction;
    u16 y_fraction;
    s16 globe_radius;
    u16 rest_x;
    u16 rest_y;
    u8 frames;
    u8 active;
    s32 velocity_x;
    s32 velocity_y;
    u8 pad_20[4];
     



    struct DisplayObject *slots[8];
    struct DisplayObject *render;
} LibraryMotionState;
extern MATRIX D_800FE148;
void func_800540B4(s32 index);
void func_800556E8(s32 index);
void func_8005B260(u32 *src, GsOT *ot, s32 idx, s32 flags);
extern GsOT *D_800E9D90[4];
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
extern LibraryMotionState D_800EA1E8;
void func_80029684(LINE_G3 *packet, GsOT *ot, SVECTOR *points,
                  long *control, s32 origin, s32 span);
void func_800297DC(LINE_G3 *packet, GsOT *ot, SVECTOR *points,
                  long *control, s32 origin, s32 span);
void func_80029934(void);
void func_80029934(void)
{
    LINE_G3 *prim;
    SVECTOR *vec;
    SVECTOR *vec1;
    SVECTOR *vec2;
    SVECTOR *vec3;
    long *ctl;
    SVECTOR *par;
    s32 angle;
    GsOT *ot;
    s32 t;
    s32 i;
    s32 step;
    s32 y;
    s32 next_angle;

    angle = 0;
    func_800878B0(0xD0, 0x60);
    func_800878D0(0x12C );
    vec = (SVECTOR *)0x1F800038;
    ctl = (long *)0x1F800060;
    par = (SVECTOR *)0x1F800200;
    ot = D_800E9D90[3];
    func_800855D0(&D_800FE148);

    {
        u32 marker = 0x55555555;
        vec1 = (SVECTOR *)0x1F800040;
        vec2 = (SVECTOR *)0x1F800048;
        vec3 = (SVECTOR *)0x1F800050;
        prim = (LINE_G3 *)0x1F800000;

         
        *par = *(SVECTOR *)0x80181000;

        *(s32 *)&prim->r0 = 0;
        (((P_TAG *)( prim ))->len  = (u8)(  7 )) ;
        (((P_TAG *)( prim ))->code = (u8)(  0x58 )) ;
        prim->pad = marker;
        prim->p2 = 0;
         


        *(s16 *)0x1F800052 = 0;
        *(s16 *)0x1F80004A = 0;
        *(s16 *)0x1F800042 = 0;
        vec->vy = 0;
    }

    do {
        t = (0x400 - angle) * 0xFF / 0x400;
        prim->b1 = t;
        prim->g1 = t;
        prim->r1 = t;
        *(s32 *)&prim->r2 = *(s32 *)&prim->r1;
        ctl[2] = D_800EA1E8.globe_radius * func_80086770(angle) / 4096;
        if (ctl[2] == 0) {
            break;
        }
        ctl[3] = D_800EA1E8.globe_radius * func_800866A0(angle) / 4096;
        vec->vz = vec1->vz = vec2->vz = vec3->vz = (u16)ctl[3] + (u16)par->vz;
        func_80029684(prim, ot, vec, ctl, par->vx, ctl[2]);
        func_80029684(prim, ot, vec, ctl, par->vx, -ctl[2]);
        if (angle != 0) {
            vec->vz = vec1->vz = vec2->vz = vec3->vz = (u16)par->vz - (u16)ctl[3];
            func_80029684(prim, ot, vec, ctl, par->vx, ctl[2]);
            func_80029684(prim, ot, vec, ctl, par->vx, -ctl[2]);
        }
        vec[0].vx = vec[1].vx = vec[2].vx = vec[3].vx = (u16)par->vx + (u16)ctl[3];
        func_800297DC(prim, ot, vec, ctl, par->vz, ctl[2]);
        func_800297DC(prim, ot, vec, ctl, par->vz, -ctl[2]);
        if (angle != 0) {
            vec[0].vx = vec[1].vx = vec[2].vx = vec[3].vx = (u16)par->vx - (u16)ctl[3];
            func_800297DC(prim, ot, vec, ctl, par->vz, ctl[2]);
            func_800297DC(prim, ot, vec, ctl, par->vz, -ctl[2]);
        }
        angle += 0x80;
    } while (angle < 0x400);

    {
        u32 marker;
        *(s32 *)&prim->r0 = 0;
        *(s32 *)&prim->r1 = 0xFFFFFF;
        *(s32 *)&prim->r2 = 0;
        marker = 0x55555555;
        angle = 0;
        (((P_TAG *)( prim ))->len  = (u8)(  7 )) ;
        (((P_TAG *)( prim ))->code = (u8)(  0x58 )) ;
        prim->pad = marker;
        prim->p2 = 0;
        vec[0].vy = 0;
        vec[1].vy = 0;
        do {
            step = D_800EA1E8.globe_radius + 0x80;
            vec[0].vx = (u16)par->vx + step * func_80086770(angle) / 4096;
            next_angle = angle + 0x80;
            vec[1].vx = (u16)par->vx + step * func_80086770(next_angle) / 4096;
            vec[0].vz = (u16)par->vz + step * func_800866A0(angle) / 4096;
            vec[1].vz = (u16)par->vz + step * func_800866A0(next_angle) / 4096;
            step = step / 40;
            __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &vec[0]  ) ) ;
            __asm__ volatile (	"nop;"	"nop;"	".word 0x0000007f" ) ;
            __asm__ volatile (	"swc2	$14, 0( %0 )"	:	: "r"(  &prim->x0  )	: "memory" ) ;
            __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &vec[1]  ) ) ;
            __asm__ volatile (	"nop;"	"nop;"	".word 0x0000007f" ) ;
            __asm__ volatile (	"swc2	$14, 0( %0 )"	:	: "r"(  &prim->x2  )	: "memory" ) ;
            i = 0;
             
            y = (u16)prim->y0 - step;
            prim->x1 = prim->x0;
            prim->y2 = y;
            prim->y1 = y;
            do {
                func_8005B260((u32 *)prim, ot, 1, 1);
                prim->y0 -= step;
                if (prim->y0 <= 0) {
                    break;
                }
                i++;
                prim->y1 -= step;
                prim->y2 -= step;
            } while (i < 7);
            angle += 0x80;
        } while (angle < 0x1000);

    }

    func_800540B4(0);
    func_800559D4(0);
    func_800556E8(0);
}
