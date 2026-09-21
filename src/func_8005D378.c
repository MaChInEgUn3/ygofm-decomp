/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/model_interpolate_transform.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
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
	long	vx, vy;
	long	vz, pad;
} VECTOR;
typedef struct {		 
	short	vx, vy;
	short	vz, pad;
} SVECTOR;
extern MATRIX *func_80089060(SVECTOR *r,MATRIX *m);
extern MATRIX *func_80087670(MATRIX *m,VECTOR *v);
typedef unsigned char PACKET;
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
typedef struct _GsCOORDUNIT {
	unsigned long		flg;
	MATRIX			matrix;
	MATRIX			workm;
	SVECTOR			rot;
	struct _GsCOORDUNIT	*super;
}	GsCOORDUNIT;
typedef struct {
	unsigned long	*primp;
	GsOT		*tagp;
	int		shift;
	int		offset;
	PACKET		*out_packetp;
	long		header_size;
	unsigned long	*htop;
	unsigned long	*ctop;
	unsigned long	*ptop;
} GsARGUNIT_ANIM;
typedef struct {
	u32		rewrite_idx;
	u16		size, num;
	u16		ii;
	u16		aframe;
	u8		sid;
	signed char	speed;
	u16		srcii;
	short		rframe;
	u16		tframe;
	u16		ci, ti;
	u16		start;
	u8		start_sid;
	u8		traveling;
} GsSEQ;
typedef struct {
    s16 x;
    s16 y;
    s16 z;
    u16 rotation_x;
    u16 rotation_y;
    u16 rotation_z;
    s16 scale_x;
    s16 scale_y;
    s16 scale_z;
} ModelAnimationSample;
typedef struct {
    GsSEQ *track;
    ModelAnimationSample *sample_1;
    ModelAnimationSample *sample_2;
    u16 *output;
} ModelAnimationInterpolationSlots;
s32 func_8005D378(GsARGUNIT_ANIM *ctx);
s32 func_8005D378(GsARGUNIT_ANIM *ctx)
{
    GsSEQ *track;
    GsCOORDUNIT *node;
    s16 *out;
    ModelAnimationInterpolationSlots *slot;
    s32 t;
    s32 dur;
    s32 rest;
    s32 rest2;
    s32 a;
    s32 b;
    s32 rx;
    s32 ry;
    s32 rz;
    s32 w;
    s32 c;
    s32 scale[3];

    slot = (ModelAnimationInterpolationSlots *)(
        &ctx->header_size + ctx->header_size
    );
    track = slot->track;
    if (track->tframe == 0) {
        return 1;
    }

    t = track->rframe;
    dur = track->tframe;
    rest = dur - t;

    {
        u32 rewrite = track->rewrite_idx;
        u32 table_index = rewrite >> 24;
        u32 word_offset = rewrite & 0xFFFFFF;
        node = (GsCOORDUNIT *)(((u32 *)ctx)[table_index + 5]
                            + (word_offset << 2));
    }

    node->matrix.t[0] =
        (slot->sample_1->x * t + slot->sample_2->x * rest) / dur;
    node->matrix.t[1] =
        (slot->sample_1->y * t + slot->sample_2->y * rest) / dur;
    node->matrix.t[2] =
        (slot->sample_1->z * t + slot->sample_2->z * rest) / dur;

    rx = slot->sample_2->rotation_x;
    ry = slot->sample_2->rotation_y;
    rz = slot->sample_2->rotation_z;
    a = slot->sample_1->rotation_x;
    b = slot->sample_1->rotation_y;
    c = slot->sample_1->rotation_z;

    if (dur == 0x10) {
        s32 d;
        d = (s16)a - (s16)rx;
        if (d < 0) goto negative_x;
        if (d >= ((0x1000  / 2)  + 1) ) goto wrap_x;
        goto done_x;
negative_x:
        if ((s16)rx - (s16)a < ((0x1000  / 2)  + 1) ) goto done_x;
wrap_x:
        w = (s16)rx;
        if (w > 0) {
            w -= 0x1000 ;
        } else {
            w += 0x1000 ;
        }
        rx = w;
done_x:
        ;

        d = (s16)b - (s16)ry;
        if (d < 0) goto negative_y;
        if (d >= ((0x1000  / 2)  + 1) ) goto wrap_y;
        goto done_y;
negative_y:
        if ((s16)ry - (s16)b < ((0x1000  / 2)  + 1) ) goto done_y;
wrap_y:
        w = (s16)ry;
        if (w > 0) {
            w -= 0x1000 ;
        } else {
            w += 0x1000 ;
        }
        ry = w;
done_y:
        ;

        d = (s16)c - (s16)rz;
        if (d < 0) goto negative_z;
        if (d >= ((0x1000  / 2)  + 1) ) goto wrap_z;
        goto done_z;
negative_z:
        if ((s16)rz - (s16)c < ((0x1000  / 2)  + 1) ) goto done_z;
wrap_z:
        w = (s16)rz;
        if (w > 0) {
            w -= 0x1000 ;
        } else {
            w += 0x1000 ;
        }
        rz = w;
done_z:
        ;
    }

    node->rot.vx = ((s16)a * t + (s16)rx * (rest2 = dur - t)) / dur;
    node->rot.vy = ((s16)b * t + (s16)ry * rest2) / dur;
    node->rot.vz = ((s16)c * t + (s16)rz * rest2) / dur;

    out = &node->rot.vx;
    func_80089060((SVECTOR *)out, &node->matrix);

    scale[0] =
        (slot->sample_1->scale_x * t +
         slot->sample_2->scale_x * rest2) / dur;
    scale[1] =
        (slot->sample_1->scale_y * t +
         slot->sample_2->scale_y * rest2) / dur;
    scale[2] =
        (slot->sample_1->scale_z * t +
         slot->sample_2->scale_z * rest2) / dur;
    func_80087670(&node->matrix, (VECTOR *)scale);

    node->flg = 0;
    if (slot->output == 0) goto finished;
    slot->output[0] = *(u16 *)&node->matrix.t[0];
    slot->output[1] = *(u16 *)&node->matrix.t[1];
    slot->output[2] = *(u16 *)&node->matrix.t[2];
    slot->output[3] = *(u16 *)&node->rot.vx;
    slot->output[4] = *(u16 *)&node->rot.vy;
    slot->output[5] = *(u16 *)&node->rot.vz;
    slot->output[6] = *(u16 *)&scale[0];
    slot->output[7] = *(u16 *)&scale[1];
    slot->output[8] = *(u16 *)&scale[2];
finished:
    return 0;
}
