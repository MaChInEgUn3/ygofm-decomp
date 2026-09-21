/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_80052D2C.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef struct {
    s16 start_x;
    s16 start_y;
    s16 start_z;
    s16 pair_slot;
    s16 end_x;
    s16 end_y;
    s16 end_z;
    s16 slot;
} ModelCameraLeg;
typedef struct {
    u8 mode;
    u8 flags;
    u16 field_02;
    u16 field_04;
    u16 field_06;
    u16 elapsed;
    u16 duration;
    ModelCameraLeg eye;
    ModelCameraLeg target;
} ModelCameraMove;
extern u16 D_800F3A10[];
extern ModelCameraMove D_800F2B20;
void func_80052D2C(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_8005F174(void);
s32 func_8005F18C(void);
void func_80057F38(u8 *view);
extern u8 D_8009AF98;
typedef struct  {
	short	m[3][3];	 
        long    t[3];		 
} MATRIX;
typedef struct {		 
	long	vx, vy;
	long	vz, pad;
} VECTOR;
typedef struct {		 
	short	vx, vy;
	short	vz, pad;
} SVECTOR;
typedef struct {
	VECTOR  scale;
	SVECTOR rotate;
	VECTOR  trans;
}       GsCOORD2PARAM;
typedef struct _GsCOORDINATE2 {
	unsigned long flg;
	MATRIX  coord;
	MATRIX  workm;
	GsCOORD2PARAM *param;
	struct _GsCOORDINATE2 *super;
	struct _GsCOORDINATE2 *sub;
}       GsCOORDINATE2;
typedef struct {
	long    vpx, vpy, vpz;
	long    vrx, vry, vrz;
	long    rz;
	GsCOORDINATE2 *super;
}       GsRVIEW2;
extern GsRVIEW2 D_800F56F0;
extern void *func_8008E3D0 ( );
void func_80052D2C(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    SVECTOR a;
    SVECTOR b;
    SVECTOR t;
    s32 index;
    s32 state;
    s32 flags;

    func_8008E3D0(&b, 0, 8);
    b.vx = D_800F56F0.vpx;
    b.vy = D_800F56F0.vpy;
    b.vz = D_800F56F0.vpz;
    a = b;
    func_8008E3D0(&t, 0, 8);
    t.vx = D_800F56F0.vrx;
    t.vy = D_800F56F0.vry;
    t.vz = D_800F56F0.vrz;
    b = t;
    state = func_8005F174();
    if (state == 1) {
        if (func_8005F18C() == state) {
            return;
        }
    }
    if (arg1 != 0 || arg0 <= 0) {
        if (arg1 > 0) {
            index = arg1 - 1;
            arg1 = (s32)((u8 *)( D_800F3A10 ) + (  index ) * 0xE20 ) ;
            if (arg3 >= 0) {
                D_800F2B20.eye.pair_slot = index ^ 1;
            } else {
                D_800F2B20.eye.pair_slot = -1;
            }
            D_800F2B20.eye.slot = index;
        } else {
            ModelCameraMove *p = &D_800F2B20;

            p->eye.slot = -1;
            p->eye.pair_slot = -1;
        }
    }
    if (arg2 != 0 || arg0 <= 0) {
        if (arg2 > 0) {
            index = arg2 - 1;
            arg2 = (s32)((u8 *)( D_800F3A10 ) + (  index ) * 0xE20 ) ;
            if (arg3 >= 0) {
                D_800F2B20.target.pair_slot = index ^ 1;
            } else {
                D_800F2B20.target.pair_slot = -1;
            }
            D_800F2B20.target.slot = index;
        } else {
            ModelCameraMove *p = &D_800F2B20;

            p->target.slot = -1;
            p->target.pair_slot = -1;
        }
        if (arg0 < 0) {
            goto have_flags;
        }
    }
    D_800F2B20.mode = arg0;
have_flags:
    {
        ModelCameraMove *p = &D_800F2B20;

        p->field_02 = 0x12C ;
        p->field_06 = 8;
        p->field_04 = 8;
        p->flags = 0;
        if (arg1 != 0) {
            p->flags = 1;
        } else {
            arg1 = (s32)&a;
        }
    }
    if (arg2 != 0) {
        ModelCameraMove *p = &D_800F2B20;

        p->flags = p->flags | 2;
    } else {
        arg2 = (s32)&b;
    }
    {
        ModelCameraMove *p = &D_800F2B20;

        p->eye.start_x = a.vx;
        p->eye.start_y = a.vy;
        p->eye.start_z = a.vz;
         

        p->eye.end_x = ((SVECTOR *)( arg1 )) ->vx;
        p->eye.end_y = ((SVECTOR *)( arg1 )) ->vy;
        p->eye.end_z = ((SVECTOR *)( arg1 )) ->vz;
        p->target.start_x = b.vx;
        p->target.start_y = b.vy;
        p->target.start_z = b.vz;
        p->target.end_x = ((SVECTOR *)( arg2 )) ->vx;
        p->target.end_y = ((SVECTOR *)( arg2 )) ->vy;
        p->target.end_z = ((SVECTOR *)( arg2 )) ->vz;
        arg3 = (arg3 < 0 ? -arg3 : arg3) * 2;
        if (arg3 > 0xFFFE) {
            p->duration = 0xFFFF;
        } else {
            p->duration = arg3;
        }
    }
    {
        ModelCameraMove *p = &D_800F2B20;

        flags = p->flags;
        p->elapsed = 0;
        if (flags != 0) {
            D_8009AF98 = 0;
        }
        if (arg3 != 0) {
            return;
        }
        if (flags & 1) {
            D_800F56F0.vpx = p->eye.end_x;
            D_800F56F0.vpy = p->eye.end_y;
            D_800F56F0.vpz = p->eye.end_z;
        }
        if (p->flags & 2) {
            D_800F56F0.vrx = p->target.end_x;
            D_800F56F0.vry = p->target.end_y;
            D_800F56F0.vrz = p->target.end_z;
        }
        if (p->flags & 3) {
            func_80057F38(0);
        }
        p->flags = 0;
    }
}
